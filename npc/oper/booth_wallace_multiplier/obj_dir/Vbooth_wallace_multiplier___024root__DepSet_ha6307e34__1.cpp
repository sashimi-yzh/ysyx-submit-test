// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbooth_wallace_multiplier.h for the primary calling header

#include "verilated.h"

#include "Vbooth_wallace_multiplier___024root.h"

void Vbooth_wallace_multiplier___024root___eval_act(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vbooth_wallace_multiplier___024root___nba_sequent__TOP__0(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->rst_n) {
        vlSelf->valid = 1U;
        vlSelf->product = ((IData)(vlSelf->is_signed)
                            ? ((((QData)((IData)(vlSelf->booth_wallace_multiplier__DOT__s[1U])) 
                                 << 0x20U) | (QData)((IData)(
                                                             vlSelf->booth_wallace_multiplier__DOT__s[0U]))) 
                               + (0xfffffffffffffffeULL 
                                  & (((QData)((IData)(
                                                      vlSelf->booth_wallace_multiplier__DOT__cout2[1U])) 
                                      << 0x21U) | ((QData)((IData)(
                                                                   vlSelf->booth_wallace_multiplier__DOT__cout2[0U])) 
                                                   << 1U))))
                            : ((((QData)((IData)(vlSelf->booth_wallace_multiplier__DOT__s[1U])) 
                                 << 0x20U) | (QData)((IData)(
                                                             vlSelf->booth_wallace_multiplier__DOT__s[0U]))) 
                               + (0xfffffffffffffffeULL 
                                  & (((QData)((IData)(
                                                      vlSelf->booth_wallace_multiplier__DOT__cout2[1U])) 
                                      << 0x21U) | ((QData)((IData)(
                                                                   vlSelf->booth_wallace_multiplier__DOT__cout2[0U])) 
                                                   << 1U)))));
    } else {
        vlSelf->valid = 0U;
        vlSelf->product = 0ULL;
    }
}

void Vbooth_wallace_multiplier___024root___eval_nba(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vbooth_wallace_multiplier___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vbooth_wallace_multiplier___024root___eval_triggers__ico(Vbooth_wallace_multiplier___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___dump_triggers__ico(Vbooth_wallace_multiplier___024root* vlSelf);
#endif  // VL_DEBUG
void Vbooth_wallace_multiplier___024root___eval_ico(Vbooth_wallace_multiplier___024root* vlSelf);
void Vbooth_wallace_multiplier___024root___eval_triggers__act(Vbooth_wallace_multiplier___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___dump_triggers__act(Vbooth_wallace_multiplier___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___dump_triggers__nba(Vbooth_wallace_multiplier___024root* vlSelf);
#endif  // VL_DEBUG

void Vbooth_wallace_multiplier___024root___eval(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___eval\n"); );
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
        Vbooth_wallace_multiplier___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vbooth_wallace_multiplier___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("booth_wallace_multiplier.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vbooth_wallace_multiplier___024root___eval_ico(vlSelf);
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
            Vbooth_wallace_multiplier___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vbooth_wallace_multiplier___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("booth_wallace_multiplier.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vbooth_wallace_multiplier___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vbooth_wallace_multiplier___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("booth_wallace_multiplier.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vbooth_wallace_multiplier___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vbooth_wallace_multiplier___024root___eval_debug_assertions(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->is_signed & 0xfeU))) {
        Verilated::overWidthError("is_signed");}
}
#endif  // VL_DEBUG
