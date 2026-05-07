// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VysyxSoCFull.h for the primary calling header

#ifndef VERILATED_VYSYXSOCFULL_TLFIFOFIXER_H_
#define VERILATED_VYSYXSOCFULL_TLFIFOFIXER_H_  // guard

#include "verilated.h"

class VysyxSoCFull__Syms;

class VysyxSoCFull_TLFIFOFixer final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_OUT8(auto_anon_in_a_ready,0,0);
        VL_IN8(auto_anon_in_a_valid,0,0);
        VL_IN8(auto_anon_in_a_bits_opcode,2,0);
        VL_IN8(auto_anon_in_a_bits_size,2,0);
        VL_IN8(auto_anon_in_a_bits_source,3,0);
        VL_IN8(auto_anon_in_a_bits_mask,3,0);
        VL_IN8(auto_anon_in_d_ready,0,0);
        VL_OUT8(auto_anon_in_d_valid,0,0);
        VL_OUT8(auto_anon_in_d_bits_opcode,2,0);
        VL_OUT8(auto_anon_in_d_bits_size,2,0);
        VL_OUT8(auto_anon_in_d_bits_source,3,0);
        VL_OUT8(auto_anon_in_d_bits_denied,0,0);
        VL_OUT8(auto_anon_in_d_bits_corrupt,0,0);
        VL_IN8(auto_anon_out_a_ready,0,0);
        VL_OUT8(auto_anon_out_a_valid,0,0);
        VL_OUT8(auto_anon_out_a_bits_opcode,2,0);
        VL_OUT8(auto_anon_out_a_bits_size,2,0);
        VL_OUT8(auto_anon_out_a_bits_source,3,0);
        VL_OUT8(auto_anon_out_a_bits_mask,3,0);
        VL_OUT8(auto_anon_out_d_ready,0,0);
        VL_IN8(auto_anon_out_d_valid,0,0);
        VL_IN8(auto_anon_out_d_bits_opcode,2,0);
        VL_IN8(auto_anon_out_d_bits_param,1,0);
        VL_IN8(auto_anon_out_d_bits_size,2,0);
        VL_IN8(auto_anon_out_d_bits_source,3,0);
        VL_IN8(auto_anon_out_d_bits_sink,5,0);
        VL_IN8(auto_anon_out_d_bits_denied,0,0);
        VL_IN8(auto_anon_out_d_bits_corrupt,0,0);
        CData/*1:0*/ __PVT__a_id;
        CData/*2:0*/ __PVT__a_first_counter;
        CData/*0:0*/ __PVT__a_first;
        CData/*2:0*/ __PVT__d_first_counter;
        CData/*0:0*/ __PVT__flight_0;
        CData/*0:0*/ __PVT__flight_1;
        CData/*0:0*/ __PVT__flight_2;
        CData/*0:0*/ __PVT__flight_3;
        CData/*0:0*/ __PVT__flight_4;
        CData/*0:0*/ __PVT__flight_5;
        CData/*0:0*/ __PVT__flight_6;
        CData/*0:0*/ __PVT__flight_7;
        CData/*0:0*/ __PVT__flight_8;
        CData/*0:0*/ __PVT__flight_9;
        CData/*0:0*/ __PVT__flight_10;
        CData/*0:0*/ __PVT__flight_11;
        CData/*0:0*/ __PVT__flight_12;
        CData/*0:0*/ __PVT__flight_13;
        CData/*0:0*/ __PVT__flight_14;
        CData/*0:0*/ __PVT__flight_15;
        CData/*1:0*/ __PVT__stalls_id;
        CData/*1:0*/ __PVT__stalls_id_1;
        CData/*0:0*/ __PVT__stall;
        CData/*0:0*/ __PVT__unnamedblk1__DOT__unnamedblk2__DOT__d_first_first;
        CData/*0:0*/ __PVT__unnamedblk1__DOT__unnamedblk2__DOT___GEN;
        CData/*0:0*/ __PVT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_0;
        CData/*0:0*/ __PVT__monitor__DOT___a_first_T_1;
        CData/*2:0*/ __PVT__monitor__DOT__a_first_counter;
        CData/*2:0*/ __PVT__monitor__DOT__opcode;
        CData/*2:0*/ __PVT__monitor__DOT__size;
        CData/*3:0*/ __PVT__monitor__DOT__source;
        CData/*2:0*/ __PVT__monitor__DOT__d_first_counter;
        CData/*2:0*/ __PVT__monitor__DOT__opcode_1;
        CData/*1:0*/ __PVT__monitor__DOT__param_1;
    };
    struct {
        CData/*2:0*/ __PVT__monitor__DOT__size_1;
        CData/*3:0*/ __PVT__monitor__DOT__source_1;
        CData/*5:0*/ __PVT__monitor__DOT__sink;
        CData/*0:0*/ __PVT__monitor__DOT__denied;
        CData/*2:0*/ __PVT__monitor__DOT__a_first_counter_1;
        CData/*0:0*/ __PVT__monitor__DOT__a_first_1;
        CData/*2:0*/ __PVT__monitor__DOT__d_first_counter_1;
        CData/*0:0*/ __PVT__monitor__DOT__d_first_1;
        CData/*0:0*/ __PVT__monitor__DOT___GEN_0;
        CData/*2:0*/ __PVT__monitor__DOT__d_first_counter_2;
        CData/*0:0*/ __PVT__monitor__DOT__d_first_2;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1;
        CData/*3:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__mask;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_45;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_47;
        SData/*11:0*/ __PVT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_first_beats1_decode_T;
        SData/*11:0*/ __PVT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT___d_first_beats1_decode_T;
        SData/*15:0*/ __PVT__monitor__DOT__inflight;
        SData/*15:0*/ __PVT__monitor__DOT__inflight_1;
        SData/*11:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3;
        SData/*11:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6;
        VL_IN(auto_anon_in_a_bits_address,31,0);
        VL_IN(auto_anon_in_a_bits_data,31,0);
        VL_OUT(auto_anon_in_d_bits_data,31,0);
        VL_OUT(auto_anon_out_a_bits_address,31,0);
        VL_OUT(auto_anon_out_a_bits_data,31,0);
        VL_IN(auto_anon_out_d_bits_data,31,0);
        IData/*31:0*/ __PVT__monitor__DOT__address;
        IData/*31:0*/ __PVT__monitor__DOT__watchdog;
        IData/*31:0*/ __PVT__monitor__DOT__watchdog_1;
        VlWide<5>/*130:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44;
        VlWide<5>/*142:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_46;
        VlWide<5>/*142:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5;
        VlWide<5>/*130:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1;
        VlWide<5>/*142:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5;
        VlWide<5>/*130:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1;
        VlWide<5>/*142:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11;
        IData/*31:0*/ __PVT__monitor__DOT__plusarg_reader__DOT__myplus;
        IData/*31:0*/ __PVT__monitor__DOT__plusarg_reader_1__DOT__myplus;
        QData/*63:0*/ __PVT__monitor__DOT__inflight_opcodes;
        QData/*63:0*/ __PVT__monitor__DOT__inflight_sizes;
        QData/*63:0*/ __PVT__monitor__DOT__inflight_sizes_1;
    };

    // INTERNAL VARIABLES
    VysyxSoCFull__Syms* const vlSymsp;

    // CONSTRUCTORS
    VysyxSoCFull_TLFIFOFixer(VysyxSoCFull__Syms* symsp, const char* v__name);
    ~VysyxSoCFull_TLFIFOFixer();
    VL_UNCOPYABLE(VysyxSoCFull_TLFIFOFixer);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
