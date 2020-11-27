#pragma once
#include <vector>
#include <memory>
#include "lex/token.h"
#include "parse/parser.h"

struct stackitem
{
    inline stackitem(size_t state): state(state), istok(false), isinitial(true) {}
    inline stackitem(size_t state, Token const &t): state(state), istok(true), isinitial(false), tok(t) {}
    inline stackitem(size_t state, std::unique_ptr<ASTNS::AST> ast): state(state), istok(false), isinitial(false), ast(std::move(ast)) {}
    int state;
    bool istok;
    bool isinitial;
    Token tok;
    std::unique_ptr<ASTNS::AST> ast;
};

struct errorstate
{
    Parser &p;
    std::vector<stackitem> &stack;
    Token const &lasttok;
    Token &lookahead;
    std::string const &justparsed, &expected, &whileparsing;

    inline errorstate(Parser &p, std::vector<stackitem> &stack, Token &lasttok, Token &lookahead, std::string const &justparsed, std::string const &expected, std::string const &whileparsing="")
        : p(p), stack(stack), lasttok(lasttok), lookahead(lookahead), justparsed(justparsed), expected(expected), whileparsing(whileparsing) {}
};

bool errorRecovery(errorstate const &e);
bool singleTok(errorstate const &e);
bool panicMode(errorstate const &e);

template <typename AST>
size_t getGoto(size_t state);
bool _parse(Parser &p, std::vector<stackitem> &stack, bool istrial, std::unique_ptr<ASTNS::DeclB> &out, Token const &_lookahead);
