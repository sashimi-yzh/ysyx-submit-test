#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include "../ysyxsoc/include/ysyxsoc.h"

extern char _heap_start;

extern char _ssbl_lma, _ssbl, _essbl;
extern char _text_lma, _text, _etext;
extern char _rodata_lma, _rodata, _erodata;
extern char _data_lma, _data, _edata;
extern char _bss, _ebss;
extern char _stack_top;
extern char _sdram_start, _sdram_end;
extern char _psram_end;
int main(const char *args);

extern char _sram_start;
#define SRAM_SIZE (8 * 1024)
#define SRAM_END  ((uintptr_t)&_sram_start + SRAM_SIZE)

Area heap = RANGE(&_heap_start, &_psram_end);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void putch(char ch) {
	// if(*(volatile char *)UART_LCR == 0x03){
	// 	while(!(*(volatile char *)UART_LSR & 0x20));
	// }
	// outb(UART_TX, ch);
  while ((inb(UART_LSR) & 0x20) == 0);//等待发送缓冲区空
  outb(UART_TX, ch);
}

static void uart_init(){
	outb(UART_LCR, inb(UART_LCR) | 0x80); //LCR寄存器最高位，使能分频系数寄存器
	outb(UART_LSB, 0x01);
	outb(UART_LCR, inb(UART_LCR) & 0x7f); //恢复LCR寄存器的值，关闭分频系数寄存器，可正常收发数据
	outb(UART_IER, 0xc7);
}

// static void uart_init(uint32_t baud_rate) {
// 	uint16_t divisor = (uint16_t)(50000000 / (baud_rate * 16)); //50MHz工作时钟，每比特周期采样16次（因子）
// 	outb(UART_LCR, 0x80 | inb(UART_LCR)); // enable divisor latch
// 	outb(UART_MSB, 0xff & (divisor >> 8));
// 	outb(UART_LSB, 0xff & divisor); 
// 	outb(UART_LCR, inb(UART_LCR) & 0x7f); // resume	
// }

void halt(int code) {
  ysyxsoc_trap(code);
  while (1);
}

void ysyx_show(){
	// TODO:
	// mvendorid - 从中读出ysyx的ASCII码, 即0x79737978(厂商ID寄存器)(CSR地址：0xF11)
	// marchid - 从中读出学号数字部分的十进制表示, 学号为ysyx_25010030, 则读出25010030, 即0x17d9f6e(架构ID寄存器)(CSR地址：0xF12)
	uint32_t mvendorid, marchid;
	uint32_t temp, index = 0;
	char buf[10];
	asm volatile("csrr %0, mvendorid" : "=r"(mvendorid));
	asm volatile("csrr %0, marchid" : "=r"(marchid));
	for(int i = 3; i >= 0; i--){
		putch((char)((mvendorid >> i * 8) & 0xff));
	}
	temp = marchid;
	while(temp > 0){
		buf[index++] = (temp % 10) + '0';
		temp /= 10;
	}
	for(int i = index - 1; i >= 0; i--) putch(buf[i]);
	putch('\n');
}

void _trm_init() {
//   uart_init(115200);
  uart_init();

//   bootloader();

  int ret = main(mainargs);
  halt(ret);
}

// void __attribute__((section(".ssbl")))_bootloader(void){
// 	//flash .text --> RAM .text
// 	char *src = &_text_lma;
// 	char *dst = &_text;
// 	while(dst < &_etext)
// 		*dst++ = *src++;

// 	//flash .data --> RAM .data(用于初始化RAM)

// 	// flash是只读的，变量运行时需要在RAM中可读写
// 	// linker-ysyxsoc.ld只负责把初值放在flash，运行时需要手动搬运到RAM
// 	src = &_data_lma;
// 	dst = &_data;
// 	while(dst < &_edata)
// 		*dst++ = *src++;

// 	_trm_init();
// }

// void __attribute((section(".fsbl")))_fsbl_init(void) {
// 	char *src = &_ssbl_lma;
// 	char *dst = &_ssbl;
// 	while(dst < &_essbl)
// 		*dst++ = *src++;

// 	_bootloader();
// }
