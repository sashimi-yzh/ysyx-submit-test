#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stdbool.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// Helper function to convert integer to string
static void itoa(int value, char *str, int base, bool is_unsigned) {
  char *p = str;
  char buffer[32];
  int pos = 0;

  if (value == 0) {
    *p++ = '0';
  }

  if (value < 0 && !is_unsigned) {
    *p++ = '-';
    value = -value;
  }

  while (value > 0) {
    int digit = value % base;
    buffer[pos++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
    value /= base;
  }

  for (int i = pos - 1; i >= 0; i--) {
    *p++ = buffer[i];
  }

  *p = '\0';
}

static int vsprintf_internal(char *out, size_t n, const char *fmt, va_list ap) {
  const char *p = fmt;
  char *out_start = out;
  size_t remaining = n;

  while (*p) {
    if (*p == '%') {
      p++;
      if (*p == '\0') break;

      int width = 0;
      while (*p >= '0' && *p <= '9') {
        width = width * 10 + (*p - '0');
        p++;
      }

      switch (*p) {
        case 'd': {
          int value = va_arg(ap, int);
          char buffer[32];
          itoa(value, buffer, 10, false);
          int len = strlen(buffer);
          int padding = (width > len) ? width - len : 0;
          while (padding-- > 0 && remaining > 1) {
            *out++ = ' ';
            remaining--;
          }
          if (remaining > len) {
            strcpy(out, buffer);
            out += len;
            remaining -= len;
          }
          break;
        }
        case 'x': {
          int value = va_arg(ap, int);
          char buffer[32];
          itoa(value, buffer, 16, true);
          int len = strlen(buffer);
          int padding = (width > len) ? width - len : 0;
          while (padding-- > 0 && remaining > 1) {
            *out++ = ' ';
            remaining--;
          }
          if (remaining > len) {
            strcpy(out, buffer);
            out += len;
            remaining -= len;
          }
          break;
        }
        case 'u': {
          unsigned int value = va_arg(ap, unsigned int);
          char buffer[32];
          itoa(value, buffer, 10, true);
          int len = strlen(buffer);
          int padding = (width > len) ? width - len : 0;
          while (padding-- > 0 && remaining > 1) {
            *out++ = ' ';
            remaining--;
          }
          if (remaining > len) {
            strcpy(out, buffer);
            out += len;
            remaining -= len;
          }
          break;
        }
        case 's': {
          const char *str = va_arg(ap, const char *);
          int len = strlen(str);
          int padding = (width > len) ? width - len : 0;
          while (padding-- > 0 && remaining > 1) {
            *out++ = ' ';
            remaining--;
          }
          if (remaining > len) {
            strcpy(out, str);
            out += len;
            remaining -= len;
          }
          break;
        }
        case 'c': {
          char c = (char)va_arg(ap, int);
          int padding = (width > 1) ? width - 1 : 0;
          while (padding-- > 0 && remaining > 1) {
            *out++ = ' ';
            remaining--;
          }
          if (remaining > 1) {
            *out++ = c;
            remaining--;
          }
          break;
        }
        default:
          if (remaining > 1) {
            *out++ = *p;
            remaining--;
          }
          break;
      }
    }
    else {
      if (remaining > 1) {
        *out++ = *p;
        remaining--;
      }
    }
    p++;
  }

  if (remaining > 0) {
    *out = '\0';
  }

  return out - out_start;
}











int printf(const char *fmt, ...) {
  char buffer[1024];
  va_list args;
  va_start(args, fmt);
  int ret = vsprintf_internal(buffer, sizeof(buffer), fmt, args);
  va_end(args);
  putstr(buffer);
  return ret;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  return vsprintf_internal(out, (size_t)-1, fmt, ap);
}

int sprintf(char *out, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int ret = vsprintf(out, fmt, args);
  va_end(args);
  return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int ret = vsprintf_internal(out, n, fmt, args);
  va_end(args);
  return ret;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  return vsprintf_internal(out, n, fmt, ap);
}

#endif