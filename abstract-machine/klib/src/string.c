#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
    size_t i;
    for(i=0; s[i] != '\0'; i++); 

    return i;
}

char *strcpy(char *dst, const char *src) {
    size_t i;
    for(i=0; src[i] != '\0'; i++)
        dst[i] = src[i];

    dst[i] = '\0';

    return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
    size_t i;
    for(i=0; i<n && src[i] != '\0'; i++)
        dst[i] = src[i];

    for(; i<n; i++) dst[i] = '\0';

    return dst;
}

char *strcat(char *dst, const char *src) {
    size_t i, j;
    for(i=strlen(dst), j=0; src[j] != '\0'; j++)
        dst[i+j] = src[j];

    dst[i+j] = '\0';

    return dst;
}

int strcmp(const char *s1, const char *s2) {
    size_t i;
    for(i=0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if(s1[i] != s2[i])
            return s1[i] - s2[i];
    }

    return s1[i] - s2[i];
}

int strncmp(const char *s1, const char *s2, size_t n) {
    size_t i;
    for(i=0; s1[i] != '\0' && s2[i] != '\0' && i<n; i++) {
        if(s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }

    if(i == n) return 0;

    return s1[i] - s2[i];
}

void *memset(void *s, int c, size_t n) {
    uint8_t *dst = (uint8_t *)s;
    for(size_t i=0; i<n; i++) dst[i] = c;

    return s;
}

void *memmove(void *dst, const void *src, size_t n) {
    const uint8_t *s = (const uint8_t *)src;
    uint8_t *d = (uint8_t *)dst;

    if(d<s) {
        for(size_t i=0; i<n; i++) d[i] = s[i];
    } else if(d>s) {
        for(size_t i=n; i>0; i--) d[i-1] = s[i-1];
    }

    return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
    const uint8_t *i = (const uint8_t *)in;
    uint8_t *o = (uint8_t *)out;

    for(size_t index=0; index<n; index++) o[index] = i[index];

    return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    const uint8_t *src1 = (const uint8_t *)s1;
    const uint8_t *src2 = (const uint8_t *)s2;

    for(size_t i=0; i<n; i++) {
        if(src1[i] != src2[i])
            return src1[i] - src2[i];
    }

    return 0;
}

#endif
