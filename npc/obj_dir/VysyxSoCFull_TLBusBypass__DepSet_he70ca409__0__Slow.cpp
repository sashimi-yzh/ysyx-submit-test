// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLBusBypass.h"
#include "VysyxSoCFull__Syms.h"

VL_ATTR_COLD void VysyxSoCFull_TLBusBypass___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass__0(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sbypass__0\n"); );
    // Body
    vlSelf->__PVT__bar__DOT__stall_first = (0U == (IData)(vlSelf->__PVT__bar__DOT__stall_counter));
    vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_1 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__error__DOT__da_first = (0U == (IData)(vlSelf->__PVT__error__DOT__r_counter));
    vlSelf->__PVT__error__DOT__idle_1 = (0U == (IData)(vlSelf->__PVT__error__DOT__beatsLeft));
    vlSelf->__PVT__error__DOT__monitor__DOT__a_first_1 
        = (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_1 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_2 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_2));
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_1 
        = (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_2 
        = (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_2));
    vlSelf->error__DOT____VdfgTmp_hc0029b36__0 = ((0U 
                                                   == (IData)(vlSelf->__PVT__error__DOT__beatsLeft)) 
                                                  | (IData)(vlSelf->__PVT__error__DOT__state_1));
    vlSelf->__PVT__bar__DOT__bypass = ((IData)(vlSelf->__PVT__bar__DOT__in_reset)
                                        ? (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__do_bypass)
                                        : (IData)(vlSelf->__PVT__bar__DOT__bypass_reg));
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

VL_ATTR_COLD void VysyxSoCFull_TLBusBypass___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass__0(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass__0\n"); );
    // Body
    vlSelf->__PVT__bar__DOT__stall_first = (0U == (IData)(vlSelf->__PVT__bar__DOT__stall_counter));
    vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_1 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__error__DOT__da_first = (0U == (IData)(vlSelf->__PVT__error__DOT__r_counter));
    vlSelf->__PVT__error__DOT__idle_1 = (0U == (IData)(vlSelf->__PVT__error__DOT__beatsLeft));
    vlSelf->__PVT__error__DOT__monitor__DOT__a_first_1 
        = (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_1 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_2 
        = (0U == (IData)(vlSelf->__PVT__bar__DOT__monitor__DOT__d_first_counter_2));
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_1 
        = (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__error__DOT__monitor__DOT__d_first_2 
        = (0U == (IData)(vlSelf->__PVT__error__DOT__monitor__DOT__d_first_counter_2));
    vlSelf->error__DOT____VdfgTmp_hc0029b36__0 = ((0U 
                                                   == (IData)(vlSelf->__PVT__error__DOT__beatsLeft)) 
                                                  | (IData)(vlSelf->__PVT__error__DOT__state_1));
    vlSelf->__PVT__bar__DOT__bypass = ((IData)(vlSelf->__PVT__bar__DOT__in_reset)
                                        ? (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__do_bypass)
                                        : (IData)(vlSelf->__PVT__bar__DOT__bypass_reg));
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
    if (vlSelf->__PVT__bar__DOT__bypass) {
        vlSelf->auto_node_in_in_d_bits_param = 0U;
        vlSelf->auto_node_in_in_d_bits_sink = 0U;
    } else {
        vlSelf->auto_node_in_in_d_bits_param = (3U 
                                                & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__q_param));
        vlSelf->auto_node_in_in_d_bits_sink = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT___sourceD_io_d_bits_sink;
    }
    vlSelf->__PVT__bar__DOT__stall = (((IData)(vlSelf->__PVT__bar__DOT__bypass) 
                                       != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__do_bypass)) 
                                      & (0U == (IData)(vlSelf->__PVT__bar__DOT__stall_counter)));
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

VL_ATTR_COLD void VysyxSoCFull_TLBusBypass___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass__1(VysyxSoCFull_TLBusBypass* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TLBusBypass___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sbypass__1\n"); );
    // Init
    CData/*0:0*/ bar__DOT____VdfgTmp_h84f1d1ee__0;
    bar__DOT____VdfgTmp_h84f1d1ee__0 = 0;
    // Body
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
