#include <am.h>
#include <my_putnum.h>

void putnum(uint32_t x){
	char buf[16];
	int idx=0;
	if(x==0)buf[idx++]='0';
	while(x>0){
		buf[idx++]=(x%10+'0');
		x/=10;
	}
	idx--;
	for(;idx>=0;idx--)putch(buf[idx]);
}
static void _putnumb2(uint8_t x){
	for(uint8_t m=1<<7;m;m>>=1){
		putch((x&m)?'1':'0');
	}
}
void putnum_base2(uint32_t x){
	if(x>>24){_putnumb2(x>>24);putch('_');}
	if(x>>16){_putnumb2(x>>16);putch('_');}
	if(x>>8){_putnumb2(x>>8);putch('_');}
	_putnumb2(x);
}

void putnum_base16(uint32_t x){
	char buf[8];
	int idx=0;
	if(x==0)buf[idx++]='0';
	while(x){
		uint8_t t=x&0xf;
		if(t<10)buf[idx++]=(t+'0');
		else buf[idx++]=(t-10+'A');
		x>>=4;
	}
	idx--;
	for(;idx>=0;idx--)putch(buf[idx]);
}
