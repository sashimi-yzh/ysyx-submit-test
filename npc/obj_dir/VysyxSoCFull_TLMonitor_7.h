// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VysyxSoCFull.h for the primary calling header

#ifndef VERILATED_VYSYXSOCFULL_TLMONITOR_7_H_
#define VERILATED_VYSYXSOCFULL_TLMONITOR_7_H_  // guard

#include "verilated.h"

class VysyxSoCFull__Syms;

class VysyxSoCFull_TLMonitor_7 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_in_a_ready,0,0);
    VL_IN8(io_in_a_valid,0,0);
    VL_IN8(io_in_a_bits_opcode,2,0);
    VL_IN8(io_in_a_bits_size,2,0);
    VL_IN8(io_in_a_bits_source,3,0);
    VL_IN8(io_in_a_bits_mask,3,0);
    VL_IN8(io_in_d_ready,0,0);
    VL_IN8(io_in_d_valid,0,0);
    VL_IN8(io_in_d_bits_opcode,2,0);
    VL_IN8(io_in_d_bits_param,1,0);
    VL_IN8(io_in_d_bits_size,2,0);
    VL_IN8(io_in_d_bits_source,3,0);
    VL_IN8(io_in_d_bits_sink,4,0);
    VL_IN8(io_in_d_bits_denied,0,0);
    VL_IN8(io_in_d_bits_corrupt,0,0);
    CData/*0:0*/ __PVT___a_first_T_1;
    CData/*2:0*/ __PVT__a_first_counter;
    CData/*2:0*/ __PVT__opcode;
    CData/*2:0*/ __PVT__size;
    CData/*3:0*/ __PVT__source;
    CData/*2:0*/ __PVT__d_first_counter;
    CData/*2:0*/ __PVT__opcode_1;
    CData/*1:0*/ __PVT__param_1;
    CData/*2:0*/ __PVT__size_1;
    CData/*3:0*/ __PVT__source_1;
    CData/*4:0*/ __PVT__sink;
    CData/*0:0*/ __PVT__denied;
    CData/*2:0*/ __PVT__a_first_counter_1;
    CData/*0:0*/ __PVT__a_first_1;
    CData/*2:0*/ __PVT__d_first_counter_1;
    CData/*0:0*/ __PVT__d_first_1;
    CData/*0:0*/ __PVT___GEN_1;
    CData/*2:0*/ __PVT__d_first_counter_2;
    CData/*0:0*/ __PVT__d_first_2;
    CData/*0:0*/ __PVT__unnamedblk1__DOT__mask_sub_0_1;
    CData/*0:0*/ __PVT__unnamedblk1__DOT__mask_sub_1_1;
    CData/*3:0*/ __PVT__unnamedblk1__DOT__mask;
    CData/*0:0*/ __PVT__unnamedblk1__DOT__same_cycle_resp;
    CData/*0:0*/ __PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41;
    CData/*0:0*/ __PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43;
    SData/*15:0*/ __PVT__inflight;
    SData/*15:0*/ __PVT__inflight_1;
    SData/*15:0*/ __PVT__unnamedblk1__DOT__a_set_wo_ready;
    SData/*11:0*/ __PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3;
    SData/*11:0*/ __PVT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6;
    VL_IN(io_in_a_bits_address,31,0);
    IData/*31:0*/ __PVT__address;
    IData/*31:0*/ __PVT__watchdog;
    IData/*31:0*/ __PVT__watchdog_1;
    VlWide<5>/*130:0*/ __PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40;
    VlWide<5>/*142:0*/ __PVT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42;
    VlWide<5>/*142:0*/ __PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5;
    VlWide<5>/*130:0*/ __PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1;
    VlWide<5>/*142:0*/ __PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5;
    VlWide<5>/*130:0*/ __PVT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1;
    VlWide<5>/*142:0*/ __PVT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11;
    IData/*31:0*/ __PVT__plusarg_reader__DOT__myplus;
    IData/*31:0*/ __PVT__plusarg_reader_1__DOT__myplus;
    QData/*63:0*/ __PVT__inflight_opcodes;
    QData/*63:0*/ __PVT__inflight_sizes;
    QData/*63:0*/ __PVT__inflight_sizes_1;

    // INTERNAL VARIABLES
    VysyxSoCFull__Syms* const vlSymsp;

    // CONSTRUCTORS
    VysyxSoCFull_TLMonitor_7(VysyxSoCFull__Syms* symsp, const char* v__name);
    ~VysyxSoCFull_TLMonitor_7();
    VL_UNCOPYABLE(VysyxSoCFull_TLMonitor_7);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
