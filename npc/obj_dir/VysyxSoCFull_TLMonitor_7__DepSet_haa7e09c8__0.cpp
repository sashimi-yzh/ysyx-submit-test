// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLMonitor_7.h"
#include "VysyxSoCFull__Syms.h"

VL_INLINE_OPT void VysyxSoCFull_TLMonitor_7___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__monitor__0(VysyxSoCFull_TLMonitor_7* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLMonitor_7___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__monitor__0\n"); );
    // Body
    vlSelf->__PVT___a_first_T_1 = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sinkA__DOT__inject_io_i_q__DOT__full)) 
                                   & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid));
    vlSelf->__PVT___GEN_1 = ((IData)(vlSelf->__PVT___a_first_T_1) 
                             & (0U == (IData)(vlSelf->__PVT__a_first_counter_1)));
}

VL_INLINE_OPT void VysyxSoCFull_TLMonitor_7___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__monitor__0(VysyxSoCFull_TLMonitor_7* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLMonitor_7___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__monitor__0\n"); );
    // Init
    SData/*11:0*/ __PVT__unnamedblk1__DOT___is_aligned_mask_T;
    __PVT__unnamedblk1__DOT___is_aligned_mask_T = 0;
    CData/*4:0*/ __PVT__unnamedblk1__DOT___GEN_6;
    __PVT__unnamedblk1__DOT___GEN_6 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_7;
    __PVT__unnamedblk1__DOT___GEN_7 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_8;
    __PVT__unnamedblk1__DOT___GEN_8 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_9;
    __PVT__unnamedblk1__DOT___GEN_9 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_10;
    __PVT__unnamedblk1__DOT___GEN_10 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_11;
    __PVT__unnamedblk1__DOT___GEN_11 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_12;
    __PVT__unnamedblk1__DOT___GEN_12 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_13;
    __PVT__unnamedblk1__DOT___GEN_13 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_14;
    __PVT__unnamedblk1__DOT___GEN_14 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_15;
    __PVT__unnamedblk1__DOT___GEN_15 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_16;
    __PVT__unnamedblk1__DOT___GEN_16 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_17;
    __PVT__unnamedblk1__DOT___GEN_17 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_18;
    __PVT__unnamedblk1__DOT___GEN_18 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_19;
    __PVT__unnamedblk1__DOT___GEN_19 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_20;
    __PVT__unnamedblk1__DOT___GEN_20 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_21;
    __PVT__unnamedblk1__DOT___GEN_21 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_22;
    __PVT__unnamedblk1__DOT___GEN_22 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_23;
    __PVT__unnamedblk1__DOT___GEN_23 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_24;
    __PVT__unnamedblk1__DOT___GEN_24 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_25;
    __PVT__unnamedblk1__DOT___GEN_25 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_26;
    __PVT__unnamedblk1__DOT___GEN_26 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_27;
    __PVT__unnamedblk1__DOT___GEN_27 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_28;
    __PVT__unnamedblk1__DOT___GEN_28 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_29;
    __PVT__unnamedblk1__DOT___GEN_29 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_30;
    __PVT__unnamedblk1__DOT___GEN_30 = 0;
    QData/*63:0*/ __PVT__unnamedblk1__DOT___GEN_31;
    __PVT__unnamedblk1__DOT___GEN_31 = 0;
    QData/*63:0*/ __PVT__unnamedblk1__DOT___a_opcode_lookup_T_1;
    __PVT__unnamedblk1__DOT___a_opcode_lookup_T_1 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___same_cycle_resp_T_1;
    __PVT__unnamedblk1__DOT___same_cycle_resp_T_1 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_32;
    __PVT__unnamedblk1__DOT___GEN_32 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_33;
    __PVT__unnamedblk1__DOT___GEN_33 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_34;
    __PVT__unnamedblk1__DOT___GEN_34 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_35;
    __PVT__unnamedblk1__DOT___GEN_35 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_36;
    __PVT__unnamedblk1__DOT___GEN_36 = 0;
    SData/*15:0*/ __PVT__unnamedblk1__DOT___GEN_37;
    __PVT__unnamedblk1__DOT___GEN_37 = 0;
    SData/*15:0*/ __PVT__unnamedblk1__DOT___GEN_38;
    __PVT__unnamedblk1__DOT___GEN_38 = 0;
    QData/*63:0*/ __PVT__unnamedblk1__DOT___a_size_lookup_T_1;
    __PVT__unnamedblk1__DOT___a_size_lookup_T_1 = 0;
    SData/*15:0*/ __PVT__unnamedblk1__DOT___GEN_39;
    __PVT__unnamedblk1__DOT___GEN_39 = 0;
    QData/*63:0*/ __PVT__unnamedblk1__DOT___c_size_lookup_T_1;
    __PVT__unnamedblk1__DOT___c_size_lookup_T_1 = 0;
    CData/*0:0*/ __PVT__unnamedblk2__DOT___d_first_T_2;
    __PVT__unnamedblk2__DOT___d_first_T_2 = 0;
    CData/*2:0*/ __Vdly__d_first_counter;
    __Vdly__d_first_counter = 0;
    SData/*15:0*/ __Vdly__inflight;
    __Vdly__inflight = 0;
    QData/*63:0*/ __Vdly__inflight_opcodes;
    __Vdly__inflight_opcodes = 0;
    QData/*63:0*/ __Vdly__inflight_sizes;
    __Vdly__inflight_sizes = 0;
    CData/*2:0*/ __Vdly__d_first_counter_1;
    __Vdly__d_first_counter_1 = 0;
    IData/*31:0*/ __Vdly__watchdog;
    __Vdly__watchdog = 0;
    SData/*15:0*/ __Vdly__inflight_1;
    __Vdly__inflight_1 = 0;
    QData/*63:0*/ __Vdly__inflight_sizes_1;
    __Vdly__inflight_sizes_1 = 0;
    CData/*2:0*/ __Vdly__d_first_counter_2;
    __Vdly__d_first_counter_2 = 0;
    IData/*31:0*/ __Vdly__watchdog_1;
    __Vdly__watchdog_1 = 0;
    CData/*2:0*/ __Vdly__a_first_counter;
    __Vdly__a_first_counter = 0;
    CData/*2:0*/ __Vdly__a_first_counter_1;
    __Vdly__a_first_counter_1 = 0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__0;
    VlWide<5>/*159:0*/ __Vtemp_h3bb56701__0;
    VlWide<5>/*159:0*/ __Vtemp_haad74c92__0;
    VlWide<5>/*159:0*/ __Vtemp_h39c01696__0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__1;
    VlWide<5>/*159:0*/ __Vtemp_h76cd2ac6__0;
    VlWide<5>/*159:0*/ __Vtemp_h0d81d63c__0;
    VlWide<5>/*159:0*/ __Vtemp_hf5c7abf0__0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__2;
    VlWide<5>/*159:0*/ __Vtemp_h4123b966__0;
    // Body
    __Vdly__watchdog_1 = vlSelf->__PVT__watchdog_1;
    __Vdly__inflight_sizes_1 = vlSelf->__PVT__inflight_sizes_1;
    __Vdly__inflight_1 = vlSelf->__PVT__inflight_1;
    __Vdly__watchdog = vlSelf->__PVT__watchdog;
    __Vdly__inflight_sizes = vlSelf->__PVT__inflight_sizes;
    __Vdly__inflight_opcodes = vlSelf->__PVT__inflight_opcodes;
    __Vdly__inflight = vlSelf->__PVT__inflight;
    __Vdly__d_first_counter = vlSelf->__PVT__d_first_counter;
    __Vdly__d_first_counter_2 = vlSelf->__PVT__d_first_counter_2;
    __Vdly__d_first_counter_1 = vlSelf->__PVT__d_first_counter_1;
    __Vdly__a_first_counter = vlSelf->__PVT__a_first_counter;
    __Vdly__a_first_counter_1 = vlSelf->__PVT__a_first_counter_1;
    __PVT__unnamedblk1__DOT___is_aligned_mask_T = (
                                                   (0xbU 
                                                    >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size))
                                                    ? 
                                                   (0xfffU 
                                                    & ((IData)(0x1fU) 
                                                       << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)))
                                                    : 0U);
    __PVT__unnamedblk1__DOT___GEN_6 = (0x1fU & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                                & (~ (IData)(__PVT__unnamedblk1__DOT___is_aligned_mask_T))));
    vlSelf->__PVT__unnamedblk1__DOT__mask_sub_0_1 = 
        (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size))) 
               | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                  & (~ (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                        >> 1U)))));
    vlSelf->__PVT__unnamedblk1__DOT__mask_sub_1_1 = 
        (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size))) 
               | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                  & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                     >> 1U))));
    vlSelf->__PVT__unnamedblk1__DOT__mask = ((8U & 
                                              (((IData)(vlSelf->__PVT__unnamedblk1__DOT__mask_sub_1_1) 
                                                << 3U) 
                                               | (0xfffffff8U 
                                                  & ((vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                                      << 2U) 
                                                     & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                                        << 3U))))) 
                                             | ((((IData)(vlSelf->__PVT__unnamedblk1__DOT__mask_sub_1_1) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address))) 
                                                 << 2U) 
                                                | ((((IData)(vlSelf->__PVT__unnamedblk1__DOT__mask_sub_0_1) 
                                                     | (1U 
                                                        == 
                                                        (3U 
                                                         & vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address))) 
                                                    << 1U) 
                                                   | ((IData)(vlSelf->__PVT__unnamedblk1__DOT__mask_sub_0_1) 
                                                      | (0U 
                                                         == 
                                                         (3U 
                                                          & vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address))))));
    __PVT__unnamedblk1__DOT___GEN_7 = ((5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)) 
                                       & (3U == (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                                 >> 0x1eU)));
    __PVT__unnamedblk1__DOT___GEN_8 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                        & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                       & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_9 = (0xfU != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_mask));
    __PVT__unnamedblk1__DOT___GEN_10 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (7U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_11 = ((3U != (3U 
                                                & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                                                   >> 1U))) 
                                        & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                           >> 0x1eU));
    __PVT__unnamedblk1__DOT___GEN_12 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (4U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_13 = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_mask) 
                                        != (IData)(vlSelf->__PVT__unnamedblk1__DOT__mask));
    __PVT__unnamedblk1__DOT___GEN_14 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (0U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_15 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (1U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_16 = ((3U > (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)) 
                                        & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                           >> 0x1eU));
    __PVT__unnamedblk1__DOT___GEN_17 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (2U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_18 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (3U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_19 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_20 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_21 = (0U == (3U & 
                                               ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_size) 
                                                >> 1U)));
    __PVT__unnamedblk1__DOT___GEN_22 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (4U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_23 = (2U == (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param)));
    __PVT__unnamedblk1__DOT___GEN_24 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_25 = (1U & ((~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param) 
                                                  >> 2U)) 
                                              | (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_corrupt)));
    __PVT__unnamedblk1__DOT___GEN_26 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (0U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_27 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (1U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_28 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (2U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_31 = ((QData)((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source)) 
                                        << 2U);
    __PVT__unnamedblk1__DOT___same_cycle_resp_T_1 = 
        ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
         & (0U == (IData)(vlSelf->__PVT__a_first_counter_1)));
    vlSelf->__PVT__unnamedblk1__DOT__a_set_wo_ready 
        = ((IData)(__PVT__unnamedblk1__DOT___same_cycle_resp_T_1)
            ? ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source))
                ? (0xffffU & ((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source)))
                : 0U) : 0U);
    __PVT__unnamedblk1__DOT___GEN_32 = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                        & (0U == (IData)(vlSelf->__PVT__d_first_counter_1)));
    __PVT__unnamedblk1__DOT___GEN_33 = ((IData)(__PVT__unnamedblk1__DOT___GEN_32) 
                                        & (6U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode)));
    vlSelf->__PVT__unnamedblk1__DOT__same_cycle_resp 
        = ((IData)(__PVT__unnamedblk1__DOT___same_cycle_resp_T_1) 
           & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
              == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source)));
    __PVT__unnamedblk1__DOT___GEN_34 = (((IData)(__PVT__unnamedblk1__DOT___GEN_33) 
                                         & (IData)(vlSelf->__PVT__unnamedblk1__DOT__same_cycle_resp)) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_35 = (((IData)(__PVT__unnamedblk1__DOT___GEN_33) 
                                         & (~ (IData)(vlSelf->__PVT__unnamedblk1__DOT__same_cycle_resp))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_36 = ((((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                          & (0U == (IData)(vlSelf->__PVT__d_first_counter_2))) 
                                         & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_29 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (0U != (IData)(vlSelf->__PVT__a_first_counter))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_30 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (0U != (IData)(vlSelf->__PVT__d_first_counter))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___a_opcode_lookup_T_1 = 
        VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__inflight_opcodes, __PVT__unnamedblk1__DOT___GEN_31);
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_8) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_7))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10143: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10143, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10145: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10145, "");
    }
    if (VL_UNLIKELY(__PVT__unnamedblk1__DOT___GEN_8)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10149: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10149, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10151: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10151, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_8) 
                     & (~ (IData)((0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10155: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10155, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10157: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10157, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_8) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10161: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10161, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10163: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10163, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_8) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_9)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10167: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10167, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10169: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10169, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_10) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_7))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10173: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10173, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10175: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10175, "");
    }
    if (VL_UNLIKELY(__PVT__unnamedblk1__DOT___GEN_10)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10179: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10179, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10181: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10181, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_10) 
                     & (~ (IData)((0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10185: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10185, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10187: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10187, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_10) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10191: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10191, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10193: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10193, "");
    }
    if (VL_UNLIKELY(__PVT__unnamedblk1__DOT___GEN_10)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10197: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10197, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10199: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10199, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_10) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_9)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10203: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10203, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10205: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10205, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_12) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10209: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries Get type which slave claims it can't support (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10209, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10211: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10211, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_12) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10215: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Get address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10215, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10217: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10217, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_12) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10221: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Get contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10221, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10223: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10223, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_14) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10227: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries PutFull type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10227, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10229: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10229, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_14) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10233: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10233, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10235: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10235, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_14) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10239: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10239, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10241: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10241, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_15) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10245: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries PutPartial type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10245, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10247: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10247, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_15) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10251: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10251, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10253: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10253, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_15) 
                     & (0U != ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_mask) 
                               & (~ (IData)(vlSelf->__PVT__unnamedblk1__DOT__mask))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10257: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10257, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10259: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10259, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_17) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_16))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10263: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10263, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10265: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10265, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_17) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10269: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10269, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10271: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10271, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_17) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10275: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10275, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10277: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10277, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_18) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_16))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10281: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10281, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10283: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10283, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_18) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10287: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Logical address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10287, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10289: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10289, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_18) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10293: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Logical contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10293, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10295: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10295, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_19) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10299: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries Hint type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10299, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10301: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10301, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_19) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10305: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Hint address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10305, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10307: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10307, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_19) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10311: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Hint contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10311, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10313: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10313, "");
    }
    if (VL_UNLIKELY((((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_valid) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (7U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10317: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel has invalid opcode (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10317, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10319: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10319, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_20) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_21)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10323: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10323, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10325: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10325, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_20) 
                     & (0U != (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10329: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseeAck carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10329, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10331: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10331, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_20) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10335: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10335, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10337: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10337, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_20) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param) 
                        >> 2U)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10341: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck is denied (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10341, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10343: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10343, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_21)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10347: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel Grant smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10347, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10349: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10349, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_22) 
                     & (3U == (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10353: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel Grant carries invalid cap param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10353, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10355: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10355, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_23)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10359: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel Grant carries toN param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10359, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10361: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10361, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10365: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel Grant is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10365, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10367: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10367, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_24) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_21)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10371: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10371, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10373: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10373, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_24) 
                     & (3U == (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10377: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData carries invalid cap param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10377, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10379: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10379, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_24) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_23)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10383: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData carries toN param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10383, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10385: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10385, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_24) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_25))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10389: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10389, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10391: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10391, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_26) 
                     & (0U != (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10395: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10395, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10397: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10397, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_26) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10401: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10401, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10403: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10403, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_27) 
                     & (0U != (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10407: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10407, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10409: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10409, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_27) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_25))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10413: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10413, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10415: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10415, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_28) 
                     & (0U != (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10419: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel HintAck carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10419, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10421: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10421, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_28) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10425: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel HintAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10425, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10427: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10427, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode) 
                        != (IData)(vlSelf->__PVT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10431: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10431, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10433: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10433, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                        != (IData)(vlSelf->__PVT__size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10437: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10437, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10439: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10439, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
                        != (IData)(vlSelf->__PVT__source))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10443: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10443, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10445: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10445, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_29) 
                     & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                        != vlSelf->__PVT__address)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10449: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel address changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10449, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10451: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10451, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode) 
                        != (IData)(vlSelf->__PVT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10455: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10455, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10457: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10457, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_30) 
                     & ((3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param)) 
                        != (IData)(vlSelf->__PVT__param_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10461: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel param changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10461, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10463: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10463, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_size) 
                        != (IData)(vlSelf->__PVT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10467: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10467, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10469: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10469, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source) 
                        != (IData)(vlSelf->__PVT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10473: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10473, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10475: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10475, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_sink) 
                        != (IData)(vlSelf->__PVT__sink))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10479: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel sink changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10479, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10481: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10481, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_30) 
                     & ((1U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param) 
                               >> 2U)) != (IData)(vlSelf->__PVT__denied))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10485: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel denied changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10485, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10487: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10487, "");
    }
    __PVT__unnamedblk1__DOT___GEN_37 = ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source))
                                         ? (0xffffU 
                                            & ((IData)(vlSelf->__PVT__inflight) 
                                               >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source)))
                                         : 0U);
    if (VL_UNLIKELY((((IData)(vlSelf->__PVT___GEN_1) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_37)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10492: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel re-used a source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10492, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10494: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10494, "");
    }
    __PVT__unnamedblk1__DOT___GEN_38 = ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                         ? (0xffffU 
                                            & ((IData)(vlSelf->__PVT__inflight) 
                                               >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source)))
                                         : 0U);
    if (VL_UNLIKELY((((IData)(__PVT__unnamedblk1__DOT___GEN_33) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((IData)(__PVT__unnamedblk1__DOT___GEN_38) 
                           | (IData)(vlSelf->__PVT__unnamedblk1__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10499: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10499, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10501: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10501, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_34) 
                     & (~ (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode)))))
                                 : 0U)) | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode)))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10507: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10507, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10509: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10509, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_34) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                        != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10513: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10513, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10515: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10515, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_35) 
                     & (~ (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (__PVT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                             >> 1U))))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (IData)(
                                                            (__PVT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                             >> 1U)))))))
                                 : 0U)) | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (IData)(
                                                               (__PVT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                                >> 1U))))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (IData)(
                                                                     (__PVT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                                      >> 1U)))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10521: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10521, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10523: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10523, "");
    }
    __PVT__unnamedblk1__DOT___a_size_lookup_T_1 = VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__inflight_sizes, __PVT__unnamedblk1__DOT___GEN_31);
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_35) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_size) 
                        != (7U & (IData)((__PVT__unnamedblk1__DOT___a_size_lookup_T_1 
                                          >> 1U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10528: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10528, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10530: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10530, "");
    }
    if (VL_UNLIKELY((((((((IData)(__PVT__unnamedblk1__DOT___GEN_32) 
                          & (0U == (IData)(vlSelf->__PVT__a_first_counter_1))) 
                         & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid)) 
                        & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
                           == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source))) 
                       & (6U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_d_ready)) 
                           | (~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sinkA__DOT__inject_io_i_q__DOT__full))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10535: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: ready check\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10535, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10537: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10537, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((IData)(vlSelf->__PVT__unnamedblk1__DOT__a_set_wo_ready) 
                                  != ((IData)(__PVT__unnamedblk1__DOT___GEN_33)
                                       ? ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                           ? (0xffffU 
                                              & ((IData)(1U) 
                                                 << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source)))
                                           : 0U) : 0U)) 
                                 | (0U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__a_set_wo_ready)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10543: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'A' and 'D' concurrent, despite minlatency > 0 (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10543, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10545: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10545, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (IData)(vlSelf->__PVT__inflight)) 
                                  | (0U == vlSelf->__PVT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->__PVT__watchdog 
                                    < vlSelf->__PVT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10551: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10551, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10553: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10553, "");
    }
    __PVT__unnamedblk1__DOT___GEN_39 = ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                         ? (0xffffU 
                                            & ((IData)(vlSelf->__PVT__inflight_1) 
                                               >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source)))
                                         : 0U);
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_36) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_39))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10558: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10558, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10560: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10560, "");
    }
    __PVT__unnamedblk1__DOT___c_size_lookup_T_1 = VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__inflight_sizes_1, __PVT__unnamedblk1__DOT___GEN_31);
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_36) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_size) 
                        != (7U & (IData)((__PVT__unnamedblk1__DOT___c_size_lookup_T_1 
                                          >> 1U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10565: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10565, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10567: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10567, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (IData)(vlSelf->__PVT__inflight_1)) 
                                  | (0U == vlSelf->__PVT__plusarg_reader_1__DOT__myplus)) 
                                 | (vlSelf->__PVT__watchdog_1 
                                    < vlSelf->__PVT__plusarg_reader_1__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10573: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10573, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10575: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10575, "");
    }
    __PVT__unnamedblk2__DOT___d_first_T_2 = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass.auto_node_out_out_d_ready) 
                                             & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_valid));
    if (vlSymsp->TOP.reset) {
        __Vdly__d_first_counter = 0U;
        __Vdly__inflight = 0U;
        __Vdly__inflight_opcodes = 0ULL;
        __Vdly__inflight_sizes = 0ULL;
        __Vdly__d_first_counter_1 = 0U;
        __Vdly__watchdog = 0U;
        __Vdly__inflight_1 = 0U;
        __Vdly__inflight_sizes_1 = 0ULL;
        __Vdly__d_first_counter_2 = 0U;
        __Vdly__watchdog_1 = 0U;
        __Vdly__a_first_counter = 0U;
        __Vdly__a_first_counter_1 = 0U;
    } else {
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[0U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
               << 2U);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[1U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
               >> 0x1eU);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[2U] = 0U;
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[3U] = 0U;
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[4U] = 0U;
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source) 
               << 2U);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[1U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source) 
               >> 0x1eU);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[2U] = 0U;
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[3U] = 0U;
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[4U] = 0U;
        __Vtemp_h6f0d4cc8__0[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__0[1U] = 0U;
        __Vtemp_h6f0d4cc8__0[2U] = 0U;
        __Vtemp_h6f0d4cc8__0[3U] = 0U;
        __Vtemp_h6f0d4cc8__0[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_h3bb56701__0, __Vtemp_h6f0d4cc8__0, vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U] 
            = __Vtemp_h3bb56701__0[0U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U] 
            = __Vtemp_h3bb56701__0[1U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[2U] 
            = __Vtemp_h3bb56701__0[2U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[3U] 
            = __Vtemp_h3bb56701__0[3U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[4U] 
            = (0x7fffU & __Vtemp_h3bb56701__0[4U]);
        if (vlSelf->__PVT___GEN_1) {
            __Vtemp_haad74c92__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode) 
                                              << 1U));
            __Vtemp_h0d81d63c__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                                              << 1U));
        } else {
            __Vtemp_haad74c92__0[0U] = 0U;
            __Vtemp_h0d81d63c__0[0U] = 0U;
        }
        __Vtemp_haad74c92__0[1U] = 0U;
        __Vtemp_haad74c92__0[2U] = 0U;
        __Vtemp_haad74c92__0[3U] = 0U;
        __Vtemp_haad74c92__0[4U] = 0U;
        VL_SHIFTL_WWW(131,131,131, __Vtemp_h39c01696__0, __Vtemp_haad74c92__0, vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U] 
            = __Vtemp_h39c01696__0[0U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U] 
            = __Vtemp_h39c01696__0[1U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[2U] 
            = __Vtemp_h39c01696__0[2U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[3U] 
            = __Vtemp_h39c01696__0[3U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[4U] 
            = (7U & __Vtemp_h39c01696__0[4U]);
        __Vtemp_h6f0d4cc8__1[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__1[1U] = 0U;
        __Vtemp_h6f0d4cc8__1[2U] = 0U;
        __Vtemp_h6f0d4cc8__1[3U] = 0U;
        __Vtemp_h6f0d4cc8__1[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_h76cd2ac6__0, __Vtemp_h6f0d4cc8__1, vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U] 
            = __Vtemp_h76cd2ac6__0[0U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U] 
            = __Vtemp_h76cd2ac6__0[1U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[2U] 
            = __Vtemp_h76cd2ac6__0[2U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[3U] 
            = __Vtemp_h76cd2ac6__0[3U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[4U] 
            = (0x7fffU & __Vtemp_h76cd2ac6__0[4U]);
        __Vtemp_h0d81d63c__0[1U] = 0U;
        __Vtemp_h0d81d63c__0[2U] = 0U;
        __Vtemp_h0d81d63c__0[3U] = 0U;
        __Vtemp_h0d81d63c__0[4U] = 0U;
        VL_SHIFTL_WWW(131,131,131, __Vtemp_hf5c7abf0__0, __Vtemp_h0d81d63c__0, vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U] 
            = __Vtemp_hf5c7abf0__0[0U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U] 
            = __Vtemp_hf5c7abf0__0[1U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[2U] 
            = __Vtemp_hf5c7abf0__0[2U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[3U] 
            = __Vtemp_hf5c7abf0__0[3U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[4U] 
            = (7U & __Vtemp_hf5c7abf0__0[4U]);
        __Vtemp_h6f0d4cc8__2[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__2[1U] = 0U;
        __Vtemp_h6f0d4cc8__2[2U] = 0U;
        __Vtemp_h6f0d4cc8__2[3U] = 0U;
        __Vtemp_h6f0d4cc8__2[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_h4123b966__0, __Vtemp_h6f0d4cc8__2, vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[0U] 
            = __Vtemp_h4123b966__0[0U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[1U] 
            = __Vtemp_h4123b966__0[1U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[2U] 
            = __Vtemp_h4123b966__0[2U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[3U] 
            = __Vtemp_h4123b966__0[3U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[4U] 
            = (0x7fffU & __Vtemp_h4123b966__0[4U]);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41 
            = (((IData)(__PVT__unnamedblk2__DOT___d_first_T_2) 
                & (IData)(vlSelf->__PVT__d_first_1)) 
               & (6U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode)));
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43 
            = (((IData)(__PVT__unnamedblk2__DOT___d_first_T_2) 
                & (IData)(vlSelf->__PVT__d_first_2)) 
               & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode)));
        if (__PVT__unnamedblk2__DOT___d_first_T_2) {
            vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                = (0xfffU & ((IData)(0x1fU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_size)));
            __Vdly__d_first_counter = (7U & ((0U != (IData)(vlSelf->__PVT__d_first_counter))
                                              ? ((IData)(vlSelf->__PVT__d_first_counter) 
                                                 - (IData)(1U))
                                              : ((1U 
                                                  & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode))
                                                  ? 
                                                 (~ 
                                                  ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                                   >> 2U))
                                                  : 0U)));
            __Vdly__d_first_counter_1 = (7U & ((IData)(vlSelf->__PVT__d_first_1)
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode))
                                                    ? 
                                                   (~ 
                                                    ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                                     >> 2U))
                                                    : 0U)
                                                : ((IData)(vlSelf->__PVT__d_first_counter_1) 
                                                   - (IData)(1U))));
            __Vdly__d_first_counter_2 = (7U & ((IData)(vlSelf->__PVT__d_first_2)
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode))
                                                    ? 
                                                   (~ 
                                                    ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                                     >> 2U))
                                                    : 0U)
                                                : ((IData)(vlSelf->__PVT__d_first_counter_2) 
                                                   - (IData)(1U))));
            __Vdly__watchdog_1 = 0U;
        } else {
            __Vdly__watchdog_1 = ((IData)(1U) + vlSelf->__PVT__watchdog_1);
        }
        __Vdly__inflight = (0xffffU & (((IData)(vlSelf->__PVT__inflight) 
                                        | ((IData)(vlSelf->__PVT___GEN_1)
                                            ? ((0xfU 
                                                >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source))
                                                ? ((IData)(1U) 
                                                   << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source))
                                                : 0U)
                                            : 0U)) 
                                       & (~ ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41)
                                              ? ((0xfU 
                                                  >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                                  ? 
                                                 ((IData)(1U) 
                                                  << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                                  : 0U)
                                              : 0U))));
        __Vdly__inflight_opcodes = ((vlSelf->__PVT__inflight_opcodes 
                                     | ((IData)(vlSelf->__PVT___GEN_1)
                                         ? (((QData)((IData)(
                                                             vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U])))
                                         : 0ULL)) & 
                                    (~ ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41)
                                         ? (((QData)((IData)(
                                                             vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U])))
                                         : 0ULL)));
        __Vdly__inflight_sizes = ((vlSelf->__PVT__inflight_sizes 
                                   | ((IData)(vlSelf->__PVT___GEN_1)
                                       ? (((QData)((IData)(
                                                           vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U])))
                                       : 0ULL)) & (~ 
                                                   ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U])))
                                                     : 0ULL)));
        __Vdly__watchdog = (((IData)(vlSelf->__PVT___a_first_T_1) 
                             | (IData)(__PVT__unnamedblk2__DOT___d_first_T_2))
                             ? 0U : ((IData)(1U) + vlSelf->__PVT__watchdog));
        __Vdly__inflight_1 = ((IData)(vlSelf->__PVT__inflight_1) 
                              & (~ ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                                     ? ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                         ? ((IData)(1U) 
                                            << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                         : 0U) : 0U)));
        __Vdly__inflight_sizes_1 = (vlSelf->__PVT__inflight_sizes_1 
                                    & (~ ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                                           ? (((QData)((IData)(
                                                               vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[1U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[0U])))
                                           : 0ULL)));
        if (vlSelf->__PVT___a_first_T_1) {
            vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 
                = ((0xbU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size))
                    ? (0xfffU & ((IData)(0x1fU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)))
                    : 0U);
            __Vdly__a_first_counter = (7U & ((0U != (IData)(vlSelf->__PVT__a_first_counter))
                                              ? ((IData)(vlSelf->__PVT__a_first_counter) 
                                                 - (IData)(1U))
                                              : ((4U 
                                                  & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))
                                                  ? 0U
                                                  : 
                                                 (~ 
                                                  ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3) 
                                                   >> 2U)))));
            __Vdly__a_first_counter_1 = (7U & ((IData)(vlSelf->__PVT__a_first_1)
                                                ? (
                                                   (4U 
                                                    & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))
                                                    ? 0U
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3) 
                                                     >> 2U)))
                                                : ((IData)(vlSelf->__PVT__a_first_counter_1) 
                                                   - (IData)(1U))));
        }
    }
    if (((IData)(__PVT__unnamedblk2__DOT___d_first_T_2) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__d_first_counter)))))) {
        vlSelf->__PVT__opcode_1 = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode;
        vlSelf->__PVT__param_1 = (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param));
        vlSelf->__PVT__size_1 = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_size;
        vlSelf->__PVT__source_1 = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source;
        vlSelf->__PVT__sink = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_sink;
        vlSelf->__PVT__denied = (1U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param) 
                                       >> 2U));
    }
    if (((IData)(vlSelf->__PVT___a_first_T_1) & (~ (IData)(
                                                           (0U 
                                                            != (IData)(vlSelf->__PVT__a_first_counter)))))) {
        vlSelf->__PVT__opcode = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode;
        vlSelf->__PVT__size = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size;
        vlSelf->__PVT__source = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source;
        vlSelf->__PVT__address = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address;
    }
    vlSelf->__PVT__d_first_counter = __Vdly__d_first_counter;
    vlSelf->__PVT__inflight = __Vdly__inflight;
    vlSelf->__PVT__inflight_opcodes = __Vdly__inflight_opcodes;
    vlSelf->__PVT__inflight_sizes = __Vdly__inflight_sizes;
    vlSelf->__PVT__watchdog = __Vdly__watchdog;
    vlSelf->__PVT__inflight_1 = __Vdly__inflight_1;
    vlSelf->__PVT__inflight_sizes_1 = __Vdly__inflight_sizes_1;
    vlSelf->__PVT__watchdog_1 = __Vdly__watchdog_1;
    vlSelf->__PVT__d_first_counter_1 = __Vdly__d_first_counter_1;
    vlSelf->__PVT__d_first_counter_2 = __Vdly__d_first_counter_2;
    vlSelf->__PVT__a_first_counter = __Vdly__a_first_counter;
    vlSelf->__PVT__a_first_counter_1 = __Vdly__a_first_counter_1;
    vlSelf->__PVT__d_first_1 = (0U == (IData)(vlSelf->__PVT__d_first_counter_1));
    vlSelf->__PVT__d_first_2 = (0U == (IData)(vlSelf->__PVT__d_first_counter_2));
    vlSelf->__PVT__a_first_1 = (0U == (IData)(vlSelf->__PVT__a_first_counter_1));
}

