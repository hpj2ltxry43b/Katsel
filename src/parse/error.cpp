#include "parsestack.h"
#include "message/errmsgs.h"

#include "utils/format.h"

bool error_recovery(errorstate const &e, std::vector<std::string> const &expectations) {
    if (single_tok(e, expectations) || panic_mode(e, expectations))
        return true;
    else {
        ERR_UNRECOVERABLE_INVALID_SYNTAX(e.olh, e.lasttok, expectations);
        return false;
    }
}

// helper functions {{{
static std::vector<stackitem> copy_stack(std::vector<stackitem> const &stack) {
    std::vector<stackitem> tempstack;
    for (auto const &si : stack) {
        tempstack.emplace_back(si.state);
    }
    return tempstack;
}

static bool try_insert(TokenType ty, Parser const &p, Token const &lookahead, std::vector<stackitem> const &stack) {
    // TODO: fix these b/c with new indentation you cant reset the lexer to a previous token
    // Lexer temp_l (lookahead);
    // Parser temp_p (temp_l, p.sourcefile);
    // Token temp_lookahead (lookahead);
    // temp_lookahead.type = ty;

    // auto tempstack (copy_stack(stack));

    // std::unique_ptr<ASTNS::CUB> temp_c (nullptr);

    // return _parse(temp_p, tempstack, true, temp_c, temp_lookahead);
    return false;
}

static bool try_del(Parser const &p, std::vector<stackitem> const &stack) {
    // Lexer temp_l (p.lexer);
    // Parser temp_p (temp_l, p.sourcefile);
    // Token temp_lookahead (temp_p.consume());

    // auto tempstack (copy_stack(stack));

    // std::unique_ptr<ASTNS::CUB> temp_c (nullptr);

    // return _parse(temp_p, tempstack, true, temp_c, temp_lookahead);
    return false;
}

static bool try_sub(TokenType ty, Parser const &p, Token const &lookahead, std::vector<stackitem> const &stack) {
    // Lexer temp_l (p.lexer);
    // Parser temp_p (temp_l, p.sourcefile);
    // Token temp_lookahead (lookahead);
    // temp_lookahead.type = ty;

    // auto tempstack (copy_stack(stack));

    // std::unique_ptr<ASTNS::CUB> temp_c (nullptr);

    // return _parse(temp_p, tempstack, true, temp_c, temp_lookahead);
    return false;
}
// }}}
struct fix {
    enum class fixtype {
        INSERT,
        REMOVE,
        SUBSTITUTE,
        NOFIX,
    } type;
    TokenType ttype;

    std::string stringify() const {
        switch (type) {
            case fix::fixtype::REMOVE:
                return "implicitly removed token";

            case fix::fixtype::SUBSTITUTE:
                return format("implicitly replaced token with {}", stringify_token_type(ttype));

            case fix::fixtype::INSERT:
                return format("implicitly inserted {} before token", stringify_token_type(ttype));

            default:
                report_abort_noh("invalid fix type");
        }
    }
};

static void apply_fix(fix const &f, Parser &p, Token &lookahead) {
    switch (f.type) {
        case fix::fixtype::REMOVE:
            lookahead = p.consume();
            break;

        case fix::fixtype::SUBSTITUTE:
            lookahead.type = f.ttype;
            break;

        case fix::fixtype::INSERT:
            // TODO: fix
            // p.lexer.reset_to_tok(lookahead);
            lookahead.type = f.ttype;
            break;

        default:
            report_abort_noh("attempt to apply invalid fix type");
    }
}

