#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
typedef char *out_ch_func(char *, char, char *const begin, size_t max_len);

enum FLAGS_PRINTF {
  FLAGS_ZEROPAD = (1U << 0U),
  FLAGS_LEFT = (1U << 1U),
  FLAGS_PLUS = (1U << 2U),
  FLAGS_SPACE = (1U << 3U),
  FLAGS_HASH = (1U << 4U),
  FLAGS_UPPERCASE = (1U << 5U),
  FLAGS_CHAR = (1U << 6U),
  FLAGS_SHORT = (1U << 7U),
  FLAGS_LONG = (1U << 8U),
  FLAGS_LONG_LONG = (1U << 9U),
};
const static size_t Buffer_Size = 32u;

static size_t _out_rev(out_ch_func out, char **buffer, const char *buf,
                       size_t len, unsigned int width, unsigned int flags,
                       char *const begin, size_t max_len) {
  int ret = 0;
  if (!(flags & FLAGS_LEFT) && !(flags & FLAGS_ZEROPAD)) {
    for (size_t i = len; i < width; i++) {
      *buffer = out(*buffer, ' ', begin, max_len);
      ret++;
    }
  }

  for (size_t i = len; i > 0; i--) {
    *buffer = out(*buffer, buf[i - 1], begin, max_len);
    ret++;
  }
  if (flags & FLAGS_LEFT) {
    for (int i = 0; i < width - len; i++) {
      *buffer = out(*buffer, ' ', begin, max_len);
      ret++;
    }
  }

  return ret;
}

static size_t _ntoa_format(out_ch_func out, char **buffer, char *buf,
                           size_t len, bool negative, unsigned int base,
                           unsigned int width, unsigned int flags,
                           char *const begin, size_t max_len) {
  if (!(flags & FLAGS_LEFT)) {
    if (width && (flags & FLAGS_ZEROPAD) &&
        (negative || (flags & (FLAGS_PLUS | FLAGS_SPACE)))) {
      width--;
    }
    while ((flags & FLAGS_ZEROPAD) && (len < width) && (len < Buffer_Size)) {
      buf[len++] = '0';
    }
  }

  if (flags & FLAGS_HASH) {
    if (len && ((len == 0) || (len == width))) {
      len--;
      if (len && (base == 16U)) {
        len--;
      }
    }
    if ((base == 16U) && !(flags & FLAGS_UPPERCASE) && (len < Buffer_Size)) {
      buf[len++] = 'x';
    } else if ((base == 16U) && (flags & FLAGS_UPPERCASE) &&
               (len < Buffer_Size)) {
      buf[len++] = 'X';
    } else if ((base == 2U) && (len < Buffer_Size)) {
      buf[len++] = 'b';
    }
    if (len < Buffer_Size) {
      buf[len++] = '0';
    }
  }

  if (len < Buffer_Size) {
    if (negative) {
      buf[len++] = '-';
    } else if (flags & FLAGS_PLUS) {
      buf[len++] = '+';
    } else if (flags & FLAGS_SPACE) {
      buf[len++] = ' ';
    }
  }

  return _out_rev(out, buffer, buf, len, width, flags, begin, max_len);
}

static inline bool _is_digit(char ch) { return (ch >= '0') && (ch <= '9'); }
static unsigned int _atoi(const char **str) {
  unsigned int i = 0U;
  while (_is_digit(**str)) {
    i = i * 10U + (unsigned int)(*((*str)++) - '0');
  }
  return i;
}
static size_t _ntoa_long(out_ch_func out, char **buffer, unsigned long value,
                         bool negative, unsigned long base, unsigned int width,
                         unsigned int flags, char *const begin,
                         size_t max_len) {

  char buf[Buffer_Size];
  size_t len = 0U;

  if (!value) {
    flags &= ~FLAGS_HASH;
  }

  do {
    const char digit = (char)(value % base);
    buf[len++] = digit < 10
                     ? '0' + digit
                     : (flags & FLAGS_UPPERCASE ? 'A' : 'a') + digit - 10;
    value /= base;
  } while (value && (len < Buffer_Size));

  return _ntoa_format(out, buffer, buf, len, negative, (unsigned int)base,
                      width, flags, begin, max_len);
}

