#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  char buf[1024];
  va_list args;
  va_start(args, fmt);
  int len = vsprintf(buf, fmt, args);
  va_end(args);
  for (int i = 0; i < len; i++) {
    putch(buf[i]);
  }
  return len;
}
int vsprintf(char *out, const char *fmt, va_list args) {
  char *p = out;
  const char *f = fmt;
  while (*f) {
    if (*f == '%') {
      f++;
      if (*f == 'd') {
        int val = va_arg(args, int);
        if (val == 0)
          *p++ = '0';
        else {
          if (val < 0) {
            *p++ = '-';
            val = -val;
          }
          char buf[20];
          int len = 0;
          while (val) {
            buf[len++] = '0' + val % 10;
            val /= 10;
          }
          while (len)
            *p++ = buf[--len];
        }
        f++;
      } else if (*f == 'l') {
        f++;
        if (*f == 'd') {
          int val = va_arg(args, long int);
          if (val == 0)
            *p++ = '0';
          else {
            if (val < 0) {
              *p++ = '-';
              val = -val;
            }
            char buf[20];
            int len = 0;
            while (val) {
              buf[len++] = '0' + val % 10;
              val /= 10;
            }
            while (len)
              *p++ = buf[--len];
          }
          f++;
        }
      } else if (*f == 's') {
        const char *s = va_arg(args, const char *);
        while (*s)
          *p++ = *s++;
        f++;
      } else if (*f == 'c') {
        char c = (char)va_arg(args, int);
        *p++ = c;
        f++;
      } else if (*f == '%') {
        *p++ = '%';
        f++;
      }
    } else {
      *p++ = *f++;
    }
  }
  *p = '\0';
  return p - out;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int ret = vsprintf(out, fmt, args);
  va_end(args);
  return ret;
}
int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
