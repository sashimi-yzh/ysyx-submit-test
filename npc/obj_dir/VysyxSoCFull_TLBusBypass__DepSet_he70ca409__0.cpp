// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLBusBypass.h"
#include "VysyxSoCFull__Syms.h"

VL_INLINE_OPT void VysyxSoCFull_TLBusBypass___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass__0(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass__0\n"); );
    // Body
    vlSelf->__PVT__error__DOT__da_bits_opcode = ((0x17U 
                                                  >= 
                                                  (0x1fU 
                                                   & ((IData)(3U) 
                                                      * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))))
                                                  ? 
                                                 (7U 
                                                  & (0x911240U 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(3U) 
                                                         * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode)))))
                                                  : 0U);
    vlSelf->__PVT__error__DOT__a_last_beats1 = ((4U 
                                                 & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))
                                                 ? 0U
                                                 : 
                                                (0x3ffU 
                                                 & (~ 
                                                    (0x1ffffffU 
                                                     & (((IData)(0xfffU) 
                                                         << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)) 
                                                        >> 2U)))));
    vlSelf->__PVT__error__DOT__r_beats1 = ((1U & (IData)(vlSelf->__PVT__error__DOT__da_bits_opcode))
                                            ? (0x3ffU 
                                               & (~ 
                                                  (0x1ffffffU 
                                                   & (((IData)(0xfffU) 
                                                       << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)) 
                                                      >> 2U))))
                                            : 0U);
    vlSelf->__PVT__error__DOT__a_last = ((1U == (IData)(vlSelf->__PVT__error__DOT__a_last_counter)) 
                                         | (0U == (IData)(vlSelf->__PVT__error__DOT__a_last_beats1)));
}

VL_INLINE_OPT void VysyxSoCFull_TLBusBypass___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass__1(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass__1\n"); );
    // Init
    CData/*0:0*/ bar__DOT____VdfgTmp_h84f1d1ee__0;
    bar__DOT____VdfgTmp_h84f1d1ee__0 = 0;
    // Body
    bar__DOT____VdfgTmp_h84f1d1ee__0 = ((~ (IData)(vlSelf->__PVT__bar__DOT__stall)) 
                                        & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid));
    vlSelf->auto_node_out_out_a_valid = ((~ (IData)(vlSelf->__PVT__bar__DOT__bypass)) 
                                         & (IData)(bar__DOT____VdfgTmp_h84f1d1ee__0));
    vlSelf->__PVT___bar_auto_out_0_a_valid = ((IData)(bar__DOT____VdfgTmp_h84f1d1ee__0) 
                                              & (IData)(vlSelf->__PVT__bar__DOT__bypass));
    vlSelf->__PVT__error__DOT__winner_1 = ((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
                                           & ((IData)(vlSelf->__PVT__error__DOT__a_last) 
                                              & (IData)(vlSelf->__PVT__error__DOT__idle)));
    vlSelf->__PVT__error__DOT__muxState_1 = ((0U == (IData)(vlSelf->__PVT__error__DOT__beatsLeft))
                                              ? (IData)(vlSelf->__PVT__error__DOT__winner_1)
                                              : (IData)(vlSelf->__PVT__error__DOT__state_1));
    vlSelf->__PVT__error__DOT__nodeIn_d_valid = ((IData)(vlSelf->error__DOT____VdfgTmp_hc0029b36__0) 
                                                 & (IData)(vlSelf->__PVT__error__DOT__winner_1));
    if (vlSelf->__PVT__error__DOT__muxState_1) {
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19 
            = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size;
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16 
            = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source;
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24 
            = vlSelf->__PVT__error__DOT__da_bits_opcode;
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3 
            = (1U & (IData)(vlSelf->__PVT__error__DOT__da_bits_opcode));
    } else {
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19 = 0U;
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16 = 0U;
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24 = 0U;
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3 = 0U;
    }
    if (vlSelf->__PVT__bar__DOT__bypass) {
        if (vlSelf->__PVT__error__DOT__muxState_1) {
            vlSelf->auto_node_in_in_d_bits_denied = 1U;
            vlSelf->auto_node_in_in_d_bits_size = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size;
        } else {
            vlSelf->auto_node_in_in_d_bits_denied = 0U;
            vlSelf->auto_node_in_in_d_bits_size = 0U;
        }
        vlSelf->auto_node_in_in_d_valid = vlSelf->__PVT__error__DOT__nodeIn_d_valid;
        vlSelf->auto_node_in_in_d_bits_corrupt = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3;
        vlSelf->auto_node_in_in_d_bits_source = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16;
        vlSelf->auto_node_in_in_d_bits_opcode = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24;
    } else {
        vlSelf->auto_node_in_in_d_bits_denied = (1U 
                                                 & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param) 
                                                    >> 2U));
        vlSelf->auto_node_in_in_d_bits_size = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_size;
        vlSelf->auto_node_in_in_d_valid = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_valid;
        vlSelf->auto_node_in_in_d_bits_corrupt = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_corrupt;
        vlSelf->auto_node_in_in_d_bits_source = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_source;
        vlSelf->auto_node_in_in_d_bits_opcode = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_opcode;
    }
}

VL_INLINE_OPT void VysyxSoCFull_TLBusBypass___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass__2(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass__2\n"); );
    // Body
    vlSelf->auto_node_out_out_d_ready = ((~ (IData)(vlSelf->__PVT__bar__DOT__bypass)) 
                                         & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_d_ready));
    vlSelf->__PVT___bar_auto_out_0_d_ready = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_d_ready) 
                                              & (IData)(vlSelf->__PVT__bar__DOT__bypass));
    vlSelf->__PVT__error__DOT__da_ready = ((IData)(vlSelf->__PVT___bar_auto_out_0_d_ready) 
                                           & (IData)(vlSelf->error__DOT____VdfgTmp_hc0029b36__0));
    vlSelf->__PVT__error__DOT__nodeIn_a_ready = (1U 
                                                 & ((~ (IData)(vlSelf->__PVT__error__DOT__a_last)) 
                                                    | ((IData)(vlSelf->__PVT__error__DOT__da_ready) 
                                                       & (((1U 
                                                            == (IData)(vlSelf->__PVT__error__DOT__r_counter)) 
                                                           | (0U 
                                                              == (IData)(vlSelf->__PVT__error__DOT__r_beats1))) 
                                                          & (IData)(vlSelf->__PVT__error__DOT__idle)))));
    vlSelf->__PVT__error__DOT__monitor__DOT___a_first_T_1 
        = ((IData)(vlSelf->__PVT__error__DOT__nodeIn_a_ready) 
           & (IData)(vlSelf->__PVT___bar_auto_out_0_a_valid));
    vlSelf->auto_node_in_in_a_ready = (1U & ((~ (IData)(vlSelf->__PVT__bar__DOT__stall)) 
                                             & ((IData)(vlSelf->__PVT__bar__DOT__bypass)
                                                 ? (IData)(vlSelf->__PVT__error__DOT__nodeIn_a_ready)
                                                 : 
                                                (~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sinkA__DOT__inject_io_i_q__DOT__full)))));
    vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0 
        = ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___a_first_T_1) 
           & (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1)));
    vlSelf->__PVT__bar__DOT__monitor__DOT___a_first_T_1 
        = ((IData)(vlSelf->auto_node_in_in_a_ready) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid));
    vlSelf->__PVT__bar__DOT__monitor__DOT___GEN_0 = 
        ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___a_first_T_1) 
         & (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1)));
}

