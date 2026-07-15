#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static int print_num(unsigned long x, int base, int width, int pad_zero, int is_signed, int neg) {
  char buf[32];
  char *p = buf + sizeof(buf);
  int cnt = 0;

  // 转换数字（倒序）
  do {
    int d = x % (unsigned long)base;
    *--p = (d < 10) ? ('0' + d) : ('a' + d - 10);
    x /= (unsigned long)base;
  } while (x);

  int len = buf + sizeof(buf) - p;

  // 负号算长度
  if (neg) len++;

  // 填充
  char pad = pad_zero ? '0' : ' ';
  while (len < width) {
    putch(pad);
    cnt++;
    width--;
  }

  // 输出负号
  if (neg) {
    putch('-');
    cnt++;
  }

  // 输出数字
  while (p < buf + sizeof(buf)) {
    putch(*p++);
    cnt++;
  }

  return cnt;
}

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);

  int count = 0;

  for (; *fmt; fmt++) {
    if (*fmt != '%') {
      putch(*fmt);
      count++;
      continue;
    }

    fmt++;  // skip '%'

    // ---------- 解析格式 ----------
    int pad_zero = 0;
    int width = 0;

    // 处理 0 填充
    if (*fmt == '0') {
      pad_zero = 1;
      fmt++;
    }

    // 处理宽度
    while (*fmt >= '0' && *fmt <= '9') {
      width = width * 10 + (*fmt - '0');
      fmt++;
    }

    int long_flag = 0;
    if (*fmt == 'l') {
      long_flag = 1;
      fmt++;
    }

    // ---------- 处理类型 ----------
    if (*fmt == 'd') {
      unsigned long ux;
      int neg = 0;

      if (long_flag) {
        long x = va_arg(ap, long);
        if (x < 0) {
          neg = 1;
          ux = 0 - (unsigned long)x;
        } else {
          ux = (unsigned long)x;
        }
      } else {
        int x = va_arg(ap, int);
        if (x < 0) {
          neg = 1;
          ux = 0 - (unsigned int)x;
        } else {
          ux = (unsigned int)x;
        }
      }

      count += print_num(ux, 10, width, pad_zero, 1, neg);
    }

    else if (*fmt == 'u') {
      unsigned long x = long_flag ? va_arg(ap, unsigned long) : va_arg(ap, unsigned int);
      count += print_num(x, 10, width, pad_zero, 0, 0);
    }

    else if (*fmt == 'x') {
      unsigned long x = long_flag ? va_arg(ap, unsigned long) : va_arg(ap, unsigned int);
      count += print_num(x, 16, width, pad_zero, 0, 0);
    }

    else if (*fmt == 's') {
      const char *s = va_arg(ap, const char *);
      if (!s) s = "(null)";

      int len = 0;
      const char *t = s;
      while (*t++) len++;

      // padding
      while (len < width) {
        putch(' ');
        count++;
        width--;
      }

      while (*s) {
        putch(*s++);
        count++;
      }
    }

    else if (*fmt == 'c') {
      char c = (char)va_arg(ap, int);
      putch(c);
      count++;
    }

    else if (*fmt == '%') {
      putch('%');
      count++;
    }

    else {
      // 不支持的格式
      putstr("Unsupported format: %");
      putch(*fmt);
      assert(0);
      count++;
    }
  }

  va_end(ap);
  return count;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);

  char *p = out;
  for( ; *fmt != '\0'; fmt++) {
    if (*fmt != '%') {
      *p++ = *fmt;
      continue;
    }
    fmt++;

    int long_flag = 0;
    if (*fmt == 'l') {
      long_flag = 1;
      fmt++;
    }

    if (*fmt == 'd') {
      unsigned long x;

      if (long_flag) {
        long v = va_arg(ap, long);
        if (v < 0) {
          *p++ = '-';
          x = 0 - (unsigned long)v;
        } else {
          x = (unsigned long)v;
        }
      } else {
        int v = va_arg(ap, int);
        if (v < 0) {
          *p++ = '-';
          x = 0 - (unsigned int)v;
        } else {
          x = (unsigned int)v;
        }
      }

      char buf[32];
      char *q = buf + sizeof(buf);
      do {
        *--q = '0' + x % 10;
        x /= 10;
      } while (x > 0);
      while (q < buf + sizeof(buf)) {
        *p++ = *q++;
      }
    }
    else if (*fmt == 's') {
      const char *s = va_arg(ap, const char *);
      while (*s != '\0') {
        *p++ = *s++;
      }
    }
    else {
      panic("unsupported format");
    }
  }

  *p = '\0';
  return p - out;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
