#include <am.h>
#include <klib-macros.h>
#include <klib.h>

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

void _trm_init() {
	ioe_init();
  	int ret = main(mainargs);
  	halt(ret);
}

extern char	_sdata, _edata, _data_lma_start;

void _bootloader()	{
	// data section
	size_t	data_size = (&_edata - &_sdata)	/ sizeof(uint32_t)	;
	uint32_t *tmp = (uint32_t *)&_sdata;
	uint32_t *s = (uint32_t *)&_data_lma_start;
	while (data_size--)
		*tmp++ = *s++;

	_trm_init();
}