VL_INLINE_OPT void VysyxSoCFull_TLBusBypass___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass__0(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass__0\n"); );
    // Init
    CData/*0:0*/ __PVT__bar__DOT__unnamedblk1__DOT___stall_T_1;
    __PVT__bar__DOT__unnamedblk1__DOT___stall_T_1 = 0;
    CData/*0:0*/ __PVT__bar__DOT__unnamedblk1__DOT___d_dec_T;
    __PVT__bar__DOT__unnamedblk1__DOT___d_dec_T = 0;
    SData/*11:0*/ __PVT__bar__DOT__unnamedblk1__DOT___rbeats1_decode_T_9;
    __PVT__bar__DOT__unnamedblk1__DOT___rbeats1_decode_T_9 = 0;
    CData/*5:0*/ __PVT__bar__DOT__unnamedblk1__DOT___next_flight_T_10;
    __PVT__bar__DOT__unnamedblk1__DOT___next_flight_T_10 = 0;
    SData/*11:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T = 0;
    CData/*4:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_7;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_7 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30 = 0;
    QData/*63:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31 = 0;
    QData/*63:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_36;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_36 = 0;
    SData/*15:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_37;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_37 = 0;
    SData/*15:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_38;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_38 = 0;
    QData/*63:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1 = 0;
    SData/*15:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_39;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_39 = 0;
    QData/*63:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2;
    __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2 = 0;
    IData/*26:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T = 0;
    SData/*11:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25 = 0;
    QData/*63:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 = 0;
    VlWide<4>/*127:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26;
    VL_ZERO_W(128, __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26);
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30 = 0;
    CData/*7:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32 = 0;
    SData/*15:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33 = 0;
    SData/*15:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34 = 0;
    VlWide<4>/*127:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1;
    VL_ZERO_W(128, __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1);
    SData/*15:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35 = 0;
    VlWide<4>/*127:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1;
    VL_ZERO_W(128, __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1);
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2;
    __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2 = 0;
    CData/*2:0*/ __Vdly__bar__DOT__r_counter;
    __Vdly__bar__DOT__r_counter = 0;
    CData/*2:0*/ __Vdly__bar__DOT__r_counter_3;
    __Vdly__bar__DOT__r_counter_3 = 0;
    CData/*2:0*/ __Vdly__bar__DOT__stall_counter;
    __Vdly__bar__DOT__stall_counter = 0;
    CData/*2:0*/ __Vdly__bar__DOT__monitor__DOT__d_first_counter;
    __Vdly__bar__DOT__monitor__DOT__d_first_counter = 0;
    SData/*15:0*/ __Vdly__bar__DOT__monitor__DOT__inflight;
    __Vdly__bar__DOT__monitor__DOT__inflight = 0;
    QData/*63:0*/ __Vdly__bar__DOT__monitor__DOT__inflight_opcodes;
    __Vdly__bar__DOT__monitor__DOT__inflight_opcodes = 0;
    QData/*63:0*/ __Vdly__bar__DOT__monitor__DOT__inflight_sizes;
    __Vdly__bar__DOT__monitor__DOT__inflight_sizes = 0;
    CData/*2:0*/ __Vdly__bar__DOT__monitor__DOT__d_first_counter_1;
    __Vdly__bar__DOT__monitor__DOT__d_first_counter_1 = 0;
    IData/*31:0*/ __Vdly__bar__DOT__monitor__DOT__watchdog;
    __Vdly__bar__DOT__monitor__DOT__watchdog = 0;
    SData/*15:0*/ __Vdly__bar__DOT__monitor__DOT__inflight_1;
    __Vdly__bar__DOT__monitor__DOT__inflight_1 = 0;
    QData/*63:0*/ __Vdly__bar__DOT__monitor__DOT__inflight_sizes_1;
    __Vdly__bar__DOT__monitor__DOT__inflight_sizes_1 = 0;
    CData/*2:0*/ __Vdly__bar__DOT__monitor__DOT__d_first_counter_2;
    __Vdly__bar__DOT__monitor__DOT__d_first_counter_2 = 0;
    IData/*31:0*/ __Vdly__bar__DOT__monitor__DOT__watchdog_1;
    __Vdly__bar__DOT__monitor__DOT__watchdog_1 = 0;
    CData/*2:0*/ __Vdly__bar__DOT__monitor__DOT__a_first_counter;
    __Vdly__bar__DOT__monitor__DOT__a_first_counter = 0;
    CData/*2:0*/ __Vdly__bar__DOT__monitor__DOT__a_first_counter_1;
    __Vdly__bar__DOT__monitor__DOT__a_first_counter_1 = 0;
    CData/*0:0*/ __Vdly__error__DOT__idle;
    __Vdly__error__DOT__idle = 0;
    SData/*9:0*/ __Vdly__error__DOT__r_counter;
    __Vdly__error__DOT__r_counter = 0;
    SData/*9:0*/ __Vdly__error__DOT__a_last_counter;
    __Vdly__error__DOT__a_last_counter = 0;
    SData/*9:0*/ __Vdly__error__DOT__beatsLeft;
    __Vdly__error__DOT__beatsLeft = 0;
    SData/*9:0*/ __Vdly__error__DOT__monitor__DOT__d_first_counter;
    __Vdly__error__DOT__monitor__DOT__d_first_counter = 0;
    SData/*15:0*/ __Vdly__error__DOT__monitor__DOT__inflight;
    __Vdly__error__DOT__monitor__DOT__inflight = 0;
    QData/*63:0*/ __Vdly__error__DOT__monitor__DOT__inflight_opcodes;
    __Vdly__error__DOT__monitor__DOT__inflight_opcodes = 0;
    VlWide<4>/*127:0*/ __Vdly__error__DOT__monitor__DOT__inflight_sizes;
    VL_ZERO_W(128, __Vdly__error__DOT__monitor__DOT__inflight_sizes);
    SData/*9:0*/ __Vdly__error__DOT__monitor__DOT__d_first_counter_1;
    __Vdly__error__DOT__monitor__DOT__d_first_counter_1 = 0;
    IData/*31:0*/ __Vdly__error__DOT__monitor__DOT__watchdog;
    __Vdly__error__DOT__monitor__DOT__watchdog = 0;
    SData/*15:0*/ __Vdly__error__DOT__monitor__DOT__inflight_1;
    __Vdly__error__DOT__monitor__DOT__inflight_1 = 0;
    VlWide<4>/*127:0*/ __Vdly__error__DOT__monitor__DOT__inflight_sizes_1;
    VL_ZERO_W(128, __Vdly__error__DOT__monitor__DOT__inflight_sizes_1);
    SData/*9:0*/ __Vdly__error__DOT__monitor__DOT__d_first_counter_2;
    __Vdly__error__DOT__monitor__DOT__d_first_counter_2 = 0;
    IData/*31:0*/ __Vdly__error__DOT__monitor__DOT__watchdog_1;
    __Vdly__error__DOT__monitor__DOT__watchdog_1 = 0;
    SData/*9:0*/ __Vdly__error__DOT__monitor__DOT__a_first_counter;
    __Vdly__error__DOT__monitor__DOT__a_first_counter = 0;
    SData/*9:0*/ __Vdly__error__DOT__monitor__DOT__a_first_counter_1;
    __Vdly__error__DOT__monitor__DOT__a_first_counter_1 = 0;
    VlWide<4>/*127:0*/ __Vtemp_hf303a3ad__0;
    VlWide<4>/*127:0*/ __Vtemp_h70724169__0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__0;
    VlWide<5>/*159:0*/ __Vtemp_h814bf4f2__0;
    VlWide<5>/*159:0*/ __Vtemp_h1ec71af6__0;
    VlWide<5>/*159:0*/ __Vtemp_h402f1848__0;
    VlWide<5>/*159:0*/ __Vtemp_h9ecf9258__0;
    VlWide<5>/*159:0*/ __Vtemp_h0fe840ea__0;
    VlWide<5>/*159:0*/ __Vtemp_hab69a0d4__0;
    VlWide<5>/*159:0*/ __Vtemp_hedb9a1f6__0;
    VlWide<5>/*159:0*/ __Vtemp_h8e9d450e__0;
    VlWide<5>/*159:0*/ __Vtemp_h1aa7efb5__0;
    VlWide<5>/*159:0*/ __Vtemp_h4911bd3b__0;
    VlWide<5>/*159:0*/ __Vtemp_hab69a0d4__1;
    VlWide<5>/*159:0*/ __Vtemp_h131918fc__0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__1;
    VlWide<5>/*159:0*/ __Vtemp_hee7b10c9__0;
    VlWide<5>/*159:0*/ __Vtemp_hd1f2b9ce__0;
    VlWide<5>/*159:0*/ __Vtemp_hff857c10__0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__2;
    VlWide<5>/*159:0*/ __Vtemp_hcb4b53f9__0;
    VlWide<5>/*159:0*/ __Vtemp_hf2fbc16c__0;
    VlWide<5>/*159:0*/ __Vtemp_h4c24cd42__0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__3;
    VlWide<5>/*159:0*/ __Vtemp_h5911eb2f__0;
    // Body
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((IData)(vlSelf->__PVT__error__DOT__idle) 
                                 | (0U == (IData)(vlSelf->__PVT__error__DOT__r_counter)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7821: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error: Assertion failed at Error.scala:34\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7821, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7823: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7823, "");
    }
    __Vdly__error__DOT__r_counter = vlSelf->__PVT__error__DOT__r_counter;
    __Vdly__error__DOT__idle = vlSelf->__PVT__error__DOT__idle;
    __Vdly__bar__DOT__monitor__DOT__watchdog_1 = vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog_1;
    __Vdly__bar__DOT__monitor__DOT__inflight_sizes_1 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes_1;
    __Vdly__bar__DOT__monitor__DOT__inflight_1 = vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_1;
    __Vdly__bar__DOT__monitor__DOT__watchdog = vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog;
    __Vdly__bar__DOT__monitor__DOT__inflight_sizes 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes;
    __Vdly__bar__DOT__monitor__DOT__inflight_opcodes 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_opcodes;
    __Vdly__bar__DOT__monitor__DOT__inflight = vlSelf->__PVT__bar__DOT__monitor__DOT__inflight;
    __Vdly__bar__DOT__monitor__DOT__d_first_counter 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter;
    __Vdly__bar__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_2;
    __Vdly__bar__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_1;
    __Vdly__error__DOT__monitor__DOT__watchdog_1 = vlSelf->__PVT__error__DOT__monitor__DOT__watchdog_1;
    __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[0U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[0U];
    __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[1U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[1U];
    __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[2U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[2U];
    __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[3U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[3U];
    __Vdly__error__DOT__monitor__DOT__inflight_1 = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_1;
    __Vdly__error__DOT__monitor__DOT__watchdog = vlSelf->__PVT__error__DOT__monitor__DOT__watchdog;
    __Vdly__error__DOT__monitor__DOT__inflight_sizes[0U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[0U];
    __Vdly__error__DOT__monitor__DOT__inflight_sizes[1U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[1U];
    __Vdly__error__DOT__monitor__DOT__inflight_sizes[2U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[2U];
    __Vdly__error__DOT__monitor__DOT__inflight_sizes[3U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[3U];
    __Vdly__error__DOT__monitor__DOT__inflight_opcodes 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_opcodes;
    __Vdly__error__DOT__monitor__DOT__inflight = vlSelf->__PVT__error__DOT__monitor__DOT__inflight;
    __Vdly__error__DOT__monitor__DOT__d_first_counter 
        = vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter;
    __Vdly__error__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_2;
    __Vdly__error__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_1;
    __Vdly__error__DOT__a_last_counter = vlSelf->__PVT__error__DOT__a_last_counter;
    __Vdly__error__DOT__monitor__DOT__a_first_counter 
        = vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter;
    __Vdly__bar__DOT__monitor__DOT__a_first_counter 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter;
    __Vdly__error__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1;
    __Vdly__bar__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1;
    __Vdly__error__DOT__beatsLeft = vlSelf->__PVT__error__DOT__beatsLeft;
    __Vdly__bar__DOT__r_counter_3 = vlSelf->__PVT__bar__DOT__r_counter_3;
    __Vdly__bar__DOT__r_counter = vlSelf->__PVT__bar__DOT__r_counter;
    __Vdly__bar__DOT__stall_counter = vlSelf->__PVT__bar__DOT__stall_counter;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T 
        = ((0x1aU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size))
            ? (0x7ffffffU & ((IData)(0xfffU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)))
            : 0U);
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6 
        = (0xfffU & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                     & (~ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T)));
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1 
        = (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size))) 
                 | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                    & (~ (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                          >> 1U)))));
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1 
        = (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size))) 
                 | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                    & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                       >> 1U))));
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask 
        = ((8U & (((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1) 
                   << 3U) | (0xfffffff8U & ((vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                             << 2U) 
                                            & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                               << 3U))))) 
           | ((4U & (((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1) 
                      << 2U) | (0xfffffffcU & ((vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                                << 1U) 
                                               & ((~ vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address) 
                                                  << 2U))))) 
              | ((2U & (((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1) 
                         | (IData)((1U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address)))) 
                        << 1U)) | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1) 
                                   | (0U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address))))));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9 
        = (0xfU != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_mask));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (7U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (4U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12 
        = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_mask) 
           != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (0U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (1U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15 
        = (5U > (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (2U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (3U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19 
        = (((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
            & (6U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20 
        = (0U == (7U & ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19) 
                        >> 1U)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21 
        = (((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
            & (4U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22 
        = (((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
            & (5U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23 
        = (1U & ((~ (IData)(vlSelf->__PVT__error__DOT__muxState_1)) 
                 | (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26[0U] 
        = ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
           << 3U);
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26[1U] 
        = ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
           >> 0x1dU);
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26[2U] = 0U;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26[3U] = 0U;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27 
        = ((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
           & (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_1)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28 
        = ((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27) 
           & (6U != (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24)));
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1))) 
           & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
              == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29 
        = (((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
            & (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp)) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30 
        = (((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
            & (~ (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31 
        = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32 
        = ((((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
             & (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_2))) 
            & (6U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (0U != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25 
        = (((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
            & (0U != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
        = VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__error__DOT__monitor__DOT__inflight_opcodes, 
                        ((QData)((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16)) 
                         << 2U));
    if (VL_UNLIKELY(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7253: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7253, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7255: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7255, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (~ (IData)((0U != (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7259: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7259, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7261: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7261, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7265: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7265, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7267: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7267, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7271: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7271, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7273: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7273, "");
    }
    if (VL_UNLIKELY(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7283: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7283, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7285: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7285, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (~ (IData)((0U != (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7289: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7289, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7291: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7291, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7295: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7295, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7297: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7297, "");
    }
    if (VL_UNLIKELY(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7301: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7301, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7303: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7303, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7307: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7307, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7309: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7309, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7323: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Get address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7323, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7325: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7325, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7329: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Get contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7329, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7331: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7331, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7341: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7341, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7343: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7343, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7347: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7347, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7349: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7349, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7359: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7359, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7361: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7361, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (0U != ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_mask) 
                               & (~ (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7365: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7365, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7367: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7367, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16) 
                     & (~ (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7371: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7371, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7373: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7373, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7377: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7377, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7379: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7379, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7383: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7383, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7385: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7385, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17) 
                     & (~ (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7389: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7389, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7391: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7391, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7395: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Logical address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7395, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7397: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7397, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7401: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Logical contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7401, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7403: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7403, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7413: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Hint address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7413, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7415: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7415, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7419: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Hint contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7419, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7421: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7421, "");
    }
    if (VL_UNLIKELY((((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (7U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7425: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel has invalid opcode (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7425, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7427: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7427, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7431: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7431, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7433: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7433, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7437: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7437, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7439: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7439, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (IData)(vlSelf->__PVT__error__DOT__muxState_1)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7443: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck is denied (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7443, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7445: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7445, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7449: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel Grant smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7449, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7451: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7451, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21) 
                     & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7455: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel Grant is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7455, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7457: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7457, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7461: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7461, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7463: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7463, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (~ (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7467: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7467, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7469: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7469, "");
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
                       & (0U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7474: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7474, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7476: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7476, "");
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
                       & (1U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7480: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7480, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7482: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7482, "");
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
                       & (2U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7487: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel HintAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7487, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7489: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7489, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7493: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7493, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7495: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7495, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7499: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7499, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7501: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7501, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__source))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7505: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7505, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7507: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7507, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & (0U != ((((vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                  ^ vlSelf->__PVT__error__DOT__monitor__DOT__address[0U]) 
                                 | vlSelf->__PVT__error__DOT__monitor__DOT__address[1U]) 
                                | vlSelf->__PVT__error__DOT__monitor__DOT__address[2U]) 
                               | vlSelf->__PVT__error__DOT__monitor__DOT__address[3U]))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7511: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel address changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7511, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7513: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7513, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25) 
                     & ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7517: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7517, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7519: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7519, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25) 
                     & ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7523: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7523, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7525: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7525, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25) 
                     & ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7529: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7529, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7531: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7531, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25) 
                     & ((IData)(vlSelf->__PVT__error__DOT__muxState_1) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__denied))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7535: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel denied changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7535, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7537: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7537, "");
    }
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33 
        = ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source))
            ? (0xffffU & ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight) 
                          >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source)))
            : 0U);
    if (VL_UNLIKELY((((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7542: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel re-used a source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7542, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7544: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7544, "");
    }
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34 
        = ((0xfU >= (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))
            ? (0xffffU & ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight) 
                          >> (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16)))
            : 0U);
    if (VL_UNLIKELY((((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34) 
                           | (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7549: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7549, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7551: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7551, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & (~ (((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode)))))
                                 : 0U)) | ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24) 
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
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7557: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7557, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7559: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7559, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                        != (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7563: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7563, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7565: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7565, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & (~ (((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                             >> 1U))))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (IData)(
                                                            (__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                             >> 1U)))))))
                                 : 0U)) | ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (IData)(
                                                               (__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                                >> 1U))))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (IData)(
                                                                     (__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                                      >> 1U)))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7571: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7571, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7573: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7573, "");
    }
    VL_SHIFTR_WWW(128,128,128, __Vtemp_hf303a3ad__0, vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes, __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26);
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0U] 
        = __Vtemp_hf303a3ad__0[0U];
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[1U] 
        = __Vtemp_hf303a3ad__0[1U];
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[2U] 
        = __Vtemp_hf303a3ad__0[2U];
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[3U] 
        = __Vtemp_hf303a3ad__0[3U];
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                        != (0x7fU & (__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0U] 
                                     >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7578: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7578, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7580: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7580, "");
    }
    if (VL_UNLIKELY((((((((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27) 
                          & (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1))) 
                         & (IData)(vlSelf->__PVT___bar_auto_out_0_a_valid)) 
                        & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
                           == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))) 
                       & (6U != (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((~ (IData)(vlSelf->__PVT___bar_auto_out_0_d_ready)) 
                           | (IData)(vlSelf->__PVT__error__DOT__nodeIn_a_ready)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7585: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: ready check\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7585, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7587: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7587, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight)) 
                                  | (0U == vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->__PVT__error__DOT__monitor__DOT__watchdog 
                                    < vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7593: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7593, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7595: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7595, "");
    }
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35 
        = ((0xfU >= (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))
            ? (0xffffU & ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight_1) 
                          >> (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16)))
            : 0U);
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                     & (~ (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7600: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7600, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7602: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7602, "");
    }
    VL_SHIFTR_WWW(128,128,128, __Vtemp_h70724169__0, vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1, __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26);
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1[0U] 
        = __Vtemp_h70724169__0[0U];
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1[1U] 
        = __Vtemp_h70724169__0[1U];
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1[2U] 
        = __Vtemp_h70724169__0[2U];
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1[3U] 
        = __Vtemp_h70724169__0[3U];
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                     & ((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                        != (0x7fU & (__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1[0U] 
                                     >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7607: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7607, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7609: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7609, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight_1)) 
                                  | (0U == vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus)) 
                                 | (vlSelf->__PVT__error__DOT__monitor__DOT__watchdog_1 
                                    < vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7615: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7615, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7617: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7617, "");
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T 
        = ((0xbU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size))
            ? (0xfffU & ((IData)(0x1fU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)))
            : 0U);
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6 
        = (0x1fU & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                    & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T))));
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1 
        = (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size))) 
                 | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                    & (~ (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                          >> 1U)))));
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1 
        = (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size))) 
                 | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                    & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                       >> 1U))));
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask 
        = ((8U & (((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1) 
                   << 3U) | (0xfffffff8U & ((vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                             << 2U) 
                                            & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                               << 3U))))) 
           | ((((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1) 
                | (2U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address))) 
               << 2U) | ((((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1) 
                           | (1U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address))) 
                          << 1U) | ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1) 
                                    | (0U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address))))));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_7 
        = ((5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)) 
           & (3U == (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                     >> 0x1eU)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9 
        = (0xfU != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_mask));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (7U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11 
        = ((3U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                         >> 1U))) & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                     >> 0x1eU));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (4U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13 
        = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_mask) 
           != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (0U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (1U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16 
        = ((3U > (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)) 
           & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
              >> 0x1eU));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (2U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (3U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (6U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21 
        = (0U == (3U & ((IData)(vlSelf->auto_node_in_in_d_bits_size) 
                        >> 1U)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (4U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23 
        = (2U == (IData)(vlSelf->auto_node_in_in_d_bits_param));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (5U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25 
        = (1U & ((~ (IData)(vlSelf->auto_node_in_in_d_bits_denied)) 
                 | (IData)(vlSelf->auto_node_in_in_d_bits_corrupt)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (0U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (1U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (2U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31 
        = ((QData)((IData)(vlSelf->auto_node_in_in_d_bits_source)) 
           << 2U);
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32 
        = ((IData)(vlSelf->auto_node_in_in_d_valid) 
           & (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_1)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33 
        = ((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
           & (6U != (IData)(vlSelf->auto_node_in_in_d_bits_opcode)));
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1))) 
           & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
              == (IData)(vlSelf->auto_node_in_in_d_bits_source)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34 
        = (((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33) 
            & (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp)) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35 
        = (((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33) 
            & (~ (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_36 
        = ((((IData)(vlSelf->auto_node_in_in_d_valid) 
             & (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_2))) 
            & (6U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (0U != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (0U != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
        = VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_opcodes, __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31);
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_7))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6361: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6361, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6363: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6363, "");
    }
    if (VL_UNLIKELY(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6367: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6367, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6369: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6369, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (~ (IData)((0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6373: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6373, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6375: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6375, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6379: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6379, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6381: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6381, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6385: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6385, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6387: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6387, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_7))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6391: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6391, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6393: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6393, "");
    }
    if (VL_UNLIKELY(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6397: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6397, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6399: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6399, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (~ (IData)((0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6403: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6403, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6405: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6405, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6409: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6409, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6411: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6411, "");
    }
    if (VL_UNLIKELY(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6415: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6415, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6417: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6417, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6421: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6421, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6423: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6423, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6427: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries Get type which slave claims it can't support (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6427, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6429: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6429, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6433: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Get address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6433, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6435: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6435, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6439: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Get contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6439, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6441: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6441, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6445: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries PutFull type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6445, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6447: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6447, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6451: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6451, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6453: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6453, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6457: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6457, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6459: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6459, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6463: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries PutPartial type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6463, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6465: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6465, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6469: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6469, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6471: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6471, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15) 
                     & (0U != ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_mask) 
                               & (~ (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6475: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6475, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6477: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6477, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6481: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6481, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6483: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6483, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6487: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6487, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6489: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6489, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6493: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6493, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6495: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6495, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6499: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6499, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6501: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6501, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6505: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Logical address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6505, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6507: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6507, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6511: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Logical contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6511, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6513: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6513, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6517: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries Hint type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6517, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6519: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6519, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6523: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Hint address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6523, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6525: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6525, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6529: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Hint contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6529, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6531: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6531, "");
    }
    if (VL_UNLIKELY((((IData)(vlSelf->auto_node_in_in_d_valid) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (7U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6535: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel has invalid opcode (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6535, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6537: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6537, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6541: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6541, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6543: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6543, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (0U != (IData)(vlSelf->auto_node_in_in_d_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6547: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseeAck carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6547, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6549: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6549, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (IData)(vlSelf->auto_node_in_in_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6553: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6553, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6555: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6555, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (IData)(vlSelf->auto_node_in_in_d_bits_denied)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6559: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck is denied (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6559, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6561: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6561, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6565: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel Grant smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6565, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6567: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6567, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (3U == (IData)(vlSelf->auto_node_in_in_d_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6571: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel Grant carries invalid cap param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6571, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6573: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6573, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6577: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel Grant carries toN param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6577, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6579: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6579, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(vlSelf->auto_node_in_in_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6583: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel Grant is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6583, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6585: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6585, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6589: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6589, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6591: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6591, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & (3U == (IData)(vlSelf->auto_node_in_in_d_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6595: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData carries invalid cap param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6595, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6597: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6597, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6601: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData carries toN param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6601, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6603: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6603, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6607: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6607, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6609: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6609, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26) 
                     & (0U != (IData)(vlSelf->auto_node_in_in_d_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6613: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6613, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6615: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6615, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26) 
                     & (IData)(vlSelf->auto_node_in_in_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6619: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6619, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6621: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6621, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27) 
                     & (0U != (IData)(vlSelf->auto_node_in_in_d_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6625: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6625, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6627: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6627, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6631: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6631, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6633: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6633, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
                     & (0U != (IData)(vlSelf->auto_node_in_in_d_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6637: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel HintAck carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6637, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6639: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6639, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
                     & (IData)(vlSelf->auto_node_in_in_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6643: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel HintAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6643, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6645: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6645, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6649: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6649, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6651: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6651, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6655: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6655, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6657: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6657, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__source))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6661: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6661, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6663: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6663, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                        != vlSelf->__PVT__bar__DOT__monitor__DOT__address)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6667: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel address changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6667, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6669: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6669, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6673: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6673, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6675: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6675, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_param) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__param_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6679: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel param changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6679, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6681: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6681, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_size) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6685: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6685, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6687: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6687, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_source) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6691: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6691, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6693: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6693, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_sink) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__sink))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6697: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel sink changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6697, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6699: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6699, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_denied) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__denied))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6703: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel denied changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6703, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6705: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6705, "");
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_37 
        = ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source))
            ? (0xffffU & ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight) 
                          >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source)))
            : 0U);
    if (VL_UNLIKELY((((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___GEN_0) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_37)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6710: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel re-used a source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6710, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6712: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6712, "");
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_38 
        = ((0xfU >= (IData)(vlSelf->auto_node_in_in_d_bits_source))
            ? (0xffffU & ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight) 
                          >> (IData)(vlSelf->auto_node_in_in_d_bits_source)))
            : 0U);
    if (VL_UNLIKELY((((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_38) 
                           | (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6717: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6717, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6719: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6719, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34) 
                     & (~ (((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode)))))
                                 : 0U)) | ((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
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
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6725: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6725, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6727: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6727, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                        != (IData)(vlSelf->auto_node_in_in_d_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6731: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6731, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6733: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6733, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35) 
                     & (~ (((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                             >> 1U))))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (IData)(
                                                            (__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                             >> 1U)))))))
                                 : 0U)) | ((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (IData)(
                                                               (__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                                >> 1U))))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (IData)(
                                                                     (__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                                      >> 1U)))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6739: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6739, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6741: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6741, "");
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1 
        = VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes, __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31);
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_size) 
                        != (7U & (IData)((__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1 
                                          >> 1U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6746: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6746, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6748: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6748, "");
    }
    if (VL_UNLIKELY((((((((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                          & (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1))) 
                         & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid)) 
                        & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
                           == (IData)(vlSelf->auto_node_in_in_d_bits_source))) 
                       & (6U != (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_d_ready)) 
                           | (IData)(vlSelf->auto_node_in_in_a_ready)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6753: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: ready check\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6753, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6755: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6755, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight)) 
                                  | (0U == vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog 
                                    < vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6761: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6761, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6763: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6763, "");
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_39 
        = ((0xfU >= (IData)(vlSelf->auto_node_in_in_d_bits_source))
            ? (0xffffU & ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_1) 
                          >> (IData)(vlSelf->auto_node_in_in_d_bits_source)))
            : 0U);
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_36) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_39))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6768: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6768, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6770: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6770, "");
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1 
        = VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes_1, __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31);
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_36) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_size) 
                        != (7U & (IData)((__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1 
                                          >> 1U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6775: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6775, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6777: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6777, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_1)) 
                                  | (0U == vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus)) 
                                 | (vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog_1 
                                    < vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6783: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6783, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6785: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6785, "");
    }
    __PVT__bar__DOT__unnamedblk1__DOT___rbeats1_decode_T_9 
        = (0xfffU & ((IData)(0x1fU) << (IData)(vlSelf->auto_node_in_in_d_bits_size)));
    __PVT__bar__DOT__unnamedblk1__DOT___stall_T_1 = 
        ((IData)(vlSelf->auto_node_in_in_a_ready) & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_a_valid));
    vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__a_first 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__r_counter));
    __PVT__bar__DOT__unnamedblk1__DOT___d_dec_T = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_d_ready) 
                                                   & (IData)(vlSelf->auto_node_in_in_d_valid));
    vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__r_beats1_3 
        = ((1U & (IData)(vlSelf->auto_node_in_in_d_bits_opcode))
            ? (7U & (~ ((IData)(__PVT__bar__DOT__unnamedblk1__DOT___rbeats1_decode_T_9) 
                        >> 2U))) : 0U);
    vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__d_first 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__r_counter_3));
    __PVT__bar__DOT__unnamedblk1__DOT___next_flight_T_10 
        = (0x3fU & (((IData)(vlSelf->__PVT__bar__DOT__flight) 
                     + (3U & (((((IData)(__PVT__bar__DOT__unnamedblk1__DOT___d_dec_T) 
                                 & (IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__d_first)) 
                                & ((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
                                   >> 2U)) & (~ ((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
                                                 >> 1U))) 
                              + ((IData)(__PVT__bar__DOT__unnamedblk1__DOT___stall_T_1) 
                                 & (IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__a_first))))) 
                    - ((IData)(__PVT__bar__DOT__unnamedblk1__DOT___d_dec_T) 
                       & ((1U == (IData)(vlSelf->__PVT__bar__DOT__r_counter_3)) 
                          | (0U == (IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__r_beats1_3))))));
    if (((IData)(vlSelf->__PVT__bar__DOT__in_reset) 
         | (0U == (IData)(__PVT__bar__DOT__unnamedblk1__DOT___next_flight_T_10)))) {
        vlSelf->__PVT__bar__DOT__bypass_reg = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__do_bypass;
    }
    if (vlSymsp->TOP.reset) {
        __Vdly__error__DOT__idle = 1U;
        __Vdly__error__DOT__r_counter = 0U;
        vlSelf->__PVT__error__DOT__r_counter = __Vdly__error__DOT__r_counter;
        vlSelf->__PVT__error__DOT__idle = __Vdly__error__DOT__idle;
        __Vdly__error__DOT__a_last_counter = 0U;
        vlSelf->__PVT__error__DOT__a_last_counter = __Vdly__error__DOT__a_last_counter;
        __Vdly__error__DOT__beatsLeft = 0U;
        vlSelf->__PVT__error__DOT__state_1 = 0U;
        vlSelf->__PVT__error__DOT__beatsLeft = __Vdly__error__DOT__beatsLeft;
        vlSelf->__PVT__bar__DOT__flight = 0U;
        __Vdly__bar__DOT__r_counter = 0U;
        __Vdly__bar__DOT__r_counter_3 = 0U;
        __Vdly__bar__DOT__stall_counter = 0U;
    } else {
        vlSelf->__PVT__error__DOT__unnamedblk1__DOT___GEN_1 
            = ((IData)(vlSelf->__PVT__error__DOT__da_ready) 
               & (IData)(vlSelf->__PVT__error__DOT__winner_1));
        __Vdly__error__DOT__idle = ((~ ((IData)(vlSelf->__PVT__error__DOT__unnamedblk1__DOT___GEN_1) 
                                        & (4U == (IData)(vlSelf->__PVT__error__DOT__da_bits_opcode)))) 
                                    & (IData)(vlSelf->__PVT__error__DOT__idle));
        if (vlSelf->__PVT__error__DOT__unnamedblk1__DOT___GEN_1) {
            __Vdly__error__DOT__r_counter = (0x3ffU 
                                             & ((IData)(vlSelf->__PVT__error__DOT__da_first)
                                                 ? (IData)(vlSelf->__PVT__error__DOT__r_beats1)
                                                 : 
                                                ((IData)(vlSelf->__PVT__error__DOT__r_counter) 
                                                 - (IData)(1U))));
        }
        vlSelf->__PVT__error__DOT__r_counter = __Vdly__error__DOT__r_counter;
        vlSelf->__PVT__error__DOT__idle = __Vdly__error__DOT__idle;
        if (((IData)(vlSelf->__PVT__error__DOT__nodeIn_a_ready) 
             & (IData)(vlSelf->__PVT___bar_auto_out_0_a_valid))) {
            __Vdly__error__DOT__a_last_counter = (0x3ffU 
                                                  & ((0U 
                                                      == (IData)(vlSelf->__PVT__error__DOT__a_last_counter))
                                                      ? (IData)(vlSelf->__PVT__error__DOT__a_last_beats1)
                                                      : 
                                                     ((IData)(vlSelf->__PVT__error__DOT__a_last_counter) 
                                                      - (IData)(1U))));
        }
        vlSelf->__PVT__error__DOT__a_last_counter = __Vdly__error__DOT__a_last_counter;
        __Vdly__error__DOT__beatsLeft = (0x3ffU & (
                                                   ((IData)(vlSelf->__PVT__error__DOT__idle_1) 
                                                    & (IData)(vlSelf->__PVT___bar_auto_out_0_d_ready))
                                                    ? 
                                                   (((IData)(vlSelf->__PVT__error__DOT__winner_1) 
                                                     & (IData)(vlSelf->__PVT__error__DOT__da_bits_opcode))
                                                     ? 
                                                    (~ 
                                                     (0x1ffffffU 
                                                      & (((IData)(0xfffU) 
                                                          << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)) 
                                                         >> 2U)))
                                                     : 0U)
                                                    : 
                                                   ((IData)(vlSelf->__PVT__error__DOT__beatsLeft) 
                                                    - 
                                                    ((IData)(vlSelf->__PVT___bar_auto_out_0_d_ready) 
                                                     & (IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid)))));
        if ((0U == (IData)(vlSelf->__PVT__error__DOT__beatsLeft))) {
            vlSelf->__PVT__error__DOT__state_1 = vlSelf->__PVT__error__DOT__winner_1;
        }
        vlSelf->__PVT__error__DOT__beatsLeft = __Vdly__error__DOT__beatsLeft;
        if (__PVT__bar__DOT__unnamedblk1__DOT___stall_T_1) {
            vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__unnamedblk2__DOT___stall_beats1_decode_T 
                = (0xfffU & ((IData)(0x1fU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)));
            __Vdly__bar__DOT__r_counter = (7U & ((IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__a_first)
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))
                                                   ? 0U
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__unnamedblk2__DOT___stall_beats1_decode_T) 
                                                    >> 2U)))
                                                  : 
                                                 ((IData)(vlSelf->__PVT__bar__DOT__r_counter) 
                                                  - (IData)(1U))));
            __Vdly__bar__DOT__stall_counter = (7U & 
                                               ((IData)(vlSelf->__PVT__bar__DOT__stall_first)
                                                 ? 
                                                ((4U 
                                                  & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))
                                                  ? 0U
                                                  : 
                                                 (~ 
                                                  ((IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__unnamedblk2__DOT___stall_beats1_decode_T) 
                                                   >> 2U)))
                                                 : 
                                                ((IData)(vlSelf->__PVT__bar__DOT__stall_counter) 
                                                 - (IData)(1U))));
        }
        if (__PVT__bar__DOT__unnamedblk1__DOT___d_dec_T) {
            __Vdly__bar__DOT__r_counter_3 = (7U & ((IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__d_first)
                                                    ? (IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__r_beats1_3)
                                                    : 
                                                   ((IData)(vlSelf->__PVT__bar__DOT__r_counter_3) 
                                                    - (IData)(1U))));
        }
        vlSelf->__PVT__bar__DOT__flight = __PVT__bar__DOT__unnamedblk1__DOT___next_flight_T_10;
    }
    vlSelf->__PVT__bar__DOT__r_counter = __Vdly__bar__DOT__r_counter;
    vlSelf->__PVT__bar__DOT__r_counter_3 = __Vdly__bar__DOT__r_counter_3;
    vlSelf->__PVT__bar__DOT__stall_counter = __Vdly__bar__DOT__stall_counter;
    __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2 
        = ((IData)(vlSelf->__PVT___bar_auto_out_0_d_ready) 
           & (IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid));
    if (((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter)))))) {
        vlSelf->__PVT__error__DOT__monitor__DOT__opcode_1 
            = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24;
        vlSelf->__PVT__error__DOT__monitor__DOT__size_1 
            = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19;
        vlSelf->__PVT__error__DOT__monitor__DOT__source_1 
            = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16;
        vlSelf->__PVT__error__DOT__monitor__DOT__denied 
            = vlSelf->__PVT__error__DOT__muxState_1;
    }
    if (((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___a_first_T_1) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter)))))) {
        vlSelf->__PVT__error__DOT__monitor__DOT__opcode 
            = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode;
        vlSelf->__PVT__error__DOT__monitor__DOT__size 
            = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size;
        vlSelf->__PVT__error__DOT__monitor__DOT__source 
            = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source;
        vlSelf->__PVT__error__DOT__monitor__DOT__address[0U] 
            = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address;
        vlSelf->__PVT__error__DOT__monitor__DOT__address[1U] = 0U;
        vlSelf->__PVT__error__DOT__monitor__DOT__address[2U] = 0U;
        vlSelf->__PVT__error__DOT__monitor__DOT__address[3U] = 0U;
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2 
        = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__xbar_1.auto_anon_out_0_d_ready) 
           & (IData)(vlSelf->auto_node_in_in_d_valid));
    if (vlSymsp->TOP.reset) {
        __Vdly__error__DOT__monitor__DOT__d_first_counter = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_opcodes = 0ULL;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[0U] = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[1U] = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[2U] = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[3U] = 0U;
        __Vdly__error__DOT__monitor__DOT__d_first_counter_1 = 0U;
        __Vdly__error__DOT__monitor__DOT__watchdog = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_1 = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[0U] = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[1U] = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[2U] = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[3U] = 0U;
        __Vdly__error__DOT__monitor__DOT__d_first_counter_2 = 0U;
        __Vdly__error__DOT__monitor__DOT__watchdog_1 = 0U;
        __Vdly__error__DOT__monitor__DOT__a_first_counter = 0U;
        __Vdly__error__DOT__monitor__DOT__a_first_counter_1 = 0U;
        __Vdly__bar__DOT__monitor__DOT__d_first_counter = 0U;
        __Vdly__bar__DOT__monitor__DOT__inflight = 0U;
        __Vdly__bar__DOT__monitor__DOT__inflight_opcodes = 0ULL;
        __Vdly__bar__DOT__monitor__DOT__inflight_sizes = 0ULL;
        __Vdly__bar__DOT__monitor__DOT__d_first_counter_1 = 0U;
        __Vdly__bar__DOT__monitor__DOT__watchdog = 0U;
        __Vdly__bar__DOT__monitor__DOT__inflight_1 = 0U;
        __Vdly__bar__DOT__monitor__DOT__inflight_sizes_1 = 0ULL;
        __Vdly__bar__DOT__monitor__DOT__d_first_counter_2 = 0U;
        __Vdly__bar__DOT__monitor__DOT__watchdog_1 = 0U;
        __Vdly__bar__DOT__monitor__DOT__a_first_counter = 0U;
        __Vdly__bar__DOT__monitor__DOT__a_first_counter_1 = 0U;
    } else {
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37[0U] 
            = ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
               << 3U);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37[1U] 
            = ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
               >> 0x1dU);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37[2U] = 0U;
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37[3U] = 0U;
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37[4U] = 0U;
        __Vtemp_h6f0d4cc8__0[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__0[1U] = 0U;
        __Vtemp_h6f0d4cc8__0[2U] = 0U;
        __Vtemp_h6f0d4cc8__0[3U] = 0U;
        __Vtemp_h6f0d4cc8__0[4U] = 0U;
        __Vtemp_h814bf4f2__0[0U] = ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
                                    << 2U);
        __Vtemp_h814bf4f2__0[1U] = ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
                                    >> 0x1eU);
        __Vtemp_h814bf4f2__0[2U] = 0U;
        __Vtemp_h814bf4f2__0[3U] = 0U;
        __Vtemp_h814bf4f2__0[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_h1ec71af6__0, __Vtemp_h6f0d4cc8__0, __Vtemp_h814bf4f2__0);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U] 
            = __Vtemp_h1ec71af6__0[0U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U] 
            = __Vtemp_h1ec71af6__0[1U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[2U] 
            = __Vtemp_h1ec71af6__0[2U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[3U] 
            = __Vtemp_h1ec71af6__0[3U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[4U] 
            = (0x7fffU & __Vtemp_h1ec71af6__0[4U]);
        if (vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0) {
            __Vtemp_h402f1848__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode) 
                                              << 1U));
            __Vtemp_h8e9d450e__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                                              << 1U));
        } else {
            __Vtemp_h402f1848__0[0U] = 0U;
            __Vtemp_h8e9d450e__0[0U] = 0U;
        }
        __Vtemp_h402f1848__0[1U] = 0U;
        __Vtemp_h402f1848__0[2U] = 0U;
        __Vtemp_h402f1848__0[3U] = 0U;
        __Vtemp_h402f1848__0[4U] = 0U;
        __Vtemp_h9ecf9258__0[0U] = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
                                    << 2U);
        __Vtemp_h9ecf9258__0[1U] = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
                                    >> 0x1eU);
        __Vtemp_h9ecf9258__0[2U] = 0U;
        __Vtemp_h9ecf9258__0[3U] = 0U;
        __Vtemp_h9ecf9258__0[4U] = 0U;
        VL_SHIFTL_WWW(131,131,131, __Vtemp_h0fe840ea__0, __Vtemp_h402f1848__0, __Vtemp_h9ecf9258__0);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U] 
            = __Vtemp_h0fe840ea__0[0U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U] 
            = __Vtemp_h0fe840ea__0[1U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[2U] 
            = __Vtemp_h0fe840ea__0[2U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[3U] 
            = __Vtemp_h0fe840ea__0[3U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[4U] 
            = (7U & __Vtemp_h0fe840ea__0[4U]);
        __Vtemp_hab69a0d4__0[0U] = 0xffU;
        __Vtemp_hab69a0d4__0[1U] = 0U;
        __Vtemp_hab69a0d4__0[2U] = 0U;
        __Vtemp_hab69a0d4__0[3U] = 0U;
        __Vtemp_hab69a0d4__0[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_hedb9a1f6__0, __Vtemp_hab69a0d4__0, vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U] 
            = __Vtemp_hedb9a1f6__0[0U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U] 
            = __Vtemp_hedb9a1f6__0[1U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[2U] 
            = __Vtemp_hedb9a1f6__0[2U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[3U] 
            = __Vtemp_hedb9a1f6__0[3U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[4U] 
            = (0x7fffU & __Vtemp_hedb9a1f6__0[4U]);
        __Vtemp_h8e9d450e__0[1U] = 0U;
        __Vtemp_h8e9d450e__0[2U] = 0U;
        __Vtemp_h8e9d450e__0[3U] = 0U;
        __Vtemp_h8e9d450e__0[4U] = 0U;
        __Vtemp_h1aa7efb5__0[0U] = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
                                    << 3U);
        __Vtemp_h1aa7efb5__0[1U] = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
                                    >> 0x1dU);
        __Vtemp_h1aa7efb5__0[2U] = 0U;
        __Vtemp_h1aa7efb5__0[3U] = 0U;
        __Vtemp_h1aa7efb5__0[4U] = 0U;
        VL_SHIFTL_WWW(132,132,132, __Vtemp_h4911bd3b__0, __Vtemp_h8e9d450e__0, __Vtemp_h1aa7efb5__0);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U] 
            = __Vtemp_h4911bd3b__0[0U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U] 
            = __Vtemp_h4911bd3b__0[1U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[2U] 
            = __Vtemp_h4911bd3b__0[2U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[3U] 
            = __Vtemp_h4911bd3b__0[3U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[4U] 
            = (0xfU & __Vtemp_h4911bd3b__0[4U]);
        __Vtemp_hab69a0d4__1[0U] = 0xffU;
        __Vtemp_hab69a0d4__1[1U] = 0U;
        __Vtemp_hab69a0d4__1[2U] = 0U;
        __Vtemp_hab69a0d4__1[3U] = 0U;
        __Vtemp_hab69a0d4__1[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_h131918fc__0, __Vtemp_hab69a0d4__1, vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[0U] 
            = __Vtemp_h131918fc__0[0U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[1U] 
            = __Vtemp_h131918fc__0[1U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[2U] 
            = __Vtemp_h131918fc__0[2U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[3U] 
            = __Vtemp_h131918fc__0[3U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[4U] 
            = (0x7fffU & __Vtemp_h131918fc__0[4U]);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36 
            = (((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
                & (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_1)) 
               & (6U != (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24)));
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38 
            = (((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
                & (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_2)) 
               & (6U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24)));
        if (__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) {
            vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                = (0x7ffffffU & ((IData)(0xfffU) << (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19)));
            __Vdly__error__DOT__monitor__DOT__d_first_counter 
                = (0x3ffU & ((0U != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter))
                              ? ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter) 
                                 - (IData)(1U)) : (
                                                   (1U 
                                                    & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))
                                                    ? 
                                                   (~ 
                                                    (vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                                                     >> 2U))
                                                    : 0U)));
            __Vdly__error__DOT__monitor__DOT__d_first_counter_1 
                = (0x3ffU & ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_1)
                              ? ((1U & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))
                                  ? (~ (vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                                        >> 2U)) : 0U)
                              : ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_1) 
                                 - (IData)(1U))));
            __Vdly__error__DOT__monitor__DOT__d_first_counter_2 
                = (0x3ffU & ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_2)
                              ? ((1U & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))
                                  ? (~ (vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                                        >> 2U)) : 0U)
                              : ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_2) 
                                 - (IData)(1U))));
            __Vdly__error__DOT__monitor__DOT__watchdog_1 = 0U;
        } else {
            __Vdly__error__DOT__monitor__DOT__watchdog_1 
                = ((IData)(1U) + vlSelf->__PVT__error__DOT__monitor__DOT__watchdog_1);
        }
        __Vdly__error__DOT__monitor__DOT__inflight 
            = (0xffffU & (((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight) 
                           | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0)
                               ? ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source))
                                   ? ((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source))
                                   : 0U) : 0U)) & (~ 
                                                   ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36)
                                                     ? 
                                                    ((0xfU 
                                                      >= (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))
                                                      ? 
                                                     ((IData)(1U) 
                                                      << (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))
                                                      : 0U)
                                                     : 0U))));
        __Vdly__error__DOT__monitor__DOT__inflight_opcodes 
            = ((vlSelf->__PVT__error__DOT__monitor__DOT__inflight_opcodes 
                | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0)
                    ? (((QData)((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U])))
                    : 0ULL)) & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36)
                                    ? (((QData)((IData)(
                                                        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U])))
                                    : 0ULL)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[0U] 
            = ((vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[0U] 
                | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0)
                    ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U]
                    : 0U)) & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36)
                                  ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U]
                                  : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[1U] 
            = ((vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[1U] 
                | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0)
                    ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U]
                    : 0U)) & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36)
                                  ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U]
                                  : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[2U] 
            = ((vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[2U] 
                | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0)
                    ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[2U]
                    : 0U)) & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36)
                                  ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[2U]
                                  : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[3U] 
            = ((vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[3U] 
                | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0)
                    ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[3U]
                    : 0U)) & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36)
                                  ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[3U]
                                  : 0U)));
        __Vdly__error__DOT__monitor__DOT__watchdog 
            = (((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___a_first_T_1) 
                | (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2))
                ? 0U : ((IData)(1U) + vlSelf->__PVT__error__DOT__monitor__DOT__watchdog));
        __Vdly__error__DOT__monitor__DOT__inflight_1 
            = ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight_1) 
               & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38)
                      ? ((0xfU >= (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))
                          ? ((IData)(1U) << (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))
                          : 0U) : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[0U] 
            = (vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[0U] 
               & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38)
                      ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[0U]
                      : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[1U] 
            = (vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[1U] 
               & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38)
                      ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[1U]
                      : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[2U] 
            = (vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[2U] 
               & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38)
                      ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[2U]
                      : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[3U] 
            = (vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[3U] 
               & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38)
                      ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[3U]
                      : 0U)));
        if (vlSelf->__PVT__error__DOT__monitor__DOT___a_first_T_1) {
            vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 
                = ((0x1aU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size))
                    ? (0x7ffffffU & ((IData)(0xfffU) 
                                     << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)))
                    : 0U);
            __Vdly__error__DOT__monitor__DOT__a_first_counter 
                = (0x3ffU & ((0U != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter))
                              ? ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter) 
                                 - (IData)(1U)) : (
                                                   (4U 
                                                    & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))
                                                    ? 0U
                                                    : 
                                                   (~ 
                                                    (vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 
                                                     >> 2U)))));
            __Vdly__error__DOT__monitor__DOT__a_first_counter_1 
                = (0x3ffU & ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_1)
                              ? ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))
                                  ? 0U : (~ (vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 
                                             >> 2U)))
                              : ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1) 
                                 - (IData)(1U))));
        }
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[0U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
               << 2U);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[1U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
               >> 0x1eU);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[2U] = 0U;
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[3U] = 0U;
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[4U] = 0U;
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0U] 
            = ((IData)(vlSelf->auto_node_in_in_d_bits_source) 
               << 2U);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[1U] 
            = ((IData)(vlSelf->auto_node_in_in_d_bits_source) 
               >> 0x1eU);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[2U] = 0U;
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[3U] = 0U;
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[4U] = 0U;
        __Vtemp_h6f0d4cc8__1[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__1[1U] = 0U;
        __Vtemp_h6f0d4cc8__1[2U] = 0U;
        __Vtemp_h6f0d4cc8__1[3U] = 0U;
        __Vtemp_h6f0d4cc8__1[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_hee7b10c9__0, __Vtemp_h6f0d4cc8__1, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U] 
            = __Vtemp_hee7b10c9__0[0U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U] 
            = __Vtemp_hee7b10c9__0[1U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[2U] 
            = __Vtemp_hee7b10c9__0[2U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[3U] 
            = __Vtemp_hee7b10c9__0[3U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[4U] 
            = (0x7fffU & __Vtemp_hee7b10c9__0[4U]);
        if (vlSelf->__PVT__bar__DOT__monitor__DOT___GEN_0) {
            __Vtemp_hd1f2b9ce__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode) 
                                              << 1U));
            __Vtemp_hf2fbc16c__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size) 
                                              << 1U));
        } else {
            __Vtemp_hd1f2b9ce__0[0U] = 0U;
            __Vtemp_hf2fbc16c__0[0U] = 0U;
        }
        __Vtemp_hd1f2b9ce__0[1U] = 0U;
        __Vtemp_hd1f2b9ce__0[2U] = 0U;
        __Vtemp_hd1f2b9ce__0[3U] = 0U;
        __Vtemp_hd1f2b9ce__0[4U] = 0U;
        VL_SHIFTL_WWW(131,131,131, __Vtemp_hff857c10__0, __Vtemp_hd1f2b9ce__0, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U] 
            = __Vtemp_hff857c10__0[0U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U] 
            = __Vtemp_hff857c10__0[1U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[2U] 
            = __Vtemp_hff857c10__0[2U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[3U] 
            = __Vtemp_hff857c10__0[3U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[4U] 
            = (7U & __Vtemp_hff857c10__0[4U]);
        __Vtemp_h6f0d4cc8__2[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__2[1U] = 0U;
        __Vtemp_h6f0d4cc8__2[2U] = 0U;
        __Vtemp_h6f0d4cc8__2[3U] = 0U;
        __Vtemp_h6f0d4cc8__2[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_hcb4b53f9__0, __Vtemp_h6f0d4cc8__2, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U] 
            = __Vtemp_hcb4b53f9__0[0U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U] 
            = __Vtemp_hcb4b53f9__0[1U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[2U] 
            = __Vtemp_hcb4b53f9__0[2U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[3U] 
            = __Vtemp_hcb4b53f9__0[3U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[4U] 
            = (0x7fffU & __Vtemp_hcb4b53f9__0[4U]);
        __Vtemp_hf2fbc16c__0[1U] = 0U;
        __Vtemp_hf2fbc16c__0[2U] = 0U;
        __Vtemp_hf2fbc16c__0[3U] = 0U;
        __Vtemp_hf2fbc16c__0[4U] = 0U;
        VL_SHIFTL_WWW(131,131,131, __Vtemp_h4c24cd42__0, __Vtemp_hf2fbc16c__0, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U] 
            = __Vtemp_h4c24cd42__0[0U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U] 
            = __Vtemp_h4c24cd42__0[1U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[2U] 
            = __Vtemp_h4c24cd42__0[2U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[3U] 
            = __Vtemp_h4c24cd42__0[3U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[4U] 
            = (7U & __Vtemp_h4c24cd42__0[4U]);
        __Vtemp_h6f0d4cc8__3[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__3[1U] = 0U;
        __Vtemp_h6f0d4cc8__3[2U] = 0U;
        __Vtemp_h6f0d4cc8__3[3U] = 0U;
        __Vtemp_h6f0d4cc8__3[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_h5911eb2f__0, __Vtemp_h6f0d4cc8__3, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[0U] 
            = __Vtemp_h5911eb2f__0[0U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[1U] 
            = __Vtemp_h5911eb2f__0[1U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[2U] 
            = __Vtemp_h5911eb2f__0[2U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[3U] 
            = __Vtemp_h5911eb2f__0[3U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[4U] 
            = (0x7fffU & __Vtemp_h5911eb2f__0[4U]);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41 
            = (((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
                & (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_1)) 
               & (6U != (IData)(vlSelf->auto_node_in_in_d_bits_opcode)));
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43 
            = (((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
                & (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_2)) 
               & (6U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode)));
        if (__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) {
            vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                = (0xfffU & ((IData)(0x1fU) << (IData)(vlSelf->auto_node_in_in_d_bits_size)));
            __Vdly__bar__DOT__monitor__DOT__d_first_counter 
                = (7U & ((0U != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter))
                          ? ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter) 
                             - (IData)(1U)) : ((1U 
                                                & (IData)(vlSelf->auto_node_in_in_d_bits_opcode))
                                                ? (~ 
                                                   ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                                    >> 2U))
                                                : 0U)));
            __Vdly__bar__DOT__monitor__DOT__d_first_counter_1 
                = (7U & ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_1)
                          ? ((1U & (IData)(vlSelf->auto_node_in_in_d_bits_opcode))
                              ? (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                    >> 2U)) : 0U) : 
                         ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_1) 
                          - (IData)(1U))));
            __Vdly__bar__DOT__monitor__DOT__d_first_counter_2 
                = (7U & ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_2)
                          ? ((1U & (IData)(vlSelf->auto_node_in_in_d_bits_opcode))
                              ? (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                    >> 2U)) : 0U) : 
                         ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_2) 
                          - (IData)(1U))));
            __Vdly__bar__DOT__monitor__DOT__watchdog_1 = 0U;
        } else {
            __Vdly__bar__DOT__monitor__DOT__watchdog_1 
                = ((IData)(1U) + vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog_1);
        }
        __Vdly__bar__DOT__monitor__DOT__inflight = 
            (0xffffU & (((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight) 
                         | ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___GEN_0)
                             ? ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source))
                                 ? ((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source))
                                 : 0U) : 0U)) & (~ 
                                                 ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41)
                                                   ? 
                                                  ((0xfU 
                                                    >= (IData)(vlSelf->auto_node_in_in_d_bits_source))
                                                    ? 
                                                   ((IData)(1U) 
                                                    << (IData)(vlSelf->auto_node_in_in_d_bits_source))
                                                    : 0U)
                                                   : 0U))));
        __Vdly__bar__DOT__monitor__DOT__inflight_opcodes 
            = ((vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_opcodes 
                | ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___GEN_0)
                    ? (((QData)((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U])))
                    : 0ULL)) & (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41)
                                    ? (((QData)((IData)(
                                                        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U])))
                                    : 0ULL)));
        __Vdly__bar__DOT__monitor__DOT__inflight_sizes 
            = ((vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes 
                | ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___GEN_0)
                    ? (((QData)((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U])))
                    : 0ULL)) & (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41)
                                    ? (((QData)((IData)(
                                                        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U])))
                                    : 0ULL)));
        __Vdly__bar__DOT__monitor__DOT__watchdog = 
            (((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___a_first_T_1) 
              | (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2))
              ? 0U : ((IData)(1U) + vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog));
        __Vdly__bar__DOT__monitor__DOT__inflight_1 
            = ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_1) 
               & (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? ((0xfU >= (IData)(vlSelf->auto_node_in_in_d_bits_source))
                          ? ((IData)(1U) << (IData)(vlSelf->auto_node_in_in_d_bits_source))
                          : 0U) : 0U)));
        __Vdly__bar__DOT__monitor__DOT__inflight_sizes_1 
            = (vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes_1 
               & (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? (((QData)((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[1U])) 
                          << 0x20U) | (QData)((IData)(
                                                      vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[0U])))
                      : 0ULL)));
        if (vlSelf->__PVT__bar__DOT__monitor__DOT___a_first_T_1) {
            vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 
                = ((0xbU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size))
                    ? (0xfffU & ((IData)(0x1fU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size)))
                    : 0U);
            __Vdly__bar__DOT__monitor__DOT__a_first_counter 
                = (7U & ((0U != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter))
                          ? ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter) 
                             - (IData)(1U)) : ((4U 
                                                & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))
                                                ? 0U
                                                : (~ 
                                                   ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3) 
                                                    >> 2U)))));
            __Vdly__bar__DOT__monitor__DOT__a_first_counter_1 
                = (7U & ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_1)
                          ? ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode))
                              ? 0U : (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3) 
                                         >> 2U))) : 
                         ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1) 
                          - (IData)(1U))));
        }
    }
    if (((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter)))))) {
        vlSelf->__PVT__bar__DOT__monitor__DOT__opcode_1 
            = vlSelf->auto_node_in_in_d_bits_opcode;
        vlSelf->__PVT__bar__DOT__monitor__DOT__param_1 
            = vlSelf->auto_node_in_in_d_bits_param;
        vlSelf->__PVT__bar__DOT__monitor__DOT__size_1 
            = vlSelf->auto_node_in_in_d_bits_size;
        vlSelf->__PVT__bar__DOT__monitor__DOT__source_1 
            = vlSelf->auto_node_in_in_d_bits_source;
        vlSelf->__PVT__bar__DOT__monitor__DOT__sink 
            = vlSelf->auto_node_in_in_d_bits_sink;
        vlSelf->__PVT__bar__DOT__monitor__DOT__denied 
            = vlSelf->auto_node_in_in_d_bits_denied;
    }
    if (((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___a_first_T_1) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter)))))) {
        vlSelf->__PVT__bar__DOT__monitor__DOT__opcode 
            = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_opcode;
        vlSelf->__PVT__bar__DOT__monitor__DOT__size 
            = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_size;
        vlSelf->__PVT__bar__DOT__monitor__DOT__source 
            = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source;
        vlSelf->__PVT__bar__DOT__monitor__DOT__address 
            = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address;
    }
    vlSelf->__PVT__error__DOT__da_first = (0U == (IData)(vlSelf->__PVT__error__DOT__r_counter));
    vlSelf->__PVT__error__DOT__idle_1 = (0U == (IData)(vlSelf->__PVT__error__DOT__beatsLeft));
    vlSelf->error__DOT____VdfgTmp_hc0029b36__0 = ((0U 
                                                   == (IData)(vlSelf->__PVT__error__DOT__beatsLeft)) 
                                                  | (IData)(vlSelf->__PVT__error__DOT__state_1));
    vlSelf->__PVT__bar__DOT__stall_first = (0U == (IData)(vlSelf->__PVT__bar__DOT__stall_counter));
    vlSelf->__PVT__bar__DOT__in_reset = vlSymsp->TOP.reset;
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter 
        = __Vdly__error__DOT__monitor__DOT__d_first_counter;
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight 
        = __Vdly__error__DOT__monitor__DOT__inflight;
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_opcodes 
        = __Vdly__error__DOT__monitor__DOT__inflight_opcodes;
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[0U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes[0U];
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[1U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes[1U];
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[2U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes[2U];
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[3U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes[3U];
    vlSelf->__PVT__error__DOT__monitor__DOT__watchdog 
        = __Vdly__error__DOT__monitor__DOT__watchdog;
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_1 
        = __Vdly__error__DOT__monitor__DOT__inflight_1;
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[0U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[0U];
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[1U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[1U];
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[2U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[2U];
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[3U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[3U];
    vlSelf->__PVT__error__DOT__monitor__DOT__watchdog_1 
        = __Vdly__error__DOT__monitor__DOT__watchdog_1;
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_1 
        = __Vdly__error__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_2 
        = __Vdly__error__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter 
        = __Vdly__error__DOT__monitor__DOT__a_first_counter;
    vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1 
        = __Vdly__error__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter 
        = __Vdly__bar__DOT__monitor__DOT__d_first_counter;
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight 
        = __Vdly__bar__DOT__monitor__DOT__inflight;
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_opcodes 
        = __Vdly__bar__DOT__monitor__DOT__inflight_opcodes;
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes 
        = __Vdly__bar__DOT__monitor__DOT__inflight_sizes;
    vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog 
        = __Vdly__bar__DOT__monitor__DOT__watchdog;
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_1 
        = __Vdly__bar__DOT__monitor__DOT__inflight_1;
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes_1 
        = __Vdly__bar__DOT__monitor__DOT__inflight_sizes_1;
    vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog_1 
        = __Vdly__bar__DOT__monitor__DOT__watchdog_1;
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_1 
        = __Vdly__bar__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_2 
        = __Vdly__bar__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter 
        = __Vdly__bar__DOT__monitor__DOT__a_first_counter;
    vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1 
        = __Vdly__bar__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_1 
        = (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_2 
        = (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_2));
    vlSelf->__PVT__error__DOT__monitor__DOT__a_first_1 
        = (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_1 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_2 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_2));
    vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_1 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1));
}

VL_INLINE_OPT void VysyxSoCFull_TLBusBypass___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass__1(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass__1\n"); );
    // Body
    vlSelf->__PVT__bar__DOT__bypass = ((IData)(vlSelf->__PVT__bar__DOT__in_reset)
                                        ? (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__do_bypass)
                                        : (IData)(vlSelf->__PVT__bar__DOT__bypass_reg));
    if (vlSelf->__PVT__bar__DOT__bypass) {
        vlSelf->auto_node_in_in_d_bits_param = 0U;
        vlSelf->auto_node_in_in_d_bits_sink = 0U;
    } else {
        vlSelf->auto_node_in_in_d_bits_param = (3U 
                                                & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__q_param));
        vlSelf->auto_node_in_in_d_bits_sink = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT___sourceD_io_d_bits_sink;
    }
    vlSelf->__PVT__bar__DOT__stall = (((IData)(vlSelf->__PVT__bar__DOT__bypass) 
                                       != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__do_bypass)) 
                                      & (0U == (IData)(vlSelf->__PVT__bar__DOT__stall_counter)));
}

VL_INLINE_OPT void VysyxSoCFull_TLBusBypass___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass__0(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass__0\n"); );
    // Init
    CData/*0:0*/ __PVT__bar__DOT__unnamedblk1__DOT___stall_T_1;
    __PVT__bar__DOT__unnamedblk1__DOT___stall_T_1 = 0;
    CData/*0:0*/ __PVT__bar__DOT__unnamedblk1__DOT___d_dec_T;
    __PVT__bar__DOT__unnamedblk1__DOT___d_dec_T = 0;
    SData/*11:0*/ __PVT__bar__DOT__unnamedblk1__DOT___rbeats1_decode_T_9;
    __PVT__bar__DOT__unnamedblk1__DOT___rbeats1_decode_T_9 = 0;
    CData/*5:0*/ __PVT__bar__DOT__unnamedblk1__DOT___next_flight_T_10;
    __PVT__bar__DOT__unnamedblk1__DOT___next_flight_T_10 = 0;
    SData/*11:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T = 0;
    CData/*4:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_7;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_7 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30 = 0;
    QData/*63:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31 = 0;
    QData/*63:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_36;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_36 = 0;
    SData/*15:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_37;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_37 = 0;
    SData/*15:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_38;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_38 = 0;
    QData/*63:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1 = 0;
    SData/*15:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_39;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_39 = 0;
    QData/*63:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1;
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1 = 0;
    CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2;
    __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2 = 0;
    IData/*26:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T = 0;
    SData/*11:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25 = 0;
    QData/*63:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 = 0;
    VlWide<4>/*127:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26;
    VL_ZERO_W(128, __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26);
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30 = 0;
    CData/*7:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31 = 0;
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32 = 0;
    SData/*15:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33 = 0;
    SData/*15:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34 = 0;
    VlWide<4>/*127:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1;
    VL_ZERO_W(128, __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1);
    SData/*15:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35 = 0;
    VlWide<4>/*127:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1;
    VL_ZERO_W(128, __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1);
    CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2;
    __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2 = 0;
    CData/*2:0*/ __Vdly__bar__DOT__r_counter;
    __Vdly__bar__DOT__r_counter = 0;
    CData/*2:0*/ __Vdly__bar__DOT__r_counter_3;
    __Vdly__bar__DOT__r_counter_3 = 0;
    CData/*2:0*/ __Vdly__bar__DOT__stall_counter;
    __Vdly__bar__DOT__stall_counter = 0;
    CData/*2:0*/ __Vdly__bar__DOT__monitor__DOT__d_first_counter;
    __Vdly__bar__DOT__monitor__DOT__d_first_counter = 0;
    SData/*15:0*/ __Vdly__bar__DOT__monitor__DOT__inflight;
    __Vdly__bar__DOT__monitor__DOT__inflight = 0;
    QData/*63:0*/ __Vdly__bar__DOT__monitor__DOT__inflight_opcodes;
    __Vdly__bar__DOT__monitor__DOT__inflight_opcodes = 0;
    QData/*63:0*/ __Vdly__bar__DOT__monitor__DOT__inflight_sizes;
    __Vdly__bar__DOT__monitor__DOT__inflight_sizes = 0;
    CData/*2:0*/ __Vdly__bar__DOT__monitor__DOT__d_first_counter_1;
    __Vdly__bar__DOT__monitor__DOT__d_first_counter_1 = 0;
    IData/*31:0*/ __Vdly__bar__DOT__monitor__DOT__watchdog;
    __Vdly__bar__DOT__monitor__DOT__watchdog = 0;
    SData/*15:0*/ __Vdly__bar__DOT__monitor__DOT__inflight_1;
    __Vdly__bar__DOT__monitor__DOT__inflight_1 = 0;
    QData/*63:0*/ __Vdly__bar__DOT__monitor__DOT__inflight_sizes_1;
    __Vdly__bar__DOT__monitor__DOT__inflight_sizes_1 = 0;
    CData/*2:0*/ __Vdly__bar__DOT__monitor__DOT__d_first_counter_2;
    __Vdly__bar__DOT__monitor__DOT__d_first_counter_2 = 0;
    IData/*31:0*/ __Vdly__bar__DOT__monitor__DOT__watchdog_1;
    __Vdly__bar__DOT__monitor__DOT__watchdog_1 = 0;
    CData/*2:0*/ __Vdly__bar__DOT__monitor__DOT__a_first_counter;
    __Vdly__bar__DOT__monitor__DOT__a_first_counter = 0;
    CData/*2:0*/ __Vdly__bar__DOT__monitor__DOT__a_first_counter_1;
    __Vdly__bar__DOT__monitor__DOT__a_first_counter_1 = 0;
    CData/*0:0*/ __Vdly__error__DOT__idle;
    __Vdly__error__DOT__idle = 0;
    SData/*9:0*/ __Vdly__error__DOT__r_counter;
    __Vdly__error__DOT__r_counter = 0;
    SData/*9:0*/ __Vdly__error__DOT__a_last_counter;
    __Vdly__error__DOT__a_last_counter = 0;
    SData/*9:0*/ __Vdly__error__DOT__beatsLeft;
    __Vdly__error__DOT__beatsLeft = 0;
    SData/*9:0*/ __Vdly__error__DOT__monitor__DOT__d_first_counter;
    __Vdly__error__DOT__monitor__DOT__d_first_counter = 0;
    SData/*15:0*/ __Vdly__error__DOT__monitor__DOT__inflight;
    __Vdly__error__DOT__monitor__DOT__inflight = 0;
    QData/*63:0*/ __Vdly__error__DOT__monitor__DOT__inflight_opcodes;
    __Vdly__error__DOT__monitor__DOT__inflight_opcodes = 0;
    VlWide<4>/*127:0*/ __Vdly__error__DOT__monitor__DOT__inflight_sizes;
    VL_ZERO_W(128, __Vdly__error__DOT__monitor__DOT__inflight_sizes);
    SData/*9:0*/ __Vdly__error__DOT__monitor__DOT__d_first_counter_1;
    __Vdly__error__DOT__monitor__DOT__d_first_counter_1 = 0;
    IData/*31:0*/ __Vdly__error__DOT__monitor__DOT__watchdog;
    __Vdly__error__DOT__monitor__DOT__watchdog = 0;
    SData/*15:0*/ __Vdly__error__DOT__monitor__DOT__inflight_1;
    __Vdly__error__DOT__monitor__DOT__inflight_1 = 0;
    VlWide<4>/*127:0*/ __Vdly__error__DOT__monitor__DOT__inflight_sizes_1;
    VL_ZERO_W(128, __Vdly__error__DOT__monitor__DOT__inflight_sizes_1);
    SData/*9:0*/ __Vdly__error__DOT__monitor__DOT__d_first_counter_2;
    __Vdly__error__DOT__monitor__DOT__d_first_counter_2 = 0;
    IData/*31:0*/ __Vdly__error__DOT__monitor__DOT__watchdog_1;
    __Vdly__error__DOT__monitor__DOT__watchdog_1 = 0;
    SData/*9:0*/ __Vdly__error__DOT__monitor__DOT__a_first_counter;
    __Vdly__error__DOT__monitor__DOT__a_first_counter = 0;
    SData/*9:0*/ __Vdly__error__DOT__monitor__DOT__a_first_counter_1;
    __Vdly__error__DOT__monitor__DOT__a_first_counter_1 = 0;
    VlWide<4>/*127:0*/ __Vtemp_hf303a3ad__0;
    VlWide<4>/*127:0*/ __Vtemp_h70724169__0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__0;
    VlWide<5>/*159:0*/ __Vtemp_h814bf4f2__0;
    VlWide<5>/*159:0*/ __Vtemp_h1ec71af6__0;
    VlWide<5>/*159:0*/ __Vtemp_he0cf7f05__0;
    VlWide<5>/*159:0*/ __Vtemp_hd643db39__0;
    VlWide<5>/*159:0*/ __Vtemp_h0dcb169b__0;
    VlWide<5>/*159:0*/ __Vtemp_hab69a0d4__0;
    VlWide<5>/*159:0*/ __Vtemp_hedb9a1f6__0;
    VlWide<5>/*159:0*/ __Vtemp_hece19c8e__0;
    VlWide<5>/*159:0*/ __Vtemp_hbb4ee8f4__0;
    VlWide<5>/*159:0*/ __Vtemp_h3700eba1__0;
    VlWide<5>/*159:0*/ __Vtemp_hab69a0d4__1;
    VlWide<5>/*159:0*/ __Vtemp_h131918fc__0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__1;
    VlWide<5>/*159:0*/ __Vtemp_hee7b10c9__0;
    VlWide<5>/*159:0*/ __Vtemp_h04a11209__0;
    VlWide<5>/*159:0*/ __Vtemp_h87029e3d__0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__2;
    VlWide<5>/*159:0*/ __Vtemp_hcb4b53f9__0;
    VlWide<5>/*159:0*/ __Vtemp_h2c36fb9a__0;
    VlWide<5>/*159:0*/ __Vtemp_hb1f1a0ad__0;
    VlWide<5>/*159:0*/ __Vtemp_h6f0d4cc8__3;
    VlWide<5>/*159:0*/ __Vtemp_h5911eb2f__0;
    // Body
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((IData)(vlSelf->__PVT__error__DOT__idle) 
                                 | (0U == (IData)(vlSelf->__PVT__error__DOT__r_counter)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7821: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error: Assertion failed at Error.scala:34\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7821, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7823: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7823, "");
    }
    __Vdly__error__DOT__r_counter = vlSelf->__PVT__error__DOT__r_counter;
    __Vdly__error__DOT__idle = vlSelf->__PVT__error__DOT__idle;
    __Vdly__bar__DOT__monitor__DOT__watchdog_1 = vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog_1;
    __Vdly__bar__DOT__monitor__DOT__inflight_sizes_1 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes_1;
    __Vdly__bar__DOT__monitor__DOT__inflight_1 = vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_1;
    __Vdly__bar__DOT__monitor__DOT__watchdog = vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog;
    __Vdly__bar__DOT__monitor__DOT__inflight_sizes 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes;
    __Vdly__bar__DOT__monitor__DOT__inflight_opcodes 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_opcodes;
    __Vdly__bar__DOT__monitor__DOT__inflight = vlSelf->__PVT__bar__DOT__monitor__DOT__inflight;
    __Vdly__bar__DOT__monitor__DOT__d_first_counter 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter;
    __Vdly__bar__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_2;
    __Vdly__bar__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_1;
    __Vdly__error__DOT__monitor__DOT__watchdog_1 = vlSelf->__PVT__error__DOT__monitor__DOT__watchdog_1;
    __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[0U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[0U];
    __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[1U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[1U];
    __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[2U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[2U];
    __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[3U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[3U];
    __Vdly__error__DOT__monitor__DOT__inflight_1 = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_1;
    __Vdly__error__DOT__monitor__DOT__watchdog = vlSelf->__PVT__error__DOT__monitor__DOT__watchdog;
    __Vdly__error__DOT__monitor__DOT__inflight_sizes[0U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[0U];
    __Vdly__error__DOT__monitor__DOT__inflight_sizes[1U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[1U];
    __Vdly__error__DOT__monitor__DOT__inflight_sizes[2U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[2U];
    __Vdly__error__DOT__monitor__DOT__inflight_sizes[3U] 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[3U];
    __Vdly__error__DOT__monitor__DOT__inflight_opcodes 
        = vlSelf->__PVT__error__DOT__monitor__DOT__inflight_opcodes;
    __Vdly__error__DOT__monitor__DOT__inflight = vlSelf->__PVT__error__DOT__monitor__DOT__inflight;
    __Vdly__error__DOT__monitor__DOT__d_first_counter 
        = vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter;
    __Vdly__error__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_2;
    __Vdly__error__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_1;
    __Vdly__error__DOT__a_last_counter = vlSelf->__PVT__error__DOT__a_last_counter;
    __Vdly__error__DOT__monitor__DOT__a_first_counter 
        = vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter;
    __Vdly__bar__DOT__monitor__DOT__a_first_counter 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter;
    __Vdly__error__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1;
    __Vdly__bar__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1;
    __Vdly__error__DOT__beatsLeft = vlSelf->__PVT__error__DOT__beatsLeft;
    __Vdly__bar__DOT__r_counter_3 = vlSelf->__PVT__bar__DOT__r_counter_3;
    __Vdly__bar__DOT__r_counter = vlSelf->__PVT__bar__DOT__r_counter;
    __Vdly__bar__DOT__stall_counter = vlSelf->__PVT__bar__DOT__stall_counter;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T 
        = ((0x1aU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size))
            ? (0x7ffffffU & ((IData)(0xfffU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)))
            : 0U);
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6 
        = (0xfffU & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                     & (~ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T)));
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1 
        = (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size))) 
                 | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                    & (~ (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                          >> 1U)))));
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1 
        = (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size))) 
                 | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                    & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                       >> 1U))));
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask 
        = ((8U & (((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1) 
                   << 3U) | (0xfffffff8U & ((vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                             << 2U) 
                                            & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                               << 3U))))) 
           | ((4U & (((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1) 
                      << 2U) | (0xfffffffcU & ((vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                                << 1U) 
                                               & ((~ vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address) 
                                                  << 2U))))) 
              | ((2U & (((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1) 
                         | (IData)((1U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address)))) 
                        << 1U)) | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1) 
                                   | (0U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address))))));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9 
        = (0xfU != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_mask));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (7U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (4U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12 
        = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_mask) 
           != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (0U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (1U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15 
        = (5U > (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (2U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (3U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19 
        = (((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
            & (6U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20 
        = (0U == (7U & ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19) 
                        >> 1U)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21 
        = (((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
            & (4U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22 
        = (((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
            & (5U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23 
        = (1U & ((~ (IData)(vlSelf->__PVT__error__DOT__muxState_1)) 
                 | (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26[0U] 
        = ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
           << 3U);
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26[1U] 
        = ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
           >> 0x1dU);
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26[2U] = 0U;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26[3U] = 0U;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27 
        = ((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
           & (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_1)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28 
        = ((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27) 
           & (6U != (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24)));
    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1))) 
           & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
              == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29 
        = (((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
            & (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp)) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30 
        = (((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
            & (~ (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31 
        = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19;
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32 
        = ((((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
             & (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_2))) 
            & (6U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24 
        = (((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
            & (0U != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25 
        = (((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
            & (0U != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
        = VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__error__DOT__monitor__DOT__inflight_opcodes, 
                        ((QData)((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16)) 
                         << 2U));
    if (VL_UNLIKELY(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7253: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7253, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7255: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7255, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (~ (IData)((0U != (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7259: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7259, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7261: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7261, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7265: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7265, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7267: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7267, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7271: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7271, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7273: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7273, "");
    }
    if (VL_UNLIKELY(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7283: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7283, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7285: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7285, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (~ (IData)((0U != (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7289: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7289, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7291: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7291, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7295: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7295, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7297: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7297, "");
    }
    if (VL_UNLIKELY(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7301: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7301, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7303: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7303, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7307: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7307, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7309: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7309, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7323: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Get address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7323, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7325: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7325, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7329: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Get contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7329, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7331: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7331, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7341: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7341, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7343: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7343, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7347: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7347, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7349: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7349, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7359: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7359, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7361: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7361, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (0U != ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_mask) 
                               & (~ (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7365: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7365, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7367: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7367, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16) 
                     & (~ (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7371: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7371, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7373: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7373, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7377: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7377, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7379: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7379, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7383: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7383, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7385: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7385, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17) 
                     & (~ (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7389: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7389, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7391: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7391, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7395: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Logical address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7395, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7397: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7397, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7401: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Logical contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7401, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7403: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7403, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (0U != (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7413: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Hint address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7413, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7415: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7415, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7419: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel Hint contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7419, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7421: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7421, "");
    }
    if (VL_UNLIKELY((((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (7U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7425: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel has invalid opcode (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7425, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7427: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7427, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7431: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7431, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7433: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7433, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7437: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7437, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7439: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7439, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (IData)(vlSelf->__PVT__error__DOT__muxState_1)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7443: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck is denied (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7443, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7445: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7445, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7449: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel Grant smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7449, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7451: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7451, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21) 
                     & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7455: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel Grant is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7455, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7457: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7457, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7461: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7461, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7463: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7463, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (~ (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7467: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7467, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7469: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7469, "");
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
                       & (0U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7474: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7474, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7476: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7476, "");
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
                       & (1U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7480: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7480, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7482: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7482, "");
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid) 
                       & (2U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7487: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel HintAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7487, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7489: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7489, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7493: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7493, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7495: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7495, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7499: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7499, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7501: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7501, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__source))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7505: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7505, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7507: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7507, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & (0U != ((((vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                  ^ vlSelf->__PVT__error__DOT__monitor__DOT__address[0U]) 
                                 | vlSelf->__PVT__error__DOT__monitor__DOT__address[1U]) 
                                | vlSelf->__PVT__error__DOT__monitor__DOT__address[2U]) 
                               | vlSelf->__PVT__error__DOT__monitor__DOT__address[3U]))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7511: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel address changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7511, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7513: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7513, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25) 
                     & ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7517: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7517, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7519: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7519, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25) 
                     & ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7523: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7523, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7525: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7525, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25) 
                     & ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7529: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7529, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7531: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7531, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25) 
                     & ((IData)(vlSelf->__PVT__error__DOT__muxState_1) 
                        != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__denied))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7535: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel denied changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7535, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7537: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7537, "");
    }
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33 
        = ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source))
            ? (0xffffU & ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight) 
                          >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source)))
            : 0U);
    if (VL_UNLIKELY((((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7542: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'A' channel re-used a source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7542, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7544: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7544, "");
    }
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34 
        = ((0xfU >= (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))
            ? (0xffffU & ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight) 
                          >> (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16)))
            : 0U);
    if (VL_UNLIKELY((((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34) 
                           | (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7549: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7549, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7551: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7551, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & (~ (((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode)))))
                                 : 0U)) | ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24) 
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
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7557: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7557, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7559: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7559, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                        != (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7563: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7563, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7565: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7565, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & (~ (((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                             >> 1U))))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (IData)(
                                                            (__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                             >> 1U)))))))
                                 : 0U)) | ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (IData)(
                                                               (__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                                >> 1U))))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (IData)(
                                                                     (__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                                      >> 1U)))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7571: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7571, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7573: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7573, "");
    }
    VL_SHIFTR_WWW(128,128,128, __Vtemp_hf303a3ad__0, vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes, __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26);
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0U] 
        = __Vtemp_hf303a3ad__0[0U];
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[1U] 
        = __Vtemp_hf303a3ad__0[1U];
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[2U] 
        = __Vtemp_hf303a3ad__0[2U];
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[3U] 
        = __Vtemp_hf303a3ad__0[3U];
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                        != (0x7fU & (__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0U] 
                                     >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7578: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7578, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7580: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7580, "");
    }
    if (VL_UNLIKELY((((((((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27) 
                          & (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1))) 
                         & (IData)(vlSelf->__PVT___bar_auto_out_0_a_valid)) 
                        & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
                           == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))) 
                       & (6U != (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((~ (IData)(vlSelf->__PVT___bar_auto_out_0_d_ready)) 
                           | (IData)(vlSelf->__PVT__error__DOT__nodeIn_a_ready)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7585: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: ready check\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7585, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7587: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7587, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight)) 
                                  | (0U == vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->__PVT__error__DOT__monitor__DOT__watchdog 
                                    < vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7593: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7593, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7595: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7595, "");
    }
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35 
        = ((0xfU >= (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))
            ? (0xffffU & ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight_1) 
                          >> (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16)))
            : 0U);
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                     & (~ (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7600: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7600, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7602: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7602, "");
    }
    VL_SHIFTR_WWW(128,128,128, __Vtemp_h70724169__0, vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1, __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26);
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1[0U] 
        = __Vtemp_h70724169__0[0U];
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1[1U] 
        = __Vtemp_h70724169__0[1U];
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1[2U] 
        = __Vtemp_h70724169__0[2U];
    __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1[3U] 
        = __Vtemp_h70724169__0[3U];
    if (VL_UNLIKELY(((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                     & ((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                        != (0x7fU & (__PVT__error__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1[0U] 
                                     >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7607: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7607, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7609: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7609, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight_1)) 
                                  | (0U == vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus)) 
                                 | (vlSelf->__PVT__error__DOT__monitor__DOT__watchdog_1 
                                    < vlSelf->__PVT__error__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7615: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:33:14)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7615, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:7617: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.error.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 7617, "");
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T 
        = ((0xbU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size))
            ? (0xfffU & ((IData)(0x1fU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)))
            : 0U);
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6 
        = (0x1fU & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                    & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T))));
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1 
        = (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size))) 
                 | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                    & (~ (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                          >> 1U)))));
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1 
        = (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size))) 
                 | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                    & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                       >> 1U))));
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask 
        = ((8U & (((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1) 
                   << 3U) | (0xfffffff8U & ((vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                             << 2U) 
                                            & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                               << 3U))))) 
           | ((((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1) 
                | (2U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address))) 
               << 2U) | ((((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1) 
                           | (1U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address))) 
                          << 1U) | ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1) 
                                    | (0U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address))))));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_7 
        = ((5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)) 
           & (3U == (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                     >> 0x1eU)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9 
        = (0xfU != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_mask));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (7U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11 
        = ((3U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                         >> 1U))) & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                     >> 0x1eU));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (4U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13 
        = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_mask) 
           != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (0U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (1U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16 
        = ((3U > (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)) 
           & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
              >> 0x1eU));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (2U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (3U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (6U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21 
        = (0U == (3U & ((IData)(vlSelf->auto_node_in_in_d_bits_size) 
                        >> 1U)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (4U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23 
        = (2U == (IData)(vlSelf->auto_node_in_in_d_bits_param));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (5U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25 
        = (1U & ((~ (IData)(vlSelf->auto_node_in_in_d_bits_denied)) 
                 | (IData)(vlSelf->auto_node_in_in_d_bits_corrupt)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (0U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (1U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (2U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31 
        = ((QData)((IData)(vlSelf->auto_node_in_in_d_bits_source)) 
           << 2U);
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32 
        = ((IData)(vlSelf->auto_node_in_in_d_valid) 
           & (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_1)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33 
        = ((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
           & (6U != (IData)(vlSelf->auto_node_in_in_d_bits_opcode)));
    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1))) 
           & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
              == (IData)(vlSelf->auto_node_in_in_d_bits_source)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34 
        = (((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33) 
            & (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp)) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35 
        = (((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33) 
            & (~ (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_36 
        = ((((IData)(vlSelf->auto_node_in_in_d_valid) 
             & (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_2))) 
            & (6U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid) 
            & (0U != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30 
        = (((IData)(vlSelf->auto_node_in_in_d_valid) 
            & (0U != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
        = VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_opcodes, __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31);
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_7))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6361: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6361, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6363: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6363, "");
    }
    if (VL_UNLIKELY(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6367: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6367, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6369: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6369, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (~ (IData)((0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6373: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6373, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6375: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6375, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6379: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6379, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6381: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6381, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6385: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6385, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6387: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6387, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_7))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6391: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6391, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6393: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6393, "");
    }
    if (VL_UNLIKELY(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6397: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6397, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6399: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6399, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (~ (IData)((0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6403: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6403, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6405: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6405, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6409: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6409, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6411: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6411, "");
    }
    if (VL_UNLIKELY(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6415: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6415, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6417: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6417, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_10) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_9)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6421: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6421, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6423: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6423, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6427: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries Get type which slave claims it can't support (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6427, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6429: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6429, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6433: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Get address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6433, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6435: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6435, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6439: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Get contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6439, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6441: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6441, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6445: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries PutFull type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6445, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6447: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6447, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6451: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6451, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6453: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6453, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6457: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6457, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6459: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6459, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6463: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries PutPartial type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6463, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6465: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6465, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6469: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6469, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6471: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6471, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_15) 
                     & (0U != ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_mask) 
                               & (~ (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6475: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6475, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6477: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6477, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6481: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6481, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6483: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6483, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6487: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6487, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6489: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6489, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_17) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6493: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6493, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6495: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6495, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_16))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6499: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6499, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6501: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6501, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6505: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Logical address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6505, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6507: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6507, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6511: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Logical contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6511, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6513: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6513, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_11))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6517: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel carries Hint type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6517, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6519: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6519, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (0U != (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6523: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Hint address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6523, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6525: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6525, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_13)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6529: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel Hint contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6529, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6531: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6531, "");
    }
    if (VL_UNLIKELY((((IData)(vlSelf->auto_node_in_in_d_valid) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (7U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6535: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel has invalid opcode (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6535, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6537: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6537, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6541: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6541, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6543: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6543, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (0U != (IData)(vlSelf->auto_node_in_in_d_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6547: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseeAck carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6547, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6549: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6549, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (IData)(vlSelf->auto_node_in_in_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6553: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6553, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6555: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6555, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (IData)(vlSelf->auto_node_in_in_d_bits_denied)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6559: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel ReleaseAck is denied (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6559, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6561: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6561, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6565: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel Grant smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6565, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6567: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6567, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (3U == (IData)(vlSelf->auto_node_in_in_d_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6571: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel Grant carries invalid cap param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6571, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6573: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6573, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6577: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel Grant carries toN param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6577, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6579: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6579, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(vlSelf->auto_node_in_in_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6583: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel Grant is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6583, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6585: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6585, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_21)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6589: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6589, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6591: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6591, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & (3U == (IData)(vlSelf->auto_node_in_in_d_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6595: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData carries invalid cap param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6595, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6597: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6597, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_23)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6601: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData carries toN param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6601, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6603: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6603, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_24) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6607: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6607, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6609: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6609, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26) 
                     & (0U != (IData)(vlSelf->auto_node_in_in_d_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6613: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6613, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6615: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6615, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_26) 
                     & (IData)(vlSelf->auto_node_in_in_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6619: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6619, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6621: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6621, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27) 
                     & (0U != (IData)(vlSelf->auto_node_in_in_d_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6625: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6625, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6627: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6627, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_27) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_25))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6631: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6631, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6633: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6633, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
                     & (0U != (IData)(vlSelf->auto_node_in_in_d_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6637: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel HintAck carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6637, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6639: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6639, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
                     & (IData)(vlSelf->auto_node_in_in_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6643: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel HintAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6643, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6645: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6645, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6649: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6649, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6651: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6651, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6655: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6655, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6657: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6657, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__source))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6661: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6661, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6663: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6663, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                        != vlSelf->__PVT__bar__DOT__monitor__DOT__address)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6667: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel address changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6667, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6669: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6669, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6673: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6673, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6675: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6675, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_param) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__param_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6679: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel param changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6679, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6681: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6681, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_size) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6685: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6685, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6687: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6687, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_source) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6691: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6691, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6693: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6693, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_sink) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__sink))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6697: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel sink changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6697, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6699: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6699, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_30) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_denied) 
                        != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__denied))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6703: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel denied changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6703, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6705: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6705, "");
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_37 
        = ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source))
            ? (0xffffU & ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight) 
                          >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source)))
            : 0U);
    if (VL_UNLIKELY((((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___GEN_0) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_37)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6710: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'A' channel re-used a source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6710, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6712: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6712, "");
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_38 
        = ((0xfU >= (IData)(vlSelf->auto_node_in_in_d_bits_source))
            ? (0xffffU & ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight) 
                          >> (IData)(vlSelf->auto_node_in_in_d_bits_source)))
            : 0U);
    if (VL_UNLIKELY((((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_33) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_38) 
                           | (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6717: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6717, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6719: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6719, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34) 
                     & (~ (((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode)))))
                                 : 0U)) | ((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
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
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6725: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6725, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6727: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6727, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_34) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                        != (IData)(vlSelf->auto_node_in_in_d_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6731: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6731, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6733: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6733, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35) 
                     & (~ (((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                             >> 1U))))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (IData)(
                                                            (__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                             >> 1U)))))))
                                 : 0U)) | ((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (IData)(
                                                               (__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                                >> 1U))))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (IData)(
                                                                     (__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1 
                                                                      >> 1U)))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6739: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6739, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6741: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6741, "");
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1 
        = VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes, __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31);
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_35) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_size) 
                        != (7U & (IData)((__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1 
                                          >> 1U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6746: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6746, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6748: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6748, "");
    }
    if (VL_UNLIKELY((((((((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                          & (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1))) 
                         & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid)) 
                        & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
                           == (IData)(vlSelf->auto_node_in_in_d_bits_source))) 
                       & (6U != (IData)(vlSelf->auto_node_in_in_d_bits_opcode))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_d_ready)) 
                           | (IData)(vlSelf->auto_node_in_in_a_ready)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6753: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: ready check\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6753, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6755: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6755, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight)) 
                                  | (0U == vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog 
                                    < vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6761: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6761, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6763: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6763, "");
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_39 
        = ((0xfU >= (IData)(vlSelf->auto_node_in_in_d_bits_source))
            ? (0xffffU & ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_1) 
                          >> (IData)(vlSelf->auto_node_in_in_d_bits_source)))
            : 0U);
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_36) 
                     & (~ (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_39))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6768: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6768, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6770: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6770, "");
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1 
        = VL_SHIFTR_QQQ(64,64,64, vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes_1, __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_31);
    if (VL_UNLIKELY(((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___GEN_36) 
                     & ((IData)(vlSelf->auto_node_in_in_d_bits_size) 
                        != (7U & (IData)((__PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT___c_size_lookup_T_1 
                                          >> 1U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6775: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6775, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6777: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6777, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_1)) 
                                  | (0U == vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus)) 
                                 | (vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog_1 
                                    < vlSelf->__PVT__bar__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6783: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/devices/tilelink/BusBypass.scala:32:12)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6783, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:6785: Assertion failed in %NysyxSoCFull.fpga.chiplink.sbypass.bar.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 6785, "");
    }
    __PVT__bar__DOT__unnamedblk1__DOT___rbeats1_decode_T_9 
        = (0xfffU & ((IData)(0x1fU) << (IData)(vlSelf->auto_node_in_in_d_bits_size)));
    __PVT__bar__DOT__unnamedblk1__DOT___stall_T_1 = 
        ((IData)(vlSelf->auto_node_in_in_a_ready) & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid));
    vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__a_first 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__r_counter));
    __PVT__bar__DOT__unnamedblk1__DOT___d_dec_T = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_d_ready) 
                                                   & (IData)(vlSelf->auto_node_in_in_d_valid));
    vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__r_beats1_3 
        = ((1U & (IData)(vlSelf->auto_node_in_in_d_bits_opcode))
            ? (7U & (~ ((IData)(__PVT__bar__DOT__unnamedblk1__DOT___rbeats1_decode_T_9) 
                        >> 2U))) : 0U);
    vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__d_first 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__r_counter_3));
    __PVT__bar__DOT__unnamedblk1__DOT___next_flight_T_10 
        = (0x3fU & (((IData)(vlSelf->__PVT__bar__DOT__flight) 
                     + (3U & (((((IData)(__PVT__bar__DOT__unnamedblk1__DOT___d_dec_T) 
                                 & (IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__d_first)) 
                                & ((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
                                   >> 2U)) & (~ ((IData)(vlSelf->auto_node_in_in_d_bits_opcode) 
                                                 >> 1U))) 
                              + ((IData)(__PVT__bar__DOT__unnamedblk1__DOT___stall_T_1) 
                                 & (IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__a_first))))) 
                    - ((IData)(__PVT__bar__DOT__unnamedblk1__DOT___d_dec_T) 
                       & ((1U == (IData)(vlSelf->__PVT__bar__DOT__r_counter_3)) 
                          | (0U == (IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__r_beats1_3))))));
    if (((IData)(vlSelf->__PVT__bar__DOT__in_reset) 
         | (0U == (IData)(__PVT__bar__DOT__unnamedblk1__DOT___next_flight_T_10)))) {
        vlSelf->__PVT__bar__DOT__bypass_reg = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__do_bypass;
    }
    if (vlSymsp->TOP.reset) {
        __Vdly__error__DOT__idle = 1U;
        __Vdly__error__DOT__r_counter = 0U;
        vlSelf->__PVT__error__DOT__r_counter = __Vdly__error__DOT__r_counter;
        vlSelf->__PVT__error__DOT__idle = __Vdly__error__DOT__idle;
        __Vdly__error__DOT__a_last_counter = 0U;
        vlSelf->__PVT__error__DOT__a_last_counter = __Vdly__error__DOT__a_last_counter;
        __Vdly__error__DOT__beatsLeft = 0U;
        vlSelf->__PVT__error__DOT__state_1 = 0U;
        vlSelf->__PVT__error__DOT__beatsLeft = __Vdly__error__DOT__beatsLeft;
        vlSelf->__PVT__bar__DOT__flight = 0U;
        __Vdly__bar__DOT__r_counter = 0U;
        __Vdly__bar__DOT__r_counter_3 = 0U;
        __Vdly__bar__DOT__stall_counter = 0U;
    } else {
        vlSelf->__PVT__error__DOT__unnamedblk1__DOT___GEN_1 
            = ((IData)(vlSelf->__PVT__error__DOT__da_ready) 
               & (IData)(vlSelf->__PVT__error__DOT__winner_1));
        __Vdly__error__DOT__idle = ((~ ((IData)(vlSelf->__PVT__error__DOT__unnamedblk1__DOT___GEN_1) 
                                        & (4U == (IData)(vlSelf->__PVT__error__DOT__da_bits_opcode)))) 
                                    & (IData)(vlSelf->__PVT__error__DOT__idle));
        if (vlSelf->__PVT__error__DOT__unnamedblk1__DOT___GEN_1) {
            __Vdly__error__DOT__r_counter = (0x3ffU 
                                             & ((IData)(vlSelf->__PVT__error__DOT__da_first)
                                                 ? (IData)(vlSelf->__PVT__error__DOT__r_beats1)
                                                 : 
                                                ((IData)(vlSelf->__PVT__error__DOT__r_counter) 
                                                 - (IData)(1U))));
        }
        vlSelf->__PVT__error__DOT__r_counter = __Vdly__error__DOT__r_counter;
        vlSelf->__PVT__error__DOT__idle = __Vdly__error__DOT__idle;
        if (((IData)(vlSelf->__PVT__error__DOT__nodeIn_a_ready) 
             & (IData)(vlSelf->__PVT___bar_auto_out_0_a_valid))) {
            __Vdly__error__DOT__a_last_counter = (0x3ffU 
                                                  & ((0U 
                                                      == (IData)(vlSelf->__PVT__error__DOT__a_last_counter))
                                                      ? (IData)(vlSelf->__PVT__error__DOT__a_last_beats1)
                                                      : 
                                                     ((IData)(vlSelf->__PVT__error__DOT__a_last_counter) 
                                                      - (IData)(1U))));
        }
        vlSelf->__PVT__error__DOT__a_last_counter = __Vdly__error__DOT__a_last_counter;
        __Vdly__error__DOT__beatsLeft = (0x3ffU & (
                                                   ((IData)(vlSelf->__PVT__error__DOT__idle_1) 
                                                    & (IData)(vlSelf->__PVT___bar_auto_out_0_d_ready))
                                                    ? 
                                                   (((IData)(vlSelf->__PVT__error__DOT__winner_1) 
                                                     & (IData)(vlSelf->__PVT__error__DOT__da_bits_opcode))
                                                     ? 
                                                    (~ 
                                                     (0x1ffffffU 
                                                      & (((IData)(0xfffU) 
                                                          << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)) 
                                                         >> 2U)))
                                                     : 0U)
                                                    : 
                                                   ((IData)(vlSelf->__PVT__error__DOT__beatsLeft) 
                                                    - 
                                                    ((IData)(vlSelf->__PVT___bar_auto_out_0_d_ready) 
                                                     & (IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid)))));
        if ((0U == (IData)(vlSelf->__PVT__error__DOT__beatsLeft))) {
            vlSelf->__PVT__error__DOT__state_1 = vlSelf->__PVT__error__DOT__winner_1;
        }
        vlSelf->__PVT__error__DOT__beatsLeft = __Vdly__error__DOT__beatsLeft;
        if (__PVT__bar__DOT__unnamedblk1__DOT___stall_T_1) {
            vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__unnamedblk2__DOT___stall_beats1_decode_T 
                = (0xfffU & ((IData)(0x1fU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)));
            __Vdly__bar__DOT__r_counter = (7U & ((IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__a_first)
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))
                                                   ? 0U
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__unnamedblk2__DOT___stall_beats1_decode_T) 
                                                    >> 2U)))
                                                  : 
                                                 ((IData)(vlSelf->__PVT__bar__DOT__r_counter) 
                                                  - (IData)(1U))));
            __Vdly__bar__DOT__stall_counter = (7U & 
                                               ((IData)(vlSelf->__PVT__bar__DOT__stall_first)
                                                 ? 
                                                ((4U 
                                                  & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))
                                                  ? 0U
                                                  : 
                                                 (~ 
                                                  ((IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__unnamedblk2__DOT___stall_beats1_decode_T) 
                                                   >> 2U)))
                                                 : 
                                                ((IData)(vlSelf->__PVT__bar__DOT__stall_counter) 
                                                 - (IData)(1U))));
        }
        if (__PVT__bar__DOT__unnamedblk1__DOT___d_dec_T) {
            __Vdly__bar__DOT__r_counter_3 = (7U & ((IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__d_first)
                                                    ? (IData)(vlSelf->__PVT__bar__DOT__unnamedblk1__DOT__r_beats1_3)
                                                    : 
                                                   ((IData)(vlSelf->__PVT__bar__DOT__r_counter_3) 
                                                    - (IData)(1U))));
        }
        vlSelf->__PVT__bar__DOT__flight = __PVT__bar__DOT__unnamedblk1__DOT___next_flight_T_10;
    }
    vlSelf->__PVT__bar__DOT__r_counter = __Vdly__bar__DOT__r_counter;
    vlSelf->__PVT__bar__DOT__r_counter_3 = __Vdly__bar__DOT__r_counter_3;
    vlSelf->__PVT__bar__DOT__stall_counter = __Vdly__bar__DOT__stall_counter;
    __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2 
        = ((IData)(vlSelf->__PVT___bar_auto_out_0_d_ready) 
           & (IData)(vlSelf->__PVT__error__DOT__nodeIn_d_valid));
    if (((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter)))))) {
        vlSelf->__PVT__error__DOT__monitor__DOT__opcode_1 
            = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24;
        vlSelf->__PVT__error__DOT__monitor__DOT__size_1 
            = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19;
        vlSelf->__PVT__error__DOT__monitor__DOT__source_1 
            = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16;
        vlSelf->__PVT__error__DOT__monitor__DOT__denied 
            = vlSelf->__PVT__error__DOT__muxState_1;
    }
    if (((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___a_first_T_1) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter)))))) {
        vlSelf->__PVT__error__DOT__monitor__DOT__opcode 
            = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode;
        vlSelf->__PVT__error__DOT__monitor__DOT__size 
            = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size;
        vlSelf->__PVT__error__DOT__monitor__DOT__source 
            = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source;
        vlSelf->__PVT__error__DOT__monitor__DOT__address[0U] 
            = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address;
        vlSelf->__PVT__error__DOT__monitor__DOT__address[1U] = 0U;
        vlSelf->__PVT__error__DOT__monitor__DOT__address[2U] = 0U;
        vlSelf->__PVT__error__DOT__monitor__DOT__address[3U] = 0U;
    }
    __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2 
        = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_d_ready) 
           & (IData)(vlSelf->auto_node_in_in_d_valid));
    if (vlSymsp->TOP.reset) {
        __Vdly__error__DOT__monitor__DOT__d_first_counter = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_opcodes = 0ULL;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[0U] = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[1U] = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[2U] = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[3U] = 0U;
        __Vdly__error__DOT__monitor__DOT__d_first_counter_1 = 0U;
        __Vdly__error__DOT__monitor__DOT__watchdog = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_1 = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[0U] = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[1U] = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[2U] = 0U;
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[3U] = 0U;
        __Vdly__error__DOT__monitor__DOT__d_first_counter_2 = 0U;
        __Vdly__error__DOT__monitor__DOT__watchdog_1 = 0U;
        __Vdly__error__DOT__monitor__DOT__a_first_counter = 0U;
        __Vdly__error__DOT__monitor__DOT__a_first_counter_1 = 0U;
        __Vdly__bar__DOT__monitor__DOT__d_first_counter = 0U;
        __Vdly__bar__DOT__monitor__DOT__inflight = 0U;
        __Vdly__bar__DOT__monitor__DOT__inflight_opcodes = 0ULL;
        __Vdly__bar__DOT__monitor__DOT__inflight_sizes = 0ULL;
        __Vdly__bar__DOT__monitor__DOT__d_first_counter_1 = 0U;
        __Vdly__bar__DOT__monitor__DOT__watchdog = 0U;
        __Vdly__bar__DOT__monitor__DOT__inflight_1 = 0U;
        __Vdly__bar__DOT__monitor__DOT__inflight_sizes_1 = 0ULL;
        __Vdly__bar__DOT__monitor__DOT__d_first_counter_2 = 0U;
        __Vdly__bar__DOT__monitor__DOT__watchdog_1 = 0U;
        __Vdly__bar__DOT__monitor__DOT__a_first_counter = 0U;
        __Vdly__bar__DOT__monitor__DOT__a_first_counter_1 = 0U;
    } else {
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37[0U] 
            = ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
               << 3U);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37[1U] 
            = ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
               >> 0x1dU);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37[2U] = 0U;
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37[3U] = 0U;
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37[4U] = 0U;
        __Vtemp_h6f0d4cc8__0[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__0[1U] = 0U;
        __Vtemp_h6f0d4cc8__0[2U] = 0U;
        __Vtemp_h6f0d4cc8__0[3U] = 0U;
        __Vtemp_h6f0d4cc8__0[4U] = 0U;
        __Vtemp_h814bf4f2__0[0U] = ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
                                    << 2U);
        __Vtemp_h814bf4f2__0[1U] = ((IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16) 
                                    >> 0x1eU);
        __Vtemp_h814bf4f2__0[2U] = 0U;
        __Vtemp_h814bf4f2__0[3U] = 0U;
        __Vtemp_h814bf4f2__0[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_h1ec71af6__0, __Vtemp_h6f0d4cc8__0, __Vtemp_h814bf4f2__0);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U] 
            = __Vtemp_h1ec71af6__0[0U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U] 
            = __Vtemp_h1ec71af6__0[1U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[2U] 
            = __Vtemp_h1ec71af6__0[2U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[3U] 
            = __Vtemp_h1ec71af6__0[3U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[4U] 
            = (0x7fffU & __Vtemp_h1ec71af6__0[4U]);
        if (vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0) {
            __Vtemp_he0cf7f05__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode) 
                                              << 1U));
            __Vtemp_hece19c8e__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                                              << 1U));
        } else {
            __Vtemp_he0cf7f05__0[0U] = 0U;
            __Vtemp_hece19c8e__0[0U] = 0U;
        }
        __Vtemp_he0cf7f05__0[1U] = 0U;
        __Vtemp_he0cf7f05__0[2U] = 0U;
        __Vtemp_he0cf7f05__0[3U] = 0U;
        __Vtemp_he0cf7f05__0[4U] = 0U;
        __Vtemp_hd643db39__0[0U] = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
                                    << 2U);
        __Vtemp_hd643db39__0[1U] = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
                                    >> 0x1eU);
        __Vtemp_hd643db39__0[2U] = 0U;
        __Vtemp_hd643db39__0[3U] = 0U;
        __Vtemp_hd643db39__0[4U] = 0U;
        VL_SHIFTL_WWW(131,131,131, __Vtemp_h0dcb169b__0, __Vtemp_he0cf7f05__0, __Vtemp_hd643db39__0);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U] 
            = __Vtemp_h0dcb169b__0[0U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U] 
            = __Vtemp_h0dcb169b__0[1U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[2U] 
            = __Vtemp_h0dcb169b__0[2U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[3U] 
            = __Vtemp_h0dcb169b__0[3U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[4U] 
            = (7U & __Vtemp_h0dcb169b__0[4U]);
        __Vtemp_hab69a0d4__0[0U] = 0xffU;
        __Vtemp_hab69a0d4__0[1U] = 0U;
        __Vtemp_hab69a0d4__0[2U] = 0U;
        __Vtemp_hab69a0d4__0[3U] = 0U;
        __Vtemp_hab69a0d4__0[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_hedb9a1f6__0, __Vtemp_hab69a0d4__0, vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U] 
            = __Vtemp_hedb9a1f6__0[0U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U] 
            = __Vtemp_hedb9a1f6__0[1U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[2U] 
            = __Vtemp_hedb9a1f6__0[2U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[3U] 
            = __Vtemp_hedb9a1f6__0[3U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[4U] 
            = (0x7fffU & __Vtemp_hedb9a1f6__0[4U]);
        __Vtemp_hece19c8e__0[1U] = 0U;
        __Vtemp_hece19c8e__0[2U] = 0U;
        __Vtemp_hece19c8e__0[3U] = 0U;
        __Vtemp_hece19c8e__0[4U] = 0U;
        __Vtemp_hbb4ee8f4__0[0U] = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
                                    << 3U);
        __Vtemp_hbb4ee8f4__0[1U] = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
                                    >> 0x1dU);
        __Vtemp_hbb4ee8f4__0[2U] = 0U;
        __Vtemp_hbb4ee8f4__0[3U] = 0U;
        __Vtemp_hbb4ee8f4__0[4U] = 0U;
        VL_SHIFTL_WWW(132,132,132, __Vtemp_h3700eba1__0, __Vtemp_hece19c8e__0, __Vtemp_hbb4ee8f4__0);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U] 
            = __Vtemp_h3700eba1__0[0U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U] 
            = __Vtemp_h3700eba1__0[1U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[2U] 
            = __Vtemp_h3700eba1__0[2U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[3U] 
            = __Vtemp_h3700eba1__0[3U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[4U] 
            = (0xfU & __Vtemp_h3700eba1__0[4U]);
        __Vtemp_hab69a0d4__1[0U] = 0xffU;
        __Vtemp_hab69a0d4__1[1U] = 0U;
        __Vtemp_hab69a0d4__1[2U] = 0U;
        __Vtemp_hab69a0d4__1[3U] = 0U;
        __Vtemp_hab69a0d4__1[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_h131918fc__0, __Vtemp_hab69a0d4__1, vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[0U] 
            = __Vtemp_h131918fc__0[0U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[1U] 
            = __Vtemp_h131918fc__0[1U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[2U] 
            = __Vtemp_h131918fc__0[2U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[3U] 
            = __Vtemp_h131918fc__0[3U];
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[4U] 
            = (0x7fffU & __Vtemp_h131918fc__0[4U]);
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36 
            = (((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
                & (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_1)) 
               & (6U != (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24)));
        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38 
            = (((IData)(__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
                & (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_2)) 
               & (6U == (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24)));
        if (__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) {
            vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                = (0x7ffffffU & ((IData)(0xfffU) << (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19)));
            __Vdly__error__DOT__monitor__DOT__d_first_counter 
                = (0x3ffU & ((0U != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter))
                              ? ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter) 
                                 - (IData)(1U)) : (
                                                   (1U 
                                                    & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))
                                                    ? 
                                                   (~ 
                                                    (vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                                                     >> 2U))
                                                    : 0U)));
            __Vdly__error__DOT__monitor__DOT__d_first_counter_1 
                = (0x3ffU & ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_1)
                              ? ((1U & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))
                                  ? (~ (vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                                        >> 2U)) : 0U)
                              : ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_1) 
                                 - (IData)(1U))));
            __Vdly__error__DOT__monitor__DOT__d_first_counter_2 
                = (0x3ffU & ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_2)
                              ? ((1U & (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24))
                                  ? (~ (vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                                        >> 2U)) : 0U)
                              : ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_2) 
                                 - (IData)(1U))));
            __Vdly__error__DOT__monitor__DOT__watchdog_1 = 0U;
        } else {
            __Vdly__error__DOT__monitor__DOT__watchdog_1 
                = ((IData)(1U) + vlSelf->__PVT__error__DOT__monitor__DOT__watchdog_1);
        }
        __Vdly__error__DOT__monitor__DOT__inflight 
            = (0xffffU & (((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight) 
                           | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0)
                               ? ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source))
                                   ? ((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source))
                                   : 0U) : 0U)) & (~ 
                                                   ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36)
                                                     ? 
                                                    ((0xfU 
                                                      >= (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))
                                                      ? 
                                                     ((IData)(1U) 
                                                      << (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))
                                                      : 0U)
                                                     : 0U))));
        __Vdly__error__DOT__monitor__DOT__inflight_opcodes 
            = ((vlSelf->__PVT__error__DOT__monitor__DOT__inflight_opcodes 
                | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0)
                    ? (((QData)((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U])))
                    : 0ULL)) & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36)
                                    ? (((QData)((IData)(
                                                        vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U])))
                                    : 0ULL)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[0U] 
            = ((vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[0U] 
                | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0)
                    ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U]
                    : 0U)) & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36)
                                  ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U]
                                  : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[1U] 
            = ((vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[1U] 
                | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0)
                    ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U]
                    : 0U)) & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36)
                                  ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U]
                                  : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[2U] 
            = ((vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[2U] 
                | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0)
                    ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[2U]
                    : 0U)) & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36)
                                  ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[2U]
                                  : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes[3U] 
            = ((vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[3U] 
                | ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0)
                    ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[3U]
                    : 0U)) & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36)
                                  ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[3U]
                                  : 0U)));
        __Vdly__error__DOT__monitor__DOT__watchdog 
            = (((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___a_first_T_1) 
                | (IData)(__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2))
                ? 0U : ((IData)(1U) + vlSelf->__PVT__error__DOT__monitor__DOT__watchdog));
        __Vdly__error__DOT__monitor__DOT__inflight_1 
            = ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__inflight_1) 
               & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38)
                      ? ((0xfU >= (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))
                          ? ((IData)(1U) << (IData)(vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16))
                          : 0U) : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[0U] 
            = (vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[0U] 
               & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38)
                      ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[0U]
                      : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[1U] 
            = (vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[1U] 
               & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38)
                      ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[1U]
                      : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[2U] 
            = (vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[2U] 
               & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38)
                      ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[2U]
                      : 0U)));
        __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[3U] 
            = (vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[3U] 
               & (~ ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38)
                      ? vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[3U]
                      : 0U)));
        if (vlSelf->__PVT__error__DOT__monitor__DOT___a_first_T_1) {
            vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 
                = ((0x1aU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size))
                    ? (0x7ffffffU & ((IData)(0xfffU) 
                                     << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)))
                    : 0U);
            __Vdly__error__DOT__monitor__DOT__a_first_counter 
                = (0x3ffU & ((0U != (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter))
                              ? ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter) 
                                 - (IData)(1U)) : (
                                                   (4U 
                                                    & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))
                                                    ? 0U
                                                    : 
                                                   (~ 
                                                    (vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 
                                                     >> 2U)))));
            __Vdly__error__DOT__monitor__DOT__a_first_counter_1 
                = (0x3ffU & ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_1)
                              ? ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))
                                  ? 0U : (~ (vlSelf->__PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 
                                             >> 2U)))
                              : ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1) 
                                 - (IData)(1U))));
        }
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[0U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
               << 2U);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[1U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
               >> 0x1eU);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[2U] = 0U;
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[3U] = 0U;
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40[4U] = 0U;
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0U] 
            = ((IData)(vlSelf->auto_node_in_in_d_bits_source) 
               << 2U);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[1U] 
            = ((IData)(vlSelf->auto_node_in_in_d_bits_source) 
               >> 0x1eU);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[2U] = 0U;
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[3U] = 0U;
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[4U] = 0U;
        __Vtemp_h6f0d4cc8__1[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__1[1U] = 0U;
        __Vtemp_h6f0d4cc8__1[2U] = 0U;
        __Vtemp_h6f0d4cc8__1[3U] = 0U;
        __Vtemp_h6f0d4cc8__1[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_hee7b10c9__0, __Vtemp_h6f0d4cc8__1, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U] 
            = __Vtemp_hee7b10c9__0[0U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U] 
            = __Vtemp_hee7b10c9__0[1U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[2U] 
            = __Vtemp_hee7b10c9__0[2U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[3U] 
            = __Vtemp_hee7b10c9__0[3U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[4U] 
            = (0x7fffU & __Vtemp_hee7b10c9__0[4U]);
        if (vlSelf->__PVT__bar__DOT__monitor__DOT___GEN_0) {
            __Vtemp_h04a11209__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode) 
                                              << 1U));
            __Vtemp_h2c36fb9a__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size) 
                                              << 1U));
        } else {
            __Vtemp_h04a11209__0[0U] = 0U;
            __Vtemp_h2c36fb9a__0[0U] = 0U;
        }
        __Vtemp_h04a11209__0[1U] = 0U;
        __Vtemp_h04a11209__0[2U] = 0U;
        __Vtemp_h04a11209__0[3U] = 0U;
        __Vtemp_h04a11209__0[4U] = 0U;
        VL_SHIFTL_WWW(131,131,131, __Vtemp_h87029e3d__0, __Vtemp_h04a11209__0, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U] 
            = __Vtemp_h87029e3d__0[0U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U] 
            = __Vtemp_h87029e3d__0[1U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[2U] 
            = __Vtemp_h87029e3d__0[2U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[3U] 
            = __Vtemp_h87029e3d__0[3U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[4U] 
            = (7U & __Vtemp_h87029e3d__0[4U]);
        __Vtemp_h6f0d4cc8__2[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__2[1U] = 0U;
        __Vtemp_h6f0d4cc8__2[2U] = 0U;
        __Vtemp_h6f0d4cc8__2[3U] = 0U;
        __Vtemp_h6f0d4cc8__2[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_hcb4b53f9__0, __Vtemp_h6f0d4cc8__2, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U] 
            = __Vtemp_hcb4b53f9__0[0U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U] 
            = __Vtemp_hcb4b53f9__0[1U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[2U] 
            = __Vtemp_hcb4b53f9__0[2U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[3U] 
            = __Vtemp_hcb4b53f9__0[3U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[4U] 
            = (0x7fffU & __Vtemp_hcb4b53f9__0[4U]);
        __Vtemp_h2c36fb9a__0[1U] = 0U;
        __Vtemp_h2c36fb9a__0[2U] = 0U;
        __Vtemp_h2c36fb9a__0[3U] = 0U;
        __Vtemp_h2c36fb9a__0[4U] = 0U;
        VL_SHIFTL_WWW(131,131,131, __Vtemp_hb1f1a0ad__0, __Vtemp_h2c36fb9a__0, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U] 
            = __Vtemp_hb1f1a0ad__0[0U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U] 
            = __Vtemp_hb1f1a0ad__0[1U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[2U] 
            = __Vtemp_hb1f1a0ad__0[2U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[3U] 
            = __Vtemp_hb1f1a0ad__0[3U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[4U] 
            = (7U & __Vtemp_hb1f1a0ad__0[4U]);
        __Vtemp_h6f0d4cc8__3[0U] = 0xfU;
        __Vtemp_h6f0d4cc8__3[1U] = 0U;
        __Vtemp_h6f0d4cc8__3[2U] = 0U;
        __Vtemp_h6f0d4cc8__3[3U] = 0U;
        __Vtemp_h6f0d4cc8__3[4U] = 0U;
        VL_SHIFTL_WWW(143,143,143, __Vtemp_h5911eb2f__0, __Vtemp_h6f0d4cc8__3, vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[0U] 
            = __Vtemp_h5911eb2f__0[0U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[1U] 
            = __Vtemp_h5911eb2f__0[1U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[2U] 
            = __Vtemp_h5911eb2f__0[2U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[3U] 
            = __Vtemp_h5911eb2f__0[3U];
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[4U] 
            = (0x7fffU & __Vtemp_h5911eb2f__0[4U]);
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41 
            = (((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
                & (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_1)) 
               & (6U != (IData)(vlSelf->auto_node_in_in_d_bits_opcode)));
        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43 
            = (((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
                & (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_2)) 
               & (6U == (IData)(vlSelf->auto_node_in_in_d_bits_opcode)));
        if (__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) {
            vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                = (0xfffU & ((IData)(0x1fU) << (IData)(vlSelf->auto_node_in_in_d_bits_size)));
            __Vdly__bar__DOT__monitor__DOT__d_first_counter 
                = (7U & ((0U != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter))
                          ? ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter) 
                             - (IData)(1U)) : ((1U 
                                                & (IData)(vlSelf->auto_node_in_in_d_bits_opcode))
                                                ? (~ 
                                                   ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                                    >> 2U))
                                                : 0U)));
            __Vdly__bar__DOT__monitor__DOT__d_first_counter_1 
                = (7U & ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_1)
                          ? ((1U & (IData)(vlSelf->auto_node_in_in_d_bits_opcode))
                              ? (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                    >> 2U)) : 0U) : 
                         ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_1) 
                          - (IData)(1U))));
            __Vdly__bar__DOT__monitor__DOT__d_first_counter_2 
                = (7U & ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_2)
                          ? ((1U & (IData)(vlSelf->auto_node_in_in_d_bits_opcode))
                              ? (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                    >> 2U)) : 0U) : 
                         ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_2) 
                          - (IData)(1U))));
            __Vdly__bar__DOT__monitor__DOT__watchdog_1 = 0U;
        } else {
            __Vdly__bar__DOT__monitor__DOT__watchdog_1 
                = ((IData)(1U) + vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog_1);
        }
        __Vdly__bar__DOT__monitor__DOT__inflight = 
            (0xffffU & (((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight) 
                         | ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___GEN_0)
                             ? ((0xfU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source))
                                 ? ((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source))
                                 : 0U) : 0U)) & (~ 
                                                 ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41)
                                                   ? 
                                                  ((0xfU 
                                                    >= (IData)(vlSelf->auto_node_in_in_d_bits_source))
                                                    ? 
                                                   ((IData)(1U) 
                                                    << (IData)(vlSelf->auto_node_in_in_d_bits_source))
                                                    : 0U)
                                                   : 0U))));
        __Vdly__bar__DOT__monitor__DOT__inflight_opcodes 
            = ((vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_opcodes 
                | ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___GEN_0)
                    ? (((QData)((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U])))
                    : 0ULL)) & (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41)
                                    ? (((QData)((IData)(
                                                        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U])))
                                    : 0ULL)));
        __Vdly__bar__DOT__monitor__DOT__inflight_sizes 
            = ((vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes 
                | ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___GEN_0)
                    ? (((QData)((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U])))
                    : 0ULL)) & (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41)
                                    ? (((QData)((IData)(
                                                        vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U])))
                                    : 0ULL)));
        __Vdly__bar__DOT__monitor__DOT__watchdog = 
            (((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___a_first_T_1) 
              | (IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2))
              ? 0U : ((IData)(1U) + vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog));
        __Vdly__bar__DOT__monitor__DOT__inflight_1 
            = ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_1) 
               & (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? ((0xfU >= (IData)(vlSelf->auto_node_in_in_d_bits_source))
                          ? ((IData)(1U) << (IData)(vlSelf->auto_node_in_in_d_bits_source))
                          : 0U) : 0U)));
        __Vdly__bar__DOT__monitor__DOT__inflight_sizes_1 
            = (vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes_1 
               & (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? (((QData)((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[1U])) 
                          << 0x20U) | (QData)((IData)(
                                                      vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11[0U])))
                      : 0ULL)));
        if (vlSelf->__PVT__bar__DOT__monitor__DOT___a_first_T_1) {
            vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 
                = ((0xbU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size))
                    ? (0xfffU & ((IData)(0x1fU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)))
                    : 0U);
            __Vdly__bar__DOT__monitor__DOT__a_first_counter 
                = (7U & ((0U != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter))
                          ? ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter) 
                             - (IData)(1U)) : ((4U 
                                                & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))
                                                ? 0U
                                                : (~ 
                                                   ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3) 
                                                    >> 2U)))));
            __Vdly__bar__DOT__monitor__DOT__a_first_counter_1 
                = (7U & ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_1)
                          ? ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))
                              ? 0U : (~ ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3) 
                                         >> 2U))) : 
                         ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1) 
                          - (IData)(1U))));
        }
    }
    if (((IData)(__PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter)))))) {
        vlSelf->__PVT__bar__DOT__monitor__DOT__opcode_1 
            = vlSelf->auto_node_in_in_d_bits_opcode;
        vlSelf->__PVT__bar__DOT__monitor__DOT__param_1 
            = vlSelf->auto_node_in_in_d_bits_param;
        vlSelf->__PVT__bar__DOT__monitor__DOT__size_1 
            = vlSelf->auto_node_in_in_d_bits_size;
        vlSelf->__PVT__bar__DOT__monitor__DOT__source_1 
            = vlSelf->auto_node_in_in_d_bits_source;
        vlSelf->__PVT__bar__DOT__monitor__DOT__sink 
            = vlSelf->auto_node_in_in_d_bits_sink;
        vlSelf->__PVT__bar__DOT__monitor__DOT__denied 
            = vlSelf->auto_node_in_in_d_bits_denied;
    }
    if (((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___a_first_T_1) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter)))))) {
        vlSelf->__PVT__bar__DOT__monitor__DOT__opcode 
            = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode;
        vlSelf->__PVT__bar__DOT__monitor__DOT__size 
            = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size;
        vlSelf->__PVT__bar__DOT__monitor__DOT__source 
            = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source;
        vlSelf->__PVT__bar__DOT__monitor__DOT__address 
            = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address;
    }
    vlSelf->__PVT__error__DOT__da_first = (0U == (IData)(vlSelf->__PVT__error__DOT__r_counter));
    vlSelf->__PVT__error__DOT__idle_1 = (0U == (IData)(vlSelf->__PVT__error__DOT__beatsLeft));
    vlSelf->error__DOT____VdfgTmp_hc0029b36__0 = ((0U 
                                                   == (IData)(vlSelf->__PVT__error__DOT__beatsLeft)) 
                                                  | (IData)(vlSelf->__PVT__error__DOT__state_1));
    vlSelf->__PVT__bar__DOT__stall_first = (0U == (IData)(vlSelf->__PVT__bar__DOT__stall_counter));
    vlSelf->__PVT__bar__DOT__in_reset = vlSymsp->TOP.reset;
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter 
        = __Vdly__error__DOT__monitor__DOT__d_first_counter;
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight 
        = __Vdly__error__DOT__monitor__DOT__inflight;
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_opcodes 
        = __Vdly__error__DOT__monitor__DOT__inflight_opcodes;
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[0U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes[0U];
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[1U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes[1U];
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[2U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes[2U];
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes[3U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes[3U];
    vlSelf->__PVT__error__DOT__monitor__DOT__watchdog 
        = __Vdly__error__DOT__monitor__DOT__watchdog;
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_1 
        = __Vdly__error__DOT__monitor__DOT__inflight_1;
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[0U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[0U];
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[1U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[1U];
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[2U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[2U];
    vlSelf->__PVT__error__DOT__monitor__DOT__inflight_sizes_1[3U] 
        = __Vdly__error__DOT__monitor__DOT__inflight_sizes_1[3U];
    vlSelf->__PVT__error__DOT__monitor__DOT__watchdog_1 
        = __Vdly__error__DOT__monitor__DOT__watchdog_1;
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_1 
        = __Vdly__error__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_2 
        = __Vdly__error__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter 
        = __Vdly__error__DOT__monitor__DOT__a_first_counter;
    vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1 
        = __Vdly__error__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter 
        = __Vdly__bar__DOT__monitor__DOT__d_first_counter;
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight 
        = __Vdly__bar__DOT__monitor__DOT__inflight;
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_opcodes 
        = __Vdly__bar__DOT__monitor__DOT__inflight_opcodes;
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes 
        = __Vdly__bar__DOT__monitor__DOT__inflight_sizes;
    vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog 
        = __Vdly__bar__DOT__monitor__DOT__watchdog;
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_1 
        = __Vdly__bar__DOT__monitor__DOT__inflight_1;
    vlSelf->__PVT__bar__DOT__monitor__DOT__inflight_sizes_1 
        = __Vdly__bar__DOT__monitor__DOT__inflight_sizes_1;
    vlSelf->__PVT__bar__DOT__monitor__DOT__watchdog_1 
        = __Vdly__bar__DOT__monitor__DOT__watchdog_1;
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_1 
        = __Vdly__bar__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_2 
        = __Vdly__bar__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter 
        = __Vdly__bar__DOT__monitor__DOT__a_first_counter;
    vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1 
        = __Vdly__bar__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_1 
        = (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_2 
        = (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_2));
    vlSelf->__PVT__error__DOT__monitor__DOT__a_first_1 
        = (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_1 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_2 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_2));
    vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_1 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1));
}

VL_INLINE_OPT void VysyxSoCFull_TLBusBypass___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass__1(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass__1\n"); );
    // Body
    vlSelf->__PVT__error__DOT__da_bits_opcode = ((0x17U 
                                                  >= 
                                                  (0x1fU 
                                                   & ((IData)(3U) 
                                                      * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))))
                                                  ? 
                                                 (7U 
                                                  & (0x911240U 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(3U) 
                                                         * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode)))))
                                                  : 0U);
    vlSelf->__PVT__error__DOT__a_last_beats1 = ((4U 
                                                 & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_opcode))
                                                 ? 0U
                                                 : 
                                                (0x3ffU 
                                                 & (~ 
                                                    (0x1ffffffU 
                                                     & (((IData)(0xfffU) 
                                                         << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)) 
                                                        >> 2U)))));
    vlSelf->__PVT__error__DOT__r_beats1 = ((1U & (IData)(vlSelf->__PVT__error__DOT__da_bits_opcode))
                                            ? (0x3ffU 
                                               & (~ 
                                                  (0x1ffffffU 
                                                   & (((IData)(0xfffU) 
                                                       << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size)) 
                                                      >> 2U))))
                                            : 0U);
    vlSelf->__PVT__error__DOT__a_last = ((1U == (IData)(vlSelf->__PVT__error__DOT__a_last_counter)) 
                                         | (0U == (IData)(vlSelf->__PVT__error__DOT__a_last_beats1)));
}

