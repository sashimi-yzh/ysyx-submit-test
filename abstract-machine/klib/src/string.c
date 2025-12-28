#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
	const char *p = s;
	while(*p != '\0'){
		p++;
	}
	return (size_t)(p - s);
  //panic("Not implemented");
}

char *strcpy(char *dst, const char *src) {
	char *p = dst;
	while (*src != '\0') { 
		*dst = *src; 
		dst++;
		src++;
	    }
	    *dst = '\0';
	    return p;
			
  //panic("Not implemented");
}

char *strncpy(char *dst, const char *src, size_t n) {
	char *p = dst;
	while(*src != '\0' && n != 0){
		*dst = *src;
		dst++;
		src++;
		n--;
	}
	*dst = '\0';
	return p;
  //panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
	char *p = dst;
	while(*dst != '\0'){
		dst++;
	}
	while(*src != '\0'){
		*dst = *src;
		src++;
		dst++;
	}
	*dst ='\0';
	return p;
	
  //panic("Not implemented");
}

int strcmp(const char *s1, const char *s2) {
	while(*s1 != '\0' && *s2 != '\0' && *s1 ==*s2){
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
  
}

int strncmp(const char *s1, const char *s2, size_t n) {
	while(*s1 != '\0' && *s2 != '\0' && *s1 ==*s2 && n !=0){
		s1++;
		s2++;
		n--;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
  //panic("Not implemented");
}

void *memset(void *s, int c, size_t n) {
	unsigned char a = (unsigned char)c;
	unsigned char *p = (unsigned char *)s;
	for(int i=0;i<n;i++){
		p[i] = a;
	}
	return s;
  //panic("Not implemented");
}

void *memmove(void *dst, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    
    for (size_t i = 0; i < n; i++) {
          d[i] = s[i];
    }
    return dst;
}
void *memcpy(void *out, const void *in, size_t n) {
	unsigned char *d = (unsigned char *)out;
    	const unsigned char *s = (const unsigned char *)in;
    	for (size_t i = 0; i < n; i++) {
          d[i] = s[i];
    }
    return out;

}

int memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;

    for (size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return (unsigned char)p1[i] - (unsigned char)p2[i];
        }
    }
    return 0;
}
#endif
