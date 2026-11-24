#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
    const char *start = s;

    // check it one by one
    while (*s)
        s++;
    return s - start;
}

char *strcpy(char *dst, const char *src) {
    char *ori_dst = dst;

    while ((*dst++ = *src++)) {
        // empty loop
    }

    return ori_dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
    char *ori_dst = dst;

    // find the tail of dst
    while (*dst) {
        dst++;
    }

    // copy until the end of src
    while ((*dst++ = *src++)) {
        // empty loop
    }

    return ori_dst;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  while (n > 0 && *s1 && (*s1 == *s2)) {
      s1++;
      s2++;
      n--;
  }
  if (n == 0) {
      return 0;
  }
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

void *memset(void *s, int c, size_t n) {
    unsigned char *p = s;
    while (n--) {
        *p++ = (unsigned char)c;
    }
    return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  unsigned char *d = (unsigned char *)dst;
  const unsigned char *s = (const unsigned char *)src;

  if (d == s || n == 0) return dst;

  if (d < s || d >= s + n) {
    // no overlap, copy from start to end
    while (n--) {
      *d++ = *s++;
    }
  } else {
    // overlap, copy from end to start
    d += n;
    s += n;
    while (n--) {
      *(--d) = *(--s);
    }
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
    uintptr_t *dest = (uintptr_t *)out;
    const uintptr_t *src = (const uintptr_t *)in;

    while (n >= sizeof(uintptr_t)) {  // 以 `uintptr_t` 为单位拷贝
        *dest++ = *src++;
        n -= sizeof(uintptr_t);
    }

    // 处理剩余的字节
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    while (n--) {
        *d++ = *s++;
    }

    return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *p1 = (unsigned char *)s1;
    unsigned char *p2 = (unsigned char *)s2;

    while (n--) {
        if (*p1 != *p2) {
            return *p1 - *p2;
        }
        p1++;
        p2++;
    }
    return 0;
}

#endif
