// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_AsyncQueueSink_UInt32.h"
#include "VysyxSoCFull__Syms.h"

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__0\n"); );
    // Body
    vlSelf->__Vcellinp__sink_valid_0__reset = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) 
                                               | (IData)(vlSymsp->TOP.reset));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__0\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h55a83eeb__0;
    // Body
    if (vlSelf->__PVT__valid) {
        __Vtemp_h55a83eeb__0[0U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_0;
        __Vtemp_h55a83eeb__0[1U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_1;
        __Vtemp_h55a83eeb__0[2U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_2;
        __Vtemp_h55a83eeb__0[3U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_3;
        __Vtemp_h55a83eeb__0[4U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_4;
        __Vtemp_h55a83eeb__0[5U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_5;
        __Vtemp_h55a83eeb__0[6U] = (IData)((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_7)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_6))));
        __Vtemp_h55a83eeb__0[7U] = (IData)(((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_7)) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_6))) 
                                            >> 0x20U));
        vlSelf->__PVT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
            = (((0U == (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                  << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                            << 7U))))
                 ? 0U : (__Vtemp_h55a83eeb__0[(((IData)(0x1fU) 
                                                + (0xffU 
                                                   & (((IData)(vlSelf->__PVT___index_T) 
                                                       << 5U) 
                                                      ^ 
                                                      ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                       << 7U)))) 
                                               >> 5U)] 
                         << ((IData)(0x20U) - (0x1fU 
                                               & (((IData)(vlSelf->__PVT___index_T) 
                                                   << 5U) 
                                                  ^ 
                                                  ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                   << 7U)))))) 
               | (__Vtemp_h55a83eeb__0[(7U & ((0x7ffffffU 
                                               & (IData)(vlSelf->__PVT___index_T)) 
                                              ^ (0x7fffffcU 
                                                 & ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                    << 2U))))] 
                  >> (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                          << 7U)))));
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__1(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__1\n"); );
    // Body
    vlSelf->__PVT__valid_reg = ((~ (IData)(vlSymsp->TOP.reset)) 
                                & (IData)(vlSelf->__PVT__valid));
    vlSelf->__PVT__ridx_ridx_bin = ((IData)(vlSymsp->TOP.reset)
                                     ? 0U : ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                              ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                              : 0U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__widx_gray) 
                                              >> 3U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__widx_gray) 
                  >> 2U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__widx_gray) 
                  >> 1U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__widx_gray)));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__2(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__2\n"); );
    // Body
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source.__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__3(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__3\n"); );
    // Body
    vlSelf->__PVT__ridx_gray = ((IData)(vlSymsp->TOP.reset)
                                 ? 0U : (IData)(vlSelf->__PVT__ridx));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__0\n"); );
    // Body
    vlSelf->__VdfgTmp_h53fdc2be__0 = (0xfU & ((IData)(vlSelf->__PVT__ridx_ridx_bin) 
                                              + ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA__DOT__io_q_ready_0) 
                                                 & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT___index_T = (7U & (((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                       ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                       : 0U) ^ ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                 ? 
                                                ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                                 >> 1U)
                                                 : 0U)));
    vlSelf->__VdfgTmp_h4436d783__0 = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                      & ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                         >> 3U));
    vlSelf->__PVT__ridx = (((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                            << 3U) | (IData)(vlSelf->__PVT___index_T));
    vlSelf->__PVT__valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & ((IData)(vlSelf->__PVT__ridx) 
                               != (((IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                    << 3U) | (((IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                               << 2U) 
                                              | (((IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                  << 1U) 
                                                 | (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink__0\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h47280742__0;
    // Body
    if (vlSelf->__PVT__valid) {
        __Vtemp_h47280742__0[0U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_0;
        __Vtemp_h47280742__0[1U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_1;
        __Vtemp_h47280742__0[2U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_2;
        __Vtemp_h47280742__0[3U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_3;
        __Vtemp_h47280742__0[4U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_4;
        __Vtemp_h47280742__0[5U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_5;
        __Vtemp_h47280742__0[6U] = (IData)((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_7)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_6))));
        __Vtemp_h47280742__0[7U] = (IData)(((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_7)) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_6))) 
                                            >> 0x20U));
        vlSelf->__PVT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
            = (((0U == (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                  << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                            << 7U))))
                 ? 0U : (__Vtemp_h47280742__0[(((IData)(0x1fU) 
                                                + (0xffU 
                                                   & (((IData)(vlSelf->__PVT___index_T) 
                                                       << 5U) 
                                                      ^ 
                                                      ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                       << 7U)))) 
                                               >> 5U)] 
                         << ((IData)(0x20U) - (0x1fU 
                                               & (((IData)(vlSelf->__PVT___index_T) 
                                                   << 5U) 
                                                  ^ 
                                                  ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                   << 7U)))))) 
               | (__Vtemp_h47280742__0[(7U & ((0x7ffffffU 
                                               & (IData)(vlSelf->__PVT___index_T)) 
                                              ^ (0x7fffffcU 
                                                 & ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                    << 2U))))] 
                  >> (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                          << 7U)))));
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink__1(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink__1\n"); );
    // Body
    vlSelf->__PVT__valid_reg = ((~ (IData)(vlSymsp->TOP.reset)) 
                                & (IData)(vlSelf->__PVT__valid));
    vlSelf->__PVT__ridx_ridx_bin = ((IData)(vlSymsp->TOP.reset)
                                     ? 0U : ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                              ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                              : 0U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__widx_gray) 
                                              >> 3U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__widx_gray) 
                  >> 2U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__widx_gray) 
                  >> 1U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__widx_gray)));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink__0\n"); );
    // Body
    vlSelf->__VdfgTmp_h53fdc2be__0 = (0xfU & ((IData)(vlSelf->__PVT__ridx_ridx_bin) 
                                              + ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB__DOT__io_q_ready_0) 
                                                 & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT___index_T = (7U & (((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                       ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                       : 0U) ^ ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                 ? 
                                                ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                                 >> 1U)
                                                 : 0U)));
    vlSelf->__VdfgTmp_h4436d783__0 = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                      & ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                         >> 3U));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink__2(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink__2\n"); );
    // Body
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource.__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink__0\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h6551d239__0;
    // Body
    if (vlSelf->__PVT__valid) {
        __Vtemp_h6551d239__0[0U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_0;
        __Vtemp_h6551d239__0[1U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_1;
        __Vtemp_h6551d239__0[2U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_2;
        __Vtemp_h6551d239__0[3U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_3;
        __Vtemp_h6551d239__0[4U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_4;
        __Vtemp_h6551d239__0[5U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_5;
        __Vtemp_h6551d239__0[6U] = (IData)((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_7)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_6))));
        __Vtemp_h6551d239__0[7U] = (IData)(((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_7)) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_6))) 
                                            >> 0x20U));
        vlSelf->__PVT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
            = (((0U == (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                  << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                            << 7U))))
                 ? 0U : (__Vtemp_h6551d239__0[(((IData)(0x1fU) 
                                                + (0xffU 
                                                   & (((IData)(vlSelf->__PVT___index_T) 
                                                       << 5U) 
                                                      ^ 
                                                      ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                       << 7U)))) 
                                               >> 5U)] 
                         << ((IData)(0x20U) - (0x1fU 
                                               & (((IData)(vlSelf->__PVT___index_T) 
                                                   << 5U) 
                                                  ^ 
                                                  ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                   << 7U)))))) 
               | (__Vtemp_h6551d239__0[(7U & ((0x7ffffffU 
                                               & (IData)(vlSelf->__PVT___index_T)) 
                                              ^ (0x7fffffcU 
                                                 & ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                    << 2U))))] 
                  >> (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                          << 7U)))));
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink__1(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink__1\n"); );
    // Body
    vlSelf->__PVT__valid_reg = ((~ (IData)(vlSymsp->TOP.reset)) 
                                & (IData)(vlSelf->__PVT__valid));
    vlSelf->__PVT__ridx_ridx_bin = ((IData)(vlSymsp->TOP.reset)
                                     ? 0U : ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                              ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                              : 0U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__widx_gray) 
                                              >> 3U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__widx_gray) 
                  >> 2U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__widx_gray) 
                  >> 1U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__widx_gray)));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink__0\n"); );
    // Body
    vlSelf->__VdfgTmp_h53fdc2be__0 = (0xfU & ((IData)(vlSelf->__PVT__ridx_ridx_bin) 
                                              + ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC__DOT__io_q_ready_0) 
                                                 & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT___index_T = (7U & (((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                       ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                       : 0U) ^ ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                 ? 
                                                ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                                 >> 1U)
                                                 : 0U)));
    vlSelf->__VdfgTmp_h4436d783__0 = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                      & ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                         >> 3U));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink__2(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink__2\n"); );
    // Body
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source.__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD_io_q_sink__1(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD_io_q_sink__1\n"); );
    // Body
    vlSelf->__VdfgTmp_h53fdc2be__0 = (0xfU & ((IData)(vlSelf->__PVT__ridx_ridx_bin) 
                                              + ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD__DOT__io_q_ready_0) 
                                                 & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT___index_T = (7U & (((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                       ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                       : 0U) ^ ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                 ? 
                                                ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                                 >> 1U)
                                                 : 0U)));
    vlSelf->__VdfgTmp_h4436d783__0 = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                      & ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                         >> 3U));
    vlSelf->__PVT__ridx = (((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                            << 3U) | (IData)(vlSelf->__PVT___index_T));
    vlSelf->__PVT__valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & ((IData)(vlSelf->__PVT__ridx) 
                               != (((IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                    << 3U) | (((IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                               << 2U) 
                                              | (((IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                  << 1U) 
                                                 | (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD_io_q_sink__0\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h2db61f49__0;
    // Body
    if (vlSelf->__PVT__valid) {
        __Vtemp_h2db61f49__0[0U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_0;
        __Vtemp_h2db61f49__0[1U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_1;
        __Vtemp_h2db61f49__0[2U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_2;
        __Vtemp_h2db61f49__0[3U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_3;
        __Vtemp_h2db61f49__0[4U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_4;
        __Vtemp_h2db61f49__0[5U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_5;
        __Vtemp_h2db61f49__0[6U] = (IData)((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_7)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_6))));
        __Vtemp_h2db61f49__0[7U] = (IData)(((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_7)) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_6))) 
                                            >> 0x20U));
        vlSelf->__PVT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
            = (((0U == (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                  << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                            << 7U))))
                 ? 0U : (__Vtemp_h2db61f49__0[(((IData)(0x1fU) 
                                                + (0xffU 
                                                   & (((IData)(vlSelf->__PVT___index_T) 
                                                       << 5U) 
                                                      ^ 
                                                      ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                       << 7U)))) 
                                               >> 5U)] 
                         << ((IData)(0x20U) - (0x1fU 
                                               & (((IData)(vlSelf->__PVT___index_T) 
                                                   << 5U) 
                                                  ^ 
                                                  ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                   << 7U)))))) 
               | (__Vtemp_h2db61f49__0[(7U & ((0x7ffffffU 
                                               & (IData)(vlSelf->__PVT___index_T)) 
                                              ^ (0x7fffffcU 
                                                 & ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                    << 2U))))] 
                  >> (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                          << 7U)))));
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD_io_q_sink__1(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD_io_q_sink__1\n"); );
    // Body
    vlSelf->__PVT__valid_reg = ((~ (IData)(vlSymsp->TOP.reset)) 
                                & (IData)(vlSelf->__PVT__valid));
    vlSelf->__PVT__ridx_ridx_bin = ((IData)(vlSymsp->TOP.reset)
                                     ? 0U : ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                              ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                              : 0U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__widx_gray) 
                                              >> 3U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__widx_gray) 
                  >> 2U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__widx_gray) 
                  >> 1U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__widx_gray)));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD_io_q_sink__2(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD_io_q_sink__2\n"); );
    // Body
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source.__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink__0\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h528ae9df__0;
    // Body
    if (vlSelf->__PVT__valid) {
        __Vtemp_h528ae9df__0[0U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_0;
        __Vtemp_h528ae9df__0[1U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_1;
        __Vtemp_h528ae9df__0[2U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_2;
        __Vtemp_h528ae9df__0[3U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_3;
        __Vtemp_h528ae9df__0[4U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_4;
        __Vtemp_h528ae9df__0[5U] = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_5;
        __Vtemp_h528ae9df__0[6U] = (IData)((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_7)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_6))));
        __Vtemp_h528ae9df__0[7U] = (IData)(((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_7)) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_6))) 
                                            >> 0x20U));
        vlSelf->__PVT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
            = (((0U == (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                  << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                            << 7U))))
                 ? 0U : (__Vtemp_h528ae9df__0[(((IData)(0x1fU) 
                                                + (0xffU 
                                                   & (((IData)(vlSelf->__PVT___index_T) 
                                                       << 5U) 
                                                      ^ 
                                                      ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                       << 7U)))) 
                                               >> 5U)] 
                         << ((IData)(0x20U) - (0x1fU 
                                               & (((IData)(vlSelf->__PVT___index_T) 
                                                   << 5U) 
                                                  ^ 
                                                  ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                   << 7U)))))) 
               | (__Vtemp_h528ae9df__0[(7U & ((0x7ffffffU 
                                               & (IData)(vlSelf->__PVT___index_T)) 
                                              ^ (0x7fffffcU 
                                                 & ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                    << 2U))))] 
                  >> (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                          << 7U)))));
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink__1(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink__1\n"); );
    // Body
    vlSelf->__PVT__valid_reg = ((~ (IData)(vlSymsp->TOP.reset)) 
                                & (IData)(vlSelf->__PVT__valid));
    vlSelf->__PVT__ridx_ridx_bin = ((IData)(vlSymsp->TOP.reset)
                                     ? 0U : ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                              ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                              : 0U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__widx_gray) 
                                              >> 3U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__widx_gray) 
                  >> 2U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__widx_gray) 
                  >> 1U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__widx_gray)));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink__0\n"); );
    // Body
    vlSelf->__VdfgTmp_h53fdc2be__0 = (0xfU & ((IData)(vlSelf->__PVT__ridx_ridx_bin) 
                                              + ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__mbypass__DOT__nodeIn_1_e_ready) 
                                                 & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT___index_T = (7U & (((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                       ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                       : 0U) ^ ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                 ? 
                                                ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                                 >> 1U)
                                                 : 0U)));
    vlSelf->__VdfgTmp_h4436d783__0 = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                      & ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                         >> 3U));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink__2(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink__2\n"); );
    // Body
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source.__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___ico_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___ico_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink__0\n"); );
    // Body
    vlSelf->__Vcellinp__sink_valid_0__reset = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) 
                                               | (IData)(vlSymsp->TOP.reset));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink__0\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h5e09b441__0;
    // Body
    if (vlSelf->__PVT__valid) {
        __Vtemp_h5e09b441__0[0U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_0;
        __Vtemp_h5e09b441__0[1U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_1;
        __Vtemp_h5e09b441__0[2U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_2;
        __Vtemp_h5e09b441__0[3U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_3;
        __Vtemp_h5e09b441__0[4U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_4;
        __Vtemp_h5e09b441__0[5U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_5;
        __Vtemp_h5e09b441__0[6U] = (IData)((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_7)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_6))));
        __Vtemp_h5e09b441__0[7U] = (IData)(((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_7)) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__mem_6))) 
                                            >> 0x20U));
        vlSelf->__PVT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
            = (((0U == (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                  << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                            << 7U))))
                 ? 0U : (__Vtemp_h5e09b441__0[(((IData)(0x1fU) 
                                                + (0xffU 
                                                   & (((IData)(vlSelf->__PVT___index_T) 
                                                       << 5U) 
                                                      ^ 
                                                      ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                       << 7U)))) 
                                               >> 5U)] 
                         << ((IData)(0x20U) - (0x1fU 
                                               & (((IData)(vlSelf->__PVT___index_T) 
                                                   << 5U) 
                                                  ^ 
                                                  ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                   << 7U)))))) 
               | (__Vtemp_h5e09b441__0[(7U & ((0x7ffffffU 
                                               & (IData)(vlSelf->__PVT___index_T)) 
                                              ^ (0x7fffffcU 
                                                 & ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                    << 2U))))] 
                  >> (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                          << 7U)))));
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink__1(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink__1\n"); );
    // Body
    vlSelf->__PVT__valid_reg = ((~ (IData)(vlSymsp->TOP.reset)) 
                                & (IData)(vlSelf->__PVT__valid));
    vlSelf->__PVT__ridx_ridx_bin = ((IData)(vlSymsp->TOP.reset)
                                     ? 0U : ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                              ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                              : 0U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__widx_gray) 
                                              >> 3U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__widx_gray) 
                  >> 2U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__widx_gray) 
                  >> 1U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__widx_gray)));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink__2(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink__2\n"); );
    // Body
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source.__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink__0\n"); );
    // Body
    vlSelf->__VdfgTmp_h53fdc2be__0 = (0xfU & ((IData)(vlSelf->__PVT__ridx_ridx_bin) 
                                              + ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA__DOT__io_q_ready_0) 
                                                 & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT___index_T = (7U & (((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                       ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                       : 0U) ^ ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                 ? 
                                                ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                                 >> 1U)
                                                 : 0U)));
    vlSelf->__VdfgTmp_h4436d783__0 = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                      & ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                         >> 3U));
    vlSelf->__PVT__ridx = (((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                            << 3U) | (IData)(vlSelf->__PVT___index_T));
    vlSelf->__PVT__valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & ((IData)(vlSelf->__PVT__ridx) 
                               != (((IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                    << 3U) | (((IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                               << 2U) 
                                              | (((IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                  << 1U) 
                                                 | (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink__0\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_hed2b1730__0;
    // Body
    if (vlSelf->__PVT__valid) {
        __Vtemp_hed2b1730__0[0U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_0;
        __Vtemp_hed2b1730__0[1U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_1;
        __Vtemp_hed2b1730__0[2U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_2;
        __Vtemp_hed2b1730__0[3U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_3;
        __Vtemp_hed2b1730__0[4U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_4;
        __Vtemp_hed2b1730__0[5U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_5;
        __Vtemp_hed2b1730__0[6U] = (IData)((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_7)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_6))));
        __Vtemp_hed2b1730__0[7U] = (IData)(((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_7)) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__mem_6))) 
                                            >> 0x20U));
        vlSelf->__PVT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
            = (((0U == (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                  << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                            << 7U))))
                 ? 0U : (__Vtemp_hed2b1730__0[(((IData)(0x1fU) 
                                                + (0xffU 
                                                   & (((IData)(vlSelf->__PVT___index_T) 
                                                       << 5U) 
                                                      ^ 
                                                      ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                       << 7U)))) 
                                               >> 5U)] 
                         << ((IData)(0x20U) - (0x1fU 
                                               & (((IData)(vlSelf->__PVT___index_T) 
                                                   << 5U) 
                                                  ^ 
                                                  ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                   << 7U)))))) 
               | (__Vtemp_hed2b1730__0[(7U & ((0x7ffffffU 
                                               & (IData)(vlSelf->__PVT___index_T)) 
                                              ^ (0x7fffffcU 
                                                 & ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                    << 2U))))] 
                  >> (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                          << 7U)))));
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink__1(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink__1\n"); );
    // Body
    vlSelf->__PVT__valid_reg = ((~ (IData)(vlSymsp->TOP.reset)) 
                                & (IData)(vlSelf->__PVT__valid));
    vlSelf->__PVT__ridx_ridx_bin = ((IData)(vlSymsp->TOP.reset)
                                     ? 0U : ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                              ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                              : 0U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__widx_gray) 
                                              >> 3U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__widx_gray) 
                  >> 2U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__widx_gray) 
                  >> 1U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__widx_gray)));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink__0\n"); );
    // Body
    vlSelf->__VdfgTmp_h53fdc2be__0 = (0xfU & ((IData)(vlSelf->__PVT__ridx_ridx_bin) 
                                              + ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB__DOT__io_q_ready_0) 
                                                 & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT___index_T = (7U & (((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                       ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                       : 0U) ^ ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                 ? 
                                                ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                                 >> 1U)
                                                 : 0U)));
    vlSelf->__VdfgTmp_h4436d783__0 = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                      & ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                         >> 3U));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink__2(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink__2\n"); );
    // Body
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource.__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink__0\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h7c5a0777__0;
    // Body
    if (vlSelf->__PVT__valid) {
        __Vtemp_h7c5a0777__0[0U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_0;
        __Vtemp_h7c5a0777__0[1U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_1;
        __Vtemp_h7c5a0777__0[2U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_2;
        __Vtemp_h7c5a0777__0[3U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_3;
        __Vtemp_h7c5a0777__0[4U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_4;
        __Vtemp_h7c5a0777__0[5U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_5;
        __Vtemp_h7c5a0777__0[6U] = (IData)((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_7)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_6))));
        __Vtemp_h7c5a0777__0[7U] = (IData)(((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_7)) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__mem_6))) 
                                            >> 0x20U));
        vlSelf->__PVT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
            = (((0U == (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                  << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                            << 7U))))
                 ? 0U : (__Vtemp_h7c5a0777__0[(((IData)(0x1fU) 
                                                + (0xffU 
                                                   & (((IData)(vlSelf->__PVT___index_T) 
                                                       << 5U) 
                                                      ^ 
                                                      ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                       << 7U)))) 
                                               >> 5U)] 
                         << ((IData)(0x20U) - (0x1fU 
                                               & (((IData)(vlSelf->__PVT___index_T) 
                                                   << 5U) 
                                                  ^ 
                                                  ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                   << 7U)))))) 
               | (__Vtemp_h7c5a0777__0[(7U & ((0x7ffffffU 
                                               & (IData)(vlSelf->__PVT___index_T)) 
                                              ^ (0x7fffffcU 
                                                 & ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                    << 2U))))] 
                  >> (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                          << 7U)))));
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink__1(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink__1\n"); );
    // Body
    vlSelf->__PVT__valid_reg = ((~ (IData)(vlSymsp->TOP.reset)) 
                                & (IData)(vlSelf->__PVT__valid));
    vlSelf->__PVT__ridx_ridx_bin = ((IData)(vlSymsp->TOP.reset)
                                     ? 0U : ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                              ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                              : 0U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__widx_gray) 
                                              >> 3U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__widx_gray) 
                  >> 2U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__widx_gray) 
                  >> 1U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__widx_gray)));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink__0\n"); );
    // Body
    vlSelf->__VdfgTmp_h53fdc2be__0 = (0xfU & ((IData)(vlSelf->__PVT__ridx_ridx_bin) 
                                              + ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC__DOT__io_q_ready_0) 
                                                 & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT___index_T = (7U & (((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                       ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                       : 0U) ^ ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                 ? 
                                                ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                                 >> 1U)
                                                 : 0U)));
    vlSelf->__VdfgTmp_h4436d783__0 = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                      & ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                         >> 3U));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink__2(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink__2\n"); );
    // Body
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source.__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD_io_q_sink__0\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h4c5f8146__0;
    // Body
    if (vlSelf->__PVT__valid) {
        __Vtemp_h4c5f8146__0[0U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_0;
        __Vtemp_h4c5f8146__0[1U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_1;
        __Vtemp_h4c5f8146__0[2U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_2;
        __Vtemp_h4c5f8146__0[3U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_3;
        __Vtemp_h4c5f8146__0[4U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_4;
        __Vtemp_h4c5f8146__0[5U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_5;
        __Vtemp_h4c5f8146__0[6U] = (IData)((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_7)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_6))));
        __Vtemp_h4c5f8146__0[7U] = (IData)(((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_7)) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__mem_6))) 
                                            >> 0x20U));
        vlSelf->__PVT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
            = (((0U == (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                  << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                            << 7U))))
                 ? 0U : (__Vtemp_h4c5f8146__0[(((IData)(0x1fU) 
                                                + (0xffU 
                                                   & (((IData)(vlSelf->__PVT___index_T) 
                                                       << 5U) 
                                                      ^ 
                                                      ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                       << 7U)))) 
                                               >> 5U)] 
                         << ((IData)(0x20U) - (0x1fU 
                                               & (((IData)(vlSelf->__PVT___index_T) 
                                                   << 5U) 
                                                  ^ 
                                                  ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                   << 7U)))))) 
               | (__Vtemp_h4c5f8146__0[(7U & ((0x7ffffffU 
                                               & (IData)(vlSelf->__PVT___index_T)) 
                                              ^ (0x7fffffcU 
                                                 & ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                    << 2U))))] 
                  >> (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                          << 7U)))));
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD_io_q_sink__1(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD_io_q_sink__1\n"); );
    // Body
    vlSelf->__PVT__valid_reg = ((~ (IData)(vlSymsp->TOP.reset)) 
                                & (IData)(vlSelf->__PVT__valid));
    vlSelf->__PVT__ridx_ridx_bin = ((IData)(vlSymsp->TOP.reset)
                                     ? 0U : ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                              ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                              : 0U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__widx_gray) 
                                              >> 3U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__widx_gray) 
                  >> 2U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__widx_gray) 
                  >> 1U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__widx_gray)));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD_io_q_sink__2(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD_io_q_sink__2\n"); );
    // Body
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source.__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD_io_q_sink__0\n"); );
    // Body
    vlSelf->__VdfgTmp_h53fdc2be__0 = (0xfU & ((IData)(vlSelf->__PVT__ridx_ridx_bin) 
                                              + ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD__DOT__io_q_ready_0) 
                                                 & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT___index_T = (7U & (((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                       ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                       : 0U) ^ ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                 ? 
                                                ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                                 >> 1U)
                                                 : 0U)));
    vlSelf->__VdfgTmp_h4436d783__0 = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                      & ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                         >> 3U));
    vlSelf->__PVT__ridx = (((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                            << 3U) | (IData)(vlSelf->__PVT___index_T));
    vlSelf->__PVT__valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & ((IData)(vlSelf->__PVT__ridx) 
                               != (((IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                    << 3U) | (((IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                               << 2U) 
                                              | (((IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                  << 1U) 
                                                 | (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink__0\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h1fbbc6cb__0;
    // Body
    if (vlSelf->__PVT__valid) {
        __Vtemp_h1fbbc6cb__0[0U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_0;
        __Vtemp_h1fbbc6cb__0[1U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_1;
        __Vtemp_h1fbbc6cb__0[2U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_2;
        __Vtemp_h1fbbc6cb__0[3U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_3;
        __Vtemp_h1fbbc6cb__0[4U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_4;
        __Vtemp_h1fbbc6cb__0[5U] = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_5;
        __Vtemp_h1fbbc6cb__0[6U] = (IData)((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_7)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_6))));
        __Vtemp_h1fbbc6cb__0[7U] = (IData)(((((QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_7)) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__mem_6))) 
                                            >> 0x20U));
        vlSelf->__PVT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
            = (((0U == (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                  << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                            << 7U))))
                 ? 0U : (__Vtemp_h1fbbc6cb__0[(((IData)(0x1fU) 
                                                + (0xffU 
                                                   & (((IData)(vlSelf->__PVT___index_T) 
                                                       << 5U) 
                                                      ^ 
                                                      ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                       << 7U)))) 
                                               >> 5U)] 
                         << ((IData)(0x20U) - (0x1fU 
                                               & (((IData)(vlSelf->__PVT___index_T) 
                                                   << 5U) 
                                                  ^ 
                                                  ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                   << 7U)))))) 
               | (__Vtemp_h1fbbc6cb__0[(7U & ((0x7ffffffU 
                                               & (IData)(vlSelf->__PVT___index_T)) 
                                              ^ (0x7fffffcU 
                                                 & ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                                    << 2U))))] 
                  >> (0x1fU & (((IData)(vlSelf->__PVT___index_T) 
                                << 5U) ^ ((IData)(vlSelf->__VdfgTmp_h4436d783__0) 
                                          << 7U)))));
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink__1(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink__1\n"); );
    // Body
    vlSelf->__PVT__valid_reg = ((~ (IData)(vlSymsp->TOP.reset)) 
                                & (IData)(vlSelf->__PVT__valid));
    vlSelf->__PVT__ridx_ridx_bin = ((IData)(vlSymsp->TOP.reset)
                                     ? 0U : ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                              ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                              : 0U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__widx_gray) 
                                              >> 3U));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__widx_gray) 
                  >> 2U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & 
                 ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__widx_gray) 
                  >> 1U)));
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__widx_gray)));
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.reset)) & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink__0\n"); );
    // Body
    vlSelf->__VdfgTmp_h53fdc2be__0 = (0xfU & ((IData)(vlSelf->__PVT__ridx_ridx_bin) 
                                              + ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__mbypass__DOT__nodeIn_1_e_ready) 
                                                 & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT___index_T = (7U & (((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                       ? (IData)(vlSelf->__VdfgTmp_h53fdc2be__0)
                                       : 0U) ^ ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                 ? 
                                                ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                                 >> 1U)
                                                 : 0U)));
    vlSelf->__VdfgTmp_h4436d783__0 = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                      & ((IData)(vlSelf->__VdfgTmp_h53fdc2be__0) 
                                         >> 3U));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink__2(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink__2\n"); );
    // Body
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_valid_0__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source.__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}
