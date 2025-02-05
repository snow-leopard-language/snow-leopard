#ifndef ERROR_H
#define ERROR_H

#define ERROR_CREATE(n, type, message) \
    Error (n) =  { (type), (message) }

#define ERROR_PREPARE(n, t, msg) \
    (n).type = (t); \
    (n).message = (msg);

typedef struct Error {
    enum {
        ERROR_NONE = 0,
        ERROR_ARGUMENTS,
        ERROR_SYNTAX,
        ERROR_TYPE,
        ERROR_GENERIC,
        ERROR_TODO,
    } type;
    char *message;
} Error;

void error(Error error);

#endif
