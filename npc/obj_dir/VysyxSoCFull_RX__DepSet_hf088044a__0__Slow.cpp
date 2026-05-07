// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_RX.h"
#include "VysyxSoCFull__Syms.h"

VL_ATTR_COLD void VysyxSoCFull_RX___eval_initial__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx(VysyxSoCFull_RX* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_RX___eval_initial__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx\n"); );
    // Body
    if (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        vlSelf->__PVT__io_txc_source__DOT__widx_widx_bin = 0U;
        vlSelf->__PVT__io_txc_source__DOT__ready_reg = 0U;
        vlSelf->__PVT__io_txc_source__DOT__widx_gray = 0U;
        vlSelf->__PVT__io_txc_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__widx_widx_bin = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__ready_reg = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__widx_gray = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
    if (vlSelf->io_txc_source__DOT____Vcellinp__sink_extend__reset) {
        vlSelf->__PVT__io_txc_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
}

VL_ATTR_COLD void VysyxSoCFull_RX___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__0(VysyxSoCFull_RX* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_RX___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__0\n"); );
    // Body
    vlSelf->__PVT__first = (0U == (IData)(vlSelf->__PVT__first_count));
    vlSelf->io_txc_source__DOT____Vcellinp__sink_extend__reset 
        = ((IData)(vlSymsp->TOP.reset) | (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0));
    vlSelf->__PVT__io_txc_source__DOT__io_enq_ready_0 
        = ((IData)(vlSelf->__PVT__io_txc_source__DOT__ready_reg) 
           & (IData)(vlSelf->__PVT__io_txc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__io_rxc_source__DOT__io_enq_ready_0 
        = ((IData)(vlSelf->__PVT__io_rxc_source__DOT__ready_reg) 
           & (IData)(vlSelf->__PVT__io_rxc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__hqa__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqb__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqc__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqd__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqe__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__formatValid = ((IData)(vlSelf->__PVT__b2c_send) 
                                  & (0U == (IData)(vlSelf->__PVT__first_count)));
    vlSelf->__PVT__hqa__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqa__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqb__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqb__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqc__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqc__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqd__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqd__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqe__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqe__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ptr_match));
    vlSelf->__VdfgTmp_h8f767e1a__0 = (7U & ((IData)(vlSelf->__PVT__formatValid)
                                             ? vlSelf->__PVT__b2c_data
                                             : (IData)(vlSelf->__PVT__format_r)));
    vlSelf->__PVT__hqa_io_enq_valid = ((IData)(vlSelf->__PVT__b2c_send) 
                                       & ((IData)(1U) 
                                          << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)));
    vlSelf->__PVT__hqb_io_enq_valid = (0x7fU & ((IData)(vlSelf->__PVT__b2c_send) 
                                                & (((IData)(1U) 
                                                    << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                   >> 1U)));
    vlSelf->__PVT__hqc_io_enq_valid = (0x3fU & ((IData)(vlSelf->__PVT__b2c_send) 
                                                & (((IData)(1U) 
                                                    << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                   >> 2U)));
    vlSelf->__PVT__hqd_io_enq_valid = (0x1fU & ((IData)(vlSelf->__PVT__b2c_send) 
                                                & (((IData)(1U) 
                                                    << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                   >> 3U)));
    vlSelf->__PVT__hqe_io_enq_valid = (0xfU & ((IData)(vlSelf->__PVT__b2c_send) 
                                               & (((IData)(1U) 
                                                   << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                  >> 4U)));
    vlSelf->__PVT__hqa__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqa_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqb__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqb_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqc__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqc_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqd__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqd_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqe__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqe_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ram_out_valid));
}

VL_ATTR_COLD void VysyxSoCFull_RX___eval_initial__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx(VysyxSoCFull_RX* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_RX___eval_initial__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx\n"); );
    // Body
    if (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        vlSelf->__PVT__io_txc_source__DOT__widx_widx_bin = 0U;
        vlSelf->__PVT__io_txc_source__DOT__ready_reg = 0U;
        vlSelf->__PVT__io_txc_source__DOT__widx_gray = 0U;
        vlSelf->__PVT__io_txc_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__widx_widx_bin = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__ready_reg = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__widx_gray = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
    if (vlSelf->io_txc_source__DOT____Vcellinp__sink_extend__reset) {
        vlSelf->__PVT__io_txc_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_txc_source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__io_rxc_source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
}

VL_ATTR_COLD void VysyxSoCFull_RX___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__0(VysyxSoCFull_RX* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_RX___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__0\n"); );
    // Body
    vlSelf->__PVT__first = (0U == (IData)(vlSelf->__PVT__first_count));
    vlSelf->io_txc_source__DOT____Vcellinp__sink_extend__reset 
        = ((IData)(vlSymsp->TOP.reset) | (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0));
    vlSelf->__PVT__io_txc_source__DOT__io_enq_ready_0 
        = ((IData)(vlSelf->__PVT__io_txc_source__DOT__ready_reg) 
           & (IData)(vlSelf->__PVT__io_txc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__io_rxc_source__DOT__io_enq_ready_0 
        = ((IData)(vlSelf->__PVT__io_rxc_source__DOT__ready_reg) 
           & (IData)(vlSelf->__PVT__io_rxc_source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__hqa__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqb__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqc__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqd__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqe__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__formatValid = ((IData)(vlSelf->__PVT__b2c_send) 
                                  & (0U == (IData)(vlSelf->__PVT__first_count)));
    vlSelf->__PVT__hqa__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqa__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqb__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqb__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqc__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqc__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqd__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqd__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqe__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqe__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ptr_match));
    vlSelf->__VdfgTmp_h8f767e1a__0 = (7U & ((IData)(vlSelf->__PVT__formatValid)
                                             ? vlSelf->__PVT__b2c_data
                                             : (IData)(vlSelf->__PVT__format_r)));
    vlSelf->__PVT__hqa_io_enq_valid = ((IData)(vlSelf->__PVT__b2c_send) 
                                       & ((IData)(1U) 
                                          << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)));
    vlSelf->__PVT__hqb_io_enq_valid = (0x7fU & ((IData)(vlSelf->__PVT__b2c_send) 
                                                & (((IData)(1U) 
                                                    << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                   >> 1U)));
    vlSelf->__PVT__hqc_io_enq_valid = (0x3fU & ((IData)(vlSelf->__PVT__b2c_send) 
                                                & (((IData)(1U) 
                                                    << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                   >> 2U)));
    vlSelf->__PVT__hqd_io_enq_valid = (0x1fU & ((IData)(vlSelf->__PVT__b2c_send) 
                                                & (((IData)(1U) 
                                                    << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                   >> 3U)));
    vlSelf->__PVT__hqe_io_enq_valid = (0xfU & ((IData)(vlSelf->__PVT__b2c_send) 
                                               & (((IData)(1U) 
                                                   << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                  >> 4U)));
    vlSelf->__PVT__hqa__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqa_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqb__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqb_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqc__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqc_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqd__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqd_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqe__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqe_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ram_out_valid));
}
