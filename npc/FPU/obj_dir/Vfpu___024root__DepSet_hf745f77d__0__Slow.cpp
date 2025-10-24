// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu.h for the primary calling header

#include "verilated.h"

#include "Vfpu___024root.h"

VL_ATTR_COLD void Vfpu___024root___eval_static(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vfpu___024root___eval_initial__TOP(Vfpu___024root* vlSelf);

VL_ATTR_COLD void Vfpu___024root___eval_initial(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___eval_initial\n"); );
    // Body
    Vfpu___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__reset = vlSelf->reset;
}

VL_ATTR_COLD void Vfpu___024root___eval_initial__TOP(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[1U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[2U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[3U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[4U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[5U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[6U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[7U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[8U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[9U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0xaU] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0xbU] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0xcU] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0xdU] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0xeU] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0xfU] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x10U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x11U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x12U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x13U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x14U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x15U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x16U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x17U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x18U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x19U] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x1aU] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x1bU] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x1cU] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x1dU] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x1eU] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0x1fU] = 0U;
    vlSelf->fpu_tb__DOT__freg_inst__DOT__i = 0x20U;
    VL_WRITEF("multiplicand = %x, multiplier = %x, is_signed = 1\n",
              32,vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant1,
              32,vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2);
}

VL_ATTR_COLD void Vfpu___024root___eval_final(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vfpu___024root___eval_triggers__stl(Vfpu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu___024root___dump_triggers__stl(Vfpu___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vfpu___024root___eval_stl(Vfpu___024root* vlSelf);

VL_ATTR_COLD void Vfpu___024root___eval_settle(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vfpu___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vfpu___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("fpu_tb.v", 3, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vfpu___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu___024root___dump_triggers__stl(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___dump_triggers__stl\n"); );
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
VL_ATTR_COLD void Vfpu___024root___dump_triggers__ico(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vfpu___024root___dump_triggers__act(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu___024root___dump_triggers__nba(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfpu___024root___ctor_var_reset(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->freg_rs1 = VL_RAND_RESET_I(5);
    vlSelf->freg_rs2 = VL_RAND_RESET_I(5);
    vlSelf->freg_rd = VL_RAND_RESET_I(5);
    vlSelf->freg_write_data = VL_RAND_RESET_I(32);
    vlSelf->freg_write_en = VL_RAND_RESET_I(1);
    vlSelf->freg_read_data1 = VL_RAND_RESET_I(32);
    vlSelf->freg_read_data2 = VL_RAND_RESET_I(32);
    vlSelf->fpu_op_valid = VL_RAND_RESET_I(1);
    vlSelf->fpu_op_type = VL_RAND_RESET_I(6);
    vlSelf->fpu_op_round = VL_RAND_RESET_I(3);
    vlSelf->operand1_fp = VL_RAND_RESET_I(32);
    vlSelf->operand2_fp = VL_RAND_RESET_I(32);
    vlSelf->operand3_fp = VL_RAND_RESET_I(32);
    vlSelf->operand4_int = VL_RAND_RESET_I(32);
    vlSelf->downstream_valid = VL_RAND_RESET_I(1);
    vlSelf->fpu_ready = VL_RAND_RESET_I(1);
    vlSelf->fpu_result = VL_RAND_RESET_I(32);
    vlSelf->int_result = VL_RAND_RESET_I(32);
    vlSelf->exception_flags = VL_RAND_RESET_I(5);
    vlSelf->fpu_result_valid = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->fpu_tb__DOT__freg_inst__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__next_state = VL_RAND_RESET_I(2);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__temp_result = VL_RAND_RESET_I(32);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__temp_int_result = VL_RAND_RESET_I(32);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__temp_exception = VL_RAND_RESET_I(5);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__next_fpu_ready = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__comb_result = VL_RAND_RESET_I(32);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__comb_int_result = VL_RAND_RESET_I(32);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__comb_exception = VL_RAND_RESET_I(5);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__shift_amt = VL_RAND_RESET_I(9);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__lzc = VL_RAND_RESET_I(9);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mant_for_round = VL_RAND_RESET_I(27);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__true_exp1 = VL_RAND_RESET_I(9);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__true_exp2 = VL_RAND_RESET_I(9);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__max_exp = VL_RAND_RESET_I(9);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__norm_mant1 = VL_RAND_RESET_I(24);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__norm_mant2 = VL_RAND_RESET_I(24);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__lead_zeros1 = VL_RAND_RESET_I(9);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__lead_zeros2 = VL_RAND_RESET_I(9);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__shifted_mant1 = VL_RAND_RESET_I(28);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__shifted_mant2 = VL_RAND_RESET_I(28);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__sum_mant = VL_RAND_RESET_I(29);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__result_exp = VL_RAND_RESET_I(9);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__result_sign = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__guard = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__round = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__sticky = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__prod_mant = VL_RAND_RESET_Q(48);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__sign2_eff = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_rounded_mant = VL_RAND_RESET_I(27);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_rounded_exp = VL_RAND_RESET_I(9);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_guard = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_round = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_lsb = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_round_up = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_denorm_mant = VL_RAND_RESET_I(23);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_shift_amt = VL_RAND_RESET_I(9);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__stored_true_exp1 = VL_RAND_RESET_I(9);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__stored_true_exp2 = VL_RAND_RESET_I(9);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant1 = VL_RAND_RESET_I(32);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 = VL_RAND_RESET_I(32);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_product = VL_RAND_RESET_Q(64);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_valid = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_nan1 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_nan2 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_snan1 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_snan2 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_inf1 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_inf2 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_zero1 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_zero2 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_denorm1 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_denorm2 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mant1 = VL_RAND_RESET_I(24);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mant2 = VL_RAND_RESET_I(24);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT____VdfgExtracted_hafe05f6b__0 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT____VdfgExtracted_haff721d2__0 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT____VdfgExtracted_hef9ab653__0 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT____VdfgExtracted_hb2387866__0 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT____VdfgExtracted_hd6e7e387__0 = VL_RAND_RESET_I(5);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT____VdfgExtracted_h74e0edf6__0 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT____VdfgExtracted_hd1e3c314__0 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT____VdfgExtracted_ha7c68572__0 = VL_RAND_RESET_I(1);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT____VdfgTmp_ha8c86842__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT____VdfgTmp_ha8c67718__0 = 0;
    VL_RAND_RESET_W(68, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        VL_RAND_RESET_W(68, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 68; ++__Vi0) {
        vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs[__Vi0] = VL_RAND_RESET_I(17);
    }
    VL_RAND_RESET_W(68, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__cout2);
    VL_RAND_RESET_W(68, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__s);
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hc3505cf3__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hf9f0876d__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hfe0a41fe__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hc5e42a69__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hbaa102cc__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hb4e6b126__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_haed8dbe3__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hb84f77ab__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_h937272c0__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_h8cb8ba8a__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hc18fac15__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hc411b621__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hcef34518__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_h91e9dc0e__0 = 0;
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_h8fc047d7__0 = 0;
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__1__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__1__is_underflow = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__1__is_inexact = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__2__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__2__is_nan = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__2__is_overflow = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__2__is_underflow = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__2__is_inexact = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__4__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__4__is_underflow = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__4__is_inexact = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__5__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__5__is_nan = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__5__is_overflow = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__5__is_underflow = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__5__is_inexact = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__8__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__8__is_underflow = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__8__is_inexact = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__9__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__9__is_nan = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__9__is_overflow = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__9__is_underflow = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_fpu_tb__DOT__fpu_inst__DOT__detect_exceptions__9__is_inexact = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__reset = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
