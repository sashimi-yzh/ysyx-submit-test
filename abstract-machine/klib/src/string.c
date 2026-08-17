#include <klib-macros.h>
#include <klib.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  while (s[len] != '\0')
    len++;

  return len;
}

char *strcpy(char *dst, const char *src) {
  char *ret = dst;
  while ((*dst = *src) != '\0') {
    dst++;
    src++;
  }
  return ret;
}

char *strncpy(char *dst, const char *src, size_t n) {
  size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dst[i] = src[i];
  }
  for (; i < n; i++) {
    dst[i] = '\0';
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  char *ret = dst;
  while (*dst)
    dst++;
  while ((*dst = *src) != '\0') {
    dst++;
    src++;
  }
  return ret;
}

int strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  const unsigned char *p1 = (const unsigned char *)s1;
  const unsigned char *p2 = (const unsigned char *)s2;
  while (n-- > 0) {
    if (*p1 != *p2) {
      return *p1 - *p2;
    }
    if (*p1 == '\0') {
      return 0;
    }
    p1++;
    p2++;
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  unsigned char *p = (unsigned char *)s;
  while ((((uintptr_t)p) & 0x3) && n) {
    *p++ = (unsigned char)c;
    n--;
  }
  const uint32_t content = ((unsigned char)c << 24) | ((unsigned char)c << 16) |
                           ((unsigned char)c << 8) | (unsigned char)c;
  while (n >= 4) {
    *(uint32_t *)p = content;
    p += 4;
    n -= 4;
  }

  const unsigned char uc = (unsigned char)c;
  while (n-- > 0) {
    *p++ = uc;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  unsigned char *d = (unsigned char *)dst;
  const unsigned char *s = (const unsigned char *)src;
  if (d < s) {
    while (n-- > 0) {
      *d++ = *s++;
    }
  } else if (d > s) {
    d += n;
    s += n;
    while (n-- > 0) {
      *--d = *--s;
    }
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  unsigned char *d = (unsigned char *)out;
  const unsigned char *s = (const unsigned char *)in;

  while ((((uintptr_t)d) & 0x3) && n) {
    *d++ = *s++;
    n--;
  }

  while (n >= 4) {
    *(uint32_t *)d = *(const uint32_t *)s;
    d += 4;
    s += 4;
    n -= 4;
  }

  while (n-- > 0) {
    *d++ = *s++;
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *p1 = (const unsigned char *)s1;
  const unsigned char *p2 = (const unsigned char *)s2;
  while (n-- > 0) {
    if (*p1 != *p2) {
      return *p1 - *p2;
    }
    p1++;
    p2++;
  }
  return 0;
}

#endif
