#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "include/token.h"
#include "include/lexer.h"

Lexer* lexer_init(char* contents)
{
    Lexer* lexer = calloc(1, sizeof(struct Lexer));
    lexer->contents = contents;
    lexer->i = 0;
    lexer->ch = contents[lexer->i];

    return lexer;
}


void lexer_advance(Lexer* lexer)
{
    if (lexer->ch != '\0' && lexer->i < strlen(lexer->contents))
    {
        lexer->i += 1;
        lexer->ch = lexer->contents[lexer->i];
    }
}

void lexer_skip_whitespace(Lexer* lexer)
{
    while (isspace(lexer->ch))
    {
        lexer_advance(lexer);
    }
}

Token* lexer_advance_with_token(Lexer* lexer, Token* token)
{
    lexer_advance(lexer);

    return token;
}

Token* lexer_next_token(Lexer* lexer)
{
    while (lexer->ch != '\0' && lexer->i < strlen(lexer->contents))
    {
        if (lexer->ch == ' ' || lexer->ch == 10)
        {
            lexer_skip_whitespace(lexer);
        }
        if (isalnum(lexer->ch))
        {
            return lexer_collect_identifier(lexer);
        }

        if (lexer->ch == '"')
        {
            return lexer_collect_string(lexer);
        }

        switch (lexer->ch)
        {
            case '=': return lexer_advance_with_token(lexer, init_token(token_equals, lexer_get_char_as_string(lexer))); break;
            case ';': return lexer_advance_with_token(lexer, init_token(token_semicolon, lexer_get_char_as_string(lexer))); break;
            case '(': return lexer_advance_with_token(lexer, init_token(token_left_parenthesis, lexer_get_char_as_string(lexer))); break;
            case ')': return lexer_advance_with_token(lexer, init_token(token_right_parenthesis, lexer_get_char_as_string(lexer))); break;
            case '{': return lexer_advance_with_token(lexer, init_token(token_left_currly_bracket, lexer_get_char_as_string(lexer))); break;
            case '}': return lexer_advance_with_token(lexer, init_token(token_right_currly_bracket, lexer_get_char_as_string(lexer))); break;
            case ',': return lexer_advance_with_token(lexer, init_token(token_comma, lexer_get_char_as_string(lexer))); break;
        }
    }

    return nullptr;
}

Token* lexer_collect_string(Lexer* lexer)
{
    lexer_advance(lexer);

    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    while (lexer->ch != '"')
    {
        char* s = lexer_get_char_as_string(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);

        lexer_advance(lexer);
    }

    lexer_advance(lexer);

    return init_token(token_string, value);
}

Token* lexer_collect_identifier(Lexer* lexer)
{
    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    while (isalnum(lexer->ch))
    {
        char* s = lexer_get_char_as_string(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);

        lexer_advance(lexer);
    }

    return init_token(token_identifier, value);
}

char* lexer_get_char_as_string(Lexer* lexer)
{
    char* string = calloc(2, sizeof(char));
    string[0] = lexer->ch;
    string[1] = '\0';

    return string;
}