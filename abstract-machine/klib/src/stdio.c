#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap);
static char buf[1024];
int printf(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	int val = vsnprintf(buf, 1024, fmt, ap);
	char *str = buf;
	while(*str != '\0'){
		putch(*str);
		str ++;
	}
	va_end(ap);
	return val;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
	memset(out, 0, strlen(out));
	va_list ap;
  va_start(ap, fmt);
	int val = vsnprintf(out, 1024, fmt, ap);
	va_end(ap);
	return val;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
	char *start = out;
	while(n -- && *fmt != '\0'){
		switch(*fmt){
			case '%': {
				fmt ++;
				switch(*fmt) {
					case '0': {
						fmt ++;
						int i = atoi(fmt);
						switch(*fmt) {
							case '2':
							case '3':
							case '4':
							case '5':
							case '6':
							case '7':
							case '8':{
								fmt ++;
								switch(*fmt) {
									case 'd': {
										int val = va_arg(ap, int);
										if(val < 0) {
											*out ++ = '-';
											val = -val;
										}
										int len = 0;
										int number = val;
										do {
											number /= 10;
											len ++;
										} while(number);
										if(len < i){
											out = out + i - 1;
                      int tmp_len = i;
                      while(tmp_len --) {
                        int tmp = val % 10;
                        *out-- = tmp + 48;
                        val /= 10;
                      }
                      out += (i + 1);
                      break;
										}
										else {
											out = out + len - 1;
											int tmp_len = len;
											while(tmp_len --) {
												int tmp = val % 10;
												*out-- = tmp + 48;
												val /= 10;
											}
											out += (len + 1);
											break;
										}
									}
									default: {
										return -1;
									}
								}
								break;
							}
							default: {
								return -1;
							}
						}
						break;
					}
					default: {
						switch(*fmt) {
							case 'd': {
								int val = va_arg(ap, long int);
								if(val < 0) {
									*out ++ = '-';
									val = -val;
								}
								int len = 0;
								int number = val;
								do {
									number /= 10;
									len ++;
								} while(number);
								out = out + len - 1;
								int tmp_len = len;
								while(tmp_len --) {
								  int tmp = val % 10;
									*out-- = tmp + 48;
									val /= 10;
								}
								out += (len + 1);
								break;
							}
							case 's': {
								char *tmp = va_arg(ap, char *);
								while(*tmp != '\0') {
									*out++ = *tmp++;
								}
								break;
							}
							case 'c': {
								char tmp = va_arg(ap, int);
								*out ++ = tmp;
								break;
							}
							default: {
								return -1;
							}
						}
					}
				}
				break;
			}
			default: {
				*out ++ = *fmt;
				break;
			}
		}
		fmt ++;
	}
	*out = '\0';
	return out - start;
}

#endif
