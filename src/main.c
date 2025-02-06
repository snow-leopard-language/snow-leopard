#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/lexer.h"
#include "include/ast.h"

void usage(char **argv)
{
    printf("Usage: sl %s [parsing file]\n", argv[0]);
}

int main (int argc, char* argv[])
{
    AST* ast = init_ast(ast_variable_declaration);


    Lexer* lexer = init_lexer(
        "string name = \"jon doe\";\n"
        "print(name);\n"
    );

    Token* token = nullptr;
    while ((token = lexer_next_token(lexer)) != nullptr)
    {
        printf("TOKEN(%d, %s)\n", token->type, token->value);
    }

    return EXIT_SUCCESS;


    if (argc != 2) {
        usage(argv);
        return EXIT_FAILURE;
    }

    //printf("ENV: %s\n", version);
    // printf("argc: %d\n", argc);
    // printf("argv0: %s\n", argv[0]);
    // printf("argv1: %s\n", argv[1]);


    return EXIT_SUCCESS;
}
