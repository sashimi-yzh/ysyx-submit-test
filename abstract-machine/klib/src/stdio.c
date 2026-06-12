#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

typedef union {
  va_list ap;
} va_list_wrapper;

typedef void (*putchcmd_t)(char, char **);

#define IS_DIGIT(c) ((c) >= '0' && (c) <= '9')

static int putnstrcmd(putchcmd_t put, char **save_ptr, const char *str, int max) {
  int i;
  for (i = 0; max < 0 ? *str : i < max; i++, str++) {
    put(*str, save_ptr);
  }
  return i;
}

static int atoip(const char **s) {
    int i = 0;
    while (IS_DIGIT(**s))
        i = i * 10 + *((*s)++) - '0';
    return i;
}

#define F_ALT   1  // '#'
#define F_ZERO  2  // '0'
#define F_LEFT  4  // '-'
#define F_SPACE 8  // ' '
#define F_PLUS  16 // '+'

static int print_num(putchcmd_t put, char **save_ptr, unsigned long long u, 
                     int base, int width, int flags, int neg) {
  int cnt = 0;
  char prefix[4];
  int prefix_len = 0;
  if (neg) {
    prefix[prefix_len++] = '-';
  } else if (flags & F_PLUS) {
    prefix[prefix_len++] = '+';
  } else if (flags & F_SPACE) {
    prefix[prefix_len++] = ' ';
  }

  if ((flags & F_ALT) && base == 16) {
    prefix[prefix_len++] = '0';
    prefix[prefix_len++] = 'x';
  }

  char tmp[128];
  int i = 0;
  if (u == 0) {
    tmp[i++] = '0';
  } else {
    const char *digits = "0123456789abcdef";
    while (u != 0) {
      int rem = u % base;
      tmp[i++] = digits[rem];
      u /= base;
    }
  }

  int num_len = i;
  int total_len = prefix_len + num_len;
  int padding = width > total_len ? width - total_len : 0;
  cnt += total_len + padding;

  if (!(flags & F_LEFT) && !(flags & F_ZERO)) {
    while (padding-- > 0) {
      put(' ', save_ptr);
    }
  }
  int k;
  for (k = 0; k < prefix_len; k++) {
    put(prefix[k], save_ptr);
  }
  if (!(flags & F_LEFT) && (flags & F_ZERO)) {
    while (padding-- > 0) {
      put('0', save_ptr);
    }
  }
  while (i-- > 0) {
    put(tmp[i], save_ptr);
  }
  if (flags & F_LEFT) {
    while (padding-- > 0) {
      put(' ', save_ptr);
    }
  }

  return cnt;
}

static void parse_arg(const char **fmt, va_list_wrapper *apw, 
                      uint32_t *flags, int *width, int *precision,
                      int *long_mod, char *type) {
  if (**fmt != '%')
    panic("Invalid fmt");
  (*fmt)++; 

  char flags_chars[] = {'#', '0', '-', ' ', '+'};
  while (1) {
    int i;
    for (i = 0; i < sizeof(flags_chars); i++) {
      if (**fmt == flags_chars[i]) {
        *flags |= (1u << i);
        (*fmt)++;
        break;
      }
    }
    if (i == sizeof(flags_chars))
      break;
  }

  if (**fmt == '*') {
    *width = va_arg(apw->ap, int);
    (*fmt)++;
    if (*width < 0) {
      *width = -*width;
      *flags |= F_LEFT;
    }
  } else if (IS_DIGIT(**fmt)) {
    *width = atoip(fmt);
  }

  if (**fmt == '.') {
    (*fmt)++;
    if (**fmt == '*') {
      *precision = va_arg(apw->ap, int);
      (*fmt)++;
    } else if (IS_DIGIT(**fmt)) {
      *precision = atoip(fmt);
    } else {
      *precision = 0;
    }
  }

  int is_mod = 0;
  do {
    is_mod = 0;
    if (**fmt == 'l') {
      (*long_mod)++;
      is_mod = 1;
    }
    if (is_mod)
      (*fmt)++;
  } while (is_mod);

  *type = *(*fmt)++;
}

