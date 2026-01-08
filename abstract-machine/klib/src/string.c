#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {  //计算字符串长度
	const char *p = s;
	while( *p != '\0'){
		p++;
	}
	return p - s;
}

char *strcpy(char *dst, const char *src) { //将源字符串复制到dst
	char *dst_write = dst;
	while( *src != '\0'){
		*dst_write = *src;
		dst_write++;
		src++;
	}
	*dst_write = *src;
	return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {  //将源字符串复制到dst,指定最大复制字符数
	char *dst_write = dst;
	size_t i = 0;
	for (i = 0; i < n && src[i] != '\0'; i++) {
    	dst_write[i] = src[i];
  	}
  	for (; i < n; i++) {
    	dst_write[i] = '\0';  
	}
	return dst;
}

char *strcat(char *dst, const char *src) {  //将源字符串追加到目标字符串末尾
	char *dst_write = dst;
	dst_write += strlen(dst); 
	while( *src != '\0'){
		*dst_write = *src;
		dst_write++;
		src++;
	}
	*dst_write = '\0';
	return dst;
}

int strcmp(const char *s1, const char *s2) {
	while( (*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2) ){
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {  //比较两个字符串
    if (n == 0) return 0;
    
    for (size_t i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        }
        if ( (s1[i] == '\0') || (s2[i] == '\0') ){
            return 0;
        }
    }
    return 0;
}

void *memset(void *s, int c, size_t n) {  //将内存区域s的前 n 个字节设置为特定值c
	char *p = s;
	for(size_t i = 0; i < n;i++){
		*p = (unsigned char)c;
		p++;
	}
	return s;
}

void *memmove(void *dst, const void *src, size_t n) { //复制内存区域src到dst 处理内存重叠情况
	char *dst_w = dst;
	const char *src_w = src;	
	if (dst_w > src_w && dst_w < src_w + n) { //有重叠情况，倒着赋值
        dst_w += n - 1;
        src_w += n - 1;
        while (n--) {
            *dst_w-- = *src_w--;
        }
    } else {
        while (n--) {
            *dst_w++ = *src_w++;
        }
    }
    return dst;
}


void *memcpy(void *out, const void *in, size_t n) { //复制内存区域（不处理内存重叠）
	//put_pointer(out);put_uint32_t_0x(n);
	char *out_w = out;
	const char *in_w = in;	
	for(size_t i = 0; i < n; i++){
		out_w[i] = in_w[i];
	}
	return out;
}



int memcmp(const void *s1, const void *s2, size_t n) {  //比较两个内存区域的前 n 个字节

	const char *s1_r = s1;
	const char *s2_r = s2;
	for(size_t i = 0; i < n; i++){
		if((unsigned char)s1_r[i] != (unsigned char)s2_r[i]){
			return (unsigned char)s1_r[i] - (unsigned char)s2_r[i];
		}

	}
	return 0;
}

#endif
