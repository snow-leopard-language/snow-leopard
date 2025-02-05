#include <stdio.h>
#include "include/error.h"

Error ok = {
    error_none,
    NULL,
};

Error lex(char *source, char **begining, char **end) {
    Error error = ok;

    if (!source || !begining || !end) {
        ERROR_PREPARE(error, error_arguments, "Can not lex empty source");
        return error;
    }
    *begining = source;
    *end = source;

    return error;
}

Error parse_expression(char *source) {
    char *begining = source;
    char *end = source;
    Error error = lex(source, &begining, &end);
    return error;
}

void error (Error error) {
    if (error.type == error_none) {
        return;
    }
    printf("ERROR: ");
    switch (error.type) {
        default:
            printf("UNKNOWN: Error type...");
        break;
        case error_arguments:
            printf("INVALID ARGUMENTS");
        break;
        case error_syntax:
            printf("INVALID SYNTAX");
        break;
        case error_type:
            printf("MISMATCHED TYPES");
        break;
        case error_todo:
            printf("TODO: (not implemented)");
        break;
        case error_generic:
            break;
        case error_none:
            break;
    }
    putchar('\n');
    if (error.message) {
        printf("     : %s\n", error.message);
    }
}
