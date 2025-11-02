#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

void intToStr(int num, char *str) {
    int i = 0;
    int isNegative = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    do {
        str[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    if (isNegative) {
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

int printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int count = 0;

    for (const char *p = fmt; *p != '\0'; p++) {
        if(*p != '%'){
            putch(*p);
            count++;
        }else{
            p++;

            if(*p == 'd'){
                int num = va_arg(args, int);
                char intstr[20];
                intToStr(num, intstr);
                for (int i = 0; intstr[i] != '\0'; i++){
                    putch(intstr[i]);
                    count++;
                }
            }
            else if(*p == 'c'){
                char c = (char)va_arg(args, int);
                putch(c);
                count++;
            }
            else if(*p == 'x'){
                uint8_t x = (uint8_t)va_arg(args, int);
                putch('0');
                putch('x');
                putch((x >> 4) < 10 ? (x >> 4) + '0' : (x >> 4) - 10 + 'a');
                putch((x & 0x0F) < 10 ? (x & 0x0F) + '0' : (x & 0x0F) - 10 + 'a');
                count++;
            }
            else if(*p == 's'){
                char *s = va_arg(args, char *);
                while (*s) {
                    putch(*s);
                    count++;
                    s++;
                }
            }
            else if(*(p+1) == 'd'){
                int width = *p - '0';
                p++;
                int num = va_arg(args, int);
                char intstr[20];
                intToStr(num, intstr);
                for(int i = 0; i < width - strlen(intstr); i++){
                    putch(' ');
                    count++;
                }
                for (int i = 0; intstr[i] != '\0'; i++){
                    putch(intstr[i]);
                    count++;
                }
            }
            else if(*(p+1) == 's'){
                putch('H');
                int width = *p - '0';
                p++;
                int num = va_arg(args, int);
                char intstr[20];
                intToStr(num, intstr);
                for(int i = 0; i < width - strlen(intstr); i++){
                    putch(' ');
                    count++;
                }
                for (int i = 0; intstr[i] != '\0'; i++){
                    putch(intstr[i]);
                    count++;
                }
            }
            else if(*(p+2) == 'd'){
                char fill = *p;
                p++;
                int width = *p  - '0';
                p++;
                int num = va_arg(args, int);
                char intstr[20];
                intToStr(num, intstr);
                for(int i = 0; i < width - strlen(intstr); i++){
                    putch(fill);
                    count++;
                }
                for (int i = 0; intstr[i] != '\0'; i++){
                    putch(intstr[i]);
                    count++;
                }
            }
            else{
                putch(*p);
                va_arg(args, int);
                count++;
            }
        }
    }

    return count; // 返回写入的字符数（不包括\0）
    //panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int count = 0;
    for (const char *p = fmt; *p != '\0'; p++) {
        if(*p != '%'){
            *out = *p;
            out++;
            count++;
        }else{
            p++;
            if(*p == 'd'){
                int num = va_arg(args, int);
                char intstr[40];
                intToStr(num, intstr);
                for (int i = 0; intstr[i] != '\0'; i++){
                    *out = intstr[i];
                    out++;
                    count++;
                }
            }
            if(*p == 's'){
                char *s = va_arg(args, char *);
                while (*s) {
                    *out = *s;
                    out++;
                    count++;
                    s++;
                }
            }
        }
    }
    *out = '\0';
    return count; 
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
