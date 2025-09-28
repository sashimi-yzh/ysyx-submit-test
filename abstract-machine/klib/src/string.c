#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t t = 0;
  while (*s++) ++t;
  return t;
}

char *strcpy(char *dst, const char *src) {
  char *ret = dst;
  while (*src) *dst++ = *src++;
  *dst = '\0';
  return ret;
}

char *strncpy(char *dst, const char *src, size_t n) {
  char *ret = dst;
  while (*src && n) *dst++ = *src++, --n;
  while (n--) *dst++ = '\0';
  return ret;
}

char *strcat(char *dst, const char *src) {
  char *ret = dst;
  while (*dst) ++dst;
  strcpy(dst, src);
  return ret;
}

int strcmp(const char *s1, const char *s2) {
  int t;
  while (*s1 || *s2) {
    t = *s1++ - *s2++;
    if (t) return t;
  }
  return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  int t;
  while ((*s1 || *s2) && n--) {
    t = *s1++ - *s2++;
    if (t) return t;
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  void *ret = s;
  while (n--) *(unsigned char *)s++ = c;
  return ret;
}

void *memmove(void *dst, const void *src, size_t n) {
  void *ret = dst;
  if (src == dst) return ret;
  if (dst < src) {
    while (n--) *(char *)dst++ = *(char *)src++;
  } else {
    src += n; dst += n;
    while (n--) *(char *)--dst = *(char *)--src;
  }
  return ret;
}

void *memcpy(void *out, const void *in, size_t n) {
  void *ret = out;
  while (n--) *(char *)out++ = *(char *)in++;
  return ret;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  int t;
  while (n--) {
    t = *(char *)s1++ - *(char *)s2++;
    if (t) return t;
  }
  return 0;
}

#endif
