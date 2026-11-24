#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static void itoa(long value, char *buffer, int base) {
    char temp[32];
    int i = 0, is_negative = 0;
    unsigned long abs = value;

    if (value == 0) {
        buffer[i++] = '0';
        buffer[i] = '\0';
        return;
    }

    if (value < 0 && base == 10) {
        is_negative = 1;
        // negate in unsigned domain: also correct for LONG_MIN
        abs = -(unsigned long)value;
    }

    while (abs) {
        int digit = abs % base;
        temp[i++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
        abs /= base;
    }

    if (is_negative) temp[i++] = '-';

    // reverse it
    int j = 0;
    while (i--) buffer[j++] = temp[i];
    buffer[j] = '\0';
}

static int vformat(void (*output)(char, char **), char **buf, const char *fmt, va_list args) {
    const char *fmt_ptr = fmt;
    char num_buffer[32];

    int count = 0;

    while (*fmt_ptr) {
        if (*fmt_ptr == '%' && *(fmt_ptr + 1)) {
            fmt_ptr++;  // skip '%'

            char pad_char = ' '; // default is blank
            int width = 0;       // default width

            if (*fmt_ptr == '0') {
                pad_char = '0';
                fmt_ptr++;
            }

            while (*fmt_ptr >= '0' && *fmt_ptr <= '9') {
                width = width * 10 + (*fmt_ptr - '0');
                fmt_ptr++;
            }

            int is_long = 0;
            while (*fmt_ptr == 'l') {  // %ld / %lx (%lld treated as long)
                is_long++;
                fmt_ptr++;
            }

            switch (*fmt_ptr) {
                case 'd': {  // int / long
                    long value = is_long ? va_arg(args, long) : va_arg(args, int);
                    itoa(value, num_buffer, 10);
                    int num_len = strlen(num_buffer);

                    while (num_len < width) {
                        output(pad_char, buf);
                        count++;
                        num_len++;
                    }

                    char *num_str = num_buffer;
                    while (*num_str) {
                        output(*num_str++, buf);
                        count++;
                    }
                    break;
                }
                case 'x': {  // unsigned int / unsigned long
                    unsigned long value = is_long ? va_arg(args, unsigned long)
                                                  : va_arg(args, unsigned int);
                    itoa(value, num_buffer, 16);
                    int num_len = strlen(num_buffer);

                    while (num_len < width) {
                        output(pad_char, buf);
                        count++;
                        num_len++;
                    }

                    char *num_str = num_buffer;
                    while (*num_str) {
                        output(*num_str++, buf);
                        count++;
                    }
                    break;
                }
                case 's': {  // string
                    char *str = va_arg(args, char *);
                    while (*str) {
                        output(*str++, buf);
                        count++;
                    }
                    break;
                }
                case 'c': {  // char
                    char ch = (char)va_arg(args, int);
                    output(ch, buf);
                    count++;
                    break;
                }
                case '%': {  // %%
                    output('%', buf);
                    count++;
                    break;
                }
                default: {  // unknown
                    output('%', buf);
                    output(*fmt_ptr, buf);
                    count += 2;
                    break;
                }
            }
        } else {
            output(*fmt_ptr, buf);
            count++;
        }
        fmt_ptr++;
    }

    return count;  // return the number of characters
}

// output using buffer
static void buffer_output(char ch, char **buf_ptr) {
    *(*buf_ptr)++ = ch;
}

// output using putch
static void putch_output(char ch, char **buf_ptr) {
    putch(ch);
}

int printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int count = vformat((void (*)(char, char **))putch_output, NULL, fmt, args);

    va_end(args);
    return count;
}

int sprintf(char *out, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char *buf_ptr = out;
    int count = vformat((void (*)(char, char **))buffer_output, &buf_ptr, fmt, args);

    *buf_ptr = '\0';  // add tail for string buffer

    va_end(args);
    return count;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
    char *buf_ptr = out;
    int count = vformat((void (*)(char, char **))buffer_output, &buf_ptr, fmt, ap);

    *buf_ptr = '\0';  // add the tail to string buffer

    return count;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
