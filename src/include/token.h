#ifndef TOKEN_H
#define TOKEN_H

//    ( and ) are the left and right parentheses, singular parenthesis.
//    [ and are the left and right square brackets.
//    { and } are the left and right curly braces.
typedef struct Token {
    enum {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_COMMA,
    TOKEN_SEMICOLON,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_PERCENT,
    TOKEN_BANG,
    TOKEN_BANG_EQUAL,
    TOKEN_EQUAL,
    TOKEN_EQUAL_EQUAL,
    TOKEN_GREATER,
    TOKEN_GREATER_EQUAL,
    TOKEN_LESS,
    TOKEN_LESS_EQUAL,
    TOKEN_NOTEQUAL,
    TOKEN_NOTEQUAL_EQUAL,
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_NOT,
    TOKEN_LSHIFT,
    TOKEN_RSHIFT,
    TOKEN_PLUS_PLUS,
    TOKEN_MINUS_MINUS,
    TOKEN_STAR_STAR,
    TOKEN_SLASH_SLASH,
    TOKEN_SLASH_SLASH_EQUAL,
    TOKEN_PERCENT_PERCENT,
    TOKEN_BANG_BANG,
    TOKEN_BANG_EQUAL_BANG,
    TOKEN_BREAK,
    TOKEN_CONTINUE,
    TOKEN_DELETE,
    TOKEN_END,
    TOKEN_ERROR,
    TOKEN_EOF
    } type;
    unsigned int i;
    char* contents;
} Token;

#endif