bool single_tok(errorstate const &e, std::vector<std::string> const &expectations) {
    fix bestfix = fix {fix::fixtype::NOFIX, static_cast<TokenType>(-1)};
    auto score = [](fix const &f) {
        switch (f.type) {
            case fix::fixtype::REMOVE:
                return 0;
            case fix::fixtype::SUBSTITUTE:
                return 1;
            case fix::fixtype::INSERT:
                return 2;
            case fix::fixtype::NOFIX:
                return -1;
            default:
                report_abort_noh("invalid fix type");
        }
    };

    // error recovery {{{
    // SINGLETOK START
#define TRYINSERT(ty) if (try_insert(ty, e.p, e.lookahead, e.stack)) {fix f = fix {fix::fixtype::INSERT, ty}; if (score(f) > score(bestfix)) bestfix = f;}
#define TRYSUB(ty) if (try_sub(ty, e.p, e.lookahead, e.stack)) {fix f = fix {fix::fixtype::SUBSTITUTE, ty}; if (score(f) > score(bestfix)) bestfix = f;}
#define TRYTOKTY(ty) TRYINSERT(ty); TRYSUB(ty);
    TRYTOKTY(TokenType::EOF_)
    TRYTOKTY(TokenType::COMMA)
    TRYTOKTY(TokenType::FUN)
    TRYTOKTY(TokenType::IDENTIFIER)
    TRYTOKTY(TokenType::OPARN)
    TRYTOKTY(TokenType::CPARN)
    TRYTOKTY(TokenType::IMPL)
    TRYTOKTY(TokenType::OCURB)
    TRYTOKTY(TokenType::CCURB)
    TRYTOKTY(TokenType::NEWLINE)
    TRYTOKTY(TokenType::INDENT)
    TRYTOKTY(TokenType::DEDENT)
    TRYTOKTY(TokenType::VAR)
    TRYTOKTY(TokenType::DOLLAR)
    TRYTOKTY(TokenType::RETURN)
    TRYTOKTY(TokenType::EQUAL)
    TRYTOKTY(TokenType::MUT)
    TRYTOKTY(TokenType::SEMICOLON)
    TRYTOKTY(TokenType::STAR)
    TRYTOKTY(TokenType::THIS)
    TRYTOKTY(TokenType::COLON)
    TRYTOKTY(TokenType::IF)
    TRYTOKTY(TokenType::ELSE)
    TRYTOKTY(TokenType::WHILE)
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
    TRYTOKTY(TokenType::SLASH)
    TRYTOKTY(TokenType::PERCENT)
    TRYTOKTY(TokenType::RIGHTARROW)
    TRYTOKTY(TokenType::TILDE)
    TRYTOKTY(TokenType::BANG)
    TRYTOKTY(TokenType::PERIOD)
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
    TRYTOKTY(TokenType::DOUBLECOLON)
    if (try_del(e.p, e.stack)) {fix f = fix {fix::fixtype::REMOVE, static_cast<TokenType>(-1)}; if (score(f) > score(bestfix)) bestfix = f;};
    // SINGLETOK END
    // }}}

    if (bestfix.type != fix::fixtype::NOFIX) {
        apply_fix(bestfix, e.p, e.lookahead);
        ERR_SIMPLE_INVALID_SYNTAX(e.olh, e.lasttok, bestfix.stringify(), expectations);
        return true;
    }

    return false;
}

