#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  // 遍历字符串直到遇到'\0'
  while (s[len] != '\0') {
    len++;
  }
  return len;
}

char *strcpy(char *dst, const char *src) {
  char *ret = dst;  // 保存dst的起始地址用于返回
  // 逐字符复制，包括'\0'
  while ((*dst++ = *src++) != '\0');
  return ret;
}

char *strncpy(char *dst, const char *src, size_t n) {
  size_t i;
  // 复制src的字符，直到遇到'\0'或复制了n个字符
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dst[i] = src[i];
  }
  // 如果src长度小于n，用'\0'填充剩余空间
  for (; i < n; i++) {
    dst[i] = '\0';
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  char *ret = dst;  // 保存dst的起始地址
  // 找到dst的末尾（'\0'的位置）
  while (*dst != '\0') {
    dst++;
  }
  // 将src复制到dst的末尾（包括'\0'）
  while ((*dst++ = *src++) != '\0');
  return ret;
}

int strcmp(const char *s1, const char *s2) {
  // 逐字符比较，直到遇到不同的字符或'\0'
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  // 返回第一个不同字符的差值
  // 使用unsigned char避免符号扩展问题
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  // 如果n为0，直接返回0
  if (n == 0) {
    return 0;
  }
  // 逐字符比较，直到遇到不同的字符、'\0'或比较了n个字符
  while (n > 0 && *s1 && (*s1 == *s2)) {
    s1++;
    s2++;
    n--;
  }
  // 如果已经比较了n个字符，返回0
  if (n == 0) {
    return 0;
  }
  // 返回第一个不同字符的差值
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

void *memset(void *s, int c, size_t n) {
  unsigned char *p = s;
  // 将c转换为unsigned char，然后设置n个字节
  while (n--) {
    *p++ = (unsigned char)c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  unsigned char *d = dst;
  const unsigned char *s = src;
  
  // 如果dst在src之前，或者没有重叠，从前往后复制
  if (d <= s || d >= s + n) {
    while (n--) {
      *d++ = *s++;
    }
  }
  // 如果dst在src之后且有重叠，从后往前复制
  else {
    d += n;
    s += n;
    while (n--) {
      *--d = *--s;
    }
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  unsigned char *dst = out;
  const unsigned char *src = in;
  // 简单地从前往后复制
  while (n--) {
    *dst++ = *src++;
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *p1 = s1;
  const unsigned char *p2 = s2;
  // 逐字节比较
  while (n--) {
    if (*p1 != *p2) {
      return *p1 - *p2;
    }
    p1++;
    p2++;
  }
  // 所有字节都相同
  return 0;
}

#endif
