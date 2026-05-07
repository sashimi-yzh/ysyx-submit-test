// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VysyxSoCFull.h for the primary calling header

#ifndef VERILATED_VYSYXSOCFULL_ASYNCQUEUESOURCE_UINT32_H_
#define VERILATED_VYSYXSOCFULL_ASYNCQUEUESOURCE_UINT32_H_  // guard

#include "verilated.h"

class VysyxSoCFull__Syms;

class VysyxSoCFull_AsyncQueueSource_UInt32 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clock,0,0);
    VL_IN8(__PVT__reset,0,0);
    CData/*0:0*/ __Vcellinp__sink_extend__reset;
    VL_OUT8(__PVT__io_enq_ready,0,0);
    VL_IN8(__PVT__io_enq_valid,0,0);
    VL_IN8(__PVT__io_async_ridx,3,0);
    VL_OUT8(__PVT__io_async_widx,3,0);
    VL_IN8(__PVT__io_async_safe_ridx_valid,0,0);
    VL_OUT8(__PVT__io_async_safe_widx_valid,0,0);
    VL_OUT8(__PVT__io_async_safe_source_reset_n,0,0);
    VL_IN8(__PVT__io_async_safe_sink_reset_n,0,0);
    CData/*0:0*/ __PVT___widx_T_1;
    CData/*3:0*/ __PVT__widx_widx_bin;
    CData/*0:0*/ __PVT__ready_reg;
    CData/*3:0*/ __PVT__widx_gray;
    CData/*2:0*/ __PVT__unnamedblk1__DOT__index;
    CData/*3:0*/ __PVT__unnamedblk2__DOT__widx_incremented;
    CData/*3:0*/ __PVT__unnamedblk2__DOT__widx;
    CData/*0:0*/ __PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0;
    CData/*0:0*/ __PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1;
    CData/*0:0*/ __PVT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2;
    CData/*0:0*/ __PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0;
    CData/*0:0*/ __PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1;
    CData/*0:0*/ __PVT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2;
    CData/*0:0*/ __PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0;
    CData/*0:0*/ __PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1;
    CData/*0:0*/ __PVT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2;
    CData/*0:0*/ __PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0;
    CData/*0:0*/ __PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1;
    CData/*0:0*/ __PVT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2;
    CData/*0:0*/ __PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
    CData/*0:0*/ __PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
    CData/*0:0*/ __PVT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
    CData/*0:0*/ __PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
    CData/*0:0*/ __PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
    CData/*0:0*/ __PVT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
    CData/*0:0*/ __PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
    CData/*0:0*/ __PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
    CData/*0:0*/ __PVT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
    CData/*0:0*/ __PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0;
    CData/*0:0*/ __PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1;
    CData/*0:0*/ __PVT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2;
    VL_IN(__PVT__io_enq_bits,31,0);
    VL_OUT(__PVT__io_async_mem_0,31,0);
    VL_OUT(__PVT__io_async_mem_1,31,0);
    VL_OUT(__PVT__io_async_mem_2,31,0);
    VL_OUT(__PVT__io_async_mem_3,31,0);
    VL_OUT(__PVT__io_async_mem_4,31,0);
    VL_OUT(__PVT__io_async_mem_5,31,0);
    VL_OUT(__PVT__io_async_mem_6,31,0);
    VL_OUT(__PVT__io_async_mem_7,31,0);
    IData/*31:0*/ __PVT__mem_0;
    IData/*31:0*/ __PVT__mem_1;
    IData/*31:0*/ __PVT__mem_2;
    IData/*31:0*/ __PVT__mem_3;
    IData/*31:0*/ __PVT__mem_4;
    IData/*31:0*/ __PVT__mem_5;
    IData/*31:0*/ __PVT__mem_6;
    IData/*31:0*/ __PVT__mem_7;

    // INTERNAL VARIABLES
    VysyxSoCFull__Syms* const vlSymsp;

    // CONSTRUCTORS
    VysyxSoCFull_AsyncQueueSource_UInt32(VysyxSoCFull__Syms* symsp, const char* v__name);
    ~VysyxSoCFull_AsyncQueueSource_UInt32();
    VL_UNCOPYABLE(VysyxSoCFull_AsyncQueueSource_UInt32);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
