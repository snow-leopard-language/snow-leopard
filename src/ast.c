#include <stdio.h>

#include "include/util.h"
#include "include/ast.h"

AST* init_ast(int type)
{
    AST* ast = xcalloc(1,sizeof(struct AST));
    ast->type = type;

    /* variable_declaration */
    ast->variable_declaration_name = nullptr;
    ast->variable_declaration_value = nullptr;

    /* variable */
    ast->variable_name = nullptr;

    /* variable_declaration */
    ast->function_call_name = nullptr;
    ast->function_call_arguments = nullptr;
    ast->function_call_arguments_size = 0;

    return ast;
}
