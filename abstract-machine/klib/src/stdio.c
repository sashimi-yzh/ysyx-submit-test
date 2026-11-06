#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)


void am_itoa(int num, char *str);
void am_long_itoa(long num, char *str);

int printf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int count = 0;

  const char *p = fmt;
  while(*p != '\0')
  {
    if(*p != '%')
    {
      putch(*p);
      p ++;
      count ++;
    }
    else
    {
      p++;

      int width = 0;
      int zero_pad = 0;

      if (*p == '0') {
        zero_pad = 1;
        p++;
                
        // 解析宽度
        while (*p >= '0' && *p <= '9') {
          width = width * 10 + (*p - '0');
          p++;
        }
      }

      switch(*p)
      {
        case 'd':
        {
          int num = va_arg(args, int);
          char str[30];
          am_itoa(num, str);

          int len = 0;
          while (str[len] != '\0') len++;
          
          int is_negative = (num < 0);
          int digits = is_negative ? len - 1 : len;
          int padding = width - digits;
          if (padding < 0) {
            padding = 0;
          }

          if (zero_pad) {
            for (int i = 0; i < padding; i++) {
              putch('0');
              count ++;
            }
          }
          for(int i = 0; str[i] != '\0'; i++)
          {
            putch(str[i]);
            count ++;
          }
          p ++;
          break;
        }
         case 'l':
        if (*(p+1) == 'd') {
          p ++;
          long num = va_arg(args, long);
          char str[30];
          am_long_itoa(num, str);

          int len = 0;
          while (str[len] != '\0') len++;
          
          int is_negative = (num < 0);
          int digits = is_negative ? len - 1 : len;
          int padding = width - digits;
          if (padding < 0) {
            padding = 0;
          }

          if (zero_pad) {
            for (int i = 0; i < padding; i++) {
              putch('0');
              count ++;
            }
          }
          for(int i = 0; str[i] != '\0'; i++)
          {
            putch(str[i]);
            count ++;
          }
          p ++;
          break;
        } else {
            // 无效
        }
        break;
        case 's':
        {
          char *str = va_arg(args, char *);
          for(int i = 0; str[i] != '\0'; i++)
          {
            putch(str[i]);
            count ++;
          }
          p ++;
          break;
        }
        case 'c':
        {
          int ch = va_arg(args, int);
          putch(ch);
          count ++;
          p ++;
          break;
        }
        case '%':
        {
          putch('%');
          count ++;
          p ++;
          break;
        }
        default: // 处理无效格式符
        {
          putch('%');
          putch(*p);
          count += 2;
          break;
        }
      }
      
    }
  }
  va_end(args);
  return count;
  // panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  char *p = out;  // 指向输出缓冲区的指针
  const char *f = fmt;  // 指向格式化字符串的指针

  while (*f != '\0') {
    if (*f != '%') {
      // 普通字符，直接写入缓冲区
      *p++ = *f++;
    } else {
      f++;  // 跳过 '%'
      switch (*f) {
        case 'd': {
          // 处理 %d 格式说明符
          int num = va_arg(ap, int);  // 从 va_list 提取整数参数
          char str[20];
          am_itoa(num, str);  // 将整数转换为字符串
          for (int i = 0; str[i] != '\0'; i++) {
            *p++ = str[i];
          }
          f++;
          break;
        }
        case 's': {
          // 处理 %s 格式说明符
          char *str = va_arg(ap, char *);  // 从 va_list 提取字符串参数
          while (*str != '\0') {
            *p++ = *str++;
          }
          f++;
          break;
        }
        case 'c': {
          // 处理 %c 格式说明符
          char ch = (char)va_arg(ap, int);  // 从 va_list 提取字符参数
          *p++ = ch;
          f++;
          break;
        }
        case '%': {
          // 处理 %%，写入一个 '%' 字符
          *p++ = '%';
          f++;
          break;
        }
        default:
          // 未知格式说明符，直接跳过
          f++;
          break;
      }
    }
  }
  *p = '\0';

  
  return p - out;
  // panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  char *p = out;
  while(*fmt != '\0')
  {
    if(*fmt != '%')
    {
      *p++ = *fmt++;
    }
    else
    {
      fmt++;
      switch(*fmt)
      {
        case 'd':
        {
          int num = va_arg(args, int);
          char str[20];
          am_itoa(num, str);
          for(int i = 0; str[i] != '\0'; i++)
          {
            *p++ = str[i];
          }
          break;
        }
        case 's':
        {
          char *str = va_arg(args, char *);
          for(int i = 0; str[i] != '\0'; i++)
          {
            *p++ = str[i];
          }
          break;
        }
        case 'c':
        {
          char ch = va_arg(args, int);
          *p++ = ch;
          break;
        }
        case '%':
        {
          *p++ = '%';
          break;
        }
        default: {
            // 处理无效格式符：原样输出 % 和无效字符
          *p++ = '%';
          *p++ = *fmt;
          break;
        }
      }
      fmt++;
    }
  }
  *p = '\0';
  va_end(args);
  return p - out;
  // panic("Not implemented");
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  if(!out) return strlen(fmt);
  if (n == 0) {
    // 如果缓冲区大小为 0，直接返回
    return 0;
  }

  va_list args;
  va_start(args, fmt);

  char *p = out;
  size_t count = 0;

  while (*fmt && count < n - 1) {
    if (*fmt != '%') {
      // 普通字符，直接写入缓冲区
      *p++ = *fmt++;
      count++;
    } else {
      fmt++;  // 跳过 '%'
      switch (*fmt) {
        case 'd': {
          // 处理 %d 格式说明符
          int num = va_arg(args, int);
          char str[20];
          am_itoa(num, str);
          for (int i = 0; str[i] != '\0' && count < n - 1; i++) {
            *p++ = str[i];
            count++;
          }
          fmt++;
          break;
        }
        case 's': {
          // 处理 %s 格式说明符
          char *str = va_arg(args, char *);
          while (*str != '\0' && count < n - 1) {
            *p++ = *str++;
            count++;
          }
          fmt++;
          break;
        }
        case 'c': {
          char ch = (char)va_arg(args, int);
          *p++ = ch;
          count++;
          fmt++;
          break;
        }
        case '%': {
          *p++ = '%';
          count++;
          fmt++;
          break;
        }
        default:
          // 未知格式说明符，直接跳过
          fmt++;
          break;
      }
    }
  }

  // 添加字符串结尾的空字符
  if (count < n) {
    *p = '\0';
  }

  va_end(args);
  return count;
  // panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
   char *p = out;
    size_t count = 0;

    // 如果输出缓冲区不是 NULL 且缓冲区大小大于0，则初始化指向输出缓冲区的指针
    if (n != 0 && out != NULL) {
        p = out;
    }

    // 遍历格式化字符串
    while (*fmt && ((n == 0) || (count < n - 1))) {
        if (*fmt != '%') {
            // 普通字符，直接写入缓冲区
            if (p) *p = *fmt;
            p++;
            count++;
            fmt++;
        } else {
            fmt++; // 跳过 '%'
            // 根据格式字符处理相应的参数
            switch (*fmt) {
                // 处理整数格式字符 'd'
                case 'd':
                {
                    // 从可变参数列表中提取整数参数
                    int num = va_arg(ap, int);
                    // 将整数转换为字符串并写入缓冲区
                    char str[20];
                    am_itoa(num, str);
                    for (int i = 0; str[i] != '\0' && (count < n - 1); i++) {
                        if (p) *p = str[i];
                        p++;
                        count++;
                    }
                    fmt++;
                    break;
                  }
                // 处理字符串格式字符 's'
                case 's':
                {
                    // 从可变参数列表中提取字符串参数
                    char *str = va_arg(ap, char *);
                    for(int i = 0; str[i] != '\0' && (count < n - 1); i++)
                    {
                      *p++ = str[i];
                      count++;
                    }
                    fmt++;
                    break;
                  }
                // 处理字符格式字符 'c'
                case 'c':
                    // 从可变参数列表中提取字符参数
                    char ch = (char)va_arg(ap, int);
                    if (p) *p = ch;
                    p++;
                    count++;
                    fmt++;
                    break;

                // 处理百分号 '%'
                case '%':
                    if (p) *p = '%';
                    p++;
                    count++;
                    fmt++;
                    break;

                // 其他格式字符可以类似处理
                default:
                    fmt++;
                    break;
            }
        }
    }

    // 如果输出缓冲区不是 NULL 且缓冲区大小大于0，则在末尾添加空字符
    if (n != 0 && out != NULL) {
      if (count < n) {
        *p = '\0'; // 添加空字符
      } 
      }
    return count;
  // panic("Not implemented");
}



void am_itoa(int num, char *str)
{
  if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    int i = 0;
    int is_negative = 0;
    unsigned int unum;  // 使用无符号数处理最小负数

    if (num < 0) {
        is_negative = 1;
        unum = (unsigned int)(-num);  // 避免溢出
    } else {
        unum = num;
    }

    while (unum > 0) {
        str[i++] = '0' + (unum % 10);
        unum /= 10;
    }

    if (is_negative) {
        str[i++] = '-';
    }

    str[i] = '\0';
    
    // 反转字符串
    int start = 0, end = i - 1;
    while (start < end) {
        char tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}
void am_long_itoa(long num, char *str)
{
  if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    int i = 0;
    int is_negative = 0;
    unsigned long unum;  // 使用无符号数处理最小负数

    if (num < 0) {
        is_negative = 1;
        unum = (unsigned long)(-num);  // 避免溢出
    } else {
        unum = num;
    }

    while (unum > 0) {
        str[i++] = '0' + (unum % 10);
        unum /= 10;
    }

    if (is_negative) {
        str[i++] = '-';
    }

    str[i] = '\0';
    
    // 反转字符串
    int start = 0, end = i - 1;
    while (start < end) {
        char tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}


#endif
