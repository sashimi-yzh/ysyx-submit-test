// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLBusBypass.h"

VL_ATTR_COLD void VysyxSoCFull_TLBusBypass___eval_initial__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___eval_initial__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h180e0517__0;
    VlWide<5>/*159:0*/ __Vtemp_h180e0517__1;
    VlWide<5>/*159:0*/ __Vtemp_h180e0517__2;
    VlWide<5>/*159:0*/ __Vtemp_h180e0517__3;
    // Body
    __Vtemp_h180e0517__0[0U] = 0x743d2564U;
    __Vtemp_h180e0517__0[1U] = 0x6d656f75U;
    __Vtemp_h180e0517__0[2U] = 0x6b5f7469U;
    __Vtemp_h180e0517__0[3U] = 0x656c696eU;
    __Vtemp_h180e0517__0[4U] = 0x74696cU;
    if ((! VL_VALUEPLUSARGS_INI(32, VL_CVT_PACK_STR_NW(5, __Vtemp_h180e0517__0), 
                                vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader__DOT__myplus))) {
        vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader__DOT__myplus = 0U;
    }
    __Vtemp_h180e0517__1[0U] = 0x743d2564U;
    __Vtemp_h180e0517__1[1U] = 0x6d656f75U;
    __Vtemp_h180e0517__1[2U] = 0x6b5f7469U;
    __Vtemp_h180e0517__1[3U] = 0x656c696eU;
    __Vtemp_h180e0517__1[4U] = 0x74696cU;
    if ((! VL_VALUEPLUSARGS_INI(32, VL_CVT_PACK_STR_NW(5, __Vtemp_h180e0517__1), 
                                vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus))) {
        vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus = 0U;
    }
    __Vtemp_h180e0517__2[0U] = 0x743d2564U;
    __Vtemp_h180e0517__2[1U] = 0x6d656f75U;
    __Vtemp_h180e0517__2[2U] = 0x6b5f7469U;
    __Vtemp_h180e0517__2[3U] = 0x656c696eU;
    __Vtemp_h180e0517__2[4U] = 0x74696cU;
    if ((! VL_VALUEPLUSARGS_INI(32, VL_CVT_PACK_STR_NW(5, __Vtemp_h180e0517__2), 
                                vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader__DOT__myplus))) {
        vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader__DOT__myplus = 0U;
    }
    __Vtemp_h180e0517__3[0U] = 0x743d2564U;
    __Vtemp_h180e0517__3[1U] = 0x6d656f75U;
    __Vtemp_h180e0517__3[2U] = 0x6b5f7469U;
    __Vtemp_h180e0517__3[3U] = 0x656c696eU;
    __Vtemp_h180e0517__3[4U] = 0x74696cU;
    if ((! VL_VALUEPLUSARGS_INI(32, VL_CVT_PACK_STR_NW(5, __Vtemp_h180e0517__3), 
                                vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus))) {
        vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus = 0U;
    }
}

