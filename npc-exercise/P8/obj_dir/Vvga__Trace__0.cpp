// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vvga__Syms.h"


void Vvga___024root__trace_chg_0_sub_0(Vvga___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vvga___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root__trace_chg_0\n"); );
    // Body
    Vvga___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vvga___024root*>(voidSelf);
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vvga___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vvga___024root__trace_chg_0_sub_0(Vvga___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root__trace_chg_0_sub_0\n"); );
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgSData(oldp+0,(vlSelfRef.vga__DOT__u_rom__DOT__v_addr),10);
        bufp->chgSData(oldp+1,(vlSelfRef.vga__DOT__u_vga_ctrl__DOT__y_cnt),10);
        bufp->chgBit(oldp+2,(vlSelfRef.vga__DOT__u_vga_ctrl__DOT__v_valid));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgSData(oldp+3,(vlSelfRef.vga__DOT__u_rom__DOT__h_addr),10);
        bufp->chgSData(oldp+4,(vlSelfRef.vga__DOT__u_vga_ctrl__DOT__x_cnt),10);
        bufp->chgBit(oldp+5,(vlSelfRef.vga__DOT__u_vga_ctrl__DOT__h_valid));
    }
    bufp->chgBit(oldp+6,(vlSelfRef.clk));
    bufp->chgBit(oldp+7,(vlSelfRef.reset));
    bufp->chgBit(oldp+8,(vlSelfRef.vsync));
    bufp->chgBit(oldp+9,(vlSelfRef.hsync));
    bufp->chgBit(oldp+10,(vlSelfRef.valid));
    bufp->chgCData(oldp+11,(vlSelfRef.vga_r),8);
    bufp->chgCData(oldp+12,(vlSelfRef.vga_g),8);
    bufp->chgCData(oldp+13,(vlSelfRef.vga_b),8);
    bufp->chgIData(oldp+14,(vlSelfRef.vga__DOT__vga_data),24);
    bufp->chgIData(oldp+15,((0x0007ffffU & (((IData)(0x00000280U) 
                                             * (IData)(vlSelfRef.vga__DOT__u_rom__DOT__v_addr)) 
                                            + (IData)(vlSelfRef.vga__DOT__u_rom__DOT__h_addr)))),19);
    bufp->chgIData(oldp+16,(vlSelfRef.vga__DOT__u_rom__DOT__addr_reg),19);
}

void Vvga___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root__trace_cleanup\n"); );
    // Body
    Vvga___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vvga___024root*>(voidSelf);
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