static int print_arg(putchcmd_t put, char **save_ptr, const char **fmt, va_list_wrapper *apw) {
  int cnt = 0;
  uint32_t flags = 0;
  int width = -1;
  int precision = -1;
  int long_mod = 0;
  char type;

  parse_arg(fmt, apw, &flags, &width, &precision, 
            &long_mod, &type);


  switch (type) {
    case 's': {
      char *str_arg;
      str_arg = va_arg(apw->ap, char *);
      if (str_arg == NULL)
          str_arg = "(null)";
      int len = strlen(str_arg);
      if (precision >= 0 && len > precision)
          len = precision;
      
      int fill_len = width > len ? width - len : 0;
      if (!(flags & F_LEFT)) {
        while (fill_len--) {
          put(' ', save_ptr);
          cnt++;
        }
      }
      cnt += putnstrcmd(put, save_ptr, str_arg, len);
      if (flags & F_LEFT) {
        while (fill_len--) {
          put(' ', save_ptr);
          cnt++;
        }
      }
      break;
    }

    case 'd': {
      long long val;
      if (long_mod == 0) 
        val = va_arg(apw->ap, int);
      else if (long_mod == 1) 
        val = va_arg(apw->ap, long);
      else 
        val = va_arg(apw->ap, long long);
      
      unsigned long long uval = 0;
      int is_neg = 0;
      if (val < 0) {
        is_neg = 1;
        uval = (unsigned long long)(-val);
      } else {
        uval = (unsigned long long)val;
      }
      cnt += print_num(put, save_ptr, uval, 10, width, flags, is_neg);
      break;
    }
    
    case 'x': {
      unsigned long long uval = 0;
      if (long_mod == 0)
        uval = (unsigned int)va_arg(apw->ap, int);
      else if (long_mod == 1)
        uval = (unsigned long)va_arg(apw->ap, long);
      else
        uval = (unsigned long long)va_arg(apw->ap, long long);
      
      cnt += print_num(put, save_ptr, uval, 16, width, flags, 0);
      break;
    }

    case 'u': {
      unsigned long long uval = 0;
      if (long_mod == 0)
        uval = (unsigned int)va_arg(apw->ap, int);
      else if (long_mod == 1)
        uval = (unsigned long)va_arg(apw->ap, long);
      else
        uval = (unsigned long long)va_arg(apw->ap, long long);
      
      cnt += print_num(put, save_ptr, uval, 10, width, flags, 0);
      break;
    }

    case 'p': {
      uintptr_t uval = (uintptr_t)va_arg(apw->ap, void *);
      flags |= F_ALT; 
      cnt += print_num(put, save_ptr, uval, 16, width, flags, 0);
      break;
    }

    case 'c':
      cnt += width > 1 ? width : 1;
      if (!(flags & F_LEFT)) {
        while (width-- > 1) {
          put(' ', save_ptr);
        }
      }
      put((char)va_arg(apw->ap, int), save_ptr);
      break;

    case '%':
      put('%', save_ptr);
      cnt++;
      break;

    default:
      put('%', save_ptr);
      put(type, save_ptr);
      cnt += 2;
      break;
  }

  return cnt;
}

static int vcmdprintf(putchcmd_t put, char **save_ptr, const char *fmt, va_list ap) {
  int cnt = 0;
  va_list_wrapper apw;
  va_copy(apw.ap, ap);
  while (*fmt) {
    if (*fmt == '%') {
      int len = print_arg(put, save_ptr, &fmt, &apw);    
      cnt += len;
    } else {
      put(*fmt++, save_ptr);
      cnt++;
    }
  }
  if (save_ptr != NULL) {
    put('\0', save_ptr);
  }
  return cnt;
}

static void sputchcmd(char c, char **save_ptr) {
  if (save_ptr == NULL) {
    panic("save_ptr is NULL");
  }
  *(*save_ptr)++ = c;
}

static void putchcmd(char c, char **save_ptr) {
  putch(c);
}

int vprintf(const char *fmt, va_list ap) {
  return vcmdprintf(putchcmd, NULL, fmt, ap); 
}

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vprintf(fmt, ap);
  va_end(ap);
  return ret;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  char *save_ptr = out;
  return vcmdprintf(sputchcmd, &save_ptr, fmt, ap); 
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