VL_ATTR_COLD void VysyxSoCFull_TLBusBypass___ctor_var_reset(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->auto_node_out_out_a_ready = VL_RAND_RESET_I(1);
    vlSelf->auto_node_out_out_a_valid = VL_RAND_RESET_I(1);
    vlSelf->auto_node_out_out_a_bits_opcode = VL_RAND_RESET_I(3);
    vlSelf->auto_node_out_out_a_bits_size = VL_RAND_RESET_I(3);
    vlSelf->auto_node_out_out_a_bits_source = VL_RAND_RESET_I(4);
    vlSelf->auto_node_out_out_a_bits_address = VL_RAND_RESET_I(32);
    vlSelf->auto_node_out_out_a_bits_mask = VL_RAND_RESET_I(4);
    vlSelf->auto_node_out_out_a_bits_data = VL_RAND_RESET_I(32);
    vlSelf->auto_node_out_out_d_ready = VL_RAND_RESET_I(1);
    vlSelf->auto_node_out_out_d_valid = VL_RAND_RESET_I(1);
    vlSelf->auto_node_out_out_d_bits_opcode = VL_RAND_RESET_I(3);
    vlSelf->auto_node_out_out_d_bits_param = VL_RAND_RESET_I(2);
    vlSelf->auto_node_out_out_d_bits_size = VL_RAND_RESET_I(3);
    vlSelf->auto_node_out_out_d_bits_source = VL_RAND_RESET_I(4);
    vlSelf->auto_node_out_out_d_bits_sink = VL_RAND_RESET_I(5);
    vlSelf->auto_node_out_out_d_bits_denied = VL_RAND_RESET_I(1);
    vlSelf->auto_node_out_out_d_bits_data = VL_RAND_RESET_I(32);
    vlSelf->auto_node_out_out_d_bits_corrupt = VL_RAND_RESET_I(1);
    vlSelf->auto_node_in_in_a_ready = VL_RAND_RESET_I(1);
    vlSelf->auto_node_in_in_a_valid = VL_RAND_RESET_I(1);
    vlSelf->auto_node_in_in_a_bits_opcode = VL_RAND_RESET_I(3);
    vlSelf->auto_node_in_in_a_bits_size = VL_RAND_RESET_I(3);
    vlSelf->auto_node_in_in_a_bits_source = VL_RAND_RESET_I(4);
    vlSelf->auto_node_in_in_a_bits_address = VL_RAND_RESET_I(32);
    vlSelf->auto_node_in_in_a_bits_mask = VL_RAND_RESET_I(4);
    vlSelf->auto_node_in_in_a_bits_data = VL_RAND_RESET_I(32);
    vlSelf->auto_node_in_in_d_ready = VL_RAND_RESET_I(1);
    vlSelf->auto_node_in_in_d_valid = VL_RAND_RESET_I(1);
    vlSelf->auto_node_in_in_d_bits_opcode = VL_RAND_RESET_I(3);
    vlSelf->auto_node_in_in_d_bits_param = VL_RAND_RESET_I(2);
    vlSelf->auto_node_in_in_d_bits_size = VL_RAND_RESET_I(3);
    vlSelf->auto_node_in_in_d_bits_source = VL_RAND_RESET_I(4);
    vlSelf->auto_node_in_in_d_bits_sink = VL_RAND_RESET_I(5);
    vlSelf->auto_node_in_in_d_bits_denied = VL_RAND_RESET_I(1);
    vlSelf->auto_node_in_in_d_bits_data = VL_RAND_RESET_I(32);
    vlSelf->auto_node_in_in_d_bits_corrupt = VL_RAND_RESET_I(1);
    vlSelf->io_bypass = VL_RAND_RESET_I(1);
    vlSelf->__PVT___bar_auto_out_0_a_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT___bar_auto_out_0_d_ready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__in_reset = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__bypass_reg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__bypass = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__flight = VL_RAND_RESET_I(6);
    vlSelf->__PVT__bar__DOT__r_counter = VL_RAND_RESET_I(3);
    vlSelf->__PVT__bar__DOT__r_counter_3 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__bar__DOT__stall_counter = VL_RAND_RESET_I(3);
    vlSelf->__PVT__bar__DOT__stall_first = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__stall = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__a_first = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__r_beats1_3 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__d_first = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__unnamedblk2__DOT___stall_beats1_decode_T = VL_RAND_RESET_I(12);
    vlSelf->__PVT__bar__DOT__monitor__DOT___a_first_T_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter = VL_RAND_RESET_I(3);
    vlSelf->__PVT__bar__DOT__monitor__DOT__opcode = VL_RAND_RESET_I(3);
    vlSelf->__PVT__bar__DOT__monitor__DOT__size = VL_RAND_RESET_I(3);
    vlSelf->__PVT__bar__DOT__monitor__DOT__source = VL_RAND_RESET_I(4);
    vlSelf->__PVT__bar__DOT__monitor__DOT__address = VL_RAND_RESET_I(32);
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter = VL_RAND_RESET_I(3);
    vlSelf->__PVT__bar__DOT__monitor__DOT__opcode_1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__bar__DOT__monitor__DOT__param_1 = VL_RAND_RESET_I(2);
    vlSelf->__PVT__bar__DOT__monitor__DOT__size_1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__bar__DOT__monitor__DOT__source_1 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__bar__DOT__monitor__DOT__sink = VL_RAND_RESET_I(5);
    vlSelf->__PVT__bar__DOT__monitor__DOT__denied = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight = VL_RAND_RESET_I(16);
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_opcodes = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__monitor__DOT___GEN_0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog = VL_RAND_RESET_I(32);
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_1 = VL_RAND_RESET_I(16);
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes_1 = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_2 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog_1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask = VL_RAND_RESET_I(4);
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(131, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40);
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(143, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(143, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5);
    VL_RAND_RESET_W(131, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1);
    VL_RAND_RESET_W(143, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5);
    VL_RAND_RESET_W(131, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1);
    VL_RAND_RESET_W(143, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11);
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader__DOT__myplus = VL_RAND_RESET_I(32);
    vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus = VL_RAND_RESET_I(32);
    vlSelf->__PVT__error__DOT__da_ready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__da_bits_opcode = VL_RAND_RESET_I(3);
    vlSelf->__PVT__error__DOT__idle = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__a_last_beats1 = VL_RAND_RESET_I(10);
    vlSelf->__PVT__error__DOT__a_last_counter = VL_RAND_RESET_I(10);
    vlSelf->__PVT__error__DOT__a_last = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__r_beats1 = VL_RAND_RESET_I(10);
    vlSelf->__PVT__error__DOT__r_counter = VL_RAND_RESET_I(10);
    vlSelf->__PVT__error__DOT__da_first = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__nodeIn_a_ready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__winner_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__beatsLeft = VL_RAND_RESET_I(10);
    vlSelf->__PVT__error__DOT__idle_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__state_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__muxState_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__nodeIn_d_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__error__DOT__unnamedblk1__DOT___GEN_1 = VL_RAND_RESET_I(1);
    vlSelf->error__DOT____VdfgTmp_hc0029b36__0 = 0;
    vlSelf->__PVT__error__DOT__monitor__DOT___a_first_T_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter = VL_RAND_RESET_I(10);
    vlSelf->__PVT__error__DOT__monitor__DOT__opcode = VL_RAND_RESET_I(3);
    vlSelf->__PVT__error__DOT__monitor__DOT__size = VL_RAND_RESET_I(4);
    vlSelf->__PVT__error__DOT__monitor__DOT__source = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(128, vlSelf->__PVT__error__DOT__monitor__DOT__address);
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter = VL_RAND_RESET_I(10);
    vlSelf->__PVT__error__DOT__monitor__DOT__opcode_1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__error__DOT__monitor__DOT__size_1 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__error__DOT__monitor__DOT__source_1 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__error__DOT__monitor__DOT__denied = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight = VL_RAND_RESET_I(16);
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_opcodes = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(128, vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes);
    vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1 = VL_RAND_RESET_I(10);
    vlSelf->__PVT__error__DOT__monitor__DOT__a_first_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_1 = VL_RAND_RESET_I(10);
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__monitor__DOT__watchdog = VL_RAND_RESET_I(32);
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_1 = VL_RAND_RESET_I(16);
    VL_RAND_RESET_W(128, vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1);
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_2 = VL_RAND_RESET_I(10);
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__monitor__DOT__watchdog_1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask = VL_RAND_RESET_I(4);
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp = VL_RAND_RESET_I(1);
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(143, vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37);
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(143, vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5);
    VL_RAND_RESET_W(131, vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1);
    VL_RAND_RESET_W(143, vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5);
    VL_RAND_RESET_W(132, vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1);
    VL_RAND_RESET_W(143, vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11);
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 = VL_RAND_RESET_I(27);
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 = VL_RAND_RESET_I(27);
    vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader__DOT__myplus = VL_RAND_RESET_I(32);
    vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus = VL_RAND_RESET_I(32);
}
