#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

#define isdigit(c) (('0'<=(c))&&((c)<='9'))
// return false to end format, also caller cnt will not +1
typedef bool(*putch_func)(int c,void* exinfo);

//  %[$][flags][width][.precision][length modifier]conversion

const char* FLAG_CHARS="#0- +";
const char* CONVERSION_CHARS="diouxXeEfFgGaAcspn%";

typedef enum{
	LM_None,
	LM_l,
	LM_ll
	
}LengthModifier;

typedef struct{
	bool zero_pad;

	int width;
	int precision;
	
	LengthModifier len;

	char conversion;
}format_info;

const char* parse_dec_num(const char* beg,uint64_t* out){
	*out=0;
	while(isdigit(*beg)){
		*out=(*out)*10+*beg-'0';
		beg++;
	}
	return beg;
}

const char* parse_format(const char*fmt,va_list ap,format_info* out){
	assert(*fmt=='%');fmt++;
	memset(out, 0, sizeof(*out));
	if(*fmt=='0'){
		out->zero_pad=true;
		fmt++;
	}
	if(isdigit(*fmt)){
		uint64_t width;
		fmt=parse_dec_num(fmt, &width);
		out->width=width;
	}
	out->len=LM_None;
	if(*fmt=='l'){
		if(*(fmt+1)=='l'){
			out->len=LM_ll;
			fmt++;
		}
		else out->len=LM_l;
		fmt++;
	}
	out->conversion=*fmt;
	fmt++;
	return fmt;
}

typedef struct {
	putch_func f_putch;
	void* exinfo;
	format_info fmt;
}print_ctx;

static bool put_withpad(const print_ctx* ctx,int* cnt,const char* s,size_t len){
#define _putch(c) do{\
	if(!ctx->f_putch(c,ctx->exinfo))return false;\
	cnt++;\
}while(0)

	int width=ctx->fmt.width;
	char pad=ctx->fmt.zero_pad?'0':' ';
	const char* send=s+len;

	while (len<width) {
		_putch(pad);
		width--;
	}
	while (s!=send) {
		_putch(*s);
		s++;
	}
	return true;
}

static bool put_snum(const print_ctx* ctx,int* cnt,int64_t d){
	if(d<0){
	    _putch('-');
	    // When d=INT_MIN
	    // -d is overflow
	}
	char buf[64];
	char* end=buf+sizeof(buf);
	char* p=end;
	int tmp;

	do{
	    p--;
	    tmp=d%10;
	    // avoid -INT_MIN overflow
	    if(tmp<0)tmp=-tmp;
	    *p='0'+tmp;
	    d/=10;
	}while(d);


	return put_withpad(ctx,cnt, p, end-p);
}
static bool put_unum(const print_ctx* ctx,int* cnt,uint64_t u,int base,bool upper){
	char buf[64];
	const char* table_low="0123456789abcdef";
	const char* table_up="0123456789ABCDEF";
	const char* table=upper?table_up:table_low;

	char* end=buf+sizeof(buf);
	char* p=end;
	
	do{
		p--;
		*p=table[u%base];
		u/=base;
	}while(u);

	return put_withpad(ctx,cnt, p, end-p);
}


#define Panic(fmt,...) do{\
	char buf[100];\
	sprintf(buf,fmt,__VA_ARGS__);\
	panic(buf);\
}while(0)


static int meta_printf(putch_func f_putch,void* exinfo,const char *fmt, va_list ap){
	int cnt=0;

	print_ctx _ctx;
	_ctx.f_putch=f_putch;
	_ctx.exinfo=exinfo;
	print_ctx* ctx=&_ctx;

#define _callwithctx(func,...) do{\
	if(!func(ctx,&cnt,__VA_ARGS__))return cnt;\
}while(0)

#define _putpadstr(s,len) _callwithctx(put_withpad,s,len)

#define _load_vlen_var(var,sign) do{\
	switch (ctx->fmt.len) {\
		 case LM_None:var=va_arg(ap,sign int);break;\
		 case LM_l:var=va_arg(ap,sign long);break;\
		 case LM_ll:var=va_arg(ap,sign long long);break;\
		 default:Panic("printf unimpl LengthModifier %d",ctx->fmt.len);break;\
	}\
}while(0)

	while(*fmt){
		if(*fmt=='%'){
			fmt=parse_format(fmt, ap, &ctx->fmt);
			char conversion=ctx->fmt.conversion;
			switch(conversion){
				case 'c':{
					char ch=va_arg(ap,int);
					_putpadstr(&ch, 1);
					break;
						 }
				case 's':{
					 const char* str=va_arg(ap,const char*);
					 _putpadstr(str, strlen(str));
					break;
						 }
				case 'd':{
					 int64_t d;
					_load_vlen_var(d, signed);
					 _callwithctx(put_snum, d);
					break;
						 }
				case 'o':
				case 'u':
				case 'x':
				case 'X':{
					 uint64_t u;
					_load_vlen_var(u, unsigned);
					 int base=(conversion=='u')?10
						 :(conversion=='o')?8
						 :16;
					 _callwithctx(put_unum,u,base,conversion=='X');
					 break;
						 }
							 
				default:{
							Panic("printf unimpl conversion '%c'",*fmt);
						}
			}
		}
		else{
			_putch(*fmt);
			fmt++;
		}
	}
	return cnt;
}

static bool printf_putch(int ch,void* v){
	putch(ch);
	return true;
}
int printf(const char *fmt, ...) {
	va_list ap;
	va_start(ap,fmt);
	int cnt=meta_printf(printf_putch,NULL,fmt,ap);
	va_end(ap);
	return cnt;
}

static bool sprintf_putch_to_str(int c,void* p){
	char** pout=(char**)p;
	char* out=*pout;
	*out=c;
	*pout=*pout+1;
	return true;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
	char* cur=out;
	int cnt=meta_printf(sprintf_putch_to_str, &cur, fmt, ap);
	sprintf_putch_to_str(0, &cur);
	return cnt;
}
int sprintf(char *out, const char *fmt, ...) {
	va_list ap;
	va_start(ap,fmt);
	int cnt=vsprintf(out, fmt, ap);
	va_end(ap);
	return cnt;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
	panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
	panic("Not implemented");
}

#endif
