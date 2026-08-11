#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// 安全写入单个字符到缓冲区
static inline void buf_putc(char ch, char *out, size_t n, size_t *idx) {
  if (n > 0 && *idx + 1 < n) {
    out[*idx] = ch;
  }
  (*idx)++;
}

// 安全写入字符串到缓冲区
static inline void buf_puts(const char *s, char *out, size_t n, size_t *idx) {
  if (s == NULL) s = "(null)";
  while (*s) {
    buf_putc(*s++, out, n, idx);
  }
}

// 按任意进制输出无符号整数
static inline void buf_putu_base(unsigned long long val, unsigned base, int upper,
                                 char *out, size_t n, size_t *idx) {
  if (base < 2 || base > 16) return;

  if (val == 0) {
    buf_putc('0', out, n, idx);
    return;
  }

  char tmp[64];
  int t = 0;
  const char *digits = upper ? "0123456789ABCDEF" : "0123456789abcdef";

  while (val > 0) {
    tmp[t++] = digits[val % base];
    val /= base;
  }

  while (t--) {
    buf_putc(tmp[t], out, n, idx);
  }
}

// 输出有符号十进制整数
static inline void buf_puti(long long val, char *out, size_t n, size_t *idx) {
  unsigned long long u;
  if (val < 0) {
    buf_putc('-', out, n, idx);
    u = (unsigned long long)(-(val + 1)) + 1;  // 避免最小负数溢出
  } else {
    u = (unsigned long long)val;
  }
  buf_putu_base(u, 10, 0, out, n, idx);
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  size_t idx = 0;

  if (out == NULL || fmt == NULL) {
    return 0;
  }

  for (const char *p = fmt; *p; p++) {
    if (*p != '%') {
      buf_putc(*p, out, n, &idx);
      continue;
    }

    p++;  // 跳过 '%'
    if (*p == '\0') break;

    // 解析长度修饰符
    // len = 0: 默认
    // len = 1: l
    // len = 2: ll
    int len = 0;
    if (*p == 'l') {
      len = 1;
      p++;
      if (*p == 'l') {
        len = 2;
        p++;
      }
    }

    switch (*p) {
      case '%':
        buf_putc('%', out, n, &idx);
        break;

      case 'c': {
        int ch = va_arg(ap, int);
        buf_putc((char)ch, out, n, &idx);
        break;
      }

      case 's': {
        const char *s = va_arg(ap, const char *);
        buf_puts(s, out, n, &idx);
        break;
      }

      case 'd':
      case 'i': {
        if (len == 2) {
          long long v = va_arg(ap, long long);
          buf_puti(v, out, n, &idx);
        } else if (len == 1) {
          long v = va_arg(ap, long);
          buf_puti((long long)v, out, n, &idx);
        } else {
          int v = va_arg(ap, int);
          buf_puti((long long)v, out, n, &idx);
        }
        break;
      }

      case 'u': {
        if (len == 2) {
          unsigned long long v = va_arg(ap, unsigned long long);
          buf_putu_base(v, 10, 0, out, n, &idx);
        } else if (len == 1) {
          unsigned long v = va_arg(ap, unsigned long);
          buf_putu_base((unsigned long long)v, 10, 0, out, n, &idx);
        } else {
          unsigned int v = va_arg(ap, unsigned int);
          buf_putu_base((unsigned long long)v, 10, 0, out, n, &idx);
        }
        break;
      }

      case 'x': {
        if (len == 2) {
          unsigned long long v = va_arg(ap, unsigned long long);
          buf_putu_base(v, 16, 0, out, n, &idx);
        } else if (len == 1) {
          unsigned long v = va_arg(ap, unsigned long);
          buf_putu_base((unsigned long long)v, 16, 0, out, n, &idx);
        } else {
          unsigned int v = va_arg(ap, unsigned int);
          buf_putu_base((unsigned long long)v, 16, 0, out, n, &idx);
        }
        break;
      }

      case 'X': {
        if (len == 2) {
          unsigned long long v = va_arg(ap, unsigned long long);
          buf_putu_base(v, 16, 1, out, n, &idx);
        } else if (len == 1) {
          unsigned long v = va_arg(ap, unsigned long);
          buf_putu_base((unsigned long long)v, 16, 1, out, n, &idx);
        } else {
          unsigned int v = va_arg(ap, unsigned int);
          buf_putu_base((unsigned long long)v, 16, 1, out, n, &idx);
        }
        break;
      }

      case 'p': {
        uintptr_t v = (uintptr_t)va_arg(ap, void *);
        buf_puts("0x", out, n, &idx);
        buf_putu_base((unsigned long long)v, 16, 0, out, n, &idx);
        break;
      }

      default:
        // 未实现格式：原样输出
        buf_putc('%', out, n, &idx);
        if (len == 1) {
          buf_putc('l', out, n, &idx);
        } else if (len == 2) {
          buf_putc('l', out, n, &idx);
          buf_putc('l', out, n, &idx);
        }
        buf_putc(*p, out, n, &idx);
        break;
    }
  }

  if (n > 0) {
    size_t term = (idx < n) ? idx : (n - 1);
    out[term] = '\0';
  }

  return (int)idx;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  return vsnprintf(out, (size_t)-1, fmt, ap);
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsnprintf(out, n, fmt, ap);
  va_end(ap);
  return ret;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsnprintf(out, (size_t)-1, fmt, ap);
  va_end(ap);
  return ret;
}

int printf(const char *fmt, ...) {
  char buf[1024];
  va_list ap;
  va_start(ap, fmt);
  int len = vsnprintf(buf, sizeof(buf), fmt, ap);
  va_end(ap);

  for (int i = 0; i < len && buf[i] != '\0'; i++) {
    putch(buf[i]);
  }
  return len;
}

#endif