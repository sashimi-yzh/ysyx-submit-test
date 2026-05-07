// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VysyxSoCFull.h for the primary calling header

#ifndef VERILATED_VYSYXSOCFULL_TLTOAXI4_H_
#define VERILATED_VYSYXSOCFULL_TLTOAXI4_H_  // guard

#include "verilated.h"

class VysyxSoCFull__Syms;

class VysyxSoCFull_TLToAXI4 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_OUT8(auto_in_a_ready,0,0);
        VL_IN8(auto_in_a_valid,0,0);
        VL_IN8(auto_in_a_bits_opcode,2,0);
        VL_IN8(auto_in_a_bits_param,2,0);
        VL_IN8(auto_in_a_bits_size,2,0);
        VL_IN8(auto_in_a_bits_source,6,0);
        VL_IN8(auto_in_a_bits_mask,3,0);
        VL_IN8(auto_in_a_bits_corrupt,0,0);
        VL_IN8(auto_in_d_ready,0,0);
        VL_OUT8(auto_in_d_valid,0,0);
        VL_OUT8(auto_in_d_bits_opcode,2,0);
        VL_OUT8(auto_in_d_bits_size,2,0);
        VL_OUT8(auto_in_d_bits_source,6,0);
        VL_OUT8(auto_in_d_bits_denied,0,0);
        VL_OUT8(auto_in_d_bits_corrupt,0,0);
        VL_IN8(auto_out_awready,0,0);
        VL_OUT8(auto_out_awvalid,0,0);
        VL_OUT8(auto_out_awid,4,0);
        VL_OUT8(auto_out_awlen,7,0);
        VL_OUT8(auto_out_awsize,2,0);
        VL_OUT8(auto_out_awburst,1,0);
        VL_OUT8(auto_out_awecho_tl_state_size,3,0);
        VL_OUT8(auto_out_awecho_tl_state_source,6,0);
        VL_IN8(auto_out_wready,0,0);
        VL_OUT8(auto_out_wvalid,0,0);
        VL_OUT8(auto_out_wstrb,3,0);
        VL_OUT8(auto_out_wlast,0,0);
        VL_OUT8(auto_out_bready,0,0);
        VL_IN8(auto_out_bvalid,0,0);
        VL_IN8(auto_out_bid,4,0);
        VL_IN8(auto_out_bresp,1,0);
        VL_IN8(auto_out_becho_tl_state_size,3,0);
        VL_IN8(auto_out_becho_tl_state_source,6,0);
        VL_IN8(auto_out_arready,0,0);
        VL_OUT8(auto_out_arvalid,0,0);
        VL_OUT8(auto_out_arid,4,0);
        VL_OUT8(auto_out_arlen,7,0);
        VL_OUT8(auto_out_arsize,2,0);
        VL_OUT8(auto_out_arburst,1,0);
        VL_OUT8(auto_out_arecho_tl_state_size,3,0);
        VL_OUT8(auto_out_arecho_tl_state_source,6,0);
        VL_OUT8(auto_out_rready,0,0);
        VL_IN8(auto_out_rvalid,0,0);
        VL_IN8(auto_out_rid,4,0);
        VL_IN8(auto_out_rresp,1,0);
        VL_IN8(auto_out_recho_tl_state_size,3,0);
        VL_IN8(auto_out_recho_tl_state_source,6,0);
        VL_IN8(auto_out_rlast,0,0);
        CData/*0:0*/ __PVT__count_22;
        CData/*0:0*/ __PVT__count_21;
        CData/*0:0*/ __PVT__count_20;
        CData/*0:0*/ __PVT__count_19;
        CData/*0:0*/ __PVT__count_18;
        CData/*0:0*/ __PVT__count_17;
        CData/*0:0*/ __PVT__count_16;
        CData/*0:0*/ __PVT__count_15;
        CData/*0:0*/ __PVT__count_14;
        CData/*0:0*/ __PVT__count_13;
        CData/*0:0*/ __PVT__count_12;
        CData/*0:0*/ __PVT__count_11;
        CData/*0:0*/ __PVT__count_10;
        CData/*0:0*/ __PVT__count_9;
    };
    struct {
        CData/*0:0*/ __PVT__count_8;
        CData/*0:0*/ __PVT__count_7;
        CData/*0:0*/ __PVT__idStall_4;
        CData/*0:0*/ __PVT__idStall_2;
        CData/*0:0*/ __PVT__idStall_0;
        CData/*0:0*/ __PVT___queue_arw_deq_q_io_deq_bits_wen;
        CData/*2:0*/ __PVT__r_beats1;
        CData/*2:0*/ __PVT__r_counter;
        CData/*0:0*/ __PVT__a_first;
        CData/*0:0*/ __PVT__a_last;
        CData/*0:0*/ __PVT__doneAW;
        CData/*0:0*/ __PVT__stall;
        CData/*0:0*/ __PVT___out_wvalid_T_3;
        CData/*0:0*/ __PVT__out_arw_valid;
        CData/*0:0*/ __PVT__r_holds_d;
        CData/*2:0*/ __PVT__b_delay;
        CData/*0:0*/ __PVT__r_wins;
        CData/*0:0*/ __PVT__r_first;
        CData/*0:0*/ __PVT__r_denied_r;
        CData/*0:0*/ __PVT__r_denied;
        CData/*4:0*/ __PVT__count;
        CData/*0:0*/ __PVT__write;
        CData/*0:0*/ __PVT___inc_T_22;
        CData/*0:0*/ __PVT__inc;
        CData/*4:0*/ __PVT__count_1;
        CData/*0:0*/ __PVT__write_1;
        CData/*0:0*/ __PVT__inc_1;
        CData/*4:0*/ __PVT__count_2;
        CData/*0:0*/ __PVT__write_2;
        CData/*0:0*/ __PVT__inc_2;
        CData/*4:0*/ __PVT__count_3;
        CData/*0:0*/ __PVT__write_3;
        CData/*0:0*/ __PVT__inc_3;
        CData/*4:0*/ __PVT__count_4;
        CData/*0:0*/ __PVT__write_4;
        CData/*0:0*/ __PVT__inc_4;
        CData/*4:0*/ __PVT__count_5;
        CData/*0:0*/ __PVT__write_5;
        CData/*0:0*/ __PVT__inc_5;
        CData/*4:0*/ __PVT__count_6;
        CData/*0:0*/ __PVT__write_6;
        CData/*0:0*/ __PVT__inc_6;
        CData/*0:0*/ __Vcellinp__nodeOut_wdeq_q__io_enq_valid;
        CData/*0:0*/ __Vcellinp__queue_arw_deq_q__io_deq_ready;
        CData/*2:0*/ __Vcellinp__queue_arw_deq_q__io_enq_bits_size;
        CData/*4:0*/ __Vcellinp__queue_arw_deq_q__io_enq_bits_id;
        CData/*4:0*/ __VdfgTmp_h3c545424__0;
        CData/*0:0*/ __VdfgTmp_hc0989b25__0;
        CData/*0:0*/ __PVT__monitor__DOT___a_first_T_1;
        CData/*2:0*/ __PVT__monitor__DOT__a_first_counter;
        CData/*2:0*/ __PVT__monitor__DOT__opcode;
        CData/*2:0*/ __PVT__monitor__DOT__param;
        CData/*2:0*/ __PVT__monitor__DOT__size;
        CData/*6:0*/ __PVT__monitor__DOT__source;
        CData/*2:0*/ __PVT__monitor__DOT__d_first_counter;
        CData/*2:0*/ __PVT__monitor__DOT__opcode_1;
        CData/*2:0*/ __PVT__monitor__DOT__size_1;
        CData/*6:0*/ __PVT__monitor__DOT__source_1;
        CData/*0:0*/ __PVT__monitor__DOT__denied;
        CData/*2:0*/ __PVT__monitor__DOT__a_first_counter_1;
        CData/*0:0*/ __PVT__monitor__DOT__a_first_1;
        CData/*2:0*/ __PVT__monitor__DOT__d_first_counter_1;
        CData/*0:0*/ __PVT__monitor__DOT__d_first_1;
        CData/*0:0*/ __PVT__monitor__DOT___GEN_1;
    };
    struct {
        CData/*2:0*/ __PVT__monitor__DOT__d_first_counter_2;
        CData/*0:0*/ __PVT__monitor__DOT__d_first_2;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__source_ok;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1;
        CData/*3:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__mask;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__source_ok_1;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp;
        CData/*0:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43;
        CData/*0:0*/ __PVT__nodeOut_wdeq_q__DOT__full;
        CData/*0:0*/ __PVT__nodeOut_wdeq_q__DOT__do_enq;
        CData/*0:0*/ __PVT__queue_arw_deq_q__DOT__full;
        CData/*0:0*/ __PVT__queue_arw_deq_q__DOT__io_deq_valid_0;
        CData/*0:0*/ __PVT__queue_arw_deq_q__DOT__do_enq;
        SData/*11:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3;
        SData/*11:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6;
        VL_IN(auto_in_a_bits_address,31,0);
        VL_IN(auto_in_a_bits_data,31,0);
        VL_OUT(auto_in_d_bits_data,31,0);
        VL_OUT(auto_out_awaddr,31,0);
        VL_OUT(auto_out_wdata,31,0);
        VL_OUT(auto_out_araddr,31,0);
        VL_IN(auto_out_rdata,31,0);
        IData/*31:0*/ __PVT__monitor__DOT__address;
        VlWide<4>/*127:0*/ __PVT__monitor__DOT__inflight;
        VlWide<16>/*511:0*/ __PVT__monitor__DOT__inflight_opcodes;
        VlWide<16>/*511:0*/ __PVT__monitor__DOT__inflight_sizes;
        IData/*31:0*/ __PVT__monitor__DOT__watchdog;
        VlWide<4>/*127:0*/ __PVT__monitor__DOT__inflight_1;
        VlWide<16>/*511:0*/ __PVT__monitor__DOT__inflight_sizes_1;
        IData/*31:0*/ __PVT__monitor__DOT__watchdog_1;
        VlWide<4>/*127:0*/ __PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready;
        VlWide<33>/*1026:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42;
        VlWide<33>/*1038:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44;
        VlWide<33>/*1038:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5;
        VlWide<33>/*1026:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1;
        VlWide<33>/*1038:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5;
        VlWide<33>/*1026:0*/ __PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1;
        IData/*31:0*/ __PVT__monitor__DOT__plusarg_reader__DOT__myplus;
        IData/*31:0*/ __PVT__monitor__DOT__plusarg_reader_1__DOT__myplus;
        QData/*36:0*/ __PVT__nodeOut_wdeq_q__DOT__ram;
        QData/*61:0*/ __PVT__queue_arw_deq_q__DOT__ram;
    };

    // INTERNAL VARIABLES
    VysyxSoCFull__Syms* const vlSymsp;

    // CONSTRUCTORS
    VysyxSoCFull_TLToAXI4(VysyxSoCFull__Syms* symsp, const char* v__name);
    ~VysyxSoCFull_TLToAXI4();
    VL_UNCOPYABLE(VysyxSoCFull_TLToAXI4);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
