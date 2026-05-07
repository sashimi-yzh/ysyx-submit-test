// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLError.h"

VL_ATTR_COLD void VysyxSoCFull_TLError___eval_initial__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__ferr(VysyxSoCFull_TLError* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLError___eval_initial__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__ferr\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h180e0517__0;
    VlWide<5>/*159:0*/ __Vtemp_h180e0517__1;
    // Body
    __Vtemp_h180e0517__0[0U] = 0x743d2564U;
    __Vtemp_h180e0517__0[1U] = 0x6d656f75U;
    __Vtemp_h180e0517__0[2U] = 0x6b5f7469U;
    __Vtemp_h180e0517__0[3U] = 0x656c696eU;
    __Vtemp_h180e0517__0[4U] = 0x74696cU;
    if ((! VL_VALUEPLUSARGS_INI(32, VL_CVT_PACK_STR_NW(5, __Vtemp_h180e0517__0), 
                                vlSelf->__PVT__monitor__DOT__plusarg_reader__DOT__myplus))) {
        vlSelf->__PVT__monitor__DOT__plusarg_reader__DOT__myplus = 0U;
    }
    __Vtemp_h180e0517__1[0U] = 0x743d2564U;
    __Vtemp_h180e0517__1[1U] = 0x6d656f75U;
    __Vtemp_h180e0517__1[2U] = 0x6b5f7469U;
    __Vtemp_h180e0517__1[3U] = 0x656c696eU;
    __Vtemp_h180e0517__1[4U] = 0x74696cU;
    if ((! VL_VALUEPLUSARGS_INI(32, VL_CVT_PACK_STR_NW(5, __Vtemp_h180e0517__1), 
                                vlSelf->__PVT__monitor__DOT__plusarg_reader_1__DOT__myplus))) {
        vlSelf->__PVT__monitor__DOT__plusarg_reader_1__DOT__myplus = 0U;
    }
}

VL_ATTR_COLD void VysyxSoCFull_TLError___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__ferr__0(VysyxSoCFull_TLError* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLError___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__ferr__0\n"); );
    // Body
    vlSelf->__PVT__da_first = (0U == (IData)(vlSelf->__PVT__r_counter));
    vlSelf->__PVT__idle_1 = (0U == (IData)(vlSelf->__PVT__beatsLeft));
    vlSelf->__PVT__monitor__DOT__a_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_2 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_2));
    vlSelf->__PVT__da_bits_opcode = ((0x17U >= (0x1fU 
                                                & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSelf->__PVT__a_q__DOT__ram 
                                                               >> 0x3cU))))))
                                      ? (7U & (0x911240U 
                                               >> (0x1fU 
                                                   & ((IData)(3U) 
                                                      * 
                                                      (7U 
                                                       & (IData)(
                                                                 (vlSelf->__PVT__a_q__DOT__ram 
                                                                  >> 0x3cU)))))))
                                      : 0U);
    vlSelf->__VdfgTmp_hec6944b2__0 = ((0U == (IData)(vlSelf->__PVT__beatsLeft)) 
                                      | (IData)(vlSelf->__PVT__state_1));
    vlSelf->__PVT__a_last_beats1 = ((1U & (IData)((vlSelf->__PVT__a_q__DOT__ram 
                                                   >> 0x3eU)))
                                     ? 0U : (7U & (~ 
                                                   (0x3ffU 
                                                    & (((IData)(0x1fU) 
                                                        << 
                                                        (7U 
                                                         & (IData)(
                                                                   (vlSelf->__PVT__a_q__DOT__ram 
                                                                    >> 0x36U)))) 
                                                       >> 2U)))));
    vlSelf->__PVT__r_beats1 = ((1U & (IData)(vlSelf->__PVT__da_bits_opcode))
                                ? (7U & (~ (0x3ffU 
                                            & (((IData)(0x1fU) 
                                                << 
                                                (7U 
                                                 & (IData)(
                                                           (vlSelf->__PVT__a_q__DOT__ram 
                                                            >> 0x36U)))) 
                                               >> 2U))))
                                : 0U);
    vlSelf->__PVT__a_last = ((1U == (IData)(vlSelf->__PVT__a_last_counter)) 
                             | (0U == (IData)(vlSelf->__PVT__a_last_beats1)));
    vlSelf->__PVT__winner_1 = ((IData)(vlSelf->__PVT__a_q__DOT__full) 
                               & ((IData)(vlSelf->__PVT__a_last) 
                                  & (IData)(vlSelf->__PVT__idle)));
    vlSelf->auto_in_d_bits_denied = ((0U == (IData)(vlSelf->__PVT__beatsLeft))
                                      ? (IData)(vlSelf->__PVT__winner_1)
                                      : (IData)(vlSelf->__PVT__state_1));
    vlSelf->auto_in_d_valid = ((IData)(vlSelf->__VdfgTmp_hec6944b2__0) 
                               & (IData)(vlSelf->__PVT__winner_1));
    if (vlSelf->auto_in_d_bits_denied) {
        vlSelf->auto_in_d_bits_corrupt = (1U & (IData)(vlSelf->__PVT__da_bits_opcode));
        vlSelf->auto_in_d_bits_size = (7U & (IData)(
                                                    (vlSelf->__PVT__a_q__DOT__ram 
                                                     >> 0x36U)));
        vlSelf->auto_in_d_bits_source = (0xfU & (IData)(
                                                        (vlSelf->__PVT__a_q__DOT__ram 
                                                         >> 0x32U)));
        vlSelf->auto_in_d_bits_opcode = vlSelf->__PVT__da_bits_opcode;
    } else {
        vlSelf->auto_in_d_bits_corrupt = 0U;
        vlSelf->auto_in_d_bits_size = 0U;
        vlSelf->auto_in_d_bits_source = 0U;
        vlSelf->auto_in_d_bits_opcode = 0U;
    }
}

