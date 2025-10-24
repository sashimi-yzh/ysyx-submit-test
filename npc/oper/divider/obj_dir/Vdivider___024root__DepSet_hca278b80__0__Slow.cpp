// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdivider.h for the primary calling header

#include "verilated.h"

#include "Vdivider___024root.h"

VL_ATTR_COLD void Vdivider___024root___eval_static(Vdivider___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdivider__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vdivider___024root___eval_initial(Vdivider___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdivider__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vdivider___024root___eval_final(Vdivider___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdivider__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vdivider___024root___eval_settle(Vdivider___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdivider__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdivider___024root___dump_triggers__act(Vdivider___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdivider__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdivider___024root___dump_triggers__nba(Vdivider___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdivider__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdivider___024root___ctor_var_reset(Vdivider___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdivider__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->dividend = VL_RAND_RESET_I(32);
    vlSelf->divisor = VL_RAND_RESET_I(32);
    vlSelf->is_signed = VL_RAND_RESET_I(1);
    vlSelf->quotient = VL_RAND_RESET_I(32);
    vlSelf->remainder = VL_RAND_RESET_I(32);
    vlSelf->valid = VL_RAND_RESET_I(1);
    vlSelf->divider__DOT__abs_divisor = VL_RAND_RESET_I(32);
    vlSelf->divider__DOT__temp_dividend = VL_RAND_RESET_Q(64);
    vlSelf->divider__DOT__temp_quotient = VL_RAND_RESET_I(32);
    vlSelf->divider__DOT__quotient_sign = VL_RAND_RESET_I(1);
    vlSelf->divider__DOT__remainder_sign = VL_RAND_RESET_I(1);
    vlSelf->divider__DOT__cycle_count = VL_RAND_RESET_I(6);
    vlSelf->divider__DOT__computing = VL_RAND_RESET_I(1);
    vlSelf->divider__DOT__pos_mask = VL_RAND_RESET_I(32);
    vlSelf->divider__DOT__unnamedblk1__DOT__temp_dividend_shifted = VL_RAND_RESET_Q(64);
    vlSelf->divider__DOT__unnamedblk1__DOT__next_remainder = VL_RAND_RESET_I(32);
    vlSelf->divider__DOT__unnamedblk1__DOT__next_quotient = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
}
