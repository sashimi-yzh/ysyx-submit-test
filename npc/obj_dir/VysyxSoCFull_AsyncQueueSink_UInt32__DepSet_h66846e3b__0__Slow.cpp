// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_AsyncQueueSink_UInt32.h"
#include "VysyxSoCFull__Syms.h"

VL_ATTR_COLD void VysyxSoCFull_AsyncQueueSink_UInt32___eval_initial__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___eval_initial__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink\n"); );
    // Body
    if (vlSymsp->TOP.reset) {
        vlSelf->__PVT__ridx_ridx_bin = 0U;
        vlSelf->__PVT__valid_reg = 0U;
        vlSelf->__PVT__ridx_gray = 0U;
        vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 = 0U;
        vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 = 0U;
        vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 = 0U;
        vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 = 0U;
        vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 = 0U;
        vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 = 0U;
        vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 = 0U;
        vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 = 0U;
        vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 = 0U;
        vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
    if (vlSelf->__Vcellinp__sink_valid_0__reset) {
        vlSelf->__PVT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
}

VL_ATTR_COLD void VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink__0\n"); );
    // Body
    vlSelf->__Vcellinp__sink_valid_0__reset = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) 
                                               | (IData)(vlSymsp->TOP.reset));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
}

VL_ATTR_COLD void VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink__0\n"); );
    // Body
    vlSelf->__Vcellinp__sink_valid_0__reset = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) 
                                               | (IData)(vlSymsp->TOP.reset));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
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

VL_ATTR_COLD void VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink__0\n"); );
    // Body
    vlSelf->__Vcellinp__sink_valid_0__reset = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) 
                                               | (IData)(vlSymsp->TOP.reset));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
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

VL_ATTR_COLD void VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink__0\n"); );
    // Body
    vlSelf->__Vcellinp__sink_valid_0__reset = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) 
                                               | (IData)(vlSymsp->TOP.reset));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
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

VL_ATTR_COLD void VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink__0\n"); );
    // Body
    vlSelf->__Vcellinp__sink_valid_0__reset = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) 
                                               | (IData)(vlSymsp->TOP.reset));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
}

VL_ATTR_COLD void VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink__0\n"); );
    // Body
    vlSelf->__Vcellinp__sink_valid_0__reset = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) 
                                               | (IData)(vlSymsp->TOP.reset));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
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

VL_ATTR_COLD void VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink__0\n"); );
    // Body
    vlSelf->__Vcellinp__sink_valid_0__reset = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) 
                                               | (IData)(vlSymsp->TOP.reset));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
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

VL_ATTR_COLD void VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink__0(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink__0\n"); );
    // Body
    vlSelf->__Vcellinp__sink_valid_0__reset = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) 
                                               | (IData)(vlSymsp->TOP.reset));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__valid_reg));
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
