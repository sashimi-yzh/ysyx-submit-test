// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VLFSR__Syms.h"


void VLFSR___024root__trace_chg_0_sub_0(VLFSR___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VLFSR___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root__trace_chg_0\n"); );
    // Body
    VLFSR___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VLFSR___024root*>(voidSelf);
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VLFSR___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VLFSR___024root__trace_chg_0_sub_0(VLFSR___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root__trace_chg_0_sub_0\n"); );
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    bufp->chgCData(oldp+0,(vlSelfRef.in),8);
    bufp->chgBit(oldp+1,(vlSelfRef.clk));
    bufp->chgCData(oldp+2,(vlSelfRef.out),8);
    bufp->chgCData(oldp+3,(vlSelfRef.LFSR__DOT__buffer),8);
}

void VLFSR___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    VLFSR___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VLFSR___024root*>(voidSelf);
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
