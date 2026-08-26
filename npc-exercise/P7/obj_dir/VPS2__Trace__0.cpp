// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPS2__Syms.h"


void VPS2___024root__trace_chg_0_sub_0(VPS2___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VPS2___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root__trace_chg_0\n"); );
    // Body
    VPS2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPS2___024root*>(voidSelf);
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VPS2___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VPS2___024root__trace_chg_0_sub_0(VPS2___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root__trace_chg_0_sub_0\n"); );
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.PS2__DOT__ready));
        bufp->chgBit(oldp+1,(vlSelfRef.PS2__DOT__overflow));
        bufp->chgBit(oldp+2,(vlSelfRef.PS2__DOT__nextdata_n));
        bufp->chgIData(oldp+3,(vlSelfRef.PS2__DOT__receiveData),24);
        bufp->chgCData(oldp+4,(vlSelfRef.PS2__DOT__ascii_out),8);
        bufp->chgBit(oldp+5,(vlSelfRef.PS2__DOT__ifPressed));
        bufp->chgCData(oldp+6,(vlSelfRef.PS2__DOT__count),8);
        bufp->chgBit(oldp+7,(vlSelfRef.PS2__DOT__status));
        bufp->chgBit(oldp+8,(vlSelfRef.PS2__DOT__nextstatus));
        bufp->chgSData(oldp+9,(vlSelfRef.PS2__DOT__inst__DOT__buffer),10);
        bufp->chgCData(oldp+10,(vlSelfRef.PS2__DOT__inst__DOT__fifo[0]),8);
        bufp->chgCData(oldp+11,(vlSelfRef.PS2__DOT__inst__DOT__fifo[1]),8);
        bufp->chgCData(oldp+12,(vlSelfRef.PS2__DOT__inst__DOT__fifo[2]),8);
        bufp->chgCData(oldp+13,(vlSelfRef.PS2__DOT__inst__DOT__fifo[3]),8);
        bufp->chgCData(oldp+14,(vlSelfRef.PS2__DOT__inst__DOT__fifo[4]),8);
        bufp->chgCData(oldp+15,(vlSelfRef.PS2__DOT__inst__DOT__fifo[5]),8);
        bufp->chgCData(oldp+16,(vlSelfRef.PS2__DOT__inst__DOT__fifo[6]),8);
        bufp->chgCData(oldp+17,(vlSelfRef.PS2__DOT__inst__DOT__fifo[7]),8);
        bufp->chgCData(oldp+18,(vlSelfRef.PS2__DOT__inst__DOT__w_ptr),3);
        bufp->chgCData(oldp+19,(vlSelfRef.PS2__DOT__inst__DOT__r_ptr),3);
        bufp->chgCData(oldp+20,(vlSelfRef.PS2__DOT__inst__DOT__count),4);
        bufp->chgCData(oldp+21,(vlSelfRef.PS2__DOT__inst__DOT__ps2_clk_sync),3);
        bufp->chgBit(oldp+22,((IData)((4U == (6U & (IData)(vlSelfRef.PS2__DOT__inst__DOT__ps2_clk_sync))))));
        bufp->chgCData(oldp+23,((0x0000000fU & vlSelfRef.PS2__DOT__receiveData)),4);
        bufp->chgCData(oldp+24,(vlSelfRef.PS2__DOT____Vcellout__segdec0____pinNumber2),7);
        bufp->chgCData(oldp+25,((0x0000000fU & (vlSelfRef.PS2__DOT__receiveData 
                                                >> 4U))),4);
        bufp->chgCData(oldp+26,(vlSelfRef.PS2__DOT____Vcellout__segdec1____pinNumber2),7);
        bufp->chgCData(oldp+27,((0x0000000fU & (IData)(vlSelfRef.PS2__DOT__ascii_out))),4);
        bufp->chgCData(oldp+28,(vlSelfRef.PS2__DOT____Vcellout__segdec2____pinNumber2),7);
        bufp->chgCData(oldp+29,((0x0000000fU & ((IData)(vlSelfRef.PS2__DOT__ascii_out) 
                                                >> 4U))),4);
        bufp->chgCData(oldp+30,(vlSelfRef.PS2__DOT____Vcellout__segdec3____pinNumber2),7);
        bufp->chgCData(oldp+31,((0x0000000fU & (vlSelfRef.PS2__DOT__receiveData 
                                                >> 0x00000010U))),4);
        bufp->chgCData(oldp+32,((0x0000000fU & (vlSelfRef.PS2__DOT__receiveData 
                                                >> 0x00000014U))),4);
        bufp->chgCData(oldp+33,((0x0000000fU & (IData)(vlSelfRef.PS2__DOT__count))),4);
        bufp->chgCData(oldp+34,(vlSelfRef.PS2__DOT____Vcellout__segdec6____pinNumber2),7);
        bufp->chgCData(oldp+35,((0x0000000fU & ((IData)(vlSelfRef.PS2__DOT__count) 
                                                >> 4U))),4);
        bufp->chgCData(oldp+36,(vlSelfRef.PS2__DOT____Vcellout__segdec7____pinNumber2),7);
        bufp->chgCData(oldp+37,((0x000000ffU & vlSelfRef.PS2__DOT__receiveData)),8);
        bufp->chgBit(oldp+38,(vlSelfRef.PS2__DOT__u_keycode_to_ascii__DOT__valid));
    }
    bufp->chgBit(oldp+39,(vlSelfRef.CLK));
    bufp->chgBit(oldp+40,(vlSelfRef.CLRN));
    bufp->chgCData(oldp+41,(vlSelfRef.seg0L),8);
    bufp->chgCData(oldp+42,(vlSelfRef.seg0H),8);
    bufp->chgCData(oldp+43,(vlSelfRef.seg1L),8);
    bufp->chgCData(oldp+44,(vlSelfRef.seg1H),8);
    bufp->chgCData(oldp+45,(vlSelfRef.seg2L),8);
    bufp->chgCData(oldp+46,(vlSelfRef.seg2H),8);
    bufp->chgCData(oldp+47,(vlSelfRef.seg3L),8);
    bufp->chgCData(oldp+48,(vlSelfRef.seg3H),8);
    bufp->chgCData(oldp+49,(vlSelfRef.data),8);
    bufp->chgBit(oldp+50,(vlSelfRef.PS2_CLK));
    bufp->chgBit(oldp+51,(vlSelfRef.PS2_DAT));
}

void VPS2___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root__trace_cleanup\n"); );
    // Body
    VPS2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPS2___024root*>(voidSelf);
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
