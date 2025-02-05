#ifndef LEXER_H
#define LEXER_H

typedef struct Lexer {
    char *ch;
    unsigned int i;
    char* contents;
} Lexer;

Lexer lexer_init(char* contents);

void lexer_advance(Lexer* lexer);

int lexer_next_char(Lexer* lexer);

#endif
