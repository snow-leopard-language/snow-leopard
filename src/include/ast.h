#ifndef AST_H
#define AST_H

#include <stdlib.h>

typedef struct AST {
    enum {
        ast_variable_declaration,
        ast_assignment,
        ast_function_call,
        ast_string,
    } type;

     /* variable_declaration */
    char* variable_declaration_name;
    struct AST* variable_declaration_value;


    /* variable */
    char* variable_name;


    /* variable_declaration */
    char* function_call_name;
    struct AST** function_call_arguments;
    size_t function_call_arguments_size;

    char* string_value;

} AST;

AST* init_ast(int type);

#endif