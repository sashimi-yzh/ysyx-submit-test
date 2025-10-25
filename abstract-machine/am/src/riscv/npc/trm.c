#include <am.h>
#include <klib-macros.h>
#include "npc.h"
#include "riscv.h"
extern char _heap_start;
extern char _heap_end;
int main(const char *args);
extern char _data_extra_lma[];	   // 数据段额外加载地址(MA)
extern char _data_extra_vma[];	   // 数据段额外运行地址(SA)
extern char _data_extra_vma_end[]; // 数据段额外结束地址(SA
extern char _bss_extra_start[];
extern char _bss_extra_end[];

extern char _data_lma[];	 // 数据段加载地址(MA)
extern char _data_vma[];	 // 数据段运行地址(SA)
extern char _data_vma_end[]; // 数据段结束地址(SA)
extern char _bss_start[];
extern char _bss_end[];
extern char _text_vma[];
extern char _text_vma_end[];
extern char _text_lma[];
extern char _rodata_vma[];
extern char _rodata_vma_end[];
extern char _rodata_lma[];
extern char _loader_vma[];
extern char _loader_vma_end[];
extern char _loader_lma[];
extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : : "r"(code))
Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS
#define UART_BASE 0x10000000
#define UART_SIZE 0x8
void _trm_init();

__attribute__((section("loader"), naked, used)) void _loader()
{
	for (unsigned i = 0; i < _text_vma_end - _text_vma; i++)
	{
		_text_vma[i] = _text_lma[i];
	}
	for (unsigned i = 0; i < _rodata_vma_end - _rodata_vma; i++)
	{
		_rodata_vma[i] = _rodata_lma[i];
	}
	for (unsigned i = 0; i < _data_extra_vma_end - _data_extra_vma; i++)
	{
		_data_extra_vma[i] = _data_extra_lma[i];
	}
	for (unsigned i = 0; i < _data_vma_end - _data_vma; i++)
	{
		_data_vma[i] = _data_lma[i];
	}
	for (char *p = _bss_start; p < _bss_end; p++)
	{
		*p = 0;
	}
	for (char *p = _bss_start; p < _bss_end; p++)
	{
		*p = 0;
	}
	asm volatile("fence.i\n");
	_trm_init();
	// should not reach here
	while (1)
		;
}
__attribute__((section("entry"), naked, used)) void _start()
{
	asm volatile(
		"la sp, _stack_pointer\n"
		"mv s0, zero\n");

	for (unsigned i = 0; i < _loader_vma_end - _loader_vma; i++)
	{
		_loader_vma[i] = _loader_lma[i];
	}
	asm volatile("fence.i\n");
	_loader();
	while (1)
		;
}

void halt(int code)
{
	npc_trap(code);
	while (1)
		;
}
void putch(char ch)
{
	volatile uint8_t *uart = (volatile uint8_t *)UART_BASE;
	*uart = ch;
}
unsigned char getch()
{
	return -1; // 无数据可读
}
void display_message()
{
	unsigned int ysyx, id;
	__asm__ volatile(
		"csrr %0, 0x114\n"
		"csrr %1, 0x514\n"
		: "=r"(ysyx), "=r"(id) // 输出约束
		:					   // 无输入
		:					   // 无破坏寄存器
	);
	for (int i = 0; i < 4; i++)
	{
		putch((ysyx & 0xFF000000) >> 24);
		ysyx <<= 8;
	}
	putch(':');
	char id_str[8];
	for (int i = 0; i < 8; i++)
	{
		unsigned char digit = id % 10;
		id_str[7 - i] = ('0' + digit);
		id /= 10;
	}
	for (int i = 0; i < 8; i++)
	{
		putch(id_str[i]);
	}
	putch('\n');
}
void _trm_init()
{
	display_message();
	int ret = main(mainargs);
	halt(ret);
}
