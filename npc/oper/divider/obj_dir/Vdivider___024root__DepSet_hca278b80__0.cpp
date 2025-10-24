// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdivider.h for the primary calling header

#include "verilated.h"

#include "Vdivider___024root.h"

void Vdivider___024root___eval_act(Vdivider___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdivider__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vdivider___024root___nba_sequent__TOP__0(Vdivider___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdivider__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__divider__DOT__temp_quotient;
    __Vdly__divider__DOT__temp_quotient = 0;
    QData/*63:0*/ __Vdly__divider__DOT__temp_dividend;
    __Vdly__divider__DOT__temp_dividend = 0;
    IData/*31:0*/ __Vdly__divider__DOT__pos_mask;
    __Vdly__divider__DOT__pos_mask = 0;
    CData/*0:0*/ __Vdly__divider__DOT__quotient_sign;
    __Vdly__divider__DOT__quotient_sign = 0;
    CData/*0:0*/ __Vdly__divider__DOT__remainder_sign;
    __Vdly__divider__DOT__remainder_sign = 0;
    CData/*5:0*/ __Vdly__divider__DOT__cycle_count;
    __Vdly__divider__DOT__cycle_count = 0;
    CData/*0:0*/ __Vdly__divider__DOT__computing;
    __Vdly__divider__DOT__computing = 0;
    // Body
    __Vdly__divider__DOT__computing = vlSelf->divider__DOT__computing;
    __Vdly__divider__DOT__cycle_count = vlSelf->divider__DOT__cycle_count;
    __Vdly__divider__DOT__remainder_sign = vlSelf->divider__DOT__remainder_sign;
    __Vdly__divider__DOT__quotient_sign = vlSelf->divider__DOT__quotient_sign;
    __Vdly__divider__DOT__pos_mask = vlSelf->divider__DOT__pos_mask;
    __Vdly__divider__DOT__temp_dividend = vlSelf->divider__DOT__temp_dividend;
    __Vdly__divider__DOT__temp_quotient = vlSelf->divider__DOT__temp_quotient;
    if (vlSelf->reset) {
        vlSelf->quotient = 0U;
        vlSelf->remainder = 0U;
        __Vdly__divider__DOT__temp_quotient = 0U;
        __Vdly__divider__DOT__temp_dividend = 0ULL;
        __Vdly__divider__DOT__pos_mask = 0x80000000U;
        __Vdly__divider__DOT__quotient_sign = 0U;
        __Vdly__divider__DOT__remainder_sign = 0U;
        vlSelf->valid = 0U;
        __Vdly__divider__DOT__cycle_count = 0U;
        __Vdly__divider__DOT__computing = 0U;
    } else if (vlSelf->divider__DOT__computing) {
        vlSelf->divider__DOT__unnamedblk1__DOT__temp_dividend_shifted 
            = (vlSelf->divider__DOT__temp_dividend 
               << 1U);
        vlSelf->divider__DOT__unnamedblk1__DOT__next_quotient 
            = vlSelf->divider__DOT__temp_quotient;
        if (((IData)((vlSelf->divider__DOT__unnamedblk1__DOT__temp_dividend_shifted 
                      >> 0x20U)) >= vlSelf->divider__DOT__abs_divisor)) {
            vlSelf->divider__DOT__unnamedblk1__DOT__next_remainder 
                = ((IData)((vlSelf->divider__DOT__unnamedblk1__DOT__temp_dividend_shifted 
                            >> 0x20U)) - vlSelf->divider__DOT__abs_divisor);
            vlSelf->divider__DOT__unnamedblk1__DOT__next_quotient 
                = (vlSelf->divider__DOT__temp_quotient 
                   | vlSelf->divider__DOT__pos_mask);
            __Vdly__divider__DOT__temp_dividend = (
                                                   ((QData)((IData)(vlSelf->divider__DOT__unnamedblk1__DOT__next_remainder)) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelf->divider__DOT__unnamedblk1__DOT__temp_dividend_shifted)));
        } else {
            vlSelf->divider__DOT__unnamedblk1__DOT__next_remainder 
                = (IData)((vlSelf->divider__DOT__unnamedblk1__DOT__temp_dividend_shifted 
                           >> 0x20U));
            __Vdly__divider__DOT__temp_dividend = vlSelf->divider__DOT__unnamedblk1__DOT__temp_dividend_shifted;
        }
        __Vdly__divider__DOT__temp_quotient = vlSelf->divider__DOT__unnamedblk1__DOT__next_quotient;
        __Vdly__divider__DOT__pos_mask = (vlSelf->divider__DOT__pos_mask 
                                          >> 1U);
        __Vdly__divider__DOT__cycle_count = (0x3fU 
                                             & ((IData)(1U) 
                                                + (IData)(vlSelf->divider__DOT__cycle_count)));
        if ((0x1fU == (IData)(vlSelf->divider__DOT__cycle_count))) {
            vlSelf->quotient = ((IData)(vlSelf->divider__DOT__quotient_sign)
                                 ? ((IData)(1U) + (~ vlSelf->divider__DOT__unnamedblk1__DOT__next_quotient))
                                 : vlSelf->divider__DOT__unnamedblk1__DOT__next_quotient);
            vlSelf->remainder = ((IData)(vlSelf->divider__DOT__remainder_sign)
                                  ? ((IData)(1U) + 
                                     (~ vlSelf->divider__DOT__unnamedblk1__DOT__next_remainder))
                                  : vlSelf->divider__DOT__unnamedblk1__DOT__next_remainder);
            vlSelf->valid = 1U;
            __Vdly__divider__DOT__computing = 0U;
        }
    } else {
        vlSelf->quotient = 0U;
        __Vdly__divider__DOT__temp_quotient = 0U;
        __Vdly__divider__DOT__pos_mask = 0x80000000U;
        __Vdly__divider__DOT__cycle_count = 0U;
        vlSelf->remainder = 0U;
        vlSelf->valid = 0U;
        if ((0U == vlSelf->divisor)) {
            vlSelf->quotient = 0xffffffffU;
            vlSelf->remainder = vlSelf->dividend;
            vlSelf->valid = 0U;
        } else if ((((IData)(vlSelf->is_signed) & (0x80000000U 
                                                   == vlSelf->dividend)) 
                    & (0xffffffffU == vlSelf->divisor))) {
            vlSelf->quotient = 0x80000000U;
            vlSelf->remainder = 0U;
            vlSelf->valid = 0U;
        } else {
            vlSelf->divider__DOT__abs_divisor = (((IData)(vlSelf->is_signed) 
                                                  & (vlSelf->divisor 
                                                     >> 0x1fU))
                                                  ? 
                                                 ((IData)(1U) 
                                                  + 
                                                  (~ vlSelf->divisor))
                                                  : vlSelf->divisor);
            __Vdly__divider__DOT__quotient_sign = ((IData)(vlSelf->is_signed) 
                                                   & ((vlSelf->dividend 
                                                       ^ vlSelf->divisor) 
                                                      >> 0x1fU));
            __Vdly__divider__DOT__remainder_sign = 
                ((IData)(vlSelf->is_signed) & (vlSelf->dividend 
                                               >> 0x1fU));
            __Vdly__divider__DOT__temp_dividend = (QData)((IData)(
                                                                  (((IData)(vlSelf->is_signed) 
                                                                    & (vlSelf->dividend 
                                                                       >> 0x1fU))
                                                                    ? 
                                                                   ((IData)(1U) 
                                                                    + 
                                                                    (~ vlSelf->dividend))
                                                                    : vlSelf->dividend)));
            __Vdly__divider__DOT__computing = 1U;
        }
    }
    vlSelf->divider__DOT__temp_quotient = __Vdly__divider__DOT__temp_quotient;
    vlSelf->divider__DOT__temp_dividend = __Vdly__divider__DOT__temp_dividend;
    vlSelf->divider__DOT__pos_mask = __Vdly__divider__DOT__pos_mask;
    vlSelf->divider__DOT__quotient_sign = __Vdly__divider__DOT__quotient_sign;
    vlSelf->divider__DOT__remainder_sign = __Vdly__divider__DOT__remainder_sign;
    vlSelf->divider__DOT__cycle_count = __Vdly__divider__DOT__cycle_count;
    vlSelf->divider__DOT__computing = __Vdly__divider__DOT__computing;
}

void Vdivider___024root___eval_nba(Vdivider___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdivider__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vdivider___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vdivider___024root___eval_triggers__act(Vdivider___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdivider___024root___dump_triggers__act(Vdivider___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdivider___024root___dump_triggers__nba(Vdivider___024root* vlSelf);
#endif  // VL_DEBUG

void Vdivider___024root___eval(Vdivider___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdivider__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vdivider___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vdivider___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("divider.v", 2, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vdivider___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vdivider___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("divider.v", 2, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vdivider___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vdivider___024root___eval_debug_assertions(Vdivider___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdivider__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->is_signed & 0xfeU))) {
        Verilated::overWidthError("is_signed");}
}
#endif  // VL_DEBUG
