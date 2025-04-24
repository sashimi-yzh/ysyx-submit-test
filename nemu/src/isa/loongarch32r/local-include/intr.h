#ifndef __LOONGARCH32R_INTR_H__
#define __LOONGARCH32R_INTR_H__

#include <common.h>

#define TLB_REFILL 0x3f

#define MEM_OK 0

word_t isa_raise_intr(uint32_t NO, vaddr_t epc);

#endif

