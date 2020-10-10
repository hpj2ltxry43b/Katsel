#include "parser.h"
#include "ast.h"

#include "errors.h"

// even though everything else is recursive descent,
// expressions are parsed with a Pratt parser, because I don't
// wnat to repeat the function call mess that was the first
// recursive descent only parser. it'll work either way
// as long as it returns a valid parse tree

const std::map<TokenType, Parser::PrefixPF> Parser::prefixParserTable = {
    {TokenType::BANG,  &Parser::prefixOp},
    {TokenType::TILDE, &Parser::prefixOp},
    {TokenType::MINUS, &Parser::prefixOp},

    {TokenType::TRUELIT,       &Parser::primary},
    {TokenType::FALSELIT,      &Parser::primary},
    {TokenType::FLOATLIT,      &Parser::primary},
    {TokenType::NULLLIT,       &Parser::primary},
    {TokenType::DECINTLIT,     &Parser::primary},
    {TokenType::OCTINTLIT,     &Parser::primary},
    {TokenType::BININTLIT,     &Parser::primary},
    {TokenType::HEXINTLIT,     &Parser::primary},
    {TokenType::CHARLIT,       &Parser::primary},
    {TokenType::STRINGLIT,     &Parser::primary},
    {TokenType::OPARN,         &Parser::parenExpr},
};

const std::map<TokenType, Parser::NonPrefixPF> Parser::nonPrefixTable = {
    {TokenType::EQUAL,         &Parser::binaryOp}, // TODO: right associative
    {TokenType::QUESTION,      &Parser::ternaryOp},
    {TokenType::DOUBLEPIPE,    &Parser::binaryOp},
    {TokenType::DOUBLEAMPER,   &Parser::binaryOp},
    {TokenType::DOUBLEEQUAL,   &Parser::binaryOp},
    {TokenType::BANGEQUAL,     &Parser::binaryOp},
    {TokenType::LESS,          &Parser::binaryOp},
    {TokenType::GREATER,       &Parser::binaryOp},
    {TokenType::LESSEQUAL,     &Parser::binaryOp},
    {TokenType::GREATEREQUAL,  &Parser::binaryOp},
    {TokenType::CARET,         &Parser::binaryOp},
    {TokenType::PIPE,          &Parser::binaryOp},
    {TokenType::AMPER,         &Parser::binaryOp},
    {TokenType::DOUBLEGREATER, &Parser::binaryOp},
    {TokenType::DOUBLELESS,    &Parser::binaryOp},
    {TokenType::PLUS,          &Parser::binaryOp},
    {TokenType::MINUS,         &Parser::binaryOp},
    {TokenType::STAR,          &Parser::binaryOp},
    {TokenType::SLASH,         &Parser::binaryOp},
    {TokenType::PERCENT,       &Parser::binaryOp},
};

static const std::map<TokenType, int> precedenceTable = {
    {TokenType::EQUAL,         1},
    {TokenType::QUESTION,      2},
    {TokenType::DOUBLEPIPE,    3},
    {TokenType::DOUBLEAMPER,   4},
    {TokenType::BANG,          5},
    {TokenType::DOUBLEEQUAL,   6},
    {TokenType::BANGEQUAL,     6},
    {TokenType::LESS,          7},
    {TokenType::GREATER,       7},
    {TokenType::LESSEQUAL,     7},
    {TokenType::GREATEREQUAL,  7},
    {TokenType::CARET,         8},
    {TokenType::PIPE,          9},
    {TokenType::AMPER,         10},
    {TokenType::DOUBLEGREATER, 11},
    {TokenType::DOUBLELESS,    11},
    {TokenType::PLUS,          12},
    {TokenType::MINUS,         12},
    {TokenType::STAR,          13},
    {TokenType::SLASH,         13},
    {TokenType::PERCENT,       13},
    {TokenType::TILDE,         14},
    {TokenType::MINUS,         14},
    {TokenType::TRUELIT,       15},
    {TokenType::FALSELIT,      15},
    {TokenType::FLOATLIT,      15},
    {TokenType::NULLLIT,       15},
    {TokenType::DECINTLIT,     15},
    {TokenType::OCTINTLIT,     15},
    {TokenType::BININTLIT,     15},
    {TokenType::HEXINTLIT,     15},
    {TokenType::CHARLIT,       15},
    {TokenType::STRINGLIT,     15},
    {TokenType::OPARN,         15},
};

std::unique_ptr<ASTNS::Expr> Parser::prefixOp()
{
    Token op = prev();
    std::unique_ptr<ASTNS::Expr> operand = expr();
    return std::make_unique<ASTNS::UnaryExpr>(std::move(operand), op);
}

std::unique_ptr<ASTNS::Expr> Parser::primary()
{
    return std::make_unique<ASTNS::PrimaryExpr>(prev());
}

std::unique_ptr<ASTNS::Expr> Parser::parenExpr()
{
    std::unique_ptr<ASTNS::Expr> e (expr());
    assertConsume(TokenType::CPARN, "Expected closing parentheses");

    return e;
}

std::unique_ptr<ASTNS::Expr> Parser::binaryOp(std::unique_ptr<ASTNS::Expr> left)
{
    Token op = prev();
    std::unique_ptr<ASTNS::Expr> right = expr();
    return std::make_unique<ASTNS::BinaryExpr>(std::move(left), std::move(right), op);
}

std::unique_ptr<ASTNS::Expr> Parser::ternaryOp(std::unique_ptr<ASTNS::Expr> cond)
{
    std::unique_ptr<ASTNS::Expr> trues = expr();
    assertConsume(TokenType::COLON, "Expected colon after true expression of ternary expression");
    std::unique_ptr<ASTNS::Expr> falses = expr();

    return std::make_unique<ASTNS::TernaryExpr>(std::move(cond), std::move(trues), std::move(falses));
}

std::unique_ptr<ASTNS::Expr> Parser::expr(int prec)
{
    Token t = consume();

    auto prefixParser = prefixParserTable.find(t.type);

    if (prefixParser == prefixParserTable.end())
    {
        reportError(prev(), "Expected primary or unary operator", sourcefile);
        return nullptr;
    }

    std::unique_ptr<ASTNS::Expr> lhs = (this->*(prefixParser->second))();

    while (prec < curPrec())
    {
        Token nonPrefixOp = consume();
        auto nonPrefixParser = nonPrefixTable.find(nonPrefixOp.type);

        if (nonPrefixParser == nonPrefixTable.end())
            return lhs;

        lhs = (this->*(nonPrefixParser->second))(std::move(lhs));
    }

    return lhs;
}

int Parser::curPrec()
{
    int prec;
    try
    {
        prec = precedenceTable.at(peek().type);
    }
    catch (std::out_of_range e)
    {
        return 0;
    }

    return prec;
}
