#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;

  while(s[len] != '\0')
  {
    len ++;
  }
  return len;
  panic("Not implemented");
}

size_t strnlen(const char *s, size_t n)
{
  const char *p = s;
  while (n-- && *p)
    p++;
  return p - s;
}

char *strcpy(char *dst, const char *src) {

  char *res = dst;

  while(*src != '\0')
  {
    *dst = *src;
    dst ++;
    src ++;
  }

  *dst = '\0';

  return res;

  panic("Not implemented");
}

char *strncpy(char *dst, const char *src, size_t n) {

  // char *res = dst;

  for (size_t i = 0; i < n; i ++){
    if (src[i] != '\0'){
      dst[i] = src[i];
    }
    else{
      while(i < n){
        dst[i] = '\0';
        i ++;
      }
    }
  }
  return dst;

  panic("Not implemented");
}

char *strcat(char *dst, const char *src) {

  size_t i = 0;
  while(dst[i] != '\0'){
    i++;
  }
	 
  strcpy(dst + i, src);
  return dst;

  panic("Not implemented");
}

int strcmp(const char *s1, const char *s2) {

  size_t i = 0;

  while(s1[i] != '\0' && s2[i] != '\0')
  {
    if(s1[i] > s2[i])
      return 1;
    if(s1[i] < s2[i])
      return -1;
    i++;
  }
  if(s1[i] != '\0' && s2[i] == '\0')
    return 1;
  if(s1[i] == '\0' && s2[i] != '\0')
    return -1;
  return 0;

  panic("Not implemented");
}

int strncmp(const char *s1, const char *s2, size_t n) {
  
  for(size_t i = 0; i < n; i ++){
    if(s1[i] > s2[i]){
      return 1;
    }
    else if(s1[i] < s2[i]){
      return -1;
    }
    else{
      continue;
    }
  }

  return 0;

  panic("Not implemented");
}

void *memset(void *s, int c, size_t n) {

  char *ch = (char *) s; 

  for (size_t i = 0; i < n; i ++){
    ch[i] = c;
  }
  return s;

  panic("Not implemented");
}

void *memmove(void *dst, const void *src, size_t n) {

  if(dst < src)
  {
	  char *d = (char *) dst;
	  char *s = (char *) src;
	  while(n--)
	  {
		  *d = *s;
		  d++;
		  s++;
	  }
  }
  else
  {
	  char *d = (char *) dst + n - 1;
	  char *s = (char *) src + n - 1;
	  while(n--)
	  {
		  *d = *s;
		  d--;
		  s--;
	  }
  }
  return dst;

  panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n) {
  char *d = (char *) out;
  char *s = (char *) in;
  while(n > 0)
  {
	  *d = *s;
	  d++;
	  s++;
    n --;
  }
  return out;

  panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n) {

  char * S1 = (char *)s1;
  char * S2 = (char *)s2;
  while(n > 0)
  {
	  if(*S1 > *S2)
		  return 1;
	  if(*S1 < *S2)
		  return -1;
	  S1++;
	  S2++;
    n --;
  }
  return 0;

  panic("Not implemented");
}

#endif