bool panic_mode(errorstate const &e, std::vector<std::string> const &expectations) {
    // error recovery {{{
    // PANIC MODE START
#define CHECKASI(ty)\
    if (nterm == NonTerminal::ty) {\
        switch (e.lookahead.type) {
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
    e.lookahead = e.p.consume(); // prevent infinite panicking loops
    std::vector<stackitem>::reverse_iterator delto;
    while (!valid) {
        for (auto i = e.stack.rbegin(); i != e.stack.rend() && !valid; ++i) {
            if (std::holds_alternative<astitem>(i->item)) {
                NonTerminal nterm = std::get<astitem>(i->item).nt;
                CHECKASI(_49)
                        case TokenType::COMMA: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_21)
                        case TokenType::COMMA: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_51)
                        case TokenType::COMMA: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_50)
                        case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_52)
                        case TokenType::COMMA: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_20)
                        case TokenType::COMMA: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_54)
                        case TokenType::COMMA: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_53)
                        case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_55)
                        case TokenType::COMMA: case TokenType::NEWLINE: case TokenType::SEMICOLON:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_57)
                        case TokenType::COMMA: case TokenType::NEWLINE: case TokenType::SEMICOLON:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_56)
                        case TokenType::NEWLINE: case TokenType::SEMICOLON:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_58)
                        case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::IF: case TokenType::WHILE: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::AMPER: case TokenType::STAR: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::THIS: case TokenType::OPARN: case TokenType::IDENTIFIER: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_6)
                        case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::IF: case TokenType::WHILE: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::AMPER: case TokenType::STAR: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::THIS: case TokenType::OPARN: case TokenType::IDENTIFIER: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_59)
                        case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::IF: case TokenType::WHILE: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::AMPER: case TokenType::STAR: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::THIS: case TokenType::OPARN: case TokenType::IDENTIFIER: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_60)
                        case TokenType::FUN: case TokenType::IMPL: case TokenType::EOF_:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_1)
                        case TokenType::FUN: case TokenType::IMPL: case TokenType::EOF_:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_61)
                        case TokenType::FUN: case TokenType::IMPL: case TokenType::EOF_:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_62)
                        case TokenType::FUN: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_5)
                        case TokenType::FUN: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_63)
                        case TokenType::FUN: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_7)
                        case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::IF: case TokenType::WHILE: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::AMPER: case TokenType::STAR: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::THIS: case TokenType::OPARN: case TokenType::IDENTIFIER: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_2)
                        case TokenType::FUN: case TokenType::IMPL: case TokenType::EOF_: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_3)
                        case TokenType::FUN: case TokenType::IMPL: case TokenType::EOF_:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_12)
                        case TokenType::NEWLINE: case TokenType::SEMICOLON: case TokenType::FUN: case TokenType::IMPL: case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::IF: case TokenType::WHILE: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::AMPER: case TokenType::STAR: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::THIS: case TokenType::OPARN: case TokenType::IDENTIFIER: case TokenType::DOLLAR: case TokenType::COMMA: case TokenType::ELSE: case TokenType::EOF_: case TokenType::CPARN: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_4)
                        case TokenType::NEWLINE: case TokenType::SEMICOLON: case TokenType::FUN: case TokenType::IMPL: case TokenType::EOF_:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_8)
                        case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::IF: case TokenType::WHILE: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::AMPER: case TokenType::STAR: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::THIS: case TokenType::OPARN: case TokenType::IDENTIFIER: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_9)
                        case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::IF: case TokenType::WHILE: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::AMPER: case TokenType::STAR: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::THIS: case TokenType::OPARN: case TokenType::IDENTIFIER: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_13)
                        case TokenType::NEWLINE: case TokenType::SEMICOLON: case TokenType::FUN: case TokenType::IMPL: case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::IF: case TokenType::WHILE: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::AMPER: case TokenType::STAR: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::THIS: case TokenType::OPARN: case TokenType::IDENTIFIER: case TokenType::DOLLAR: case TokenType::COMMA: case TokenType::ELSE: case TokenType::EOF_: case TokenType::CPARN: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_14)
                        case TokenType::NEWLINE: case TokenType::SEMICOLON: case TokenType::FUN: case TokenType::IMPL: case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::IF: case TokenType::WHILE: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::AMPER: case TokenType::STAR: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::THIS: case TokenType::OPARN: case TokenType::IDENTIFIER: case TokenType::DOLLAR: case TokenType::COMMA: case TokenType::ELSE: case TokenType::EOF_: case TokenType::CPARN: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_23)
                        case TokenType::COMMA: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_22)
                        case TokenType::COMMA: case TokenType::CPARN:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_27)
                        case TokenType::NEWLINE: case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::IF: case TokenType::WHILE: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::AMPER: case TokenType::STAR: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::THIS: case TokenType::OPARN: case TokenType::IDENTIFIER: case TokenType::DOLLAR: case TokenType::COMMA: case TokenType::CPARN: case TokenType::CCURB: case TokenType::DEDENT:
                            RECOVERANDDEFBREAK()
                FINISHCHECKASI()
                CHECKASI(_28)
                        case TokenType::NEWLINE: case TokenType::SEMICOLON: case TokenType::VAR: case TokenType::RETURN: case TokenType::OCURB: case TokenType::IF: case TokenType::WHILE: case TokenType::TILDE: case TokenType::MINUS: case TokenType::BANG: case TokenType::AMPER: case TokenType::STAR: case TokenType::TRUELIT: case TokenType::FALSELIT: case TokenType::FLOATLIT: case TokenType::NULLPTRLIT: case TokenType::DECINTLIT: case TokenType::OCTINTLIT: case TokenType::BININTLIT: case TokenType::HEXINTLIT: case TokenType::CHARLIT: case TokenType::STRINGLIT: case TokenType::THIS: case TokenType::OPARN: case TokenType::IDENTIFIER: case TokenType::DOLLAR: case TokenType::COMMA: case TokenType::CPARN: case TokenType::CCURB: case TokenType::DEDENT:
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
    ERR_PANICKING_INVALID_SYNTAX(e.olh, e.lasttok, e.lookahead, expectations);
    return true;
    // PANIC MODE END
    // }}}
}
