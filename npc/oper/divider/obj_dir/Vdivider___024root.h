// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdivider.h for the primary calling header

#ifndef VERILATED_VDIVIDER___024ROOT_H_
#define VERILATED_VDIVIDER___024ROOT_H_  // guard

#include "verilated.h"

class Vdivider__Syms;

class Vdivider___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(is_signed,0,0);
    VL_OUT8(valid,0,0);
    CData/*0:0*/ divider__DOT__quotient_sign;
    CData/*0:0*/ divider__DOT__remainder_sign;
    CData/*5:0*/ divider__DOT__cycle_count;
    CData/*0:0*/ divider__DOT__computing;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_IN(dividend,31,0);
    VL_IN(divisor,31,0);
    VL_OUT(quotient,31,0);
    VL_OUT(remainder,31,0);
    IData/*31:0*/ divider__DOT__abs_divisor;
    IData/*31:0*/ divider__DOT__temp_quotient;
    IData/*31:0*/ divider__DOT__pos_mask;
    IData/*31:0*/ divider__DOT__unnamedblk1__DOT__next_remainder;
    IData/*31:0*/ divider__DOT__unnamedblk1__DOT__next_quotient;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ divider__DOT__temp_dividend;
    QData/*63:0*/ divider__DOT__unnamedblk1__DOT__temp_dividend_shifted;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdivider__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdivider___024root(Vdivider__Syms* symsp, const char* v__name);
    ~Vdivider___024root();
    VL_UNCOPYABLE(Vdivider___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
