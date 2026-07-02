#include <am.h>
#include <klib.h>
#include <stdarg.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  char buf[1024];
  int ret = vsnprintf(buf, sizeof(buf), fmt, ap);
  va_end(ap);
  for (char *p = buf; *p; p++) putch(*p);
  return ret;
}

int vsprintf(char *restrict s, const char *restrict fmt, va_list ap) {
  return vsnprintf(s, INT_MAX, fmt, ap);
}

int sprintf(char *restrict s, const char *restrict fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(s, fmt, ap);
  va_end(ap);
  return ret;
}

int snprintf(char *restrict s, size_t n, const char *restrict fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsnprintf(s, n, fmt, ap);
  va_end(ap);
  return ret;
}

static void append_char(char *out, size_t n, size_t *len, char ch) {
  if (out != NULL && *len + 1 < n) {
    out[*len] = ch;
  }
  (*len)++;
}

static void append_repeat(char *out, size_t n, size_t *len, char ch, int count) {
  for (int i = 0; i < count; i++) {
    append_char(out, n, len, ch);
  }
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  size_t len = 0;

  for (const char *p = fmt; *p; p++) {
    if (*p != '%') {
      append_char(out, n, &len, *p);
      continue;
    }

    p++;
    if (*p == '\0') break;

    int left_align = 0;
    int zero_pad = 0;
    int width = 0;
    int long_level = 0;

    while (*p == '-' || *p == '0') {
      if (*p == '-') left_align = 1;
      if (*p == '0') zero_pad = 1;
      p++;
    }
    if (left_align) zero_pad = 0;

    while (*p >= '0' && *p <= '9') {
      width = width * 10 + (*p - '0');
      p++;
    }

    if (*p == '.') {
      p++;
      while (*p >= '0' && *p <= '9') p++;
    }

    while (*p == 'l') {
      long_level++;
      p++;
    }

    char spec = *p;
    if (spec == '\0') break;

    if (spec == '%') {
      append_char(out, n, &len, '%');
      continue;
    }

    if (spec == 'c') {
      char ch = (char)va_arg(ap, int);
      if (!left_align) append_repeat(out, n, &len, ' ', width > 1 ? width - 1 : 0);
      append_char(out, n, &len, ch);
      if (left_align) append_repeat(out, n, &len, ' ', width > 1 ? width - 1 : 0);
      continue;
    }

    if (spec == 's') {
      const char *s = va_arg(ap, const char *);
      if (s == NULL) s = "(null)";
      int slen = (int)strlen(s);
      if (!left_align) append_repeat(out, n, &len, ' ', width > slen ? width - slen : 0);
      for (int i = 0; i < slen; i++) append_char(out, n, &len, s[i]);
      if (left_align) append_repeat(out, n, &len, ' ', width > slen ? width - slen : 0);
      continue;
    }

    char numbuf[64];
    int ndig = 0;
    int base = 10;
    int upper = 0;
    char sign = 0;
    const char *prefix = "";
    unsigned long long u = 0;

    if (spec == 'd' || spec == 'i') {
      long long v;
      if (long_level >= 2) v = va_arg(ap, long long);
      else if (long_level == 1) v = va_arg(ap, long);
      else v = va_arg(ap, int);
      if (v < 0) {
        sign = '-';
        u = (unsigned long long)(-(v + 1)) + 1;
      } else {
        u = (unsigned long long)v;
      }
    } else if (spec == 'u') {
      if (long_level >= 2) u = va_arg(ap, unsigned long long);
      else if (long_level == 1) u = va_arg(ap, unsigned long);
      else u = va_arg(ap, unsigned int);
    } else if (spec == 'x' || spec == 'X') {
      if (long_level >= 2) u = va_arg(ap, unsigned long long);
      else if (long_level == 1) u = va_arg(ap, unsigned long);
      else u = va_arg(ap, unsigned int);
      base = 16;
      upper = (spec == 'X');
    } else if (spec == 'p') {
      u = (uintptr_t)va_arg(ap, void *);
      base = 16;
      prefix = "0x";
    } else {
      append_char(out, n, &len, '%');
      append_char(out, n, &len, spec);
      continue;
    }

    if (u == 0) {
      numbuf[ndig++] = '0';
    } else {
      while (u > 0) {
        int d = (int)(u % (unsigned)base);
        if (d < 10) numbuf[ndig++] = (char)('0' + d);
        else numbuf[ndig++] = (char)((upper ? 'A' : 'a') + d - 10);
        u /= (unsigned)base;
      }
    }

    int prefix_len = prefix[0] ? 2 : 0;
    int body_len = ndig + prefix_len + (sign ? 1 : 0);
    int pad_len = width > body_len ? width - body_len : 0;

    if (!left_align && !zero_pad) append_repeat(out, n, &len, ' ', pad_len);
    if (sign) append_char(out, n, &len, sign);
    for (int i = 0; i < prefix_len; i++) append_char(out, n, &len, prefix[i]);
    if (!left_align && zero_pad) append_repeat(out, n, &len, '0', pad_len);
    for (int i = ndig - 1; i >= 0; i--) append_char(out, n, &len, numbuf[i]);
    if (left_align) append_repeat(out, n, &len, ' ', pad_len);
  }

  if (n > 0 && out != NULL) out[len < n ? len : n - 1] = '\0';

  return (int)len;
}

#endif
