// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TX.h"
#include "VysyxSoCFull__Syms.h"

VL_ATTR_COLD void VysyxSoCFull_TX___eval_initial__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__tx(VysyxSoCFull_TX* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TX___eval_initial__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__tx\n"); );
    // Body
    if (vlSymsp->TOP.reset) {
        vlSelf->__PVT__rxInc_sink__DOT__ridx_ridx_bin = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__valid_reg = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__ridx_gray = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__ridx_ridx_bin = 0U;
        vlSelf->__PVT__txInc_sink__DOT__valid_reg = 0U;
        vlSelf->__PVT__txInc_sink__DOT__ridx_gray = 0U;
        vlSelf->__PVT__txInc_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_c2b_rst_reg__DOT__reg_0 = 1U;
    }
    if (vlSelf->rxInc_sink__DOT____Vcellinp__sink_valid_0__reset) {
        vlSelf->__PVT__rxInc_sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__rxInc_sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__txInc_sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
}

VL_ATTR_COLD void VysyxSoCFull_TX___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__tx__0(VysyxSoCFull_TX* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TX___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__tx__0\n"); );
    // Init
    IData/*17:0*/ __PVT___GEN;
    __PVT___GEN = 0;
    IData/*16:0*/ __PVT___GEN_0;
    __PVT___GEN_0 = 0;
    SData/*14:0*/ __PVT___GEN_1;
    __PVT___GEN_1 = 0;
    SData/*10:0*/ __PVT___GEN_2;
    __PVT___GEN_2 = 0;
    IData/*17:0*/ __PVT___GEN_3;
    __PVT___GEN_3 = 0;
    IData/*16:0*/ __PVT___GEN_4;
    __PVT___GEN_4 = 0;
    SData/*14:0*/ __PVT___GEN_5;
    __PVT___GEN_5 = 0;
    SData/*10:0*/ __PVT___GEN_6;
    __PVT___GEN_6 = 0;
    IData/*17:0*/ __PVT___GEN_7;
    __PVT___GEN_7 = 0;
    IData/*16:0*/ __PVT___GEN_8;
    __PVT___GEN_8 = 0;
    SData/*14:0*/ __PVT___GEN_9;
    __PVT___GEN_9 = 0;
    SData/*10:0*/ __PVT___GEN_10;
    __PVT___GEN_10 = 0;
    IData/*17:0*/ __PVT___GEN_11;
    __PVT___GEN_11 = 0;
    IData/*16:0*/ __PVT___GEN_12;
    __PVT___GEN_12 = 0;
    SData/*14:0*/ __PVT___GEN_13;
    __PVT___GEN_13 = 0;
    SData/*10:0*/ __PVT___GEN_14;
    __PVT___GEN_14 = 0;
    IData/*17:0*/ __PVT___GEN_15;
    __PVT___GEN_15 = 0;
    IData/*16:0*/ __PVT___GEN_16;
    __PVT___GEN_16 = 0;
    SData/*14:0*/ __PVT___GEN_17;
    __PVT___GEN_17 = 0;
    SData/*10:0*/ __PVT___GEN_18;
    __PVT___GEN_18 = 0;
    CData/*5:0*/ __PVT___readys_filter_T_1;
    __PVT___readys_filter_T_1 = 0;
    SData/*9:0*/ __PVT___GEN_19;
    __PVT___GEN_19 = 0;
    SData/*8:0*/ __PVT___GEN_20;
    __PVT___GEN_20 = 0;
    // Body
    vlSelf->rxInc_sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) 
           | (IData)(vlSymsp->TOP.reset));
    vlSelf->__PVT__ioX_delta = (0x1fffffU & (vlSelf->__PVT__tx_a 
                                             - (IData)(vlSelf->__PVT__qa_q__DOT__elts_0_beats)));
    vlSelf->__PVT__ioX_delta_1 = (0x1fffffU & (vlSelf->__PVT__tx_b 
                                               - (IData)(vlSelf->__PVT__qb_q__DOT__elts_0_beats)));
    vlSelf->__PVT__ioX_delta_2 = (0x1fffffU & (vlSelf->__PVT__tx_c 
                                               - (IData)(vlSelf->__PVT__qc_q__DOT__elts_0_beats)));
    vlSelf->__PVT__ioX_delta_3 = (0x1fffffU & (vlSelf->__PVT__tx_d 
                                               - (IData)(vlSelf->__PVT__qd_q__DOT__elts_0_beats)));
    vlSelf->__PVT__ioX_delta_4 = (0x1fffffU & (vlSelf->__PVT__tx_e 
                                               - (IData)(vlSelf->__PVT__qe_q__DOT__elts_0_beats)));
    vlSelf->__PVT__rxInc_sink__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__rxInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
           & (IData)(vlSelf->__PVT__rxInc_sink__DOT__valid_reg));
    vlSelf->__PVT__txInc_sink__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__txInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
           & (IData)(vlSelf->__PVT__txInc_sink__DOT__valid_reg));
    vlSelf->__PVT__allowReturn = (1U & ((~ ((IData)(vlSelf->__PVT__ioX_cq__DOT__valid_0) 
                                            | ((IData)(vlSelf->__PVT__ioX_cq_1__DOT__valid_0) 
                                               | ((IData)(vlSelf->__PVT__ioX_cq_2__DOT__valid_0) 
                                                  | ((IData)(vlSelf->__PVT__ioX_cq_3__DOT__valid_0) 
                                                     | (IData)(vlSelf->__PVT__ioX_cq_4__DOT__valid_0)))))) 
                                        | (~ (IData)(
                                                     (0U 
                                                      != (IData)(vlSelf->__PVT__xmit))))));
    __PVT___GEN = (0x3ffffU & ((vlSelf->__PVT__rx_a 
                                >> 1U) | (vlSelf->__PVT__rx_a 
                                          >> 2U)));
    __PVT___GEN_3 = (0x3ffffU & ((vlSelf->__PVT__rx_b 
                                  >> 1U) | (vlSelf->__PVT__rx_b 
                                            >> 2U)));
    __PVT___GEN_7 = (0x3ffffU & ((vlSelf->__PVT__rx_c 
                                  >> 1U) | (vlSelf->__PVT__rx_c 
                                            >> 2U)));
    __PVT___GEN_11 = (0x3ffffU & ((vlSelf->__PVT__rx_d 
                                   >> 1U) | (vlSelf->__PVT__rx_d 
                                             >> 2U)));
    __PVT___GEN_15 = (0x3ffffU & ((vlSelf->__PVT__rx_e 
                                   >> 1U) | (vlSelf->__PVT__rx_e 
                                             >> 2U)));
    vlSelf->__PVT__ioX_allow = (1U & ((~ (IData)(vlSelf->__PVT__ioX_first)) 
                                      | VL_LTS_III(21, 0x1fffffU, vlSelf->__PVT__ioX_delta)));
    vlSelf->__PVT__ioX_allow_1 = (1U & ((~ (IData)(vlSelf->__PVT__ioX_first_1)) 
                                        | VL_LTS_III(21, 0x1fffffU, vlSelf->__PVT__ioX_delta_1)));
    vlSelf->__PVT__ioX_allow_2 = (1U & ((~ (IData)(vlSelf->__PVT__ioX_first_2)) 
                                        | VL_LTS_III(21, 0x1fffffU, vlSelf->__PVT__ioX_delta_2)));
    vlSelf->__PVT__ioX_allow_3 = (1U & ((~ (IData)(vlSelf->__PVT__ioX_first_3)) 
                                        | VL_LTS_III(21, 0x1fffffU, vlSelf->__PVT__ioX_delta_3)));
    vlSelf->__PVT__ioX_allow_4 = (1U & ((~ (IData)(vlSelf->__PVT__ioX_first_4)) 
                                        | VL_LTS_III(21, 0x1fffffU, vlSelf->__PVT__ioX_delta_4)));
    vlSelf->__PVT__rxInc_sink__DOT__ridx = ((IData)(vlSelf->__PVT__rxInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                            & ((IData)(vlSelf->__PVT__rxInc_sink__DOT__ridx_ridx_bin) 
                                               + (IData)(vlSelf->__PVT__rxInc_sink__DOT__io_deq_valid_0)));
    vlSelf->__PVT__txInc_sink__DOT__ridx = ((IData)(vlSelf->__PVT__txInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                            & ((IData)(vlSelf->__PVT__txInc_sink__DOT__ridx_ridx_bin) 
                                               + (IData)(vlSelf->__PVT__txInc_sink__DOT__io_deq_valid_0)));
    vlSelf->__PVT__f_valid = ((IData)(vlSelf->__PVT__rxQ__DOT__valid_0) 
                              & (IData)(vlSelf->__PVT__allowReturn));
    __PVT___GEN_0 = (0x1ffffU & (__PVT___GEN | ((0x10000U 
                                                 & (vlSelf->__PVT__rx_a 
                                                    >> 3U)) 
                                                | (0xffffU 
                                                   & (__PVT___GEN 
                                                      >> 2U)))));
    __PVT___GEN_4 = (0x1ffffU & (__PVT___GEN_3 | ((0x10000U 
                                                   & (vlSelf->__PVT__rx_b 
                                                      >> 3U)) 
                                                  | (0xffffU 
                                                     & (__PVT___GEN_3 
                                                        >> 2U)))));
    __PVT___GEN_8 = (0x1ffffU & (__PVT___GEN_7 | ((0x10000U 
                                                   & (vlSelf->__PVT__rx_c 
                                                      >> 3U)) 
                                                  | (0xffffU 
                                                     & (__PVT___GEN_7 
                                                        >> 2U)))));
    __PVT___GEN_12 = (0x1ffffU & (__PVT___GEN_11 | 
                                  ((0x10000U & (vlSelf->__PVT__rx_d 
                                                >> 3U)) 
                                   | (0xffffU & (__PVT___GEN_11 
                                                 >> 2U)))));
    __PVT___GEN_16 = (0x1ffffU & (__PVT___GEN_15 | 
                                  ((0x10000U & (vlSelf->__PVT__rx_e 
                                                >> 3U)) 
                                   | (0xffffU & (__PVT___GEN_15 
                                                 >> 2U)))));
    vlSelf->__PVT__qa_q_io_deq_ready = ((~ (IData)(vlSelf->__PVT__ioX_cq__DOT__valid_1)) 
                                        & (IData)(vlSelf->__PVT__ioX_allow));
    vlSelf->__PVT__qb_q_io_deq_ready = ((~ (IData)(vlSelf->__PVT__ioX_cq_1__DOT__valid_1)) 
                                        & (IData)(vlSelf->__PVT__ioX_allow_1));
    vlSelf->__PVT__qc_q_io_deq_ready = ((~ (IData)(vlSelf->__PVT__ioX_cq_2__DOT__valid_1)) 
                                        & (IData)(vlSelf->__PVT__ioX_allow_2));
    vlSelf->__PVT__qd_q_io_deq_ready = ((~ (IData)(vlSelf->__PVT__ioX_cq_3__DOT__valid_1)) 
                                        & (IData)(vlSelf->__PVT__ioX_allow_3));
    vlSelf->__PVT__qe_q_io_deq_ready = ((~ (IData)(vlSelf->__PVT__ioX_cq_4__DOT__valid_1)) 
                                        & (IData)(vlSelf->__PVT__ioX_allow_4));
    vlSelf->__PVT__rxInc_sink__DOT__valid = ((IData)(vlSelf->__PVT__rxInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                             & ((IData)(vlSelf->__PVT__rxInc_sink__DOT__ridx) 
                                                != (IData)(vlSelf->__PVT__rxInc_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0)));
    vlSelf->__PVT__txInc_sink__DOT__valid = ((IData)(vlSelf->__PVT__txInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                             & ((IData)(vlSelf->__PVT__txInc_sink__DOT__ridx) 
                                                != (IData)(vlSelf->__PVT__txInc_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0)));
    vlSelf->__PVT__requests = (((IData)(vlSelf->__PVT__f_valid) 
                                << 5U) | (((IData)(vlSelf->__PVT__ioX_cq_4__DOT__valid_0) 
                                           << 4U) | 
                                          (((IData)(vlSelf->__PVT__ioX_cq_3__DOT__valid_0) 
                                            << 3U) 
                                           | (((IData)(vlSelf->__PVT__ioX_cq_2__DOT__valid_0) 
                                               << 2U) 
                                              | (((IData)(vlSelf->__PVT__ioX_cq_1__DOT__valid_0) 
                                                  << 1U) 
                                                 | (IData)(vlSelf->__PVT__ioX_cq__DOT__valid_0))))));
    __PVT___GEN_1 = (0x7fffU & (__PVT___GEN_0 | ((0x4000U 
                                                  & (vlSelf->__PVT__rx_a 
                                                     >> 5U)) 
                                                 | ((0x2000U 
                                                     & (__PVT___GEN 
                                                        >> 4U)) 
                                                    | (0x1fffU 
                                                       & (__PVT___GEN_0 
                                                          >> 4U))))));
    __PVT___GEN_5 = (0x7fffU & (__PVT___GEN_4 | ((0x4000U 
                                                  & (vlSelf->__PVT__rx_b 
                                                     >> 5U)) 
                                                 | ((0x2000U 
                                                     & (__PVT___GEN_3 
                                                        >> 4U)) 
                                                    | (0x1fffU 
                                                       & (__PVT___GEN_4 
                                                          >> 4U))))));
    __PVT___GEN_9 = (0x7fffU & (__PVT___GEN_8 | ((0x4000U 
                                                  & (vlSelf->__PVT__rx_c 
                                                     >> 5U)) 
                                                 | ((0x2000U 
                                                     & (__PVT___GEN_7 
                                                        >> 4U)) 
                                                    | (0x1fffU 
                                                       & (__PVT___GEN_8 
                                                          >> 4U))))));
    __PVT___GEN_13 = (0x7fffU & (__PVT___GEN_12 | (
                                                   (0x4000U 
                                                    & (vlSelf->__PVT__rx_d 
                                                       >> 5U)) 
                                                   | ((0x2000U 
                                                       & (__PVT___GEN_11 
                                                          >> 4U)) 
                                                      | (0x1fffU 
                                                         & (__PVT___GEN_12 
                                                            >> 4U))))));
    __PVT___GEN_17 = (0x7fffU & (__PVT___GEN_16 | (
                                                   (0x4000U 
                                                    & (vlSelf->__PVT__rx_e 
                                                       >> 5U)) 
                                                   | ((0x2000U 
                                                       & (__PVT___GEN_15 
                                                          >> 4U)) 
                                                      | (0x1fffU 
                                                         & (__PVT___GEN_16 
                                                            >> 4U))))));
    __PVT___readys_filter_T_1 = ((~ (IData)(vlSelf->__PVT__readys_mask)) 
                                 & (IData)(vlSelf->__PVT__requests));
    __PVT___GEN_2 = (0x7ffU & ((IData)(__PVT___GEN_1) 
                               | ((0x400U & (vlSelf->__PVT__rx_a 
                                             >> 9U)) 
                                  | ((0x200U & (__PVT___GEN 
                                                >> 8U)) 
                                     | ((0x180U & (__PVT___GEN_0 
                                                   >> 8U)) 
                                        | (0x7fU & 
                                           ((IData)(__PVT___GEN_1) 
                                            >> 8U)))))));
    __PVT___GEN_6 = (0x7ffU & ((IData)(__PVT___GEN_5) 
                               | ((0x400U & (vlSelf->__PVT__rx_b 
                                             >> 9U)) 
                                  | ((0x200U & (__PVT___GEN_3 
                                                >> 8U)) 
                                     | ((0x180U & (__PVT___GEN_4 
                                                   >> 8U)) 
                                        | (0x7fU & 
                                           ((IData)(__PVT___GEN_5) 
                                            >> 8U)))))));
    __PVT___GEN_10 = (0x7ffU & ((IData)(__PVT___GEN_9) 
                                | ((0x400U & (vlSelf->__PVT__rx_c 
                                              >> 9U)) 
                                   | ((0x200U & (__PVT___GEN_7 
                                                 >> 8U)) 
                                      | ((0x180U & 
                                          (__PVT___GEN_8 
                                           >> 8U)) 
                                         | (0x7fU & 
                                            ((IData)(__PVT___GEN_9) 
                                             >> 8U)))))));
    __PVT___GEN_14 = (0x7ffU & ((IData)(__PVT___GEN_13) 
                                | ((0x400U & (vlSelf->__PVT__rx_d 
                                              >> 9U)) 
                                   | ((0x200U & (__PVT___GEN_11 
                                                 >> 8U)) 
                                      | ((0x180U & 
                                          (__PVT___GEN_12 
                                           >> 8U)) 
                                         | (0x7fU & 
                                            ((IData)(__PVT___GEN_13) 
                                             >> 8U)))))));
    __PVT___GEN_18 = (0x7ffU & ((IData)(__PVT___GEN_17) 
                                | ((0x400U & (vlSelf->__PVT__rx_e 
                                              >> 9U)) 
                                   | ((0x200U & (__PVT___GEN_15 
                                                 >> 8U)) 
                                      | ((0x180U & 
                                          (__PVT___GEN_16 
                                           >> 8U)) 
                                         | (0x7fU & 
                                            ((IData)(__PVT___GEN_17) 
                                             >> 8U)))))));
    __PVT___GEN_19 = (((0x3e0U & ((IData)(__PVT___readys_filter_T_1) 
                                  << 5U)) | (((IData)(vlSelf->__PVT__f_valid) 
                                              << 4U) 
                                             | (((IData)(vlSelf->__PVT__ioX_cq_4__DOT__valid_0) 
                                                 << 3U) 
                                                | (((IData)(vlSelf->__PVT__ioX_cq_3__DOT__valid_0) 
                                                    << 2U) 
                                                   | (((IData)(vlSelf->__PVT__ioX_cq_2__DOT__valid_0) 
                                                       << 1U) 
                                                      | (IData)(vlSelf->__PVT__ioX_cq_1__DOT__valid_0)))))) 
                      | (((IData)(__PVT___readys_filter_T_1) 
                          << 4U) | (((IData)(vlSelf->__PVT__f_valid) 
                                     << 3U) | (((IData)(vlSelf->__PVT__ioX_cq_4__DOT__valid_0) 
                                                << 2U) 
                                               | (((IData)(vlSelf->__PVT__ioX_cq_3__DOT__valid_0) 
                                                   << 1U) 
                                                  | (IData)(vlSelf->__PVT__ioX_cq_2__DOT__valid_0))))));
    vlSelf->__PVT__mask = ((0x40000U & (vlSelf->__PVT__rx_a 
                                        >> 1U)) | (
                                                   (0x20000U 
                                                    & __PVT___GEN) 
                                                   | ((0x18000U 
                                                       & __PVT___GEN_0) 
                                                      | ((0x7800U 
                                                          & (IData)(__PVT___GEN_1)) 
                                                         | ((0x7f8U 
                                                             & (IData)(__PVT___GEN_2)) 
                                                            | (7U 
                                                               & ((IData)(__PVT___GEN_2) 
                                                                  | ((4U 
                                                                      & (vlSelf->__PVT__rx_a 
                                                                         >> 0x11U)) 
                                                                     | ((2U 
                                                                         & (__PVT___GEN 
                                                                            >> 0x10U)) 
                                                                        | (1U 
                                                                           & (__PVT___GEN_0 
                                                                              >> 0x10U)))))))))));
    vlSelf->__PVT__mask_1 = ((0x40000U & (vlSelf->__PVT__rx_b 
                                          >> 1U)) | 
                             ((0x20000U & __PVT___GEN_3) 
                              | ((0x18000U & __PVT___GEN_4) 
                                 | ((0x7800U & (IData)(__PVT___GEN_5)) 
                                    | ((0x7f8U & (IData)(__PVT___GEN_6)) 
                                       | (7U & ((IData)(__PVT___GEN_6) 
                                                | ((4U 
                                                    & (vlSelf->__PVT__rx_b 
                                                       >> 0x11U)) 
                                                   | ((2U 
                                                       & (__PVT___GEN_3 
                                                          >> 0x10U)) 
                                                      | (1U 
                                                         & (__PVT___GEN_4 
                                                            >> 0x10U)))))))))));
    vlSelf->__PVT__mask_2 = ((0x40000U & (vlSelf->__PVT__rx_c 
                                          >> 1U)) | 
                             ((0x20000U & __PVT___GEN_7) 
                              | ((0x18000U & __PVT___GEN_8) 
                                 | ((0x7800U & (IData)(__PVT___GEN_9)) 
                                    | ((0x7f8U & (IData)(__PVT___GEN_10)) 
                                       | (7U & ((IData)(__PVT___GEN_10) 
                                                | ((4U 
                                                    & (vlSelf->__PVT__rx_c 
                                                       >> 0x11U)) 
                                                   | ((2U 
                                                       & (__PVT___GEN_7 
                                                          >> 0x10U)) 
                                                      | (1U 
                                                         & (__PVT___GEN_8 
                                                            >> 0x10U)))))))))));
    vlSelf->__PVT__mask_3 = ((0x40000U & (vlSelf->__PVT__rx_d 
                                          >> 1U)) | 
                             ((0x20000U & __PVT___GEN_11) 
                              | ((0x18000U & __PVT___GEN_12) 
                                 | ((0x7800U & (IData)(__PVT___GEN_13)) 
                                    | ((0x7f8U & (IData)(__PVT___GEN_14)) 
                                       | (7U & ((IData)(__PVT___GEN_14) 
                                                | ((4U 
                                                    & (vlSelf->__PVT__rx_d 
                                                       >> 0x11U)) 
                                                   | ((2U 
                                                       & (__PVT___GEN_11 
                                                          >> 0x10U)) 
                                                      | (1U 
                                                         & (__PVT___GEN_12 
                                                            >> 0x10U)))))))))));
    vlSelf->__PVT__mask_4 = ((0x40000U & (vlSelf->__PVT__rx_e 
                                          >> 1U)) | 
                             ((0x20000U & __PVT___GEN_15) 
                              | ((0x18000U & __PVT___GEN_16) 
                                 | ((0x7800U & (IData)(__PVT___GEN_17)) 
                                    | ((0x7f8U & (IData)(__PVT___GEN_18)) 
                                       | (7U & ((IData)(__PVT___GEN_18) 
                                                | ((4U 
                                                    & (vlSelf->__PVT__rx_e 
                                                       >> 0x11U)) 
                                                   | ((2U 
                                                       & (__PVT___GEN_15 
                                                          >> 0x10U)) 
                                                      | (1U 
                                                         & (__PVT___GEN_16 
                                                            >> 0x10U)))))))))));
    __PVT___GEN_20 = (0x1ffU & ((IData)(__PVT___GEN_19) 
                                | ((0x100U & ((IData)(__PVT___readys_filter_T_1) 
                                              << 3U)) 
                                   | (0xffU & ((IData)(__PVT___GEN_19) 
                                               >> 2U)))));
    vlSelf->__PVT__msbOH = (0xfffffU & (~ ((0x80000U 
                                            & ((~ (vlSelf->__PVT__rx_a 
                                                   >> 0x13U)) 
                                               << 0x13U)) 
                                           | (0x7ffffU 
                                              & ((~ vlSelf->__PVT__rx_a) 
                                                 | vlSelf->__PVT__mask)))));
    vlSelf->__PVT__msbOH_1 = (0xfffffU & (~ ((0x80000U 
                                              & ((~ 
                                                  (vlSelf->__PVT__rx_b 
                                                   >> 0x13U)) 
                                                 << 0x13U)) 
                                             | (0x7ffffU 
                                                & ((~ vlSelf->__PVT__rx_b) 
                                                   | vlSelf->__PVT__mask_1)))));
    vlSelf->__PVT__msbOH_2 = (0xfffffU & (~ ((0x80000U 
                                              & ((~ 
                                                  (vlSelf->__PVT__rx_c 
                                                   >> 0x13U)) 
                                                 << 0x13U)) 
                                             | (0x7ffffU 
                                                & ((~ vlSelf->__PVT__rx_c) 
                                                   | vlSelf->__PVT__mask_2)))));
    vlSelf->__PVT__msbOH_3 = (0xfffffU & (~ ((0x80000U 
                                              & ((~ 
                                                  (vlSelf->__PVT__rx_d 
                                                   >> 0x13U)) 
                                                 << 0x13U)) 
                                             | (0x7ffffU 
                                                & ((~ vlSelf->__PVT__rx_d) 
                                                   | vlSelf->__PVT__mask_3)))));
    vlSelf->__PVT__msbOH_4 = (0xfffffU & (~ ((0x80000U 
                                              & ((~ 
                                                  (vlSelf->__PVT__rx_e 
                                                   >> 0x13U)) 
                                                 << 0x13U)) 
                                             | (0x7ffffU 
                                                & ((~ vlSelf->__PVT__rx_e) 
                                                   | vlSelf->__PVT__mask_4)))));
    vlSelf->__PVT__readys_unready = (((0x400U & ((IData)(__PVT___readys_filter_T_1) 
                                                 << 5U)) 
                                      | ((0x200U & (IData)(__PVT___GEN_19)) 
                                         | ((0x180U 
                                             & (IData)(__PVT___GEN_20)) 
                                            | (0x7fU 
                                               & ((IData)(__PVT___GEN_20) 
                                                  | ((0x40U 
                                                      & ((IData)(__PVT___readys_filter_T_1) 
                                                         << 1U)) 
                                                     | ((0x20U 
                                                         & ((IData)(__PVT___GEN_19) 
                                                            >> 4U)) 
                                                        | (0x1fU 
                                                           & ((IData)(__PVT___GEN_20) 
                                                              >> 4U))))))))) 
                                     | ((IData)(vlSelf->__PVT__readys_mask) 
                                        << 6U));
    vlSelf->__PVT___msb_T_2 = (0x7fffU & ((0xfU & (vlSelf->__PVT__msbOH 
                                                   >> 0x10U)) 
                                          | vlSelf->__PVT__msbOH));
    vlSelf->__PVT___msb_T_15 = (0x7fffU & ((0xfU & 
                                            (vlSelf->__PVT__msbOH_1 
                                             >> 0x10U)) 
                                           | vlSelf->__PVT__msbOH_1));
    vlSelf->__PVT___msb_T_28 = (0x7fffU & ((0xfU & 
                                            (vlSelf->__PVT__msbOH_2 
                                             >> 0x10U)) 
                                           | vlSelf->__PVT__msbOH_2));
    vlSelf->__PVT___msb_T_41 = (0x7fffU & ((0xfU & 
                                            (vlSelf->__PVT__msbOH_3 
                                             >> 0x10U)) 
                                           | vlSelf->__PVT__msbOH_3));
    vlSelf->__PVT___msb_T_54 = (0x7fffU & ((0xfU & 
                                            (vlSelf->__PVT__msbOH_4 
                                             >> 0x10U)) 
                                           | vlSelf->__PVT__msbOH_4));
    vlSelf->__PVT___readys_readys_T_2 = (0x3fU & (((IData)(vlSelf->__PVT__readys_unready) 
                                                   >> 6U) 
                                                  & (IData)(vlSelf->__PVT__readys_unready)));
    vlSelf->__PVT___msb_T_4 = (0x7fU & (((IData)(vlSelf->__PVT___msb_T_2) 
                                         >> 8U) | (IData)(vlSelf->__PVT___msb_T_2)));
    vlSelf->__PVT___msb_T_17 = (0x7fU & (((IData)(vlSelf->__PVT___msb_T_15) 
                                          >> 8U) | (IData)(vlSelf->__PVT___msb_T_15)));
    vlSelf->__PVT___msb_T_30 = (0x7fU & (((IData)(vlSelf->__PVT___msb_T_28) 
                                          >> 8U) | (IData)(vlSelf->__PVT___msb_T_28)));
    vlSelf->__PVT___msb_T_43 = (0x7fU & (((IData)(vlSelf->__PVT___msb_T_41) 
                                          >> 8U) | (IData)(vlSelf->__PVT___msb_T_41)));
    vlSelf->__PVT___msb_T_56 = (0x7fU & (((IData)(vlSelf->__PVT___msb_T_54) 
                                          >> 8U) | (IData)(vlSelf->__PVT___msb_T_54)));
    vlSelf->__PVT__winner = ((~ (IData)(vlSelf->__PVT___readys_readys_T_2)) 
                             & (IData)(vlSelf->__PVT__requests));
    if (vlSelf->__PVT__first) {
        vlSelf->__PVT__send = vlSelf->__PVT__rxQ__DOT__valid_0;
        vlSelf->__PVT__allowed = (0x3fU & (~ (IData)(vlSelf->__PVT___readys_readys_T_2)));
        vlSelf->__PVT__grant = vlSelf->__PVT__winner;
    } else {
        vlSelf->__PVT__send = (0U != ((IData)(vlSelf->__PVT__state) 
                                      & (IData)(vlSelf->__PVT__requests)));
        vlSelf->__PVT__allowed = (0x3fU & (IData)(vlSelf->__PVT__state));
        vlSelf->__PVT__grant = vlSelf->__PVT__state;
    }
    vlSelf->__PVT___msb_T_6 = (7U & (((IData)(vlSelf->__PVT___msb_T_4) 
                                      >> 4U) | (IData)(vlSelf->__PVT___msb_T_4)));
    vlSelf->__PVT___msb_T_19 = (7U & (((IData)(vlSelf->__PVT___msb_T_17) 
                                       >> 4U) | (IData)(vlSelf->__PVT___msb_T_17)));
    vlSelf->__PVT___msb_T_32 = (7U & (((IData)(vlSelf->__PVT___msb_T_30) 
                                       >> 4U) | (IData)(vlSelf->__PVT___msb_T_30)));
    vlSelf->__PVT___msb_T_45 = (7U & (((IData)(vlSelf->__PVT___msb_T_43) 
                                       >> 4U) | (IData)(vlSelf->__PVT___msb_T_43)));
    vlSelf->__PVT___msb_T_58 = (7U & (((IData)(vlSelf->__PVT___msb_T_56) 
                                       >> 4U) | (IData)(vlSelf->__PVT___msb_T_56)));
    vlSelf->__Vcellinp__rxQ__io_deq_ready = (((IData)(vlSelf->__PVT__allowed) 
                                              >> 5U) 
                                             & (IData)(vlSelf->__PVT__allowReturn));
    vlSelf->__Vcellinp__rxQ__io_enq_bits_data = (5U 
                                                 | (((IData)(
                                                             (0U 
                                                              != 
                                                              (0x1fU 
                                                               & (vlSelf->__PVT__msbOH_4 
                                                                  >> 0xfU)))) 
                                                     << 0x1fU) 
                                                    | (((IData)(
                                                                (0U 
                                                                 != 
                                                                 (0xffU 
                                                                  & ((IData)(vlSelf->__PVT___msb_T_54) 
                                                                     >> 7U)))) 
                                                        << 0x1eU) 
                                                       | (((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0xfU 
                                                                     & ((IData)(vlSelf->__PVT___msb_T_56) 
                                                                        >> 3U)))) 
                                                           << 0x1dU) 
                                                          | (((IData)(
                                                                      (0U 
                                                                       != 
                                                                       (3U 
                                                                        & ((IData)(vlSelf->__PVT___msb_T_58) 
                                                                           >> 1U)))) 
                                                              << 0x1cU) 
                                                             | (((IData)(
                                                                         (0U 
                                                                          != 
                                                                          (5U 
                                                                           & (IData)(vlSelf->__PVT___msb_T_58)))) 
                                                                 << 0x1bU) 
                                                                | (((IData)(
                                                                            (0U 
                                                                             != 
                                                                             (0x1fU 
                                                                              & (vlSelf->__PVT__msbOH_3 
                                                                                >> 0xfU)))) 
                                                                    << 0x1aU) 
                                                                   | (((IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0xffU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_41) 
                                                                                >> 7U)))) 
                                                                       << 0x19U) 
                                                                      | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xfU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_43) 
                                                                                >> 3U)))) 
                                                                          << 0x18U) 
                                                                         | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (3U 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_45) 
                                                                                >> 1U)))) 
                                                                             << 0x17U) 
                                                                            | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (5U 
                                                                                & (IData)(vlSelf->__PVT___msb_T_45)))) 
                                                                                << 0x16U) 
                                                                               | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__msbOH_2 
                                                                                >> 0xfU)))) 
                                                                                << 0x15U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xffU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_28) 
                                                                                >> 7U)))) 
                                                                                << 0x14U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xfU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_30) 
                                                                                >> 3U)))) 
                                                                                << 0x13U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (3U 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_32) 
                                                                                >> 1U)))) 
                                                                                << 0x12U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (5U 
                                                                                & (IData)(vlSelf->__PVT___msb_T_32)))) 
                                                                                << 0x11U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__msbOH_1 
                                                                                >> 0xfU)))) 
                                                                                << 0x10U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xffU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_15) 
                                                                                >> 7U)))) 
                                                                                << 0xfU) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xfU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_17) 
                                                                                >> 3U)))) 
                                                                                << 0xeU) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (3U 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_19) 
                                                                                >> 1U)))) 
                                                                                << 0xdU) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (5U 
                                                                                & (IData)(vlSelf->__PVT___msb_T_19)))) 
                                                                                << 0xcU) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__msbOH 
                                                                                >> 0xfU)))) 
                                                                                << 0xbU) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xffU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_2) 
                                                                                >> 7U)))) 
                                                                                << 0xaU) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xfU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_4) 
                                                                                >> 3U)))) 
                                                                                << 9U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (3U 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_6) 
                                                                                >> 1U)))) 
                                                                                << 8U) 
                                                                                | ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (5U 
                                                                                & (IData)(vlSelf->__PVT___msb_T_6)))) 
                                                                                << 7U))))))))))))))))))))))))));
}

