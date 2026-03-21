#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

#define STRLEN 1024

static char *print_int_to_buf(char *out, int num);
static char *print_uint_to_buf(char *out, unsigned int num);
static char *print_str_to_buf(char *out, char *str); 
static char *print_hex_to_buf(char *out, unsigned int num, int uppercase);

int vsprintf(char *out, const char *fmt, va_list ap) {
    char *origin_out = out; 
    
    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            
            int field_width = 0;
            
            while (*fmt >= '0' && *fmt <= '9') {
                field_width = field_width * 10 + (*fmt - '0');
                fmt++;
            }

            if (*fmt == 'l') fmt++;
            
            switch (*fmt) {
                case 'u': {
                    unsigned int num = va_arg(ap, unsigned int);
                    out = print_uint_to_buf(out, num);
                    break;
                }
                case 'd': 
                case 'i': {
                    int num = va_arg(ap, int);
                    out = print_int_to_buf(out, num);
                    break;
                }
                case 's': {
                    char *str = va_arg(ap, char *);
                    out = print_str_to_buf(out, str);
                    break;
                }
                case 'c': {
                    int ch = va_arg(ap, int);
                    *out++ = (char)ch;
                    break;
                }
                case 'x': {
                    unsigned int num = va_arg(ap, unsigned int);
                    out = print_hex_to_buf(out, num, 0);
                    break;
                }
                case 'X': {
                    unsigned int num = va_arg(ap, unsigned int);
                    out = print_hex_to_buf(out, num, 1);
                    break;
                }
                case 'p': {
                    void *ptr = va_arg(ap, void*);
                    uintptr_t num = (uintptr_t)ptr;
                    *out++ = '0';
                    *out++ = 'x';
                    out = print_hex_to_buf(out, num, 1);
                    break;
                }
                case '%': {
                    *out++ = '%';
                    break;
                }
                default: {
                    *out++ = '%';
                    *out++ = *fmt;
                    break;
                }
            }
            fmt++;
        } else {
            *out++ = *fmt++;
        }
    }
    
    *out = '\0';
    return out - origin_out;
}

int printf(const char *fmt, ...) {
    va_list ap;
    char out[STRLEN] = {0};

    va_start(ap, fmt);
    int ret = vsprintf(out, fmt, ap);
    va_end(ap);

    putstr(out);

    return ret;
}


int sprintf(char *out, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int ret = vsprintf(out, fmt, ap);
    va_end(ap);
    return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int ret = vsnprintf(out, n, fmt, ap);
    va_end(ap);
    return ret;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
    if (n == 0) return 0;
    
    char *origin_out = out;
    char buffer[32];
    size_t remaining = n - 1; // 为null终止符保留空间
    
    while (*fmt && remaining > 0) {
        if (*fmt == '%') {
            fmt++;
            
            switch (*fmt) {
                case 'u': {
                    unsigned int num = va_arg(ap, unsigned int);
                    char *temp = buffer;
                    temp = print_uint_to_buf(temp, num);
                    *temp = '\0';
                    
                    size_t len = temp - buffer;
                    if (len > remaining) len = remaining;
                    
                    memcpy(out, buffer, len);
                    out += len;
                    remaining -= len;
                    break;
                }
                case 'd': 
                case 'i': {
                    int num = va_arg(ap, int);
                    char *temp = buffer;
                    temp = print_int_to_buf(temp, num);
                    *temp = '\0';
                    
                    size_t len = temp - buffer;
                    if (len > remaining) len = remaining;
                    
                    memcpy(out, buffer, len);
                    out += len;
                    remaining -= len;
                    break;
                }
                case 's': {
                    char *str = va_arg(ap, char *);
                    size_t len = strlen(str);
                    if (len > remaining) len = remaining;
                    
                    memcpy(out, str, len);
                    out += len;
                    remaining -= len;
                    break;
                }
                case 'c': {
                    if (remaining > 0) {
                        int ch = va_arg(ap, int);
                        *out++ = (char)ch;
                        remaining--;
                    }
                    break;
                }
                case '%': {
                    if (remaining > 0) {
                        *out++ = '%';
                        remaining--;
                    }
                    break;
                }
                default: {
                    if (remaining > 1) {
                        *out++ = '%';
                        *out++ = *fmt;
                        remaining -= 2;
                    }
                    break;
                }
            }
            fmt++;
        } else {
            *out++ = *fmt++;
            remaining--;
        }
    }
    
    *out = '\0';
    return out - origin_out;
}

char *print_uint_to_buf(char *out, unsigned int num) {
    char buffer[32];
    int i = 0;

    if(num == 0) {
        buffer[i++] = '0';
    } else {
        while(num > 0) {
            buffer[i++] = '0' + (num % 10);
            num /= 10;
        }
    }

    for(int j=i-1; j>=0; j--) *out++ = buffer[j];

    return out;
}

char *print_int_to_buf(char *out, int num) {
    if (num == (-2147483647 - 1)) { // 更安全的INT_MIN检查
        const char *min_str = "-2147483648";
        while (*min_str) *out++ = *min_str++;
        return out;
    }
    
    if (num < 0) {
        *out++ = '-';
        num = -num;
    }
    
    return print_uint_to_buf(out, (unsigned int)num);
}

char *print_str_to_buf(char *out, char *str) {
    while(*str) *out++ = *str++;

    return out;
}

char *print_hex_to_buf(char *out, unsigned int num, int uppercase) {
    char buffer[32];
    int i = 0;
    const char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (num == 0) {
        buffer[i++] = '0';
    } else {
        while (num > 0) {
            buffer[i++] = digits[num % 16];
            num /= 16;
        }
    }

    for (int j = i - 1; j >= 0; j--) {
        *out++ = buffer[j];
    }

    return out;
}

#endif
