// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLToAXI4.h"

VL_ATTR_COLD void VysyxSoCFull_TLToAXI4___eval_initial__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4(VysyxSoCFull_TLToAXI4* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLToAXI4___eval_initial__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4\n"); );
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

VL_ATTR_COLD void VysyxSoCFull_TLToAXI4___ctor_var_reset(VysyxSoCFull_TLToAXI4* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLToAXI4___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->auto_in_a_ready = VL_RAND_RESET_I(1);
    vlSelf->auto_in_a_valid = VL_RAND_RESET_I(1);
    vlSelf->auto_in_a_bits_opcode = VL_RAND_RESET_I(3);
    vlSelf->auto_in_a_bits_param = VL_RAND_RESET_I(3);
    vlSelf->auto_in_a_bits_size = VL_RAND_RESET_I(3);
    vlSelf->auto_in_a_bits_source = VL_RAND_RESET_I(7);
    vlSelf->auto_in_a_bits_address = VL_RAND_RESET_I(32);
    vlSelf->auto_in_a_bits_mask = VL_RAND_RESET_I(4);
    vlSelf->auto_in_a_bits_data = VL_RAND_RESET_I(32);
    vlSelf->auto_in_a_bits_corrupt = VL_RAND_RESET_I(1);
    vlSelf->auto_in_d_ready = VL_RAND_RESET_I(1);
    vlSelf->auto_in_d_valid = VL_RAND_RESET_I(1);
    vlSelf->auto_in_d_bits_opcode = VL_RAND_RESET_I(3);
    vlSelf->auto_in_d_bits_size = VL_RAND_RESET_I(3);
    vlSelf->auto_in_d_bits_source = VL_RAND_RESET_I(7);
    vlSelf->auto_in_d_bits_denied = VL_RAND_RESET_I(1);
    vlSelf->auto_in_d_bits_data = VL_RAND_RESET_I(32);
    vlSelf->auto_in_d_bits_corrupt = VL_RAND_RESET_I(1);
    vlSelf->auto_out_awready = VL_RAND_RESET_I(1);
    vlSelf->auto_out_awvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_out_awid = VL_RAND_RESET_I(5);
    vlSelf->auto_out_awaddr = VL_RAND_RESET_I(32);
    vlSelf->auto_out_awlen = VL_RAND_RESET_I(8);
    vlSelf->auto_out_awsize = VL_RAND_RESET_I(3);
    vlSelf->auto_out_awburst = VL_RAND_RESET_I(2);
    vlSelf->auto_out_awecho_tl_state_size = VL_RAND_RESET_I(4);
    vlSelf->auto_out_awecho_tl_state_source = VL_RAND_RESET_I(7);
    vlSelf->auto_out_wready = VL_RAND_RESET_I(1);
    vlSelf->auto_out_wvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_out_wdata = VL_RAND_RESET_I(32);
    vlSelf->auto_out_wstrb = VL_RAND_RESET_I(4);
    vlSelf->auto_out_wlast = VL_RAND_RESET_I(1);
    vlSelf->auto_out_bready = VL_RAND_RESET_I(1);
    vlSelf->auto_out_bvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_out_bid = VL_RAND_RESET_I(5);
    vlSelf->auto_out_bresp = VL_RAND_RESET_I(2);
    vlSelf->auto_out_becho_tl_state_size = VL_RAND_RESET_I(4);
    vlSelf->auto_out_becho_tl_state_source = VL_RAND_RESET_I(7);
    vlSelf->auto_out_arready = VL_RAND_RESET_I(1);
    vlSelf->auto_out_arvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_out_arid = VL_RAND_RESET_I(5);
    vlSelf->auto_out_araddr = VL_RAND_RESET_I(32);
    vlSelf->auto_out_arlen = VL_RAND_RESET_I(8);
    vlSelf->auto_out_arsize = VL_RAND_RESET_I(3);
    vlSelf->auto_out_arburst = VL_RAND_RESET_I(2);
    vlSelf->auto_out_arecho_tl_state_size = VL_RAND_RESET_I(4);
    vlSelf->auto_out_arecho_tl_state_source = VL_RAND_RESET_I(7);
    vlSelf->auto_out_rready = VL_RAND_RESET_I(1);
    vlSelf->auto_out_rvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_out_rid = VL_RAND_RESET_I(5);
    vlSelf->auto_out_rdata = VL_RAND_RESET_I(32);
    vlSelf->auto_out_rresp = VL_RAND_RESET_I(2);
    vlSelf->auto_out_recho_tl_state_size = VL_RAND_RESET_I(4);
    vlSelf->auto_out_recho_tl_state_source = VL_RAND_RESET_I(7);
    vlSelf->auto_out_rlast = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_22 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_21 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_20 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_19 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_18 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_17 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_16 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_15 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_14 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_13 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_12 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_11 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_10 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_9 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_8 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_7 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__idStall_4 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__idStall_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__idStall_0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT___queue_arw_deq_q_io_deq_bits_wen = VL_RAND_RESET_I(1);
    vlSelf->__PVT__r_beats1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__r_counter = VL_RAND_RESET_I(3);
    vlSelf->__PVT__a_first = VL_RAND_RESET_I(1);
    vlSelf->__PVT__a_last = VL_RAND_RESET_I(1);
    vlSelf->__PVT__doneAW = VL_RAND_RESET_I(1);
    vlSelf->__PVT__stall = VL_RAND_RESET_I(1);
    vlSelf->__PVT___out_wvalid_T_3 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__out_arw_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__r_holds_d = VL_RAND_RESET_I(1);
    vlSelf->__PVT__b_delay = VL_RAND_RESET_I(3);
    vlSelf->__PVT__r_wins = VL_RAND_RESET_I(1);
    vlSelf->__PVT__r_first = VL_RAND_RESET_I(1);
    vlSelf->__PVT__r_denied_r = VL_RAND_RESET_I(1);
    vlSelf->__PVT__r_denied = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count = VL_RAND_RESET_I(5);
    vlSelf->__PVT__write = VL_RAND_RESET_I(1);
    vlSelf->__PVT___inc_T_22 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__inc = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_1 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__write_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__inc_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_2 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__write_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__inc_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__write_3 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__inc_3 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_4 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__write_4 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__inc_4 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_5 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__write_5 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__inc_5 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__count_6 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__write_6 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__inc_6 = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__nodeOut_wdeq_q__io_enq_valid = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__queue_arw_deq_q__io_deq_ready = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_size = VL_RAND_RESET_I(3);
    vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id = VL_RAND_RESET_I(5);
    vlSelf->__VdfgTmp_h3c545424__0 = 0;
    vlSelf->__VdfgTmp_hc0989b25__0 = 0;
    vlSelf->__PVT__monitor__DOT___a_first_T_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__a_first_counter = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__opcode = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__param = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__size = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__source = VL_RAND_RESET_I(7);
    vlSelf->__PVT__monitor__DOT__address = VL_RAND_RESET_I(32);
    vlSelf->__PVT__monitor__DOT__d_first_counter = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__opcode_1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__size_1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__source_1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__monitor__DOT__denied = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->__PVT__monitor__DOT__inflight);
    VL_RAND_RESET_W(512, vlSelf->__PVT__monitor__DOT__inflight_opcodes);
    VL_RAND_RESET_W(512, vlSelf->__PVT__monitor__DOT__inflight_sizes);
    vlSelf->__PVT__monitor__DOT__a_first_counter_1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__a_first_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__d_first_counter_1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__d_first_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT___GEN_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__watchdog = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->__PVT__monitor__DOT__inflight_1);
    VL_RAND_RESET_W(512, vlSelf->__PVT__monitor__DOT__inflight_sizes_1);
    vlSelf->__PVT__monitor__DOT__d_first_counter_2 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__monitor__DOT__d_first_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__watchdog_1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask = VL_RAND_RESET_I(4);
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok_1 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready);
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(1027, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
    vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(1039, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44);
    VL_RAND_RESET_W(1039, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5);
    VL_RAND_RESET_W(1027, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1);
    VL_RAND_RESET_W(1039, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5);
    VL_RAND_RESET_W(1027, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1);
    vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__monitor__DOT__plusarg_reader__DOT__myplus = VL_RAND_RESET_I(32);
    vlSelf->__PVT__monitor__DOT__plusarg_reader_1__DOT__myplus = VL_RAND_RESET_I(32);
    vlSelf->__PVT__nodeOut_wdeq_q__DOT__ram = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__nodeOut_wdeq_q__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__nodeOut_wdeq_q__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__queue_arw_deq_q__DOT__ram = VL_RAND_RESET_Q(62);
    vlSelf->__PVT__queue_arw_deq_q__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__queue_arw_deq_q__DOT__io_deq_valid_0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__queue_arw_deq_q__DOT__do_enq = VL_RAND_RESET_I(1);
}
