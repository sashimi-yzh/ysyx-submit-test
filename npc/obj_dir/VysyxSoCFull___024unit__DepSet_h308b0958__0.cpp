// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull__Syms.h"
#include "VysyxSoCFull___024unit.h"

extern "C" void ebreak();

VL_INLINE_OPT void VysyxSoCFull___024unit____Vdpiimwrap_ebreak_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VysyxSoCFull___024unit____Vdpiimwrap_ebreak_TOP____024unit\n"); );
    // Body
    ebreak();
}

extern "C" void difftest_next_step(char difftest_check);

VL_INLINE_OPT void VysyxSoCFull___024unit____Vdpiimwrap_difftest_next_step_TOP____024unit(CData/*7:0*/ difftest_check) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VysyxSoCFull___024unit____Vdpiimwrap_difftest_next_step_TOP____024unit\n"); );
    // Body
    char difftest_check__Vcvt;
    for (size_t difftest_check__Vidx = 0; difftest_check__Vidx < 1; ++difftest_check__Vidx) difftest_check__Vcvt = difftest_check;
    difftest_next_step(difftest_check__Vcvt);
}

extern "C" void difftest_skip();

VL_INLINE_OPT void VysyxSoCFull___024unit____Vdpiimwrap_difftest_skip_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VysyxSoCFull___024unit____Vdpiimwrap_difftest_skip_TOP____024unit\n"); );
    // Body
    difftest_skip();
}

extern "C" void reg_return_value(int gpr_0, int gpr_1, int gpr_2, int gpr_3, int gpr_4, int gpr_5, int gpr_6, int gpr_7, int gpr_8, int gpr_9, int gpr_10, int gpr_11, int gpr_12, int gpr_13, int gpr_14, int gpr_15, int pc, int csr_reg_0, int csr_reg_1, int csr_reg_2, int csr_reg_3);

