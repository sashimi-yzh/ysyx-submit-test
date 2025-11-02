#ifndef DIFFTEST_H
#define DIFFTEST_H

#include <iostream>
#include <stdint.h>
#include <cassert>
#include <dlfcn.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "VysyxSoCFull.h"
#include <include/auto.h>


#define RESET_VECTOR 0x80000000
#define NPC_TO_NEMU 1
#define NEMU_TO_NPC 0

#define NR_GPR 32


struct npc_context_t{
    uint32_t gpr[NR_GPR];
    uint32_t pc;
};


void init_difftest(const char* ref_so_file, long img_size, int port);
void difftest_step();


#endif

