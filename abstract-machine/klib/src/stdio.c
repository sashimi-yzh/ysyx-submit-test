#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  char buf_stdout[1024];
  va_list args;
  va_start(args, fmt);
  int len = vsprintf(buf_stdout, fmt, args);
  putstr(buf_stdout);
  return len;
  // panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  int i = 0;
  char *out_temp = out;
  
  for (; fmt[i] != '\0'; i++) {
    if (fmt[i] == '%') {
      i++;
      
      // 解析标志和宽度
      char padding_ch = ' ';
      int width = 0;
      int long_flag = 0;
      
      // 解析标志
      if (fmt[i] == '0') {
        padding_ch = '0';
        i++;
      }
      
      // 解析宽度
      while (fmt[i] >= '0' && fmt[i] <= '9') {
        width = width * 10 + (fmt[i] - '0');
        i++;
      }
      
      // 解析长度修饰符
      if (fmt[i] == 'l') {
        long_flag = 1;
        i++;
      }
      
      switch (fmt[i]) {
        case 'c': {
          char ch = va_arg(ap, int);
          *out_temp++ = ch;
          break;
        }
        
        case 'd':
        case 'i': {
          int64_t int_arg;
          int is_negative = 0;
          
          if (long_flag) {
            int_arg = va_arg(ap, long);
          } else {
            int_arg = va_arg(ap, int);
          }
          
          if (int_arg < 0) {
            is_negative = 1;
            int_arg = -int_arg;
          }
          
          char int_buf[32];
          int off_int_buf = 0;
          
          if (int_arg == 0) {
            int_buf[off_int_buf++] = '0';
          } else {
            while (int_arg != 0) {
              int_buf[off_int_buf++] = (int_arg % 10) + '0';
              int_arg /= 10;
            }
          }
          
          int total_len = off_int_buf + (is_negative ? 1 : 0);
          int pad_len = (width > total_len) ? (width - total_len) : 0;
          
          if (padding_ch == '0' && is_negative) {
            *out_temp++ = '-';
            is_negative = 0; // 负号已输出
          }
          
          for (int j = 0; j < pad_len; j++) {
            *out_temp++ = padding_ch;
          }
          
          if (is_negative) {
            *out_temp++ = '-';
          }
          
          while (off_int_buf--) {
            *out_temp++ = int_buf[off_int_buf];
          }
          break;
        }
        
        case 'u': {
          uint64_t uint_arg;
          
          if (long_flag) {
            uint_arg = va_arg(ap, unsigned long);
          } else {
            uint_arg = va_arg(ap, unsigned int);
          }
          
          char uint_buf[32];
          int off_int_buf = 0;
          
          if (uint_arg == 0) {
              uint_buf[off_int_buf++] = '0';
          } else {
            while (uint_arg != 0) {
              uint_buf[off_int_buf++] = (uint_arg % 10) + '0';
              uint_arg /= 10;
            }
          }
          
          int pad_len = (width > off_int_buf) ? (width - off_int_buf) : 0;
          for (int j = 0; j < pad_len; j++) {
            *out_temp++ = padding_ch;
          }
          
          while (off_int_buf--) {
            *out_temp++ = uint_buf[off_int_buf];
          }
          break;
        }
        
        case 'x':
        case 'X': {
          uint64_t hex_arg;
          const char *hex_digits = (fmt[i] == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
          
          if (long_flag) {
            hex_arg = va_arg(ap, unsigned long);
          } else {
            hex_arg = va_arg(ap, unsigned int);
          }
          
          char hex_buf[32];
          int off_hex_buf = 0;
          
          if (hex_arg == 0) {
            hex_buf[off_hex_buf++] = '0';
          } else {
            while (hex_arg != 0) {
              hex_buf[off_hex_buf++] = hex_digits[hex_arg & 0xF];
              hex_arg >>= 4;
            }
          }
          
          int pad_len = (width > off_hex_buf) ? (width - off_hex_buf) : 0;
          for (int j = 0; j < pad_len; j++) {
            *out_temp++ = padding_ch;
          }
          
          while (off_hex_buf--) {
            *out_temp++ = hex_buf[off_hex_buf];
          }
          break;
        }
        case 's': {
          char *string_arg = va_arg(ap, char *);
          if (string_arg == NULL) {
            string_arg = "(null)";
          }
          
          int str_len = 0;
          const char *temp = string_arg;
          while (*temp++) str_len++;
          
          if (width > str_len) {
            int pad_len = width - str_len;
            for (int j = 0; j < pad_len; j++) {
              *out_temp++ = padding_ch;
            }
          }
          
          // 复制字符串
          while (*string_arg != '\0') {
            *out_temp++ = *string_arg++;
          }
          break;
        }
        
        case '%': 
          *out_temp++ = '%'; 
          break;
            
        default: 
          panic("format specifier not implemented");
      }
    } else {
        *out_temp++ = fmt[i];
    }
  }
  
  *out_temp = '\0';
  return out_temp - out;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  return vsprintf(out, fmt, ap);
  panic("Not implemented");
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
