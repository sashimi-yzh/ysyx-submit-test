#ifndef __MEM_H__
#define __MEM_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <common.h>
#include <device.h>

#define REGNUM 32
#define REAL_REGNUM 16//for difftest

extern uint32_t gpr[REGNUM];
extern uint32_t csr[4];
extern const char *regs[];


uint8_t* guest_to_host(paddr_t paddr);

void get_reg();
void isa_reg_display();
word_t isa_reg_str2val(const char *s, bool *success);





void init_pmem();

void init_flash();
void init_sdram();

void init_mrom();
void init_psram();

#endif
