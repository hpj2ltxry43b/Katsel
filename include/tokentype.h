#pragma once

enum TokenType
{
    OPARN, CPARN,
    OSQUB, CSQUB,
    OCURB, CCURB,
    COMMA,
    PERIOD,
    SEMICOLON,
    QUESTION,
    COLON,
    BANG,
    PLUS,
    MINUS,
    STAR,
    SLASH,
    PERCENT,
    EQUAL,
    GREATER,
    LESS,
    TILDE,
    AMPER,
    PIPE,
    CARET,

    DOUBLEPLUS,
    DOUBLEMINUS,
    DOUBLEGREATER,
    DOUBLELESS,
    DOUBLEAMPER,
    DOUBLEPIPE,
    DOUBLEEQUAL,
    DOUBLECOLON,

    PLUSEQUAL,
    MINUSEQUAL,
    STAREQUAL,
    SLASHEQUAL,
    BANGEQUAL,
    GREATEREQUAL,
    LESSEQUAL,
    PERCENTEQUAL,
    DOUBLELESSEQUAL,
    DOUBLEGREATEREQUAL,
    AMPEREQUAL,
    PIPEEQUAL,
    CARETEQUAL,

    IDENTIFIER,

    CHARLIT,
    STRINGLIT,

    DECINTLIT,
    OCTINTLIT,
    BININTLIT,
    HEXINTLIT,

    FLOATLIT,
    TRUELIT,
    FALSELIT,
    NULLLIT,

    INT,
    FLOAT,
    BOOL,
    DOUBLE,

    PRINT,
    VOID,
    NAMESPACE,
    CLASS,
    ENUM,
    RETURN,
    THIS,
    WHILE,
    FOR,
    IF,
    ELSE,
    SWITCH,
    CASE,
    DEFAULT,
    BREAK,
    BREAKALL,
    BREAKTO,
    CONST,
    CONTINUE,
    INLINE,
    VOLATILE,

    EOF_,
    ERROR
};
