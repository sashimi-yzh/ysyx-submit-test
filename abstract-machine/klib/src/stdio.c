#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)


void reverse(char *str, int length)
{
  int start = 0;
  int end = length - 1;

  while (start < end)
  {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

static char *sky_itoa(uint32_t num, char *str, int base)
{
  int i = 0;
  int isNegative = 0;

  
  if (num == 0)
  {
    str[i] = '\0';
    return str;
  }
  
  if (num < 0 && base == 10)
  {
    isNegative = 1;
    num = -num;
  }
  uint32_t remainder;
 
  while (num != 0)
  {
    remainder = num % base;
    str[i++] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
    num = num / base;
  }

  
  if (isNegative)
    str[i++] = '-';

  str[i] = '\0'; 


  reverse(str, i);

  return str;
}



int printf(const char *fmt, ...) {
  int i=0;
  const char *s;
  char buf[17];
  int d,x;
  va_list ap;
  va_start(ap, fmt);
  while(*fmt){
    if (*fmt == '%')
    {
      switch (*++fmt)
      {
      case 'x':
        x = va_arg(ap, int);
        sky_itoa(x, buf, 16);
        for (s = buf; *s; s++)
        {
          putch(*s);
        }
        fmt++;
        break;
      case 's':
        s = va_arg(ap, const char *); 
        for (; *s; s++)
        {
          putch(*s);
        }
        fmt++;
        break;
      case 'c':
        char q = va_arg(ap, int); 
        putch(q);
        fmt++;
        break;
      case 'd':
        d = va_arg(ap, int);
        sky_itoa(d, buf, 10);
        for (s = buf; *s; s++)
        {
          putch(*s);
        }
        fmt++;
        break;
      }
    }
    else
    {
      putch(*fmt);
      fmt++;
    }
    i++;
  }
  
  return i;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *str,const char *fmt, ...) {
    
    memset(str, 0, sizeof(str));
    const char *s;
    char buf[17];
    int d, x;
    va_list ap;
    int i = 0;
    va_start(ap, fmt);

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            switch (*fmt) {
            case 'x':
                x = va_arg(ap, int);
                sky_itoa(x, buf, 16);
                for (s = buf; *s ; s++) {
                    str[i++] = *s;
                }
                break;
            case 's':
                s = va_arg(ap, const char *);
                for (; *s ; s++) {
                    str[i++] = *s;
                }
                break;
            case 'c':
                str[i++] = va_arg(ap, int);
                break;
            case 'd':
                d = va_arg(ap, int);
                sky_itoa(d, buf, 10);
                for (s = buf; *s ; s++) {
                    str[i++] = *s;
                }
                break;
            }
        } else {
            str[i++] = *fmt;
        }
        fmt++;
    }

    str[i] = '\0';  // Ensure null-termination
    va_end(ap);

    return i;  // Return the number of characters written
}


int snprintf(char *str, size_t size, const char *fmt, ...) {
    if (size == 0) {
        return 0;
    }

    memset(str, 0, size);
    const char *s;
    char buf[17];
    int d, x;
    va_list ap;
    int i = 0;
    va_start(ap, fmt);

    while (*fmt && i < size - 1) {
        if (*fmt == '%') {
            fmt++;
            switch (*fmt) {
            case 'x':
                x = va_arg(ap, int);
                sky_itoa(x, buf, 16);
                for (s = buf; *s && i < size - 1; s++) {
                    str[i++] = *s;
                }
                break;
            case 's':
                s = va_arg(ap, const char *);
                for (; *s && i < size - 1; s++) {
                    str[i++] = *s;
                }
                break;
            case 'c':
                str[i++] = va_arg(ap, int);
                break;
            case 'd':
                d = va_arg(ap, int);
                sky_itoa(d, buf, 10);
                for (s = buf; *s && i < size - 1; s++) {
                    str[i++] = *s;
                }
                break;
            }
        } else {
            str[i++] = *fmt;
        }
        fmt++;
    }

    str[i] = '\0';  // Ensure null-termination
    va_end(ap);

    return i;  // Return the number of characters written
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
