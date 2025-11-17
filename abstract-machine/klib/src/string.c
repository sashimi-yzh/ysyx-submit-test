#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  // panic("Not implemented");
  size_t len = 0;
  while (s[len] != '\0') {
      len++;
  }
  return len;
}

char *strcpy(char *dst, const char *src) {
  // panic("Not implemented");
  char* tmp = dst;
  while ((*dst++ = *src++) != '\0') {}
  return tmp;
}

char *strncpy(char *dst, const char *src, size_t n) {
  // panic("Not implemented");
  char* tmp = dst;
  size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
      dst[i] = src[i];
  }
  for (; i < n; i++) {
      dst[i] = '\0';
  }
  return tmp;
}

char *strcat(char *dst, const char *src) {
  // panic("Not implemented");
  char* tmp = dst;
  while (*dst != '\0') dst++;  
  while ((*dst++ = *src++) != '\0');  
  return tmp;
}

int strcmp(const char *s1, const char *s2) {
  //panic("Not implemented");
  while (*s1 && (*s1 == *s2)) { s1++; s2++; }
  return *(unsigned char*)s1 - *(unsigned char*)s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  //panic("Not implemented");
  for (size_t i = 0; i < n; i++) {
      if (s1[i] != s2[i]) return (unsigned char)s1[i] - (unsigned char)s2[i];
      if (s1[i] == '\0') break;  
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  //panic("Not implemented");
  unsigned char* p = s;
  for (size_t i = 0; i < n; i++) p[i] = (unsigned char)c;
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  //panic("Not implemented");
  unsigned char* d = dst;
  const unsigned char* s = src;
  if (d < s) {  // 从前往后复制（无重叠或 dest 在前）
      for (size_t i = 0; i < n; i++) d[i] = s[i];
  } else {      // 从后往前复制（dest 在后，避免覆盖）
      for (size_t i = n; i > 0; i--) d[i-1] = s[i-1];
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  //panic("Not implemented");
  unsigned char* d = out;
  const unsigned char* s = in;
  for (size_t i = 0; i < n; i++) d[i] = s[i];
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  //panic("Not implemented");
  const unsigned char* p1 = s1, *p2 = s2;
  for (size_t i = 0; i < n; i++) {
      if (p1[i] != p2[i]) return p1[i] - p2[i];
  }
  return 0;
}

#endif
