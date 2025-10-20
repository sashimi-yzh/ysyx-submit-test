#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int count = 0;

  for (; *fmt; fmt++) {
    if (*fmt == '%') {
      fmt++;
      int width = 0;
      char pad = ' ';

      if (*fmt == '0') {
        pad = '0';
        fmt++;
      }
      while (*fmt >= '0' && *fmt <= '9') {
        width = width * 10 + (*fmt - '0');
        fmt++;
      }

      switch (*fmt) {
        case 'd': {
          int num = va_arg(args, int);
          int len = 0;
          char buffer[128];
          int i = 0;
          
          if (num < 0) {
            putch('-');
            num = -num;
            count++;
          }
          if (num == 0) buffer[i++] = '0';
          else {
            while (num > 0) {
              buffer[i++] = num % 10 + '0';
              num /= 10;
            }
          }
          len = i;
          while (len < width) {
            putch(pad);
            count++;
            len++;
          }
          while (i > 0) {
            putch(buffer[--i]);
            count++;
          }
          break;
        }
        case 'x': {
          unsigned int num = va_arg(args, unsigned int);
          int len = 0;
          char buffer[128];
          int i = 0;
          if (num == 0) buffer[i++] = '0';
          else {
            while (num > 0) {
              int digit = num % 16;
              buffer[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
              num /= 16;
            }
          }
          len = i;
          if (width == 0) width = 8;
          while (len < width) {
            putch('0');
            count++;
            len++;
          }
          while (i > 0) {
            putch(buffer[--i]);
            count++;
          }
          break;
        }
        case 's': {
          const char *str = va_arg(args, const char *);
          while (*str) {
            putch(*str++);
            count++;
          }
          break;
        }
        case 'c': {
          char c = (char)va_arg(args, int);
          putch(c);
          count++;
          break;
        }
        case '%': {
          putch('%');
          count++;
          break;
        }
        default: {
          putch('%');
          putch(*fmt);
          count += 2;
          break;
        }
      }
    } else {
      putch(*fmt);
      count++;
    }
  }
  va_end(args);
  return count;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

void inttostr(int num, char *str, int base) {
    int i = 0;
    int is_negative = 0;
    if (num < 0 && base == 10) {
      is_negative = 1;
      num = -num;
    }
    if (num == 0) {
      str[i++] = '0';
    }
    while (num != 0) {
      int rem = num % base;
      str[i++] = (rem > 9)? (rem - 10) + 'a' : rem + '0';
      num = num / base;
    }
    if (is_negative) {
      str[i++] = '-';
    }
    str[i] = '\0';

    int start = 0;
    int end = i - 1;
    while (start < end) {
      char temp = str[start];
      str[start] = str[end];
      str[end] = temp;
      start++;
      end--;
    }
}

int sprintf(char *out, const char *fmt, ...) {
  //panic("Not implemented");
  va_list args;
  va_start(args, fmt);
  int temp = 0;
  for(int i = 0; fmt[i] != '\0'; i++) {
    if(fmt[i] == '%') {
      i++;
      switch (fmt[i]) {
        case 's':{
          char *str = va_arg(args, char *);
          int len = strlen(str);
          for(int j = 0; j < len; j++) {
            out[temp] = str[j];
            temp++;
          }
          break;
        }
        case 'd': {
          int num = va_arg(args, int);
          char num_str[128];
          inttostr(num, num_str, 10);
          int len = strlen(num_str);
          for (int j = 0; j < len; j++) {
            out[temp++] = num_str[j];
          }
          break;
        }
        default:{
          out[temp++] = '%';
          out[temp++] = fmt[i];
          break;
        }
      }
    }
    else {
      out[temp] = fmt[i];
      temp++;
    }
  }
  out[temp] = '\0';
  va_end(args);
  return temp;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  
  int total = 0;          // 总字符数（不包括终止符）
  char *buf = out;
  size_t left = n;        // 剩余可用空间
  
  // 确保至少能写入终止符
  if (left > 0 && buf) *buf = '\0';
  
  for (int i = 0; fmt[i]; i++) {
    if (fmt[i] != '%') {
      // 普通字符
      total++;
      if (left > 1) {
        *buf++ = fmt[i];
        left--;
      }
      continue;
    }
    
    // 处理格式控制
    i++;
    switch (fmt[i]) {
      case 'd': {
        // 处理整数
        int num = va_arg(args, int);
        char temp[20];
        int len = 0;
        int neg = 0;
        unsigned int val;
        
        if (num < 0) {
          neg = 1;
          val = (unsigned int)(-num);
        } else {
          val = (unsigned int)num;
        }
        
        // 数字转字符串（逆序）
        do {
          temp[len++] = '0' + (val % 10);
          val /= 10;
        } while (val > 0);
        
        if (neg) temp[len++] = '-';
        
        // 计入总长度
        total += len;
        
        // 写入缓冲区（反转）
        if (left > 1) {
          int write_len = len < (int)(left - 1) ? len : (int)(left - 1);
          for (int j = 0; j < write_len; j++) {
            *buf++ = temp[len - 1 - j];
          }
          left -= write_len;
        }
        break;
      }
      
      case 's': {
        // 处理字符串
        const char *str = va_arg(args, const char *);
        if (!str) str = "(null)";
        int len = strlen(str);
        total += len;
        
        if (left > 1) {
          int copy_len = len < (int)(left - 1) ? len : (int)(left - 1);
          memcpy(buf, str, copy_len);
          buf += copy_len;
          left -= copy_len;
        }
        break;
      }
      
      case 'c': {
        // 处理字符
        char c = (char)va_arg(args, int);
        total++;
        if (left > 1) {
          *buf++ = c;
          left--;
        }
        break;
      }
      
      case '%': {
        // 处理百分号
        total++;
        if (left > 1) {
          *buf++ = '%';
          left--;
        }
        break;
      }
      
      default: {
        // 未知格式符，原样输出
        total += 2;
        if (left > 1) {
          *buf++ = '%';
          left--;
          if (left > 1) {
            *buf++ = fmt[i];
            left--;
          }
        }
        break;
      }
    }
  }
  
  // 添加终止符
  if (left > 0 && buf) *buf = '\0';
  
  va_end(args);
  return total;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
