#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static char HEX_CHARACTERS[] = "0123456789ABCDEF";

int printf(const char *fmt, ...) {
//   panic("Not implemented");

	int count;
	char buf[2048];
	va_list args;
	// 解析...中的参数
	va_start(args, fmt);
	
	count = vsprintf(buf, fmt, args);

	// for(int i = 0; i < count;i++){
	// 	putch(buf[i]);
	// }
	putstr(buf);

	va_end(args);
	return count;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
//   panic("Not implemented");

	int index = 0;

	while(*fmt){
		if(*fmt != '%'){
			out[index++] = *fmt;
		}else{
			fmt++;
			/**
			 * width: 指定输出字段的最小宽度
			 * precision: 控制输出的精度。
			 * argc_type: 指定参数的类型。
			 */
			int width =0,precision = -1;
			//char argc_type = 0;
			while(*fmt>='0' && *fmt<='9'){
				width = width * 10 + (*fmt - '0');
				fmt ++;
			}
			if(*fmt == '.'){
				fmt++;
				precision = 0;
				while(*fmt>='0' && *fmt<='9'){
					precision = precision * 10 + (*fmt - '0');
					fmt ++;
				}
			}
			// if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L') {
            //     argc_type = *fmt++;
            // }

			switch(*fmt){
				case 's':{
					char *s = va_arg(ap, char*);
					int len = strlen(s);
					if (precision >= 0 && precision < len) {
                        len = precision;
                    }
					if (width > len) {
                        for (int i = 0; i < width - len; i++) {
                            out[index++] = ' '; // 右对齐
                        }
                    }
					strncpy(out + index, s, len);
					index += len;
					break;
				}
				case 'd':{
					int i = va_arg(ap, int);
					if(i == 0){
						out[index++] = '0';
					}else {
						if(i < 0){
							out[index++] = '-';
							i = 0 - i;
						}
						int digital;
						char temp[32];
						int count = 0;
						while(i>0){
							digital = i%10;
							temp[count++] = HEX_CHARACTERS[digital];
							i = i/10;
						}
						//count--;	// 对于下标而言，这个count多加了一次
						if (precision >= 0 && precision < count) {
							count = precision - 1;
						}else{
							count--;
						}
						if (width > count) {
							for (int i = 0; i < width - count; i++) {
								out[index++] = ' '; // 右对齐
							}
						}
						while(count>=0){
							out[index++] = temp[count--];
						}
					}
					break;
				}
				case 'l': {
					// 检查下一个字符是否为 'd'，即 "%ld"
					if (*(fmt + 1) == 'd') {
						fmt += 1; // 跳过 'l'，处理 'd'
						long long i = va_arg(ap, long long);

						// 处理零的情况
						if (i == 0) {
							out[index++] = '0';
						} else {
							// 处理负数
							if (i < 0) {
								out[index++] = '-';
								i = -i; // 转为正数处理
							}

							// 分解数字为字符
							int digital;
							char temp[64]; // 足够容纳 long long 的最大值（最多 20 位）
							int count = 0;
							while (i > 0) {
								digital = i % 10;
								temp[count++] = HEX_CHARACTERS[digital];
								i = i / 10;
							}

							// 处理 precision 控制
							if (precision >= 0 && precision < count) {
								count = precision - 1;
							} else {
								count--;
							}

							// 处理 width 填充（右对齐）
							if (width > count) {
								for (int i = 0; i < width - count; i++) {
									out[index++] = ' ';
								}
							}

							// 逆序输出数字字符
							while (count >= 0) {
								out[index++] = temp[count--];
							}
						}
					}
					break;
				}
				case 'c': {
					char temp = (char)va_arg(ap,int);
					if (width > 1) {
						for (int i = 0; i < width - 1; i++) {
							out[index++] = ' '; // 右对齐
						}
					}
					out[index++] = temp;
					break;
				}
				case 'x': {
					unsigned int x = va_arg(ap, unsigned int);
					char temp[32]; 
					int count = 0,digital = 0;
					while(x>0){
						digital = x%16;
						temp[count++] = HEX_CHARACTERS[digital];
						x = x/16;
					}
					// 处理宽度和精度
					// count和precision代表的是数字的位数，但是后续需要使用下标，所以需要减1
					if (precision >= 0 && precision < count) {
						count = precision - 1;
					}else{
						count--;
					}
					if (width > count) {
						for (int i = 0; i < width - count; i++) {
							out[index++] = ' '; // 右对齐
						}
					}
					while(count>=0){
						out[index++] = temp[count--];
					}
                    break;
				}
				default:{
					out[index++] = *fmt;
					break;
				}
					
			}
		} 
		fmt++;
	}
	out[index] = '\0';

	return index;
}

int sprintf(char *out, const char *fmt, ...) {
	//panic("Not implemented");

	// char *start = out;
	va_list args;
	// 解析...中的参数
	va_start(args, fmt);
	
	int ret = vsprintf(out, fmt, args);
	
	va_end(args);
	// return out - start;
	return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
