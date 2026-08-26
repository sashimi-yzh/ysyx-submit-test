#ifndef __MEM_H__
#define __MEM_H__
#include "common.h"
#include "Vtop__Dpi.h"
#include "svdpi.h"
#define MEM(addr) MEM[(addr - PMEM_LEFT)>>2]
extern uint32_t MEM[CONFIG_MSIZE>>2];
void pmem_write(int waddr, int wdata, char wmask);
int pmem_read(int raddr);
bool check_pmem_bound(uint32_t addr);
#endif