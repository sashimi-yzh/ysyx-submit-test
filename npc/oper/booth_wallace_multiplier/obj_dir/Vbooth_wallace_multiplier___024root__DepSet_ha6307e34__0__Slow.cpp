// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbooth_wallace_multiplier.h for the primary calling header

#include "verilated.h"

#include "Vbooth_wallace_multiplier___024root.h"

VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___eval_static(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___eval_initial__TOP(Vbooth_wallace_multiplier___024root* vlSelf);

VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___eval_initial(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___eval_initial\n"); );
    // Body
    Vbooth_wallace_multiplier___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst_n = vlSelf->rst_n;
}

VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___eval_initial__TOP(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___eval_initial__TOP\n"); );
    // Body
    VL_WRITEF("multiplicand = %x, multiplier = %x, is_signed = %b\n",
              32,vlSelf->multiplicand,32,vlSelf->multiplier,
              1,(IData)(vlSelf->is_signed));
}

VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___eval_final(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___eval_triggers__stl(Vbooth_wallace_multiplier___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___dump_triggers__stl(Vbooth_wallace_multiplier___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___eval_stl(Vbooth_wallace_multiplier___024root* vlSelf);

VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___eval_settle(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vbooth_wallace_multiplier___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vbooth_wallace_multiplier___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("booth_wallace_multiplier.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vbooth_wallace_multiplier___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___dump_triggers__stl(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___dump_triggers__ico(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___dump_triggers__act(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___dump_triggers__nba(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vbooth_wallace_multiplier___024root___ctor_var_reset(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->multiplicand = VL_RAND_RESET_I(32);
    vlSelf->multiplier = VL_RAND_RESET_I(32);
    vlSelf->is_signed = VL_RAND_RESET_I(1);
    vlSelf->product = VL_RAND_RESET_Q(64);
    vlSelf->valid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(68, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext);
    vlSelf->booth_wallace_multiplier__DOT__multiplier_ext = VL_RAND_RESET_Q(35);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        VL_RAND_RESET_W(68, vlSelf->booth_wallace_multiplier__DOT__partial_products[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 68; ++__Vi0) {
        vlSelf->booth_wallace_multiplier__DOT__switch_outputs[__Vi0] = VL_RAND_RESET_I(17);
    }
    VL_RAND_RESET_W(68, vlSelf->booth_wallace_multiplier__DOT__cout2);
    VL_RAND_RESET_W(68, vlSelf->booth_wallace_multiplier__DOT__s);
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hed3c5934__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc3505cf3__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hf9f0876d__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hfe0a41fe__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc5e42a69__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hbaa102cc__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hb4e6b126__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_haed8dbe3__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hb84f77ab__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h937272c0__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h8cb8ba8a__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc18fac15__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc411b621__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hcef34518__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h91e9dc0e__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h8fc047d7__0 = 0;
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h9b1da5a9__0 = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__rst_n = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
