#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t num = 0;
  while(*s++) {
    num++;
  }
  return num;
}

char *strcpy(char *dst, const char *src) {
  char *det = dst;
  while(*src) {
    *dst = *src;
    src++;
    dst++;
  }
  *dst = '\0';
  return det;
}

char *strncpy(char *dst, const char *src, size_t n) {
  char *det = dst;
  while(n--) {
    if(*src == '\0') {
      *dst++ = '\0';
    } else {
      *dst++ = *src++;
    }
  }
  return det;
}

char *strcat(char *dst, const char *src) {
  
  char *det = dst;
  while(*dst) {
    dst++;
  }
  while(*src) {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = '\0';
  return det;
}

int strcmp(const char *s1, const char *s2) {
  while (*s1 && *s2 && (*s1 == *s2))
  {
    s1++;
    s2++;
  }
  return *(uint8_t *)s1 - *(uint8_t *)s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  while (n-- && (*s1 == *s2))
  {
    s1++;
    s2++;
  }
  return (n == (size_t)-1) ? 0 : *(uint8_t *)s1 - *(uint8_t *)s2;
}

void *memset(void *s, int c, size_t n) {
  uint8_t a = (uint8_t)c;
  uint8_t *st = (uint8_t *)s;
  while(n--) {
    *st = a;
    st++;
  }
  return s;
}

void *memcpy(void *out, const void *in, size_t n) {
  void *a = out;
  while(n--) {
    *(uint8_t *)out++ = *(uint8_t *)in++;
  }
  return a;
}

void *memmove(void *dst, const void *src, size_t n) {
  uint8_t *d = (uint8_t *)dst;
  const uint8_t *s = (const uint8_t *)src;

  if (d > s && s + n > d) {
    // 从后往前拷贝，避免内存重叠问题
    d += n;
    s += n;
    while (n--) {
      *(--d) = *(--s);
    }
  } else {
    // 从前往后拷贝
    while (n--) {
      *d++ = *s++;
    }
  }
  return dst;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const char *ss1 = (const char *)s1;
  const char *ss2 = (const char *)s2;
  
  while (n && (*ss1 == *ss2))
  {
    n--;
    ss1++;
    ss2++;
  }
  if(n)
    return *(unsigned char *)ss1 - *(unsigned char *)ss2;
  else
    return 0;
}

#endif
