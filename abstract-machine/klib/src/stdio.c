#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stdio.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
int intcatstr(char *str,int64_t num,char fc,int width,int cardinal,int signornot);
int printf(const char *fmt, ...) {
    va_list ap;
    va_start(ap,fmt);
    char str[1024];
    int i=0;
    int num=vsprintf(str,fmt,ap);
    for(i=0;str[i];i++){
        putch(str[i]);
    }
    va_end(ap);
    return num;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
    char *ptr=(char *)fmt;
    int num=0;
    int64_t tmp;
    char *string;
    int flag=0,fc,width,mylong=0,is_signed;
    while(*ptr){
        switch (*ptr) {
            case '%':{
                flag=1;fc=' ';width=0,mylong=0;
                while(flag){
                    ptr++;
                    switch (*ptr) {
                        case '0':if(width<=0){
                                    fc='0';
                                }else{
                                    width=width*10;
                                }
                                break;
                        case 'l':mylong++;break;
                        case 'x':
                        case 'o':
                        case 'd':
                                is_signed = (*ptr == 'd');
                                if (mylong == 0) {
                                    if(is_signed)
                                        tmp = va_arg(ap,int);
                                    else
                                        tmp = va_arg(ap, unsigned int);
                                } else if (mylong == 1) {
                                    if(is_signed)
                                        tmp = va_arg(ap, long);
                                    else
                                        tmp = va_arg(ap, unsigned long);
                                } else {
                                    if(is_signed)
                                        tmp = va_arg(ap, long long);
                                    else 
                                        tmp = va_arg(ap, unsigned long long);
                                }
                                num+=intcatstr(out+num,tmp,fc,width,(*ptr)=='d'?10:((*ptr=='x')?16:8),is_signed);
                                flag=0;
                                break;
                        case 's':string=va_arg(ap,char*);
                                assert(fc==' '&&width==0);
                                strcpy(out+num,string);
                                num+=strlen(string);
                                flag=0;
                                break;
                        case 'c':out[num++]=(char)va_arg(ap,int);
                                assert(fc==' '&&width==0);
                                flag=0;
                                break;
                        case '%':out[num++]='%';
                                flag=0;
                                break;
                        default:if(*ptr>'0'&&*ptr<='9'){
                                    width=width*10+*ptr-'0';
                                    break;
                                }else{
                                    putch('\n');
                                    putch(*ptr);
                                    putch('\n');
                                    assert(0);
                                }
                    }
                }
            }break;
            default:out[num++]=*(ptr);break;
        }
        ptr++;
    }
    out[num]='\0';
    return num;

}

int sprintf(char *out, const char *fmt, ...) {
    int num=0;
    va_list ap;
    va_start(ap,fmt);
    num=vsprintf(out,fmt,ap);
    va_end(ap);
    return num;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}
int intcatstr(char *str,int64_t num,char fc,int width,int cardinal,int signornot){
    int i=0,j=0,is_neg=0,pad_len,total_len;
    uint64_t unum,t;
    int length=num==0?1:0;
    if(num<0&&signornot){
        is_neg=1;
        unum=(uint64_t)-(num+1)+1;
    }else{
        unum=(uint64_t)num;
    }
    t=unum;
    while(t>0){length+=1;t/=cardinal;}
    total_len=length+is_neg;
    pad_len=(width>total_len)?width-total_len:0;
    if(fc==' '){
        for(i=0;i<pad_len;i++){
            *(str++)=fc;
        }
    }
    if(is_neg){
        *(str++)='-';
    }
    if(fc=='0'){
        for(i=0;i<pad_len;i++){
            *(str++)=fc;
        }
    }
    if(num==0){
        *(str++)='0';
        return total_len+pad_len;
    }
    char buf[32];
    i=0;
    while(unum>0){
        uint64_t tmp=unum%cardinal;
        buf[i++]=tmp<10?tmp+'0':tmp+'a'-10;
        unum=unum/cardinal;
    }
    for(j=i-1;j>=0;j--){
        *(str++)=buf[j];
    }
    return total_len+pad_len;
}
#endif
