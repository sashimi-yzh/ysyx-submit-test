#ifndef __DRIVER_H__
#define __DRIVER_H__

#include <macro.h>

#ifdef YSYXSOC
#include "VysyxSoCFull.h"
#include "VysyxSoCFull_CPU.h"
#include "VysyxSoCFull_ysyxSoCASIC.h"
#include "VysyxSoCFull_ysyxSoCFull.h"
#include "VysyxSoCFull_ysyx_23060203.h"
#include "VysyxSoCFull_ysyx_23060203_CPU.h"
#define cpu_module top_module->ysyxSoCFull->asic->cpu->cpu->NPC_CPU
#else
#include "Vysyx_23060203.h"
#include "Vysyx_23060203_ysyx_23060203.h"
#include "Vysyx_23060203_ysyx_23060203_CPU.h"
#define cpu_module top_module->ysyx_23060203->NPC_CPU
#endif

typedef MUXDEF(YSYXSOC, VysyxSoCFull, Vysyx_23060203) Vtop;

extern Vtop *top_module;

void init_top(int argc, char **argv);
void init_wave(const char *filename);
void init_nvboard();
void driver_cycle();
void finalize_driver();
void reset_top();

#endif