static inline unsigned int _strnlen_s(const char *str, size_t maxsize) {
  const char *s;
  for (s = str; *s && maxsize--; ++s)
    ;
  return (unsigned int)(s - str);
}

static size_t _ntoa_long_long(out_ch_func out, char **buffer,
                              unsigned long long value, bool negative,
                              unsigned long long base, unsigned int width,
                              unsigned int flags, char *const begin,
                              size_t max_len) {
  char buf[Buffer_Size];
  size_t len = 0U;

  if (!value) {
    flags &= ~FLAGS_HASH;
  }

  do {
    const char digit = (char)(value % base);
    buf[len++] = digit < 10
                     ? '0' + digit
                     : (flags & FLAGS_UPPERCASE ? 'A' : 'a') + digit - 10;
    value /= base;
  } while (value && (len < Buffer_Size));

  return _ntoa_format(out, buffer, buf, len, negative, (unsigned int)base,
                      width, flags, begin, max_len);
}

int __vasprintf(out_ch_func out, char *buffer, const char *format, va_list va,
                size_t max_len) {
  int ret_idx = 0;
  char *const begin = buffer;
  while (*format) {
    if (*format != '%') {
      buffer = out(buffer, *format, buffer, max_len);
      ret_idx++;
      format++;
      continue;
    } else
      format++;

    unsigned int flags = 0U, n;
    do {
      switch (*format) {
      case '0':
        flags |= FLAGS_ZEROPAD;
        format++;
        n = 1U;
        break;
      case '-':
        flags |= FLAGS_LEFT;
        format++;
        n = 1U;
        break;
      case '+':
        flags |= FLAGS_PLUS;
        format++;
        n = 1U;
        break;
      case ' ':
        flags |= FLAGS_SPACE;
        format++;
        n = 1U;
        break;
      case '#':
        flags |= FLAGS_HASH;
        format++;
        n = 1U;
        break;
      default:
        n = 0U;
        break;
      }
    } while (n);
    unsigned int width = 0;
    if (_is_digit(*format)) {
      width = _atoi(&format);
    } else if (*format == '*') {
      const int w = va_arg(va, int);
      if (w < 0) {
        flags |= FLAGS_LEFT;
        width = (unsigned int)-w;
      } else {
        width = (unsigned int)w;
      }
      format++;
    }

    switch (*format) {
    case 'l':
      flags |= FLAGS_LONG;
      format++;
      if (*format == 'l') {
        flags |= FLAGS_LONG_LONG;
        format++;
      }
      break;
    case 'z':
      flags |= (sizeof(size_t) == sizeof(long) ? FLAGS_LONG : FLAGS_LONG_LONG);
      format++;
      break;
    default:
      break;
    }

    switch (*format) {
    case 'd':
    case 'i':
    case 'u':
    case 'x':
    case 'X':
    case 'o':
    case 'b': {
      unsigned int base;
      if (*format == 'x' || *format == 'X') {
        base = 16U;
      } else if (*format == 'o') {
        base = 8U;
      } else if (*format == 'b') {
        base = 2U;
      } else {
        base = 10U;
        flags &= ~FLAGS_HASH;
      }

      if (*format == 'X') {
        flags |= FLAGS_UPPERCASE;
      }

      if ((*format != 'i') && (*format != 'd')) {
        flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
      }

      if ((*format == 'i') || (*format == 'd')) {
        if (flags & FLAGS_LONG_LONG) {
          const long long value = va_arg(va, long long);
          ret_idx += _ntoa_long_long(
              out, &buffer, (unsigned long long)(value > 0 ? value : 0 - value),
              value < 0, base, width, flags, begin, max_len);

        } else if (flags & FLAGS_LONG) {
          const long value = va_arg(va, long);
          ret_idx += _ntoa_long(out, &buffer,
                                (unsigned long)(value > 0 ? value : 0 - value),
                                value < 0, base, width, flags, begin, max_len);
        } else {
          const int value = (flags & FLAGS_CHAR)    ? (char)va_arg(va, int)
                            : (flags & FLAGS_SHORT) ? (short int)va_arg(va, int)
                                                    : va_arg(va, int);
          ret_idx += _ntoa_long(out, &buffer,
                                (unsigned int)(value > 0 ? value : 0 - value),
                                value < 0, base, width, flags, begin, max_len);
        }
      } else {
        if (flags & FLAGS_LONG_LONG) {
          ret_idx +=
              _ntoa_long_long(out, &buffer, va_arg(va, unsigned long long),
                              false, base, width, flags, begin, max_len);

        } else if (flags & FLAGS_LONG) {
          ret_idx += _ntoa_long(out, &buffer, va_arg(va, unsigned long), false,
                                base, width, flags, begin, max_len);
        } else {
          const unsigned int value =
              (flags & FLAGS_CHAR) ? (unsigned char)va_arg(va, unsigned int)
              : (flags & FLAGS_SHORT)
                  ? (unsigned short int)va_arg(va, unsigned int)
                  : va_arg(va, unsigned int);
          ret_idx += _ntoa_long(out, &buffer, value, false, base, width, flags,
                                begin, max_len);
        }
      }
      format++;
      break;
    }
    case 'c': {
      unsigned int l = 1U;
      if (!(flags & FLAGS_LEFT)) {
        while (l++ < width) {
          buffer = out(buffer, ' ', begin, max_len);
          ret_idx++;
        }
      }
      buffer = out(buffer, (char)va_arg(va, int), begin, max_len);
      ret_idx++;
      if (flags & FLAGS_LEFT) {
        while (l++ < width) {
          buffer = out(buffer, ' ', begin, max_len);
          ret_idx++;
        }
      }
      format++;
      break;
    }

    case 's': {
      const char *p = va_arg(va, char *);
      unsigned int l = _strnlen_s(p, (size_t)-1);
      if (!(flags & FLAGS_LEFT)) {
        while (l++ < width) {
          buffer = out(buffer, ' ', begin, max_len);
          ret_idx++;
        }
      }
      while (*p != 0) {
        buffer = out(buffer, *(p++), begin, max_len);
        ret_idx++;
      }
      if (flags & FLAGS_LEFT) {
        while (l++ < width) {
          buffer = out(buffer, ' ', begin, max_len);
          ret_idx++;
        }
      }
      format++;
      break;
    }

    case 'p': {
      width = sizeof(void *) * 2U;
      flags |= FLAGS_ZEROPAD | FLAGS_UPPERCASE;
      const bool is_ll = sizeof(uintptr_t) == sizeof(long long);
      if (is_ll) {
        ret_idx += _ntoa_long_long(out, &buffer, (uintptr_t)va_arg(va, void *),
                                   false, 16U, width, flags, begin, max_len);
      } else {

        ret_idx += _ntoa_long(out, &buffer,
                              (unsigned long)((uintptr_t)va_arg(va, void *)),
                              false, 16U, width, flags, begin, max_len);
      }

      format++;
      break;
    }

    case '%':
      buffer = out(buffer, '%', begin, max_len);
      ret_idx++;
      format++;
      break;

    default:
      buffer = out(buffer, *format, begin, max_len);
      ret_idx++;
      format++;
      break;
    }
  }
  buffer = out(buffer, '\0', begin, max_len);
  return ret_idx;
}
static char *update_to_str(char *addr, char c, char *const begin,
                           size_t max_len) {
  if (c != '\0' && addr - begin >= max_len)
    return addr;
  *addr = c;
  return addr + 1;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list argp;
  va_start(argp, fmt);
  return __vasprintf(update_to_str, out, fmt, argp, -1);
  va_end(argp);
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  if (n == 0)
    return 0;
  va_list argp;
  va_start(argp, fmt);
  return __vasprintf(update_to_str, out, fmt, argp, n - 1);
  va_end(argp);
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  if (n == 0)
    return 0;
  return __vasprintf(update_to_str, out, fmt, ap, n - 1);
}

static char *update_to_serial(char *addr, char c, char *begin, size_t max_len) {
  putch(c);
  return addr;
}

int printf(const char *fmt, ...) {
  va_list argp;
  va_start(argp, fmt);
  return __vasprintf(update_to_serial, NULL, fmt, argp, -1);

  va_end(argp);
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  return __vasprintf(update_to_str, out, fmt, ap, -1);
}

#endif
