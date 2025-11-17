#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  if (s == NULL){
    return 0;
  }
  int i=0;
  do {
    i++;
  } while (s[i] != '\0');  
  return i;
}

char *strcpy(char *dst, const char *src) {
  char * res = dst;
  while((*dst++=*src++))
    ;
  return res;
}

char *strncpy(char *dst, const char *src, size_t n) {
  int i=0;
  char * res = dst;
  while (i<n && (*dst++=*src++))
  {
    i++;
  }
  return res;
}

char *strcat(char *dst, const char *src) {
    int l1 = strlen(dst);
    strcpy(&dst[l1],src);
    return dst;
}

int strcmp(const char *s1, const char *s2) {
    int i = 0;
    for (i=0;s1[i]==s2[i];i++){
      if (s1[i] == '\0') {
        return 0;
      }
    }
    return s1[i]-s2[i];
}

int strncmp(const char *s1, const char *s2, size_t n) {
  int i = 0;
  for (i=0;(i<n)&&(s1[i]==s2[i]);i++){
    if (s1[i] == '\0') {
      return 0;
    }
  }
  return s1[i]-s2[i];
}

void *memset(void *s, int c, size_t n) {
    char * ss = (char*)s;
    for (int i=0;i<n;i++){
      ss[i]=(char)c;
    }
    return s;
}

/* memmove() function src, dst may overlap, 
   use a temporary array to get rid of it. */ 
void *memmove(void *dst, const void *src, size_t n) {
  char *temp = malloc(sizeof(char)*n); 
  strncpy(temp,src,n);
  strncpy(dst,temp,n);
  free(temp);
  return dst;
}

/* memcpy() function src, dst must not overlap*/ 
void *memcpy(void *dst, const void *src, size_t n) {
  if (dst == NULL || src == NULL || n <= 0)
  return NULL;

  char * pdst = (char *)dst;
  char * psrc = (char *)src;

  if (pdst > psrc && pdst < psrc + n)
  {
      pdst = pdst + n - 1;
      psrc = psrc + n - 1;
      while (n--)
          *pdst-- = *psrc--;
  }
  else
  {
      while (n--)
          *pdst++ = *psrc++;
  }
  return dst;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const char *ss1 = s1;
  const char *ss2 = s2;
  int i = 0;
  for (i=0;ss1[i]==ss2[i];i++){
    if (i==(n-1)) {
      return 0;
    }
  }
  return ss1[i]-ss2[i];
}

#endif
