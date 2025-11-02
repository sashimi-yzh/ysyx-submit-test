//re-resign difftest by Jason @ 2025.10.11

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


#define RESET_VECTOR 0x30000000
#define NPC_TO_NEMU 1
#define NEMU_TO_NPC 0

#define NR_GPR 16


struct npc_context_t{
    int32_t gpr[NR_GPR];
    int32_t pc;
};


void init_difftest(const char* ref_so_file, long img_size, int port);
void difftest_step();


#endif

