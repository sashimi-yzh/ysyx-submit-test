#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  while (*s++) len++;
  return len;
}

char *strcpy(char *dst, const char *src) {
  for(char *p = dst; (*p = *src) != '\0'; p++, src++);
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
  char *p = dst;
  for( ; *p!='\0'; p++);
  for( ; (*p = *src) != '\0'; p++, src++);
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  for ( ; *s1 == *s2; s1++, s2++) {
    if (*s1 == '\0') {
      return 0;
    }
  }
  return (unsigned char)*s1 - (unsigned char)*s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  for ( ; n > 0 && *s1 == *s2; s1++, s2++, n--) {
    if (*s1 == '\0') {
      return 0;
    }
  }
  if (n == 0) {
    return 0;
  }
  return (unsigned char)*s1 - (unsigned char)*s2;

}

void *memset(void *s, int c, size_t n) {
  for(uint8_t *p = s; n > 0; p++, n--) {
    *p = (uint8_t)c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  uint8_t *d = dst;
  const uint8_t *s = src;
  if (d < s) {
    for ( ; n > 0; d++, s++, n--) {
      *d = *s;
    }
  } else {
    d += n;
    s += n;
    for ( ; n > 0; d--, s--, n--) {
      *d = *s;
    }
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
    for(uint8_t *p = out, *q = (uint8_t *)in; n > 0; p++, q++, n--) {
        *p = *q;
    }
    return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const uint8_t *p1 = s1, *p2 = s2;
  for ( ; n > 0; p1++, p2++, n--) {
    if (*p1 != *p2) {
      return (int)*p1 - (int)*p2;
    }
  }
  return 0;
}

#endif
