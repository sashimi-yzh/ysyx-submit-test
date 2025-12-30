#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)


// int printf(const char *fmt, ...) {
//     va_list ap;
//     char *buf;
//     char buf_test[1024];
        
//     // 第一阶段：测量需要的空间
//     va_start(ap, fmt);
//     int length = vsprintf(buf_test, fmt, ap);
//     va_end(ap);
    
//     if (length < 0) {
//         // 格式化错误
//         return -1;
//     } else if (length == 0) {
//         // 空字符串，直接返回
//         return 0;
//     }
    
//     // 分配精确大小的缓冲区（+1 用于字符串终止符）
//     buf = malloc(length + 1);
//     if (!buf) {  return -1; } // 内存分配失败
    
//     // 第二阶段：实际格式化
//     va_start(ap, fmt);
//     vsprintf(buf, fmt, ap);
//     va_end(ap);
    
//     // 输出字符串
//     char *tmp = buf;
//     while (*tmp != '\0') {
//         putch(*tmp);
//         tmp++;
//     }
    
//     // 释放内存
//     free(buf);
    
//     return length;
// }


int printf(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	
	char *buf = malloc(0x1000);
    
    //char buf[1024];
    if (!buf) { return -1;}
    
	int length = vsprintf(buf, fmt, ap);// 计算需要的缓冲区大小

    char *tmp = buf;
    // putch('Q');putch(':');
    // put_pointer(buf);putch('\n');
    while (*tmp !='\0') {
        putch(*tmp);
        tmp++;
    }
    
    free(buf);
	va_end(ap);
	return length;

}


