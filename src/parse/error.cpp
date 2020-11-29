#include "parsestack.h"
#include "message/errmsgs.h"

bool errorRecovery(errorstate const &e)
{
    if (singleTok(e))
    {
        return true;
    }
    else if (panicMode(e))
    {
        return true;
    }
    else
    {
        if (e.w)
            ERR_UNRECOVERABLE_INVALID_SYNTAX_WHILE(e.justparsed, e.expected, e.whileparsing, e.lasttok, e.olh);
        else
            ERR_UNRECOVERABLE_INVALID_SYNTAX(e.justparsed, e.expected, e.lasttok, e.olh);

        return false;
    }
}

// helper functions {{{
static std::vector<stackitem> copyStack(std::vector<stackitem> const &stack)
{
    std::vector<stackitem> tempstack;
    for (auto const &si : stack)
    {
        tempstack.emplace_back(si.state);
    }
    return tempstack;
}

static bool tryInsert(TokenType ty, Parser const &p, Token const &lookahead, std::vector<stackitem> const &stack)
{
    Lexer tempL (lookahead);
    Parser tempP (tempL, p.sourcefile);
    Token tempLookahead (lookahead);
    tempLookahead.type = ty;

    auto tempstack (copyStack(stack));

    std::unique_ptr<ASTNS::CUB> tempC (nullptr);

    return _parse(tempP, tempstack, true, tempC, tempLookahead);
}

static bool tryDel(Parser const &p, std::vector<stackitem> const &stack)
{
    Lexer tempL (p.lexer);
    Parser tempP (tempL, p.sourcefile);
    Token tempLookahead (tempP.consume());

    auto tempstack (copyStack(stack));

    std::unique_ptr<ASTNS::CUB> tempC (nullptr);

    return _parse(tempP, tempstack, true, tempC, tempLookahead);
}

static bool trySub(TokenType ty, Parser const &p, Token const &lookahead, std::vector<stackitem> const &stack)
{
    Lexer tempL (p.lexer);
    Parser tempP (tempL, p.sourcefile);
    Token tempLookahead (lookahead);
    tempLookahead.type = ty;

    auto tempstack (copyStack(stack));

    std::unique_ptr<ASTNS::CUB> tempC (nullptr);

    return _parse(tempP, tempstack, true, tempC, tempLookahead);
}
// }}}
struct fix
{
    enum class fixtype
    {
        INSERT,
        REMOVE,
        SUBSTITUTE,
        NOFIX,
    } type;
    TokenType ttype;

    std::string stringify() const
    {
        switch (type)
        {
            case fix::fixtype::REMOVE:
                return "remove token";

            case fix::fixtype::SUBSTITUTE:
                return concatMsg("replace token with ", stringifyTokenType(ttype));

            case fix::fixtype::INSERT:
                return concatMsg("insert ", stringifyTokenType(ttype), " before token");

            default:
                reportAbortNoh("invalid fix type");
        }
    }
};

static void applyFix(fix const &f, Parser &p, Token &lookahead)
{
    switch (f.type)
    {
        case fix::fixtype::REMOVE:
            lookahead = p.consume();
            break;

        case fix::fixtype::SUBSTITUTE:
            lookahead.type = f.ttype;
            break;

        case fix::fixtype::INSERT:
            p.lexer.resetToTok(lookahead);
            lookahead.type = f.ttype;
            break;

        default:
            reportAbortNoh("attempt to apply invalid fix type");
    }
}

