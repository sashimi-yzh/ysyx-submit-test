#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// va_list 是一个类型，用于存储可变参数列表。
// va_start初始化 va_list,使其指向可变参数的起始位置。
// va_arg用于从可变参数列表中提取参数。需要指定参数的类型。
// va_end清理 va_list，结束可变参数的使用
// buf数组不要太大！！！！！！！！！不然内容会全存在数组而没有打印出来

void int_to_str(int num, char *buffer, int *index, int *is_negative) {
    *is_negative = 0;
    if (num == 0) {
        buffer[(*index)++] = '0';
        return;
    }
    
    char temp[32];
    int temp_index = 0;
    *is_negative = (num < 0);
    unsigned int n = (unsigned int)(*is_negative ? -num : num);
    
    while (n > 0) {
        temp[temp_index++] = (char)((n % 10) + '0');
        n /= 10;
    }
    
    // 反向复制数字部分
    for (int i = temp_index - 1; i >= 0; i--) {
        buffer[(*index)++] = temp[i];
    }
}

void int_to_base_str(unsigned int num, char *buffer, int *index, int base) {
    const char digits[] = "0123456789abcdef";
    if (num == 0) {
        buffer[(*index)++] = '0';
        return;
    }
    char temp[32];
    int temp_index = 0;
    while (num > 0) {
        temp[temp_index++] = digits[num % base];
        num /= base;
    }
    for (int i = temp_index - 1; i >= 0; i--) {
        buffer[(*index)++] = temp[i];
    }
}

void long_to_str(long long num, char *buffer, int *index) {
    if (num == 0) {
        buffer[(*index)++] = '0';
        return;
    }
    if (num < 0) {
        buffer[(*index)++] = '-';
        num = -num;
    }
    char temp[32];
    int temp_index = 0;
    while (num > 0) {
        temp[temp_index++] = (char)((num % 10) + '0');
        num /= 10;
    }
    for (int i = temp_index - 1; i >= 0; i--) {
        buffer[(*index)++] = temp[i];
    }
}

// int printf(const char *fmt, ...) {
//   panic("Not implemented");
// }

int vsprintf(char *out, const char *fmt, va_list ap) {
    char *str;
    int d;
    long ld;
    long long lld;
    // short hd;
    char c;
    char buffer[224] = {0};  // 初始化为零
    int index = 0;
    int buffer_index;  // 添加独立的缓冲区索引
    int precision = 6;

    for (; *fmt != '\0'; fmt++) {
        if(*fmt == '\\'){
            fmt++;
            if(*fmt == '\0') break;
            switch(*fmt){
                case 'n': out[index++]='\n';break;
                case 't': out[index++]='\t';break;
                case 'r': out[index++]='\r';break;
                case '\\': out[index++]='\\';break;
                default: out[index++]=*fmt;break;
            }
        }
        if (*fmt != '%') {
            out[index++] = *fmt;
            continue;
        }
        fmt++;//跳过“%”
        
        int width = 0;
        int zero_pad = 0;
        //解析标志
        if(*fmt == '0'){
            zero_pad = 1;
            fmt++;
        }
        //解析宽度
        while(*fmt >= '0' && *fmt <= '9') {
            width = width * 10 + (*fmt - '0');
            fmt++;
        }

        // 处理精度
        if (*fmt == '.') {
            fmt++;
            precision = 0;
            while (*fmt >= '0' && *fmt <= '9') {
                precision = precision * 10 + (*fmt - '0');
                fmt++;
            }
        }
        
        buffer_index = 0;  // 重置缓冲区索引
        switch (*fmt) {
            case 's':
                str = va_arg(ap, char *);
                while (*str) {
                    out[index++] = *str++;
                }
                break;
            case 'd':
                d = va_arg(ap, int);
                char num_buffer[32];  // 临时缓冲区
                int num_index = 0;
                int is_negative = 0;
                int_to_str(d, num_buffer, &num_index, &is_negative);
                int total_length = num_index + (is_negative ? 1 : 0);
                int pad = width - total_length;
                if (pad < 0) pad = 0;
                if (zero_pad) {
                    if(is_negative) out[index++] = '-';
                    //添加前导零
                    for (int i = 0; i < pad; i++) out[index++] = '0';
                    //添加数字
                    for (int i = 0; i < num_index; i++) out[index++] = num_buffer[i];
                }else{
                    //添加空格
                    for (int i = 0; i < pad; i++) out[index++] = ' ';
                    if(is_negative) out[index++] = '-';
                    //添加数字
                    for (int i = 0; i < num_index; i++) out[index++] = num_buffer[i];
                }
                break;
            case 'x':
                d = va_arg(ap, unsigned int);  // 改为 unsigned int
                int_to_base_str(d, buffer, &buffer_index, 16);
                for (int i = 0; i < buffer_index; i++) {
                    out[index++] = buffer[i];
                }
                break;
            case 'o':
                d = va_arg(ap, unsigned int);  // 改为 unsigned int
                int_to_base_str(d, buffer, &buffer_index, 8);
                for (int i = 0; i < buffer_index; i++) {
                    out[index++] = buffer[i];
                }
                break;
            case 'p':
                {
                    void *p = va_arg(ap, void *);
                    uintptr_t addr = (uintptr_t)p;
                    buffer_index = 0;
                    int_to_base_str(addr, buffer, &buffer_index, 16);
                    out[index++] = '0';
                    out[index++] = 'x';
                    for (int i = 0; i < buffer_index; i++) {
                        out[index++] = buffer[i];
                    }
                }
                break;
            case 'c':
                c = (char)va_arg(ap, int);
                out[index++] = c;
                break;
            case 'l':
                fmt++;
                if (*fmt == 'd') {
                    ld = va_arg(ap, long);
                    buffer_index = 0;
                    long_to_str(ld, buffer, &buffer_index);
                    for (int i = 0; i < buffer_index; i++) {
                        out[index++] = buffer[i];
                    }
                }
                else if (*fmt == 'l' && *(fmt + 1) == 'd') {
                    fmt++;
                    lld = va_arg(ap, long long);
                    buffer_index = 0;
                    long_to_str(lld, buffer, &buffer_index);
                    for (int i = 0; i < buffer_index; i++) {
                        out[index++] = buffer[i];
                    }
                }
                break;
            // case 'h':
            //     fmt++;
            //     if (*fmt == 'd') {
            //         hd = (short)va_arg(ap, int);
            //         buffer_index = 0;
            //         int_to_str(hd, buffer, &buffer_index);
            //         for (int i = 0; i < buffer_index; i++) {
            //             out[index++] = buffer[i];
            //         }
            //     }
            //     break;
            default:
                out[index++] = '%';
                out[index++] = *fmt;
                break;
        }
    }
    out[index] = '\0';
    return index;
}

// void putstr(const char *str){
//     while(*str){
//         putch(*str++);
//     }
// }

int printf(const char *fmt, ...){
    char buf[248];
    va_list args;
    va_start(args,fmt);
    int val = vsprintf(buf,fmt,args);
    putstr(buf);
    va_end(args);
    return val;
}

int sprintf(char *out, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int val=vsprintf(out,fmt,args);
    va_end(args);
    return val;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
    char buffer[224]; // 临时缓冲区
    int len = vsprintf(buffer, fmt, ap); // 先格式化到临时缓冲区
    if (len >= n) len = n - 1; // 截断超出部分
    memcpy(out, buffer, len); // 复制到输出缓冲区
    out[len] = '\0'; // 确保字符串以\0结尾
    return len;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(out, n, fmt, args);
    va_end(args);
    return len;
}

#endif
