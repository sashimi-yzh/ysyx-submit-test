// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VysyxSoCFull.h for the primary calling header

#ifndef VERILATED_VYSYXSOCFULL_TLERROR_H_
#define VERILATED_VYSYXSOCFULL_TLERROR_H_  // guard

#include "verilated.h"

class VysyxSoCFull__Syms;

class VysyxSoCFull_TLError final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_OUT8(auto_in_a_ready,0,0);
        VL_IN8(auto_in_a_valid,0,0);
        VL_IN8(auto_in_a_bits_opcode,2,0);
        VL_IN8(auto_in_a_bits_size,2,0);
        VL_IN8(auto_in_a_bits_source,3,0);
        VL_IN8(auto_in_a_bits_mask,3,0);
        VL_IN8(auto_in_d_ready,0,0);
        VL_OUT8(auto_in_d_valid,0,0);
        VL_OUT8(auto_in_d_bits_opcode,2,0);
        VL_OUT8(auto_in_d_bits_size,2,0);
        VL_OUT8(auto_in_d_bits_source,3,0);
        VL_OUT8(auto_in_d_bits_denied,0,0);
        VL_OUT8(auto_in_d_bits_corrupt,0,0);
        CData/*0:0*/ __PVT__da_ready;
        CData/*2:0*/ __PVT__da_bits_opcode;
        CData/*0:0*/ __PVT__idle;
        CData/*2:0*/ __PVT__a_last_beats1;
        CData/*2:0*/ __PVT__a_last_counter;
        CData/*0:0*/ __PVT__a_last;
        CData/*2:0*/ __PVT__r_beats1;
        CData/*2:0*/ __PVT__r_counter;
        CData/*0:0*/ __PVT__da_first;
        CData/*0:0*/ __PVT__a_q_io_deq_ready;
        CData/*0:0*/ __PVT__winner_1;
        CData/*2:0*/ __PVT__beatsLeft;
        CData/*0:0*/ __PVT__idle_1;
        CData/*0:0*/ __PVT__state_1;
        CData/*0:0*/ __PVT__unnamedblk1__DOT___GEN_1;
        CData/*0:0*/ __VdfgTmp_hec6944b2__0;
        CData/*0:0*/ __PVT__monitor__DOT___a_first_T_1;
        CData/*2:0*/ __PVT__monitor__DOT__a_first_counter;
        CData/*2:0*/ __PVT__monitor__DOT__opcode;
        CData/*2:0*/ __PVT__monitor__DOT__size;
        CData/*3:0*/ __PVT__monitor__DOT__source;
        CData/*2:0*/ __PVT__monitor__DOT__d_first_counter;
        CData/*2:0*/ __PVT__monitor__DOT__opcode_1;
        CData/*1:0*/ __PVT__monitor__DOT__param_1;
        CData/*2:0*/ __PVT__monitor__DOT__size_1;
        CData/*3:0*/ __PVT__monitor__DOT__source_1;
        CData/*0:0*/ __PVT__monitor__DOT__denied;
        CData/*2:0*/ __PVT__monitor__DOT__a_first_counter_1;
        CData/*0:0*/ __PVT__monitor__DOT__a_first_1;
        CData/*2:0*/ __PVT__monitor__DOT__d_first_counter_1;
        CData/*0:0*/ __PVT__monitor__DOT__d_first_1;
        CData/*0:0*/ __PVT__monitor__DOT___GEN_1;
        CData/*2:0*/ __PVT__monitor__DOT__d_first_counter_2;
        CData/*0:0*/ __PVT__monitor__DOT__d_first_2;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1;
        CData/*3:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__mask;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_39;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41;
        CData/*0:0*/ __PVT__a_q__DOT__full;
        CData/*0:0*/ __PVT__a_q__DOT__unnamedblk1__DOT__do_enq;
        VL_IN16(auto_in_a_bits_address,12,0);
        SData/*12:0*/ __PVT__monitor__DOT__address;
        SData/*15:0*/ __PVT__monitor__DOT__inflight;
        SData/*15:0*/ __PVT__monitor__DOT__inflight_1;
        SData/*15:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready;
        SData/*11:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3;
        SData/*11:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6;
    };
    struct {
        VL_IN(auto_in_a_bits_data,31,0);
        IData/*31:0*/ __PVT__monitor__DOT__watchdog;
        IData/*31:0*/ __PVT__monitor__DOT__watchdog_1;
        VlWide<5>/*130:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38;
        VlWide<5>/*142:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40;
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
        QData/*62:0*/ __PVT__a_q__DOT__ram;
    };

    // INTERNAL VARIABLES
    VysyxSoCFull__Syms* const vlSymsp;

    // CONSTRUCTORS
    VysyxSoCFull_TLError(VysyxSoCFull__Syms* symsp, const char* v__name);
    ~VysyxSoCFull_TLError();
    VL_UNCOPYABLE(VysyxSoCFull_TLError);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
