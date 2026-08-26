// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPS2__Syms.h"


VL_ATTR_COLD void VPS2___024root__trace_init_sub__TOP__0(VPS2___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root__trace_init_sub__TOP__0\n"); );
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+40,0,"CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"CLRN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"seg0L",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+43,0,"seg0H",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+44,0,"seg1L",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+45,0,"seg1H",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+46,0,"seg2L",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+47,0,"seg2H",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+48,0,"seg3L",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+49,0,"seg3H",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+50,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+51,0,"PS2_CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"PS2_DAT",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("PS2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+40,0,"CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"CLRN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"seg0L",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+43,0,"seg0H",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+44,0,"seg1L",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+45,0,"seg1H",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+46,0,"seg2L",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+47,0,"seg2H",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+48,0,"seg3L",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+49,0,"seg3H",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+50,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+51,0,"PS2_CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"PS2_DAT",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"nextdata_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"receiveData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+5,0,"ascii_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+6,0,"displayEnable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"ifPressed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+8,0,"status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"nextstatus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+40,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"clrn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"ps2_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"ps2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"nextdata_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1,0,"ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"overflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"buffer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->pushPrefix("fifo", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+11+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+19,0,"w_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+20,0,"r_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+21,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+22,0,"ps2_clk_sync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+23,0,"sampling",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("segdec0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+24,0,"hex",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+25,0,"seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+6,0,"enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("segdec1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+26,0,"hex",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+27,0,"seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+6,0,"enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("segdec2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+28,0,"hex",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+29,0,"seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+6,0,"enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("segdec3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+30,0,"hex",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+31,0,"seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+6,0,"enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("segdec4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+32,0,"hex",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+53,0,"seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+54,0,"enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("segdec5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+33,0,"hex",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+53,0,"seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+54,0,"enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("segdec6", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+34,0,"hex",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+35,0,"seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+55,0,"enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("segdec7", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+36,0,"hex",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+37,0,"seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+55,0,"enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_keycode_to_ascii", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+38,0,"scancode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+5,0,"ascii",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+39,0,"valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VPS2___024root__trace_init_top(VPS2___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root__trace_init_top\n"); );
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VPS2___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VPS2___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VPS2___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VPS2___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VPS2___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VPS2___024root__trace_register(VPS2___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root__trace_register\n"); );
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VPS2___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&VPS2___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&VPS2___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&VPS2___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VPS2___024root__trace_const_0_sub_0(VPS2___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VPS2___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root__trace_const_0\n"); );
    // Body
    VPS2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPS2___024root*>(voidSelf);
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VPS2___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VPS2___024root__trace_const_0_sub_0(VPS2___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root__trace_const_0_sub_0\n"); );
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+53,(0x7fU),7);
    bufp->fullBit(oldp+54,(0U));
    bufp->fullBit(oldp+55,(1U));
}

VL_ATTR_COLD void VPS2___024root__trace_full_0_sub_0(VPS2___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VPS2___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root__trace_full_0\n"); );
    // Body
    VPS2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPS2___024root*>(voidSelf);
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VPS2___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VPS2___024root__trace_full_0_sub_0(VPS2___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root__trace_full_0_sub_0\n"); );
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+1,(vlSelfRef.PS2__DOT__ready));
    bufp->fullBit(oldp+2,(vlSelfRef.PS2__DOT__overflow));
    bufp->fullBit(oldp+3,(vlSelfRef.PS2__DOT__nextdata_n));
    bufp->fullIData(oldp+4,(vlSelfRef.PS2__DOT__receiveData),24);
    bufp->fullCData(oldp+5,(vlSelfRef.PS2__DOT__ascii_out),8);
    bufp->fullBit(oldp+6,(vlSelfRef.PS2__DOT__ifPressed));
    bufp->fullCData(oldp+7,(vlSelfRef.PS2__DOT__count),8);
    bufp->fullBit(oldp+8,(vlSelfRef.PS2__DOT__status));
    bufp->fullBit(oldp+9,(vlSelfRef.PS2__DOT__nextstatus));
    bufp->fullSData(oldp+10,(vlSelfRef.PS2__DOT__inst__DOT__buffer),10);
    bufp->fullCData(oldp+11,(vlSelfRef.PS2__DOT__inst__DOT__fifo[0]),8);
    bufp->fullCData(oldp+12,(vlSelfRef.PS2__DOT__inst__DOT__fifo[1]),8);
    bufp->fullCData(oldp+13,(vlSelfRef.PS2__DOT__inst__DOT__fifo[2]),8);
    bufp->fullCData(oldp+14,(vlSelfRef.PS2__DOT__inst__DOT__fifo[3]),8);
    bufp->fullCData(oldp+15,(vlSelfRef.PS2__DOT__inst__DOT__fifo[4]),8);
    bufp->fullCData(oldp+16,(vlSelfRef.PS2__DOT__inst__DOT__fifo[5]),8);
    bufp->fullCData(oldp+17,(vlSelfRef.PS2__DOT__inst__DOT__fifo[6]),8);
    bufp->fullCData(oldp+18,(vlSelfRef.PS2__DOT__inst__DOT__fifo[7]),8);
    bufp->fullCData(oldp+19,(vlSelfRef.PS2__DOT__inst__DOT__w_ptr),3);
    bufp->fullCData(oldp+20,(vlSelfRef.PS2__DOT__inst__DOT__r_ptr),3);
    bufp->fullCData(oldp+21,(vlSelfRef.PS2__DOT__inst__DOT__count),4);
    bufp->fullCData(oldp+22,(vlSelfRef.PS2__DOT__inst__DOT__ps2_clk_sync),3);
    bufp->fullBit(oldp+23,((IData)((4U == (6U & (IData)(vlSelfRef.PS2__DOT__inst__DOT__ps2_clk_sync))))));
    bufp->fullCData(oldp+24,((0x0000000fU & vlSelfRef.PS2__DOT__receiveData)),4);
    bufp->fullCData(oldp+25,(vlSelfRef.PS2__DOT____Vcellout__segdec0____pinNumber2),7);
    bufp->fullCData(oldp+26,((0x0000000fU & (vlSelfRef.PS2__DOT__receiveData 
                                             >> 4U))),4);
    bufp->fullCData(oldp+27,(vlSelfRef.PS2__DOT____Vcellout__segdec1____pinNumber2),7);
    bufp->fullCData(oldp+28,((0x0000000fU & (IData)(vlSelfRef.PS2__DOT__ascii_out))),4);
    bufp->fullCData(oldp+29,(vlSelfRef.PS2__DOT____Vcellout__segdec2____pinNumber2),7);
    bufp->fullCData(oldp+30,((0x0000000fU & ((IData)(vlSelfRef.PS2__DOT__ascii_out) 
                                             >> 4U))),4);
    bufp->fullCData(oldp+31,(vlSelfRef.PS2__DOT____Vcellout__segdec3____pinNumber2),7);
    bufp->fullCData(oldp+32,((0x0000000fU & (vlSelfRef.PS2__DOT__receiveData 
                                             >> 0x00000010U))),4);
    bufp->fullCData(oldp+33,((0x0000000fU & (vlSelfRef.PS2__DOT__receiveData 
                                             >> 0x00000014U))),4);
    bufp->fullCData(oldp+34,((0x0000000fU & (IData)(vlSelfRef.PS2__DOT__count))),4);
    bufp->fullCData(oldp+35,(vlSelfRef.PS2__DOT____Vcellout__segdec6____pinNumber2),7);
    bufp->fullCData(oldp+36,((0x0000000fU & ((IData)(vlSelfRef.PS2__DOT__count) 
                                             >> 4U))),4);
    bufp->fullCData(oldp+37,(vlSelfRef.PS2__DOT____Vcellout__segdec7____pinNumber2),7);
    bufp->fullCData(oldp+38,((0x000000ffU & vlSelfRef.PS2__DOT__receiveData)),8);
    bufp->fullBit(oldp+39,(vlSelfRef.PS2__DOT__u_keycode_to_ascii__DOT__valid));
    bufp->fullBit(oldp+40,(vlSelfRef.CLK));
    bufp->fullBit(oldp+41,(vlSelfRef.CLRN));
    bufp->fullCData(oldp+42,(vlSelfRef.seg0L),8);
    bufp->fullCData(oldp+43,(vlSelfRef.seg0H),8);
    bufp->fullCData(oldp+44,(vlSelfRef.seg1L),8);
    bufp->fullCData(oldp+45,(vlSelfRef.seg1H),8);
    bufp->fullCData(oldp+46,(vlSelfRef.seg2L),8);
    bufp->fullCData(oldp+47,(vlSelfRef.seg2H),8);
    bufp->fullCData(oldp+48,(vlSelfRef.seg3L),8);
    bufp->fullCData(oldp+49,(vlSelfRef.seg3H),8);
    bufp->fullCData(oldp+50,(vlSelfRef.data),8);
    bufp->fullBit(oldp+51,(vlSelfRef.PS2_CLK));
    bufp->fullBit(oldp+52,(vlSelfRef.PS2_DAT));
}
