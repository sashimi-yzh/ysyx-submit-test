#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <riscv/riscv.h>
#include <ysyxsoc.h>

#define ysyxsoc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

extern char _stext_rom, _etext_rom;
extern char _srodata_rom, _erodata_rom;
extern char _sdata_rom, _edata_rom;
extern char _stext_ram, _etext_ram;
extern char _srodata_ram, _erodata_ram;
extern char _sdata_ram, _edata_ram;

extern char _heap_start;
extern char _heap_end;

Area heap = RANGE((uintptr_t)&_heap_start, (uintptr_t)&_heap_end);

int main(const char *args);

static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS


//outb和inb定义于riscv.h
void putch(char ch){
	//注意LSR第五位指示FIFO是否还有空位
	//while(!(*(volatile char *)(UART_BASE + UART_LSR) & (char)0x20));
    //*(volatile char *)(UART_BASE + UART_TX) = ch;
	while(!(inb(UART_BASE + UART_LSR) & (char)0x20));
	outb(UART_BASE + UART_TX, ch);
}

char getch(){
	//if(*(volatile char *)(UART_BASE + UART_LSR) & (char)0x01)//接收到数据
	//	return *(volatile char*)(UART_BASE + UART_RX);
	//else
	//	return (char)0xff;
	if(inb(UART_BASE + UART_LSR) & (char)0x01)
		return inb(UART_BASE + UART_RX);
	else
		return (char)0xff;
}

void bootloader(){
	size_t i;
	//从rom向ram拷贝数据,模拟bootloader
    //拷贝text段
	size_t length_text = (size_t)&_etext_rom - (size_t)&_stext_rom;
	size_t dest_text = (size_t)&_stext_ram;
	size_t src_text = (size_t)&_stext_rom;
	for(i = 0; i < length_text; i++){
		*((char *)(dest_text + i)) = *((char *)(src_text + i));
	}

	//拷贝rodata段
	size_t length_rodata = (size_t)&_erodata_rom - (size_t)&_srodata_rom;
    size_t dest_rodata = (size_t)&_srodata_ram;
    size_t src_rodata = (size_t)&_srodata_rom;
    for(i = 0; i < length_rodata; i++){
      *((char *)(dest_rodata + i)) = *((char *)(src_rodata + i));
    }

	//拷贝data段
	size_t length_data = (size_t)&_edata_rom - (size_t)&_sdata_rom;
    size_t dest_data = (size_t)&_sdata_ram;
    size_t src_data = (size_t)&_sdata_rom;
    for(i = 0; i < length_data; i++){
      *((char *)(dest_data + i)) = *((char *)(src_data + i));
    }
}


void init_uart(){
	*(volatile char *)(UART_BASE + UART_LCR) = (char)0x83;//1000_0011
	//*(volatile short *)(UART_BASE + UART_DLB1) = 0x0200;
	//*(volatile char *)(UART_BASE + UART_DLB1) = (char)'A';//0000_0000
	*(volatile char *)(UART_BASE + UART_DLB2) = (char)0x00;//0000_0100
	*(volatile char *)(UART_BASE + UART_DLB1) = (char)0x01;//0000_0000
	//设置为16'b0000_0100_0000_0000,即1024
	*(volatile char *)(UART_BASE + UART_LCR) = (char)0x03;//0000_0011,恢复默认值
	printf("init_uart in trm.c\n");//注意只能在初始化完毕后才能输出信息
}


//unsigned int mvendorid,marchid;
void csrr_id(){
	//printf("csrr_id in trm.c\n");
	unsigned int mvendorid, marchid;
    asm volatile("csrr %0, mvendorid" : "=r"(mvendorid));
    asm volatile("csrr %0, marchid" : "=r"(marchid));

    char c0 = (char)(mvendorid & 0x000000ff);
    char c1 = (char)((mvendorid & 0x0000ff00) >> 8);
    char c2 = (char)((mvendorid & 0x00ff0000) >> 16);
    char c3 = (char)((mvendorid & 0xff000000) >> 24);
    const char vendor[5] = {c3, c2, c1, c0, '\0'};
	//putch(c3); putch(c2); putch(c1); putch(c0); putch('\n');
    printf("vendorid: %s, archid: %d\n", vendor, marchid);
}

void halt(int code){
    ysyxsoc_trap(code);
    while(1);
}


void _trm_init(){
	//从rom向ram拷贝数据,模拟bootloader
	//size_t length = (size_t)&_edata_rom - (size_t)&_sdata_rom;
	//size_t dest = (size_t)&_sdata_ram;
	//size_t src = (size_t)&_sdata_rom;
    //size_t i;
	//for(i = 0; i < length; i++){
	//	*((char *)(dest + i)) = *((char *)(src + i));
	//}
	
	//bootloader();
	
	//初始化串口
	init_uart();

	//读出ysyx和学号
	csrr_id();

	int ret = main(mainargs);
    halt(ret);
}
