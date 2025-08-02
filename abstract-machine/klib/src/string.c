#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
	const char* _str = s;
	while (*s)
	{
		s++;
	}
	return s - _str;
}

char *strcpy(char *dst, const char *src) {
	//保留目标字符串起始地址
	char* _dest = dst;
	//逐个字符进行拷贝
	while ((*dst++ = *src++) != '\0')
	{
		;
	}
	return _dest;
}

char *strncpy(char *dst, const char *src, size_t n) {
    char *dest_start = dst;

    // 拷贝 src 到 dst，最多 n 个字符
    while (n > 0 && *src != '\0') {
        *dst++ = *src++;
        n--;
    }

    // 如果 src 的长度小于 n，用 '\0' 填充 dst 的剩余部分
    while (n > 0) {
        *dst++ = '\0';
        n--;
    }

    return dest_start;
//   panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
	char* _dest = dst;
	//找末尾\0
	while (*dst)
	{
		dst++;
	}
	//从目标字符串\0位置开始往后追加
	while ((*dst++ = *src++) != '\0')
	{
		;
	}
	return _dest; 
}

int strcmp(const char *s1, const char *s2) {
	//使用循环遍历 str1 和 str2,同时比较它们的对应字符
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return 0;
		}
		s1++;
		s2++;
	}
	//发现字符不相等，则返回它们的差值
	return *s1 - *s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
    // 如果n为0，直接返回0，因为没有字符需要比较
    if (n == 0) {
        return 0;
    }

    // 使用循环比较s1和s2的字符，最多比较n个字符
    while (n-- > 0) {
        if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0') {
            return (unsigned char)*s1 - (unsigned char)*s2;
        }
        s1++;
        s2++;
    }

    // 如果前n个字符都相等，返回0
    return 0;
	// panic("Not implemented");
}

void *memset(void *s, int c, size_t n) {
	char *xs = s;

	while (n--)
		*xs++ = c;
	return s;
}

void *memmove(void *dst, const void *src, size_t n) {
	char *tmp;
	const char *s;

	if (dst <= src) {
		tmp = dst;
		s = src;
		while (n--)
			*tmp++ = *s++;
	} else {
		tmp = dst;
		tmp += n;
		s = src;
		s += n;
		while (n--)
			*--tmp = *--s;
	}
	return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
	char *tmp = out;
	const char *s = in;

	while (n--)
		*tmp++ = *s++;
	return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
	const unsigned char *su1, *su2;
	int res = 0;

	for (su1 = s1, su2 = s2; 0 < n; su1++, su2++, n--)
		if ((res = *su1 - *su2) != 0)
			break;
	return res;
}

#endif
