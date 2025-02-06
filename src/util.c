#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <alloca.h>

#include "include/util.h"

//#undef malloc
//#undef calloc
//#undef realloc
//#undef alloca
//#undef reallocarray
//#undef strdup
//#undef strndup

void *xmalloc(size_t size)
{
    void *ptr = malloc(size);
    if (!ptr) {
        abort();
    }
    return ptr;
}

void *xcalloc(size_t nmemb, size_t size)
{
    void *ptr = calloc(nmemb, size);
    if (!ptr && size) {
        abort();
    }
    return ptr;
}

void* xrealloc(void *ptr, size_t size)
{
    ptr = realloc(ptr, size);
    if (!ptr && size) {
        abort();
    }
    return ptr;
}

void *xalloca(size_t size)
{
    if (!alloca(size)) {
        abort();
    }
}

void *xreallocarray(void *ptr, size_t nmemb, size_t size)
{
    ptr = reallocarray(ptr, nmemb, size);
    if (!ptr && nmemb && size) {
        abort();
    }
    return ptr;
}

char *xstrdup(const char *s)
{
    char *c = strdup(s);
    if (!c) {
        abort();
    }
    return c;
}

char *xstrndup(const char *s, size_t n)
{
    char *c = strndup(s, n);
    if (!c) {
        abort();
    }
    return c;
}
