// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VysyxSoCFull.h for the primary calling header

#ifndef VERILATED_VYSYXSOCFULL_TLBUSBYPASS_H_
#define VERILATED_VYSYXSOCFULL_TLBUSBYPASS_H_  // guard

#include "verilated.h"

class VysyxSoCFull__Syms;

class VysyxSoCFull_TLBusBypass final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(auto_node_out_out_a_ready,0,0);
        VL_OUT8(auto_node_out_out_a_valid,0,0);
        VL_OUT8(auto_node_out_out_a_bits_opcode,2,0);
        VL_OUT8(auto_node_out_out_a_bits_size,2,0);
        VL_OUT8(auto_node_out_out_a_bits_source,3,0);
        VL_OUT8(auto_node_out_out_a_bits_mask,3,0);
        VL_OUT8(auto_node_out_out_d_ready,0,0);
        VL_IN8(auto_node_out_out_d_valid,0,0);
        VL_IN8(auto_node_out_out_d_bits_opcode,2,0);
        VL_IN8(auto_node_out_out_d_bits_param,1,0);
        VL_IN8(auto_node_out_out_d_bits_size,2,0);
        VL_IN8(auto_node_out_out_d_bits_source,3,0);
        VL_IN8(auto_node_out_out_d_bits_sink,4,0);
        VL_IN8(auto_node_out_out_d_bits_denied,0,0);
        VL_IN8(auto_node_out_out_d_bits_corrupt,0,0);
        VL_OUT8(auto_node_in_in_a_ready,0,0);
        VL_IN8(auto_node_in_in_a_valid,0,0);
        VL_IN8(auto_node_in_in_a_bits_opcode,2,0);
        VL_IN8(auto_node_in_in_a_bits_size,2,0);
        VL_IN8(auto_node_in_in_a_bits_source,3,0);
        VL_IN8(auto_node_in_in_a_bits_mask,3,0);
        VL_IN8(auto_node_in_in_d_ready,0,0);
        VL_OUT8(auto_node_in_in_d_valid,0,0);
        VL_OUT8(auto_node_in_in_d_bits_opcode,2,0);
        VL_OUT8(auto_node_in_in_d_bits_param,1,0);
        VL_OUT8(auto_node_in_in_d_bits_size,2,0);
        VL_OUT8(auto_node_in_in_d_bits_source,3,0);
        VL_OUT8(auto_node_in_in_d_bits_sink,4,0);
        VL_OUT8(auto_node_in_in_d_bits_denied,0,0);
        VL_OUT8(auto_node_in_in_d_bits_corrupt,0,0);
        VL_IN8(io_bypass,0,0);
        CData/*0:0*/ __PVT___bar_auto_out_0_a_valid;
        CData/*0:0*/ __PVT___bar_auto_out_0_d_ready;
        CData/*0:0*/ __PVT__bar__DOT__in_reset;
        CData/*0:0*/ __PVT__bar__DOT__bypass_reg;
        CData/*0:0*/ __PVT__bar__DOT__bypass;
        CData/*5:0*/ __PVT__bar__DOT__flight;
        CData/*2:0*/ __PVT__bar__DOT__r_counter;
        CData/*2:0*/ __PVT__bar__DOT__r_counter_3;
        CData/*2:0*/ __PVT__bar__DOT__stall_counter;
        CData/*0:0*/ __PVT__bar__DOT__stall_first;
        CData/*0:0*/ __PVT__bar__DOT__stall;
        CData/*0:0*/ __PVT__bar__DOT__unnamedblk1__DOT__a_first;
        CData/*2:0*/ __PVT__bar__DOT__unnamedblk1__DOT__r_beats1_3;
        CData/*0:0*/ __PVT__bar__DOT__unnamedblk1__DOT__d_first;
        CData/*0:0*/ __PVT__bar__DOT__monitor__DOT___a_first_T_1;
        CData/*2:0*/ __PVT__bar__DOT__monitor__DOT__a_first_counter;
        CData/*2:0*/ __PVT__bar__DOT__monitor__DOT__opcode;
        CData/*2:0*/ __PVT__bar__DOT__monitor__DOT__size;
        CData/*3:0*/ __PVT__bar__DOT__monitor__DOT__source;
        CData/*2:0*/ __PVT__bar__DOT__monitor__DOT__d_first_counter;
        CData/*2:0*/ __PVT__bar__DOT__monitor__DOT__opcode_1;
        CData/*1:0*/ __PVT__bar__DOT__monitor__DOT__param_1;
        CData/*2:0*/ __PVT__bar__DOT__monitor__DOT__size_1;
        CData/*3:0*/ __PVT__bar__DOT__monitor__DOT__source_1;
        CData/*4:0*/ __PVT__bar__DOT__monitor__DOT__sink;
        CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__denied;
        CData/*2:0*/ __PVT__bar__DOT__monitor__DOT__a_first_counter_1;
        CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__a_first_1;
        CData/*2:0*/ __PVT__bar__DOT__monitor__DOT__d_first_counter_1;
        CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__d_first_1;
        CData/*0:0*/ __PVT__bar__DOT__monitor__DOT___GEN_0;
    };
    struct {
        CData/*2:0*/ __PVT__bar__DOT__monitor__DOT__d_first_counter_2;
        CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__d_first_2;
        CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1;
        CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1;
        CData/*3:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__mask;
        CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp;
        CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_41;
        CData/*0:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43;
        CData/*0:0*/ __PVT__error__DOT__da_ready;
        CData/*2:0*/ __PVT__error__DOT__da_bits_opcode;
        CData/*0:0*/ __PVT__error__DOT__idle;
        CData/*0:0*/ __PVT__error__DOT__a_last;
        CData/*0:0*/ __PVT__error__DOT__da_first;
        CData/*0:0*/ __PVT__error__DOT__nodeIn_a_ready;
        CData/*0:0*/ __PVT__error__DOT__winner_1;
        CData/*0:0*/ __PVT__error__DOT__idle_1;
        CData/*0:0*/ __PVT__error__DOT__state_1;
        CData/*0:0*/ __PVT__error__DOT__muxState_1;
        CData/*0:0*/ __PVT__error__DOT__nodeIn_d_valid;
        CData/*0:0*/ __PVT__error__DOT___nodeIn_d_bits_T_3;
        CData/*3:0*/ __PVT__error__DOT___nodeIn_d_bits_T_16;
        CData/*3:0*/ __PVT__error__DOT___nodeIn_d_bits_T_19;
        CData/*2:0*/ __PVT__error__DOT___nodeIn_d_bits_T_24;
        CData/*0:0*/ __PVT__error__DOT__unnamedblk1__DOT___GEN_1;
        CData/*0:0*/ error__DOT____VdfgTmp_hc0029b36__0;
        CData/*0:0*/ __PVT__error__DOT__monitor__DOT___a_first_T_1;
        CData/*2:0*/ __PVT__error__DOT__monitor__DOT__opcode;
        CData/*3:0*/ __PVT__error__DOT__monitor__DOT__size;
        CData/*3:0*/ __PVT__error__DOT__monitor__DOT__source;
        CData/*2:0*/ __PVT__error__DOT__monitor__DOT__opcode_1;
        CData/*3:0*/ __PVT__error__DOT__monitor__DOT__size_1;
        CData/*3:0*/ __PVT__error__DOT__monitor__DOT__source_1;
        CData/*0:0*/ __PVT__error__DOT__monitor__DOT__denied;
        CData/*0:0*/ __PVT__error__DOT__monitor__DOT__a_first_1;
        CData/*0:0*/ __PVT__error__DOT__monitor__DOT__d_first_1;
        CData/*0:0*/ __PVT__error__DOT__monitor__DOT___GEN_0;
        CData/*0:0*/ __PVT__error__DOT__monitor__DOT__d_first_2;
        CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1;
        CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1;
        CData/*3:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__mask;
        CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp;
        CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_36;
        CData/*0:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_38;
        SData/*11:0*/ __PVT__bar__DOT__unnamedblk1__DOT__unnamedblk2__DOT___stall_beats1_decode_T;
        SData/*15:0*/ __PVT__bar__DOT__monitor__DOT__inflight;
        SData/*15:0*/ __PVT__bar__DOT__monitor__DOT__inflight_1;
        SData/*11:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3;
        SData/*11:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6;
        SData/*9:0*/ __PVT__error__DOT__a_last_beats1;
        SData/*9:0*/ __PVT__error__DOT__a_last_counter;
        SData/*9:0*/ __PVT__error__DOT__r_beats1;
        SData/*9:0*/ __PVT__error__DOT__r_counter;
        SData/*9:0*/ __PVT__error__DOT__beatsLeft;
        SData/*9:0*/ __PVT__error__DOT__monitor__DOT__a_first_counter;
        SData/*9:0*/ __PVT__error__DOT__monitor__DOT__d_first_counter;
        SData/*15:0*/ __PVT__error__DOT__monitor__DOT__inflight;
        SData/*9:0*/ __PVT__error__DOT__monitor__DOT__a_first_counter_1;
        SData/*9:0*/ __PVT__error__DOT__monitor__DOT__d_first_counter_1;
        SData/*15:0*/ __PVT__error__DOT__monitor__DOT__inflight_1;
        SData/*9:0*/ __PVT__error__DOT__monitor__DOT__d_first_counter_2;
        VL_OUT(auto_node_out_out_a_bits_address,31,0);
        VL_OUT(auto_node_out_out_a_bits_data,31,0);
        VL_IN(auto_node_out_out_d_bits_data,31,0);
        VL_IN(auto_node_in_in_a_bits_address,31,0);
    };
    struct {
        VL_IN(auto_node_in_in_a_bits_data,31,0);
        VL_OUT(auto_node_in_in_d_bits_data,31,0);
        IData/*31:0*/ __PVT__bar__DOT__monitor__DOT__address;
        IData/*31:0*/ __PVT__bar__DOT__monitor__DOT__watchdog;
        IData/*31:0*/ __PVT__bar__DOT__monitor__DOT__watchdog_1;
        VlWide<5>/*130:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_40;
        VlWide<5>/*142:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42;
        VlWide<5>/*142:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5;
        VlWide<5>/*130:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1;
        VlWide<5>/*142:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5;
        VlWide<5>/*130:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1;
        VlWide<5>/*142:0*/ __PVT__bar__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11;
        IData/*31:0*/ __PVT__bar__DOT__monitor__DOT__plusarg_reader__DOT__myplus;
        IData/*31:0*/ __PVT__bar__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus;
        VlWide<4>/*127:0*/ __PVT__error__DOT__monitor__DOT__address;
        VlWide<4>/*127:0*/ __PVT__error__DOT__monitor__DOT__inflight_sizes;
        IData/*31:0*/ __PVT__error__DOT__monitor__DOT__watchdog;
        VlWide<4>/*127:0*/ __PVT__error__DOT__monitor__DOT__inflight_sizes_1;
        IData/*31:0*/ __PVT__error__DOT__monitor__DOT__watchdog_1;
        VlWide<5>/*142:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_37;
        VlWide<5>/*142:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5;
        VlWide<5>/*130:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1;
        VlWide<5>/*142:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5;
        VlWide<5>/*131:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1;
        VlWide<5>/*142:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_11;
        IData/*26:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3;
        IData/*26:0*/ __PVT__error__DOT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6;
        IData/*31:0*/ __PVT__error__DOT__monitor__DOT__plusarg_reader__DOT__myplus;
        IData/*31:0*/ __PVT__error__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus;
        QData/*63:0*/ __PVT__bar__DOT__monitor__DOT__inflight_opcodes;
        QData/*63:0*/ __PVT__bar__DOT__monitor__DOT__inflight_sizes;
        QData/*63:0*/ __PVT__bar__DOT__monitor__DOT__inflight_sizes_1;
        QData/*63:0*/ __PVT__error__DOT__monitor__DOT__inflight_opcodes;
    };

    // INTERNAL VARIABLES
    VysyxSoCFull__Syms* const vlSymsp;

    // CONSTRUCTORS
    VysyxSoCFull_TLBusBypass(VysyxSoCFull__Syms* symsp, const char* v__name);
    ~VysyxSoCFull_TLBusBypass();
    VL_UNCOPYABLE(VysyxSoCFull_TLBusBypass);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
