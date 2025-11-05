#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  while(*(s++)) len++;
  return len;
}

char *strcpy(char *dst, const char *src) {
  char *ptr = dst;
  while((*(dst++) = *(src++)));

  return ptr;
}

char *strncpy(char *dst, const char *src, size_t n) {

  for(size_t i=0; i<n; i++)
    *dst = *src;

  return dst;
}

char *strcat(char *dst, const char *src) {
  char *ptr = dst;
  while(*dst) dst++;
  while((*(dst++) = *(src++)));

  return ptr;
}

int strcmp(const char *s1, const char *s2) {
  while(*s1 && *s2 && *s1 == *s2) {
    s1++;
    s2++;
  }

  return *s1 - *s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  for(size_t i=0; i<n; i++) {
    if(*s1 != *s2) return *s1 - *s2;
    s1++;
    s2++;
  }

  return 0;
}

void *memset(void *s, int c, size_t n) {
  char *ptr = s;
  for(size_t i=0; i<n; i++)
    *(ptr++) = c;

  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  char *d = dst;
  const char *s = src;
  if(d < s ) {    //src和dst重叠时仍然正确
    for(size_t i=0; i<n; i++)
      d[i] = s[i];
  } else {
    for(size_t i=n; i>0; i--)
      d[i-1] = s[i-1];
  }

  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  char *dst = out;
  const char *src = in;
  for(size_t i=0; i<n; i++)
    dst[i] = src[i];

  return out;

}

int memcmp(const void *s1, const void *s2, size_t n) {
  const uint8_t *p1 = s1;
  const uint8_t *p2 = s2;
  for(size_t i=0; i<n; i++) {
    if(p1[i] != p2[i]) return p1[i] - p2[i];
  }

  return 0;
}

#endif
