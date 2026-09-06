#include "am.h"
#include <klib-macros.h>
#include <klib.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// clang-format off

size_t strlen(const char *s) {
  size_t i = 0;
  while (*(s + i) != '\0')
    i++;
  return i;
}

char *strcpy(char *dst, const char *src) { 
  size_t i = 0;
  for(i = 0;src[i] != '\0';i++)
    dst[i] = src[i];
  dst[i] = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  size_t i = 0;
  for(i = 0;i<n && src[i]!='\0';i++)
    dst[i] = src[i];
  for(;i<n;i++)
    dst[i] = '\0';
  return dst;
}

char *strcat(char *dst, const char *src) { 
  size_t i = 0;
  size_t j = 0;
  while(dst[i] != '\0')
    i++;
  while(src[j]!='\0')
    dst[i++] = src[j++];
  dst[i] = '\0';
  return dst;
}

int strcmp(const char *s1, const char *s2) { 
  size_t i = 0;
  while(s1[i] != '\0'){
    if(s2[i] == '\0') return 1;

    if(s1[i] > s2[i]) return 1;
    if(s1[i] < s2[i]) return -1;
    i++;
  }
  if(s2[i] != '\0') return -1;
  return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  size_t i = 0;
  for(;i<n;i++){
    if(s1[i] == '\0' && s2[i] == '\0')
      return 0;
    if(s1[i] == '\0' || s1[i] < s2[i])
      return -1;
    if(s2[i] == '\0' || s1[i] > s2[i])
      return 1;
  }
  return 0;
}

char *strchr (const char *s, int c) {
  char *ptr = (char *)s;
  while(*ptr != '\0') {
    if(*ptr == c) {
      return ptr;
    }
    ptr++;
  }

  if(c == '\0')
    return ptr;
  else 
    return NULL;
}

char *strrchr(const char *s, int c) {
  char *ptr = (char *)s;

  while(*ptr != '\0') ptr++;
  if(c == '\0') return ptr;

  while(ptr > s) {
    if(*ptr == c) {
      return ptr;
    }
    ptr--;
  }

  // the first element is the target
  if(*ptr == c)
    return ptr; 
  else 
    return NULL;
}

void *memset(void *s, int c, size_t n) { 
  char *pos = (char*)s;
  for(size_t i=0;i<n;i++){
    pos[i] = c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  char *out = (char*)dst;
  const char *in = (const char*)src;
  if(out <= in){
    // the overlap in the head of src, cp the head first
    for(size_t i=0;i<n;i++){
      out[i] = in[i];
    }
  } else {
    // the overlap in the tail of src, cp the tail first
    for(size_t i=n-1;i>=0;i--){
      out[i] = in[i];
    }
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) { 
  char *pos = (char*)out;
  const char *src = (const char*)in;
  for(size_t i=0;i<n;i++){
    pos[i] = src[i];
  }
  return out; 
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const char *str1 = (const char*)s1;
  const char *str2 = (const char*)s2;
  for(size_t i=0;i<n;i++){
    if(str1[i] > str2[i]) return 1;
    if(str1[i] < str2[i]) return -1;
  }
  return 0;
}

#endif

// cptr --;lang-format on