VL_INLINE_OPT void VysyxSoCFull_TLBusBypass___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass__0(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass__0\n"); );
    // Init
    CData/*0:0*/ bar__DOT____VdfgTmp_h84f1d1ee__0;
    bar__DOT____VdfgTmp_h84f1d1ee__0 = 0;
    // Body
    vlSelf->__PVT__bar__DOT__bypass = ((IData)(vlSelf->__PVT__bar__DOT__in_reset)
                                        ? (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__do_bypass)
                                        : (IData)(vlSelf->__PVT__bar__DOT__bypass_reg));
    vlSelf->__PVT__bar__DOT__stall = (((IData)(vlSelf->__PVT__bar__DOT__bypass) 
                                       != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__do_bypass)) 
                                      & (0U == (IData)(vlSelf->__PVT__bar__DOT__stall_counter)));
    bar__DOT____VdfgTmp_h84f1d1ee__0 = ((~ (IData)(vlSelf->__PVT__bar__DOT__stall)) 
                                        & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid));
    vlSelf->auto_node_out_out_a_valid = ((~ (IData)(vlSelf->__PVT__bar__DOT__bypass)) 
                                         & (IData)(bar__DOT____VdfgTmp_h84f1d1ee__0));
    vlSelf->__PVT___bar_auto_out_0_a_valid = ((IData)(bar__DOT____VdfgTmp_h84f1d1ee__0) 
                                              & (IData)(vlSelf->__PVT__bar__DOT__bypass));
    vlSelf->__PVT__error__DOT__winner_1 = ((IData)(vlSelf->__PVT___bar_auto_out_0_a_valid) 
                                           & ((IData)(vlSelf->__PVT__error__DOT__a_last) 
                                              & (IData)(vlSelf->__PVT__error__DOT__idle)));
    vlSelf->__PVT__error__DOT__muxState_1 = ((0U == (IData)(vlSelf->__PVT__error__DOT__beatsLeft))
                                              ? (IData)(vlSelf->__PVT__error__DOT__winner_1)
                                              : (IData)(vlSelf->__PVT__error__DOT__state_1));
    vlSelf->__PVT__error__DOT__nodeIn_d_valid = ((IData)(vlSelf->error__DOT____VdfgTmp_hc0029b36__0) 
                                                 & (IData)(vlSelf->__PVT__error__DOT__winner_1));
    if (vlSelf->__PVT__error__DOT__muxState_1) {
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19 
            = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size;
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16 
            = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source;
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24 
            = vlSelf->__PVT__error__DOT__da_bits_opcode;
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3 
            = (1U & (IData)(vlSelf->__PVT__error__DOT__da_bits_opcode));
    } else {
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_19 = 0U;
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16 = 0U;
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24 = 0U;
        vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3 = 0U;
    }
    if (vlSelf->__PVT__bar__DOT__bypass) {
        vlSelf->auto_node_in_in_d_bits_param = 0U;
        vlSelf->auto_node_in_in_d_bits_sink = 0U;
        if (vlSelf->__PVT__error__DOT__muxState_1) {
            vlSelf->auto_node_in_in_d_bits_size = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_size;
            vlSelf->auto_node_in_in_d_bits_denied = 1U;
        } else {
            vlSelf->auto_node_in_in_d_bits_size = 0U;
            vlSelf->auto_node_in_in_d_bits_denied = 0U;
        }
        vlSelf->auto_node_in_in_d_valid = vlSelf->__PVT__error__DOT__nodeIn_d_valid;
        vlSelf->auto_node_in_in_d_bits_corrupt = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_3;
        vlSelf->auto_node_in_in_d_bits_source = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_16;
        vlSelf->auto_node_in_in_d_bits_opcode = vlSelf->__PVT__error__DOT___nodeIn_d_bits_T_24;
    } else {
        vlSelf->auto_node_in_in_d_bits_param = (3U 
                                                & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param));
        vlSelf->auto_node_in_in_d_bits_sink = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_sink;
        vlSelf->auto_node_in_in_d_bits_size = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_size;
        vlSelf->auto_node_in_in_d_bits_denied = (1U 
                                                 & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param) 
                                                    >> 2U));
        vlSelf->auto_node_in_in_d_valid = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_valid;
        vlSelf->auto_node_in_in_d_bits_corrupt = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_corrupt;
        vlSelf->auto_node_in_in_d_bits_source = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_source;
        vlSelf->auto_node_in_in_d_bits_opcode = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_opcode;
    }
}

