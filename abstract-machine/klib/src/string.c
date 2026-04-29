#include "am.h"
#include <klib-macros.h>
#include <klib.h>
#include <stdint.h>

#define ATTRIBUTE_NO_SANITIZE_ADDRESS __attribute__((no_sanitize_address))

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t n = 0;
  while (*s) {
    n++;
    s++;
  }
  return n;
}

char *strcpy(char *dst, const char *src) {
  char *pd = dst;
  while (*src) {
    *pd = *src;
    pd++;
    src++;
  }
  *pd = 0;
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
  char *pd = dst;
  while (*pd)
    pd++;
  while (*src) {
    *pd = *src;
    pd++;
    src++;
  }
  *pd = 0;
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  int tmp;
  while (*s1 && *s2) {
    tmp = (int)*s1 - (int)*s2;
    if (tmp)
      return tmp;
    s1++;
    s2++;
  }
  return (int)*s1 - (int)*s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
	if(n==0)return 0;
	while(n-- > 1 && *s1 && *s2 && *s1 == *s2) {
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
  // int tmp;
  // size_t i = 0;
  // while (*s1 && *s2 && i < n) {
  //   i++;
  //   tmp = (int)*s1 - (int)*s2;
  //   if (tmp)
  //     return tmp;
  //   s1++;
  //   s2++;
  // }
  // return (int)*s1 - (int)*s2;
}

ATTRIBUTE_NO_SANITIZE_ADDRESS
void *_no_asan_kmemzero(void *s, size_t n) {
  if (n % 4 == 0) {
		uint32_t *bs = (uint32_t *)s;
		uint32_t *es = bs + n / 4;
		while (bs != es) {
			*bs = 0;
			bs++;
		}
		return s;
  }
  char *bs = (char *)s;
  char *es = bs + n;
  while (bs != es) {
    *bs = 0;
    bs++;
  }
  return s;
}

void *kmemset(void *s, int c, size_t n) {
  char *bs = (char *)s;
  char *es = bs + n;
  while (bs != es) {
    *bs = c;
    bs++;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  uint8_t *tmp = malloc(n);
  memcpy(tmp, src, n);
  memcpy(dst, tmp, n);
  return dst;
}

void *kmemcpy(void *out, const void *in, size_t n) {
  const char *ibeg = in;
  char *obeg = out;
  const char *iend = ibeg + n;

  while (ibeg != iend) {
    *obeg = *ibeg;
    ibeg++;
    obeg++;
  }
  return out;
}

#ifndef KASAN_ENABLED
#undef memset
void* memset(void *s, int c, size_t n) {
	return kmemset(s, c, n);
}
#undef memcpy
void* memcpy(void *out, const void *in, size_t n) {
	return kmemcpy(out, in, n);
}
#endif

int memcmp(const void *s1, const void *s2, size_t n) {
  const char *bs1 = (const char *)s1;
  const char *bs2 = (const char *)s2;
  const char *es1 = bs1 + n;
  while (bs1 != es1) {
    int tmp = (*bs1 - *bs2);
    if (tmp)
      return tmp;
    bs1++;
    bs2++;
  }
  return 0;
}

#endif
