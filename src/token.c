#include <stdlib.h>
#include "include/token.h"

Token* init_token(int type, char *value)
{
    Token* token = calloc(1, sizeof(struct Token));
    token->type = type;
    token->value = value;

    return token;
}