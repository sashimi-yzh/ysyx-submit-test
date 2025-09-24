#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int itou(uint64_t u, char *s) {
  int n = 0;
  int i = 0;
  char temp[32] = {};

  do{
    temp[i++] = '0' + u % 10;
    u /= 10;
  }while (u != 0);
  for (i = i - 1; i >= 0; i--) {
    *s++ = temp[i];
    n++;
  }
  return n;
}
int itod(int d, char *s) {
  int n = 0;
  int i = 0;
  long long dd = (long long)d;
  char temp[14] = {};

  if (dd < 0) {
    *s++ = '-';
    n++;
    dd = -dd;
  }
  do{
    temp[i++] = '0' + dd % 10;
    dd /= 10;
  }while (dd != 0);
  for (i = i - 1; i >= 0; i--) {
    *s++ = temp[i];
    n++;
  }
  return n;
}

int itox(unsigned int x, char *s) {
  int n = 0;
  int i = 0;
  char temp[10] = {};

  while (x != 0) {
    int n = x % 16;
    if (n < 10) temp[i++] = '0' + n;
    else temp[i++] = 'a' + n - 10;
    x /= 16;
  }
  for (i = i - 1; i >= 0; i--) {
    *s++ = temp[i];
    n++;
  }
  return n;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  int n = 0;
  int d = 0;
  char *s;
  unsigned int x;
  uint64_t u;

  while (*fmt) {
    if (*fmt == '%') {
      fmt++;
      int num = 0;
      switch (*fmt++) {
        case 'd':
          d = va_arg(ap, int);
          num = itod(d, out);
          n += num;
          out += num;
          break;
        case 's':
          s = va_arg(ap, char *);
          while (*s) {
            *out++ = *s++;
            n++;
          }
          break;
        case 'x':
          x = va_arg(ap, unsigned int);
          num = itox(x, out);
          n += num;
          out += num;
          break;
        case 'u':
          u = va_arg(ap, int);
          num = itou(u, out);
          n += num;
          out += num;
          break;
      }
    } else {
      *out++ = *fmt++;
      n++;
    }
  }
  *out = '\0';
  return n;
}

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  char out[256] = {};

  int n = vsprintf(out, fmt, ap);
  putstr(out);

  va_end(ap);
  return n;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);

  int n = vsprintf(out, fmt, ap);

  va_end(ap);
  return n;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
