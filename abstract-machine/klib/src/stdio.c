#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static char buff[256];

static int num2str(char *out, uint64_t num, bool is_sign, int width,
                   bool fill_zero, int radix) {
  char *tmp = out;
  if (is_sign && (int64_t)num < 0) {
    *out++ = '-';
    num = ~num + 1;
  }
  char num_buff[20];
  int index = 0;
  do {
    if (radix == 0) { // dec
      num_buff[index++] = num % 10 + '0';
      num /= 10;
    } else if (radix == 1) { // hex
      char c = num % 16;
      if (c >= 10) {
        c = c - 10 + 'a';
      } else {
        c += '0';
      }
      num_buff[index++] = c;
      num /= 16;
    }
  } while (num != 0);

  // fill 0
  while (width-- > index) {
    *out++ = fill_zero ? '0' : ' ';
  }
  while (index > 0) {
    *out++ = num_buff[--index];
  }
  return out - tmp;
}

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  char *tmp = buff;
  int len = vsprintf(buff, fmt, ap);
  va_end(ap);
  while (*tmp) {
    putch(*tmp++);
  }
  return len;
}

enum { FLAG_LONG = 1, FLAG_LONG_LONG };

int vsprintf(char *out, const char *fmt, va_list ap) {
  char *tmp = out;
  int flag = 0;
  while (*fmt) {
    int width = 0;
    bool fill_zero = false;
    if (*fmt == '%') {
      switch (*++fmt) {
      case 'l':
        if (*++fmt == 'l') {
          flag = FLAG_LONG_LONG;
          fmt++;
        } else {
          flag = FLAG_LONG;
        }
        break;
      case '0':
        fill_zero = true;
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9': {
        width = *fmt - '0';
        char ch = *++fmt;
        while (ch >= '0' && ch <= '9') {
          width = width * 10 + ch - '0';
          ch = *++fmt;
        }
        break;
      }
      default:
        break;
      }
      switch (*fmt++) {
      case 'c':
        *out++ = (char)va_arg(ap, int);
        break;
      case 's': {
        char *s = va_arg(ap, char *);
        while (*s) {
          *out++ = *s++;
        }
        break;
      }
      // TODO: va_arg use long or long long sometimes could lead to UB when the
      // arg is int
      case 'd': {
        int64_t num;
        if (flag == FLAG_LONG) {
          num = va_arg(ap, long);
        } else if (flag == FLAG_LONG_LONG) {
          num = va_arg(ap, long long);
        } else {
          num = va_arg(ap, int);
        }
        int len = num2str(out, num, true, width, fill_zero, 0);
        out += len;
        break;
      }
      case 'x': {
        uint64_t num;
        if (flag == FLAG_LONG) {
          num = va_arg(ap, unsigned long);
        } else if (flag == FLAG_LONG_LONG) {
          num = va_arg(ap, unsigned long long);
        } else {
          num = va_arg(ap, unsigned int);
        }
        int len = num2str(out, num, false, width, fill_zero, 1);
        out += len;
        break;
      }
      case 'p': {
        uintptr_t p = (uintptr_t)va_arg(ap, void *);
        *out++ = '0';
        *out++ = 'x';
        int real_width =
            sizeof(uintptr_t) * 2 > width ? sizeof(uintptr_t) * 2 : width;
        int len = num2str(out, p, false, real_width, fill_zero, 1);
        out += len;
        break;
      }
      default:
        assert(0); // unsupport
      }
    } else {
      *out++ = *fmt++;
    }
  }
  *out = '\0';
  return out - tmp + 1;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int len = vsprintf(out, fmt, ap);
  va_end(ap);
  return len;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int len = vsnprintf(out, n, fmt, ap);
  va_end(ap);
  return len;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  int len = vsprintf(buff, fmt, ap);
  if (len <= n) {
    strcpy(out, buff);
    return len;
  }
  strncpy(out, buff, n);
  return n;
}

#endif