VL_INLINE_OPT void VysyxSoCFull_TLMonitor_7___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__monitor__0(VysyxSoCFull_TLMonitor_7* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLMonitor_7___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__monitor__0\n"); );
    // Init
    SData/*11:0*/ __PVT__unnamedblk1__DOT___is_aligned_mask_T;
    __PVT__unnamedblk1__DOT___is_aligned_mask_T = 0;
    CData/*4:0*/ __PVT__unnamedblk1__DOT___GEN_6;
    __PVT__unnamedblk1__DOT___GEN_6 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_7;
    __PVT__unnamedblk1__DOT___GEN_7 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_8;
    __PVT__unnamedblk1__DOT___GEN_8 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_9;
    __PVT__unnamedblk1__DOT___GEN_9 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_10;
    __PVT__unnamedblk1__DOT___GEN_10 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_11;
    __PVT__unnamedblk1__DOT___GEN_11 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_12;
    __PVT__unnamedblk1__DOT___GEN_12 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_13;
    __PVT__unnamedblk1__DOT___GEN_13 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_14;
    __PVT__unnamedblk1__DOT___GEN_14 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_15;
    __PVT__unnamedblk1__DOT___GEN_15 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_16;
    __PVT__unnamedblk1__DOT___GEN_16 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_17;
    __PVT__unnamedblk1__DOT___GEN_17 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_18;
    __PVT__unnamedblk1__DOT___GEN_18 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_19;
    __PVT__unnamedblk1__DOT___GEN_19 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_20;
    __PVT__unnamedblk1__DOT___GEN_20 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_21;
    __PVT__unnamedblk1__DOT___GEN_21 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_22;
    __PVT__unnamedblk1__DOT___GEN_22 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_23;
    __PVT__unnamedblk1__DOT___GEN_23 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_24;
    __PVT__unnamedblk1__DOT___GEN_24 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_25;
    __PVT__unnamedblk1__DOT___GEN_25 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_26;
    __PVT__unnamedblk1__DOT___GEN_26 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_27;
    __PVT__unnamedblk1__DOT___GEN_27 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_28;
    __PVT__unnamedblk1__DOT___GEN_28 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_29;
    __PVT__unnamedblk1__DOT___GEN_29 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_30;
    __PVT__unnamedblk1__DOT___GEN_30 = 0;
    QData/*63:0*/ __PVT__unnamedblk1__DOT___GEN_31;
    __PVT__unnamedblk1__DOT___GEN_31 = 0;
    QData/*63:0*/ __PVT__unnamedblk1__DOT___a_opcode_lookup_T_1;
    __PVT__unnamedblk1__DOT___a_opcode_lookup_T_1 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___same_cycle_resp_T_1;
    __PVT__unnamedblk1__DOT___same_cycle_resp_T_1 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_32;
    __PVT__unnamedblk1__DOT___GEN_32 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_33;
    __PVT__unnamedblk1__DOT___GEN_33 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_34;
    __PVT__unnamedblk1__DOT___GEN_34 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_35;
    __PVT__unnamedblk1__DOT___GEN_35 = 0;
    CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_36;
    __PVT__unnamedblk1__DOT___GEN_36 = 0;
    SData/*15:0*/ __PVT__unnamedblk1__DOT___GEN_37;
    __PVT__unnamedblk1__DOT___GEN_37 = 0;
    SData/*15:0*/ __PVT__unnamedblk1__DOT___GEN_38;
    __PVT__unnamedblk1__DOT___GEN_38 = 0;
    QData/*63:0*/ __PVT__unnamedblk1__DOT___a_size_lookup_T_1;
    __PVT__unnamedblk1__DOT___a_size_lookup_T_1 = 0;
    SData/*15:0*/ __PVT__unnamedblk1__DOT___GEN_39;
    __PVT__unnamedblk1__DOT___GEN_39 = 0;
    QData/*63:0*/ __PVT__unnamedblk1__DOT___c_size_lookup_T_1;
    __PVT__unnamedblk1__DOT___c_size_lookup_T_1 = 0;
    CData/*0:0*/ __PVT__unnamedblk2__DOT___d_first_T_2;
    __PVT__unnamedblk2__DOT___d_first_T_2 = 0;
    CData/*2:0*/ __Vdly__d_first_counter;
    __Vdly__d_first_counter = 0;
    SData/*15:0*/ __Vdly__inflight;
    __Vdly__inflight = 0;
    QData/*63:0*/ __Vdly__inflight_opcodes;
    __Vdly__inflight_opcodes = 0;
    QData/*63:0*/ __Vdly__inflight_sizes;
    __Vdly__inflight_sizes = 0;
    CData/*2:0*/ __Vdly__d_first_counter_1;
    __Vdly__d_first_counter_1 = 0;
    IData/*31:0*/ __Vdly__watchdog;
    __Vdly__watchdog = 0;
    SData/*15:0*/ __Vdly__inflight_1;
    __Vdly__inflight_1 = 0;
    QData/*63:0*/ __Vdly__inflight_sizes_1;
    __Vdly__inflight_sizes_1 = 0;
    CData/*2:0*/ __Vdly__d_first_counter_2;
    __Vdly__d_first_counter_2 = 0;
    IData/*31:0*/ __Vdly__watchdog_1;
    __Vdly__watchdog_1 = 0;
    CData/*2:0*/ __Vdly__a_first_counter;
    __Vdly__a_first_counter = 0;
    CData/*2:0*/ __Vdly__a_first_counter_1;
    __Vdly__a_first_counter_1 = 0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__0;
    VlWide<5>/*159:0*/ __Vtemp_h3bb56701__0;
    VlWide<5>/*159:0*/ __Vtemp_h0552935f__0;
    VlWide<5>/*159:0*/ __Vtemp_h4b30de50__0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__1;
    VlWide<5>/*159:0*/ __Vtemp_h76cd2ac6__0;
    VlWide<5>/*159:0*/ __Vtemp_hbf550051__0;
    VlWide<5>/*159:0*/ __Vtemp_h09d64742__0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__2;
    VlWide<5>/*159:0*/ __Vtemp_h4123b966__0;
    // Body
    __Vdly__watchdog_1 = vlSelf->__PVT__watchdog_1;
    __Vdly__inflight_sizes_1 = vlSelf->__PVT__inflight_sizes_1;
    __Vdly__inflight_1 = vlSelf->__PVT__inflight_1;
    __Vdly__watchdog = vlSelf->__PVT__watchdog;
    __Vdly__inflight_sizes = vlSelf->__PVT__inflight_sizes;
    __Vdly__inflight_opcodes = vlSelf->__PVT__inflight_opcodes;
    __Vdly__inflight = vlSelf->__PVT__inflight;
    __Vdly__d_first_counter = vlSelf->__PVT__d_first_counter;
    __Vdly__d_first_counter_2 = vlSelf->__PVT__d_first_counter_2;
    __Vdly__d_first_counter_1 = vlSelf->__PVT__d_first_counter_1;
    __Vdly__a_first_counter = vlSelf->__PVT__a_first_counter;
    __Vdly__a_first_counter_1 = vlSelf->__PVT__a_first_counter_1;
    __PVT__unnamedblk1__DOT___is_aligned_mask_T = (
                                                   (0xbU 
                                                    >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size))
                                                    ? 
                                                   (0xfffU 
                                                    & ((IData)(0x1fU) 
                                                       << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)))
                                                    : 0U);
    __PVT__unnamedblk1__DOT___GEN_6 = (0x1fU & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                                & (~ (IData)(__PVT__unnamedblk1__DOT___is_aligned_mask_T))));
    vlSelf->__PVT__unnamedblk1__DOT__mask_sub_0_1 = 
        (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size))) 
               | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                  & (~ (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                        >> 1U)))));
    vlSelf->__PVT__unnamedblk1__DOT__mask_sub_1_1 = 
        (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size))) 
               | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                  & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                     >> 1U))));
    vlSelf->__PVT__unnamedblk1__DOT__mask = ((8U & 
                                              (((IData)(vlSelf->__PVT__unnamedblk1__DOT__mask_sub_1_1) 
                                                << 3U) 
                                               | (0xfffffff8U 
                                                  & ((vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                                      << 2U) 
                                                     & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                                        << 3U))))) 
                                             | ((((IData)(vlSelf->__PVT__unnamedblk1__DOT__mask_sub_1_1) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address))) 
                                                 << 2U) 
                                                | ((((IData)(vlSelf->__PVT__unnamedblk1__DOT__mask_sub_0_1) 
                                                     | (1U 
                                                        == 
                                                        (3U 
                                                         & vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address))) 
                                                    << 1U) 
                                                   | ((IData)(vlSelf->__PVT__unnamedblk1__DOT__mask_sub_0_1) 
                                                      | (0U 
                                                         == 
                                                         (3U 
                                                          & vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address))))));
    __PVT__unnamedblk1__DOT___GEN_7 = ((5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)) 
                                       & (3U == (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                                 >> 0x1eU)));
    __PVT__unnamedblk1__DOT___GEN_8 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                        & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                       & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_9 = (0xfU != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_mask));
    __PVT__unnamedblk1__DOT___GEN_10 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (7U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_11 = ((3U != (3U 
                                                & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                                                   >> 1U))) 
                                        & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                           >> 0x1eU));
    __PVT__unnamedblk1__DOT___GEN_12 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (4U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_13 = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_mask) 
                                        != (IData)(vlSelf->__PVT__unnamedblk1__DOT__mask));
    __PVT__unnamedblk1__DOT___GEN_14 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (0U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_15 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (1U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_16 = ((3U > (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)) 
                                        & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                           >> 0x1eU));
    __PVT__unnamedblk1__DOT___GEN_17 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (2U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_18 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (3U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_19 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_20 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_21 = (0U == (3U & 
                                               ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_size) 
                                                >> 1U)));
    __PVT__unnamedblk1__DOT___GEN_22 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (4U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_23 = (2U == (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param)));
    __PVT__unnamedblk1__DOT___GEN_24 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_25 = (1U & ((~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param) 
                                                  >> 2U)) 
                                              | (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_corrupt)));
    __PVT__unnamedblk1__DOT___GEN_26 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (0U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_27 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (1U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_28 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (2U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_31 = ((QData)((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source)) 
                                        << 2U);
    __PVT__unnamedblk1__DOT___same_cycle_resp_T_1 = 
        ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
         & (0U == (IData)(vlSelf->__PVT__a_first_counter_1)));
    vlSelf->__PVT__unnamedblk1__DOT__a_set_wo_ready 
        = ((IData)(__PVT__unnamedblk1__DOT___same_cycle_resp_T_1)
            ? ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source))
                ? (0xffffU & ((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source)))
                : 0U) : 0U);
    __PVT__unnamedblk1__DOT___GEN_32 = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                        & (0U == (IData)(vlSelf->__PVT__d_first_counter_1)));
    __PVT__unnamedblk1__DOT___GEN_33 = ((IData)(__PVT__unnamedblk1__DOT___GEN_32) 
                                        & (6U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode)));
    vlSelf->__PVT__unnamedblk1__DOT__same_cycle_resp 
        = ((IData)(__PVT__unnamedblk1__DOT___same_cycle_resp_T_1) 
           & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
              == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source)));
    __PVT__unnamedblk1__DOT___GEN_34 = (((IData)(__PVT__unnamedblk1__DOT___GEN_33) 
                                         & (IData)(vlSelf->__PVT__unnamedblk1__DOT__same_cycle_resp)) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_35 = (((IData)(__PVT__unnamedblk1__DOT___GEN_33) 
                                         & (~ (IData)(vlSelf->__PVT__unnamedblk1__DOT__same_cycle_resp))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_36 = ((((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                          & (0U == (IData)(vlSelf->__PVT__d_first_counter_2))) 
                                         & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_29 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid) 
                                         & (0U != (IData)(vlSelf->__PVT__a_first_counter))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___GEN_30 = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_valid) 
                                         & (0U != (IData)(vlSelf->__PVT__d_first_counter))) 
                                        & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__unnamedblk1__DOT___a_opcode_lookup_T_1 = 
        VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__inflight_opcodes, __PVT__unnamedblk1__DOT___GEN_31);
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_8) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_7))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10143: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10143, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10145: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10145, "");
    }
    if (VL_UNLIKELY(__PVT__unnamedblk1__DOT___GEN_8)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10149: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10149, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10151: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10151, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_8) 
                     & (~ (IData)((0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10155: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10155, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10157: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10157, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_8) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10161: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10161, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10163: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10163, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_8) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_9)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10167: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10167, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10169: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10169, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_10) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_7))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10173: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10173, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10175: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10175, "");
    }
    if (VL_UNLIKELY(__PVT__unnamedblk1__DOT___GEN_10)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10179: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10179, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10181: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10181, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_10) 
                     & (~ (IData)((0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10185: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10185, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10187: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10187, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_10) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10191: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10191, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10193: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10193, "");
    }
    if (VL_UNLIKELY(__PVT__unnamedblk1__DOT___GEN_10)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10197: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10197, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10199: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10199, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_10) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_9)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10203: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10203, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10205: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10205, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_12) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10209: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries Get type which slave claims it can't support (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10209, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10211: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10211, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_12) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10215: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Get address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10215, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10217: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10217, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_12) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10221: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Get contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10221, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10223: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10223, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_14) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10227: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries PutFull type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10227, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10229: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10229, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_14) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10233: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10233, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10235: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10235, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_14) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10239: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10239, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10241: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10241, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_15) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10245: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries PutPartial type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10245, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10247: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10247, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_15) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10251: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10251, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10253: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10253, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_15) 
                     & (0U != ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_mask) 
                               & (~ (IData)(vlSelf->__PVT__unnamedblk1__DOT__mask))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10257: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10257, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10259: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10259, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_17) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_16))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10263: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10263, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10265: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10265, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_17) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10269: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10269, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10271: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10271, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_17) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10275: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10275, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10277: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10277, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_18) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_16))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10281: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10281, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10283: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10283, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_18) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10287: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Logical address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10287, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10289: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10289, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_18) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10293: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Logical contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10293, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10295: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10295, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_19) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10299: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel carries Hint type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10299, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10301: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10301, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_19) 
                     & (0U != (IData)(__PVT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10305: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Hint address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10305, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10307: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10307, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_19) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10311: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel Hint contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10311, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10313: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10313, "");
    }
    if (VL_UNLIKELY((((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_valid) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (7U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10317: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel has invalid opcode (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10317, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10319: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10319, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_20) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_21)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10323: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10323, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10325: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10325, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_20) 
                     & (0U != (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10329: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseeAck carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10329, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10331: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10331, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_20) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10335: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10335, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10337: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10337, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_20) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param) 
                        >> 2U)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10341: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck is denied (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10341, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10343: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10343, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_21)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10347: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel Grant smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10347, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10349: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10349, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_22) 
                     & (3U == (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10353: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel Grant carries invalid cap param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10353, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10355: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10355, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_23)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10359: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel Grant carries toN param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10359, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10361: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10361, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10365: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel Grant is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10365, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10367: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10367, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_24) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_21)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10371: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10371, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10373: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10373, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_24) 
                     & (3U == (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10377: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData carries invalid cap param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10377, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10379: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10379, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_24) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_23)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10383: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData carries toN param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10383, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10385: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10385, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_24) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_25))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10389: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10389, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10391: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10391, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_26) 
                     & (0U != (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10395: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10395, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10397: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10397, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_26) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10401: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10401, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10403: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10403, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_27) 
                     & (0U != (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10407: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10407, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10409: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10409, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_27) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_25))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10413: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10413, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10415: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10415, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_28) 
                     & (0U != (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10419: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel HintAck carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10419, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10421: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10421, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_28) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10425: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel HintAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10425, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10427: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10427, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode) 
                        != (IData)(vlSelf->__PVT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10431: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10431, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10433: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10433, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                        != (IData)(vlSelf->__PVT__size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10437: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10437, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10439: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10439, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
                        != (IData)(vlSelf->__PVT__source))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10443: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10443, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10445: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10445, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_29) 
                     & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                        != vlSelf->__PVT__address)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10449: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel address changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10449, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10451: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10451, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode) 
                        != (IData)(vlSelf->__PVT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10455: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10455, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10457: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10457, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_30) 
                     & ((3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param)) 
                        != (IData)(vlSelf->__PVT__param_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10461: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel param changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10461, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10463: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10463, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_size) 
                        != (IData)(vlSelf->__PVT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10467: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10467, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10469: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10469, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source) 
                        != (IData)(vlSelf->__PVT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10473: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10473, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10475: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10475, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_sink) 
                        != (IData)(vlSelf->__PVT__sink))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10479: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel sink changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10479, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10481: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10481, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_30) 
                     & ((1U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param) 
                               >> 2U)) != (IData)(vlSelf->__PVT__denied))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10485: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel denied changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10485, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10487: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10487, "");
    }
    __PVT__unnamedblk1__DOT___GEN_37 = ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source))
                                         ? (0xffffU 
                                            & ((IData)(vlSelf->__PVT__inflight) 
                                               >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source)))
                                         : 0U);
    if (VL_UNLIKELY((((IData)(vlSelf->__PVT___GEN_1) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (IData)(__PVT__unnamedblk1__DOT___GEN_37)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10492: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' channel re-used a source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10492, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10494: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10494, "");
    }
    __PVT__unnamedblk1__DOT___GEN_38 = ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                         ? (0xffffU 
                                            & ((IData)(vlSelf->__PVT__inflight) 
                                               >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source)))
                                         : 0U);
    if (VL_UNLIKELY((((IData)(__PVT__unnamedblk1__DOT___GEN_33) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((IData)(__PVT__unnamedblk1__DOT___GEN_38) 
                           | (IData)(vlSelf->__PVT__unnamedblk1__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10499: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10499, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10501: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10501, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_34) 
                     & (~ (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode)))))
                                 : 0U)) | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode)))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10507: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10507, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10509: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10509, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_34) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                        != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10513: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10513, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10515: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10515, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_35) 
                     & (~ (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (__PVT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                             >> 1U))))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (IData)(
                                                            (__PVT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                             >> 1U)))))))
                                 : 0U)) | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (IData)(
                                                               (__PVT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                                >> 1U))))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (IData)(
                                                                     (__PVT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                                      >> 1U)))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10521: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10521, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10523: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10523, "");
    }
    __PVT__unnamedblk1__DOT___a_size_lookup_T_1 = VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__inflight_sizes, __PVT__unnamedblk1__DOT___GEN_31);
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_35) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_size) 
                        != (7U & (IData)((__PVT__unnamedblk1__DOT___a_size_lookup_T_1 
                                          >> 1U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10528: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10528, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10530: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10530, "");
    }
    if (VL_UNLIKELY((((((((IData)(__PVT__unnamedblk1__DOT___GEN_32) 
                          & (0U == (IData)(vlSelf->__PVT__a_first_counter_1))) 
                         & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid)) 
                        & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
                           == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source))) 
                       & (6U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_d_ready)) 
                           | (~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sinkA__DOT__inject_io_i_q__DOT__full))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10535: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: ready check\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10535, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10537: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10537, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((IData)(vlSelf->__PVT__unnamedblk1__DOT__a_set_wo_ready) 
                                  != ((IData)(__PVT__unnamedblk1__DOT___GEN_33)
                                       ? ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                           ? (0xffffU 
                                              & ((IData)(1U) 
                                                 << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source)))
                                           : 0U) : 0U)) 
                                 | (0U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__a_set_wo_ready)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10543: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'A' and 'D' concurrent, despite minlatency > 0 (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10543, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10545: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10545, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (IData)(vlSelf->__PVT__inflight)) 
                                  | (0U == vlSelf->__PVT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->__PVT__watchdog 
                                    < vlSelf->__PVT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10551: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10551, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10553: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10553, "");
    }
    __PVT__unnamedblk1__DOT___GEN_39 = ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                         ? (0xffffU 
                                            & ((IData)(vlSelf->__PVT__inflight_1) 
                                               >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source)))
                                         : 0U);
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_36) 
                     & (~ (IData)(__PVT__unnamedblk1__DOT___GEN_39))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10558: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10558, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10560: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10560, "");
    }
    __PVT__unnamedblk1__DOT___c_size_lookup_T_1 = VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__inflight_sizes_1, __PVT__unnamedblk1__DOT___GEN_31);
    if (VL_UNLIKELY(((IData)(__PVT__unnamedblk1__DOT___GEN_36) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_size) 
                        != (7U & (IData)((__PVT__unnamedblk1__DOT___c_size_lookup_T_1 
                                          >> 1U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10565: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10565, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10567: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10567, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (IData)(vlSelf->__PVT__inflight_1)) 
                                  | (0U == vlSelf->__PVT__plusarg_reader_1__DOT__myplus)) 
                                 | (vlSelf->__PVT__watchdog_1 
                                    < vlSelf->__PVT__plusarg_reader_1__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10573: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/chiplink/ChipLink.scala:65:13)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10573, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:10575: Assertion failed in %NysyxSoCFull.fpga.chiplink.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 10575, "");
    }
    __PVT__unnamedblk2__DOT___d_first_T_2 = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_d_ready) 
                                             & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_valid));
    if (vlSymsp->TOP.reset) {
        __Vdly__d_first_counter = 0U;
        __Vdly__inflight = 0U;
        __Vdly__inflight_opcodes = 0ULL;
        __Vdly__inflight_sizes = 0ULL;
        __Vdly__d_first_counter_1 = 0U;
        __Vdly__watchdog = 0U;
        __Vdly__inflight_1 = 0U;
        __Vdly__inflight_sizes_1 = 0ULL;
        __Vdly__d_first_counter_2 = 0U;
        __Vdly__watchdog_1 = 0U;
        __Vdly__a_first_counter = 0U;
        __Vdly__a_first_counter_1 = 0U;
    } else {
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[0U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
               << 2U);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[1U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
               >> 0x1eU);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[2U] = 0U;
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[3U] = 0U;
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[4U] = 0U;
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source) 
               << 2U);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[1U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source) 
               >> 0x1eU);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[2U] = 0U;
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[3U] = 0U;
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[4U] = 0U;
        __Vtemp_h6f0d4cc8__0[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__0[1U] = 0U;
        __Vtemp_h6f0d4cc8__0[2U] = 0U;
        __Vtemp_h6f0d4cc8__0[3U] = 0U;
        __Vtemp_h6f0d4cc8__0[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_h3bb56701__0, __Vtemp_h6f0d4cc8__0, vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U] 
            = __Vtemp_h3bb56701__0[0U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U] 
            = __Vtemp_h3bb56701__0[1U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[2U] 
            = __Vtemp_h3bb56701__0[2U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[3U] 
            = __Vtemp_h3bb56701__0[3U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[4U] 
            = (0x7fffU & __Vtemp_h3bb56701__0[4U]);
        if (vlSelf->__PVT___GEN_1) {
            __Vtemp_h0552935f__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode) 
                                              << 1U));
            __Vtemp_hbf550051__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                                              << 1U));
        } else {
            __Vtemp_h0552935f__0[0U] = 0U;
            __Vtemp_hbf550051__0[0U] = 0U;
        }
        __Vtemp_h0552935f__0[1U] = 0U;
        __Vtemp_h0552935f__0[2U] = 0U;
        __Vtemp_h0552935f__0[3U] = 0U;
        __Vtemp_h0552935f__0[4U] = 0U;
        VL_SHIFTL_WWW(131,131,131, __Vtemp_h4b30de50__0, __Vtemp_h0552935f__0, vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U] 
            = __Vtemp_h4b30de50__0[0U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U] 
            = __Vtemp_h4b30de50__0[1U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[2U] 
            = __Vtemp_h4b30de50__0[2U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[3U] 
            = __Vtemp_h4b30de50__0[3U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[4U] 
            = (7U & __Vtemp_h4b30de50__0[4U]);
        __Vtemp_h6f0d4cc8__1[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__1[1U] = 0U;
        __Vtemp_h6f0d4cc8__1[2U] = 0U;
        __Vtemp_h6f0d4cc8__1[3U] = 0U;
        __Vtemp_h6f0d4cc8__1[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_h76cd2ac6__0, __Vtemp_h6f0d4cc8__1, vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U] 
            = __Vtemp_h76cd2ac6__0[0U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U] 
            = __Vtemp_h76cd2ac6__0[1U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[2U] 
            = __Vtemp_h76cd2ac6__0[2U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[3U] 
            = __Vtemp_h76cd2ac6__0[3U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[4U] 
            = (0x7fffU & __Vtemp_h76cd2ac6__0[4U]);
        __Vtemp_hbf550051__0[1U] = 0U;
        __Vtemp_hbf550051__0[2U] = 0U;
        __Vtemp_hbf550051__0[3U] = 0U;
        __Vtemp_hbf550051__0[4U] = 0U;
        VL_SHIFTL_WWW(131,131,131, __Vtemp_h09d64742__0, __Vtemp_hbf550051__0, vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U] 
            = __Vtemp_h09d64742__0[0U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U] 
            = __Vtemp_h09d64742__0[1U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[2U] 
            = __Vtemp_h09d64742__0[2U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[3U] 
            = __Vtemp_h09d64742__0[3U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[4U] 
            = (7U & __Vtemp_h09d64742__0[4U]);
        __Vtemp_h6f0d4cc8__2[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__2[1U] = 0U;
        __Vtemp_h6f0d4cc8__2[2U] = 0U;
        __Vtemp_h6f0d4cc8__2[3U] = 0U;
        __Vtemp_h6f0d4cc8__2[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_h4123b966__0, __Vtemp_h6f0d4cc8__2, vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[0U] 
            = __Vtemp_h4123b966__0[0U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[1U] 
            = __Vtemp_h4123b966__0[1U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[2U] 
            = __Vtemp_h4123b966__0[2U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[3U] 
            = __Vtemp_h4123b966__0[3U];
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[4U] 
            = (0x7fffU & __Vtemp_h4123b966__0[4U]);
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41 
            = (((IData)(__PVT__unnamedblk2__DOT___d_first_T_2) 
                & (IData)(vlSelf->__PVT__d_first_1)) 
               & (6U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode)));
        vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43 
            = (((IData)(__PVT__unnamedblk2__DOT___d_first_T_2) 
                & (IData)(vlSelf->__PVT__d_first_2)) 
               & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode)));
        if (__PVT__unnamedblk2__DOT___d_first_T_2) {
            vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                = (0xfffU & ((IData)(0x1fU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_size)));
            __Vdly__d_first_counter = (7U & ((0U != (IData)(vlSelf->__PVT__d_first_counter))
                                              ? ((IData)(vlSelf->__PVT__d_first_counter) 
                                                 - (IData)(1U))
                                              : ((1U 
                                                  & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode))
                                                  ? 
                                                 (~ 
                                                  ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                                   >> 2U))
                                                  : 0U)));
            __Vdly__d_first_counter_1 = (7U & ((IData)(vlSelf->__PVT__d_first_1)
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode))
                                                    ? 
                                                   (~ 
                                                    ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                                     >> 2U))
                                                    : 0U)
                                                : ((IData)(vlSelf->__PVT__d_first_counter_1) 
                                                   - (IData)(1U))));
            __Vdly__d_first_counter_2 = (7U & ((IData)(vlSelf->__PVT__d_first_2)
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode))
                                                    ? 
                                                   (~ 
                                                    ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                                     >> 2U))
                                                    : 0U)
                                                : ((IData)(vlSelf->__PVT__d_first_counter_2) 
                                                   - (IData)(1U))));
            __Vdly__watchdog_1 = 0U;
        } else {
            __Vdly__watchdog_1 = ((IData)(1U) + vlSelf->__PVT__watchdog_1);
        }
        __Vdly__inflight = (0xffffU & (((IData)(vlSelf->__PVT__inflight) 
                                        | ((IData)(vlSelf->__PVT___GEN_1)
                                            ? ((0xfU 
                                                >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source))
                                                ? ((IData)(1U) 
                                                   << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source))
                                                : 0U)
                                            : 0U)) 
                                       & (~ ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41)
                                              ? ((0xfU 
                                                  >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                                  ? 
                                                 ((IData)(1U) 
                                                  << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                                  : 0U)
                                              : 0U))));
        __Vdly__inflight_opcodes = ((vlSelf->__PVT__inflight_opcodes 
                                     | ((IData)(vlSelf->__PVT___GEN_1)
                                         ? (((QData)((IData)(
                                                             vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U])))
                                         : 0ULL)) & 
                                    (~ ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41)
                                         ? (((QData)((IData)(
                                                             vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U])))
                                         : 0ULL)));
        __Vdly__inflight_sizes = ((vlSelf->__PVT__inflight_sizes 
                                   | ((IData)(vlSelf->__PVT___GEN_1)
                                       ? (((QData)((IData)(
                                                           vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U])))
                                       : 0ULL)) & (~ 
                                                   ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U])))
                                                     : 0ULL)));
        __Vdly__watchdog = (((IData)(vlSelf->__PVT___a_first_T_1) 
                             | (IData)(__PVT__unnamedblk2__DOT___d_first_T_2))
                             ? 0U : ((IData)(1U) + vlSelf->__PVT__watchdog));
        __Vdly__inflight_1 = ((IData)(vlSelf->__PVT__inflight_1) 
                              & (~ ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                                     ? ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                         ? ((IData)(1U) 
                                            << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source))
                                         : 0U) : 0U)));
        __Vdly__inflight_sizes_1 = (vlSelf->__PVT__inflight_sizes_1 
                                    & (~ ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                                           ? (((QData)((IData)(
                                                               vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[1U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[0U])))
                                           : 0ULL)));
        if (vlSelf->__PVT___a_first_T_1) {
            vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 
                = ((0xbU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size))
                    ? (0xfffU & ((IData)(0x1fU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)))
                    : 0U);
            __Vdly__a_first_counter = (7U & ((0U != (IData)(vlSelf->__PVT__a_first_counter))
                                              ? ((IData)(vlSelf->__PVT__a_first_counter) 
                                                 - (IData)(1U))
                                              : ((4U 
                                                  & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))
                                                  ? 0U
                                                  : 
                                                 (~ 
                                                  ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3) 
                                                   >> 2U)))));
            __Vdly__a_first_counter_1 = (7U & ((IData)(vlSelf->__PVT__a_first_1)
                                                ? (
                                                   (4U 
                                                    & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))
                                                    ? 0U
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3) 
                                                     >> 2U)))
                                                : ((IData)(vlSelf->__PVT__a_first_counter_1) 
                                                   - (IData)(1U))));
        }
    }
    if (((IData)(__PVT__unnamedblk2__DOT___d_first_T_2) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__d_first_counter)))))) {
        vlSelf->__PVT__opcode_1 = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode;
        vlSelf->__PVT__param_1 = (3U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param));
        vlSelf->__PVT__size_1 = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_size;
        vlSelf->__PVT__source_1 = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source;
        vlSelf->__PVT__sink = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_sink;
        vlSelf->__PVT__denied = (1U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param) 
                                       >> 2U));
    }
    if (((IData)(vlSelf->__PVT___a_first_T_1) & (~ (IData)(
                                                           (0U 
                                                            != (IData)(vlSelf->__PVT__a_first_counter)))))) {
        vlSelf->__PVT__opcode = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode;
        vlSelf->__PVT__size = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size;
        vlSelf->__PVT__source = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source;
        vlSelf->__PVT__address = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address;
    }
    vlSelf->__PVT__d_first_counter = __Vdly__d_first_counter;
    vlSelf->__PVT__inflight = __Vdly__inflight;
    vlSelf->__PVT__inflight_opcodes = __Vdly__inflight_opcodes;
    vlSelf->__PVT__inflight_sizes = __Vdly__inflight_sizes;
    vlSelf->__PVT__watchdog = __Vdly__watchdog;
    vlSelf->__PVT__inflight_1 = __Vdly__inflight_1;
    vlSelf->__PVT__inflight_sizes_1 = __Vdly__inflight_sizes_1;
    vlSelf->__PVT__watchdog_1 = __Vdly__watchdog_1;
    vlSelf->__PVT__d_first_counter_1 = __Vdly__d_first_counter_1;
    vlSelf->__PVT__d_first_counter_2 = __Vdly__d_first_counter_2;
    vlSelf->__PVT__a_first_counter = __Vdly__a_first_counter;
    vlSelf->__PVT__a_first_counter_1 = __Vdly__a_first_counter_1;
    vlSelf->__PVT__d_first_1 = (0U == (IData)(vlSelf->__PVT__d_first_counter_1));
    vlSelf->__PVT__d_first_2 = (0U == (IData)(vlSelf->__PVT__d_first_counter_2));
    vlSelf->__PVT__a_first_1 = (0U == (IData)(vlSelf->__PVT__a_first_counter_1));
}

VL_INLINE_OPT void VysyxSoCFull_TLMonitor_7___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__monitor__0(VysyxSoCFull_TLMonitor_7* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLMonitor_7___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__monitor__0\n"); );
    // Body
    vlSelf->__PVT___a_first_T_1 = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sinkA__DOT__inject_io_i_q__DOT__full)) 
                                   & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass.auto_node_out_out_a_valid));
    vlSelf->__PVT___GEN_1 = ((IData)(vlSelf->__PVT___a_first_T_1) 
                             & (0U == (IData)(vlSelf->__PVT__a_first_counter_1)));
}
