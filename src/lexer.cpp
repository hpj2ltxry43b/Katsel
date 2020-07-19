#include "lexer.h"

Lexer::Lexer(std::string &source) : start(source.begin()), end(source.begin()), nextline(1), nextcolumn(1), line(1), column(1), srcend(source.end()){ }

TokenType Lexer::checkKeyword(int start, std::string compareTo, TokenType type) {
  if (std::string(this->start + start, end) == compareTo) {
    return type;
  }

  return TokenType::IDENTIFIER;
}

TokenType Lexer::getIdentifierType() {
    return TokenType::IDENTIFIER;
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isDigit(char c, TokenType base) { // overloaded method for dealing with non-decimal integer literals
    switch (base) {
        case TokenType::DECINT:
            return isDigit(c);

        case TokenType::OCTINT:
            return c >= '0' && c < '8';

        case TokenType::BININT:
            return c == '0' || c == '1';

        case TokenType::HEXINT:
            return isDigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');

        default: // invalid base
            return false;
    }
}

bool isAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
}

Token Lexer::nextToken() {
    start = end;

    if (atEnd()) // don't parse tokens
        return makeToken(TokenType::EOF_);

    {
        bool atWhitespace = true;
        while (atWhitespace) {
            char c = peek();
            switch (c) {
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
                    if (peekpeek() == '/') { // check if this is a comment
                        while (peek() != '\n' && !atEnd()) advance();
                    } else if (peekpeek() == '*') { // multiline comment
                        // while next two characters are not * and /
                        while ((peek() != '*' || peekpeek() != '/') && !atEnd()) {
                            if (peek() == '\n') nextLine();
                            advance();
                        }

                        advance(); // advance twice to consume the * and /
                        advance();
                    } else {
                        atWhitespace = false;
                    }
                    break;

                default:
                    atWhitespace = false;
                    break;
            }

            if (atEnd()) {
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

    switch (c) {
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
        //                  if matches double ? return double         : is not double so check if it has equals after it
        case '+': return makeToken(match('+') ? TokenType::DOUBLEPLUS : (match('=') ? TokenType::PLUSEQUAL : TokenType::PLUS));
        case '-': return makeToken(match('-') ? TokenType::DOUBLEMINUS : (match('=') ? TokenType::MINUSEQUAL : TokenType::MINUS));
        case '&': return makeToken(match('&') ? TokenType::DOUBLEAMPER : (match('=') ? TokenType::AMPEREQUAL : TokenType::AMPER));
        case '|': return makeToken(match('|') ? TokenType::DOUBLEPIPE : (match('=') ? TokenType::PIPEEQUAL : TokenType::PIPE));

        // double, doubleequal, singleequal, single
        //                  if matches double ? (is double so check if it has equal after it                          ) : (is not double so check if it has equal after it          )
        case '>': return makeToken(match('>') ? (match('=') ? TokenType::DOUBLEGREATEREQUAL : TokenType::DOUBLEGREATER) : (match('=') ? TokenType::GREATEREQUAL : TokenType::GREATER));
        // once again,      if matches double ? (is double so check if it has equal after it                    ) : (is not double so check if it has equal after it    )
        case '<': return makeToken(match('<') ? (match('=') ? TokenType::DOUBLELESSEQUAL : TokenType::DOUBLELESS) : (match('=') ? TokenType::LESSEQUAL : TokenType::LESS));



        case 'c': // check for char literal
            if (match('\'') || match('"')) { // should consume quote
                char startingQuote = consumed();
                advance(); // consume character

                if (!match(startingQuote)) return makeErrorToken("Error lexing: unterminated single-character literal");

                return makeToken(TokenType::CHAR);
            }
            break;

        case '"':
        case '\'':
            // c is the starting string thing
            while (peek() != c && !atEnd()) {
                if (peek() == '\n') nextLine();
                advance();
            }

            if (atEnd()) return makeErrorToken("Error lexing: unterminated string literal");
            advance(); // consume closing quote/apostrophe
            return makeToken(TokenType::STRING);
    }

    if (isDigit(c)) { // check for number literal
        TokenType inttype;

        if (isDigit(peek()) || c != '0') {
            inttype = TokenType::DECINT;
        } else {
            switch (peek()) {
                case 'o': inttype = TokenType::OCTINT; break;
                case 'b': inttype = TokenType::BININT; break;
                case 'x': inttype = TokenType::HEXINT; break;

                default:
                    return makeErrorToken("Error lexing: invalid number literal type (must be 0o, 0b, or 0x)");
            }

            advance(); // consume o, b, or x
        }

        while (isDigit(peek(), inttype) && !atEnd()) advance();

        if (peek() == '.' && isDigit(peekpeek(), inttype) && !atEnd()) { // is actually a decimal and is not integer literal
            advance(); // consume decimal point
            
            while (isDigit(peek(), inttype) && !atEnd()) advance();

            if (inttype != TokenType::DECINT) return makeErrorToken("Error lexing: Non-decimal floating point literals are not supported");

            return makeToken(TokenType::FLOAT);
        }

        return makeToken(inttype);
    } else if (isAlpha(c)) {
        while (isAlpha(peek()) || isDigit(peek())) advance();

        TokenType idenType = getIdentifierType();


        return makeToken(idenType);
    }

    return makeErrorToken("Error lexing: unexpected character");
}

bool Lexer::atEnd() {
    return end + 1 == srcend;
}

bool Lexer::match(char c) {
    if (atEnd())
        return false;

    if (peek() == c) {
        advance();
        return true;
    }

    return false;
}

char Lexer::advance() {
    ++nextcolumn;

    return *(end++);
}

char Lexer::peek() {
    return *(end);
}

char Lexer::consumed() {
    return *(end - 1);
}

char Lexer::peekpeek() {
    return *(end + 1);
}

Token Lexer::makeErrorToken(std::string message) {
    Token token = makeToken(TokenType::ERROR);

    token.message = message;

    return token;
}

Token Lexer::makeToken(TokenType type) {
    Token token;

    token.type = type;
    token.start = start;
    token.end = end;
    token.line = line;
    token.column = column - 1;

    return token;
}

void Lexer::nextLine() {
    ++nextline;
    nextcolumn = 1;
}


