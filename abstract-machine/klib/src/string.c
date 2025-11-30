#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  int i = 0;
	while(s[i] != '\0') {
		i ++;
	}
	return i;
}

char *strcpy(char *dst, const char *src) {
	int i = 0;
	while(src[i] != '\0') {
		dst[i] = src[i];
		i ++;
	}
	dst[i] = '\0';
	return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
	if(strlen(src) < n) {
		int i = 0;
		while((i < strlen(src) - 1)) {
			dst[i] = src[i];
			i ++;
		}
		for(; i < n; i ++) {
			dst[i] = '\0';
		}
	}
	else {
		int j = 0;
		while(j < n) {
			dst[j] = src[j];
			j ++;
		}
	}
  return dst;
}

char *strcat(char *dst, const char *src) {
	int i = 0;
	int j = strlen(dst);
	while(src[i] != '\0') {
		dst[j] = src[i];
		i ++;
		j ++;
	}
	return dst;
}

int strcmp(const char *s1, const char *s2) {
	int i = 0;
	while((s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '\0') {
		i ++;
	}
	if(s1[i] < s2[i])
		return -1;
	else if(s1[i] > s2[i])
		return 1;
	else return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  int i = 0;
  while((i < n-1) && (s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '\0') {
    i ++;
  }
  if(s1[i] < s2[i])
    return -1;
  else if(s1[i] > s2[i])
    return 1;
  else return 0;
}

void *memset(void *s, int c, size_t n) {
	int i = 0;
	volatile char *p = (char *)s;
	while(i < n) {
		*p ++ = (char)c;
		i ++;
	}
	return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  volatile char *d = (char *)dst;
  char *s = (char *)src;
	if(d < s) {
		int i = 0;
		while(i < n) {
			*d ++ = *s ++;
			i ++;
		}
	}
	else if(d > s) {
		int i = n;
		while(i > 0) {
			d[i-1] = s[i-1];
			i --;
		}
	}
	return dst;	
}

void *memcpy(void *out, const void *in, size_t n) {
  int j = 0;
	char *o = (char *)out;
	char *i = (char *)in;
	while(j < n) {
		*o ++ = *i ++;
		j ++;
	}
	return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
	int i = 0;
	char *c1 = (char *)s1;
	char *c2 = (char *)s2;
	while((i < (n-1)) && (c1[i] == c2[i])) {
		i ++;
	}
	if(c1[i] < c2[i])
		return -1;
	else if(c1[i] > c2[i])
		return 1;
	else
		return 0;
}

#endif
