#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

#define ABS(x) ((x) < 0 ? -(x) : (x))

static void write_char(char **p, char c) {
  if (*p) *(*p)++ = c;
  else putch(c);
}

static void reverse(char *s, size_t n) {
  char t;
  for (int i = 0; i < (n >> 1); ++i) {
    t = s[i];
    s[i] = s[n - i - 1];
    s[n - i - 1] = t;
  }
}

static int vtnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  size_t t = 0;
  char buf[25];
  buf[0] = '-';
  while (*fmt && t < n - 1) {
    if (*fmt != '%') {
      write_char(&out, *fmt++);
      ++t;
      continue;
    }
    ++fmt;
    // ----- flags -----
    // 0~1+ chars
    char pad = ' ';
    int justify = 0; // 0 for right, 1 for left
    while (1) {
      switch (*fmt) {
        case '0':
          pad = '0';
          ++fmt;
          continue;
        case '-':
          justify = 1;
          ++fmt;
          continue;
        default: ;
      }
      break;
    }
    // ----- field width -----
    // unsigned int (without leading zero) or * (not implemented yet)
    int field_width = 0; // 0 for unset
    if ('1' <= *fmt && *fmt <= '9') {
      field_width = (*fmt++) - '0';
      while ('0' <= *fmt && *fmt <= '9') {
        field_width *= 10;
        field_width += (*fmt++) - '0';
      }
    } else if (*fmt == '*') {
      field_width = va_arg(ap, int);
      panic(fmt);
    }

    // ----- precision -----

    // ----- length modifier -----
    int int_length = 0; // 0 for unset, 3 for l, 4 for ll
    switch (*fmt) {
      case 'l':
        ++fmt;
        if (*fmt == 'l') {
          ++fmt;
          int_length = 4; // ll
        } else {
          int_length = 3;
        }
        break;
      default: ;
    }

    // ----- flag override -----
    if (justify && pad == '0') pad = ' ';

    // ----- conversion specifier -----
    char *res, *p;
    int64_t x;
    uint64_t ux;
    switch (*fmt) {
      case '%':
        res = buf + 1;
        res[0] = '%';
        res[1] = '\0';
        break;
      case 'c':
        res = buf + 1;
        res[0] = va_arg(ap, int);
        res[1] = '\0';
        break;
      case 's':
        res = va_arg(ap, char *);
        break;
      case 'd':
        switch (int_length) {
          case 0: x = va_arg(ap, int); break;
          case 3: x = va_arg(ap, long); break;
          case 4: x = va_arg(ap, long long); break;
          default: panic("not implemented"); break;
        }
        p = buf + 1;
        res = x < 0 ? buf : buf + 1; // '-'
        if (x == 0) {
          *p++ = '0';
          *p = '\0';
        } else {
          while (x) {
            *p++ = '0' + ABS(x % 10);
            x /= 10;
          }
          *p = '\0';
          reverse(buf + 1, p - buf - 1);
        }
        break;
      case 'u':
      case 'x':
      case 'p': // TEMP: 32 bit pointer
        switch (int_length) {
          case 0: ux = va_arg(ap, unsigned int); break;
          case 3: ux = va_arg(ap, unsigned long); break;
          case 4: ux = va_arg(ap, unsigned long long); break;
          default: panic("not implemented"); break;
        }
        int base = *fmt == 'u' ? 10 : 16;
        p = buf + 1;
        res = p;
        if (ux == 0) {
          *p++ = '0';
          *p = '\0';
        } else {
          while (ux) {
            int dig = ux % base;
            *p++ = (dig < 10 ? '0' : 'a' - 10) + dig;
            ux /= base;
          }
          *p = '\0';
          reverse(buf + 1, p - buf - 1);
        }
        if (*fmt == 'p') {
          write_char(&out, '0');
          write_char(&out, 'x');
          pad = '0';
          field_width = 8;
        }
        break;
      default:
        panic(fmt);
        break;
    }
    ++fmt;
    // ----- write result -----
    int res_len = strlen(res);
    // justify right
    if (justify == 0 && field_width > res_len) {
      int i = field_width - res_len;
      while (t < n - 1 && i--) {
        write_char(&out, pad); ++t;
      }
    }
    while (*res && t < n - 1) write_char(&out, *res++), ++t;
    // justify left
    if (justify == 1 && field_width > res_len) {
      int i = field_width - res_len;
      while (t < n - 1 && i--) {
        write_char(&out, pad); ++t;
      }
    }
  }
  write_char(&out, '\0');
  return t;
}

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int t = vtnprintf(NULL, -1, fmt, ap);
  va_end(ap);
  return t;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  return vsnprintf(out, -1, fmt, ap);
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int t = vsprintf(out, fmt, ap);
  va_end(ap);
  return t;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int t = vsnprintf(out, n, fmt, ap);
  va_end(ap);
  return t;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  return vtnprintf(out, n, fmt, ap);
}

#endif
