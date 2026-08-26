// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPS2.h for the primary calling header

#ifndef VERILATED_VPS2___024ROOT_H_
#define VERILATED_VPS2___024ROOT_H_  // guard

#include "verilated.h"


class VPS2__Syms;

class alignas(VL_CACHE_LINE_BYTES) VPS2___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(CLK,0,0);
    VL_IN8(CLRN,0,0);
    VL_OUT8(seg0L,7,0);
    VL_OUT8(seg0H,7,0);
    VL_OUT8(seg1L,7,0);
    VL_OUT8(seg1H,7,0);
    VL_OUT8(seg2L,7,0);
    VL_OUT8(seg2H,7,0);
    VL_OUT8(seg3L,7,0);
    VL_OUT8(seg3H,7,0);
    VL_OUT8(data,7,0);
    VL_IN8(PS2_CLK,0,0);
    VL_IN8(PS2_DAT,0,0);
    CData/*0:0*/ PS2__DOT__ready;
    CData/*0:0*/ PS2__DOT__overflow;
    CData/*0:0*/ PS2__DOT__nextdata_n;
    CData/*7:0*/ PS2__DOT__ascii_out;
    CData/*0:0*/ PS2__DOT__ifPressed;
    CData/*7:0*/ PS2__DOT__count;
    CData/*0:0*/ PS2__DOT__status;
    CData/*0:0*/ PS2__DOT__nextstatus;
    CData/*6:0*/ PS2__DOT____Vcellout__segdec0____pinNumber2;
    CData/*6:0*/ PS2__DOT____Vcellout__segdec1____pinNumber2;
    CData/*6:0*/ PS2__DOT____Vcellout__segdec2____pinNumber2;
    CData/*6:0*/ PS2__DOT____Vcellout__segdec3____pinNumber2;
    CData/*6:0*/ PS2__DOT____Vcellout__segdec6____pinNumber2;
    CData/*6:0*/ PS2__DOT____Vcellout__segdec7____pinNumber2;
    CData/*0:0*/ PS2__DOT__u_keycode_to_ascii__DOT__valid;
    CData/*2:0*/ PS2__DOT__inst__DOT__w_ptr;
    CData/*2:0*/ PS2__DOT__inst__DOT__r_ptr;
    CData/*3:0*/ PS2__DOT__inst__DOT__count;
    CData/*2:0*/ PS2__DOT__inst__DOT__ps2_clk_sync;
    CData/*0:0*/ PS2__DOT__inst__DOT____Vlvbound_hf7a7b477__0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CLK__0;
    SData/*9:0*/ PS2__DOT__inst__DOT__buffer;
    IData/*23:0*/ PS2__DOT__receiveData;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8> PS2__DOT__inst__DOT__fifo;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VPS2__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPS2___024root(VPS2__Syms* symsp, const char* v__name);
    ~VPS2___024root();
    VL_UNCOPYABLE(VPS2___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
