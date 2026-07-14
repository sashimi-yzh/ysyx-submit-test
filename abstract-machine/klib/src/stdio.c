#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  //panic("Not implemented");
  char buf[1024];
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(buf, fmt, ap);
  va_end(ap);
  for (char *i = buf; *i; i++) {
    putch(*i);
  }
  return ret;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  char *ptr = out;
  while (*fmt) {
    if (*fmt != '%') {
      *ptr++ = *fmt++;
      continue;
    }
    fmt++;

    int zero_pad = 0;
    int width = 0;

    if (*fmt == '0') {          
      zero_pad = 1;
      fmt++;
    }
    while (*fmt >= '0' && *fmt <= '9') {  
      width = width * 10 + (*fmt - '0');
      fmt++;
    }


    switch (*fmt++)
    {
    case 's': {
      char *str = va_arg(ap, char *);
      while (*str) {
        *ptr++ = *str++;
      }
      break;
    }
    case 'd':case 'i': {
      long long num = (long long)va_arg(ap, int);
      if (num < 0) {
        *ptr++ = '-';
        num = -num;
      }
      char buf[21];
      int i = 0;
      do {
        buf[i++] = num % 10 + '0';
        num /= 10;
      } while (num);

      while (i < width) {
        buf[i++] = zero_pad ? '0' : ' ';
      }
      while (i--) {
        *ptr++ = buf[i];
      }
      break;
    }
    case 'c':{
      char ch = (char)va_arg(ap, int);
      *ptr++ = ch;
      break;
    }
    case 'x':case 'X': {
      unsigned int num = va_arg(ap, unsigned int);
      int is_upper = (*fmt == 'X');

      char buf[9];
      int i = 0;
      if (num == 0) {
        buf[i++] = '0';
      } else {
        while (num) {
          int hex_digit = num & 0xF;  
          if (hex_digit < 10) {
            buf[i++] = hex_digit + '0';
          } else {
            buf[i++] = hex_digit - 10 + (is_upper ? 'A' : 'a');
          }
          num >>= 4;  
        }
      }
      
      while (i < width) {
        buf[i++] = zero_pad ? '0' : ' ';
      }
      
      while (i--) {
        *ptr++ = buf[i];
      }
      break;
    }
    default:
      break;
    }
  }
  *ptr = '\0';
  return ptr - out;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(out, fmt, ap);
  va_end(ap);
  return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
