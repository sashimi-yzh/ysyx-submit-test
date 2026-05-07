// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VysyxSoCFull.h for the primary calling header

#ifndef VERILATED_VYSYXSOCFULL_ASYNCQUEUESINK_UINT32_H_
#define VERILATED_VYSYXSOCFULL_ASYNCQUEUESINK_UINT32_H_  // guard

#include "verilated.h"

class VysyxSoCFull__Syms;

class VysyxSoCFull_AsyncQueueSink_UInt32 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ __Vcellinp__sink_valid_0__reset;
    VL_IN8(io_deq_ready,0,0);
    VL_OUT8(io_deq_valid,0,0);
    VL_OUT8(io_async_ridx,3,0);
    VL_IN8(io_async_widx,3,0);
    VL_OUT8(io_async_safe_ridx_valid,0,0);
    VL_IN8(io_async_safe_widx_valid,0,0);
    VL_IN8(io_async_safe_source_reset_n,0,0);
    VL_OUT8(io_async_safe_sink_reset_n,0,0);
    CData/*3:0*/ __PVT__ridx_ridx_bin;
    CData/*2:0*/ __PVT___index_T;
    CData/*3:0*/ __PVT__ridx;
    CData/*0:0*/ __PVT__valid;
    CData/*0:0*/ __PVT__valid_reg;
    CData/*3:0*/ __PVT__ridx_gray;
    CData/*3:0*/ __VdfgTmp_h53fdc2be__0;
    CData/*0:0*/ __VdfgTmp_h4436d783__0;
    CData/*0:0*/ __PVT__widx_widx_gray__DOT__output_chain__DOT__sync_0;
    CData/*0:0*/ __PVT__widx_widx_gray__DOT__output_chain__DOT__sync_1;
    CData/*0:0*/ __PVT__widx_widx_gray__DOT__output_chain__DOT__sync_2;
    CData/*0:0*/ __PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0;
    CData/*0:0*/ __PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1;
    CData/*0:0*/ __PVT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2;
    CData/*0:0*/ __PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0;
    CData/*0:0*/ __PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1;
    CData/*0:0*/ __PVT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2;
    CData/*0:0*/ __PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0;
    CData/*0:0*/ __PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1;
    CData/*0:0*/ __PVT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2;
    CData/*0:0*/ __PVT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
    CData/*0:0*/ __PVT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
    CData/*0:0*/ __PVT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
    CData/*0:0*/ __PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
    CData/*0:0*/ __PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
    CData/*0:0*/ __PVT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
    CData/*0:0*/ __PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
    CData/*0:0*/ __PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
    CData/*0:0*/ __PVT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
    CData/*0:0*/ __PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
    CData/*0:0*/ __PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
    CData/*0:0*/ __PVT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
    VL_OUT(io_deq_bits,31,0);
    VL_IN(io_async_mem_0,31,0);
    VL_IN(io_async_mem_1,31,0);
    VL_IN(io_async_mem_2,31,0);
    VL_IN(io_async_mem_3,31,0);
    VL_IN(io_async_mem_4,31,0);
    VL_IN(io_async_mem_5,31,0);
    VL_IN(io_async_mem_6,31,0);
    VL_IN(io_async_mem_7,31,0);
    IData/*31:0*/ __PVT__io_deq_bits_deq_bits_reg__DOT__cdc_reg;

    // INTERNAL VARIABLES
    VysyxSoCFull__Syms* const vlSymsp;

    // CONSTRUCTORS
    VysyxSoCFull_AsyncQueueSink_UInt32(VysyxSoCFull__Syms* symsp, const char* v__name);
    ~VysyxSoCFull_AsyncQueueSink_UInt32();
    VL_UNCOPYABLE(VysyxSoCFull_AsyncQueueSink_UInt32);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