bool singleTok(errorstate const &e)
{
    fix bestfix = fix {fix::fixtype::NOFIX};
    auto score = [](fix const &f)
    {
        switch (f.type)
        {
            case fix::fixtype::REMOVE:
                return 0;
            case fix::fixtype::SUBSTITUTE:
                return 1;
            case fix::fixtype::INSERT:
                return 2;
            case fix::fixtype::NOFIX:
                return -1;
            default:
                reportAbortNoh("invalid fix type");
        }
    };

    // error recovery {{{
    // SINGLETOK START

// The following code was autogenerated - see the utils/ directory
#define TRYINSERT(ty) if (tryInsert(ty, e.p, e.lookahead, e.stack)) {fix f = fix {fix::fixtype::INSERT, ty}; if (score(f) > score(bestfix)) bestfix = f;}
#define TRYSUB(ty) if (trySub(ty, e.p, e.lookahead, e.stack)) {fix f = fix {fix::fixtype::SUBSTITUTE, ty}; if (score(f) > score(bestfix)) bestfix = f;}
#define TRYTOKTY(ty) TRYINSERT(ty); TRYSUB(ty);
    TRYTOKTY(TokenType::EOF_)
    TRYTOKTY(TokenType::FUN)
    TRYTOKTY(TokenType::IDENTIFIER)
    TRYTOKTY(TokenType::OPARN)
    TRYTOKTY(TokenType::CPARN)
    TRYTOKTY(TokenType::VAR)
    TRYTOKTY(TokenType::SEMICOLON)
    TRYTOKTY(TokenType::RETURN)
    TRYTOKTY(TokenType::COMMA)
    TRYTOKTY(TokenType::EQUAL)
    TRYTOKTY(TokenType::OCURB)
    TRYTOKTY(TokenType::CCURB)
    TRYTOKTY(TokenType::VOID)
    TRYTOKTY(TokenType::UINT8)
    TRYTOKTY(TokenType::UINT16)
    TRYTOKTY(TokenType::UINT32)
    TRYTOKTY(TokenType::UINT64)
    TRYTOKTY(TokenType::SINT8)
    TRYTOKTY(TokenType::SINT16)
    TRYTOKTY(TokenType::SINT32)
    TRYTOKTY(TokenType::SINT64)
    TRYTOKTY(TokenType::FLOAT)
    TRYTOKTY(TokenType::BOOL)
    TRYTOKTY(TokenType::DOUBLE)
    TRYTOKTY(TokenType::CHAR)
    TRYTOKTY(TokenType::QUESTION)
    TRYTOKTY(TokenType::COLON)
    TRYTOKTY(TokenType::DOUBLEPIPE)
    TRYTOKTY(TokenType::DOUBLEAMPER)
    TRYTOKTY(TokenType::BANGEQUAL)
    TRYTOKTY(TokenType::DOUBLEEQUAL)
    TRYTOKTY(TokenType::LESS)
    TRYTOKTY(TokenType::GREATER)
    TRYTOKTY(TokenType::LESSEQUAL)
    TRYTOKTY(TokenType::GREATEREQUAL)
    TRYTOKTY(TokenType::CARET)
    TRYTOKTY(TokenType::PIPE)
    TRYTOKTY(TokenType::AMPER)
    TRYTOKTY(TokenType::DOUBLEGREATER)
    TRYTOKTY(TokenType::DOUBLELESS)
    TRYTOKTY(TokenType::PLUS)
    TRYTOKTY(TokenType::MINUS)
    TRYTOKTY(TokenType::STAR)
    TRYTOKTY(TokenType::SLASH)
    TRYTOKTY(TokenType::PERCENT)
    TRYTOKTY(TokenType::TILDE)
    TRYTOKTY(TokenType::BANG)
    TRYTOKTY(TokenType::TRUELIT)
    TRYTOKTY(TokenType::FALSELIT)
    TRYTOKTY(TokenType::FLOATLIT)
    TRYTOKTY(TokenType::NULLPTRLIT)
    TRYTOKTY(TokenType::DECINTLIT)
    TRYTOKTY(TokenType::OCTINTLIT)
    TRYTOKTY(TokenType::BININTLIT)
    TRYTOKTY(TokenType::HEXINTLIT)
    TRYTOKTY(TokenType::CHARLIT)
    TRYTOKTY(TokenType::STRINGLIT)
    if (tryDel(e.p, e.stack)) {fix f = fix {fix::fixtype::REMOVE}; if (score(f) > score(bestfix)) bestfix = f;};
// This code was autogenerated - see the utils/ directory

    // SINGLETOK END
    // }}}

    if (bestfix.type != fix::fixtype::NOFIX)
    {
        applyFix(bestfix, e.p, e.lookahead);
        if (e.w)
            ERR_SIMPLE_INVALID_SYNTAX_WHILE(e.justparsed, e.expected, e.whileparsing, e.lasttok, e.olh, bestfix.stringify());
        else
            ERR_SIMPLE_INVALID_SYNTAX(e.justparsed, e.expected, e.lasttok, e.olh, bestfix.stringify());
        return true;
    }

    return false;
}

