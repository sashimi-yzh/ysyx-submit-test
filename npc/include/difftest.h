#ifndef DIFFTEST_H
#define DIFFTEST_H
#include "common.h"

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

extern void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n,
                                   bool direction);
extern void (*ref_difftest_regcpy)(void *dut, void*pc, bool direction);
extern void (*ref_difftest_exec)(uint64_t n);
extern void (*ref_difftest_raise_intr)(uint64_t NO);

void init_difftest(const char *ref_so_file, int size);
#endif