VL_INLINE_OPT void VysyxSoCFull___024unit____Vdpiimwrap_reg_return_value_TOP____024unit(IData/*31:0*/ gpr_0, IData/*31:0*/ gpr_1, IData/*31:0*/ gpr_2, IData/*31:0*/ gpr_3, IData/*31:0*/ gpr_4, IData/*31:0*/ gpr_5, IData/*31:0*/ gpr_6, IData/*31:0*/ gpr_7, IData/*31:0*/ gpr_8, IData/*31:0*/ gpr_9, IData/*31:0*/ gpr_10, IData/*31:0*/ gpr_11, IData/*31:0*/ gpr_12, IData/*31:0*/ gpr_13, IData/*31:0*/ gpr_14, IData/*31:0*/ gpr_15, IData/*31:0*/ pc, IData/*31:0*/ csr_reg_0, IData/*31:0*/ csr_reg_1, IData/*31:0*/ csr_reg_2, IData/*31:0*/ csr_reg_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VysyxSoCFull___024unit____Vdpiimwrap_reg_return_value_TOP____024unit\n"); );
    // Body
    int gpr_0__Vcvt;
    for (size_t gpr_0__Vidx = 0; gpr_0__Vidx < 1; ++gpr_0__Vidx) gpr_0__Vcvt = gpr_0;
    int gpr_1__Vcvt;
    for (size_t gpr_1__Vidx = 0; gpr_1__Vidx < 1; ++gpr_1__Vidx) gpr_1__Vcvt = gpr_1;
    int gpr_2__Vcvt;
    for (size_t gpr_2__Vidx = 0; gpr_2__Vidx < 1; ++gpr_2__Vidx) gpr_2__Vcvt = gpr_2;
    int gpr_3__Vcvt;
    for (size_t gpr_3__Vidx = 0; gpr_3__Vidx < 1; ++gpr_3__Vidx) gpr_3__Vcvt = gpr_3;
    int gpr_4__Vcvt;
    for (size_t gpr_4__Vidx = 0; gpr_4__Vidx < 1; ++gpr_4__Vidx) gpr_4__Vcvt = gpr_4;
    int gpr_5__Vcvt;
    for (size_t gpr_5__Vidx = 0; gpr_5__Vidx < 1; ++gpr_5__Vidx) gpr_5__Vcvt = gpr_5;
    int gpr_6__Vcvt;
    for (size_t gpr_6__Vidx = 0; gpr_6__Vidx < 1; ++gpr_6__Vidx) gpr_6__Vcvt = gpr_6;
    int gpr_7__Vcvt;
    for (size_t gpr_7__Vidx = 0; gpr_7__Vidx < 1; ++gpr_7__Vidx) gpr_7__Vcvt = gpr_7;
    int gpr_8__Vcvt;
    for (size_t gpr_8__Vidx = 0; gpr_8__Vidx < 1; ++gpr_8__Vidx) gpr_8__Vcvt = gpr_8;
    int gpr_9__Vcvt;
    for (size_t gpr_9__Vidx = 0; gpr_9__Vidx < 1; ++gpr_9__Vidx) gpr_9__Vcvt = gpr_9;
    int gpr_10__Vcvt;
    for (size_t gpr_10__Vidx = 0; gpr_10__Vidx < 1; ++gpr_10__Vidx) gpr_10__Vcvt = gpr_10;
    int gpr_11__Vcvt;
    for (size_t gpr_11__Vidx = 0; gpr_11__Vidx < 1; ++gpr_11__Vidx) gpr_11__Vcvt = gpr_11;
    int gpr_12__Vcvt;
    for (size_t gpr_12__Vidx = 0; gpr_12__Vidx < 1; ++gpr_12__Vidx) gpr_12__Vcvt = gpr_12;
    int gpr_13__Vcvt;
    for (size_t gpr_13__Vidx = 0; gpr_13__Vidx < 1; ++gpr_13__Vidx) gpr_13__Vcvt = gpr_13;
    int gpr_14__Vcvt;
    for (size_t gpr_14__Vidx = 0; gpr_14__Vidx < 1; ++gpr_14__Vidx) gpr_14__Vcvt = gpr_14;
    int gpr_15__Vcvt;
    for (size_t gpr_15__Vidx = 0; gpr_15__Vidx < 1; ++gpr_15__Vidx) gpr_15__Vcvt = gpr_15;
    int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    int csr_reg_0__Vcvt;
    for (size_t csr_reg_0__Vidx = 0; csr_reg_0__Vidx < 1; ++csr_reg_0__Vidx) csr_reg_0__Vcvt = csr_reg_0;
    int csr_reg_1__Vcvt;
    for (size_t csr_reg_1__Vidx = 0; csr_reg_1__Vidx < 1; ++csr_reg_1__Vidx) csr_reg_1__Vcvt = csr_reg_1;
    int csr_reg_2__Vcvt;
    for (size_t csr_reg_2__Vidx = 0; csr_reg_2__Vidx < 1; ++csr_reg_2__Vidx) csr_reg_2__Vcvt = csr_reg_2;
    int csr_reg_3__Vcvt;
    for (size_t csr_reg_3__Vidx = 0; csr_reg_3__Vidx < 1; ++csr_reg_3__Vidx) csr_reg_3__Vcvt = csr_reg_3;
    reg_return_value(gpr_0__Vcvt, gpr_1__Vcvt, gpr_2__Vcvt, gpr_3__Vcvt, gpr_4__Vcvt, gpr_5__Vcvt, gpr_6__Vcvt, gpr_7__Vcvt, gpr_8__Vcvt, gpr_9__Vcvt, gpr_10__Vcvt, gpr_11__Vcvt, gpr_12__Vcvt, gpr_13__Vcvt, gpr_14__Vcvt, gpr_15__Vcvt, pc__Vcvt, csr_reg_0__Vcvt, csr_reg_1__Vcvt, csr_reg_2__Vcvt, csr_reg_3__Vcvt);
}

extern "C" void flash_read(int addr, int* data);

VL_INLINE_OPT void VysyxSoCFull___024unit____Vdpiimwrap_flash_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ &data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VysyxSoCFull___024unit____Vdpiimwrap_flash_read_TOP____024unit\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int data__Vcvt;
    flash_read(addr__Vcvt, &data__Vcvt);
    data = data__Vcvt;
}
