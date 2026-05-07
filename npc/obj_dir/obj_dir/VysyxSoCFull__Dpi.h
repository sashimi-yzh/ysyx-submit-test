// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYXSOCFULL__DPI_H_
#define VERILATED_VYSYXSOCFULL__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/yanlx/ysyx-workbench/npc/vsrc/ysyx_25050137.v:12:34
    extern void difftest_next_step(char difftest_check);
    // DPI import at /home/yanlx/ysyx-workbench/npc/vsrc/ysyx_25050137.v:13:34
    extern void difftest_skip();
    // DPI import at /home/yanlx/ysyx-workbench/npc/vsrc/ysyx_25050137.v:11:34
    extern void ebreak();
    // DPI import at /home/yanlx/ysyx-workbench/ysyxSoC/perip/flash/flash.v:84:30
    extern void flash_read(int addr, int* data);
    // DPI import at /home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v:6723:30
    extern void mrom_read(int raddr, int* rdata);
    // DPI import at /home/yanlx/ysyx-workbench/npc/vsrc/ysyx_25050137.v:14:34
    extern void reg_return_value(int gpr_0, int gpr_1, int gpr_2, int gpr_3, int gpr_4, int gpr_5, int gpr_6, int gpr_7, int gpr_8, int gpr_9, int gpr_10, int gpr_11, int gpr_12, int gpr_13, int gpr_14, int gpr_15, int pc, int csr_reg_0, int csr_reg_1, int csr_reg_2, int csr_reg_3);

#ifdef __cplusplus
}
#endif

#endif  // guard
