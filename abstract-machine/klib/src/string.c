#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  //panic("Not implemented");
  size_t i=0;
  while(*(s+i)!='\0')
    i++;
  return i;
}

char *strcpy(char *dst, const char *src) {
  //panic("Not implemented");
  char *p;
  size_t l=strlen(src);
  p=memmove(dst,src,l);
  *(p+l)='\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  //panic("Not implemented");
  size_t i=0;
  while(i<n){
    if(*(src+i)!='\0'){
      *(dst+i) = *(src+i);
      i++;
    }else{
      break;
    }
  }
  while(i<n){
    *(dst+i) = '\0';
    i++;
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  //panic("Not implemented");
  strcpy(dst+strlen(dst),src);
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  //panic("Not implemented");
  size_t i=0;
  while(*(s1+i)!='\0' && *(s2+i)!='\0'){
    if(*(s1+i) != *(s2+i)) return *(s1+i) - *(s2+i);
    i++;
  }
  if(*(s1+i)=='\0' && *(s2+i)!='\0') return -1;
  else if(*(s1+i)!='\0' && *(s2+i)=='\0') return 1;
  else return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  //panic("Not implemented");
  size_t i=0;
  while(i<n){
    if(*(s1+i)!='\0' && *(s2+i)!='\0'){
      if(*(s1+i) > *(s2+i)) return 1;
      else if(*(s1+i) < *(s2+i)) return -1;
      i++;
    }else{
      if(*(s1+i)=='\0' && *(s2+i)!='\0') return -1;
      else if(*(s1+i)!='\0' && *(s2+i)=='\0') return 1;
      else return 0;
    }
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  //panic("Not implemented");
  uint8_t s8=c&0xff;
  uint32_t s32=s8|(s8<<8)|(s8<<16)|(s8<<24);
  uint8_t *sb=(uint8_t*)s;
  while(n && ((uintptr_t)sb & (sizeof(uint32_t)-1))){
    *(sb++)=s8;
    n--;
  }
  
  uint32_t *sl=(uint32_t*)sb;
  while(n >= sizeof(uint32_t)){
    *(sl++)=s32;
    n-=sizeof(uint32_t);
  }

  sb=(uint8_t*)sl;
  while(n--){
    *(sb++)=s8;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  //panic("Not implemented");
  size_t i=0;
  if(dst<=src || ((char*)dst>(char*)src && ((char*)src+n <= (char*)dst))){
    while(i<n){
      *((char*)dst+i) = *((char*)src+i);
      i++;
    }
  }else{
    i=n;
    while(i){
      *((char*)dst+i-1) = *((char*)src+i-1);
      i--;
    }
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  //panic("Not implemented");
  uint8_t *outb=(uint8_t*)out,*inb=(uint8_t*)in;
  
  while(n--){
    *(outb++) = *(inb++);
  }

  // while(n && !(((uintptr_t)outb & (sizeof(uint32_t)-1)) || ((uintptr_t)inb & (sizeof(uint32_t)-1)))){
  //   *(outb++) = *(inb++);
  //   n--;
  // }

  // uint32_t *outl=(uint32_t*)outb,*inl=(uint32_t*)inb;
  // while(n>=sizeof(uint32_t)){
  //   *(outl++) = *(inl++);
  //   n-=sizeof(uint32_t);
  // }
  
  // outb=(uint8_t*)outl;
  // inb=(uint8_t*)inl;
  // while(n--){
  //   *(outb++) = *(inb++);
  // }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  //panic("Not implemented");
  size_t i=0;
  while(i<n){
    if( *((char*)s1+i) != *((char*)s2+i) )
      return *((char*)s1+i) - *((char*)s2+i);
    i++;
  }
  return 0;
}

#endif
