#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include "VysyxSoCFull.h"
#include "verilated.h"
#include "svdpi.h"
#include "VysyxSoCFull__Dpi.h"
#include "./include/common.h"

#ifdef CONFIG_MTRACE
  extern char *mtrace_p;
#endif

static uint64_t us = 0;
int pmem_read(int raddr) {
  // 总是读取地址为`raddr & ~0x3u`的4字节返回
	raddr = raddr & ~0x3u;
	uint32_t result;
#ifdef CONFIG_DEVICE
	if (raddr == 0xa000004c) {
		#ifdef CONFIG_DIFFTEST
			difftest_skip_ref();
		#endif
		us = get_time();
		result = us >> 32;
	}
	else if(raddr == 0xa0000048) {
		#ifdef CONFIG_DIFFTEST
			difftest_skip_ref();
		#endif
		result = (uint32_t)us;
	}
	else {
		result = paddr_read(raddr, 4);
	}
#else
	result = paddr_read(raddr, 4);
#endif
#ifdef CONFIG_MTRACE
	extern uint8_t fopcode;
	if(fopcode == 0b0000011) {
		mtrace_p += sprintf(mtrace_p, "raddr:%08x read:%08x\n", raddr, result);
	}
#endif
	return result;
}
void pmem_write(int waddr, int wdata, char wmask) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
	waddr = waddr & ~0x3u;
#ifdef CONFIG_MTRACE
		mtrace_p += sprintf(mtrace_p, "waddr:%08x write:%08x\n", waddr, wdata);
#endif
#ifdef CONFIG_DEVICE
	if(waddr == 0xa00003f8) {
		#ifdef CONFIG_DIFFTEST
			difftest_skip_ref();
		#endif
		putchar((char)wdata);
		//putc((char)wdata, stderr);
		return;
	}
#endif
	switch(wmask) {
		case 1:	paddr_write(waddr, 1, wdata); break;
		case 3: paddr_write(waddr, 2, wdata); break;
		case 15: paddr_write(waddr, 4, wdata); break;
		default: break;
	}
}

