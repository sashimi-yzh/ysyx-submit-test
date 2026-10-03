#include "am.h"
#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
    assert(s);
    size_t i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}

char *strcpy(char *dst, const char *src) {
    assert(dst&&src);
    size_t i;
    for(i=0;src[i]!='\0';i++){
        dst[i]=src[i];
    }
    dst[i]='\0';
    return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
    assert(dst&&src);
    size_t i;
    for(i=0;src[i]!='\0'&&i<n;i++){
        dst[i]=src[i];
    }
    while(i<n){
        dst[i]='\0';
        i++;
    }
    return dst;
}

char *strcat(char *dst, const char *src) {
    assert(dst&&src);
    strcpy(dst+strlen(dst),src);
    return dst;
}

int strcmp(const char *s1, const char *s2) {
    assert(s1&&s2);
    size_t i=0;
    while(s1[i]==s2[i]&&s1[i]!='\0'){
        i++;
    }
    return (int)(unsigned char)s1[i]-(int)(unsigned char)s2[i];
}

int strncmp(const char *s1, const char *s2, size_t n) {
    assert(s1&&s2);
    if(n==0)
        return 0;
    size_t i=0;
    while(s1[i]==s2[i]&&s1[i]!='\0'&&i<n-1){
        i++;
    }
    return (int)(unsigned char)s1[i]-(int)(unsigned char)s2[i];
}

void *memset(void *s, int c, size_t n) {
    assert(s);
    size_t i;
    for(i=0;i<n;i++){
        *((char *)s+i)=c;
    }
    return s;
}

void *memmove(void *dst, const void *src, size_t n) {
    assert(dst&&src);
    size_t i;
    if(dst<src){
        for(i=0;i<n;i++){
            ((char *)dst)[i]=((char *)src)[i];
        }
    }else if(dst>src){
        for(i=n;i>0;i--){
            ((char *)dst)[i-1]=((char *)src)[i-1];
        }
    }
    return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
    assert(out&&in);
    size_t i;
    for(i=0;i<n;i++){
        ((char *)out)[i]=((char *)in)[i];
    }
    return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    assert(s1&&s2);
    if(n==0)
        return 0;
    size_t i=0;
    while(((unsigned char*)s1)[i]==((unsigned char*)s2)[i]&&i<n-1){
        i++;
    }
    return (int)((unsigned char*)s1)[i]-(int)((unsigned char*)s2)[i];
}

#endif
