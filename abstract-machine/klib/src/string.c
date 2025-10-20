#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  //panic("Not implemented");
  size_t len = 0;
  while(*s) {
    len++;
    s++;
  }
  return len;
}

char *strcpy(char *dst, const char *src) {
  //panic("Not implemented");
  char *temp = dst;
  while (*src) {
    *temp = *src;
    temp++;
    src++;
  }
  *temp = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
  //panic("Not implemented");
  char *temp = dst;
  while (*temp) {
    temp++;
  }
  while (*src) {
    *temp = *src;
    temp++;
    src++;
  }
  *temp = '\0';
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  //panic("Not implemented");
  while (*s1 && *s2 && (*s1 == *s2)) {
      s1++;
      s2++;
    }
  if(*s1 < *s2)
    return -1;
  else if (*s1 > *s2)
    return 1;
  else 
    return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  while (n > 0) {
    if (*s1 != *s2) return (unsigned char)*s1 - (unsigned char)*s2;
    else if (*s1 == '\0') return 0;
    s1++;
    s2++;
    n--;
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  //panic("Not implemented");
  unsigned char *temp = (unsigned char *)s;
  for (size_t i = 0; i < n; i++) {
    *temp = c;
    temp ++;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  char *destination = (char *)dst;
  const char *source = (const char *)src;

  if (source < destination && destination < source + n) {
    for (size_t i = n; i > 0; --i) {
      destination[i - 1] = source[i - 1];
    }
  } else {
    for (size_t i = 0; i < n; ++i) {
      destination[i] = source[i];
    }
  }

  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  //panic("Not implemented");
  void *original_out = out;
  char *dest = (char *)out;
  const char *src = (const char *)in;

  for (size_t i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  return original_out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  //panic("Not implemented");
    const unsigned char *temp1 = (const unsigned char *)s1;
    const unsigned char *temp2 = (const unsigned char *)s2;
  while (n) {
    if(*temp1 < *temp2)
      return -1;
    else if (*temp1 > *temp2)
      return 1;
    temp1++;
    temp2++;
    n--;
  }
  return 0;
}

#endif
