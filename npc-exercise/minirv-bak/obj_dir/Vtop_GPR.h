// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_GPR_H_
#define VERILATED_VTOP_GPR_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_GPR final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__rst,0,0);
    VL_IN8(__PVT__addRA,4,0);
    VL_IN8(__PVT__addRB,4,0);
    VL_IN8(__PVT__addW,4,0);
    VL_IN8(__PVT__WEN,0,0);
    VL_OUT(__PVT__outA,31,0);
    VL_OUT(__PVT__outB,31,0);
    VL_IN(__PVT__inData,31,0);
    IData/*31:0*/ __PVT__unnamedblk1__DOT__i;
    VlUnpacked<IData/*31:0*/, 32> GPR;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_GPR(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_GPR();
    VL_UNCOPYABLE(Vtop_GPR);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
