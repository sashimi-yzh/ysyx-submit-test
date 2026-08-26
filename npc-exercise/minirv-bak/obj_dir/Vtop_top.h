// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_TOP_H_
#define VERILATED_VTOP_TOP_H_  // guard

#include "verilated.h"
class Vtop_GPR;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_top final : public VerilatedModule {
  public:
    // CELLS
    Vtop_GPR* GPR_0;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(LSU_rmask,3,0);
    VL_OUT8(LSU_wmask,3,0);
    VL_OUT8(LSU_WEN,0,0);
    VL_OUT8(LSU_REN,0,0);
    CData/*0:0*/ __VdfgRegularize_he2b63832_0_0;
    CData/*2:0*/ __PVT__clkdiv_0__DOT__cnt;
    CData/*0:0*/ __PVT__IDU_0__DOT__isJALR;
    CData/*0:0*/ __PVT__IDU_0__DOT__isADD;
    CData/*0:0*/ __PVT__IDU_0__DOT__isLW;
    CData/*0:0*/ __PVT__IDU_0__DOT__isLBU;
    CData/*0:0*/ __PVT__IDU_0__DOT__isLB;
    CData/*0:0*/ __PVT__IDU_0__DOT__isSW;
    CData/*0:0*/ __PVT__IDU_0__DOT__isSB;
    CData/*0:0*/ __PVT__IDU_0__DOT__isLOAD;
    CData/*0:0*/ __PVT__IDU_0__DOT__isWRITE;
    CData/*0:0*/ __PVT__IDU_0__DOT__isI;
    CData/*0:0*/ IDU_0__DOT____VdfgRegularize_h52656aab_0_4;
    CData/*0:0*/ IDU_0__DOT____VdfgRegularize_h52656aab_0_5;
    CData/*0:0*/ IDU_0__DOT____VdfgRegularize_h52656aab_0_6;
    VL_OUT(LSU_address,31,0);
    VL_OUT(LSU_writedata,31,0);
    VL_OUT(LSU_readdata,31,0);
    VL_OUT(PC_command,31,0);
    VL_OUT(EXU_inA,31,0);
    VL_OUT(EXU_inB,31,0);
    VL_OUT(EXU_data,31,0);
    IData/*31:0*/ PC;
    IData/*31:0*/ dnpc;
    IData/*31:0*/ snpc;
    IData/*31:0*/ __PVT__command;
    IData/*31:0*/ __PVT__rs1_val;
    IData/*31:0*/ __PVT__LSU_0__DOT__val0;
    IData/*31:0*/ __PVT__LSU_0__DOT__val1;
    IData/*31:0*/ __PVT__LSU_0__DOT__val2;
    IData/*31:0*/ __PVT__LSU_0__DOT__rdata4;
    IData/*31:0*/ __Vfunc_pmem_read__1__Vfuncout;
    IData/*31:0*/ __Vfunc_pmem_read__2__Vfuncout;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_top(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_top();
    VL_UNCOPYABLE(Vtop_top);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
