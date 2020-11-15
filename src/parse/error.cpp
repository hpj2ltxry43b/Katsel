#include "parsestack.h"

bool errorRecovery(Parser &p, std::vector<stackitem> &stack, Token &lookahead, Error &e)
{
    if (singleTok(p, stack, lookahead, e))
        return true;
    else
        return panicMode(p, stack, lookahead, e);
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

static bool tryInsert(TokenType ty, Parser const &p, Token const &lookahead, std::vector<stackitem> const &stack, Error &e)
{
    Lexer tempL (lookahead);
    Parser tempP (tempL, p.sourcefile);
    Token tempLookahead (lookahead);
    tempLookahead.type = ty;

    auto tempstack (copyStack(stack));

    std::unique_ptr<ASTNS::Decls> tempD (nullptr);

    bool success;
    if ((success = _parse(tempP, tempstack, true, tempD, tempLookahead)))
        e.underline(Error::Underline(tempLookahead, '^').hint(concatMsg("insert ", stringifyTokenType(ty), " before here")));

    return success;
}

static bool tryDel(Parser const &p, Token const &lookahead, std::vector<stackitem> const &stack, Error &e)
{
    Lexer tempL (p.lexer);
    Parser tempP (tempL, p.sourcefile);
    Token tempLookahead (tempP.consume());

    auto tempstack (copyStack(stack));

    std::unique_ptr<ASTNS::Decls> tempD (nullptr);

    bool success;
    if ((success = _parse(tempP, tempstack, true, tempD, tempLookahead)))
        e.underline(Error::Underline(lookahead, '^').hint("delete this token"));

    return success;
}

static bool trySub(TokenType ty, Parser const &p, Token const &lookahead, std::vector<stackitem> const &stack, Error &e)
{
    Lexer tempL (p.lexer);
    Parser tempP (tempL, p.sourcefile);
    Token tempLookahead (lookahead);
    tempLookahead.type = ty;

    auto tempstack (copyStack(stack));

    std::unique_ptr<ASTNS::Decls> tempD (nullptr);

    bool success;
    if ((success = _parse(tempP, tempstack, true, tempD, tempLookahead)))
        e.underline(Error::Underline(tempLookahead, '^').hint(concatMsg("replace this token with ", stringifyTokenType(ty))));

    return success;
}
struct fix
{
    enum class fixtype
    {
        INSERT,
        REMOVE,
        SUBSTITUTE
    } type;
    TokenType ttype;
};
static void applyFix(fix const &f, Parser &p, Token &lookahead, Error &e)
{
    if (f.type == fix::fixtype::REMOVE)
    {
        lookahead = p.consume();
    }
    else if (f.type == fix::fixtype::SUBSTITUTE)
    {
        lookahead.type = f.ttype;
    }
    else
    {
        p.lexer.resetToTok(lookahead);
        lookahead.type = f.ttype;
    }
}
// }}}

bool singleTok(Parser &p, std::vector<stackitem> &stack, Token &lookahead, Error &e)
{
    std::vector<fix> fixes;

    // error recovery {{{
    // SINGLETOK START

// The following code was autogenerated - see the utils/ directory
#define TRYINSERT(ty) if (tryInsert(ty, p, lookahead, stack, e)) fixes.push_back(fix {fix::fixtype::INSERT, ty});;
#define TRYSUB(ty) if (trySub(ty, p, lookahead, stack, e)) fixes.push_back(fix {fix::fixtype::SUBSTITUTE, ty});;
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
    TRYTOKTY(TokenType::VOID)
    TRYTOKTY(TokenType::CHAR)
    TRYTOKTY(TokenType::QUESTION)
    TRYTOKTY(TokenType::COLON)
    TRYTOKTY(TokenType::DOUBLEPIPE)
    TRYTOKTY(TokenType::DOUBLEAMPER)
    TRYTOKTY(TokenType::BANG)
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
    if (tryDel(p, lookahead, stack, e)) fixes.push_back(fix {fix::fixtype::REMOVE});
// This code was autogenerated - see the utils/ directory

    // SINGLETOK END
    // }}}

    auto score = [](fix const &f)
    {
        if (f.type == fix::fixtype::REMOVE)
            return 0;
        else if (f.type == fix::fixtype::SUBSTITUTE)
            return 1;
        else
            return 2;
    };
    std::sort(fixes.begin(), fixes.end(), [&score](fix const &f1, fix const &f2)
            {
            int f1score (score(f1)), f2score (score(f2));
            return f1score > f2score;
            });

    if (fixes.size())
    {
        applyFix(fixes.front(), p, lookahead, e);
        return true;
    }

    return false;
}

bool panicMode(Parser &p, std::vector<stackitem> &stack, Token &lookahead, Error &e)
{
    // error recovery {{{
    // PANIC MODE START

// The following code was autogenerated - see the utils/ directory
#define CHECKASI(ty)\
    ASTNS::ty *ast##ty (dynamic_cast<ASTNS::ty*>(ast));\
    if (ast##ty)\
    {\
        switch (lookahead.type)\
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
#define SITOLOC(v)\
    Location v##l ({}, {}, nullptr);\
    if (v->istok)\
        v##l = v->tok;\
    else\
        v##l = v->ast.get();
    bool valid = false;
    std::vector<stackitem>::reverse_iterator delto;
    while (!valid)
    {
        for (auto i = stack.rbegin(); i != stack.rend() && !valid; ++i)
        {
            if (!i->istok)
            {
                ASTNS::AST *ast = i->ast.get();
                CHECKASI(Decls)
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
                CHECKASI(Type)
                        case TokenType::IDENTIFIER:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(Block)
                        case TokenType::FUN: case TokenType::EOF_: case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::BANG: case TokenType::TILDE: case TokenType::MINUS: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::RETURN: case TokenType::OCURB: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(ParamList)
                        case TokenType::CPARN: case TokenType::COMMA:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(Stmts)
                        case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::BANG: case TokenType::TILDE: case TokenType::MINUS: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::RETURN: case TokenType::OCURB: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(Stmt)
                        case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::BANG: case TokenType::TILDE: case TokenType::MINUS: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::RETURN: case TokenType::OCURB: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(EmptyStmt)
                        case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::BANG: case TokenType::TILDE: case TokenType::MINUS: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::RETURN: case TokenType::OCURB: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(VarStmt)
                        case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::BANG: case TokenType::TILDE: case TokenType::MINUS: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::RETURN: case TokenType::OCURB: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(ExprStmt)
                        case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::BANG: case TokenType::TILDE: case TokenType::MINUS: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::RETURN: case TokenType::OCURB: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(RetStmt)
                        case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::BANG: case TokenType::TILDE: case TokenType::MINUS: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::IDENTIFIER: case TokenType::OPARN: case TokenType::RETURN: case TokenType::OCURB: case TokenType::CCURB:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(VarStmtItems)
                        case TokenType::SEMICOLON: case TokenType::COMMA:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(Expr)
                        case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(VarStmtItem)
                        case TokenType::SEMICOLON: case TokenType::COMMA:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BuiltinType)
                        case TokenType::IDENTIFIER:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(Args)
                        case TokenType::COMMA: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(AssignmentExpr)
                        case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(TernaryExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BinorExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BinandExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BinnotExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(CompeqExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(ComplgtExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BitxorExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BitorExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BitandExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(BitshiftExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER: case TokenType::DOUBLEGREATER: case TokenType::DOUBLELESS:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(AdditionExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER: case TokenType::DOUBLEGREATER: case TokenType::DOUBLELESS: case TokenType::PLUS: case TokenType::MINUS:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(MultExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER: case TokenType::DOUBLEGREATER: case TokenType::DOUBLELESS: case TokenType::PLUS: case TokenType::MINUS: case TokenType::STAR: case TokenType::SLASH: case TokenType::PERCENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(UnaryExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER: case TokenType::DOUBLEGREATER: case TokenType::DOUBLELESS: case TokenType::PLUS: case TokenType::MINUS: case TokenType::STAR: case TokenType::SLASH: case TokenType::PERCENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(CallExpr)
                        case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER: case TokenType::DOUBLEGREATER: case TokenType::DOUBLELESS: case TokenType::PLUS: case TokenType::MINUS: case TokenType::STAR: case TokenType::SLASH: case TokenType::PERCENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(PrimaryExpr)
                        case TokenType::OPARN: case TokenType::EQUAL: case TokenType::SEMICOLON: case TokenType::COMMA: case TokenType::CPARN: case TokenType::COLON: case TokenType::QUESTION: case TokenType::DOUBLEPIPE: case TokenType::DOUBLEAMPER: case TokenType::BANGEQUAL: case TokenType::DOUBLEEQUAL: case TokenType::LESS: case TokenType::GREATER: case TokenType::LESSEQUAL: case TokenType::GREATEREQUAL: case TokenType::CARET: case TokenType::PIPE: case TokenType::AMPER: case TokenType::DOUBLEGREATER: case TokenType::DOUBLELESS: case TokenType::PLUS: case TokenType::MINUS: case TokenType::STAR: case TokenType::SLASH: case TokenType::PERCENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
            }
        }
        if (!valid)
            lookahead = p.consume();
        if (lookahead.type == TokenType::EOF_)
            return false;
    }
    stackitem *startabandon = &*delto.base();
    stackitem *endabandon = &*stack.end() - 1;
    SITOLOC(startabandon)
    SITOLOC(endabandon)
    e.underline(Error::Underline(Location(startabandonl.start, endabandonl.end, startabandonl.file), '~').note("erroneous syntax: abandoned this construct"));
    e.underline(Error::Underline(lookahead, '-').note("parser panicked until here"));
    stack.erase(delto.base(), stack.end());
#undef CHECKASI
#undef FINISHCHECKASI
#undef RECOVERANDDEFBREAK
    return true;
// This code was autogenerated - see the utils/ directory

    // PANIC MODE END
    // }}}
}
