#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  // if(s==NULL) return 0;
  size_t n=0;
  while(s[n]!='\0') ++n;
  return n;
}

char *strcpy(char *dst, const char *src) {
  if(dst==NULL || src==NULL) return dst;
  char *ptr=dst;//dst指针会在复制过程中移动，所以需要保存其起始地址以便返回
  while((*dst++ = *src++)!='\0');
  // *dst='\0';//复制结束后在末尾添加空字符
  return ptr;
}

char *strncpy(char *dst, const char *src, size_t n) {
  if(n==0 || dst==NULL || src==NULL) return dst;
  size_t i;
  for(i=0;i<n && src[i]!='\0';i++) dst[i]=src[i];
  for(;i<n;i++) dst[i]='\0';//空字符填充剩余内容
  return dst;
}

//用于将一个字符串（源字符串）追加到另一个字符串（目标字符串）的末尾
char *strcat(char *dst, const char *src) {
  if(dst==NULL || src==NULL) return dst;
  char *ptr=dst;
  while(*ptr!='\0') ptr++;//!!!!!!!!!!!!!!!!
  while((*ptr++ = *src++)!='\0');
  // *dst='\0';
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  if(s1==NULL || s2==NULL) return 0;
  while(*s1 && *s2 && *s1==*s2){
    s1++;
    s2++;
  }
  if(*s1>*s2) return 1;
  else if(*s1<*s2) return -1;
  else return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  if(s1==NULL || s2==NULL) return 0;
  while(n--){
    if(*s1>*s2) return 1;
    if(*s1<*s2) return -1;
    s1++;
    s2++;
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  if(s==NULL) return NULL;
  char *ptr=(char *)s;
  while(n--) *ptr++=c;
  return s;
}

//memmove用于将一块内存区域的内容复制到另一块内存区域， 会处理源内存和目标内存重叠的情况
void *memmove(void *dst, const void *src, size_t n) {
  if (dst == NULL || src == NULL) return dst;
  char *d=(char *)dst;
  const char *s=(const char *)src;
  if (d < s) {
    // 如果目标地址在源地址之前，正向复制
    while (n--) {
      *d++ = *s++;
    }
  } else {
    // 如果目标地址在源地址之后，反向复制
    d += n;
    s += n;
    while (n--) {
      *--d = *--s;
    }
  }

  return dst; // 返回目标地址
}

void *memcpy(void *out, const void *in, size_t n) {
  if (out == NULL || in == NULL) return NULL;
  char *dst=(char *)out;
  const char *src=(const char *)in;
  // while(n--) *dst++ = *src++;
  if (src < dst && dst < src + n) {// 如果内存区域重叠，且目标地址在源地址之前
        dst += n - 1;
        src += n - 1;
        while (n--) {
            *dst-- = *src--;
        }
    } else {
        while (n--) {
            *dst++ = *src++;//正向复制
        }
    }
    return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  char *str1=(char *)s1;
  const char *str2=(const char *)s2;
  while(n--){
    if(*str1>*str2) return 1;
    if(*str1<*str2) return -1;
    str1++;
    str2++;
  }
  return 0;
}

#endif
