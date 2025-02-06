#ifndef TOKEN_H
#define TOKEN_H

//
//
// alignas
// alignof
// auto
// bool
// break
// case
// char
// const
// constexpr
// continue
// default
// do
// double
// else
// enum
// extern
// false
// float
// for
// goto
// if
// inline
// int
// long
// nullptr
// register
// restrict
// return
// short
// signed
// sizeof
// static
// static_assert
// struct
// switch
// thread_local
// true
// typedef
// typeof
// typeof_unqual
// union
// unsigned
// void
// volatile



//    ( and ) are the left and right parentheses, singular parenthesis.
//    [ and are the left and right square brackets.
//    { and } are the left and right curly braces.
typedef struct Token {
    enum {
    token_identifier,
    token_number,
    token_string,
    token_equals,
    token_semicolon,
    token_left_parenthesis,
    token_right_parenthesis,
    token_left_currly_bracket,
    token_right_currly_bracket,
    token_comma,
//    TOKEN_COMMA,
//    TOKEN_SEMICOLON,
//    TOKEN_PLUS,
//    TOKEN_MINUS,
//    TOKEN_STAR,
//    TOKEN_SLASH,
//    TOKEN_PERCENT,
//    TOKEN_BANG,
//    TOKEN_BANG_EQUAL,
//    TOKEN_EQUAL,
//    TOKEN_EQUAL_EQUAL,
//    TOKEN_GREATER,
//    TOKEN_GREATER_EQUAL,
//    TOKEN_LESS,
//    TOKEN_LESS_EQUAL,
//    TOKEN_NOTEQUAL,
//    TOKEN_NOTEQUAL_EQUAL,
//    TOKEN_AND,
//    TOKEN_OR,
//    TOKEN_NOT,
//    TOKEN_LSHIFT,
//    TOKEN_RSHIFT,
//    TOKEN_PLUS_PLUS,
//    TOKEN_MINUS_MINUS,
//    TOKEN_STAR_STAR,
//    TOKEN_SLASH_SLASH,
//    TOKEN_SLASH_SLASH_EQUAL,
//    TOKEN_PERCENT_PERCENT,
//    TOKEN_BANG_BANG,
//    TOKEN_BANG_EQUAL_BANG,
//    TOKEN_BREAK,
//    TOKEN_CONTINUE,
//    TOKEN_DELETE,
//    TOKEN_END,
//    TOKEN_ERROR,
//    TOKEN_EOF
    } type;
    char* value;
} Token;

Token* init_token(int type, char *value);

#endif