VL_ATTR_COLD void VysyxSoCFull_TLError___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__ferr__0(VysyxSoCFull_TLError* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLError___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__ferr__0\n"); );
    // Body
    vlSelf->__PVT__da_first = (0U == (IData)(vlSelf->__PVT__r_counter));
    vlSelf->__PVT__idle_1 = (0U == (IData)(vlSelf->__PVT__beatsLeft));
    vlSelf->__PVT__monitor__DOT__a_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_2 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_2));
    vlSelf->__PVT__da_bits_opcode = ((0x17U >= (0x1fU 
                                                & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSelf->__PVT__a_q__DOT__ram 
                                                               >> 0x3cU))))))
                                      ? (7U & (0x911240U 
                                               >> (0x1fU 
                                                   & ((IData)(3U) 
                                                      * 
                                                      (7U 
                                                       & (IData)(
                                                                 (vlSelf->__PVT__a_q__DOT__ram 
                                                                  >> 0x3cU)))))))
                                      : 0U);
    vlSelf->__VdfgTmp_hec6944b2__0 = ((0U == (IData)(vlSelf->__PVT__beatsLeft)) 
                                      | (IData)(vlSelf->__PVT__state_1));
    vlSelf->__PVT__a_last_beats1 = ((1U & (IData)((vlSelf->__PVT__a_q__DOT__ram 
                                                   >> 0x3eU)))
                                     ? 0U : (7U & (~ 
                                                   (0x3ffU 
                                                    & (((IData)(0x1fU) 
                                                        << 
                                                        (7U 
                                                         & (IData)(
                                                                   (vlSelf->__PVT__a_q__DOT__ram 
                                                                    >> 0x36U)))) 
                                                       >> 2U)))));
    vlSelf->__PVT__r_beats1 = ((1U & (IData)(vlSelf->__PVT__da_bits_opcode))
                                ? (7U & (~ (0x3ffU 
                                            & (((IData)(0x1fU) 
                                                << 
                                                (7U 
                                                 & (IData)(
                                                           (vlSelf->__PVT__a_q__DOT__ram 
                                                            >> 0x36U)))) 
                                               >> 2U))))
                                : 0U);
    vlSelf->__PVT__a_last = ((1U == (IData)(vlSelf->__PVT__a_last_counter)) 
                             | (0U == (IData)(vlSelf->__PVT__a_last_beats1)));
    vlSelf->__PVT__winner_1 = ((IData)(vlSelf->__PVT__a_q__DOT__full) 
                               & ((IData)(vlSelf->__PVT__a_last) 
                                  & (IData)(vlSelf->__PVT__idle)));
    vlSelf->auto_in_d_bits_denied = ((0U == (IData)(vlSelf->__PVT__beatsLeft))
                                      ? (IData)(vlSelf->__PVT__winner_1)
                                      : (IData)(vlSelf->__PVT__state_1));
    vlSelf->auto_in_d_valid = ((IData)(vlSelf->__VdfgTmp_hec6944b2__0) 
                               & (IData)(vlSelf->__PVT__winner_1));
    if (vlSelf->auto_in_d_bits_denied) {
        vlSelf->auto_in_d_bits_size = (7U & (IData)(
                                                    (vlSelf->__PVT__a_q__DOT__ram 
                                                     >> 0x36U)));
        vlSelf->auto_in_d_bits_source = (0xfU & (IData)(
                                                        (vlSelf->__PVT__a_q__DOT__ram 
                                                         >> 0x32U)));
        vlSelf->auto_in_d_bits_opcode = vlSelf->__PVT__da_bits_opcode;
        vlSelf->auto_in_d_bits_corrupt = (1U & (IData)(vlSelf->__PVT__da_bits_opcode));
    } else {
        vlSelf->auto_in_d_bits_size = 0U;
        vlSelf->auto_in_d_bits_source = 0U;
        vlSelf->auto_in_d_bits_opcode = 0U;
        vlSelf->auto_in_d_bits_corrupt = 0U;
    }
}

