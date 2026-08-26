// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vvga.h for the primary calling header

#ifndef VERILATED_VVGA___024ROOT_H_
#define VERILATED_VVGA___024ROOT_H_  // guard

#include "verilated.h"


class Vvga__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vvga___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(vsync,0,0);
    VL_OUT8(hsync,0,0);
    VL_OUT8(valid,0,0);
    VL_OUT8(vga_r,7,0);
    VL_OUT8(vga_g,7,0);
    VL_OUT8(vga_b,7,0);
    CData/*0:0*/ vga__DOT__u_vga_ctrl__DOT__h_valid;
    CData/*0:0*/ vga__DOT__u_vga_ctrl__DOT__v_valid;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    SData/*9:0*/ vga__DOT__u_rom__DOT__v_addr;
    SData/*9:0*/ vga__DOT__u_rom__DOT__h_addr;
    SData/*9:0*/ vga__DOT__u_vga_ctrl__DOT__x_cnt;
    SData/*9:0*/ vga__DOT__u_vga_ctrl__DOT__y_cnt;
    SData/*9:0*/ __Vdly__vga__DOT__u_vga_ctrl__DOT__x_cnt;
    IData/*23:0*/ vga__DOT__vga_data;
    IData/*18:0*/ vga__DOT__u_rom__DOT__addr_reg;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*23:0*/, 307200> vga__DOT__u_rom__DOT__rom;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vvga__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vvga___024root(Vvga__Syms* symsp, const char* v__name);
    ~Vvga___024root();
    VL_UNCOPYABLE(Vvga___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
