#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
    //panic("Not implemented");
    size_t len = 0;
    const char* tmp = s;
    while(*tmp != '\0'){
        len++;
        tmp++;
    }
 //   len++;	// for '\0'
    return len;
}

char *strcpy(char *dst, const char *src) {
    //panic("Not implemented");
    size_t len = strlen(src);
    for(size_t i = 0;i < len;i++){
        dst[i] = src[i];
    }
    dst[len] = '\0';
    return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
    //panic("Not implemented");
    size_t i;
    for(i = 0;i < n && src[i] != '\0';i++){
        dst[i] = src[i];
    }
    for(;i < n;i++){
        dst[i] = '\0';
    }
    return dst;
}

char *strcat(char *dst, const char *src) {
    //panic("Not implemented");
    size_t index = strlen(dst);
    const char* tmp = src;
    while(*tmp != '\0'){
        dst[index] = *tmp;
        tmp++;
        index++;
    }
    dst[index] = '\0';
    return dst;
}

int strcmp(const char *s1, const char *s2) {
    //panic("Not implemented");
    int i;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; ++i){
        if (s1[i] != s2[i])
        return (int)(s1[i]) - (int)(s2[i]);
    }
    //case 同时结束：为0
    //case s1先结束，0-x < 0
    //case s2先结束，x-0 > 0
    return (int)(s1[i]) - (int)(s2[i]);
}

int strncmp(const char *s1, const char *s2, size_t n) {
    //panic("Not implemented");
    int i;
    for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; ++i){
        if (s1[i] != s2[i])
        return (int)(s1[i]) - (int)(s2[i]);
    }
    //case 同时结束：为0
    //case s1先结束，0-x < 0
    //case s2先结束，x-0 > 0
    //case 到达n，返回0
    if (i == n)
        return 0;
    return (int)(s1[i]) - (int)(s2[i]);
}

void *memset(void *s, int c, size_t n) {
  //panic("Not implemented");
    size_t i;
    char* tmp = (char*)s;

    for(i = 0;i < n;i++){
        *tmp = (char)c;
        tmp++;
    }
    return s;
}

void *memmove(void *dst, const void *src, size_t n) {
    //panic("Not implemented");
    char *d = (char *)dst;
    const char *s = (const char *)src;

    if (d < s) {
        for (int i = 0; i < n; i++) {
            d[i] = s[i];
        }
    } else if (d > s) {
        for (int i = n - 1; i >= 0; i--) {
            d[i] = s[i];
        }
    }

    return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  //panic("Not implemented");
    char *d = (char *)out;
    const char *s = (const char *)in;

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }

    return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    //panic("Not implemented");
    const char *p1 = (const char *)s1;
    const char *p2 = (const char *)s2;
    size_t len_1 = 0,len_2 = 0;
    len_1 = strlen(p1);
    len_2 = strlen(p2);
    size_t len = (len_1 > len_2)? len_2:len_1;
    len = (len > n)? n:len;

    for(size_t i = 0;i < len;i++){
        if(p1[i] != p2[i]){
            return p1[i] - p2[i];
        }
    }

    if(len >= n){
        return 0;
    }
    
    if(len_1 > len_2){
        return p1[len_2] - p2[len_2];
    }
    else if(len_1 < len_2){
        return p1[len_1] - p2[len_1];
    }
    
    return 0;
}

#endif
