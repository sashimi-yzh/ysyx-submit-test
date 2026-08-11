#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  const char *p=s;
  while(*p){
    p++;
  }
  return (size_t)(p-s);
}

char *strcpy(char *dst, const char *src) {
  char* res=dst;
  while(1){
    *dst=*src;
    if(*dst=='\0'){
      break;
    }
    dst++;
    src++;
  }
  return res;
}

char *strncpy(char *dst, const char *src, size_t n) {
  char* res=dst;
  size_t i=0;
  for(;(i<n)&&(src[i]!='\0');i++){
    dst[i]=src[i];
  }
  // 防止出现src比n的长度要小的问题
  for(;i<n;i++){
    dst[i]='\0';
  }
  return res;
}

char *strcat(char *dst, const char *src) {
  char* res=dst;
  while(*dst){
    dst++;
  }
  while((*dst=*src)!='\0'){
    dst++;
    src++;
  }
  *dst='\0';
  return res;
}

int strcmp(const char *s1, const char *s2) {
  const unsigned char* p1=(const unsigned char*)s1;
  const unsigned char* p2=(const unsigned char*)s2;  
  while(*p1&&*p1==*p2){
    p1++;
    p2++;
  }
  return (int)(*p1)-(int)(*p2);
}

int strncmp(const char *s1, const char *s2, size_t n) {
  const unsigned char* p1=(const unsigned char*)s1;
  const unsigned char* p2=(const unsigned char*)s2;
  for(size_t i=0;i<n;i++){
    if(p1[i]!=p2[i]){
      return (int)p1[i]-p2[i];
    }
    if(p1[i]=='\0'){
      return 0;
    }
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  unsigned char* p=(unsigned char*)s;
  unsigned char w=(unsigned char)c;
  for(size_t i=0;i<n;i++){
    p[i]=w;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  unsigned char* d=(unsigned char*)dst;
  const unsigned char* s=(const unsigned char*)src;
  if(d==s||n==0){
    return dst;
  }
  if(d<s){
    for(size_t i=0;i<n;i++){
      d[i]=s[i];
    }  
  }
  else{
    for(size_t i=n;i!=0;i--){
      d[i-1]=s[i-1];
    }
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  unsigned char* d=(unsigned char*)out;
  unsigned char* s=(unsigned char*)in;
  for(size_t i=0;i<n;i++){
    d[i]=s[i];
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char* p1=(const unsigned char*)s1;
  const unsigned char* p2=(const unsigned char*)s2;  
  for(size_t i=0;i<n;i++){
    if(p1[i]!=p2[i]){
      return (int)p1[i]-(int)p2[i];
    }
  }
  return 0;
}

#endif