VL_ATTR_COLD void VysyxSoCFull_TLError___ctor_var_reset(VysyxSoCFull_TLError* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLError___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->auto_in_a_ready = VL_RAND_RESET_I(1);
    vlSelf->auto_in_a_valid = VL_RAND_RESET_I(1);
    vlSelf->auto_in_a_bits_opcode = VL_RAND_RESET_I(3);
    vlSelf->auto_in_a_bits_size = VL_RAND_RESET_I(3);
    vlSelf->auto_in_a_bits_source = VL_RAND_RESET_I(4);
    vlSelf->auto_in_a_bits_address = VL_RAND_RESET_I(13);
    vlSelf->auto_in_a_bits_mask = VL_RAND_RESET_I(4);
    vlSelf->auto_in_a_bits_data = VL_RAND_RESET_I(32);
    vlSelf->auto_in_d_ready = VL_RAND_RESET_I(1);
    vlSelf->auto_in_d_valid = VL_RAND_RESET_I(1);
    vlSelf->auto_in_d_bits_opcode = VL_RAND_RESET_I(3);
    vlSelf->auto_in_d_bits_size = VL_RAND_RESET_I(3);
    vlSelf->auto_in_d_bits_source = VL_RAND_RESET_I(4);
    vlSelf->auto_in_d_bits_denied = VL_RAND_RESET_I(1);
    vlSelf->auto_in_d_bits_corrupt = VL_RAND_RESET_I(1);
    vlSelf->__PVT__da_ready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__da_bits_opcode = VL_RAND_RESET_I(3);
    vlSelf->__PVT__idle = VL_RAND_RESET_I(1);
    vlSelf->__PVT__a_last_beats1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__a_last_counter = VL_RAND_RESET_I(3);
    vlSelf->__PVT__a_last = VL_RAND_RESET_I(1);
    vlSelf->__PVT__r_beats1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__r_counter = VL_RAND_RESET_I(3);
    vlSelf->__PVT__da_first = VL_RAND_RESET_I(1);
    vlSelf->__PVT__a_q_io_deq_ready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__winner_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__beatsLeft = VL_RAND_RESET_I(3);
    vlSelf->__PVT__idle_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__state_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__unnamedblk1__DOT___GEN_1 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgTmp_hec6944b2__0 = 0;
    vlSelf->__PVT__monitor__DOT___a_first_T_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__a_first_counter = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__opcode = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__size = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__source = VL_RAND_RESET_I(4);
    vlSelf->__PVT__monitor__DOT__address = VL_RAND_RESET_I(13);
    vlSelf->__PVT__monitor__DOT__d_first_counter = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__opcode_1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__param_1 = VL_RAND_RESET_I(2);
    vlSelf->__PVT__monitor__DOT__size_1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__source_1 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__monitor__DOT__denied = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__inflight = VL_RAND_RESET_I(16);
    vlSelf->__PVT__monitor__DOT__inflight_opcodes = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__monitor__DOT__inflight_sizes = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__monitor__DOT__a_first_counter_1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__a_first_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__d_first_counter_1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__d_first_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT___GEN_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__watchdog = VL_RAND_RESET_I(32);
    vlSelf->__PVT__monitor__DOT__inflight_1 = VL_RAND_RESET_I(16);
    vlSelf->__PVT__monitor__DOT__inflight_sizes_1 = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__monitor__DOT__d_first_counter_2 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__d_first_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__watchdog_1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask = VL_RAND_RESET_I(4);
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready = VL_RAND_RESET_I(16);
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(131, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38);
    vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_39 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(143, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40);
    vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(143, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5);
    VL_RAND_RESET_W(131, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1);
    VL_RAND_RESET_W(143, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5);
    VL_RAND_RESET_W(131, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1);
    VL_RAND_RESET_W(143, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11);
    vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__monitor__DOT__plusarg_reader__DOT__myplus = VL_RAND_RESET_I(32);
    vlSelf->__PVT__monitor__DOT__plusarg_reader_1__DOT__myplus = VL_RAND_RESET_I(32);
    vlSelf->__PVT__a_q__DOT__ram = VL_RAND_RESET_Q(63);
    vlSelf->__PVT__a_q__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__a_q__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
}
