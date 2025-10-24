// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu.h for the primary calling header

#include "verilated.h"

#include "Vfpu___024root.h"

void Vfpu___024root___eval_triggers__ico(Vfpu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu___024root___dump_triggers__ico(Vfpu___024root* vlSelf);
#endif  // VL_DEBUG
void Vfpu___024root___eval_ico(Vfpu___024root* vlSelf);
void Vfpu___024root___eval_triggers__act(Vfpu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu___024root___dump_triggers__act(Vfpu___024root* vlSelf);
#endif  // VL_DEBUG
void Vfpu___024root___eval_act(Vfpu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu___024root___dump_triggers__nba(Vfpu___024root* vlSelf);
#endif  // VL_DEBUG
void Vfpu___024root___eval_nba(Vfpu___024root* vlSelf);

void Vfpu___024root___eval(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vfpu___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vfpu___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("fpu_tb.v", 3, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vfpu___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vfpu___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vfpu___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("fpu_tb.v", 3, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vfpu___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vfpu___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("fpu_tb.v", 3, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vfpu___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vfpu___024root___eval_debug_assertions(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->freg_rs1 & 0xe0U))) {
        Verilated::overWidthError("freg_rs1");}
    if (VL_UNLIKELY((vlSelf->freg_rs2 & 0xe0U))) {
        Verilated::overWidthError("freg_rs2");}
    if (VL_UNLIKELY((vlSelf->freg_rd & 0xe0U))) {
        Verilated::overWidthError("freg_rd");}
    if (VL_UNLIKELY((vlSelf->freg_write_en & 0xfeU))) {
        Verilated::overWidthError("freg_write_en");}
    if (VL_UNLIKELY((vlSelf->fpu_op_valid & 0xfeU))) {
        Verilated::overWidthError("fpu_op_valid");}
    if (VL_UNLIKELY((vlSelf->fpu_op_type & 0xc0U))) {
        Verilated::overWidthError("fpu_op_type");}
    if (VL_UNLIKELY((vlSelf->fpu_op_round & 0xf8U))) {
        Verilated::overWidthError("fpu_op_round");}
    if (VL_UNLIKELY((vlSelf->downstream_valid & 0xfeU))) {
        Verilated::overWidthError("downstream_valid");}
}
#endif  // VL_DEBUG
