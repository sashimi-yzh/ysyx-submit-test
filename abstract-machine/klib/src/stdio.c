#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)


static int print_hex(char *out, unsigned int val, int upper) {
  char buffer[32];
  const char *hex_digits = upper ? "0123456789ABCDEF" : "0123456789abcdef";
  int i = 0;

  if (val == 0) {
    *out = '0';
    return 1;
  }

  while (val > 0) {
    buffer[i++] = hex_digits[val & 0xf];
    val >>= 4;
  }

  int len = i;
  while (i > 0) {
    *out++ = buffer[--i];
  }
  return len;
}

static int print_unsigned(char *out, unsigned int val) {
  char buffer[32]; 
  int i = 0;
  
  if (val == 0) {
    *out = '0';
    return 1;
  }

  while (val > 0) {
    buffer[i++] = (val % 10) + '0';
    val /= 10;
  }

  int len = i;
  while (i > 0) {
    *out++ = buffer[--i];
  }
  return len;
}

static int print_int(char *out, int val) {
  int len = 0;
  
  if (val < 0) {
    *out++ = '-';
    len++;
    unsigned int uval = (unsigned int)(-(val + 1)) + 1;
    len += print_unsigned(out, uval);
  } else {
    len += print_unsigned(out, (unsigned int)val);
  }
  return len;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  char *p = out; 
  
  while (*fmt) {
    if (*fmt != '%') {
      *p++ = *fmt++;
      continue;
    }

    fmt++; 

    switch (*fmt) {
      case 's': {
        const char *s = va_arg(ap, const char *); 
        while (*s) *p++ = *s++;
        break;
      }
      case 'd': {
        int d = va_arg(ap, int); 
        p += print_int(p, d);
        break;
      }
      case 'u': {
        int d = va_arg(ap, int);
        p += print_unsigned(p, d);
        break;
      }
      case 'x': {
        unsigned int x = va_arg(ap, unsigned int);
        p += print_hex(p, x, 0);
        break;
      }
      case 'X': {
        unsigned int x = va_arg(ap, unsigned int);
        p += print_hex(p, x, 1);
        break;
      }
      case 'c': {
        char d = (char)va_arg(ap, int); // 使用 ap
        *p = d;
        p++;
        break;
      }
      case '%':
        *p++ = '%';
        break;
      default:
        *p++ = '%';
        if (*fmt) *p++ = *fmt; 
        break;
    }
    if (*fmt) fmt++; 
  }
  *p = '\0';
  return p - out; 
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int len = vsprintf(out, fmt, ap);
  va_end(ap);
  return len;
}

int printf(const char *fmt, ...) {
  char out[1024];
  va_list ap;
  va_start(ap, fmt);
  int len = vsprintf(out, fmt, ap); 
  va_end(ap);
  
  for(int i = 0; i < len; i++) {
    putch(out[i]); 
  }

  return len; 
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
