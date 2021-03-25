module Parse(parse) where

import Location
import qualified Lex
import qualified Message
import qualified Message.Underlines as MsgUnds
import qualified AST

import Data.Data(toConstr, Data)
import Data.Maybe(isJust, fromMaybe)

import Control.Monad.State.Lazy

-- TODO: boom tokens

-- errors {{{1
data ErrorCondition = ErrorCondition Int ErrorConditionVariant
data ErrorConditionVariant
    = XIsMissingYFound String String Span (Located Lex.Token)
    | XIsMissingYAfterZFound String String String Span (Located Lex.Token)
    | ExcessTokens Span (Located Lex.Token)
    | InvalidToken String String [String] Span (Located Lex.Token)
    | Unclosed String String Span Span (Located Lex.Token)

condToMsgs :: ErrorConditionVariant -> [MsgUnds.Message]

condToMsgs (XIsMissingYFound x y sp (Located _ tok)) =
    [ MsgUnds.Message sp MsgUnds.Error MsgUnds.Primary $ x ++ " is missing " ++ y ++ " (found " ++ Lex.fmtToken tok ++ ")"
    ]
condToMsgs (XIsMissingYAfterZFound x y z sp (Located _ tok)) =
    [ MsgUnds.Message sp MsgUnds.Error MsgUnds.Primary $ x ++ " is missing " ++ y ++ " after " ++ z ++ " (found " ++ Lex.fmtToken tok ++ ")"
    ]
condToMsgs (ExcessTokens sp (Located _ tok)) =
    [ MsgUnds.Message sp MsgUnds.Error MsgUnds.Primary $ "extraneous tokens found in input (" ++ Lex.fmtToken tok ++ ")"
    ]
condToMsgs (InvalidToken construct thing possibilities sp (Located _ found)) =
    [ MsgUnds.Message sp MsgUnds.Error MsgUnds.Primary $ "invalid " ++ thing ++ " for " ++ construct ++ "; must be " ++ fmtPossibilities possibilities ++ " (found " ++ Lex.fmtToken found ++ ")"
    ]
    where
        fmtPossibilities [] = error "no possibilities"
        fmtPossibilities (x:[]) = x
        fmtPossibilities (x:y:[]) = x ++ " or " ++ y
        fmtPossibilities (x:y:z:[]) = x ++ ", " ++ y ++ ", or " ++ z
        fmtPossibilities (x:xs) = x ++ ", " ++ fmtPossibilities xs
condToMsgs (Unclosed construct delimiterName openSp sp (Located _ found)) =
    [ MsgUnds.Message sp MsgUnds.Error MsgUnds.Primary $ construct ++ " has unclosed " ++ delimiterName ++ " (found " ++ Lex.fmtToken found ++ ")"
    , MsgUnds.Message openSp MsgUnds.Note MsgUnds.Secondary $ "opening " ++ delimiterName ++ " is here"
    ]


data ParseError = ParseError [ErrorCondition]
instance Message.ToDiagnostic ParseError where
    toDiagnostic (ParseError msgs) =
        Message.SimpleDiag Message.Error Nothing Nothing Nothing
            [Message.Underlines $ MsgUnds.UnderlinesSection $ concatMap condToMsgs toShow]
        where
            toShow = map condv $ filter ((maxind==) . condloc) msgs
            maxind = maximum $ map condloc msgs

            condloc (ErrorCondition i _) = i
            condv (ErrorCondition _ v) = v

-- parser {{{1
data Parser = Parser [Located Lex.Token] (Maybe (Located Lex.Token)) [ErrorCondition] Int
type ParseFun a = State Parser a
type ParseFunM a = ParseFun (Maybe a)
-- utility functions {{{1
constrEq :: (Data a, Data b) => a -> b -> Bool
constrEq a b = toConstr a == toConstr b

isTT :: Lex.Token -> Located Lex.Token -> Bool
isTT a (Located _ b) = constrEq a b

isTTU :: Lex.Token -> Located Lex.Token -> Maybe ()
isTTU a b = if isTT a b then Just () else Nothing

isTTS :: Lex.Token -> Located Lex.Token -> Maybe Span
isTTS a b@(Located sp _) = if isTT a b then Just sp else Nothing

unmfp :: ParseFunM a -> (a -> ParseFunM b) -> ParseFunM b
unmfp exa cont =
    exa >>= \ mres ->
    case mres of
        Just res -> cont res
        Nothing -> return Nothing
-- parser helpers {{{1
advance :: Int -> Parser -> Parser
advance 0 p = p
advance 1 (Parser (t:ts) _ errs ind) = Parser ts (Just t) errs (ind + 1)
advance n p = advance 1 $ advance (n - 1) p

advanceS :: Int -> ParseFun ()
advanceS x = state $ \ parser -> ((), advance x parser)

peek :: Parser -> Located Lex.Token
peek (Parser (x:_) _ _ _) = x
peek (Parser [] _ _ _) = error "peek on empty token stream"

peekS :: ParseFun (Located Lex.Token)
peekS = state $ \ parser -> (peek parser, parser)

newErr :: ErrorConditionVariant -> Parser -> Parser
newErr err (Parser toks l errs ind) = Parser toks l (errs ++ [ErrorCondition ind err]) ind

newErrS :: ErrorConditionVariant -> ParseFun ()
newErrS err = state $ \ parser -> ((), newErr err parser)

getParser :: ParseFun Parser
getParser = state $ \ parser -> (parser, parser)

saveLocation :: ParseFun ([Located Lex.Token], Maybe (Located Lex.Token), Int)
saveLocation = state $ \ parser@(Parser toks l _ ind) -> ((toks, l, ind), parser)

restoreLocation :: ([Located Lex.Token], Maybe (Located Lex.Token), Int) -> ParseFun ()
restoreLocation (toks, l, ind) = state $ \ (Parser _ _ errs _) -> ((), Parser toks l errs ind)

selectSpanFromParser :: Parser -> Span
selectSpanFromParser (Parser toks back _ _) =
    let front =
            case toks of
                x:_ -> Just x
                [] -> Nothing
    in case (front, back) of
        (Just (Located _ Lex.EOF), Just (Located notEofSp _)) -> notEofSp
        (Just (Located eofSp Lex.EOF), Nothing) -> eofSp
        (Just (Located fsp _), _) -> fsp
        (Nothing, Just (Located bsp _)) -> bsp
        (Nothing, Nothing) -> error "parser has empty token stream, no last"
-- combinators {{{1
consume :: (Located Lex.Token -> Maybe t) -> (Span -> Located Lex.Token -> ErrorConditionVariant) -> ParseFunM t
consume predicate onerr =
    peekS >>= \ locatedPeeked ->
    case predicate locatedPeeked of
        Just x ->
            advanceS 1 >>
            return (Just x)
        Nothing ->
            getParser >>= \ parser ->
            newErrS (onerr (selectSpanFromParser parser) locatedPeeked) >>
            return Nothing
-- consume combinators {{{
consumeTokU :: Lex.Token -> (Span -> Located Lex.Token -> ErrorConditionVariant) -> ParseFunM ()
consumeTokU tok = consume (isTTU tok)

consumeTokS :: Lex.Token -> (Span -> Located Lex.Token -> ErrorConditionVariant) -> ParseFunM Span
consumeTokS tok = consume (isTTS tok)

consumeIden :: (Span -> Located Lex.Token -> ErrorConditionVariant) -> ParseFunM (Located String)
consumeIden = consume $
    \ tok ->
    case tok of
        Located sp (Lex.Identifier n) -> Just $ Located sp n
        _ -> Nothing
-- }}}

-- TODO: allow error override, if used then silence all choice's errors, and if none of them match then emit that custom error
choice :: [ParseFunM a] -> ParseFunM a
choice choices =
    saveLocation >>= tryChoices choices
    where
        tryChoices (c:cs) originalLocation =
            restoreLocation originalLocation >>
            c >>= \ res ->
            case res of
                Just x -> return (Just x)
                Nothing -> tryChoices cs originalLocation

        tryChoices [] originalLocation =
            restoreLocation originalLocation >>
            return Nothing

zeromore :: ParseFunM a -> ParseFun [a]
zeromore ex = fun
    where
        fun =
            saveLocation >>= \ saved ->
            ex >>= \ mres ->
            case mres of
                Just res ->
                    fun >>= \ rest ->
                    return ([res] ++ rest)

                Nothing ->
                    restoreLocation saved >>
                    return []

onemore :: ParseFunM a -> ParseFunM [a]
onemore ex = fun []
    where
        fun acc =
            ex >>= \ res ->
            case res of
                Just thing ->
                    fun (acc ++ [thing])

                Nothing ->
                    if length acc == 0
                    then return Nothing
                    else return (Just acc)

onemoredelim :: ParseFunM a -> ParseFunM b -> ParseFunM [a]
onemoredelim ex delim =
    ex `unmfp` \ first ->
    zeromore (
        delim `unmfp` \ _ -> ex
    ) >>= \ rest ->
    return $ Just $ first:rest

convert :: ParseFun a -> (a -> b) -> ParseFun b
convert ex conv =
    ex >>= \ res ->
    return (conv res)

mustMatch :: ParseFunM a -> ParseFunM ()
mustMatch ex =
    saveLocation >>= \ saved ->
    ex >>= \ res ->
    restoreLocation saved >>
    return (const () <$> res)

mustNotMatch :: ParseFunM a -> (Span -> ErrorConditionVariant) -> ParseFunM ()
mustNotMatch ex onerr =
    saveLocation >>= \ saved ->
    ex >>= \ res ->
    restoreLocation saved >>
    case res of
        Just _ ->
            getParser >>= \ parser ->
            newErrS (onerr $ selectSpanFromParser parser) >>
            return Nothing

        Nothing ->
            return (Just ())
-- grammar {{{1
-- grammar helpers {{{
maybeToMutability :: Maybe a -> AST.Mutability
maybeToMutability (Just _) = AST.Mutable
maybeToMutability Nothing = AST.Immutable
-- }}}
-- span helpers {{{
spanFromList :: Span -> [Located a] -> Span
spanFromList fallback [] = fallback
spanFromList _ list =
    joinSpan a b
    where 
        Located a _ = head list
        Located b _ = last list

-- }}}
grammar :: ParseFunM AST.LDCU
grammar =
    declList >>= \ mdl ->
    consumeTokS Lex.EOF ExcessTokens `unmfp` \ eofsp ->
    case mdl of
        Just dl -> return $ Just $ Located (spanFromList eofsp dl) (AST.DCU'CU dl)
        Nothing -> return $ Just $ Located eofsp $ AST.DCU'CU []
-- lists {{{2
declList :: ParseFunM [AST.LDDecl]
declList = onemore parseDecl

paramList :: ParseFunM [AST.LDParam]
-- TODO: improve separator errors
paramList = onemoredelim parseParam (consumeTokU Lex.Comma (XIsMissingYAfterZFound "parameter list" "parameter separator ','" "parameter"))

stmtList :: ParseFunM [AST.LDStmt]
stmtList = onemore parseStmt

argList :: ParseFunM [AST.LDExpr]
-- TODO: also improve separator errors
argList = onemoredelim parseExpr (consumeTokU Lex.Comma (XIsMissingYAfterZFound "argument list" "argument separator ','" "argument"))
-- line endings {{{2
lnend :: String -> ParseFunM Span
lnend what = consume
    (\ tok ->
    case tok of
        Located sp Lex.Newline -> Just sp
        Located sp Lex.Semicolon -> Just sp
        _ -> Nothing
    ) (XIsMissingYFound what "terminator (newline or ';')")
-- blocks {{{2
blocked, braced, indented :: String -> ParseFun a -> ParseFunM (Span, a)
blocked what ex = choice [braced what ex, indented what ex]

braced what ex =
    consumeTokS Lex.OBrace (XIsMissingYFound what "opening '{'") `unmfp` \ obracesp ->
    ex >>= \ inside ->
    consumeTokS Lex.CBrace (Unclosed what "'{'" obracesp) `unmfp` \ cbracesp ->
    return $ Just (obracesp `joinSpan` cbracesp, inside)

indented what ex =
    consumeTokS Lex.Indent (XIsMissingYFound what "opening indent") `unmfp` \ indentsp ->
    ex >>= \ inside ->
    consumeTokS Lex.Dedent (Unclosed what "indent" indentsp) `unmfp` \ dedentsp ->
    return $ Just (indentsp `joinSpan` dedentsp, inside)
-- decl {{{2
parseDecl :: ParseFunM AST.LDDecl
parseDecl =
    choice
        [ implDecl
        , functionDecl `unmfp` \ lsfd@(Located sp _) ->
          return $ Just $ Located sp $ AST.DDecl'Fun lsfd
        ]

functionDecl :: ParseFunM AST.LSFunDecl
functionDecl =
    (consumeTokS Lex.Fun (XIsMissingYFound "function declaration" "introductory 'fun'")) `unmfp` \ funsp ->
    (consumeIden (XIsMissingYAfterZFound "function declaration" "function name" "'fun'")) `unmfp` \ name ->
    (consumeTokU Lex.OParen (XIsMissingYAfterZFound "function declaration" "'('" "function name")) `unmfp` \ _ ->
    paramList >>= \ mparamlist ->
    (consumeTokS Lex.CParen (XIsMissingYAfterZFound "function declaration" "')'" "(optional) parameter list")) `unmfp` \ cparensp ->
    typeAnnotation >>= \ retty ->
    blockExpr `unmfp` \ body ->
    lnend "function declaration" >>= \ _ ->
    let params = case mparamlist of
            Just l -> l
            Nothing -> []
        fdsp = joinSpan funsp $
            case retty of
                Just (Located rettysp _) -> rettysp
                Nothing -> cparensp

    in return $ Just $ Located fdsp $ AST.SFunDecl' retty name params body

implDecl :: ParseFunM AST.LDDecl
implDecl =
    consumeTokS Lex.Impl (XIsMissingYFound "implementation block" "introductory 'impl'") `unmfp` \ implsp ->
    parseType `unmfp` \ implFor@(Located tysp _)->
    implBody `unmfp` \ body ->
    return $ Just $ Located (joinSpan implsp tysp) $ AST.DDecl'Impl implFor $ snd body
    where
        implBody = blocked "implementation body" implList
        implList = zeromore $
            choice
                [ functionDecl `unmfp` \ lsfd@(Located sp _) ->
                  return $ Just $ Located sp $ AST.DImplMember'Fun lsfd
                ]
-- types {{{2
typeAnnotation :: ParseFunM AST.LDType
typeAnnotation =
    (consumeTokU Lex.Colon (XIsMissingYFound "type annotation" "introductory ':'")) `unmfp` \ _ ->
    parseType

parseType, pointerType, thisType, pathType :: ParseFunM AST.LDType
parseType = choice [pointerType, thisType, pathType]

pointerType =
    (consumeTokS Lex.Star (XIsMissingYFound "pointer type" "introductory '*'")) `unmfp` \ starsp ->
    (consumeTokU Lex.Mut (XIsMissingYAfterZFound "mutable pointer type" "'mut'" "'*'")) >>= \ mmut ->
    parseType `unmfp` \ pointeeTy@(Located pointeesp _) ->
    return $ Just $ Located (joinSpan starsp pointeesp) $ AST.DType'Pointer (maybeToMutability mmut) pointeeTy

thisType =
    consumeTokS Lex.This (XIsMissingYFound "'this' type" "'this'") `unmfp` \ thsp ->
    return $ Just $ Located thsp $ AST.DType'This

pathType =
    parsePath `unmfp` \ path@(Located pathsp _) ->
    return $ Just $ Located pathsp $ AST.DType'Path path
-- paths {{{2
parsePath :: ParseFunM AST.LDPath
parsePath =
    -- TODO: improve delimiter error
    (onemoredelim
        (consumeIden (XIsMissingYFound "path" "path segment (identifier)"))
        (consumeTokU Lex.DoubleColon (XIsMissingYAfterZFound "path" "segment separator ('::')" "segment"))) `unmfp` \ list ->
    let totalsp = spanFromList (error "path should always have at least one element") list
    in return $ Just $ Located totalsp $ AST.DPath' list
-- params {{{2
parseParam, normalParam, thisParam :: ParseFunM AST.LDParam
parseParam = choice [normalParam, thisParam]

normalParam =
    (consumeTokS Lex.Mut (XIsMissingYFound "mutable parameter" "'mut'")) >>= \ mmut ->
    (consumeIden (XIsMissingYFound "parameter" "parameter name")) `unmfp` \ name@(Located namesp _) ->
    typeAnnotation `unmfp` \ ty@(Located tysp _) ->
    let startsp = fromMaybe namesp mmut
        endsp = tysp
    in return $ Just $ Located (joinSpan startsp endsp) $ AST.DParam'Normal (maybeToMutability mmut) ty name

thisParam =
    (
        consumeTokS Lex.Star (XIsMissingYFound "'this' reference parameter" "'*'") `unmfp` \ starsp ->
        consumeTokU Lex.Mut (XIsMissingYAfterZFound "'this' mutable reference parameter" "'mut'" "'*'") >>= \ mmut ->
        return $ Just $ Located starsp $ isJust mmut
    ) >>= \ mstarmut ->
    consumeTokS Lex.This (XIsMissingYFound "'this' parameter" "'this'") `unmfp` \ thissp ->
    let (mstartsp, kind) = case mstarmut of
            Just (Located startsp True) -> (Just startsp, AST.MutRef)
            Just (Located startsp False) -> (Just startsp, AST.Ref)
            Nothing -> (Nothing, AST.Value)

        startsp = fromMaybe thissp mstartsp
        endsp = thissp

    in return $ Just $ Located (startsp `joinSpan` endsp) $ AST.DParam'This kind
-- expr {{{2
parseExpr, ifExpr, whileExpr :: ParseFunM AST.LDExpr
parseExpr =
    choice
        [ assignExpr
        , ifExpr
        , whileExpr
        , blockExpr `unmfp` \ bl@(Located blsp _) ->
          return $ Just $ Located blsp $ AST.DExpr'Block bl
        ]

blockStmtList :: ParseFunM (Span, [AST.LDStmt])
blockStmtList =
    blocked "code block" (
        stmtList >>= \ sl ->
        return $ case sl of
            Just x -> x
            Nothing -> []
    )

blockExpr :: ParseFunM AST.LSBlockExpr
blockExpr =
    blockStmtList `unmfp` \ (slsp, sl) ->
    return $ Just $ Located slsp $ AST.SBlockExpr' sl

ifExpr =
    (consumeTokS Lex.If (XIsMissingYFound "'if' expression" "'if'")) `unmfp` \ ifsp ->
    parseExpr `unmfp` \ cond ->
    blockExpr `unmfp` \ trueb@(Located truebsp _) ->
    (
        (consumeTokS Lex.Else (XIsMissingYFound "'else' branch of 'if' expression" "'else'")) `unmfp` \ elsesp ->
        choice
            [ blockExpr `unmfp` \ block@(Located blocksp _) ->
              return $ Just $ Located blocksp $ AST.DExpr'Block block
            , ifExpr
            ] `unmfp` \ falseb@(Located falsebsp _) ->
        return $ Just (falsebsp, (elsesp, falseb))
    ) >>= \ melsebandspan ->
    let startsp = ifsp
        endsp = fromMaybe truebsp $ fst <$> melsebandspan
        melseb = snd <$> melsebandspan

        loctrueb = Located truebsp $ AST.DExpr'Block trueb
    in return $ Just $ Located (startsp `joinSpan` endsp) $ AST.DExpr'If ifsp cond loctrueb melseb

whileExpr =
    (consumeTokS Lex.While (XIsMissingYFound "'while' expression" "'while'")) `unmfp` \ whilesp ->
    parseExpr `unmfp` \ cond ->
    blockExpr `unmfp` \ block@(Located blocksp _) ->
    return $ Just $ Located (whilesp `joinSpan` blocksp) $ AST.DExpr'While cond (Located blocksp $ AST.DExpr'Block block)

mkBinExpr :: ParseFunM AST.LDExpr -> ParseFunM a -> (AST.LDExpr -> a -> AST.LDExpr -> AST.DExpr) -> ParseFunM AST.LDExpr
mkBinExpr next operators constructor =
    next `unmfp` \ lhs ->
    maybeNextRep lhs
    where
        maybeNextRep lhs@(Located lhssp _) =
            (
                operators `unmfp` \ op ->
                next `unmfp` \ rhs ->
                return $ Just (op, rhs)
            ) >>= \ mrhs ->
            case mrhs of
                Just (op, rhs@(Located rhssp _)) -> maybeNextRep $ Located (lhssp `joinSpan` rhssp) $ constructor lhs op rhs
                Nothing -> return $ Just lhs

assignExpr, binOrExpr, binAndExpr, compEQExpr, compLGTExpr, bitXorExpr, bitOrExpr, bitAndExpr, bitShiftExpr, additionExpr, multExpr, castExpr, unaryExpr, callExpr, primaryExpr, pathExpr :: ParseFunM AST.LDExpr

assignExpr =
    binOrExpr `unmfp` \ lhs@(Located lhssp _) ->
    (
        consume (\ (Located sp tok) ->
        case tok of
            Lex.Equal -> Just $ Located sp AST.Equal
            _ -> Nothing
        ) (InvalidToken "assignment expression" "operator" ["'='"]) `unmfp` \ op ->
        assignExpr `unmfp` \ rhs ->
        return $ Just (op, rhs)
    ) >>= \ mrhs ->
    return $ Just (case mrhs of
        Just (op, rhs@(Located rhssp _)) -> Located (lhssp `joinSpan` rhssp) $ AST.DExpr'Assign lhs op rhs
        Nothing -> lhs
    )

binOrExpr = mkBinExpr binAndExpr
        (consume (\ (Located sp tok) ->
            let op = case tok of
                    Lex.DoublePipe -> Just AST.DoublePipe
                    _ -> Nothing
            in Located sp <$> op
        ) (InvalidToken "binary or expression" "operator" ["'||'"]))
        AST.DExpr'ShortCircuit
binAndExpr = mkBinExpr compEQExpr
        (consume (\ (Located sp tok) ->
            let op = case tok of
                    Lex.DoubleAmper -> Just AST.DoubleAmper
                    _ -> Nothing
            in Located sp <$> op
        ) (InvalidToken "binary and expression" "operator" ["'&&'"]))
        AST.DExpr'ShortCircuit
compEQExpr = mkBinExpr compLGTExpr
        (consume (\ (Located sp tok) ->
            let op = case tok of
                    Lex.BangEqual -> Just AST.BangEqual
                    Lex.DoubleEqual -> Just AST.DoubleEqual
                    _ -> Nothing
            in Located sp <$> op
        ) (InvalidToken "equality test expression" "operator" ["'!='", "'=='"]))
        AST.DExpr'Binary
compLGTExpr = mkBinExpr bitXorExpr
        (consume (\ (Located sp tok) ->
            let op = case tok of
                    Lex.Greater -> Just AST.Greater
                    Lex.Less -> Just AST.Less
                    Lex.GreaterEqual -> Just AST.GreaterEqual
                    Lex.LessEqual -> Just AST.LessEqual
                    _ -> Nothing
            in Located sp <$> op
        ) (InvalidToken "comparison expression" "operator" ["'>'", "'<'", "'>='", "'<='"]))
        AST.DExpr'Binary
bitXorExpr = mkBinExpr bitOrExpr
        (consume (\ (Located sp tok) ->
            let op = case tok of
                    Lex.Caret -> Just AST.Caret
                    _ -> Nothing
            in Located sp <$> op
        ) (InvalidToken "bitwise xor expression" "operator" ["'^'"]))
        AST.DExpr'Binary
bitOrExpr = mkBinExpr bitAndExpr
        (consume (\ (Located sp tok) ->
            let op = case tok of
                    Lex.Pipe -> Just AST.Pipe
                    _ -> Nothing
            in Located sp <$> op
        ) (InvalidToken "bitwise or expression" "operator" ["'|'"]))
        AST.DExpr'Binary
bitAndExpr = mkBinExpr bitShiftExpr
        (consume (\ (Located sp tok) ->
            let op = case tok of
                    Lex.Amper -> Just AST.Amper
                    _ -> Nothing
            in Located sp <$> op
        ) (InvalidToken "bitwise and expression" "operator" ["'&'"]))
        AST.DExpr'Binary
bitShiftExpr = mkBinExpr additionExpr
        (consume (\ (Located sp tok) ->
            let op = case tok of
                    Lex.DoubleLess -> Just AST.DoubleLess
                    Lex.DoubleGreater -> Just AST.DoubleGreater
                    _ -> Nothing
            in Located sp <$> op
        ) (InvalidToken "bitshift expression" "operator" ["'<<'", "'>>'"]))
        AST.DExpr'Binary
additionExpr = mkBinExpr multExpr
        (consume (\ (Located sp tok) ->
            let op = case tok of
                    Lex.Plus -> Just AST.Plus
                    Lex.Minus -> Just AST.Minus
                    _ -> Nothing
            in Located sp <$> op
        ) (InvalidToken "addition or subtraction expression" "operator" ["'+'", "'-'"]))
        AST.DExpr'Binary
multExpr = mkBinExpr castExpr
        (consume (\ (Located sp tok) ->
            let op = case tok of
                    Lex.Star -> Just AST.Star
                    Lex.Slash -> Just AST.Slash
                    Lex.Percent -> Just AST.Percent
                    _ -> Nothing
            in Located sp <$> op
        ) (InvalidToken "multiplication, division, or modulo expression" "operator" ["'*'", "'/'", "'%'"]))
        AST.DExpr'Binary

castExpr =
    unaryExpr `unmfp` \ lhs ->
    parseMore lhs
    where
        parseMore lhs@(Located lhssp _) =
            (
                consumeTokU Lex.RightArrow (InvalidToken "cast expression" "operator" ["'->'"]) `unmfp` \ _ ->
                parseType `unmfp` \ ty ->
                return $ Just ty
            ) >>= \ mty ->
            case mty of
                Just ty@(Located tysp _) -> parseMore $ Located (lhssp `joinSpan` tysp) $ AST.DExpr'Cast ty lhs
                Nothing -> return $ Just lhs

unaryExpr =
    choice [punop, amperExpr, callExpr]
    where
        amperExpr =
            consumeTokS Lex.Amper (XIsMissingYFound "reference expression" "operator '&'") `unmfp` \ ampersp ->
            consumeTokU Lex.Mut (XIsMissingYFound "mutable reference expression" "'mut'") >>= \ mmut ->
            unaryExpr `unmfp` \ operand@(Located operandsp _) ->
            return $ Just $ Located (ampersp `joinSpan` operandsp) $ AST.DExpr'Ref ampersp (maybeToMutability mmut) operand

        punop =
            consume (\ (Located sp tok) ->
                let op = case tok of
                        Lex.Tilde -> Just AST.UnTilde
                        Lex.Minus -> Just AST.UnMinus
                        Lex.Bang -> Just AST.UnBang
                        Lex.Star -> Just AST.UnStar
                        _ -> Nothing
                in Located sp <$> op
            ) (InvalidToken "unary expression" "operator" ["'~'", "'-'", "'!'", "'*'"]) `unmfp` \ op@(Located opsp _) ->
            unaryExpr `unmfp` \ operand@(Located operandsp _) ->
            return $ Just $ Located (opsp `joinSpan` operandsp) $ AST.DExpr'Unary op operand

callExpr =
    primaryExpr `unmfp` \ lhs ->
    parseMore lhs
    where
        parseMore lhs@(Located lhssp _) =
            choice [method lhs, field lhs, call lhs] >>= \ mres ->
            case mres of
                Just newlhs -> parseMore newlhs
                Nothing -> return $ Just lhs

        consumeDot exprName operandName =
            consumeTokS Lex.Period (XIsMissingYAfterZFound exprName "'.'" operandName)

        field lhs@(Located lhssp _) =
            consumeDot "field access expression" "expression with fields" `unmfp` \ dot ->
            consumeIden (XIsMissingYAfterZFound "field access expression" "field name" "'.'") `unmfp` \ fieldname@(Located fieldsp _) ->
            return $ Just $ Located (lhssp `joinSpan` fieldsp) $ AST.DExpr'Field lhs dot fieldname

        method lhs@(Located lhssp _) =
            consumeDot "method call expression" "expression with methods" `unmfp` \ dot ->
            consumeIden (XIsMissingYAfterZFound "method call expression" "method name" "'.'") `unmfp` \ methodname ->
            consumeTokS Lex.OParen (XIsMissingYAfterZFound "method call expression" "'('" "method name") `unmfp` \ oparensp ->
            argList >>= \ marglist ->
            -- TODO: replace this with unclosed delimiter error
            consumeTokS Lex.CParen (XIsMissingYAfterZFound "method call expression" "')'" "(optional) argument list") `unmfp` \ cparensp ->
            let arglist = case marglist of
                    Just x -> x
                    Nothing -> []
            in return $ Just $ Located (lhssp `joinSpan` cparensp) $ AST.DExpr'Method lhs dot methodname oparensp arglist

        call lhs@(Located lhssp _) =
            consumeTokS Lex.OParen (XIsMissingYAfterZFound "call expression" "'('" "callee") `unmfp` \ oparensp ->
            argList >>= \ marglist ->
            -- TODO: replace this with unclosed delimiter error
            consumeTokS Lex.CParen (XIsMissingYAfterZFound "call expression" "')'" "(optional) argument list") `unmfp` \ cparensp ->
            let arglist = case marglist of
                    Just x -> x
                    Nothing -> []
            in return $ Just $ Located (lhssp `joinSpan` cparensp) $ AST.DExpr'Call lhs oparensp arglist

primaryExpr = choice [tokExpr, parenExpr, pathExpr]
    where
        tokExpr = consume (
                \ (Located sp tok) ->
                    let e = case tok of
                            Lex.BoolLit b -> Just $ AST.DExpr'Bool b
                            Lex.FloatLit f -> Just $ AST.DExpr'Float f
                            Lex.IntLit _ i -> Just $ AST.DExpr'Int i
                            Lex.CharLit c -> Just $ AST.DExpr'Char c
                            Lex.StringLit s -> Just $ AST.DExpr'String s
                            Lex.This -> Just AST.DExpr'This
                            _ -> Nothing
                    in Located sp <$> e
            ) (InvalidToken "primary expression" "token" ["a literal", "'this'"])
        parenExpr =
            consumeTokS Lex.OParen (XIsMissingYFound "parenthesized expression" "introductory '('") `unmfp` \ oparensp ->
            parseExpr `unmfp` \ inside ->
            consumeTokU Lex.CParen (Unclosed "parenthesized expression" "')'" oparensp) `unmfp` \ _ ->
            return $ Just inside

pathExpr =
    parsePath `unmfp` \ path@(Located pathsp _) ->
    return $ Just $ Located pathsp $ AST.DExpr'Path path
-- stmt {{{2
parseStmt, varStmt, retStmt, exprStmt :: ParseFunM AST.LDStmt
parseStmt = choice [varStmt, retStmt, exprStmt]

varStmt =
    (consumeTokS Lex.Var (XIsMissingYFound "variable statement" "introductory 'var'")) `unmfp` \ varsp ->
    (consumeTokU Lex.Mut (XIsMissingYAfterZFound "variable statement" "'mut'" "'var'")) >>= \ mmut ->
    (consumeIden (XIsMissingYFound "variable statement" "variable name")) `unmfp` \ name ->
    typeAnnotation `unmfp` \ ty ->
    (
        (consumeTokS Lex.Equal (XIsMissingYAfterZFound "variable initialization" "'='" "variable name")) `unmfp` \ eqsp ->
        parseExpr `unmfp` \ initializer ->
        return $ Just (eqsp, initializer)
    ) >>= \ minit ->
    lnend "variable statement" `unmfp` \ endlsp ->
    return $ Just $ Located (varsp `joinSpan` endlsp) $ AST.DStmt'Var ty (maybeToMutability mmut) name minit

retStmt =
    (consumeTokS Lex.Return (XIsMissingYFound "return statement" "introductory 'return'")) `unmfp` \ retsp ->
    parseExpr `unmfp` \ expr ->
    lnend "return statement" `unmfp` \ endlsp ->
    return $ Just $ Located (retsp `joinSpan` endlsp) $ AST.DStmt'Ret expr

exprStmt =
    parseExpr `unmfp` \ expr@(Located exprsp notLocatedExpr) ->
    let needendl = case notLocatedExpr of
            AST.DExpr'Block _ -> False
            AST.DExpr'If _ _ _ _ -> False
            AST.DExpr'While _ _ -> False
            _ -> True
    in
    (
        if needendl
        then lnend "expression statement without block" `unmfp` \ ln -> return $ Just $ Just ln
        else lnend "expression statement with block" >>= \ ln -> return $ Just ln
    ) `unmfp` \ msp ->
    let totalsp = case msp of
            Just sp -> exprsp `joinSpan` sp
            Nothing -> exprsp
    in return $ Just $ Located totalsp $ AST.DStmt'Expr expr

-- parse {{{1
parse :: [Located Lex.Token] -> Either ParseError AST.LDCU
parse toks =
    let (res, (Parser _ _ errs _)) = runState grammar $ Parser toks Nothing [] 0
    in case res of
        Just x -> Right x
        Nothing -> Left $ ParseError errs
