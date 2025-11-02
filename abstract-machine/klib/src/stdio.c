#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)


void int2str(char *out, int in){
	char tmp[30];
	int i = 0, j = 0;
	if(in < 0){
		in = -in;
		out[j++] = '-';
	}
	if(in == 0){
		tmp[i++] = '0';
	}
	else{
		while(in){
			tmp[i++] = in % 10 + '0';
			in /= 10;
		}
	}
	while(i){
		out[j++] = tmp[--i];
	}
	out[j] = '\0';
}


void long2str(char *out, long in){
    char tmp[30];
    int i = 0, j = 0;
    if(in < 0){
        in = -in;
        out[j++] = '-';
    }
    if(in == 0){
        tmp[i++] = '0';
    }
    else{
        while(in){
            tmp[i++] = in % 10 + '0';
            in /= 10;
        }
    }
    while(i){
        out[j++] = tmp[--i];
    }
    out[j] = '\0';
}



void int2xstr(char *out, int in, bool _x){
	int i = 0;
	if(_x){
		out[i++] = '0';
		out[i++] = 'x';
	}

	for(int j = 0; j < 8; ++j){
		uint8_t tmp = (in >> (28 - 4 * j)) & 0x0000000f;
		if(tmp <= 9)
			out[i++] = tmp + '0';
		else
			out[i++] = tmp - 10 + 'a';
	}
	out[i] = '\0';
}


void long2xstr(char *out, int in, bool _x){
    int i = 0;
    if(_x){
        out[i++] = '0';
        out[i++] = 'x';
    }

    for(int j = 0; j < 8; ++j){
        uint8_t tmp = (in >> (28 - 4 * j)) & 0x0000000f;
        if(tmp <= 9)
            out[i++] = tmp + '0';
        else
            out[i++] = tmp - 10 + 'a';
    }
    out[i] = '\0';
}


int printf(const char *fmt, ...) {
  assert(fmt);
  int i = 0;

  va_list ap;
  int d;
  long dd;
  char c;
  char *s;
  char tmp[30];

  //putstr("in printf");
  va_start(ap, fmt);
  while(*fmt){
    if(*fmt == '%' && *(fmt+1) == 's'){
        s = va_arg(ap, char*);
        //strcpy(out + i, s);
        i += strlen(s);
		putstr(s);
        fmt += 2;
    }
    else if(*fmt == '%' && *(fmt+1) == 'd'){
        d = va_arg(ap, int);
        int2str(tmp,d);
        //strcpy(out + i, tmp);
        i += strlen(tmp);
		putstr(tmp);
        fmt += 2;
    }
	else if(*fmt == '%' && *(fmt+1) == 'l' && *(fmt+2) == 'd'){
		dd = va_arg(ap, long);
		long2str(tmp,dd);
		i += strlen(tmp);
		putstr(tmp);
		fmt += 3;
	}
	else if(*fmt == '%' && *(fmt+1) == '#' && *(fmt+2) == 'x'){
		d = va_arg(ap, int);
		int2xstr(tmp,d,true);
		i += strlen(tmp);
		putstr(tmp);
		fmt += 3;
	}
	else if(*fmt == '%' && *(fmt+1) == 'x'){
		d = va_arg(ap, int);
		int2xstr(tmp,d,false);
		i += strlen(tmp);
		putstr(tmp);
		fmt += 2;
	}
    else if(*fmt == '%' && *(fmt+1) == 'c'){
        c = (char) va_arg(ap, int);
        //out[i] = c;
        i ++;
		putch(c);
        fmt += 2;
    }
    else{
        //out[i] = *fmt;
        i ++;
		putch(*fmt);
        fmt ++;
    }
  }
  va_end(ap);

  //out[i] = '\0';
  //return strlen(out);
  return i;
}



int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}



int sprintf(char *out, const char *fmt, ...) {
  assert(out); assert(fmt);
  int i = 0;

  va_list ap;
  int d;
  char c;
  char *s;
  char tmp[30];
  
  va_start(ap, fmt);
  while(*fmt){
  	if(*fmt == '%' && *(fmt+1) == 's'){
		s = va_arg(ap, char*);
		strcpy(out + i, s);
		i += strlen(s);
		fmt += 2;
	}
	else if(*fmt == '%' && *(fmt+1) == 'd'){
		d = va_arg(ap, int);
		int2str(tmp,d);
		strcpy(out + i, tmp);
		i += strlen(tmp);
		fmt += 2;
	}
	else if(*fmt == '%' && *(fmt+1) == 'c'){
		c = (char) va_arg(ap, int);
		out[i] = c;
		i ++;
		fmt ++;
	}
	else{
		out[i] = *fmt;
		i ++;
		fmt ++;
	}
  }
  va_end(ap);

  out[i] = '\0';
  return strlen(out);
}




int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