int vsprintf(char *out, const char *fmt, va_list ap) {
    char *out_w = out;
    const char *fmt_r = fmt;

    while (*fmt_r != '\0') {
        if (*fmt_r != '%') {
            *out_w++ = *fmt_r++;
            continue;
        }
        
        fmt_r++; // 跳过 '%'
        if (*fmt_r == '\0') {
            *out_w++ = '%';
            break;
        }

        char length_modifier = 0;   // 解析长度修饰符
        if (*fmt_r == 'l') {
            length_modifier = 'l';
            fmt_r++;
        }
        
        int flags = 0;        //标志位(0默认空格填充)
        int width = 0;        //宽度控制
        char pad_char = ' ';  //默认用空格填充

        // 解析标志 - 检测零填充
        if (*fmt_r == '0') {
            pad_char = '0';  // 使用零填充
            flags |= 1;      // 设置零填充标志
            fmt_r++;
        }
 
        // 解析宽度
        if (*fmt_r >= '0' && *fmt_r <= '9') {
            width = 0;
            while (*fmt_r >= '0' && *fmt_r <= '9') {
                width = width * 10 + (*fmt_r - '0');
                fmt_r++;
            }
        }

        // 处理类型
        switch (*fmt_r) {
            case '%': {
                *out_w++ = '%';
                fmt_r++;
                break;
            }
            case 'd':
            case 'i': {
                long num;
                if (length_modifier == 'l') {
                    num = va_arg(ap, long);
                } else {
                    num = va_arg(ap, int);
                }
                int is_negative = num < 0;
                unsigned  long  abs_num = is_negative ? -num : num; //取绝对值
                
                // 转换为字符串（反向）
                char buffer[32];
                int index = 0;
                int digit_count = 0;
                
                // 处理0的特殊情况
                if (abs_num == 0) {
                    buffer[index++] = '0';
                    digit_count = 1;
                } else {
                    while (abs_num > 0) {
                        buffer[index++] = '0' + (abs_num % 10);
                        abs_num /= 10;
                        digit_count++;
                    }
                }
                
                // 计算需要填充的字符数
                int total_chars = digit_count;
                //if (is_negative || (flags & 2) || (flags & 4)) {
                if (is_negative) {
                    total_chars++; // 符号位
                }
                int padding = width > total_chars ? width - total_chars : 0; //填充的空格或者0位数

                // 处理符号和填充
                if (is_negative) {
                    if (pad_char == '0') {// 零填充：先输出符号，再填充零
                        *out_w++ = '-';
                        for (int i = 0; i < padding; i++) {
                            *out_w++ = pad_char;
                        }
                    } else {// 空格填充：先填充空格，再输出符号
                        for (int i = 0; i < padding; i++) {
                            *out_w++ = pad_char;
                        }
                        *out_w++ = '-';
                    }
                }else {// 非负数，直接填充
                    for (int i = 0; i < padding; i++) {
                        *out_w++ = pad_char;
                    }
                }
                // 输出数字（反向输出）
                for (int i = index - 1; i >= 0; i--) {
                    *out_w++ = buffer[i];
                }

                fmt_r++;
                break;
            }
            case 'u': {
                unsigned long num;
                if (length_modifier == 'l') {
                    num = va_arg(ap, unsigned long);
                } else {
                    num = va_arg(ap, unsigned int);
                }
                // 实现类似于 %d，但没有符号处理
                char buffer[32];
                int index = 0;
                int digit_count = 0;
                
                if (num == 0) {
                    buffer[index++] = '0';
                    digit_count = 1;
                } else {
                    while (num > 0) {
                        buffer[index++] = '0' + (num % 10);
                        num /= 10;
                        digit_count++;
                    }
                }

                // 输出数字（反向输出）
                for (int i = index - 1; i >= 0; i--) {
                    *out_w++ = buffer[i];
                }

                fmt_r++;
                break;
            }
			case 'X':{//%X大写十六进制数
				unsigned long num;
                if (length_modifier == 'l') {
                    num = va_arg(ap, unsigned long);
                } else {
                    num = va_arg(ap, unsigned int);
                }
				unsigned long digit = num, num_digit = 1;
				char hex_digit[] = "0123456789ABCDEF";
				while(digit >= 16){digit /= 16; num_digit++;}//计算位数
				for(int i = num_digit; i >=1; i--){
					unsigned int digit_2 = num;
					for(int j = 0; j < i -1; j++){digit_2 /= 16;}
					digit_2 %= 16;
					*out_w++ = hex_digit[digit_2];
				}
				fmt_r++;
				break;
			}
			case 'x':{//%x小写十六进制数
                unsigned long num;
                if (length_modifier == 'l') {
                    num = va_arg(ap, unsigned long);
                } else {
                    num = va_arg(ap, unsigned int);
                }
				unsigned int digit = num, num_digit = 1;
				char hex_digit[] = "0123456789abcdef";
				while(digit >= 16){digit /= 16; num_digit++;}//计算位数
				for(int i = num_digit; i >=1; i--){
					unsigned int digit_2 = num;
					for(int j = 0; j < i -1; j++){digit_2 /= 16;}
					digit_2 %= 16;
					*out_w++ = hex_digit[digit_2];
				}
				fmt_r++;
				break;
			}
			case 's':{//%s字符串
				char *str = va_arg(ap, char*);
				if (str == NULL) {str = "(null)";}
				while(*str != '\0') {*out_w++ = *str++;}
				fmt_r++;
				break;			
			}
			case 'c':{//%c字符
				char c = (char)va_arg(ap, int);
				*out_w++ = c;
				fmt_r++;
				break;			
			}
            case 'p': {  // %p 指针
                void *ptr = va_arg(ap, void*);
                 unsigned long addr = (unsigned long)ptr;
    
                // 输出 "0x" 前缀
                *out_w++ = '0';
                *out_w++ = 'x';
    
                // 输出十六进制地址
                char hex_digit[] = "0123456789abcdef";
                int started = 0;
    
                for (int i = 7; i >= 0; i--) {
                    int digit = (addr >> (i * 4)) & 0xF;  //当前处理的4位右移到最低位
                    if (digit != 0 || started || i == 0) { //前面的0不输出||中间的零可以输出||全零会输出0
                        *out_w++ = hex_digit[digit];
                        started = 1;
                    }
                }
    
                fmt_r++;
                break;
            }
            
            default: {
                // 不支持的格式，原样输出
                *out_w++ = '%';
                *out_w++ = *fmt_r++;
                break;
            }
        }
    }
    
    *out_w = '\0';
    return out_w - out;
}




int sprintf(char *out, const char *fmt, ...) {
	va_list ap;        //声明参数列表变量
	va_start(ap, fmt); //初始化 va_list 对象，使其指向第一个可变参数
	int length = vsprintf(out, fmt, ap);
	va_end(ap) ;         //清理 va_list 对象，结束可变参数的访问
	return length;
}



int snprintf(char *out, size_t n, const char *fmt, ...) {
	panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
	panic("Not implemented");
}

#endif
