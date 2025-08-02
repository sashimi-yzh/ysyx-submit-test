#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <string.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// 辅助函数：将字符串输出到串口
void puts(const char *str) {
    while (*str) {
        putch(*str++);
    }
}

void put_long(long value) {
    char buffer[21]; // 足够存放最大64位整数的字符数组，包括负号和结束符
    int i = 0;
    unsigned long uvalue;

    if (value == 0) {
        putch('0');
        return;
    }

    if (value == 0x8000000000000000) {
        // 特殊处理 LONG_MIN
        puts("-9223372036854775808");
        return;
    }

    if (value < 0) {
        putch('-');
        uvalue = (unsigned long)(-value);
    } else {
        uvalue = (unsigned long)value;
    }

    // 将数字转换为字符串（逆序）
    while (uvalue != 0) {
        buffer[i++] = (uvalue % 10) + '0';
        uvalue /= 10;
    }

    // 逆序输出
    while (i--) {
        putch(buffer[i]);
    }
}

// 辅助函数：将整数转换为字符串并输出
void put_int(int value) {
    char buffer[12]; // 够用来存放最大32位整数的字符数组，包括负号和结束符
    int i = 0;
    unsigned int uvalue;

    if (value == 0) {
        putch('0');
        return;
    }

    if (value == 0x80000000) {
        // 特殊处理 INT_MIN
        puts("-2147483648");
        return;
    }

    if (value < 0) {
        putch('-');
        uvalue = (unsigned int)(-value);
    } else {
        uvalue = (unsigned int)value;
    }

    // 将数字转换为字符串（逆序）
    while (uvalue != 0) {
        buffer[i++] = (uvalue % 10) + '0';
        uvalue /= 10;
    }

    // 逆序输出
    while (i--) {
        putch(buffer[i]);
    }
}

void put_hex(unsigned int value) {
    char buffer[9]; // 够用来存放32位整数的十六进制表示，包括结束符
    int i = 0;

    if (value == 0) {
        putch('0');
        return;
    }

    // 将数字转换为十六进制字符串（逆序）
    while (value != 0) {
        unsigned int digit = value % 16;
        buffer[i++] = (digit < 10) ? ('0' + digit) : ('a' + (digit - 10));
        value /= 16;
    }

    // 逆序输出
    while (i--) {
        putch(buffer[i]);
    }
}

int printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            if (*fmt == 'l') {
                fmt++;
                if (*fmt == 'd') {
                    long value = va_arg(args, long);
                    put_long(value);
                }
                // 可以添加其他类似的处理，如%lx, %lu等
            } else {
                switch (*fmt) {
                    case 'c': {
                        char ch = (char)va_arg(args, int);
                        putch(ch);
                        break;
                    }
                    case 'd':
                    case 'i': {
                        int value = va_arg(args, int);
                        put_int(value);
                        break;
                    }
                    case 's': {
                        const char *str = va_arg(args, const char *);
                        puts(str);
                        break;
                    }
                    case 'x': {
                        unsigned int value = va_arg(args, unsigned int);
                        put_hex(value);
                        break;
                    }
                    default:
                        putch('%');
                        putch(*fmt);
                        break;
                }
            }
        } else {
            putch(*fmt);
        }
        fmt++;
    }

    va_end(args);
    return 0;
}


// the num must be positive
void int2str(int num, char *str) {
	int one = num % 10;
	int temp = num / 10;
	char num_str[2] = {'\0', '\0'};

	if(temp != 0)
		int2str(temp, str);
	
	num_str[0] = one + '0';
	strcat(str, num_str);
}

#define APPEND(c) do {   \
	def_str[0] = c;        \
	strcat(out, def_str);  \
} while(0)

int vsprintf(char *out, const char *fmt, va_list ap) {
	int d, ch_num = 0;
	char *s;
	char int_str[10];
	char def_str[2] = {'\0', '\0'};

	while (*fmt) {
		switch (*fmt) {
		case 's':              /* string */
			if(*(fmt - 1) != '%')  //%s
				APPEND('s');
			else{
				s = va_arg(ap, char *);
				strcat(out, s);
			}
			break;
		case 'd':              /* int */
			if(*(fmt - 1) != '%')  //%d
				APPEND('d');
			else{
				d = va_arg(ap, int); //the int is negative
				if(d < 0){
					strcat(out, "-");
					d = -d;
				}
				int_str[0] = '\0';
				int2str(d, int_str);
				int_str[strlen(int_str)] = '\0';
				strcat(out, int_str);
			}
			break;
		case '%':             
			break;
		default:
			APPEND(*fmt);
			break;
		}
		fmt++;
   		ch_num++;
	}
  return ch_num;
}

int sprintf(char *out, const char *fmt, ...) {
	va_list ap;
	int ret;

	out[0] = '\0';    //clear the out string
	va_start(ap, fmt);
	ret = vsprintf(out, fmt, ap);
	va_end(ap);
	return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
