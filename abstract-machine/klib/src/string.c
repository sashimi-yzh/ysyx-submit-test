#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  while (s[len] != '\0') {
    ++len;
  }
  return len;
}

char *strcpy(char *dst, const char *src) {
  size_t i = 0;
  while (src[i] != '\0') {
    dst[i] = src[i];
    ++i;
  }
  dst[i] = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dst[i] = src[i];
  }
  for (; i < n; i++) {
    dst[i] = '\0';
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  size_t i = 0;
  size_t len = strlen(dst);
  while (src[i] != '\0') {
    dst[len + i] = src[i];
    ++i;
  }
  dst[len + i] = '\0';
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  while (*s1 != '\0' || *s2 != '\0') {
    if (*s1 != *s2) {
      return *s1 < *s2 ? -1 : 1;
    }
    s1++;
    s2++;
  }
  return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  size_t i;
  for (i = 0; i < n && s1[i] == s2[i]; i++) {
    if (s1[i] == '\0') {
      return 0;
    }
  }
  if (i != n) {
    return s1[i] < s2[i] ? -1 : 1;
  } else {
    return 0;
  }
}

void *memset(void *s, int c, size_t n) {
  char *tmp = (char *)s;
  for (size_t i = 0; i < n; i++) {
    tmp[i] = c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  char *pos1 = (char *)dst;
  const char *pos2 = (const char *)src;
  if (pos1 > pos2 && pos1 < pos2 + n) {
    for (int i = n - 1; i >= 0; i--) {
      pos1[i] = pos2[i];
    }
    return dst;
  }
  return memcpy(dst, src, n);
}

void *memcpy(void *out, const void *in, size_t n) {
  char *dst = (char *)out;
  const char *src = (const char *)in;
  for (size_t i = 0; i < n; i++) {
    dst[i] = src[i];
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  size_t i;
  const unsigned char *m1 = (const unsigned char *)s1;
  const unsigned char *m2 = (const unsigned char *)s2;
  for (i = 0; i < n && m1[i] == m2[i]; i++);

  if (i != n) {
    return m1[i] < m2[i] ? -1 : 1;
  } else {
    return 0;
  }
}

#endif
