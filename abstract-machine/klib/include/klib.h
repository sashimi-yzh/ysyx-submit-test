#ifndef KLIB_H__
#define KLIB_H__

#include <am.h>
#include <stddef.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

//#define __NATIVE_USE_KLIB__

typedef struct {
    unsigned v;
} __attribute__((packed)) unaligned_u32;
#define DerefUnalignedU32(p) (((volatile unaligned_u32 *)(p))->v)

// string.h

#ifdef KASAN_ENABLED
#include KASAN_MEM_H
#else
#define memset kmemset
#define memcpy kmemcpy
#endif

void *kmemcpy(void *out, const void *in, size_t n);
void  *kmemset    (void *s, int c, size_t n);
void  *_no_asan_kmemzero(void *s,size_t n);

void  *memmove   (void *dst, const void *src, size_t n);
int    memcmp    (const void *s1, const void *s2, size_t n);
size_t strlen    (const char *s);
char  *strcat    (char *dst, const char *src);
char  *strcpy    (char *dst, const char *src);
char  *strncpy   (char *dst, const char *src, size_t n);
int    strcmp    (const char *s1, const char *s2);
int    strncmp   (const char *s1, const char *s2, size_t n);

// stdlib.h
#ifdef KASAN_ENABLED
void  *malloc    (unsigned long size);
void   free      (void *ptr);
#else
void  *kmalloc   (size_t size);
void   kfree     (void *ptr);
#define malloc  kmalloc
#define free    kfree
#endif
void   srand     (unsigned int seed);
int    rand      (void);
int    abs       (int x);
int    atoi      (const char *nptr);

// stdio.h
int    printf    (const char *format, ...);
int    sprintf   (char *str, const char *format, ...);
int    snprintf  (char *str, size_t size, const char *format, ...);
int    vsprintf  (char *str, const char *format, va_list ap);
int    vsnprintf (char *str, size_t size, const char *format, va_list ap);

// assert.h
#ifdef NDEBUG
  #define assert(ignore) ((void)0)
#else
  #define assert(cond) \
    do { \
      if (!(cond)) { \
        printf("Assertion fail at %s:%d\n", __FILE__, __LINE__); \
        halt(1); \
      } \
    } while (0)
#endif

#ifdef __cplusplus
}
#endif

#endif
