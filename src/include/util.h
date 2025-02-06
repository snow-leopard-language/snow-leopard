#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>

void *xmalloc(size_t size);

void *xcalloc(size_t nmemb, size_t size);

void *xrealloc(void *ptr, size_t size);

void *xalloca(size_t size);

void *xreallocarray(void *ptr, size_t nmemb, size_t size);

char *xstrdup(const char *s);

char *xstrndup(const char *s, size_t n);

//#define malloc(size) (void *)sizeof(struct { static_assert(0, "Use xmalloc instead"); int _; })
//#define calloc(nmemb, size) (void *)sizeof(struct { static_assert(0, "Use xcalloc instead"); int _; })
//#define realloc(ptr, size) (void *)sizeof(struct { static_assert(0, "Use xrealloc instead"); int _; })
//#define alloca(size) (void *)sizeof(struct { static_assert(0, "Use xalloca instead"); int _; })
//#define reallocarray(ptr, nmemb, size) (char *)(sizeof(struct { static_assert(0, "Use xreallocarray instead"); int _; })
//#define strdup(s) (char *)(sizeof(struct { static_assert(0, "Use xstrdup instead"); int _; })
//#define strndup(s, n) (char *)(sizeof(struct { static_assert(0, "Use xstrndup instead"); int _; })

#endif
