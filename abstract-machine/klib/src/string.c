#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t n = 0;
  while(*s++) n++;
  return n;
}

char *strcpy(char *dst, const char *src) {
  char *temp = dst;
  while (*src) {
    *temp++ = *src++;
  }
  *temp = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  char *temp = dst;
  for (int i = 0; i < n; i++) {
    if (*src) *temp++ = *src++;
    else *temp++ = '\0';
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  char *temp = dst;
  while (*temp) temp++;
  while (*src) {
    *temp++ = *src++;
  }
  *temp = '\0';
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  while(*s1 == *s2 && *s1 != '\0') {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  for (int i = 0; i < n; i++) {
    if (*s1++ != *s2++) break;
  }
  return *--s1 - *--s2;
}


void *memset(void *s, int c, size_t n) {
  unsigned char *temp = (unsigned char *)s;
  for (int i = 0; i < n; i++) {
    *temp++ = (unsigned char)c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;

    if (d == s) return dst;  // 避免源地址和目标地址相同的情况

    if (d < s) {
        for (size_t i = 0; i < n; i++) {
            d[i] = s[i];
        }
    } else {
        for (size_t i = n; i > 0; i--) {
            d[i-1] = s[i-1];
        }
    }

    return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  unsigned char *o = (unsigned char *)out;
  const unsigned char *i = (const unsigned char *)in;
  for (int j = 0; j < n; j++) {
    *o++ = *i++;
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  if (n == 0) return 0;
  const unsigned char *a = (const unsigned char *)s1;
  const unsigned char *b = (const unsigned char *)s2;
  for (int i = 0; i < n; i++) {
    if (*a++ != *b++) break;
  }
  return *--a - *--b;
}

#endif
