// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_AsyncQueueSink_UInt32.h"

VL_ATTR_COLD void VysyxSoCFull_AsyncQueueSink_UInt32___ctor_var_reset(VysyxSoCFull_AsyncQueueSink_UInt32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_AsyncQueueSink_UInt32___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->io_deq_ready = VL_RAND_RESET_I(1);
    vlSelf->io_deq_valid = VL_RAND_RESET_I(1);
    vlSelf->io_deq_bits = VL_RAND_RESET_I(32);
    vlSelf->io_async_mem_0 = VL_RAND_RESET_I(32);
    vlSelf->io_async_mem_1 = VL_RAND_RESET_I(32);
    vlSelf->io_async_mem_2 = VL_RAND_RESET_I(32);
    vlSelf->io_async_mem_3 = VL_RAND_RESET_I(32);
    vlSelf->io_async_mem_4 = VL_RAND_RESET_I(32);
    vlSelf->io_async_mem_5 = VL_RAND_RESET_I(32);
    vlSelf->io_async_mem_6 = VL_RAND_RESET_I(32);
    vlSelf->io_async_mem_7 = VL_RAND_RESET_I(32);
    vlSelf->io_async_ridx = VL_RAND_RESET_I(4);
    vlSelf->io_async_widx = VL_RAND_RESET_I(4);
    vlSelf->io_async_safe_ridx_valid = VL_RAND_RESET_I(1);
    vlSelf->io_async_safe_widx_valid = VL_RAND_RESET_I(1);
    vlSelf->io_async_safe_source_reset_n = VL_RAND_RESET_I(1);
    vlSelf->io_async_safe_sink_reset_n = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ridx_ridx_bin = VL_RAND_RESET_I(4);
    vlSelf->__PVT___index_T = VL_RAND_RESET_I(3);
    vlSelf->__PVT__ridx = VL_RAND_RESET_I(4);
    vlSelf->__PVT__valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__valid_reg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ridx_gray = VL_RAND_RESET_I(4);
    vlSelf->__Vcellinp__sink_valid_0__reset = VL_RAND_RESET_I(1);
    vlSelf->__VdfgTmp_h53fdc2be__0 = 0;
    vlSelf->__VdfgTmp_h4436d783__0 = 0;
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_deq_bits_deq_bits_reg__DOT__cdc_reg = VL_RAND_RESET_I(32);
    vlSelf->__PVT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = VL_RAND_RESET_I(1);
}
