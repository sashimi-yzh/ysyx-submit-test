#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static void out_char(char **out, char c) {
  **out = c;
  (*out)++;
}

static int out_str(char **out, const char *s) {
  int count = 0;
  while (*s) {
    out_char(out, *s++);
    count++;
  }
  return count;
}

static int out_int(char **out, int num, int width, char pad) {
  char buf[32];  // 足够存储32位整数的字符串表示
  int i = 0;
  int count = 0;
  int is_negative = 0;
  
  // 处理负数
  if (num < 0) {
    is_negative = 1;
    num = -num;
  }
  
  // 特殊情况：0
  if (num == 0) {
    buf[i++] = '0';
  } else {
    // 将数字转换为字符串（逆序）
    while (num > 0) {
      buf[i++] = '0' + (num % 10);
      num /= 10;
    }
  }
  
  // 计算需要的总宽度
  int num_len = i + (is_negative ? 1 : 0);
  
  // 如果需要填充
  if (width > num_len) {
    // 如果是'0'填充且有负号，先输出负号
    if (pad == '0' && is_negative) {
      out_char(out, '-');
      count++;
      is_negative = 0;  // 标记已输出负号
    }
    
    // 输出填充字符
    for (int j = 0; j < width - num_len; j++) {
      out_char(out, pad);
      count++;
    }
  }
  
  // 输出负号（如果还没输出）
  if (is_negative) {
    out_char(out, '-');
    count++;
  }
  
  // 逆序输出数字
  while (i > 0) {
    out_char(out, buf[--i]);
    count++;
  }
  
  return count;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  char *out_start = out;  // 保存起始位置
  
  while (*fmt) {
    if (*fmt == '%') {
      fmt++;  // 跳过'%'
      
      // 解析宽度和填充字符
      int width = 0;
      char pad = ' ';  // 默认用空格填充
      
      // 检查是否有'0'填充
      if (*fmt == '0') {
        pad = '0';
        fmt++;
      }
      
      // 解析宽度
      while (*fmt >= '0' && *fmt <= '9') {
        width = width * 10 + (*fmt - '0');
        fmt++;
      }
      
      switch (*fmt) {
        case 's': {
          // 字符串格式
          const char *s = va_arg(ap, const char *);
          out_str(&out, s);
          break;
        }
        
        case 'd': {
          // 十进制整数格式
          int num = va_arg(ap, int);
          out_int(&out, num, width, pad);
          break;
        }
        
        case '%': {
          // 百分号字符
          out_char(&out, '%');
          break;
        }
        
        default:
          // 不支持的格式，直接输出
          out_char(&out, '%');
          if (pad == '0') out_char(&out, '0');
          if (width > 0) {
            // 输出宽度数字
            char width_buf[16];
            int i = 0;
            int w = width;
            while (w > 0) {
              width_buf[i++] = '0' + (w % 10);
              w /= 10;
            }
            while (i > 0) {
              out_char(&out, width_buf[--i]);
            }
          }
          out_char(&out, *fmt);
          break;
      }
      fmt++;
    } else {
      // 普通字符，直接输出
      out_char(&out, *fmt++);
    }
  }
  
  // 添加字符串结束符
  *out = '\0';
  
  // 返回写入的字符数（不包括'\0'）
  return out - out_start;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  int ret;
  
  // 初始化可变参数列表
  va_start(ap, fmt);
  
  // 调用vsprintf完成实际工作
  ret = vsprintf(out, fmt, ap);
  
  // 清理可变参数列表
  va_end(ap);
  
  return ret;
}

int printf(const char *fmt, ...) {
  char buf[4096];  // 临时缓冲区
  va_list ap;
  int ret;
  
  // 初始化可变参数列表
  va_start(ap, fmt);
  
  // 使用vsprintf格式化到缓冲区
  ret = vsprintf(buf, fmt, ap);
  
  // 清理可变参数列表
  va_end(ap);
  
  // 逐字符输出到串口
  for (int i = 0; i < ret; i++) {
    putch(buf[i]);
  }
  
  return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
