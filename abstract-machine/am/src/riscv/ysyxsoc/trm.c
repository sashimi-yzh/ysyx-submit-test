#include <am.h>
#include <klib-macros.h>
#include <klib.h>

// SPI
#define SPI_MASTER_BASE_ADDR	0x10001000
#define	SPI_TX 		(*(volatile	uint32_t	*)(SPI_MASTER_BASE_ADDR	+	0x04))
#define	SPI_RX 		(*(volatile	uint32_t	*)(SPI_MASTER_BASE_ADDR	+	0x00))
#define	SPI_CRTL	(*(volatile	uint32_t	*)(SPI_MASTER_BASE_ADDR	+	0x10))
#define TX_NEG		(uint32_t)(1	<<	10)
#define SPI_LSB		(uint32_t)(1	<<	11)
#define GO_BSY		(uint32_t)(1	<<	8)
#define	SPI_DIV 	(*(volatile	uint32_t	*)(SPI_MASTER_BASE_ADDR	+	0x14))
#define	SPI_SS 		(*(volatile	uint32_t	*)(SPI_MASTER_BASE_ADDR	+	0x18))

extern char _heap_start;
extern char _heap_end;
Area heap = RANGE(&_heap_start, &_heap_end);

int main(const char *args);

#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void halt(int code) {
	asm volatile("mv a0, %0; ebreak" : :"r"(code));
	// should not reach here
  	while (1);
}

// extern char _data_start, _data_end, _data_lma_start;
// void bootloader(void) {
//     // 计算 .data 段的大小
//     size_t data_size = &_data_end - &_data_start;
//     // 使用 memcpy 将 .data 段从 MROM 加载到 SRAM
//     memcpy(&_data_start, &_data_lma_start, data_size);
// }

void SPI_Init() {
	SPI_DIV		=	0x0	;
	SPI_CRTL	=	(0x40)	+	TX_NEG	;
}

void _trm_init() {
	ioe_init();
    SPI_Init();
  	int ret = main(mainargs);
  	halt(ret);
}

extern char	_stext, _etext, _text_lma_start;
extern char	_srodata, _erodata, _rodata_lma_start;
extern char	_sdata, _edata, _data_lma_start;

void __attribute__((section(".bootloader"))) _bootloader()	{
	// text section
	size_t	text_size = (&_etext - &_stext)	/ sizeof(uint32_t)	;
	uint32_t *tmp = (uint32_t *)&_stext;
	uint32_t *s = (uint32_t *)&_text_lma_start;
	while (text_size--)
		*tmp++ = *s++;

	// rodata section
	size_t	rodata_size = (&_erodata - &_srodata)	/ sizeof(uint32_t)	;
	tmp = (uint32_t *)&_srodata;
	s = (uint32_t *)&_rodata_lma_start;
	while (rodata_size--)
		*tmp++ = *s++;

	// data section
	size_t	data_size = (&_edata - &_sdata)	/ sizeof(uint32_t)	;
	tmp = (uint32_t *)&_sdata;
	s = (uint32_t *)&_data_lma_start;
	while (data_size--)
		*tmp++ = *s++;

	_trm_init();
}

// extern char _data_end, _stext, _app_lma_start;

// void __attribute__((section(".bootloader"))) _bootloader()	{
// 	size_t	data_size = (&_data_end - &_stext)	/ sizeof(uint32_t)	;
// 	uint32_t *tmp = (uint32_t *)&_stext;
// 	const uint32_t *s = (const uint32_t *)&_app_lma_start;
// 	while (data_size--)
// 		*tmp++ = *s++;
// 	_trm_init();
// }

extern char	_siflash_ssbl, _eiflash_ssbl, _ssbl_lma_start;

void __attribute__((section(".fsbl"))) _fsbl_init()	{
	size_t	data_size = &_eiflash_ssbl - &_siflash_ssbl;
	char *tmp = &_siflash_ssbl;
	const char *s = &_ssbl_lma_start;
	while (data_size--)
		*tmp++ = *s++;
	_bootloader();
}

// uint32_t flash_read(uint32_t addr) {
// 	SPI_SS		=	0x1	;
// 	SPI_TX		=	(0x03	<<	24)	+	addr;
// 	SPI_CRTL	|=	GO_BSY;
// 	while (SPI_CRTL	&	GO_BSY);
// 	SPI_SS		=	0x0	;
// 	return SPI_RX	;
// }

// uint32_t flash_XIP_read(uint32_t addr) {
// 	return *(volatile uint32_t *)addr	;
// }




