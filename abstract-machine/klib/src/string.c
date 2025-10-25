#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s)
{
	if (!s)
		return 0;
	size_t len = 0;
	while (*s++)
		len++;
	return len;
}

char *strcpy(char *dst, const char *src)
{
	char *d = dst;
	while ((*dst++ = *src++))
		;
	return d;
}

char *strncpy(char *dst, const char *src, size_t n)
{
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++)
		dst[i] = src[i];
	for (; i < n; i++)
		dst[i] = '\0';
	return dst;
}

char *strcat(char *dst, const char *src)
{
	char *d = dst;
	while (*d)
		d++;
	while ((*d++ = *src++))
		;
	return dst;
}

int strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return 0;
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

void *memset(void *s, int c, size_t n)
{
	unsigned char *p = s;
	while (n--)
		*p++ = (unsigned char)c;
	return s;
}

void *memmove(void *dst, const void *src, size_t n)
{
	unsigned char *d = dst;
	const unsigned char *s = src;
	void *original_dst = dst;

	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return original_dst;
}

void *memcpy(void *out, const void *in, size_t n)
{
	const char *src = in;
	char *dst = out;
	while (n--)
		*dst++ = *src++;
	return out;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *p1 = s1;
	const unsigned char *p2 = s2;
	while (n--)
	{
		if (*p1 != *p2)
			return *p1 - *p2;
		p1++;
		p2++;
	}
	return 0;
}

#endif