bool panicMode(errorstate const &e)
{
    // error recovery {{{
    // PANIC MODE START

// The following code was autogenerated - see the utils/ directory
#define CHECKASI(ty)\
    ASTNS::ty *ast##ty (dynamic_cast<ASTNS::ty*>(ast));\
    if (ast##ty)\
    {\
        switch (e.lookahead.type)\
        {
#define FINISHCHECKASI()\
        }\
    }
#define RECOVERANDDEFBREAK()\
        valid = true;\
        delto = i;\
        break;\
    default:\
        break;
    bool valid = false;
    std::vector<stackitem>::reverse_iterator delto;
    while (!valid)
    {
        for (auto i = e.stack.rbegin(); i != e.stack.rend() && !valid; ++i)
        {
            if (!i->istok && !i->isinitial)
            {
                ASTNS::AST *ast = i->ast.get();
                CHECKASI(CU)
                        case TokenType::EOF_:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(DeclList)
                        case TokenType::FUN: case TokenType::EOF_:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(Decl)
                        case TokenType::FUN: case TokenType::EOF_:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(Function)
                        case TokenType::FUN: case TokenType::EOF_:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(TypeV)
                        case TokenType::IDENTIFIER:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(Block)
                        case TokenType::FUN: case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::EOF_: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(ParamList)
                        case TokenType::CPARN: case TokenType::COMMA:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(StmtList)
                        case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(Stmt)
                        case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(EmptyStmt)
                        case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(VarStmt)
                        case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(ExprStmt)
                        case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(RetStmt)
                        case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(TypeNV)
                        case TokenType::IDENTIFIER:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(VarStmtItemList)
                        case TokenType::SEMICOLON: case TokenType::COMMA:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(Expr)
                        case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(VarStmtItem)
                        case TokenType::SEMICOLON: case TokenType::COMMA:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BuiltinTypeNoVoid)
                        case TokenType::IDENTIFIER:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BuiltinTypeVoid)
                        case TokenType::IDENTIFIER:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(ArgList)
                        case TokenType::COMMA: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(Arg)
                        case TokenType::COMMA: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(Param)
                        case TokenType::CPARN: case TokenType::COMMA:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(AssignmentExpr)
                        case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(TernaryExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BinorExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BinandExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(CompeqExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(ComplgtExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BitxorExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BitorExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BitandExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BitshiftExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER: case TokenType::DOUBLEGREATER: case TokenType::DOUBLELESS: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(AdditionExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER: case TokenType::DOUBLEGREATER: case TokenType::DOUBLELESS: case TokenType::PLUS: case TokenType::MINUS: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(MultExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER: case TokenType::DOUBLEGREATER: case TokenType::DOUBLELESS: case TokenType::PLUS: case TokenType::MINUS: case TokenType::STAR: case TokenType::SLASH: case TokenType::PERCENT: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(UnaryExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER: case TokenType::DOUBLEGREATER: case TokenType::DOUBLELESS: case TokenType::PLUS: case TokenType::MINUS: case TokenType::STAR: case TokenType::SLASH: case TokenType::PERCENT: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(CallExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER: case TokenType::DOUBLEGREATER: case TokenType::DOUBLELESS: case TokenType::PLUS: case TokenType::MINUS: case TokenType::STAR: case TokenType::SLASH: case TokenType::PERCENT: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(PrimaryExpr)
                        case TokenType::OPARN: case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER: case TokenType::DOUBLEGREATER: case TokenType::DOUBLELESS: case TokenType::PLUS: case TokenType::MINUS: case TokenType::STAR: case TokenType::SLASH: case TokenType::PERCENT: case TokenType::COLON: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
            }
        }
        if (!valid)
            e.lookahead = e.p.consume();
        if (e.lookahead.type == TokenType::EOF_)
            return false;
    }
    e.stack.erase(delto.base(), e.stack.end());
#undef CHECKASI
#undef FINISHCHECKASI
#undef RECOVERANDDEFBREAK
    if (e.w)
        ERR_PANICKING_INVALID_SYNTAX_WHILE(e.justparsed, e.expected, e.whileparsing, e.lasttok, e.lookahead);
    else
        ERR_PANICKING_INVALID_SYNTAX(e.justparsed, e.expected, e.lasttok, e.lookahead);
    return true;
// This code was autogenerated - see the utils/ directory

    // PANIC MODE END
    // }}}
}