VL_ATTR_COLD void VysyxSoCFull_TX___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__tx__0(VysyxSoCFull_TX* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_TX___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__tx__0\n"); );
    // Init
    IData/*17:0*/ __PVT___GEN;
    __PVT___GEN = 0;
    IData/*16:0*/ __PVT___GEN_0;
    __PVT___GEN_0 = 0;
    SData/*14:0*/ __PVT___GEN_1;
    __PVT___GEN_1 = 0;
    SData/*10:0*/ __PVT___GEN_2;
    __PVT___GEN_2 = 0;
    IData/*17:0*/ __PVT___GEN_3;
    __PVT___GEN_3 = 0;
    IData/*16:0*/ __PVT___GEN_4;
    __PVT___GEN_4 = 0;
    SData/*14:0*/ __PVT___GEN_5;
    __PVT___GEN_5 = 0;
    SData/*10:0*/ __PVT___GEN_6;
    __PVT___GEN_6 = 0;
    IData/*17:0*/ __PVT___GEN_7;
    __PVT___GEN_7 = 0;
    IData/*16:0*/ __PVT___GEN_8;
    __PVT___GEN_8 = 0;
    SData/*14:0*/ __PVT___GEN_9;
    __PVT___GEN_9 = 0;
    SData/*10:0*/ __PVT___GEN_10;
    __PVT___GEN_10 = 0;
    IData/*17:0*/ __PVT___GEN_11;
    __PVT___GEN_11 = 0;
    IData/*16:0*/ __PVT___GEN_12;
    __PVT___GEN_12 = 0;
    SData/*14:0*/ __PVT___GEN_13;
    __PVT___GEN_13 = 0;
    SData/*10:0*/ __PVT___GEN_14;
    __PVT___GEN_14 = 0;
    IData/*17:0*/ __PVT___GEN_15;
    __PVT___GEN_15 = 0;
    IData/*16:0*/ __PVT___GEN_16;
    __PVT___GEN_16 = 0;
    SData/*14:0*/ __PVT___GEN_17;
    __PVT___GEN_17 = 0;
    SData/*10:0*/ __PVT___GEN_18;
    __PVT___GEN_18 = 0;
    CData/*5:0*/ __PVT___readys_filter_T_1;
    __PVT___readys_filter_T_1 = 0;
    SData/*9:0*/ __PVT___GEN_19;
    __PVT___GEN_19 = 0;
    SData/*8:0*/ __PVT___GEN_20;
    __PVT___GEN_20 = 0;
    // Body
    vlSelf->rxInc_sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) 
           | (IData)(vlSymsp->TOP.reset));
    vlSelf->__PVT__ioX_delta = (0x1fffffU & (vlSelf->__PVT__tx_a 
                                             - (IData)(vlSelf->__PVT__qa_q__DOT__elts_0_beats)));
    vlSelf->__PVT__ioX_delta_1 = (0x1fffffU & (vlSelf->__PVT__tx_b 
                                               - (IData)(vlSelf->__PVT__qb_q__DOT__elts_0_beats)));
    vlSelf->__PVT__ioX_delta_2 = (0x1fffffU & (vlSelf->__PVT__tx_c 
                                               - (IData)(vlSelf->__PVT__qc_q__DOT__elts_0_beats)));
    vlSelf->__PVT__ioX_delta_3 = (0x1fffffU & (vlSelf->__PVT__tx_d 
                                               - (IData)(vlSelf->__PVT__qd_q__DOT__elts_0_beats)));
    vlSelf->__PVT__ioX_delta_4 = (0x1fffffU & (vlSelf->__PVT__tx_e 
                                               - (IData)(vlSelf->__PVT__qe_q__DOT__elts_0_beats)));
    vlSelf->__PVT__rxInc_sink__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__rxInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
           & (IData)(vlSelf->__PVT__rxInc_sink__DOT__valid_reg));
    vlSelf->__PVT__txInc_sink__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__txInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
           & (IData)(vlSelf->__PVT__txInc_sink__DOT__valid_reg));
    vlSelf->__PVT__allowReturn = (1U & ((~ ((IData)(vlSelf->__PVT__ioX_cq__DOT__valid_0) 
                                            | ((IData)(vlSelf->__PVT__ioX_cq_1__DOT__valid_0) 
                                               | ((IData)(vlSelf->__PVT__ioX_cq_2__DOT__valid_0) 
                                                  | ((IData)(vlSelf->__PVT__ioX_cq_3__DOT__valid_0) 
                                                     | (IData)(vlSelf->__PVT__ioX_cq_4__DOT__valid_0)))))) 
                                        | (~ (IData)(
                                                     (0U 
                                                      != (IData)(vlSelf->__PVT__xmit))))));
    __PVT___GEN = (0x3ffffU & ((vlSelf->__PVT__rx_a 
                                >> 1U) | (vlSelf->__PVT__rx_a 
                                          >> 2U)));
    __PVT___GEN_3 = (0x3ffffU & ((vlSelf->__PVT__rx_b 
                                  >> 1U) | (vlSelf->__PVT__rx_b 
                                            >> 2U)));
    __PVT___GEN_7 = (0x3ffffU & ((vlSelf->__PVT__rx_c 
                                  >> 1U) | (vlSelf->__PVT__rx_c 
                                            >> 2U)));
    __PVT___GEN_11 = (0x3ffffU & ((vlSelf->__PVT__rx_d 
                                   >> 1U) | (vlSelf->__PVT__rx_d 
                                             >> 2U)));
    __PVT___GEN_15 = (0x3ffffU & ((vlSelf->__PVT__rx_e 
                                   >> 1U) | (vlSelf->__PVT__rx_e 
                                             >> 2U)));
    vlSelf->__PVT__ioX_allow = (1U & ((~ (IData)(vlSelf->__PVT__ioX_first)) 
                                      | VL_LTS_III(21, 0x1fffffU, vlSelf->__PVT__ioX_delta)));
    vlSelf->__PVT__ioX_allow_1 = (1U & ((~ (IData)(vlSelf->__PVT__ioX_first_1)) 
                                        | VL_LTS_III(21, 0x1fffffU, vlSelf->__PVT__ioX_delta_1)));
    vlSelf->__PVT__ioX_allow_2 = (1U & ((~ (IData)(vlSelf->__PVT__ioX_first_2)) 
                                        | VL_LTS_III(21, 0x1fffffU, vlSelf->__PVT__ioX_delta_2)));
    vlSelf->__PVT__ioX_allow_3 = (1U & ((~ (IData)(vlSelf->__PVT__ioX_first_3)) 
                                        | VL_LTS_III(21, 0x1fffffU, vlSelf->__PVT__ioX_delta_3)));
    vlSelf->__PVT__ioX_allow_4 = (1U & ((~ (IData)(vlSelf->__PVT__ioX_first_4)) 
                                        | VL_LTS_III(21, 0x1fffffU, vlSelf->__PVT__ioX_delta_4)));
    vlSelf->__PVT__rxInc_sink__DOT__ridx = ((IData)(vlSelf->__PVT__rxInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                            & ((IData)(vlSelf->__PVT__rxInc_sink__DOT__ridx_ridx_bin) 
                                               + (IData)(vlSelf->__PVT__rxInc_sink__DOT__io_deq_valid_0)));
    vlSelf->__PVT__txInc_sink__DOT__ridx = ((IData)(vlSelf->__PVT__txInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                            & ((IData)(vlSelf->__PVT__txInc_sink__DOT__ridx_ridx_bin) 
                                               + (IData)(vlSelf->__PVT__txInc_sink__DOT__io_deq_valid_0)));
    vlSelf->__PVT__f_valid = ((IData)(vlSelf->__PVT__rxQ__DOT__valid_0) 
                              & (IData)(vlSelf->__PVT__allowReturn));
    __PVT___GEN_0 = (0x1ffffU & (__PVT___GEN | ((0x10000U 
                                                 & (vlSelf->__PVT__rx_a 
                                                    >> 3U)) 
                                                | (0xffffU 
                                                   & (__PVT___GEN 
                                                      >> 2U)))));
    __PVT___GEN_4 = (0x1ffffU & (__PVT___GEN_3 | ((0x10000U 
                                                   & (vlSelf->__PVT__rx_b 
                                                      >> 3U)) 
                                                  | (0xffffU 
                                                     & (__PVT___GEN_3 
                                                        >> 2U)))));
    __PVT___GEN_8 = (0x1ffffU & (__PVT___GEN_7 | ((0x10000U 
                                                   & (vlSelf->__PVT__rx_c 
                                                      >> 3U)) 
                                                  | (0xffffU 
                                                     & (__PVT___GEN_7 
                                                        >> 2U)))));
    __PVT___GEN_12 = (0x1ffffU & (__PVT___GEN_11 | 
                                  ((0x10000U & (vlSelf->__PVT__rx_d 
                                                >> 3U)) 
                                   | (0xffffU & (__PVT___GEN_11 
                                                 >> 2U)))));
    __PVT___GEN_16 = (0x1ffffU & (__PVT___GEN_15 | 
                                  ((0x10000U & (vlSelf->__PVT__rx_e 
                                                >> 3U)) 
                                   | (0xffffU & (__PVT___GEN_15 
                                                 >> 2U)))));
    vlSelf->__PVT__qa_q_io_deq_ready = ((~ (IData)(vlSelf->__PVT__ioX_cq__DOT__valid_1)) 
                                        & (IData)(vlSelf->__PVT__ioX_allow));
    vlSelf->__PVT__qb_q_io_deq_ready = ((~ (IData)(vlSelf->__PVT__ioX_cq_1__DOT__valid_1)) 
                                        & (IData)(vlSelf->__PVT__ioX_allow_1));
    vlSelf->__PVT__qc_q_io_deq_ready = ((~ (IData)(vlSelf->__PVT__ioX_cq_2__DOT__valid_1)) 
                                        & (IData)(vlSelf->__PVT__ioX_allow_2));
    vlSelf->__PVT__qd_q_io_deq_ready = ((~ (IData)(vlSelf->__PVT__ioX_cq_3__DOT__valid_1)) 
                                        & (IData)(vlSelf->__PVT__ioX_allow_3));
    vlSelf->__PVT__qe_q_io_deq_ready = ((~ (IData)(vlSelf->__PVT__ioX_cq_4__DOT__valid_1)) 
                                        & (IData)(vlSelf->__PVT__ioX_allow_4));
    vlSelf->__PVT__rxInc_sink__DOT__valid = ((IData)(vlSelf->__PVT__rxInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                             & ((IData)(vlSelf->__PVT__rxInc_sink__DOT__ridx) 
                                                != (IData)(vlSelf->__PVT__rxInc_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0)));
    vlSelf->__PVT__txInc_sink__DOT__valid = ((IData)(vlSelf->__PVT__txInc_sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                             & ((IData)(vlSelf->__PVT__txInc_sink__DOT__ridx) 
                                                != (IData)(vlSelf->__PVT__txInc_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0)));
    vlSelf->__PVT__requests = (((IData)(vlSelf->__PVT__f_valid) 
                                << 5U) | (((IData)(vlSelf->__PVT__ioX_cq_4__DOT__valid_0) 
                                           << 4U) | 
                                          (((IData)(vlSelf->__PVT__ioX_cq_3__DOT__valid_0) 
                                            << 3U) 
                                           | (((IData)(vlSelf->__PVT__ioX_cq_2__DOT__valid_0) 
                                               << 2U) 
                                              | (((IData)(vlSelf->__PVT__ioX_cq_1__DOT__valid_0) 
                                                  << 1U) 
                                                 | (IData)(vlSelf->__PVT__ioX_cq__DOT__valid_0))))));
    __PVT___GEN_1 = (0x7fffU & (__PVT___GEN_0 | ((0x4000U 
                                                  & (vlSelf->__PVT__rx_a 
                                                     >> 5U)) 
                                                 | ((0x2000U 
                                                     & (__PVT___GEN 
                                                        >> 4U)) 
                                                    | (0x1fffU 
                                                       & (__PVT___GEN_0 
                                                          >> 4U))))));
    __PVT___GEN_5 = (0x7fffU & (__PVT___GEN_4 | ((0x4000U 
                                                  & (vlSelf->__PVT__rx_b 
                                                     >> 5U)) 
                                                 | ((0x2000U 
                                                     & (__PVT___GEN_3 
                                                        >> 4U)) 
                                                    | (0x1fffU 
                                                       & (__PVT___GEN_4 
                                                          >> 4U))))));
    __PVT___GEN_9 = (0x7fffU & (__PVT___GEN_8 | ((0x4000U 
                                                  & (vlSelf->__PVT__rx_c 
                                                     >> 5U)) 
                                                 | ((0x2000U 
                                                     & (__PVT___GEN_7 
                                                        >> 4U)) 
                                                    | (0x1fffU 
                                                       & (__PVT___GEN_8 
                                                          >> 4U))))));
    __PVT___GEN_13 = (0x7fffU & (__PVT___GEN_12 | (
                                                   (0x4000U 
                                                    & (vlSelf->__PVT__rx_d 
                                                       >> 5U)) 
                                                   | ((0x2000U 
                                                       & (__PVT___GEN_11 
                                                          >> 4U)) 
                                                      | (0x1fffU 
                                                         & (__PVT___GEN_12 
                                                            >> 4U))))));
    __PVT___GEN_17 = (0x7fffU & (__PVT___GEN_16 | (
                                                   (0x4000U 
                                                    & (vlSelf->__PVT__rx_e 
                                                       >> 5U)) 
                                                   | ((0x2000U 
                                                       & (__PVT___GEN_15 
                                                          >> 4U)) 
                                                      | (0x1fffU 
                                                         & (__PVT___GEN_16 
                                                            >> 4U))))));
    __PVT___readys_filter_T_1 = ((~ (IData)(vlSelf->__PVT__readys_mask)) 
                                 & (IData)(vlSelf->__PVT__requests));
    __PVT___GEN_2 = (0x7ffU & ((IData)(__PVT___GEN_1) 
                               | ((0x400U & (vlSelf->__PVT__rx_a 
                                             >> 9U)) 
                                  | ((0x200U & (__PVT___GEN 
                                                >> 8U)) 
                                     | ((0x180U & (__PVT___GEN_0 
                                                   >> 8U)) 
                                        | (0x7fU & 
                                           ((IData)(__PVT___GEN_1) 
                                            >> 8U)))))));
    __PVT___GEN_6 = (0x7ffU & ((IData)(__PVT___GEN_5) 
                               | ((0x400U & (vlSelf->__PVT__rx_b 
                                             >> 9U)) 
                                  | ((0x200U & (__PVT___GEN_3 
                                                >> 8U)) 
                                     | ((0x180U & (__PVT___GEN_4 
                                                   >> 8U)) 
                                        | (0x7fU & 
                                           ((IData)(__PVT___GEN_5) 
                                            >> 8U)))))));
    __PVT___GEN_10 = (0x7ffU & ((IData)(__PVT___GEN_9) 
                                | ((0x400U & (vlSelf->__PVT__rx_c 
                                              >> 9U)) 
                                   | ((0x200U & (__PVT___GEN_7 
                                                 >> 8U)) 
                                      | ((0x180U & 
                                          (__PVT___GEN_8 
                                           >> 8U)) 
                                         | (0x7fU & 
                                            ((IData)(__PVT___GEN_9) 
                                             >> 8U)))))));
    __PVT___GEN_14 = (0x7ffU & ((IData)(__PVT___GEN_13) 
                                | ((0x400U & (vlSelf->__PVT__rx_d 
                                              >> 9U)) 
                                   | ((0x200U & (__PVT___GEN_11 
                                                 >> 8U)) 
                                      | ((0x180U & 
                                          (__PVT___GEN_12 
                                           >> 8U)) 
                                         | (0x7fU & 
                                            ((IData)(__PVT___GEN_13) 
                                             >> 8U)))))));
    __PVT___GEN_18 = (0x7ffU & ((IData)(__PVT___GEN_17) 
                                | ((0x400U & (vlSelf->__PVT__rx_e 
                                              >> 9U)) 
                                   | ((0x200U & (__PVT___GEN_15 
                                                 >> 8U)) 
                                      | ((0x180U & 
                                          (__PVT___GEN_16 
                                           >> 8U)) 
                                         | (0x7fU & 
                                            ((IData)(__PVT___GEN_17) 
                                             >> 8U)))))));
    __PVT___GEN_19 = (((0x3e0U & ((IData)(__PVT___readys_filter_T_1) 
                                  << 5U)) | (((IData)(vlSelf->__PVT__f_valid) 
                                              << 4U) 
                                             | (((IData)(vlSelf->__PVT__ioX_cq_4__DOT__valid_0) 
                                                 << 3U) 
                                                | (((IData)(vlSelf->__PVT__ioX_cq_3__DOT__valid_0) 
                                                    << 2U) 
                                                   | (((IData)(vlSelf->__PVT__ioX_cq_2__DOT__valid_0) 
                                                       << 1U) 
                                                      | (IData)(vlSelf->__PVT__ioX_cq_1__DOT__valid_0)))))) 
                      | (((IData)(__PVT___readys_filter_T_1) 
                          << 4U) | (((IData)(vlSelf->__PVT__f_valid) 
                                     << 3U) | (((IData)(vlSelf->__PVT__ioX_cq_4__DOT__valid_0) 
                                                << 2U) 
                                               | (((IData)(vlSelf->__PVT__ioX_cq_3__DOT__valid_0) 
                                                   << 1U) 
                                                  | (IData)(vlSelf->__PVT__ioX_cq_2__DOT__valid_0))))));
    vlSelf->__PVT__mask = ((0x40000U & (vlSelf->__PVT__rx_a 
                                        >> 1U)) | (
                                                   (0x20000U 
                                                    & __PVT___GEN) 
                                                   | ((0x18000U 
                                                       & __PVT___GEN_0) 
                                                      | ((0x7800U 
                                                          & (IData)(__PVT___GEN_1)) 
                                                         | ((0x7f8U 
                                                             & (IData)(__PVT___GEN_2)) 
                                                            | (7U 
                                                               & ((IData)(__PVT___GEN_2) 
                                                                  | ((4U 
                                                                      & (vlSelf->__PVT__rx_a 
                                                                         >> 0x11U)) 
                                                                     | ((2U 
                                                                         & (__PVT___GEN 
                                                                            >> 0x10U)) 
                                                                        | (1U 
                                                                           & (__PVT___GEN_0 
                                                                              >> 0x10U)))))))))));
    vlSelf->__PVT__mask_1 = ((0x40000U & (vlSelf->__PVT__rx_b 
                                          >> 1U)) | 
                             ((0x20000U & __PVT___GEN_3) 
                              | ((0x18000U & __PVT___GEN_4) 
                                 | ((0x7800U & (IData)(__PVT___GEN_5)) 
                                    | ((0x7f8U & (IData)(__PVT___GEN_6)) 
                                       | (7U & ((IData)(__PVT___GEN_6) 
                                                | ((4U 
                                                    & (vlSelf->__PVT__rx_b 
                                                       >> 0x11U)) 
                                                   | ((2U 
                                                       & (__PVT___GEN_3 
                                                          >> 0x10U)) 
                                                      | (1U 
                                                         & (__PVT___GEN_4 
                                                            >> 0x10U)))))))))));
    vlSelf->__PVT__mask_2 = ((0x40000U & (vlSelf->__PVT__rx_c 
                                          >> 1U)) | 
                             ((0x20000U & __PVT___GEN_7) 
                              | ((0x18000U & __PVT___GEN_8) 
                                 | ((0x7800U & (IData)(__PVT___GEN_9)) 
                                    | ((0x7f8U & (IData)(__PVT___GEN_10)) 
                                       | (7U & ((IData)(__PVT___GEN_10) 
                                                | ((4U 
                                                    & (vlSelf->__PVT__rx_c 
                                                       >> 0x11U)) 
                                                   | ((2U 
                                                       & (__PVT___GEN_7 
                                                          >> 0x10U)) 
                                                      | (1U 
                                                         & (__PVT___GEN_8 
                                                            >> 0x10U)))))))))));
    vlSelf->__PVT__mask_3 = ((0x40000U & (vlSelf->__PVT__rx_d 
                                          >> 1U)) | 
                             ((0x20000U & __PVT___GEN_11) 
                              | ((0x18000U & __PVT___GEN_12) 
                                 | ((0x7800U & (IData)(__PVT___GEN_13)) 
                                    | ((0x7f8U & (IData)(__PVT___GEN_14)) 
                                       | (7U & ((IData)(__PVT___GEN_14) 
                                                | ((4U 
                                                    & (vlSelf->__PVT__rx_d 
                                                       >> 0x11U)) 
                                                   | ((2U 
                                                       & (__PVT___GEN_11 
                                                          >> 0x10U)) 
                                                      | (1U 
                                                         & (__PVT___GEN_12 
                                                            >> 0x10U)))))))))));
    vlSelf->__PVT__mask_4 = ((0x40000U & (vlSelf->__PVT__rx_e 
                                          >> 1U)) | 
                             ((0x20000U & __PVT___GEN_15) 
                              | ((0x18000U & __PVT___GEN_16) 
                                 | ((0x7800U & (IData)(__PVT___GEN_17)) 
                                    | ((0x7f8U & (IData)(__PVT___GEN_18)) 
                                       | (7U & ((IData)(__PVT___GEN_18) 
                                                | ((4U 
                                                    & (vlSelf->__PVT__rx_e 
                                                       >> 0x11U)) 
                                                   | ((2U 
                                                       & (__PVT___GEN_15 
                                                          >> 0x10U)) 
                                                      | (1U 
                                                         & (__PVT___GEN_16 
                                                            >> 0x10U)))))))))));
    __PVT___GEN_20 = (0x1ffU & ((IData)(__PVT___GEN_19) 
                                | ((0x100U & ((IData)(__PVT___readys_filter_T_1) 
                                              << 3U)) 
                                   | (0xffU & ((IData)(__PVT___GEN_19) 
                                               >> 2U)))));
    vlSelf->__PVT__msbOH = (0xfffffU & (~ ((0x80000U 
                                            & ((~ (vlSelf->__PVT__rx_a 
                                                   >> 0x13U)) 
                                               << 0x13U)) 
                                           | (0x7ffffU 
                                              & ((~ vlSelf->__PVT__rx_a) 
                                                 | vlSelf->__PVT__mask)))));
    vlSelf->__PVT__msbOH_1 = (0xfffffU & (~ ((0x80000U 
                                              & ((~ 
                                                  (vlSelf->__PVT__rx_b 
                                                   >> 0x13U)) 
                                                 << 0x13U)) 
                                             | (0x7ffffU 
                                                & ((~ vlSelf->__PVT__rx_b) 
                                                   | vlSelf->__PVT__mask_1)))));
    vlSelf->__PVT__msbOH_2 = (0xfffffU & (~ ((0x80000U 
                                              & ((~ 
                                                  (vlSelf->__PVT__rx_c 
                                                   >> 0x13U)) 
                                                 << 0x13U)) 
                                             | (0x7ffffU 
                                                & ((~ vlSelf->__PVT__rx_c) 
                                                   | vlSelf->__PVT__mask_2)))));
    vlSelf->__PVT__msbOH_3 = (0xfffffU & (~ ((0x80000U 
                                              & ((~ 
                                                  (vlSelf->__PVT__rx_d 
                                                   >> 0x13U)) 
                                                 << 0x13U)) 
                                             | (0x7ffffU 
                                                & ((~ vlSelf->__PVT__rx_d) 
                                                   | vlSelf->__PVT__mask_3)))));
    vlSelf->__PVT__msbOH_4 = (0xfffffU & (~ ((0x80000U 
                                              & ((~ 
                                                  (vlSelf->__PVT__rx_e 
                                                   >> 0x13U)) 
                                                 << 0x13U)) 
                                             | (0x7ffffU 
                                                & ((~ vlSelf->__PVT__rx_e) 
                                                   | vlSelf->__PVT__mask_4)))));
    vlSelf->__PVT__readys_unready = (((0x400U & ((IData)(__PVT___readys_filter_T_1) 
                                                 << 5U)) 
                                      | ((0x200U & (IData)(__PVT___GEN_19)) 
                                         | ((0x180U 
                                             & (IData)(__PVT___GEN_20)) 
                                            | (0x7fU 
                                               & ((IData)(__PVT___GEN_20) 
                                                  | ((0x40U 
                                                      & ((IData)(__PVT___readys_filter_T_1) 
                                                         << 1U)) 
                                                     | ((0x20U 
                                                         & ((IData)(__PVT___GEN_19) 
                                                            >> 4U)) 
                                                        | (0x1fU 
                                                           & ((IData)(__PVT___GEN_20) 
                                                              >> 4U))))))))) 
                                     | ((IData)(vlSelf->__PVT__readys_mask) 
                                        << 6U));
    vlSelf->__PVT___msb_T_2 = (0x7fffU & ((0xfU & (vlSelf->__PVT__msbOH 
                                                   >> 0x10U)) 
                                          | vlSelf->__PVT__msbOH));
    vlSelf->__PVT___msb_T_15 = (0x7fffU & ((0xfU & 
                                            (vlSelf->__PVT__msbOH_1 
                                             >> 0x10U)) 
                                           | vlSelf->__PVT__msbOH_1));
    vlSelf->__PVT___msb_T_28 = (0x7fffU & ((0xfU & 
                                            (vlSelf->__PVT__msbOH_2 
                                             >> 0x10U)) 
                                           | vlSelf->__PVT__msbOH_2));
    vlSelf->__PVT___msb_T_41 = (0x7fffU & ((0xfU & 
                                            (vlSelf->__PVT__msbOH_3 
                                             >> 0x10U)) 
                                           | vlSelf->__PVT__msbOH_3));
    vlSelf->__PVT___msb_T_54 = (0x7fffU & ((0xfU & 
                                            (vlSelf->__PVT__msbOH_4 
                                             >> 0x10U)) 
                                           | vlSelf->__PVT__msbOH_4));
    vlSelf->__PVT___readys_readys_T_2 = (0x3fU & (((IData)(vlSelf->__PVT__readys_unready) 
                                                   >> 6U) 
                                                  & (IData)(vlSelf->__PVT__readys_unready)));
    vlSelf->__PVT___msb_T_4 = (0x7fU & (((IData)(vlSelf->__PVT___msb_T_2) 
                                         >> 8U) | (IData)(vlSelf->__PVT___msb_T_2)));
    vlSelf->__PVT___msb_T_17 = (0x7fU & (((IData)(vlSelf->__PVT___msb_T_15) 
                                          >> 8U) | (IData)(vlSelf->__PVT___msb_T_15)));
    vlSelf->__PVT___msb_T_30 = (0x7fU & (((IData)(vlSelf->__PVT___msb_T_28) 
                                          >> 8U) | (IData)(vlSelf->__PVT___msb_T_28)));
    vlSelf->__PVT___msb_T_43 = (0x7fU & (((IData)(vlSelf->__PVT___msb_T_41) 
                                          >> 8U) | (IData)(vlSelf->__PVT___msb_T_41)));
    vlSelf->__PVT___msb_T_56 = (0x7fU & (((IData)(vlSelf->__PVT___msb_T_54) 
                                          >> 8U) | (IData)(vlSelf->__PVT___msb_T_54)));
    vlSelf->__PVT__winner = ((~ (IData)(vlSelf->__PVT___readys_readys_T_2)) 
                             & (IData)(vlSelf->__PVT__requests));
    if (vlSelf->__PVT__first) {
        vlSelf->__PVT__send = vlSelf->__PVT__rxQ__DOT__valid_0;
        vlSelf->__PVT__allowed = (0x3fU & (~ (IData)(vlSelf->__PVT___readys_readys_T_2)));
        vlSelf->__PVT__grant = vlSelf->__PVT__winner;
    } else {
        vlSelf->__PVT__send = (0U != ((IData)(vlSelf->__PVT__state) 
                                      & (IData)(vlSelf->__PVT__requests)));
        vlSelf->__PVT__allowed = (0x3fU & (IData)(vlSelf->__PVT__state));
        vlSelf->__PVT__grant = vlSelf->__PVT__state;
    }
    vlSelf->__PVT___msb_T_6 = (7U & (((IData)(vlSelf->__PVT___msb_T_4) 
                                      >> 4U) | (IData)(vlSelf->__PVT___msb_T_4)));
    vlSelf->__PVT___msb_T_19 = (7U & (((IData)(vlSelf->__PVT___msb_T_17) 
                                       >> 4U) | (IData)(vlSelf->__PVT___msb_T_17)));
    vlSelf->__PVT___msb_T_32 = (7U & (((IData)(vlSelf->__PVT___msb_T_30) 
                                       >> 4U) | (IData)(vlSelf->__PVT___msb_T_30)));
    vlSelf->__PVT___msb_T_45 = (7U & (((IData)(vlSelf->__PVT___msb_T_43) 
                                       >> 4U) | (IData)(vlSelf->__PVT___msb_T_43)));
    vlSelf->__PVT___msb_T_58 = (7U & (((IData)(vlSelf->__PVT___msb_T_56) 
                                       >> 4U) | (IData)(vlSelf->__PVT___msb_T_56)));
    vlSelf->__Vcellinp__rxQ__io_deq_ready = (((IData)(vlSelf->__PVT__allowed) 
                                              >> 5U) 
                                             & (IData)(vlSelf->__PVT__allowReturn));
    vlSelf->__Vcellinp__rxQ__io_enq_bits_data = (5U 
                                                 | (((IData)(
                                                             (0U 
                                                              != 
                                                              (0x1fU 
                                                               & (vlSelf->__PVT__msbOH_4 
                                                                  >> 0xfU)))) 
                                                     << 0x1fU) 
                                                    | (((IData)(
                                                                (0U 
                                                                 != 
                                                                 (0xffU 
                                                                  & ((IData)(vlSelf->__PVT___msb_T_54) 
                                                                     >> 7U)))) 
                                                        << 0x1eU) 
                                                       | (((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0xfU 
                                                                     & ((IData)(vlSelf->__PVT___msb_T_56) 
                                                                        >> 3U)))) 
                                                           << 0x1dU) 
                                                          | (((IData)(
                                                                      (0U 
                                                                       != 
                                                                       (3U 
                                                                        & ((IData)(vlSelf->__PVT___msb_T_58) 
                                                                           >> 1U)))) 
                                                              << 0x1cU) 
                                                             | (((IData)(
                                                                         (0U 
                                                                          != 
                                                                          (5U 
                                                                           & (IData)(vlSelf->__PVT___msb_T_58)))) 
                                                                 << 0x1bU) 
                                                                | (((IData)(
                                                                            (0U 
                                                                             != 
                                                                             (0x1fU 
                                                                              & (vlSelf->__PVT__msbOH_3 
                                                                                >> 0xfU)))) 
                                                                    << 0x1aU) 
                                                                   | (((IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0xffU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_41) 
                                                                                >> 7U)))) 
                                                                       << 0x19U) 
                                                                      | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xfU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_43) 
                                                                                >> 3U)))) 
                                                                          << 0x18U) 
                                                                         | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (3U 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_45) 
                                                                                >> 1U)))) 
                                                                             << 0x17U) 
                                                                            | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (5U 
                                                                                & (IData)(vlSelf->__PVT___msb_T_45)))) 
                                                                                << 0x16U) 
                                                                               | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__msbOH_2 
                                                                                >> 0xfU)))) 
                                                                                << 0x15U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xffU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_28) 
                                                                                >> 7U)))) 
                                                                                << 0x14U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xfU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_30) 
                                                                                >> 3U)))) 
                                                                                << 0x13U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (3U 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_32) 
                                                                                >> 1U)))) 
                                                                                << 0x12U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (5U 
                                                                                & (IData)(vlSelf->__PVT___msb_T_32)))) 
                                                                                << 0x11U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__msbOH_1 
                                                                                >> 0xfU)))) 
                                                                                << 0x10U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xffU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_15) 
                                                                                >> 7U)))) 
                                                                                << 0xfU) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xfU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_17) 
                                                                                >> 3U)))) 
                                                                                << 0xeU) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (3U 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_19) 
                                                                                >> 1U)))) 
                                                                                << 0xdU) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (5U 
                                                                                & (IData)(vlSelf->__PVT___msb_T_19)))) 
                                                                                << 0xcU) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__msbOH 
                                                                                >> 0xfU)))) 
                                                                                << 0xbU) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xffU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_2) 
                                                                                >> 7U)))) 
                                                                                << 0xaU) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xfU 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_4) 
                                                                                >> 3U)))) 
                                                                                << 9U) 
                                                                                | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (3U 
                                                                                & ((IData)(vlSelf->__PVT___msb_T_6) 
                                                                                >> 1U)))) 
                                                                                << 8U) 
                                                                                | ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (5U 
                                                                                & (IData)(vlSelf->__PVT___msb_T_6)))) 
                                                                                << 7U))))))))))))))))))))))))));
}
