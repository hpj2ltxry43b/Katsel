/// @file lexer.cpp
/// Lexer method definitions and lexing methods.
/// Methods definitions to convert a character stream into a Token stream.

#include "lexer.h"

Lexer::Lexer(File &sourcefile) : start(sourcefile.source.begin()), end(sourcefile.source.begin()), nextline(1), nextcolumn(1), line(1), column(1), srcend(sourcefile.source.end()) {}

// {{{ getIdentifierType
// KWGEN START
/// Check if an idenetifier token is a keyword type and return that type, or just return TokenType::IDENTIFIER
TokenType Lexer::getIdentifierType()
{
    switch (*(start + 0))
    {
        case 'v':
            switch (*(start + 1))
            {
                case 'o':
                    switch (*(start + 2))
                    {
                        case 'i':
                            switch (*(start + 3))
                            {
                                case 'd':
                                    if (start + 4 == end) return TokenType::VOID;
                                    break;
                            }
                            break;
                        case 'l':
                            switch (*(start + 3))
                            {
                                case 'a':
                                    switch (*(start + 4))
                                    {
                                        case 't':
                                            switch (*(start + 5))
                                            {
                                                case 'i':
                                                    switch (*(start + 6))
                                                    {
                                                        case 'l':
                                                            switch (*(start + 7))
                                                            {
                                                                case 'e':
                                                                    if (start + 8 == end) return TokenType::VOLATILE;
                                                                    break;
                                                            }
                                                            break;
                                                    }
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
                case 'a':
                    switch (*(start + 2))
                    {
                        case 'r':
                            if (start + 3 == end) return TokenType::VAR;
                            break;
                    }
                    break;
            }
            break;
        case 'n':
            switch (*(start + 1))
            {
                case 'a':
                    switch (*(start + 2))
                    {
                        case 'm':
                            switch (*(start + 3))
                            {
                                case 'e':
                                    switch (*(start + 4))
                                    {
                                        case 's':
                                            switch (*(start + 5))
                                            {
                                                case 'p':
                                                    switch (*(start + 6))
                                                    {
                                                        case 'a':
                                                            switch (*(start + 7))
                                                            {
                                                                case 'c':
                                                                    switch (*(start + 8))
                                                                    {
                                                                        case 'e':
                                                                            if (start + 9 == end) return TokenType::NAMESPACE;
                                                                            break;
                                                                    }
                                                                    break;
                                                            }
                                                            break;
                                                    }
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
                case 'u':
                    switch (*(start + 2))
                    {
                        case 'l':
                            switch (*(start + 3))
                            {
                                case 'l':
                                    if (start + 4 == end) return TokenType::NULLLIT;
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
        case 'c':
            switch (*(start + 1))
            {
                case 'l':
                    switch (*(start + 2))
                    {
                        case 'a':
                            switch (*(start + 3))
                            {
                                case 's':
                                    switch (*(start + 4))
                                    {
                                        case 's':
                                            if (start + 5 == end) return TokenType::CLASS;
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
                case 'a':
                    switch (*(start + 2))
                    {
                        case 's':
                            switch (*(start + 3))
                            {
                                case 'e':
                                    if (start + 4 == end) return TokenType::CASE;
                                    break;
                            }
                            break;
                    }
                    break;
                case 'o':
                    switch (*(start + 2))
                    {
                        case 'n':
                            switch (*(start + 3))
                            {
                                case 's':
                                    switch (*(start + 4))
                                    {
                                        case 't':
                                            if (start + 5 == end) return TokenType::CONST;
                                            break;
                                    }
                                    break;
                                case 't':
                                    switch (*(start + 4))
                                    {
                                        case 'i':
                                            switch (*(start + 5))
                                            {
                                                case 'n':
                                                    switch (*(start + 6))
                                                    {
                                                        case 'u':
                                                            switch (*(start + 7))
                                                            {
                                                                case 'e':
                                                                    if (start + 8 == end) return TokenType::CONTINUE;
                                                                    break;
                                                            }
                                                            break;
                                                    }
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
                case 'h':
                    switch (*(start + 2))
                    {
                        case 'a':
                            switch (*(start + 3))
                            {
                                case 'r':
                                    if (start + 4 == end) return TokenType::CHAR;
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
        case 'e':
            switch (*(start + 1))
            {
                case 'n':
                    switch (*(start + 2))
                    {
                        case 'u':
                            switch (*(start + 3))
                            {
                                case 'm':
                                    if (start + 4 == end) return TokenType::ENUM;
                                    break;
                            }
                            break;
                    }
                    break;
                case 'l':
                    switch (*(start + 2))
                    {
                        case 's':
                            switch (*(start + 3))
                            {
                                case 'e':
                                    if (start + 4 == end) return TokenType::ELSE;
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
        case 'r':
            switch (*(start + 1))
            {
                case 'e':
                    switch (*(start + 2))
                    {
                        case 't':
                            switch (*(start + 3))
                            {
                                case 'u':
                                    switch (*(start + 4))
                                    {
                                        case 'r':
                                            switch (*(start + 5))
                                            {
                                                case 'n':
                                                    if (start + 6 == end) return TokenType::RETURN;
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
        case 't':
            switch (*(start + 1))
            {
                case 'h':
                    switch (*(start + 2))
                    {
                        case 'i':
                            switch (*(start + 3))
                            {
                                case 's':
                                    if (start + 4 == end) return TokenType::THIS;
                                    break;
                            }
                            break;
                    }
                    break;
                case 'r':
                    switch (*(start + 2))
                    {
                        case 'u':
                            switch (*(start + 3))
                            {
                                case 'e':
                                    if (start + 4 == end) return TokenType::TRUELIT;
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
        case 'w':
            switch (*(start + 1))
            {
                case 'h':
                    switch (*(start + 2))
                    {
                        case 'i':
                            switch (*(start + 3))
                            {
                                case 'l':
                                    switch (*(start + 4))
                                    {
                                        case 'e':
                                            if (start + 5 == end) return TokenType::WHILE;
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
        case 'f':
            switch (*(start + 1))
            {
                case 'o':
                    switch (*(start + 2))
                    {
                        case 'r':
                            if (start + 3 == end) return TokenType::FOR;
                            break;
                    }
                    break;
                case 'l':
                    switch (*(start + 2))
                    {
                        case 'o':
                            switch (*(start + 3))
                            {
                                case 'a':
                                    switch (*(start + 4))
                                    {
                                        case 't':
                                            if (start + 5 == end) return TokenType::FLOAT;
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
                case 'a':
                    switch (*(start + 2))
                    {
                        case 'l':
                            switch (*(start + 3))
                            {
                                case 's':
                                    switch (*(start + 4))
                                    {
                                        case 'e':
                                            if (start + 5 == end) return TokenType::FALSELIT;
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
        case 'i':
            switch (*(start + 1))
            {
                case 'f':
                    if (start + 2 == end) return TokenType::IF;
                    break;
                case 'n':
                    switch (*(start + 2))
                    {
                        case 'l':
                            switch (*(start + 3))
                            {
                                case 'i':
                                    switch (*(start + 4))
                                    {
                                        case 'n':
                                            switch (*(start + 5))
                                            {
                                                case 'e':
                                                    if (start + 6 == end) return TokenType::INLINE;
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
        case 's':
            switch (*(start + 1))
            {
                case 'w':
                    switch (*(start + 2))
                    {
                        case 'i':
                            switch (*(start + 3))
                            {
                                case 't':
                                    switch (*(start + 4))
                                    {
                                        case 'c':
                                            switch (*(start + 5))
                                            {
                                                case 'h':
                                                    if (start + 6 == end) return TokenType::SWITCH;
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
                case 'i':
                    switch (*(start + 2))
                    {
                        case 'n':
                            switch (*(start + 3))
                            {
                                case 't':
                                    switch (*(start + 4))
                                    {
                                        case '8':
                                            if (start + 5 == end) return TokenType::SINT8;
                                            break;
                                        case '1':
                                            switch (*(start + 5))
                                            {
                                                case '6':
                                                    if (start + 6 == end) return TokenType::SINT16;
                                                    break;
                                            }
                                            break;
                                        case '3':
                                            switch (*(start + 5))
                                            {
                                                case '2':
                                                    if (start + 6 == end) return TokenType::SINT32;
                                                    break;
                                            }
                                            break;
                                        case '6':
                                            switch (*(start + 5))
                                            {
                                                case '4':
                                                    if (start + 6 == end) return TokenType::SINT64;
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
        case 'd':
            switch (*(start + 1))
            {
                case 'e':
                    switch (*(start + 2))
                    {
                        case 'f':
                            switch (*(start + 3))
                            {
                                case 'a':
                                    switch (*(start + 4))
                                    {
                                        case 'u':
                                            switch (*(start + 5))
                                            {
                                                case 'l':
                                                    switch (*(start + 6))
                                                    {
                                                        case 't':
                                                            if (start + 7 == end) return TokenType::DEFAULT;
                                                            break;
                                                    }
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
                case 'o':
                    switch (*(start + 2))
                    {
                        case 'u':
                            switch (*(start + 3))
                            {
                                case 'b':
                                    switch (*(start + 4))
                                    {
                                        case 'l':
                                            switch (*(start + 5))
                                            {
                                                case 'e':
                                                    if (start + 6 == end) return TokenType::DOUBLE;
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
        case 'b':
            switch (*(start + 1))
            {
                case 'r':
                    switch (*(start + 2))
                    {
                        case 'e':
                            switch (*(start + 3))
                            {
                                case 'a':
                                    switch (*(start + 4))
                                    {
                                        case 'k':
                                                if (start + 5 == end) return TokenType::BREAK;
                                            switch (*(start + 5))
                                            {
                                                case 'a':
                                                    switch (*(start + 6))
                                                    {
                                                        case 'l':
                                                            switch (*(start + 7))
                                                            {
                                                                case 'l':
                                                                    if (start + 8 == end) return TokenType::BREAKALL;
                                                                    break;
                                                            }
                                                            break;
                                                    }
                                                    break;
                                                case 't':
                                                    switch (*(start + 6))
                                                    {
                                                        case 'o':
                                                            if (start + 7 == end) return TokenType::BREAKTO;
                                                            break;
                                                    }
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
                case 'o':
                    switch (*(start + 2))
                    {
                        case 'o':
                            switch (*(start + 3))
                            {
                                case 'l':
                                    if (start + 4 == end) return TokenType::BOOL;
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
        case 'a':
            switch (*(start + 1))
            {
                case 's':
                    switch (*(start + 2))
                    {
                        case 's':
                            switch (*(start + 3))
                            {
                                case 'e':
                                    switch (*(start + 4))
                                    {
                                        case 'r':
                                            switch (*(start + 5))
                                            {
                                                case 't':
                                                    if (start + 6 == end) return TokenType::ASSERT;
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
        case 'u':
            switch (*(start + 1))
            {
                case 'i':
                    switch (*(start + 2))
                    {
                        case 'n':
                            switch (*(start + 3))
                            {
                                case 't':
                                    switch (*(start + 4))
                                    {
                                        case '8':
                                            if (start + 5 == end) return TokenType::UINT8;
                                            break;
                                        case '1':
                                            switch (*(start + 5))
                                            {
                                                case '6':
                                                    if (start + 6 == end) return TokenType::UINT16;
                                                    break;
                                            }
                                            break;
                                        case '3':
                                            switch (*(start + 5))
                                            {
                                                case '2':
                                                    if (start + 6 == end) return TokenType::UINT32;
                                                    break;
                                            }
                                            break;
                                        case '6':
                                            switch (*(start + 5))
                                            {
                                                case '4':
                                                    if (start + 6 == end) return TokenType::UINT64;
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
    }

    return TokenType::IDENTIFIER;
}
// KWGEN END
// }}}
// {{{ helper functions
/// Return whether a character is a digit
/// @param c The character to check
bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

/// Return whether a character is a digit in a certain base
/// @param c The character to check
/// @param base The base that the character is in
bool isDigit(char c, TokenType base)
{ // overloaded method for dealing with non-decimal integer literals
    switch (base)
    {
        case TokenType::DECINTLIT:
            return isDigit(c);

        case TokenType::OCTINTLIT:
            return c >= '0' && c < '8';

        case TokenType::BININTLIT:
            return c == '0' || c == '1';

        case TokenType::HEXINTLIT:
            return isDigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');

        default: // invalid base
            return false;
    }
}

/// Return whteher a character is an alphabetic character
/// @param c The character to check
bool isAlpha(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
}
// }}}
// {{{ nextToken
Token Lexer::nextToken()
{
    start = end;

    if (atEnd()) // don't parse tokens
        return makeToken(TokenType::EOF_);

    {
        bool atWhitespace = true;
        while (atWhitespace)
        {
            char c = peek();
            switch (c)
            {
                case '\r':
                case ' ':
                case '\t':
                    advance();
                    break;

                case '\n':
                    nextLine();
                    advance();
                    break;

                case '/':
                    if (peekpeek() == '/')
                    { // check if this is a comment
                        while (peek() != '\n' && !atEnd()) advance();
                    }
                    else if (peekpeek() == '*')
                    { // multiline comment
                        // while next two characters are not * and /
                        while ((peek() != '*' || peekpeek() != '/') && !atEnd())
                        {
                            if (peek() == '\n') nextLine();
                            advance();
                        }

                        advance(); // advance twice to consume the * and /
                        advance();
                    }
                    else
                    {
                        atWhitespace = false;
                    }
                    break;

                default:
                    atWhitespace = false;
                    break;
            }

            if (atEnd())
            {
                atWhitespace = false;
            }
        }
    }

    start = end; // put this before so if file ends with whitespace then the whitespace is not included in the EOF token
    line = nextline;
    column = nextcolumn;

    if (atEnd()) // if file ends with whitespace
        return makeToken(TokenType::EOF_);

    char c = advance();

    switch (c)
    {
        case '(': return makeToken(TokenType::OPARN);
        case ')': return makeToken(TokenType::CPARN);
        case '[': return makeToken(TokenType::OSQUB);
        case ']': return makeToken(TokenType::CSQUB);
        case '{': return makeToken(TokenType::OCURB);
        case '}': return makeToken(TokenType::CCURB);
        case ',': return makeToken(TokenType::COMMA);
        case '.': return makeToken(TokenType::PERIOD);
        case ';': return makeToken(TokenType::SEMICOLON);
        case '?': return makeToken(TokenType::QUESTION);
        case '~': return makeToken(TokenType::TILDE);

                  // double and single
        case '=': return makeToken(match('=') ? TokenType::DOUBLEEQUAL : TokenType::EQUAL);
        case ':': return makeToken(match(':') ? TokenType::DOUBLECOLON : TokenType::COLON);

                  // equal and single
        case '*': return makeToken(match('=') ? TokenType::STAREQUAL : TokenType::STAR);
        case '/': return makeToken(match('=') ? TokenType::SLASHEQUAL : TokenType::SLASH);
        case '!': return makeToken(match('=') ? TokenType::BANGEQUAL : TokenType::BANG);
        case '%': return makeToken(match('=') ? TokenType::PERCENTEQUAL : TokenType::PERCENT);
        case '^': return makeToken(match('=') ? TokenType::CARETEQUAL : TokenType::CARET);

                  // double and equal and single
                  //        if matches double ? return double         : is not double so check if it has equals after it
        case '+': return makeToken(match('+') ? TokenType::DOUBLEPLUS : (match('=') ? TokenType::PLUSEQUAL : TokenType::PLUS));
        case '-': return makeToken(match('-') ? TokenType::DOUBLEMINUS : (match('=') ? TokenType::MINUSEQUAL : TokenType::MINUS));
        case '&': return makeToken(match('&') ? TokenType::DOUBLEAMPER : (match('=') ? TokenType::AMPEREQUAL : TokenType::AMPER));
        case '|': return makeToken(match('|') ? TokenType::DOUBLEPIPE : (match('=') ? TokenType::PIPEEQUAL : TokenType::PIPE));

                  // double, doubleequal, singleequal, single
                  //        if matches double ? (is double so check if it has equal after it                          ) : (is not double so check if it has equal after it          )
        case '>': return makeToken(match('>') ? (match('=') ? TokenType::DOUBLEGREATEREQUAL : TokenType::DOUBLEGREATER) : (match('=') ? TokenType::GREATEREQUAL : TokenType::GREATER));
                  //        if matches double ? (is double so check if it has equal after it                    ) : (is not double so check if it has equal after it    )
        case '<': return makeToken(match('<') ? (match('=') ? TokenType::DOUBLELESSEQUAL : TokenType::DOUBLELESS) : (match('=') ? TokenType::LESSEQUAL : TokenType::LESS));

        case 'c': // check for char literal
                  if (match('\'') || match('"'))
                  { // should consume quote
                      char startingQuote = consumed();
                      advance(); // consume character

                      if (!match(startingQuote)) return makeErrorToken("Unterminated single-character literal");

                      return makeToken(TokenType::CHARLIT);
                  }
                  break;

        case '"':
        case '\'':
                  // c is the starting string thing
                  while (peek() != c && !atEnd() && peek() != '\n')
                  {
                      advance();
                  }

                  if (peek() != c) return makeErrorToken("Unterminated string literal");
                  advance(); // consume closing quote/apostrophe
                  return makeToken(TokenType::STRINGLIT);
    }

    if (isDigit(c))
    { // check for number literal
        TokenType inttype;

        if (isDigit(peek()) || c != '0' || !isAlpha(peek()))
        {
            inttype = TokenType::DECINTLIT;
        }
        else
        {
            switch (peek())
            {
                case 'o': inttype = TokenType::OCTINTLIT; break;
                case 'b': inttype = TokenType::BININTLIT; break;
                case 'x': inttype = TokenType::HEXINTLIT; break;

                default:
                          return makeErrorToken("Invalid number literal type (must be 0o, 0b, or 0x)");
            }

            advance(); // consume o, b, or x
        }

        while (isDigit(peek(), inttype) && !atEnd()) advance();

        if (peek() == '.' && isDigit(peekpeek(), inttype) && !atEnd())
        { // is actually a decimal and is not integer literal
            advance(); // consume decimal point

            while (isDigit(peek(), inttype) && !atEnd()) advance();

            if (inttype != TokenType::DECINTLIT) return makeErrorToken("Non-decimal floating point literals are not supported");

            return makeToken(TokenType::FLOATLIT);
        }

        return makeToken(inttype);
    }
    else if (isAlpha(c))
    {
        while (isAlpha(peek()) || isDigit(peek())) advance();

        TokenType idenType = getIdentifierType();


        return makeToken(idenType);
    }

    return makeErrorToken("Unexpected character");
}
// }}}
// {{{ other helpers
bool Lexer::atEnd()
{
    return end >= srcend;
}

bool Lexer::match(char c)
{
    if (atEnd())
        return false;

    if (peek() == c)
    {
        advance();
        return true;
    }

    return false;
}

char Lexer::advance()
{
    ++nextcolumn;

    return *(end++);
}

char Lexer::peek()
{
    return *(end);
}

char Lexer::consumed()
{
    return *(end - 1);
}

char Lexer::peekpeek()
{
    return *(end + 1);
}

Token Lexer::makeErrorToken(std::string message)
{
    Token token = makeToken(TokenType::ERROR);

    token.message = message;

    return token;
}

Token Lexer::makeToken(TokenType type)
{
    Token token;

    token.type = type;
    token.start = start;
    token.end = end;
    token.line = line;
    token.column = column - 1;

    return token;
}

void Lexer::nextLine()
{
    ++nextline;
    nextcolumn = 1;
}
// }}}


