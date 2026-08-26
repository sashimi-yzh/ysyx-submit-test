// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VLFSR__Syms.h"


VL_ATTR_COLD void VLFSR___024root__trace_init_sub__TOP__0(VLFSR___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root__trace_init_sub__TOP__0\n"); );
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+2,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("LFSR", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+2,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+4,0,"buffer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void VLFSR___024root__trace_init_top(VLFSR___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root__trace_init_top\n"); );
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VLFSR___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VLFSR___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VLFSR___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VLFSR___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VLFSR___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VLFSR___024root__trace_register(VLFSR___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root__trace_register\n"); );
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VLFSR___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&VLFSR___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&VLFSR___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&VLFSR___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VLFSR___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root__trace_const_0\n"); );
    // Body
    VLFSR___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VLFSR___024root*>(voidSelf);
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VLFSR___024root__trace_full_0_sub_0(VLFSR___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VLFSR___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root__trace_full_0\n"); );
    // Body
    VLFSR___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VLFSR___024root*>(voidSelf);
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VLFSR___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VLFSR___024root__trace_full_0_sub_0(VLFSR___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root__trace_full_0_sub_0\n"); );
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+1,(vlSelfRef.in),8);
    bufp->fullBit(oldp+2,(vlSelfRef.clk));
    bufp->fullCData(oldp+3,(vlSelfRef.out),8);
    bufp->fullCData(oldp+4,(vlSelfRef.LFSR__DOT__buffer),8);
}