VL_INLINE_OPT void VysyxSoCFull_TLBusBypass___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass__1(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass__1\n"); );
    // Body
    vlSelf->auto_node_out_out_d_ready = ((~ (IData)(vlSelf->__PVT__bar__DOT__bypass)) 
                                         & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_d_ready));
    vlSelf->__PVT___bar_auto_out_0_d_ready = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_d_ready) 
                                              & (IData)(vlSelf->__PVT__bar__DOT__bypass));
    vlSelf->__PVT__error__DOT__da_ready = ((IData)(vlSelf->__PVT___bar_auto_out_0_d_ready) 
                                           & (IData)(vlSelf->error__DOT____VdfgTmp_hc0029b36__0));
    vlSelf->__PVT__error__DOT__nodeIn_a_ready = (1U 
                                                 & ((~ (IData)(vlSelf->__PVT__error__DOT__a_last)) 
                                                    | ((IData)(vlSelf->__PVT__error__DOT__da_ready) 
                                                       & (((1U 
                                                            == (IData)(vlSelf->__PVT__error__DOT__r_counter)) 
                                                           | (0U 
                                                              == (IData)(vlSelf->__PVT__error__DOT__r_beats1))) 
                                                          & (IData)(vlSelf->__PVT__error__DOT__idle)))));
    vlSelf->__PVT__error__DOT__monitor__DOT___a_first_T_1 
        = ((IData)(vlSelf->__PVT__error__DOT__nodeIn_a_ready) 
           & (IData)(vlSelf->__PVT___bar_auto_out_0_a_valid));
    vlSelf->auto_node_in_in_a_ready = (1U & ((~ (IData)(vlSelf->__PVT__bar__DOT__stall)) 
                                             & ((IData)(vlSelf->__PVT__bar__DOT__bypass)
                                                 ? (IData)(vlSelf->__PVT__error__DOT__nodeIn_a_ready)
                                                 : 
                                                (~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sinkA__DOT__inject_io_i_q__DOT__full)))));
    vlSelf->__PVT__error__DOT__monitor__DOT___GEN_0 
        = ((IData)(vlSelf->__PVT__error__DOT__monitor__DOT___a_first_T_1) 
           & (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1)));
    vlSelf->__PVT__bar__DOT__monitor__DOT___a_first_T_1 
        = ((IData)(vlSelf->auto_node_in_in_a_ready) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__xbar_1.auto_anon_out_0_a_valid));
    vlSelf->__PVT__bar__DOT__monitor__DOT___GEN_0 = 
        ((IData)(vlSelf->__PVT__bar__DOT__monitor__DOT___a_first_T_1) 
         & (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1)));
}
