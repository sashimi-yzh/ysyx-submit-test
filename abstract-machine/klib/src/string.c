#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t i = 0;
  const char *s_temp = s;
  while(*s_temp != '\0') {
    i++;
    s_temp++;
  }
  return i;
  // panic("Not implemented");
}

char *strcpy(char *dst, const char *src) {
  char *p = dst;
  while(*src != '\0'){
    *p = *src;
    p++;
    src++;
  }
  *p = '\0';
  return dst;
  // panic("Not implemented");
}

char *strncpy(char *dst, const char *src, size_t n) {
  panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
  char *p = dst + strlen(dst);
  while(*src != '\0'){
    *p = *src;
    p++;
    src++;
  }
  *p = '\0';
  return dst;
  // panic("Not implemented");
}

int strcmp(const char *s1, const char *s2) {
  const char *s1_temp = s1;
  const char *s2_temp = s2;

  while(*s1_temp != '\0' && *s2_temp != '\0'){
    if(*s1_temp != *s2_temp) {
      return *s1_temp - *s2_temp;
    }
    s1_temp++;
    s2_temp++;
  }
  if(*s1_temp != '\0') return *s1_temp;
  if(*s2_temp != '\0') return *s2_temp;
  return 0;
  // panic("Not implemented");
}

int strncmp(const char *s1, const char *s2, size_t n) {
  const char *s1_temp = s1;
  const char *s2_temp = s2;

  while(*s1_temp != '\0' && *s2_temp != '\0' && n > 0){
    if(*s1_temp != *s2_temp) {
      return *s1_temp - *s2_temp;
    }
    s1_temp++;
    s2_temp++;
    n--;
  }
  if(n == 0) return 0;
  if(*s1_temp != '\0') return *s1_temp;
  if(*s2_temp != '\0') return *s2_temp;
  return 0;
  // panic("Not implemented");
}

void *memset(void *s, int c, size_t n) {
  char *s_temp = (char* )s;
  while(n--) {
    *s_temp = (char)c;
    s_temp++;
  }
  return s;
  // panic("Not implemented");
}

void *memmove(void *dst, const void *src, size_t n) {
  char temp[n+1];
  memcpy(temp, src, n);
  memcpy(dst, temp, n);
  return dst;
  // panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n) {
  char *dest = (char *)out;
  const char *src = (const char *)in;
  while (n--) {
    *dest++ = *src++;
  }
  return out;
  // panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const char* s1_temp = (const char*) s1;
  const char* s2_temp = (const char*) s2;

  while(n--){
    if(*s1_temp != *s2_temp) {
      return *s1_temp - *s2_temp;
    }
    s1_temp++;
    s2_temp++;
  }
  return 0;
  // panic("Not implemented");
}

#endif
