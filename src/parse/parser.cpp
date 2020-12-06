#include "parse/parser.h"
#include "parsestack.h"

#include "lex/tokentype.h"
#include "message/errors.h"

#include <sstream>

Parser::Parser(Lexer &l, File &sourcefile): lexer(l), sourcefile(sourcefile), errored(false) {}

std::unique_ptr<ASTNS::CUB> Parser::parse()
{
    std::unique_ptr<ASTNS::CUB> ret (nullptr);

    std::vector<stackitem> stack;
    stack.emplace_back(0);

    _parse(*this, stack, false, ret, consume());

    if (errored)
        return nullptr;

    return ret;
}

Token Parser::consume()
{
    Token cur;
    while (true)
    {
        cur = lexer.nextToken();
        if (cur.type != TokenType::ERROR) return cur;

        errored = true;
        cur.errf(cur);
    }

    return cur;
}
