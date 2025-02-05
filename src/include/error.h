#ifndef ERROR_H
#define ERROR_H

#define ERROR_CREATE(n, type, message) \
    Error (n) =  { (type), (message) }

#define ERROR_PREPARE(n, t, msg) \
    (n).type = (t); \
    (n).message = (msg);

typedef struct Error {
    enum {
        error_none = 0,
        error_arguments,
        error_syntax,
        error_type,
        error_generic,
        error_todo,
    } type;
    char *message;
} Error;

void error(Error error);

#endif
