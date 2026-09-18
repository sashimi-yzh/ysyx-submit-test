#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static char *i2a(int n, char *s, int base) {
  static char digits[] = "0123456789abcdef";
  char buf[32];
  int i = 0;
  unsigned int num = (n < 0 && base == 10) ? -n : (unsigned int)n;

  if (n == 0) buf[i++] = '0';
  while (num > 0) {
      buf[i++] = digits[num % base];
      num /= base;
  }
  if (n < 0 && base == 10) buf[i++] = '-';

  while (i > 0) {
      *s++ = buf[--i];
  }
  return s;
}

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  uint32_t count = 0;
 
  for (const char *f = fmt; *f != '\0'; f ++) {
    if (*f != '%') putch(*f);

    else {
      f ++;
      int w = 0;
      char pad = ' ';

      if (*f == '0') {
	pad = '0';
	f ++;
      }

      while (*f >= '0' && *f <= '9') {
	w = w * 10 + (*f - '0');
	f ++;
      }

      switch(*f) {

        case 's': {
	  char *s = va_arg(ap, char *);
          if (s == NULL) s = "(null)";
	  while(*s != '\0') {
	    putch(*s++);
	    count ++;
	  }
	  break;
	}
	
	case 'd': {
	  int n = va_arg(ap, int);
	  char i[64];
	  char *p = i2a(n, i, 10);
	  *p = '\0';

	  int len = p - i;
	  while (len < w) {
	    putch(pad);
	    len ++;
	  }

	  for (int k = 0; i[k] != '\0'; k++) {
	    putch(i[k]);
	    count ++;
	  }
	  break;
	}

  case 'x': {
    unsigned int n = va_arg(ap, unsigned int);
    char i[64];
    char *p = i2a(n, i, 16);
    *p = '\0';

    int len = p - i;
    while (len < w) {
      putch(pad);
      len ++;
    }

    for (int k = 0; i[k] != '\0'; k++) {
      putch(i[k]);
      count ++;
    }
    break;
  }

  case 'c': {
    char c = (char)va_arg(ap, int);
    putch(c);
    count ++;
    break;
  }

  case 'p': {
    unsigned int n = va_arg(ap, unsigned int);
    char i[64];
    char *p = i2a(n, i, 16);
    *p = '\0';

    int len = p - i;
    while (len < w) {
      putch(pad);
      len ++;
    }

    for (int k = 0; i[k] != '\0'; k++) {
      putch(i[k]);
      count ++;
    }
    break;
  }

  case '%': {
 	  putch('%');
	  count ++;
	  break;
	}

        default: putch('%'); putch(*f); count ++;
      }
    }
    count ++; 
  }

  va_end(ap);
  return count;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("no\n");
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  char *p = out;

  for (const char *f = fmt; *f != '\0'; f++) {
      if (*f != '%') {
          *p++ = *f;
          continue;
      }

      f++;
      switch (*f) {
          case 's': {
              char *s = va_arg(ap, char *);
              while (*s) *p++ = *s++;
              break;
          }
          case 'd': {
              int n = va_arg(ap, int);
              p = i2a(n, p, 10);
              break;
          }
          case 'x':
          case 'p': {
              unsigned int n = va_arg(ap, unsigned int);
              p = i2a(n, p, 16);
              break;
          }
          case '%': {
              *p++ = '%';
              break;
          }
          default:
              *p++ = *f;
              break;
      }
  }

  *p = '\0';
  va_end(ap);
  return (p - out);
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("no\n");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("no\n");
}

#endif
