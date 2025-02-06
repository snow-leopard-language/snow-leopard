#ifndef LEXER_H
#define LEXER_H

#include "token.h"

typedef struct Lexer {
    char ch;
    unsigned int i;
    char* contents;
} Lexer;

Lexer* init_lexer(char* contents);

void lexer_advance(Lexer* lexer);

void lexer_skip_whitespace(Lexer* lexer);

Token* lexer_advance_with_token(Lexer* lexer, Token* token);

Token* lexer_next_token(Lexer* lexer);

Token* lexer_collect_string(Lexer* lexer);

Token* lexer_collect_identifier(Lexer* lexer);

char* lexer_get_char_as_string(Lexer* lexer);

#endif
