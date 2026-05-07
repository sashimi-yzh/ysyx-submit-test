// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_AsyncQueueSource_UInt32.h"
#include "VysyxSoCFull__Syms.h"

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___ico_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source__0\n"); );
    // Body
    vlSelf->__Vcellinp__sink_extend__reset = ((IData)(vlSymsp->TOP.reset) 
                                              | (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source__0\n"); );
    // Body
    vlSelf->__PVT__unnamedblk1__DOT__index = (7U & 
                                              ((IData)(vlSelf->__PVT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__widx_gray) 
                                                     >> 1U))));
    if (((IData)(vlSelf->__PVT___widx_T_1) & (0U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_0 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (1U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_1 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (2U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_2 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (3U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_3 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (4U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_4 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (5U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_5 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (6U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_6 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (7U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_7 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source__1(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source__1\n"); );
    // Init
    CData/*3:0*/ __Vdly__widx_widx_bin;
    __Vdly__widx_widx_bin = 0;
    // Body
    __Vdly__widx_widx_bin = vlSelf->__PVT__widx_widx_bin;
    if (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        __Vdly__widx_widx_bin = 0U;
        vlSelf->__PVT__ready_reg = 0U;
        vlSelf->__PVT__widx_gray = 0U;
    } else {
        vlSelf->__PVT__unnamedblk2__DOT__widx_incremented 
            = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                ? (0xfU & ((IData)(vlSelf->__PVT__widx_widx_bin) 
                           + (IData)(vlSelf->__PVT___widx_T_1)))
                : 0U);
        vlSelf->__PVT__unnamedblk2__DOT__widx = ((8U 
                                                  & (IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented)) 
                                                 | (7U 
                                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                       ^ 
                                                       ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                        >> 1U))));
        __Vdly__widx_widx_bin = vlSelf->__PVT__unnamedblk2__DOT__widx_incremented;
        vlSelf->__PVT__ready_reg = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx) 
                                       != (0xcU ^ (
                                                   ((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0)))))));
        vlSelf->__PVT__widx_gray = vlSelf->__PVT__unnamedblk2__DOT__widx;
    }
    vlSelf->__PVT__widx_widx_bin = __Vdly__widx_widx_bin;
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__io_enq_ready = ((IData)(vlSelf->__PVT__ready_reg) 
                                   & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink.__PVT__ridx_gray) 
              >> 3U));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink.__PVT__ridx_gray) 
                    >> 2U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink.__PVT__ridx_gray) 
                    >> 1U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink.__PVT__ridx_gray)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source__0\n"); );
    // Body
    vlSelf->__PVT___widx_T_1 = ((IData)(vlSelf->__PVT__io_enq_ready) 
                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__full));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source__2(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_a_source__2\n"); );
    // Body
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceA_io_q_sink.__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource__0\n"); );
    // Body
    vlSelf->__PVT__unnamedblk1__DOT__index = (7U & 
                                              ((IData)(vlSelf->__PVT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__widx_gray) 
                                                     >> 1U))));
    if (((IData)(vlSelf->__PVT___widx_T_1) & (0U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_0 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (1U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_1 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (2U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_2 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (3U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_3 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (4U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_4 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (5U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_5 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (6U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_6 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (7U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_7 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource__1(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource__1\n"); );
    // Init
    CData/*3:0*/ __Vdly__widx_widx_bin;
    __Vdly__widx_widx_bin = 0;
    // Body
    __Vdly__widx_widx_bin = vlSelf->__PVT__widx_widx_bin;
    if (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        __Vdly__widx_widx_bin = 0U;
        vlSelf->__PVT__ready_reg = 0U;
        vlSelf->__PVT__widx_gray = 0U;
    } else {
        vlSelf->__PVT__unnamedblk2__DOT__widx_incremented 
            = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                ? (0xfU & ((IData)(vlSelf->__PVT__widx_widx_bin) 
                           + (IData)(vlSelf->__PVT___widx_T_1)))
                : 0U);
        vlSelf->__PVT__unnamedblk2__DOT__widx = ((8U 
                                                  & (IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented)) 
                                                 | (7U 
                                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                       ^ 
                                                       ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                        >> 1U))));
        __Vdly__widx_widx_bin = vlSelf->__PVT__unnamedblk2__DOT__widx_incremented;
        vlSelf->__PVT__ready_reg = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx) 
                                       != (0xcU ^ (
                                                   ((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0)))))));
        vlSelf->__PVT__widx_gray = vlSelf->__PVT__unnamedblk2__DOT__widx;
    }
    vlSelf->__PVT__widx_widx_bin = __Vdly__widx_widx_bin;
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__io_enq_ready = ((IData)(vlSelf->__PVT__ready_reg) 
                                   & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink.__PVT__ridx_gray) 
              >> 3U));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink.__PVT__ridx_gray) 
                    >> 2U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink.__PVT__ridx_gray) 
                    >> 1U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink.__PVT__ridx_gray)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource__0\n"); );
    // Body
    vlSelf->__PVT___widx_T_1 = ((IData)(vlSelf->__PVT__io_enq_ready) 
                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__full));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource__2(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_bsource__2\n"); );
    // Body
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceB_io_q_sink.__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source__0\n"); );
    // Body
    vlSelf->__PVT__unnamedblk1__DOT__index = (7U & 
                                              ((IData)(vlSelf->__PVT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__widx_gray) 
                                                     >> 1U))));
    if (((IData)(vlSelf->__PVT___widx_T_1) & (0U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_0 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (1U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_1 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (2U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_2 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (3U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_3 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (4U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_4 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (5U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_5 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (6U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_6 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (7U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_7 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source__1(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source__1\n"); );
    // Init
    CData/*3:0*/ __Vdly__widx_widx_bin;
    __Vdly__widx_widx_bin = 0;
    // Body
    __Vdly__widx_widx_bin = vlSelf->__PVT__widx_widx_bin;
    if (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        __Vdly__widx_widx_bin = 0U;
        vlSelf->__PVT__ready_reg = 0U;
        vlSelf->__PVT__widx_gray = 0U;
    } else {
        vlSelf->__PVT__unnamedblk2__DOT__widx_incremented 
            = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                ? (0xfU & ((IData)(vlSelf->__PVT__widx_widx_bin) 
                           + (IData)(vlSelf->__PVT___widx_T_1)))
                : 0U);
        vlSelf->__PVT__unnamedblk2__DOT__widx = ((8U 
                                                  & (IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented)) 
                                                 | (7U 
                                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                       ^ 
                                                       ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                        >> 1U))));
        __Vdly__widx_widx_bin = vlSelf->__PVT__unnamedblk2__DOT__widx_incremented;
        vlSelf->__PVT__ready_reg = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx) 
                                       != (0xcU ^ (
                                                   ((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0)))))));
        vlSelf->__PVT__widx_gray = vlSelf->__PVT__unnamedblk2__DOT__widx;
    }
    vlSelf->__PVT__widx_widx_bin = __Vdly__widx_widx_bin;
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__io_enq_ready = ((IData)(vlSelf->__PVT__ready_reg) 
                                   & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink.__PVT__ridx_gray) 
              >> 3U));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink.__PVT__ridx_gray) 
                    >> 2U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink.__PVT__ridx_gray) 
                    >> 1U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink.__PVT__ridx_gray)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source__0\n"); );
    // Body
    vlSelf->__PVT___widx_T_1 = ((IData)(vlSelf->__PVT__io_enq_ready) 
                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__full));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source__2(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_c_source__2\n"); );
    // Body
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceC_io_q_sink.__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source__0\n"); );
    // Body
    vlSelf->__PVT__unnamedblk1__DOT__index = (7U & 
                                              ((IData)(vlSelf->__PVT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__widx_gray) 
                                                     >> 1U))));
    if (((IData)(vlSelf->__PVT___widx_T_1) & (0U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_0 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (1U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_1 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (2U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_2 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (3U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_3 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (4U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_4 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (5U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_5 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (6U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_6 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (7U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_7 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source__1(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source__1\n"); );
    // Init
    CData/*3:0*/ __Vdly__widx_widx_bin;
    __Vdly__widx_widx_bin = 0;
    // Body
    __Vdly__widx_widx_bin = vlSelf->__PVT__widx_widx_bin;
    if (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        __Vdly__widx_widx_bin = 0U;
        vlSelf->__PVT__ready_reg = 0U;
        vlSelf->__PVT__widx_gray = 0U;
    } else {
        vlSelf->__PVT__unnamedblk2__DOT__widx_incremented 
            = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                ? (0xfU & ((IData)(vlSelf->__PVT__widx_widx_bin) 
                           + (IData)(vlSelf->__PVT___widx_T_1)))
                : 0U);
        vlSelf->__PVT__unnamedblk2__DOT__widx = ((8U 
                                                  & (IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented)) 
                                                 | (7U 
                                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                       ^ 
                                                       ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                        >> 1U))));
        __Vdly__widx_widx_bin = vlSelf->__PVT__unnamedblk2__DOT__widx_incremented;
        vlSelf->__PVT__ready_reg = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx) 
                                       != (0xcU ^ (
                                                   ((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0)))))));
        vlSelf->__PVT__widx_gray = vlSelf->__PVT__unnamedblk2__DOT__widx;
    }
    vlSelf->__PVT__widx_widx_bin = __Vdly__widx_widx_bin;
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__io_enq_ready = ((IData)(vlSelf->__PVT__ready_reg) 
                                   & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD_io_q_sink.__PVT__ridx_gray) 
              >> 3U));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD_io_q_sink.__PVT__ridx_gray) 
                    >> 2U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD_io_q_sink.__PVT__ridx_gray) 
                    >> 1U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD_io_q_sink.__PVT__ridx_gray)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source__0\n"); );
    // Body
    vlSelf->__PVT___widx_T_1 = ((IData)(vlSelf->__PVT__io_enq_ready) 
                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__full));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source__2(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_d_source__2\n"); );
    // Body
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceD_io_q_sink.__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source__0\n"); );
    // Body
    vlSelf->__PVT__unnamedblk1__DOT__index = (7U & 
                                              ((IData)(vlSelf->__PVT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__widx_gray) 
                                                     >> 1U))));
    if (((IData)(vlSelf->__PVT___widx_T_1) & (0U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_0 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (1U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_1 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (2U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_2 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (3U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_3 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (4U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_4 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (5U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_5 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (6U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_6 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (7U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_7 = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source__1(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source__1\n"); );
    // Init
    CData/*3:0*/ __Vdly__widx_widx_bin;
    __Vdly__widx_widx_bin = 0;
    // Body
    __Vdly__widx_widx_bin = vlSelf->__PVT__widx_widx_bin;
    if (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        __Vdly__widx_widx_bin = 0U;
        vlSelf->__PVT__ready_reg = 0U;
        vlSelf->__PVT__widx_gray = 0U;
    } else {
        vlSelf->__PVT__unnamedblk2__DOT__widx_incremented 
            = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                ? (0xfU & ((IData)(vlSelf->__PVT__widx_widx_bin) 
                           + (IData)(vlSelf->__PVT___widx_T_1)))
                : 0U);
        vlSelf->__PVT__unnamedblk2__DOT__widx = ((8U 
                                                  & (IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented)) 
                                                 | (7U 
                                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                       ^ 
                                                       ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                        >> 1U))));
        __Vdly__widx_widx_bin = vlSelf->__PVT__unnamedblk2__DOT__widx_incremented;
        vlSelf->__PVT__ready_reg = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx) 
                                       != (0xcU ^ (
                                                   ((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0)))))));
        vlSelf->__PVT__widx_gray = vlSelf->__PVT__unnamedblk2__DOT__widx;
    }
    vlSelf->__PVT__widx_widx_bin = __Vdly__widx_widx_bin;
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__io_enq_ready = ((IData)(vlSelf->__PVT__ready_reg) 
                                   & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink.__PVT__ridx_gray) 
              >> 3U));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink.__PVT__ridx_gray) 
                    >> 2U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink.__PVT__ridx_gray) 
                    >> 1U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink.__PVT__ridx_gray)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source__0\n"); );
    // Body
    vlSelf->__PVT___widx_T_1 = ((IData)(vlSelf->__PVT__io_enq_ready) 
                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__full));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source__2(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__io_e_source__2\n"); );
    // Body
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__sourceE_io_q_sink.__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___ico_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___ico_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source__0\n"); );
    // Body
    vlSelf->__Vcellinp__sink_extend__reset = ((IData)(vlSymsp->TOP.reset) 
                                              | (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source__0\n"); );
    // Body
    vlSelf->__PVT__unnamedblk1__DOT__index = (7U & 
                                              ((IData)(vlSelf->__PVT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__widx_gray) 
                                                     >> 1U))));
    if (((IData)(vlSelf->__PVT___widx_T_1) & (0U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_0 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (1U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_1 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (2U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_2 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (3U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_3 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (4U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_4 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (5U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_5 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (6U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_6 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (7U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_7 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__ram;
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source__1(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source__1\n"); );
    // Init
    CData/*3:0*/ __Vdly__widx_widx_bin;
    __Vdly__widx_widx_bin = 0;
    // Body
    __Vdly__widx_widx_bin = vlSelf->__PVT__widx_widx_bin;
    if (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        __Vdly__widx_widx_bin = 0U;
        vlSelf->__PVT__ready_reg = 0U;
        vlSelf->__PVT__widx_gray = 0U;
    } else {
        vlSelf->__PVT__unnamedblk2__DOT__widx_incremented 
            = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                ? (0xfU & ((IData)(vlSelf->__PVT__widx_widx_bin) 
                           + (IData)(vlSelf->__PVT___widx_T_1)))
                : 0U);
        vlSelf->__PVT__unnamedblk2__DOT__widx = ((8U 
                                                  & (IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented)) 
                                                 | (7U 
                                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                       ^ 
                                                       ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                        >> 1U))));
        __Vdly__widx_widx_bin = vlSelf->__PVT__unnamedblk2__DOT__widx_incremented;
        vlSelf->__PVT__ready_reg = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx) 
                                       != (0xcU ^ (
                                                   ((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0)))))));
        vlSelf->__PVT__widx_gray = vlSelf->__PVT__unnamedblk2__DOT__widx;
    }
    vlSelf->__PVT__widx_widx_bin = __Vdly__widx_widx_bin;
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__io_enq_ready = ((IData)(vlSelf->__PVT__ready_reg) 
                                   & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink.__PVT__ridx_gray) 
              >> 3U));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink.__PVT__ridx_gray) 
                    >> 2U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink.__PVT__ridx_gray) 
                    >> 1U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink.__PVT__ridx_gray)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source__0\n"); );
    // Body
    vlSelf->__PVT___widx_T_1 = ((IData)(vlSelf->__PVT__io_enq_ready) 
                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqa__DOT__io_deq_q__DOT__full));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source__2(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_a_source__2\n"); );
    // Body
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceA_io_q_sink.__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource__0\n"); );
    // Body
    vlSelf->__PVT__unnamedblk1__DOT__index = (7U & 
                                              ((IData)(vlSelf->__PVT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__widx_gray) 
                                                     >> 1U))));
    if (((IData)(vlSelf->__PVT___widx_T_1) & (0U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_0 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (1U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_1 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (2U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_2 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (3U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_3 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (4U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_4 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (5U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_5 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (6U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_6 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (7U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_7 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__ram;
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource__1(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource__1\n"); );
    // Init
    CData/*3:0*/ __Vdly__widx_widx_bin;
    __Vdly__widx_widx_bin = 0;
    // Body
    __Vdly__widx_widx_bin = vlSelf->__PVT__widx_widx_bin;
    if (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        __Vdly__widx_widx_bin = 0U;
        vlSelf->__PVT__ready_reg = 0U;
        vlSelf->__PVT__widx_gray = 0U;
    } else {
        vlSelf->__PVT__unnamedblk2__DOT__widx_incremented 
            = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                ? (0xfU & ((IData)(vlSelf->__PVT__widx_widx_bin) 
                           + (IData)(vlSelf->__PVT___widx_T_1)))
                : 0U);
        vlSelf->__PVT__unnamedblk2__DOT__widx = ((8U 
                                                  & (IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented)) 
                                                 | (7U 
                                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                       ^ 
                                                       ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                        >> 1U))));
        __Vdly__widx_widx_bin = vlSelf->__PVT__unnamedblk2__DOT__widx_incremented;
        vlSelf->__PVT__ready_reg = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx) 
                                       != (0xcU ^ (
                                                   ((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0)))))));
        vlSelf->__PVT__widx_gray = vlSelf->__PVT__unnamedblk2__DOT__widx;
    }
    vlSelf->__PVT__widx_widx_bin = __Vdly__widx_widx_bin;
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__io_enq_ready = ((IData)(vlSelf->__PVT__ready_reg) 
                                   & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink.__PVT__ridx_gray) 
              >> 3U));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink.__PVT__ridx_gray) 
                    >> 2U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink.__PVT__ridx_gray) 
                    >> 1U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink.__PVT__ridx_gray)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource__0\n"); );
    // Body
    vlSelf->__PVT___widx_T_1 = ((IData)(vlSelf->__PVT__io_enq_ready) 
                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqb__DOT__io_deq_q__DOT__full));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource__2(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_bsource__2\n"); );
    // Body
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceB_io_q_sink.__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source__0\n"); );
    // Body
    vlSelf->__PVT__unnamedblk1__DOT__index = (7U & 
                                              ((IData)(vlSelf->__PVT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__widx_gray) 
                                                     >> 1U))));
    if (((IData)(vlSelf->__PVT___widx_T_1) & (0U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_0 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (1U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_1 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (2U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_2 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (3U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_3 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (4U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_4 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (5U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_5 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (6U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_6 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (7U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_7 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__ram;
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source__1(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source__1\n"); );
    // Init
    CData/*3:0*/ __Vdly__widx_widx_bin;
    __Vdly__widx_widx_bin = 0;
    // Body
    __Vdly__widx_widx_bin = vlSelf->__PVT__widx_widx_bin;
    if (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        __Vdly__widx_widx_bin = 0U;
        vlSelf->__PVT__ready_reg = 0U;
        vlSelf->__PVT__widx_gray = 0U;
    } else {
        vlSelf->__PVT__unnamedblk2__DOT__widx_incremented 
            = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                ? (0xfU & ((IData)(vlSelf->__PVT__widx_widx_bin) 
                           + (IData)(vlSelf->__PVT___widx_T_1)))
                : 0U);
        vlSelf->__PVT__unnamedblk2__DOT__widx = ((8U 
                                                  & (IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented)) 
                                                 | (7U 
                                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                       ^ 
                                                       ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                        >> 1U))));
        __Vdly__widx_widx_bin = vlSelf->__PVT__unnamedblk2__DOT__widx_incremented;
        vlSelf->__PVT__ready_reg = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx) 
                                       != (0xcU ^ (
                                                   ((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0)))))));
        vlSelf->__PVT__widx_gray = vlSelf->__PVT__unnamedblk2__DOT__widx;
    }
    vlSelf->__PVT__widx_widx_bin = __Vdly__widx_widx_bin;
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__io_enq_ready = ((IData)(vlSelf->__PVT__ready_reg) 
                                   & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink.__PVT__ridx_gray) 
              >> 3U));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink.__PVT__ridx_gray) 
                    >> 2U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink.__PVT__ridx_gray) 
                    >> 1U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink.__PVT__ridx_gray)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source__0\n"); );
    // Body
    vlSelf->__PVT___widx_T_1 = ((IData)(vlSelf->__PVT__io_enq_ready) 
                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqc__DOT__io_deq_q__DOT__full));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source__2(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_c_source__2\n"); );
    // Body
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceC_io_q_sink.__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source__0\n"); );
    // Body
    vlSelf->__PVT__unnamedblk1__DOT__index = (7U & 
                                              ((IData)(vlSelf->__PVT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__widx_gray) 
                                                     >> 1U))));
    if (((IData)(vlSelf->__PVT___widx_T_1) & (0U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_0 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (1U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_1 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (2U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_2 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (3U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_3 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (4U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_4 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (5U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_5 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (6U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_6 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (7U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_7 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__ram;
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source__1(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source__1\n"); );
    // Init
    CData/*3:0*/ __Vdly__widx_widx_bin;
    __Vdly__widx_widx_bin = 0;
    // Body
    __Vdly__widx_widx_bin = vlSelf->__PVT__widx_widx_bin;
    if (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        __Vdly__widx_widx_bin = 0U;
        vlSelf->__PVT__ready_reg = 0U;
        vlSelf->__PVT__widx_gray = 0U;
    } else {
        vlSelf->__PVT__unnamedblk2__DOT__widx_incremented 
            = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                ? (0xfU & ((IData)(vlSelf->__PVT__widx_widx_bin) 
                           + (IData)(vlSelf->__PVT___widx_T_1)))
                : 0U);
        vlSelf->__PVT__unnamedblk2__DOT__widx = ((8U 
                                                  & (IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented)) 
                                                 | (7U 
                                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                       ^ 
                                                       ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                        >> 1U))));
        __Vdly__widx_widx_bin = vlSelf->__PVT__unnamedblk2__DOT__widx_incremented;
        vlSelf->__PVT__ready_reg = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx) 
                                       != (0xcU ^ (
                                                   ((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0)))))));
        vlSelf->__PVT__widx_gray = vlSelf->__PVT__unnamedblk2__DOT__widx;
    }
    vlSelf->__PVT__widx_widx_bin = __Vdly__widx_widx_bin;
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__io_enq_ready = ((IData)(vlSelf->__PVT__ready_reg) 
                                   & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD_io_q_sink.__PVT__ridx_gray) 
              >> 3U));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD_io_q_sink.__PVT__ridx_gray) 
                    >> 2U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD_io_q_sink.__PVT__ridx_gray) 
                    >> 1U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD_io_q_sink.__PVT__ridx_gray)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source__0\n"); );
    // Body
    vlSelf->__PVT___widx_T_1 = ((IData)(vlSelf->__PVT__io_enq_ready) 
                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqd__DOT__io_deq_q__DOT__full));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source__2(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_d_source__2\n"); );
    // Body
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceD_io_q_sink.__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source__0\n"); );
    // Body
    vlSelf->__PVT__unnamedblk1__DOT__index = (7U & 
                                              ((IData)(vlSelf->__PVT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__widx_gray) 
                                                     >> 1U))));
    if (((IData)(vlSelf->__PVT___widx_T_1) & (0U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_0 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (1U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_1 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (2U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_2 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (3U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_3 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (4U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_4 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (5U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_5 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (6U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_6 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
    if (((IData)(vlSelf->__PVT___widx_T_1) & (7U == (IData)(vlSelf->__PVT__unnamedblk1__DOT__index)))) {
        vlSelf->__PVT__mem_7 = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__ram;
    }
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source__1(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source__1\n"); );
    // Init
    CData/*3:0*/ __Vdly__widx_widx_bin;
    __Vdly__widx_widx_bin = 0;
    // Body
    __Vdly__widx_widx_bin = vlSelf->__PVT__widx_widx_bin;
    if (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        __Vdly__widx_widx_bin = 0U;
        vlSelf->__PVT__ready_reg = 0U;
        vlSelf->__PVT__widx_gray = 0U;
    } else {
        vlSelf->__PVT__unnamedblk2__DOT__widx_incremented 
            = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                ? (0xfU & ((IData)(vlSelf->__PVT__widx_widx_bin) 
                           + (IData)(vlSelf->__PVT___widx_T_1)))
                : 0U);
        vlSelf->__PVT__unnamedblk2__DOT__widx = ((8U 
                                                  & (IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented)) 
                                                 | (7U 
                                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                       ^ 
                                                       ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx_incremented) 
                                                        >> 1U))));
        __Vdly__widx_widx_bin = vlSelf->__PVT__unnamedblk2__DOT__widx_incremented;
        vlSelf->__PVT__ready_reg = ((IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                    & ((IData)(vlSelf->__PVT__unnamedblk2__DOT__widx) 
                                       != (0xcU ^ (
                                                   ((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0)))))));
        vlSelf->__PVT__widx_gray = vlSelf->__PVT__unnamedblk2__DOT__widx;
    }
    vlSelf->__PVT__widx_widx_bin = __Vdly__widx_widx_bin;
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__io_enq_ready = ((IData)(vlSelf->__PVT__ready_reg) 
                                   & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink.__PVT__ridx_gray) 
              >> 3U));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink.__PVT__ridx_gray) 
                    >> 2U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink.__PVT__ridx_gray) 
                    >> 1U)));
    vlSelf->__PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 
        = (1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                 & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink.__PVT__ridx_gray)));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source__0(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source__0\n"); );
    // Body
    vlSelf->__PVT___widx_T_1 = ((IData)(vlSelf->__PVT__io_enq_ready) 
                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx.__PVT__hqe__DOT__io_deq_q__DOT__full));
}

VL_INLINE_OPT void VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source__2(VysyxSoCFull_AsyncQueueSource_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                VysyxSoCFull_AsyncQueueSource_UInt32___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__io_e_source__2\n"); );
    // Body
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__sourceE_io_q_sink.__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)) 
           & (IData)(vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->__Vcellinp__sink_extend__reset)));
}
