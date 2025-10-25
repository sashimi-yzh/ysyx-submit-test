#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
int vsprintf(char *out, const char *fmt, va_list ap);
static int number_to_string(char *buf, int num, int base)
{
	if (base < 2 || base > 16)
		return 0;

	char tmp[32];
	int i = 0;
	int is_negative = 0;
	if (num == -2147483648)
	{
		switch (base)
		{
		case 10:
			strcpy(buf, "-2147483648");
			return 11;
		default:
			break; // 其他进制需扩展
		}
	}
	if (num < 0 && base == 10)
	{
		is_negative = 1;
		num = -num;
	}

	if (num == 0)
	{
		tmp[i++] = '0';
	}
	else
	{
		while (num > 0)
		{
			int digit = num % base;
			tmp[i++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
			num /= base;
		}
	}

	if (is_negative)
	{
		tmp[i++] = '-';
	}

	int len = i;
	for (int j = 0; j < len; j++)
	{
		buf[j] = tmp[i - 1 - j];
	}
	buf[len] = '\0';
	return len;
}
static int unsigned_number_to_string(char *buf, unsigned int num, int base)
{
	if (base < 2 || base > 16)
		return 0;

	char tmp[32];
	int i = 0;
	if (num == 0)
	{
		tmp[i++] = '0';
	}
	else
	{
		while (num > 0)
		{
			int digit = num % base;
			tmp[i++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
			num /= base;
		}
	}
	int len = i;
	for (int j = 0; j < len; j++)
	{
		buf[j] = tmp[i - 1 - j];
	}
	buf[len] = '\0';
	return len;
}
int printf(const char *fmt, ...)
{
	char buf[128];
	va_list args;
	va_start(args, fmt);
	int written = vsprintf(buf, fmt, args);
	va_end(args);
	for (const char *p = buf; *p; p++)
	{
		putch(*p);
	}
	return written;
}

int vsprintf(char *out, const char *fmt, va_list ap)
{
	int written = 0;
	for (const char *p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			*out++ = *p;
			written++;
			continue;
		}

		p++; // 跳过%
		switch (*p)
		{
		case 'd':
		{
			int num = va_arg(ap, int);
			written += number_to_string(out, num, 10);
			out += strlen(out);
			break;
		}
		case 's':
		{
			char *str = va_arg(ap, char *);
			if (!str)
				str = "(null)";
			size_t len = strlen(str);
			memcpy(out, str, len);
			out += len;
			written += len;
			break;
		}
		case 'c':
		{
			char ch = (char)va_arg(ap, int);
			*out++ = ch;
			written++;
			break;
		}
		case 'x':
		case 'p':
		{
			unsigned int num = va_arg(ap, unsigned int);
			written += unsigned_number_to_string(out, num, 16);
			out += strlen(out);
			break;
		}
		case 'u':
		{
			unsigned int num = va_arg(ap, unsigned int);
			written += unsigned_number_to_string(out, num, 10);
			out += strlen(out);
			break;
		}
		case '%':
		{
			*out++ = '%';
			written++;
			break;
		}
		// 其他格式可在此扩展
		default:
			break; // 不支持的格式直接忽略
		}
	}

	*out = '\0';
	return written;
}

int sprintf(char *out, const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int written = vsprintf(out, fmt, args);
	va_end(args);
	return written;
}

int snprintf(char *out, size_t n, const char *fmt, ...)
{
	panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap)
{
	panic("Not implemented");
}

#endif
