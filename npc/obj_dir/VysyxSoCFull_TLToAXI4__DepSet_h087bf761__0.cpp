// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLToAXI4.h"
#include "VysyxSoCFull__Syms.h"

extern const VlWide<16>/*511:0*/ VysyxSoCFull__ConstPool__CONST_h93e1b771_0;
extern const VlWide<33>/*1055:0*/ VysyxSoCFull__ConstPool__CONST_h3892cc72_0;
extern const VlWide<33>/*1055:0*/ VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0;
extern const VlWide<33>/*1055:0*/ VysyxSoCFull__ConstPool__CONST_hf1d99c76_0;

VL_INLINE_OPT void VysyxSoCFull_TLToAXI4___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4__0(VysyxSoCFull_TLToAXI4* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLToAXI4___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4__0\n"); );
    // Init
    SData/*11:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T;
    __PVT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T = 0;
    CData/*4:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_6;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_6 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_7;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_7 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_8;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_8 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_9;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_9 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_10;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_10 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_11;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_11 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_12;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_12 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_13;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_13 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_14;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_14 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_15;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_15 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_16;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_16 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_17;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_17 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_18;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_18 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_19;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_19 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_20;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_20 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_21;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_21 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_22;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_22 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_27;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_27 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_28;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_28 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_29;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_29 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_31;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_31 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_32;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_32 = 0;
    VlWide<16>/*511:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33;
    VL_ZERO_W(512, __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33);
    VlWide<16>/*511:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1;
    VL_ZERO_W(512, __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1);
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___same_cycle_resp_T_1;
    __PVT__monitor__DOT__unnamedblk1__DOT___same_cycle_resp_T_1 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_34;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_34 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_35;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_35 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_36;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_36 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_37;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_37 = 0;
    VlWide<4>/*127:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39;
    VL_ZERO_W(128, __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39);
    VlWide<4>/*127:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_40;
    VL_ZERO_W(128, __PVT__monitor__DOT__unnamedblk1__DOT___GEN_40);
    VlWide<16>/*511:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1;
    VL_ZERO_W(512, __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1);
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk2__DOT___d_first_T_2;
    __PVT__monitor__DOT__unnamedblk2__DOT___d_first_T_2 = 0;
    CData/*2:0*/ __Vdly__r_counter;
    __Vdly__r_counter = 0;
    CData/*2:0*/ __Vdly__monitor__DOT__d_first_counter;
    __Vdly__monitor__DOT__d_first_counter = 0;
    VlWide<4>/*127:0*/ __Vdly__monitor__DOT__inflight;
    VL_ZERO_W(128, __Vdly__monitor__DOT__inflight);
    VlWide<16>/*511:0*/ __Vdly__monitor__DOT__inflight_opcodes;
    VL_ZERO_W(512, __Vdly__monitor__DOT__inflight_opcodes);
    VlWide<16>/*511:0*/ __Vdly__monitor__DOT__inflight_sizes;
    VL_ZERO_W(512, __Vdly__monitor__DOT__inflight_sizes);
    CData/*2:0*/ __Vdly__monitor__DOT__d_first_counter_1;
    __Vdly__monitor__DOT__d_first_counter_1 = 0;
    IData/*31:0*/ __Vdly__monitor__DOT__watchdog;
    __Vdly__monitor__DOT__watchdog = 0;
    CData/*2:0*/ __Vdly__monitor__DOT__d_first_counter_2;
    __Vdly__monitor__DOT__d_first_counter_2 = 0;
    IData/*31:0*/ __Vdly__monitor__DOT__watchdog_1;
    __Vdly__monitor__DOT__watchdog_1 = 0;
    CData/*2:0*/ __Vdly__monitor__DOT__a_first_counter;
    __Vdly__monitor__DOT__a_first_counter = 0;
    CData/*2:0*/ __Vdly__monitor__DOT__a_first_counter_1;
    __Vdly__monitor__DOT__a_first_counter_1 = 0;
    CData/*0:0*/ __Vdly__nodeOut_wdeq_q__DOT__full;
    __Vdly__nodeOut_wdeq_q__DOT__full = 0;
    CData/*0:0*/ __Vdly__queue_arw_deq_q__DOT__full;
    __Vdly__queue_arw_deq_q__DOT__full = 0;
    VlWide<4>/*127:0*/ __Vtemp_hd2b6c582__0;
    VlWide<4>/*127:0*/ __Vtemp_hde3016fd__0;
    VlWide<4>/*127:0*/ __Vtemp_hf6f22703__0;
    VlWide<16>/*511:0*/ __Vtemp_h4da8319f__0;
    VlWide<4>/*127:0*/ __Vtemp_hde3016fd__1;
    VlWide<4>/*127:0*/ __Vtemp_h136e34bf__0;
    VlWide<4>/*127:0*/ __Vtemp_hb6b3ff4d__0;
    VlWide<4>/*127:0*/ __Vtemp_hc4c123ef__0;
    VlWide<16>/*511:0*/ __Vtemp_hbd76628a__0;
    VlWide<4>/*127:0*/ __Vtemp_hd2b6c582__1;
    VlWide<4>/*127:0*/ __Vtemp_hb6b3ff4d__1;
    VlWide<4>/*127:0*/ __Vtemp_hc5f56152__0;
    VlWide<16>/*511:0*/ __Vtemp_hb529c94c__0;
    VlWide<4>/*127:0*/ __Vtemp_h3d43d0e3__0;
    VlWide<33>/*1055:0*/ __Vtemp_h0ac0b756__0;
    VlWide<33>/*1055:0*/ __Vtemp_h7174190e__0;
    VlWide<33>/*1055:0*/ __Vtemp_hf6ef8570__0;
    VlWide<33>/*1055:0*/ __Vtemp_h0ac0b756__1;
    VlWide<33>/*1055:0*/ __Vtemp_hb5fda8da__0;
    VlWide<33>/*1055:0*/ __Vtemp_h2afb9a52__0;
    VlWide<4>/*127:0*/ __Vtemp_hd2b6c582__2;
    VlWide<4>/*127:0*/ __Vtemp_hde3016fd__2;
    VlWide<4>/*127:0*/ __Vtemp_h46c47151__0;
    VlWide<4>/*127:0*/ __Vtemp_hd2b6c582__3;
    VlWide<4>/*127:0*/ __Vtemp_hb6b3ff4d__2;
    VlWide<4>/*127:0*/ __Vtemp_h61d6301d__0;
    // Body
    __Vdly__nodeOut_wdeq_q__DOT__full = vlSelf->__PVT__nodeOut_wdeq_q__DOT__full;
    __Vdly__r_counter = vlSelf->__PVT__r_counter;
    __Vdly__queue_arw_deq_q__DOT__full = vlSelf->__PVT__queue_arw_deq_q__DOT__full;
    __Vdly__monitor__DOT__a_first_counter = vlSelf->__PVT__monitor__DOT__a_first_counter;
    __Vdly__monitor__DOT__a_first_counter_1 = vlSelf->__PVT__monitor__DOT__a_first_counter_1;
    __Vdly__monitor__DOT__watchdog_1 = vlSelf->__PVT__monitor__DOT__watchdog_1;
    __Vdly__monitor__DOT__watchdog = vlSelf->__PVT__monitor__DOT__watchdog;
    __Vdly__monitor__DOT__inflight_sizes[0U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0U];
    __Vdly__monitor__DOT__inflight_sizes[1U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[1U];
    __Vdly__monitor__DOT__inflight_sizes[2U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[2U];
    __Vdly__monitor__DOT__inflight_sizes[3U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[3U];
    __Vdly__monitor__DOT__inflight_sizes[4U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[4U];
    __Vdly__monitor__DOT__inflight_sizes[5U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[5U];
    __Vdly__monitor__DOT__inflight_sizes[6U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[6U];
    __Vdly__monitor__DOT__inflight_sizes[7U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[7U];
    __Vdly__monitor__DOT__inflight_sizes[8U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[8U];
    __Vdly__monitor__DOT__inflight_sizes[9U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[9U];
    __Vdly__monitor__DOT__inflight_sizes[0xaU] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0xaU];
    __Vdly__monitor__DOT__inflight_sizes[0xbU] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0xbU];
    __Vdly__monitor__DOT__inflight_sizes[0xcU] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0xcU];
    __Vdly__monitor__DOT__inflight_sizes[0xdU] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0xdU];
    __Vdly__monitor__DOT__inflight_sizes[0xeU] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0xeU];
    __Vdly__monitor__DOT__inflight_sizes[0xfU] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0xfU];
    __Vdly__monitor__DOT__inflight_opcodes[0U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[0U];
    __Vdly__monitor__DOT__inflight_opcodes[1U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[1U];
    __Vdly__monitor__DOT__inflight_opcodes[2U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[2U];
    __Vdly__monitor__DOT__inflight_opcodes[3U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[3U];
    __Vdly__monitor__DOT__inflight_opcodes[4U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[4U];
    __Vdly__monitor__DOT__inflight_opcodes[5U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[5U];
    __Vdly__monitor__DOT__inflight_opcodes[6U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[6U];
    __Vdly__monitor__DOT__inflight_opcodes[7U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[7U];
    __Vdly__monitor__DOT__inflight_opcodes[8U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[8U];
    __Vdly__monitor__DOT__inflight_opcodes[9U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[9U];
    __Vdly__monitor__DOT__inflight_opcodes[0xaU] = 
        vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xaU];
    __Vdly__monitor__DOT__inflight_opcodes[0xbU] = 
        vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xbU];
    __Vdly__monitor__DOT__inflight_opcodes[0xcU] = 
        vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xcU];
    __Vdly__monitor__DOT__inflight_opcodes[0xdU] = 
        vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xdU];
    __Vdly__monitor__DOT__inflight_opcodes[0xeU] = 
        vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xeU];
    __Vdly__monitor__DOT__inflight_opcodes[0xfU] = 
        vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xfU];
    __Vdly__monitor__DOT__inflight[0U] = vlSelf->__PVT__monitor__DOT__inflight[0U];
    __Vdly__monitor__DOT__inflight[1U] = vlSelf->__PVT__monitor__DOT__inflight[1U];
    __Vdly__monitor__DOT__inflight[2U] = vlSelf->__PVT__monitor__DOT__inflight[2U];
    __Vdly__monitor__DOT__inflight[3U] = vlSelf->__PVT__monitor__DOT__inflight[3U];
    __Vdly__monitor__DOT__d_first_counter = vlSelf->__PVT__monitor__DOT__d_first_counter;
    __Vdly__monitor__DOT__d_first_counter_2 = vlSelf->__PVT__monitor__DOT__d_first_counter_2;
    __Vdly__monitor__DOT__d_first_counter_1 = vlSelf->__PVT__monitor__DOT__d_first_counter_1;
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ (((IData)(1U) 
                                              << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20318: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20318, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20320: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20320, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20324: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20324, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20326: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20326, "");
    }
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ ((((IData)(1U) 
                                               << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                              >> 1U) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count_1)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20330: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20330, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20332: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20332, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc_1)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count_1)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20336: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20336, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20338: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20338, "");
    }
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ ((((IData)(1U) 
                                               << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                              >> 2U) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count_2)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20342: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20342, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20344: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20344, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc_2)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count_2)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20348: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20348, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20350: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20350, "");
    }
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ ((((IData)(1U) 
                                               << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                              >> 3U) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count_3)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20354: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20354, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20356: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20356, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc_3)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count_3)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20360: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20360, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20362: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20362, "");
    }
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ ((((IData)(1U) 
                                               << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                              >> 4U) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count_4)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20366: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20366, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20368: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20368, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc_4)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count_4)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20372: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20372, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20374: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20374, "");
    }
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ ((((IData)(1U) 
                                               << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                              >> 5U) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count_5)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20378: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20378, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20380: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20380, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc_5)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count_5)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20384: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20384, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20386: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20386, "");
    }
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ ((((IData)(1U) 
                                               << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                              >> 6U) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count_6)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20390: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20390, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20392: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20392, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc_6)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count_6)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20396: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20396, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20398: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20398, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 7U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_7))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20402: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20402, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20404: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20404, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 7U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_7)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20408: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20408, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20410: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20410, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 8U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_8))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20414: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20414, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20416: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20416, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 8U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_8)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20420: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20420, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20422: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20422, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 9U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_9))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20426: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20426, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20428: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20428, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 9U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_9)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20432: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20432, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20434: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20434, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0xaU) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_10))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20438: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20438, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20440: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20440, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0xaU) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_10)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20444: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20444, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20446: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20446, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0xbU) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_11))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20450: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20450, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20452: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20452, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0xbU) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_11)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20456: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20456, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20458: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20458, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0xcU) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_12))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20462: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20462, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20464: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20464, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0xcU) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_12)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20468: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20468, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20470: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20470, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0xdU) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_13))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20474: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20474, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20476: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20476, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0xdU) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_13)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20480: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20480, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20482: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20482, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0xeU) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_14))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20486: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20486, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20488: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20488, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0xeU) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_14)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20492: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20492, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20494: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20494, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0xfU) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_15))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20498: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20498, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20500: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20500, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0xfU) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_15)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20504: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20504, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20506: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20506, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x10U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_16))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20510: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20510, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20512: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20512, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x10U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_16)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20516: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20516, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20518: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20518, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x11U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_17))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20522: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20522, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20524: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20524, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x11U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_17)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20528: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20528, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20530: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20530, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x12U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_18))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20534: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20534, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20536: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20536, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x12U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_18)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20540: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20540, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20542: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20542, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x13U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_19))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20546: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20546, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20548: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20548, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x13U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_19)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20552: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20552, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20554: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20554, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x14U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_20))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20558: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20558, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20560: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20560, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x14U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_20)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20564: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20564, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20566: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20566, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x15U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_21))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20570: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20570, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20572: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20572, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x15U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_21)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20576: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20576, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20578: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20578, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x16U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_22))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20582: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20582, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20584: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20584, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x16U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_22)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20588: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20588, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20590: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20590, "");
    }
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok 
        = (1U & ((((((((~ (IData)((0U != (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                                >> 4U))))) 
                       | (1U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                       >> 4U)))) | 
                      (2U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                    >> 4U)))) | (3U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                                     >> 4U)))) 
                    | (4U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                    >> 4U)))) | (5U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                                     >> 4U)))) 
                  | (6U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                  >> 4U)))) | (7U == 
                                               (7U 
                                                & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                                   >> 4U)))));
    __PVT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T 
        = ((0xbU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size))
            ? (0xfffU & ((IData)(0x1fU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size)))
            : 0U);
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_6 = 
        (0x1fU & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_address 
                  & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T))));
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1 
        = (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size))) 
                 | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size) 
                    & (~ (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_address 
                          >> 1U)))));
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1 
        = (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size))) 
                 | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size) 
                    & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_address 
                       >> 1U))));
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask 
        = ((8U & (((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1) 
                   << 3U) | (0xfffffff8U & ((vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_address 
                                             << 2U) 
                                            & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_address 
                                               << 3U))))) 
           | ((((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1) 
                | (2U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_address))) 
               << 2U) | ((((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1) 
                           | (1U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_address))) 
                          << 1U) | ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1) 
                                    | (0U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_address))))));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_7 = 
        (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid) 
          & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))) 
         & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_8 = 
        (3U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size) 
                      >> 1U)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_9 = 
        (((~ (IData)((0U != (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                   >> 4U))))) & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_8)) 
         & (3U == (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_address 
                   >> 0x1eU)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_10 
        = (2U < (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_param));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_11 
        = (0xfU != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_mask));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_12 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid) 
            & (7U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_13 
        = (1U & ((((((((~ (IData)((0U != (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                                >> 4U))))) 
                       | (1U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                       >> 4U)))) | 
                      (2U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                    >> 4U)))) | (3U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                                     >> 4U)))) 
                    | (4U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                    >> 4U)))) | (5U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                                     >> 4U)))) 
                  | (6U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                  >> 4U)))) | (7U == 
                                               (7U 
                                                & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                                   >> 4U)))));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_14 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid) 
            & (4U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_15 
        = ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
           & (3U == (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_address 
                     >> 0x1eU)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_16 
        = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_mask) 
           != (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_17 
        = ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_13) 
           & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_15));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_18 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid) 
            & (0U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_19 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid) 
            & (1U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_20 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid) 
            & (2U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_21 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid) 
            & (3U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_22 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid) 
            & (5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok_1 
        = ((((((((0U == (7U & ((IData)(vlSelf->auto_in_d_bits_source) 
                               >> 4U))) | (1U == (7U 
                                                  & ((IData)(vlSelf->auto_in_d_bits_source) 
                                                     >> 4U)))) 
                | (2U == (7U & ((IData)(vlSelf->auto_in_d_bits_source) 
                                >> 4U)))) | (3U == 
                                             (7U & 
                                              ((IData)(vlSelf->auto_in_d_bits_source) 
                                               >> 4U)))) 
              | (4U == (7U & ((IData)(vlSelf->auto_in_d_bits_source) 
                              >> 4U)))) | (5U == (7U 
                                                  & ((IData)(vlSelf->auto_in_d_bits_source) 
                                                     >> 4U)))) 
            | (6U == (7U & ((IData)(vlSelf->auto_in_d_bits_source) 
                            >> 4U)))) | (7U == (7U 
                                                & ((IData)(vlSelf->auto_in_d_bits_source) 
                                                   >> 4U))));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_27 
        = (1U & ((~ (IData)(vlSelf->auto_in_d_bits_denied)) 
                 | (IData)(vlSelf->auto_in_d_bits_corrupt)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_28 
        = (((IData)(vlSelf->auto_in_d_valid) & (~ (IData)(vlSelf->__PVT__r_wins))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_29 
        = (((IData)(vlSelf->auto_in_d_valid) & (IData)(vlSelf->__PVT__r_wins)) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0U] 
        = ((IData)(vlSelf->auto_in_d_bits_source) << 2U);
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[1U] 
        = ((IData)(vlSelf->auto_in_d_bits_source) >> 0x1eU);
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[2U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[3U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[4U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[5U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[6U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[7U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[8U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[9U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0xaU] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0xbU] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0xcU] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0xdU] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0xeU] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0xfU] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___same_cycle_resp_T_1 
        = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid) 
           & (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1)));
    __Vtemp_hd2b6c582__0[0U] = 1U;
    __Vtemp_hd2b6c582__0[1U] = 0U;
    __Vtemp_hd2b6c582__0[2U] = 0U;
    __Vtemp_hd2b6c582__0[3U] = 0U;
    __Vtemp_hde3016fd__0[0U] = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source;
    __Vtemp_hde3016fd__0[1U] = 0U;
    __Vtemp_hde3016fd__0[2U] = 0U;
    __Vtemp_hde3016fd__0[3U] = 0U;
    VL_SHIFTL_WWW(128,128,128, __Vtemp_hf6f22703__0, __Vtemp_hd2b6c582__0, __Vtemp_hde3016fd__0);
    if (__PVT__monitor__DOT__unnamedblk1__DOT___same_cycle_resp_T_1) {
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[0U] 
            = __Vtemp_hf6f22703__0[0U];
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[1U] 
            = __Vtemp_hf6f22703__0[1U];
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[2U] 
            = __Vtemp_hf6f22703__0[2U];
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[3U] 
            = __Vtemp_hf6f22703__0[3U];
    } else {
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[0U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[1U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[2U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[3U] = 0U;
    }
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_34 
        = ((IData)(vlSelf->auto_in_d_valid) & (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_1)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_35 
        = __PVT__monitor__DOT__unnamedblk1__DOT___GEN_34;
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp 
        = ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___same_cycle_resp_T_1) 
           & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
              == (IData)(vlSelf->auto_in_d_bits_source)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_36 
        = (((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35) 
            & (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp)) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_37 
        = (((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35) 
            & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_31 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid) 
            & (0U != (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_32 
        = (((IData)(vlSelf->auto_in_d_valid) & (0U 
                                                != (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    VL_SHIFTR_WWW(512,512,512, __Vtemp_h4da8319f__0, vlSelf->__PVT__monitor__DOT__inflight_opcodes, __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33);
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0U] 
        = __Vtemp_h4da8319f__0[0U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[1U] 
        = __Vtemp_h4da8319f__0[1U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[2U] 
        = __Vtemp_h4da8319f__0[2U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[3U] 
        = __Vtemp_h4da8319f__0[3U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[4U] 
        = __Vtemp_h4da8319f__0[4U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[5U] 
        = __Vtemp_h4da8319f__0[5U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[6U] 
        = __Vtemp_h4da8319f__0[6U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[7U] 
        = __Vtemp_h4da8319f__0[7U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[8U] 
        = __Vtemp_h4da8319f__0[8U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[9U] 
        = __Vtemp_h4da8319f__0[9U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0xaU] 
        = __Vtemp_h4da8319f__0[0xaU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0xbU] 
        = __Vtemp_h4da8319f__0[0xbU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0xcU] 
        = __Vtemp_h4da8319f__0[0xcU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0xdU] 
        = __Vtemp_h4da8319f__0[0xdU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0xeU] 
        = __Vtemp_h4da8319f__0[0xeU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0xfU] 
        = __Vtemp_h4da8319f__0[0xfU];
    if (VL_UNLIKELY(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19009: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19009, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19011: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19011, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_9))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19015: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19015, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19017: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19017, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19021: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19021, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19023: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19023, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (~ (IData)((0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19027: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19027, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19029: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19029, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19033: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19033, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19035: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19035, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_10)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19039: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock carries invalid grow param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19039, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19041: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19041, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_11)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19045: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19045, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19047: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19047, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19051: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19051, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19053: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19053, "");
    }
    if (VL_UNLIKELY(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19057: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19057, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19059: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19059, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_9))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19063: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19063, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19065: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19065, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19069: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19069, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19071: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19071, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (~ (IData)((0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19075: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19075, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19077: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19077, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19081: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19081, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19083: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19083, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_10)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19087: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm carries invalid grow param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19087, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19089: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19089, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (~ (IData)((0U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_param))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19093: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19093, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19095: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19095, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_11)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19099: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19099, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19101: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19101, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19105: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19105, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19107: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19107, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_13))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19111: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries Get type which master claims it can't emit (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19111, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19113: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19113, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_15))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19117: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries Get type which slave claims it can't support (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19117, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19119: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19119, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19123: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Get carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19123, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19125: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19125, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19129: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Get address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19129, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19131: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19131, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (0U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19135: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Get carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19135, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19137: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19137, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_16)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19141: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Get contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19141, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19143: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19143, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19147: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Get is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19147, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19149: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19149, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_17))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19153: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries PutFull type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19153, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19155: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19155, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19159: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19159, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19161: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19161, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19165: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19165, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19167: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19167, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (0U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19171: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19171, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19173: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19173, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_16)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19177: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19177, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19179: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19179, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_17))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19183: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries PutPartial type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19183, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19185: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19185, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19189: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19189, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19191: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19191, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19195: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19195, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19197: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19197, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (0U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19201: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19201, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19203: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19203, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (0U != ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_mask) 
                               & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19207: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19207, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19209: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19209, "");
    }
    if (VL_UNLIKELY(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_20)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19213: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19213, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19215: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19215, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19219: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19219, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19221: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19221, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19225: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19225, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19227: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19227, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (4U < (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19231: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic carries invalid opcode param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19231, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19233: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19233, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_16)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19237: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19237, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19239: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19239, "");
    }
    if (VL_UNLIKELY(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_21)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19243: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19243, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19245: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19245, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_21) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19249: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Logical carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19249, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19251: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19251, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_21) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19255: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Logical address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19255, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19257: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19257, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_21) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_param) 
                        >> 2U)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19261: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Logical carries invalid opcode param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19261, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19263: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19263, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_21) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_16)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19267: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Logical contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19267, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19269: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19269, "");
    }
    if (VL_UNLIKELY(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_22)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19273: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries Hint type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19273, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19275: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19275, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19279: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Hint carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19279, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19281: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19281, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19285: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Hint address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19285, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19287: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19287, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_param) 
                                     >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19291: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Hint carries invalid opcode param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19291, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19293: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19293, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_16)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19297: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Hint contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19297, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19299: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19299, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19303: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Hint is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19303, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19305: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19305, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19387: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19387, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19389: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19389, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
                     & (IData)(vlSelf->auto_in_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19393: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19393, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19395: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19395, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19399: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19399, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19401: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19401, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_27))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19405: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19405, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19407: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19407, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19423: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19423, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19425: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19425, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_param) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19429: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel param changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19429, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19431: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19431, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19435: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19435, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19437: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19437, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__source))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19441: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19441, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19443: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19443, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                     & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_address 
                        != vlSelf->__PVT__monitor__DOT__address)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19447: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel address changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19447, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19449: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19449, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                     & ((IData)(vlSelf->__PVT__r_wins) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19453: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19453, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19455: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19455, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                     & ((IData)(vlSelf->auto_in_d_bits_size) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19459: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19459, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19461: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19461, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                     & ((IData)(vlSelf->auto_in_d_bits_source) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19465: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19465, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19467: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19467, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                     & ((IData)(vlSelf->auto_in_d_bits_denied) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__denied))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19471: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel denied changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19471, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19473: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19473, "");
    }
    __Vtemp_hde3016fd__1[0U] = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source;
    __Vtemp_hde3016fd__1[1U] = 0U;
    __Vtemp_hde3016fd__1[2U] = 0U;
    __Vtemp_hde3016fd__1[3U] = 0U;
    VL_SHIFTR_WWW(128,128,128, __Vtemp_h136e34bf__0, vlSelf->__PVT__monitor__DOT__inflight, __Vtemp_hde3016fd__1);
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39[0U] 
        = __Vtemp_h136e34bf__0[0U];
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39[1U] 
        = __Vtemp_h136e34bf__0[1U];
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39[2U] 
        = __Vtemp_h136e34bf__0[2U];
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39[3U] 
        = __Vtemp_h136e34bf__0[3U];
    if (VL_UNLIKELY((((IData)(vlSelf->__PVT__monitor__DOT___GEN_1) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39[0U]))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19478: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel re-used a source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19478, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19480: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19480, "");
    }
    __Vtemp_hb6b3ff4d__0[0U] = vlSelf->auto_in_d_bits_source;
    __Vtemp_hb6b3ff4d__0[1U] = 0U;
    __Vtemp_hb6b3ff4d__0[2U] = 0U;
    __Vtemp_hb6b3ff4d__0[3U] = 0U;
    VL_SHIFTR_WWW(128,128,128, __Vtemp_hc4c123ef__0, vlSelf->__PVT__monitor__DOT__inflight, __Vtemp_hb6b3ff4d__0);
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_40[0U] 
        = __Vtemp_hc4c123ef__0[0U];
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_40[1U] 
        = __Vtemp_hc4c123ef__0[1U];
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_40[2U] 
        = __Vtemp_hc4c123ef__0[2U];
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_40[3U] 
        = __Vtemp_hc4c123ef__0[3U];
    if (VL_UNLIKELY((((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ (__PVT__monitor__DOT__unnamedblk1__DOT___GEN_40[0U] 
                           | (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19485: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19485, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19487: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19487, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_36) 
                     & (~ (((IData)(vlSelf->__PVT__r_wins) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode)))))
                                 : 0U)) | ((IData)(vlSelf->__PVT__r_wins) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode)))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19493: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19493, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19495: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19495, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_36) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size) 
                        != (IData)(vlSelf->auto_in_d_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19499: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19499, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19501: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19501, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_37) 
                     & (~ (((IData)(vlSelf->__PVT__r_wins) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & 
                                               (__PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0U] 
                                                >> 1U)))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (__PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0U] 
                                                     >> 1U))))))
                                 : 0U)) | ((IData)(vlSelf->__PVT__r_wins) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (__PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0U] 
                                                        >> 1U)))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (__PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0U] 
                                                              >> 1U))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19507: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19507, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19509: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19509, "");
    }
    VL_SHIFTR_WWW(512,512,512, __Vtemp_hbd76628a__0, vlSelf->__PVT__monitor__DOT__inflight_sizes, __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33);
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0U] 
        = __Vtemp_hbd76628a__0[0U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[1U] 
        = __Vtemp_hbd76628a__0[1U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[2U] 
        = __Vtemp_hbd76628a__0[2U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[3U] 
        = __Vtemp_hbd76628a__0[3U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[4U] 
        = __Vtemp_hbd76628a__0[4U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[5U] 
        = __Vtemp_hbd76628a__0[5U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[6U] 
        = __Vtemp_hbd76628a__0[6U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[7U] 
        = __Vtemp_hbd76628a__0[7U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[8U] 
        = __Vtemp_hbd76628a__0[8U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[9U] 
        = __Vtemp_hbd76628a__0[9U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0xaU] 
        = __Vtemp_hbd76628a__0[0xaU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0xbU] 
        = __Vtemp_hbd76628a__0[0xbU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0xcU] 
        = __Vtemp_hbd76628a__0[0xcU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0xdU] 
        = __Vtemp_hbd76628a__0[0xdU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0xeU] 
        = __Vtemp_hbd76628a__0[0xeU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0xfU] 
        = __Vtemp_hbd76628a__0[0xfU];
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_37) 
                     & ((IData)(vlSelf->auto_in_d_bits_size) 
                        != (7U & (__PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0U] 
                                  >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19514: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19514, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19516: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19516, "");
    }
    if (VL_UNLIKELY(((((((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_34) 
                         & (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1))) 
                        & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid)) 
                       & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                          == (IData)(vlSelf->auto_in_d_bits_source))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_d_ready)) 
                           | (IData)(vlSelf->auto_in_a_ready)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19521: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: ready check\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19521, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19523: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19523, "");
    }
    __Vtemp_hd2b6c582__1[0U] = 1U;
    __Vtemp_hd2b6c582__1[1U] = 0U;
    __Vtemp_hd2b6c582__1[2U] = 0U;
    __Vtemp_hd2b6c582__1[3U] = 0U;
    __Vtemp_hb6b3ff4d__1[0U] = vlSelf->auto_in_d_bits_source;
    __Vtemp_hb6b3ff4d__1[1U] = 0U;
    __Vtemp_hb6b3ff4d__1[2U] = 0U;
    __Vtemp_hb6b3ff4d__1[3U] = 0U;
    VL_SHIFTL_WWW(128,128,128, __Vtemp_hc5f56152__0, __Vtemp_hd2b6c582__1, __Vtemp_hb6b3ff4d__1);
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((0U != ((((vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[0U] 
                                            ^ ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35)
                                                ? __Vtemp_hc5f56152__0[0U]
                                                : 0U)) 
                                           | (vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[1U] 
                                              ^ ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35)
                                                  ? 
                                                 __Vtemp_hc5f56152__0[1U]
                                                  : 0U))) 
                                          | (vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[2U] 
                                             ^ ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35)
                                                 ? 
                                                __Vtemp_hc5f56152__0[2U]
                                                 : 0U))) 
                                         | (vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[3U] 
                                            ^ ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35)
                                                ? __Vtemp_hc5f56152__0[3U]
                                                : 0U)))) 
                                 | (0U == (((vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[0U] 
                                             | vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[1U]) 
                                            | vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[2U]) 
                                           | vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[3U])))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19529: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' and 'D' concurrent, despite minlatency > 0 (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19529, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19531: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19531, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (((vlSelf->__PVT__monitor__DOT__inflight[0U] 
                                            | vlSelf->__PVT__monitor__DOT__inflight[1U]) 
                                           | vlSelf->__PVT__monitor__DOT__inflight[2U]) 
                                          | vlSelf->__PVT__monitor__DOT__inflight[3U])) 
                                  | (0U == vlSelf->__PVT__monitor__DOT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->__PVT__monitor__DOT__watchdog 
                                    < vlSelf->__PVT__monitor__DOT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19537: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19537, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19539: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19539, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (((vlSelf->__PVT__monitor__DOT__inflight_1[0U] 
                                            | vlSelf->__PVT__monitor__DOT__inflight_1[1U]) 
                                           | vlSelf->__PVT__monitor__DOT__inflight_1[2U]) 
                                          | vlSelf->__PVT__monitor__DOT__inflight_1[3U])) 
                                  | (0U == vlSelf->__PVT__monitor__DOT__plusarg_reader_1__DOT__myplus)) 
                                 | (vlSelf->__PVT__monitor__DOT__watchdog_1 
                                    < vlSelf->__PVT__monitor__DOT__plusarg_reader_1__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19559: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19559, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19561: Assertion failed in %NysyxSoCFull.asic.chipMaster.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19561, "");
    }
    if (vlSymsp->TOP.reset) {
        __Vtemp_hb529c94c__0[1U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[1U];
        __Vtemp_hb529c94c__0[2U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[2U];
        __Vtemp_hb529c94c__0[3U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[3U];
        __Vtemp_hb529c94c__0[4U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[4U];
        __Vtemp_hb529c94c__0[5U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[5U];
        __Vtemp_hb529c94c__0[6U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[6U];
        __Vtemp_hb529c94c__0[7U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[7U];
        __Vtemp_hb529c94c__0[8U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[8U];
        __Vtemp_hb529c94c__0[9U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[9U];
        __Vtemp_hb529c94c__0[0xaU] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xaU];
        __Vtemp_hb529c94c__0[0xbU] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xbU];
        __Vtemp_hb529c94c__0[0xcU] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xcU];
        __Vtemp_hb529c94c__0[0xdU] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xdU];
        __Vtemp_hb529c94c__0[0xeU] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xeU];
        __Vtemp_hb529c94c__0[0xfU] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xfU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0U] 
            = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[1U] 
            = __Vtemp_hb529c94c__0[1U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[2U] 
            = __Vtemp_hb529c94c__0[2U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[3U] 
            = __Vtemp_hb529c94c__0[3U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[4U] 
            = __Vtemp_hb529c94c__0[4U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[5U] 
            = __Vtemp_hb529c94c__0[5U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[6U] 
            = __Vtemp_hb529c94c__0[6U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[7U] 
            = __Vtemp_hb529c94c__0[7U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[8U] 
            = __Vtemp_hb529c94c__0[8U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[9U] 
            = __Vtemp_hb529c94c__0[9U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xaU] 
            = __Vtemp_hb529c94c__0[0xaU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xbU] 
            = __Vtemp_hb529c94c__0[0xbU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xcU] 
            = __Vtemp_hb529c94c__0[0xcU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xdU] 
            = __Vtemp_hb529c94c__0[0xdU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xeU] 
            = __Vtemp_hb529c94c__0[0xeU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xfU] 
            = __Vtemp_hb529c94c__0[0xfU];
        __Vtemp_h3d43d0e3__0[1U] = 0U;
        __Vtemp_h3d43d0e3__0[2U] = 0U;
        __Vtemp_h3d43d0e3__0[3U] = 0U;
        vlSelf->__PVT__monitor__DOT__inflight_1[0U] = 0U;
    } else {
        __Vtemp_hb529c94c__0[1U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[1U];
        __Vtemp_hb529c94c__0[2U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[2U];
        __Vtemp_hb529c94c__0[3U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[3U];
        __Vtemp_hb529c94c__0[4U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[4U];
        __Vtemp_hb529c94c__0[5U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[5U];
        __Vtemp_hb529c94c__0[6U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[6U];
        __Vtemp_hb529c94c__0[7U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[7U];
        __Vtemp_hb529c94c__0[8U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[8U];
        __Vtemp_hb529c94c__0[9U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[9U];
        __Vtemp_hb529c94c__0[0xaU] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xaU];
        __Vtemp_hb529c94c__0[0xbU] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xbU];
        __Vtemp_hb529c94c__0[0xcU] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xcU];
        __Vtemp_hb529c94c__0[0xdU] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xdU];
        __Vtemp_hb529c94c__0[0xeU] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xeU];
        __Vtemp_hb529c94c__0[0xfU] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xfU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0U] 
            = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[1U] 
            = __Vtemp_hb529c94c__0[1U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[2U] 
            = __Vtemp_hb529c94c__0[2U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[3U] 
            = __Vtemp_hb529c94c__0[3U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[4U] 
            = __Vtemp_hb529c94c__0[4U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[5U] 
            = __Vtemp_hb529c94c__0[5U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[6U] 
            = __Vtemp_hb529c94c__0[6U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[7U] 
            = __Vtemp_hb529c94c__0[7U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[8U] 
            = __Vtemp_hb529c94c__0[8U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[9U] 
            = __Vtemp_hb529c94c__0[9U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xaU] 
            = __Vtemp_hb529c94c__0[0xaU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xbU] 
            = __Vtemp_hb529c94c__0[0xbU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xcU] 
            = __Vtemp_hb529c94c__0[0xcU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xdU] 
            = __Vtemp_hb529c94c__0[0xdU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xeU] 
            = __Vtemp_hb529c94c__0[0xeU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xfU] 
            = __Vtemp_hb529c94c__0[0xfU];
        __Vtemp_h3d43d0e3__0[1U] = vlSelf->__PVT__monitor__DOT__inflight_1[1U];
        __Vtemp_h3d43d0e3__0[2U] = vlSelf->__PVT__monitor__DOT__inflight_1[2U];
        __Vtemp_h3d43d0e3__0[3U] = vlSelf->__PVT__monitor__DOT__inflight_1[3U];
        vlSelf->__PVT__monitor__DOT__inflight_1[0U] 
            = vlSelf->__PVT__monitor__DOT__inflight_1[0U];
    }
    vlSelf->__PVT__monitor__DOT__inflight_1[1U] = __Vtemp_h3d43d0e3__0[1U];
    vlSelf->__PVT__monitor__DOT__inflight_1[2U] = __Vtemp_h3d43d0e3__0[2U];
    vlSelf->__PVT__monitor__DOT__inflight_1[3U] = __Vtemp_h3d43d0e3__0[3U];
    vlSelf->__PVT__count_7 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                    & (((IData)(vlSelf->__PVT__count_7) 
                                        + ((((IData)(1U) 
                                             << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                            >> 7U) 
                                           & (IData)(vlSelf->__PVT___inc_T_22))) 
                                       - ((((IData)(1U) 
                                            << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                           >> 7U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_8 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                    & (((IData)(vlSelf->__PVT__count_8) 
                                        + ((((IData)(1U) 
                                             << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                            >> 8U) 
                                           & (IData)(vlSelf->__PVT___inc_T_22))) 
                                       - ((((IData)(1U) 
                                            << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                           >> 8U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_9 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                    & (((IData)(vlSelf->__PVT__count_9) 
                                        + ((((IData)(1U) 
                                             << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                            >> 9U) 
                                           & (IData)(vlSelf->__PVT___inc_T_22))) 
                                       - ((((IData)(1U) 
                                            << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                           >> 9U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_10 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_10) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0xaU) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0xaU) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_11 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_11) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0xbU) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0xbU) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_12 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_12) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0xcU) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0xcU) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_13 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_13) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0xdU) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0xdU) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_14 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_14) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0xeU) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0xeU) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_15 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_15) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0xfU) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0xfU) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_16 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_16) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x10U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x10U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_17 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_17) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x11U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x11U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_18 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_18) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x12U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x12U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_19 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_19) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x13U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x13U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_20 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_20) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x14U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x14U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_21 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_21) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x15U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x15U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_22 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_22) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x16U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x16U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__b_delay = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bvalid) 
                               & (~ (IData)(vlSelf->auto_out_bready)))
                               ? (7U & ((IData)(1U) 
                                        + (IData)(vlSelf->__PVT__b_delay)))
                               : 0U);
    if (vlSelf->__PVT__nodeOut_wdeq_q__DOT__do_enq) {
        vlSelf->__PVT__nodeOut_wdeq_q__DOT__ram = (
                                                   ((QData)((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_data)) 
                                                    << 5U) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_mask) 
                                                                       << 1U) 
                                                                      | (IData)(vlSelf->__PVT__a_last)))));
    }
    if (vlSelf->__PVT__inc_6) {
        vlSelf->__PVT__write_6 = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                           >> 2U)));
    }
    if (vlSelf->__PVT__inc_3) {
        vlSelf->__PVT__write_3 = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                           >> 2U)));
    }
    if (vlSelf->__PVT__inc_1) {
        vlSelf->__PVT__write_1 = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                           >> 2U)));
    }
    if (vlSelf->__PVT__inc_5) {
        vlSelf->__PVT__write_5 = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                           >> 2U)));
    }
    if (vlSelf->__PVT__inc_4) {
        vlSelf->__PVT__write_4 = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                           >> 2U)));
    }
    if (vlSelf->__PVT__inc) {
        vlSelf->__PVT__write = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                         >> 2U)));
    }
    if (vlSelf->__PVT__inc_2) {
        vlSelf->__PVT__write_2 = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                           >> 2U)));
    }
    if (vlSelf->__PVT__queue_arw_deq_q__DOT__do_enq) {
        vlSelf->__PVT__queue_arw_deq_q__DOT__ram = 
            (((QData)((IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
              << 0x39U) | (((QData)((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_address)) 
                            << 0x19U) | (QData)((IData)(
                                                        (0x1000U 
                                                         | ((0x1fe0000U 
                                                             & ((~ 
                                                                 (0x7fffU 
                                                                  & (((IData)(0x3ffU) 
                                                                      << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size)) 
                                                                     >> 2U))) 
                                                                << 0x11U)) 
                                                            | ((((0U 
                                                                  != 
                                                                  (3U 
                                                                   & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size) 
                                                                      >> 1U)))
                                                                  ? 2U
                                                                  : (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size)) 
                                                                << 0xeU) 
                                                               | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size) 
                                                                   << 8U) 
                                                                  | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                                                      << 1U) 
                                                                     | (1U 
                                                                        & (~ 
                                                                           ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                                            >> 2U))))))))))));
    }
    if (vlSymsp->TOP.reset) {
        __Vdly__nodeOut_wdeq_q__DOT__full = 0U;
        vlSelf->__PVT__nodeOut_wdeq_q__DOT__full = __Vdly__nodeOut_wdeq_q__DOT__full;
        vlSelf->__PVT__count_6 = 0U;
        vlSelf->__PVT__count_5 = 0U;
        vlSelf->__PVT__count_3 = 0U;
        vlSelf->__PVT__count_1 = 0U;
        vlSelf->__PVT__count_2 = 0U;
        vlSelf->__PVT__count = 0U;
        vlSelf->__PVT__count_4 = 0U;
        __Vdly__r_counter = 0U;
        vlSelf->__PVT__r_counter = __Vdly__r_counter;
        __Vdly__queue_arw_deq_q__DOT__full = 0U;
    } else {
        if (((((IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full) 
               & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_wready)) 
              & (IData)(vlSelf->auto_out_wvalid)) != (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__do_enq))) {
            __Vdly__nodeOut_wdeq_q__DOT__full = vlSelf->__PVT__nodeOut_wdeq_q__DOT__do_enq;
        }
        vlSelf->__PVT__nodeOut_wdeq_q__DOT__full = __Vdly__nodeOut_wdeq_q__DOT__full;
        vlSelf->__PVT__count_6 = (0x1fU & (((IData)(vlSelf->__PVT__count_6) 
                                            + (IData)(vlSelf->__PVT__inc_6)) 
                                           - ((((IData)(1U) 
                                                << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                               >> 6U) 
                                              & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        vlSelf->__PVT__count_5 = (0x1fU & (((IData)(vlSelf->__PVT__count_5) 
                                            + (IData)(vlSelf->__PVT__inc_5)) 
                                           - ((((IData)(1U) 
                                                << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                               >> 5U) 
                                              & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        vlSelf->__PVT__count_3 = (0x1fU & (((IData)(vlSelf->__PVT__count_3) 
                                            + (IData)(vlSelf->__PVT__inc_3)) 
                                           - ((((IData)(1U) 
                                                << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                               >> 3U) 
                                              & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        vlSelf->__PVT__count_1 = (0x1fU & (((IData)(vlSelf->__PVT__count_1) 
                                            + (IData)(vlSelf->__PVT__inc_1)) 
                                           - ((((IData)(1U) 
                                                << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                               >> 1U) 
                                              & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        vlSelf->__PVT__count_2 = (0x1fU & (((IData)(vlSelf->__PVT__count_2) 
                                            + (IData)(vlSelf->__PVT__inc_2)) 
                                           - ((((IData)(1U) 
                                                << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                               >> 2U) 
                                              & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        vlSelf->__PVT__count = (0x1fU & (((IData)(vlSelf->__PVT__count) 
                                          + (IData)(vlSelf->__PVT__inc)) 
                                         - (((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        vlSelf->__PVT__count_4 = (0x1fU & (((IData)(vlSelf->__PVT__count_4) 
                                            + (IData)(vlSelf->__PVT__inc_4)) 
                                           - ((((IData)(1U) 
                                                << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                               >> 4U) 
                                              & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        if (((IData)(vlSelf->auto_in_a_ready) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid))) {
            __Vdly__r_counter = (7U & ((IData)(vlSelf->__PVT__a_first)
                                        ? (IData)(vlSelf->__PVT__r_beats1)
                                        : ((IData)(vlSelf->__PVT__r_counter) 
                                           - (IData)(1U))));
        }
        vlSelf->__PVT__r_counter = __Vdly__r_counter;
        if (((IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__do_enq) 
             != (((IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full) 
                  & (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_deq_ready)) 
                 & (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__io_deq_valid_0)))) {
            __Vdly__queue_arw_deq_q__DOT__full = vlSelf->__PVT__queue_arw_deq_q__DOT__do_enq;
        }
    }
    vlSelf->__PVT__queue_arw_deq_q__DOT__full = __Vdly__queue_arw_deq_q__DOT__full;
    if (((IData)(vlSelf->__PVT__monitor__DOT___a_first_T_1) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter)))))) {
        vlSelf->__PVT__monitor__DOT__opcode = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode;
        vlSelf->__PVT__monitor__DOT__param = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_param;
        vlSelf->__PVT__monitor__DOT__size = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size;
        vlSelf->__PVT__monitor__DOT__source = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source;
        vlSelf->__PVT__monitor__DOT__address = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_address;
    }
    __PVT__monitor__DOT__unnamedblk2__DOT___d_first_T_2 
        = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_d_ready) 
           & (IData)(vlSelf->auto_in_d_valid));
    if (vlSymsp->TOP.reset) {
        vlSelf->__PVT__doneAW = 0U;
        vlSelf->__PVT__r_holds_d = 0U;
        __Vdly__monitor__DOT__a_first_counter = 0U;
        __Vdly__monitor__DOT__a_first_counter_1 = 0U;
        __Vdly__monitor__DOT__d_first_counter = 0U;
        __Vdly__monitor__DOT__inflight[0U] = 0U;
        __Vdly__monitor__DOT__inflight[1U] = 0U;
        __Vdly__monitor__DOT__inflight[2U] = 0U;
        __Vdly__monitor__DOT__inflight[3U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[1U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[2U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[3U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[4U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[5U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[6U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[7U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[8U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[9U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0xaU] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0xbU] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0xcU] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0xdU] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0xeU] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0xfU] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[1U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[2U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[3U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[4U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[5U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[6U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[7U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[8U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[9U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0xaU] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0xbU] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0xcU] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0xdU] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0xeU] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0xfU] = 0U;
        __Vdly__monitor__DOT__d_first_counter_1 = 0U;
        __Vdly__monitor__DOT__watchdog = 0U;
        __Vdly__monitor__DOT__d_first_counter_2 = 0U;
        __Vdly__monitor__DOT__watchdog_1 = 0U;
    } else {
        if (((IData)(vlSelf->auto_in_a_ready) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid))) {
            vlSelf->__PVT__doneAW = (1U & (~ (IData)(vlSelf->__PVT__a_last)));
        }
        if (((IData)(vlSelf->auto_out_rready) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rvalid))) {
            vlSelf->__PVT__r_holds_d = (1U & (~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast)));
        }
        if (vlSelf->__PVT__monitor__DOT___a_first_T_1) {
            vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 
                = ((0xbU >= (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size))
                    ? (0xfffU & ((IData)(0x1fU) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size)))
                    : 0U);
            __Vdly__monitor__DOT__a_first_counter = 
                (7U & ((0U != (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter))
                        ? ((IData)(vlSelf->__PVT__monitor__DOT__a_first_counter) 
                           - (IData)(1U)) : ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))
                                              ? 0U : 
                                             (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3) 
                                                 >> 2U)))));
            __Vdly__monitor__DOT__a_first_counter_1 
                = (7U & ((IData)(vlSelf->__PVT__monitor__DOT__a_first_1)
                          ? ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))
                              ? 0U : (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3) 
                                         >> 2U))) : 
                         ((IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1) 
                          - (IData)(1U))));
        }
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
               << 2U);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[1U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
               >> 0x1eU);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[2U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[3U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[4U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[5U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[6U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[7U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[8U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[9U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0xaU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0xbU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0xcU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0xdU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0xeU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0xfU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x10U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x11U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x12U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x13U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x14U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x15U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x16U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x17U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x18U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x19U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x1aU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x1bU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x1cU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x1dU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x1eU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x1fU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x20U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0U] 
            = ((IData)(vlSelf->auto_in_d_bits_source) 
               << 2U);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[1U] 
            = ((IData)(vlSelf->auto_in_d_bits_source) 
               >> 0x1eU);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[2U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[3U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[4U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[5U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[6U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[7U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[8U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[9U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0xaU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0xbU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0xcU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0xdU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0xeU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0xfU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x10U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x11U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x12U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x13U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x14U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x15U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x16U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x17U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x18U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x19U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x1aU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x1bU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x1cU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x1dU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x1eU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x1fU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x20U] = 0U;
        VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h0ac0b756__0, VysyxSoCFull__ConstPool__CONST_h3892cc72_0, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0U] 
               & __Vtemp_h0ac0b756__0[0U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[1U] 
               & __Vtemp_h0ac0b756__0[1U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[2U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[2U] 
               & __Vtemp_h0ac0b756__0[2U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[3U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[3U] 
               & __Vtemp_h0ac0b756__0[3U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[4U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[4U] 
               & __Vtemp_h0ac0b756__0[4U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[5U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[5U] 
               & __Vtemp_h0ac0b756__0[5U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[6U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[6U] 
               & __Vtemp_h0ac0b756__0[6U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[7U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[7U] 
               & __Vtemp_h0ac0b756__0[7U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[8U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[8U] 
               & __Vtemp_h0ac0b756__0[8U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[9U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[9U] 
               & __Vtemp_h0ac0b756__0[9U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xaU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xaU] 
               & __Vtemp_h0ac0b756__0[0xaU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xbU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xbU] 
               & __Vtemp_h0ac0b756__0[0xbU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xcU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xcU] 
               & __Vtemp_h0ac0b756__0[0xcU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xdU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xdU] 
               & __Vtemp_h0ac0b756__0[0xdU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xeU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xeU] 
               & __Vtemp_h0ac0b756__0[0xeU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xfU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xfU] 
               & __Vtemp_h0ac0b756__0[0xfU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x10U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x10U] 
               & __Vtemp_h0ac0b756__0[0x10U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x11U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x11U] 
               & __Vtemp_h0ac0b756__0[0x11U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x12U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x12U] 
               & __Vtemp_h0ac0b756__0[0x12U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x13U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x13U] 
               & __Vtemp_h0ac0b756__0[0x13U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x14U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x14U] 
               & __Vtemp_h0ac0b756__0[0x14U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x15U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x15U] 
               & __Vtemp_h0ac0b756__0[0x15U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x16U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x16U] 
               & __Vtemp_h0ac0b756__0[0x16U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x17U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x17U] 
               & __Vtemp_h0ac0b756__0[0x17U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x18U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x18U] 
               & __Vtemp_h0ac0b756__0[0x18U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x19U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x19U] 
               & __Vtemp_h0ac0b756__0[0x19U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x1aU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1aU] 
               & __Vtemp_h0ac0b756__0[0x1aU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x1bU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1bU] 
               & __Vtemp_h0ac0b756__0[0x1bU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x1cU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1cU] 
               & __Vtemp_h0ac0b756__0[0x1cU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x1dU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1dU] 
               & __Vtemp_h0ac0b756__0[0x1dU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x1eU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1eU] 
               & __Vtemp_h0ac0b756__0[0x1eU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x1fU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1fU] 
               & __Vtemp_h0ac0b756__0[0x1fU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x20U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x20U] 
               & __Vtemp_h0ac0b756__0[0x20U]);
        if (vlSelf->__PVT__monitor__DOT___GEN_1) {
            __Vtemp_h7174190e__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                              << 1U));
            __Vtemp_hb5fda8da__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size) 
                                              << 1U));
        } else {
            __Vtemp_h7174190e__0[0U] = 0U;
            __Vtemp_hb5fda8da__0[0U] = 0U;
        }
        __Vtemp_h7174190e__0[1U] = 0U;
        __Vtemp_h7174190e__0[2U] = 0U;
        __Vtemp_h7174190e__0[3U] = 0U;
        __Vtemp_h7174190e__0[4U] = 0U;
        __Vtemp_h7174190e__0[5U] = 0U;
        __Vtemp_h7174190e__0[6U] = 0U;
        __Vtemp_h7174190e__0[7U] = 0U;
        __Vtemp_h7174190e__0[8U] = 0U;
        __Vtemp_h7174190e__0[9U] = 0U;
        __Vtemp_h7174190e__0[0xaU] = 0U;
        __Vtemp_h7174190e__0[0xbU] = 0U;
        __Vtemp_h7174190e__0[0xcU] = 0U;
        __Vtemp_h7174190e__0[0xdU] = 0U;
        __Vtemp_h7174190e__0[0xeU] = 0U;
        __Vtemp_h7174190e__0[0xfU] = 0U;
        __Vtemp_h7174190e__0[0x10U] = 0U;
        __Vtemp_h7174190e__0[0x11U] = 0U;
        __Vtemp_h7174190e__0[0x12U] = 0U;
        __Vtemp_h7174190e__0[0x13U] = 0U;
        __Vtemp_h7174190e__0[0x14U] = 0U;
        __Vtemp_h7174190e__0[0x15U] = 0U;
        __Vtemp_h7174190e__0[0x16U] = 0U;
        __Vtemp_h7174190e__0[0x17U] = 0U;
        __Vtemp_h7174190e__0[0x18U] = 0U;
        __Vtemp_h7174190e__0[0x19U] = 0U;
        __Vtemp_h7174190e__0[0x1aU] = 0U;
        __Vtemp_h7174190e__0[0x1bU] = 0U;
        __Vtemp_h7174190e__0[0x1cU] = 0U;
        __Vtemp_h7174190e__0[0x1dU] = 0U;
        __Vtemp_h7174190e__0[0x1eU] = 0U;
        __Vtemp_h7174190e__0[0x1fU] = 0U;
        __Vtemp_h7174190e__0[0x20U] = 0U;
        VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_hf6ef8570__0, __Vtemp_h7174190e__0, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0U] 
               & __Vtemp_hf6ef8570__0[0U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[1U] 
               & __Vtemp_hf6ef8570__0[1U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[2U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[2U] 
               & __Vtemp_hf6ef8570__0[2U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[3U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[3U] 
               & __Vtemp_hf6ef8570__0[3U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[4U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[4U] 
               & __Vtemp_hf6ef8570__0[4U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[5U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[5U] 
               & __Vtemp_hf6ef8570__0[5U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[6U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[6U] 
               & __Vtemp_hf6ef8570__0[6U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[7U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[7U] 
               & __Vtemp_hf6ef8570__0[7U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[8U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[8U] 
               & __Vtemp_hf6ef8570__0[8U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[9U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[9U] 
               & __Vtemp_hf6ef8570__0[9U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xaU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xaU] 
               & __Vtemp_hf6ef8570__0[0xaU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xbU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xbU] 
               & __Vtemp_hf6ef8570__0[0xbU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xcU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xcU] 
               & __Vtemp_hf6ef8570__0[0xcU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xdU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xdU] 
               & __Vtemp_hf6ef8570__0[0xdU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xeU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xeU] 
               & __Vtemp_hf6ef8570__0[0xeU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xfU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xfU] 
               & __Vtemp_hf6ef8570__0[0xfU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x10U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x10U] 
               & __Vtemp_hf6ef8570__0[0x10U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x11U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x11U] 
               & __Vtemp_hf6ef8570__0[0x11U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x12U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x12U] 
               & __Vtemp_hf6ef8570__0[0x12U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x13U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x13U] 
               & __Vtemp_hf6ef8570__0[0x13U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x14U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x14U] 
               & __Vtemp_hf6ef8570__0[0x14U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x15U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x15U] 
               & __Vtemp_hf6ef8570__0[0x15U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x16U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x16U] 
               & __Vtemp_hf6ef8570__0[0x16U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x17U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x17U] 
               & __Vtemp_hf6ef8570__0[0x17U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x18U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x18U] 
               & __Vtemp_hf6ef8570__0[0x18U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x19U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x19U] 
               & __Vtemp_hf6ef8570__0[0x19U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x1aU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1aU] 
               & __Vtemp_hf6ef8570__0[0x1aU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x1bU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1bU] 
               & __Vtemp_hf6ef8570__0[0x1bU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x1cU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1cU] 
               & __Vtemp_hf6ef8570__0[0x1cU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x1dU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1dU] 
               & __Vtemp_hf6ef8570__0[0x1dU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x1eU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1eU] 
               & __Vtemp_hf6ef8570__0[0x1eU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x1fU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1fU] 
               & __Vtemp_hf6ef8570__0[0x1fU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x20U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x20U] 
               & __Vtemp_hf6ef8570__0[0x20U]);
        VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h0ac0b756__1, VysyxSoCFull__ConstPool__CONST_h3892cc72_0, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0U] 
               & __Vtemp_h0ac0b756__1[0U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[1U] 
               & __Vtemp_h0ac0b756__1[1U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[2U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[2U] 
               & __Vtemp_h0ac0b756__1[2U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[3U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[3U] 
               & __Vtemp_h0ac0b756__1[3U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[4U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[4U] 
               & __Vtemp_h0ac0b756__1[4U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[5U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[5U] 
               & __Vtemp_h0ac0b756__1[5U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[6U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[6U] 
               & __Vtemp_h0ac0b756__1[6U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[7U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[7U] 
               & __Vtemp_h0ac0b756__1[7U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[8U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[8U] 
               & __Vtemp_h0ac0b756__1[8U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[9U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[9U] 
               & __Vtemp_h0ac0b756__1[9U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xaU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xaU] 
               & __Vtemp_h0ac0b756__1[0xaU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xbU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xbU] 
               & __Vtemp_h0ac0b756__1[0xbU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xcU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xcU] 
               & __Vtemp_h0ac0b756__1[0xcU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xdU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xdU] 
               & __Vtemp_h0ac0b756__1[0xdU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xeU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xeU] 
               & __Vtemp_h0ac0b756__1[0xeU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xfU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xfU] 
               & __Vtemp_h0ac0b756__1[0xfU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x10U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x10U] 
               & __Vtemp_h0ac0b756__1[0x10U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x11U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x11U] 
               & __Vtemp_h0ac0b756__1[0x11U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x12U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x12U] 
               & __Vtemp_h0ac0b756__1[0x12U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x13U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x13U] 
               & __Vtemp_h0ac0b756__1[0x13U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x14U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x14U] 
               & __Vtemp_h0ac0b756__1[0x14U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x15U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x15U] 
               & __Vtemp_h0ac0b756__1[0x15U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x16U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x16U] 
               & __Vtemp_h0ac0b756__1[0x16U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x17U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x17U] 
               & __Vtemp_h0ac0b756__1[0x17U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x18U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x18U] 
               & __Vtemp_h0ac0b756__1[0x18U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x19U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x19U] 
               & __Vtemp_h0ac0b756__1[0x19U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x1aU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1aU] 
               & __Vtemp_h0ac0b756__1[0x1aU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x1bU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1bU] 
               & __Vtemp_h0ac0b756__1[0x1bU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x1cU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1cU] 
               & __Vtemp_h0ac0b756__1[0x1cU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x1dU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1dU] 
               & __Vtemp_h0ac0b756__1[0x1dU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x1eU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1eU] 
               & __Vtemp_h0ac0b756__1[0x1eU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x1fU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1fU] 
               & __Vtemp_h0ac0b756__1[0x1fU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x20U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x20U] 
               & __Vtemp_h0ac0b756__1[0x20U]);
        __Vtemp_hb5fda8da__0[1U] = 0U;
        __Vtemp_hb5fda8da__0[2U] = 0U;
        __Vtemp_hb5fda8da__0[3U] = 0U;
        __Vtemp_hb5fda8da__0[4U] = 0U;
        __Vtemp_hb5fda8da__0[5U] = 0U;
        __Vtemp_hb5fda8da__0[6U] = 0U;
        __Vtemp_hb5fda8da__0[7U] = 0U;
        __Vtemp_hb5fda8da__0[8U] = 0U;
        __Vtemp_hb5fda8da__0[9U] = 0U;
        __Vtemp_hb5fda8da__0[0xaU] = 0U;
        __Vtemp_hb5fda8da__0[0xbU] = 0U;
        __Vtemp_hb5fda8da__0[0xcU] = 0U;
        __Vtemp_hb5fda8da__0[0xdU] = 0U;
        __Vtemp_hb5fda8da__0[0xeU] = 0U;
        __Vtemp_hb5fda8da__0[0xfU] = 0U;
        __Vtemp_hb5fda8da__0[0x10U] = 0U;
        __Vtemp_hb5fda8da__0[0x11U] = 0U;
        __Vtemp_hb5fda8da__0[0x12U] = 0U;
        __Vtemp_hb5fda8da__0[0x13U] = 0U;
        __Vtemp_hb5fda8da__0[0x14U] = 0U;
        __Vtemp_hb5fda8da__0[0x15U] = 0U;
        __Vtemp_hb5fda8da__0[0x16U] = 0U;
        __Vtemp_hb5fda8da__0[0x17U] = 0U;
        __Vtemp_hb5fda8da__0[0x18U] = 0U;
        __Vtemp_hb5fda8da__0[0x19U] = 0U;
        __Vtemp_hb5fda8da__0[0x1aU] = 0U;
        __Vtemp_hb5fda8da__0[0x1bU] = 0U;
        __Vtemp_hb5fda8da__0[0x1cU] = 0U;
        __Vtemp_hb5fda8da__0[0x1dU] = 0U;
        __Vtemp_hb5fda8da__0[0x1eU] = 0U;
        __Vtemp_hb5fda8da__0[0x1fU] = 0U;
        __Vtemp_hb5fda8da__0[0x20U] = 0U;
        VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_h2afb9a52__0, __Vtemp_hb5fda8da__0, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0U] 
               & __Vtemp_h2afb9a52__0[0U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[1U] 
               & __Vtemp_h2afb9a52__0[1U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[2U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[2U] 
               & __Vtemp_h2afb9a52__0[2U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[3U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[3U] 
               & __Vtemp_h2afb9a52__0[3U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[4U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[4U] 
               & __Vtemp_h2afb9a52__0[4U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[5U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[5U] 
               & __Vtemp_h2afb9a52__0[5U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[6U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[6U] 
               & __Vtemp_h2afb9a52__0[6U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[7U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[7U] 
               & __Vtemp_h2afb9a52__0[7U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[8U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[8U] 
               & __Vtemp_h2afb9a52__0[8U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[9U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[9U] 
               & __Vtemp_h2afb9a52__0[9U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xaU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xaU] 
               & __Vtemp_h2afb9a52__0[0xaU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xbU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xbU] 
               & __Vtemp_h2afb9a52__0[0xbU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xcU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xcU] 
               & __Vtemp_h2afb9a52__0[0xcU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xdU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xdU] 
               & __Vtemp_h2afb9a52__0[0xdU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xeU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xeU] 
               & __Vtemp_h2afb9a52__0[0xeU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xfU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xfU] 
               & __Vtemp_h2afb9a52__0[0xfU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x10U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x10U] 
               & __Vtemp_h2afb9a52__0[0x10U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x11U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x11U] 
               & __Vtemp_h2afb9a52__0[0x11U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x12U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x12U] 
               & __Vtemp_h2afb9a52__0[0x12U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x13U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x13U] 
               & __Vtemp_h2afb9a52__0[0x13U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x14U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x14U] 
               & __Vtemp_h2afb9a52__0[0x14U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x15U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x15U] 
               & __Vtemp_h2afb9a52__0[0x15U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x16U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x16U] 
               & __Vtemp_h2afb9a52__0[0x16U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x17U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x17U] 
               & __Vtemp_h2afb9a52__0[0x17U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x18U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x18U] 
               & __Vtemp_h2afb9a52__0[0x18U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x19U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x19U] 
               & __Vtemp_h2afb9a52__0[0x19U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x1aU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1aU] 
               & __Vtemp_h2afb9a52__0[0x1aU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x1bU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1bU] 
               & __Vtemp_h2afb9a52__0[0x1bU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x1cU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1cU] 
               & __Vtemp_h2afb9a52__0[0x1cU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x1dU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1dU] 
               & __Vtemp_h2afb9a52__0[0x1dU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x1eU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1eU] 
               & __Vtemp_h2afb9a52__0[0x1eU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x1fU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1fU] 
               & __Vtemp_h2afb9a52__0[0x1fU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x20U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x20U] 
               & __Vtemp_h2afb9a52__0[0x20U]);
        if (__PVT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) {
            vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43 
                = vlSelf->__PVT__monitor__DOT__d_first_1;
            vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                = (0xfffU & ((IData)(0x1fU) << (IData)(vlSelf->auto_in_d_bits_size)));
            __Vdly__monitor__DOT__d_first_counter = 
                (7U & ((0U != (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter))
                        ? ((IData)(vlSelf->__PVT__monitor__DOT__d_first_counter) 
                           - (IData)(1U)) : ((IData)(vlSelf->__PVT__r_wins)
                                              ? (~ 
                                                 ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                                  >> 2U))
                                              : 0U)));
            __Vdly__monitor__DOT__d_first_counter_1 
                = (7U & ((IData)(vlSelf->__PVT__monitor__DOT__d_first_1)
                          ? ((IData)(vlSelf->__PVT__r_wins)
                              ? (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                    >> 2U)) : 0U) : 
                         ((IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_1) 
                          - (IData)(1U))));
            __Vdly__monitor__DOT__d_first_counter_2 
                = (7U & ((IData)(vlSelf->__PVT__monitor__DOT__d_first_2)
                          ? ((IData)(vlSelf->__PVT__r_wins)
                              ? (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                    >> 2U)) : 0U) : 
                         ((IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_2) 
                          - (IData)(1U))));
            __Vdly__monitor__DOT__watchdog_1 = 0U;
        } else {
            vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43 = 0U;
            __Vdly__monitor__DOT__watchdog_1 = ((IData)(1U) 
                                                + vlSelf->__PVT__monitor__DOT__watchdog_1);
        }
        __Vtemp_hd2b6c582__2[0U] = 1U;
        __Vtemp_hd2b6c582__2[1U] = 0U;
        __Vtemp_hd2b6c582__2[2U] = 0U;
        __Vtemp_hd2b6c582__2[3U] = 0U;
        __Vtemp_hde3016fd__2[0U] = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source;
        __Vtemp_hde3016fd__2[1U] = 0U;
        __Vtemp_hde3016fd__2[2U] = 0U;
        __Vtemp_hde3016fd__2[3U] = 0U;
        VL_SHIFTL_WWW(128,128,128, __Vtemp_h46c47151__0, __Vtemp_hd2b6c582__2, __Vtemp_hde3016fd__2);
        __Vtemp_hd2b6c582__3[0U] = 1U;
        __Vtemp_hd2b6c582__3[1U] = 0U;
        __Vtemp_hd2b6c582__3[2U] = 0U;
        __Vtemp_hd2b6c582__3[3U] = 0U;
        __Vtemp_hb6b3ff4d__2[0U] = vlSelf->auto_in_d_bits_source;
        __Vtemp_hb6b3ff4d__2[1U] = 0U;
        __Vtemp_hb6b3ff4d__2[2U] = 0U;
        __Vtemp_hb6b3ff4d__2[3U] = 0U;
        VL_SHIFTL_WWW(128,128,128, __Vtemp_h61d6301d__0, __Vtemp_hd2b6c582__3, __Vtemp_hb6b3ff4d__2);
        __Vdly__monitor__DOT__inflight[0U] = ((vlSelf->__PVT__monitor__DOT__inflight[0U] 
                                               | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                                                   ? 
                                                  __Vtemp_h46c47151__0[0U]
                                                   : 0U)) 
                                              & (~ 
                                                 ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                                                   ? 
                                                  __Vtemp_h61d6301d__0[0U]
                                                   : 0U)));
        __Vdly__monitor__DOT__inflight[1U] = ((vlSelf->__PVT__monitor__DOT__inflight[1U] 
                                               | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                                                   ? 
                                                  __Vtemp_h46c47151__0[1U]
                                                   : 0U)) 
                                              & (~ 
                                                 ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                                                   ? 
                                                  __Vtemp_h61d6301d__0[1U]
                                                   : 0U)));
        __Vdly__monitor__DOT__inflight[2U] = ((vlSelf->__PVT__monitor__DOT__inflight[2U] 
                                               | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                                                   ? 
                                                  __Vtemp_h46c47151__0[2U]
                                                   : 0U)) 
                                              & (~ 
                                                 ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                                                   ? 
                                                  __Vtemp_h61d6301d__0[2U]
                                                   : 0U)));
        __Vdly__monitor__DOT__inflight[3U] = ((vlSelf->__PVT__monitor__DOT__inflight[3U] 
                                               | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                                                   ? 
                                                  __Vtemp_h46c47151__0[3U]
                                                   : 0U)) 
                                              & (~ 
                                                 ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                                                   ? 
                                                  __Vtemp_h61d6301d__0[3U]
                                                   : 0U)));
        __Vdly__monitor__DOT__inflight_opcodes[0U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0U])));
        __Vdly__monitor__DOT__inflight_opcodes[1U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[1U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[1U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[1U])));
        __Vdly__monitor__DOT__inflight_opcodes[2U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[2U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[2U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[2U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[2U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[2U])));
        __Vdly__monitor__DOT__inflight_opcodes[3U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[3U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[3U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[3U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[3U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[3U])));
        __Vdly__monitor__DOT__inflight_opcodes[4U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[4U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[4U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[4U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[4U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[4U])));
        __Vdly__monitor__DOT__inflight_opcodes[5U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[5U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[5U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[5U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[5U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[5U])));
        __Vdly__monitor__DOT__inflight_opcodes[6U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[6U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[6U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[6U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[6U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[6U])));
        __Vdly__monitor__DOT__inflight_opcodes[7U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[7U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[7U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[7U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[7U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[7U])));
        __Vdly__monitor__DOT__inflight_opcodes[8U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[8U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[8U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[8U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[8U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[8U])));
        __Vdly__monitor__DOT__inflight_opcodes[9U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[9U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[9U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[9U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[9U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[9U])));
        __Vdly__monitor__DOT__inflight_opcodes[0xaU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xaU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xaU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xaU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xaU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xaU])));
        __Vdly__monitor__DOT__inflight_opcodes[0xbU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xbU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xbU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xbU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xbU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xbU])));
        __Vdly__monitor__DOT__inflight_opcodes[0xcU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xcU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xcU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xcU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xcU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xcU])));
        __Vdly__monitor__DOT__inflight_opcodes[0xdU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xdU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xdU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xdU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xdU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xdU])));
        __Vdly__monitor__DOT__inflight_opcodes[0xeU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xeU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xeU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xeU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xeU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xeU])));
        __Vdly__monitor__DOT__inflight_opcodes[0xfU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xfU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xfU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xfU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xfU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xfU])));
        __Vdly__monitor__DOT__inflight_sizes[0U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0U])));
        __Vdly__monitor__DOT__inflight_sizes[1U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[1U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[1U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[1U])));
        __Vdly__monitor__DOT__inflight_sizes[2U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[2U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[2U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[2U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[2U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[2U])));
        __Vdly__monitor__DOT__inflight_sizes[3U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[3U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[3U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[3U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[3U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[3U])));
        __Vdly__monitor__DOT__inflight_sizes[4U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[4U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[4U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[4U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[4U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[4U])));
        __Vdly__monitor__DOT__inflight_sizes[5U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[5U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[5U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[5U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[5U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[5U])));
        __Vdly__monitor__DOT__inflight_sizes[6U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[6U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[6U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[6U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[6U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[6U])));
        __Vdly__monitor__DOT__inflight_sizes[7U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[7U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[7U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[7U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[7U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[7U])));
        __Vdly__monitor__DOT__inflight_sizes[8U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[8U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[8U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[8U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[8U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[8U])));
        __Vdly__monitor__DOT__inflight_sizes[9U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[9U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[9U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[9U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[9U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[9U])));
        __Vdly__monitor__DOT__inflight_sizes[0xaU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0xaU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xaU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xaU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xaU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xaU])));
        __Vdly__monitor__DOT__inflight_sizes[0xbU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0xbU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xbU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xbU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xbU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xbU])));
        __Vdly__monitor__DOT__inflight_sizes[0xcU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0xcU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xcU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xcU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xcU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xcU])));
        __Vdly__monitor__DOT__inflight_sizes[0xdU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0xdU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xdU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xdU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xdU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xdU])));
        __Vdly__monitor__DOT__inflight_sizes[0xeU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0xeU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xeU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xeU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xeU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xeU])));
        __Vdly__monitor__DOT__inflight_sizes[0xfU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0xfU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xfU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xfU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xfU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xfU])));
        __Vdly__monitor__DOT__watchdog = (((IData)(vlSelf->__PVT__monitor__DOT___a_first_T_1) 
                                           | (IData)(__PVT__monitor__DOT__unnamedblk2__DOT___d_first_T_2))
                                           ? 0U : ((IData)(1U) 
                                                   + vlSelf->__PVT__monitor__DOT__watchdog));
    }
    if (vlSelf->__PVT__r_first) {
        vlSelf->__PVT__r_denied_r = (3U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rresp));
    }
    if (vlSymsp->TOP.reset) {
        vlSelf->__PVT__r_first = 1U;
    } else if (((IData)(vlSelf->auto_out_rready) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rvalid))) {
        vlSelf->__PVT__r_first = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast;
    }
    vlSelf->__PVT__r_denied = ((IData)(vlSelf->__PVT__r_first)
                                ? (3U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rresp))
                                : (IData)(vlSelf->__PVT__r_denied_r));
    if (((IData)(__PVT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter)))))) {
        vlSelf->__PVT__monitor__DOT__opcode_1 = vlSelf->__PVT__r_wins;
        vlSelf->__PVT__monitor__DOT__size_1 = vlSelf->auto_in_d_bits_size;
        vlSelf->__PVT__monitor__DOT__source_1 = vlSelf->auto_in_d_bits_source;
        vlSelf->__PVT__monitor__DOT__denied = vlSelf->auto_in_d_bits_denied;
    }
    vlSelf->__PVT__a_first = (0U == (IData)(vlSelf->__PVT__r_counter));
    vlSelf->__PVT___out_wvalid_T_3 = (1U & ((~ (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full)) 
                                            | (IData)(vlSelf->__PVT__doneAW)));
    vlSelf->__PVT__monitor__DOT__a_first_counter = __Vdly__monitor__DOT__a_first_counter;
    vlSelf->__PVT__monitor__DOT__a_first_counter_1 
        = __Vdly__monitor__DOT__a_first_counter_1;
    vlSelf->__PVT__monitor__DOT__d_first_counter = __Vdly__monitor__DOT__d_first_counter;
    vlSelf->__PVT__monitor__DOT__inflight[0U] = __Vdly__monitor__DOT__inflight[0U];
    vlSelf->__PVT__monitor__DOT__inflight[1U] = __Vdly__monitor__DOT__inflight[1U];
    vlSelf->__PVT__monitor__DOT__inflight[2U] = __Vdly__monitor__DOT__inflight[2U];
    vlSelf->__PVT__monitor__DOT__inflight[3U] = __Vdly__monitor__DOT__inflight[3U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0U] 
        = __Vdly__monitor__DOT__inflight_opcodes[0U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[1U] 
        = __Vdly__monitor__DOT__inflight_opcodes[1U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[2U] 
        = __Vdly__monitor__DOT__inflight_opcodes[2U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[3U] 
        = __Vdly__monitor__DOT__inflight_opcodes[3U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[4U] 
        = __Vdly__monitor__DOT__inflight_opcodes[4U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[5U] 
        = __Vdly__monitor__DOT__inflight_opcodes[5U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[6U] 
        = __Vdly__monitor__DOT__inflight_opcodes[6U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[7U] 
        = __Vdly__monitor__DOT__inflight_opcodes[7U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[8U] 
        = __Vdly__monitor__DOT__inflight_opcodes[8U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[9U] 
        = __Vdly__monitor__DOT__inflight_opcodes[9U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xaU] 
        = __Vdly__monitor__DOT__inflight_opcodes[0xaU];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xbU] 
        = __Vdly__monitor__DOT__inflight_opcodes[0xbU];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xcU] 
        = __Vdly__monitor__DOT__inflight_opcodes[0xcU];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xdU] 
        = __Vdly__monitor__DOT__inflight_opcodes[0xdU];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xeU] 
        = __Vdly__monitor__DOT__inflight_opcodes[0xeU];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xfU] 
        = __Vdly__monitor__DOT__inflight_opcodes[0xfU];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0U] 
        = __Vdly__monitor__DOT__inflight_sizes[0U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[1U] 
        = __Vdly__monitor__DOT__inflight_sizes[1U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[2U] 
        = __Vdly__monitor__DOT__inflight_sizes[2U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[3U] 
        = __Vdly__monitor__DOT__inflight_sizes[3U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[4U] 
        = __Vdly__monitor__DOT__inflight_sizes[4U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[5U] 
        = __Vdly__monitor__DOT__inflight_sizes[5U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[6U] 
        = __Vdly__monitor__DOT__inflight_sizes[6U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[7U] 
        = __Vdly__monitor__DOT__inflight_sizes[7U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[8U] 
        = __Vdly__monitor__DOT__inflight_sizes[8U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[9U] 
        = __Vdly__monitor__DOT__inflight_sizes[9U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0xaU] 
        = __Vdly__monitor__DOT__inflight_sizes[0xaU];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0xbU] 
        = __Vdly__monitor__DOT__inflight_sizes[0xbU];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0xcU] 
        = __Vdly__monitor__DOT__inflight_sizes[0xcU];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0xdU] 
        = __Vdly__monitor__DOT__inflight_sizes[0xdU];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0xeU] 
        = __Vdly__monitor__DOT__inflight_sizes[0xeU];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0xfU] 
        = __Vdly__monitor__DOT__inflight_sizes[0xfU];
    vlSelf->__PVT__monitor__DOT__watchdog = __Vdly__monitor__DOT__watchdog;
    vlSelf->__PVT__monitor__DOT__watchdog_1 = __Vdly__monitor__DOT__watchdog_1;
    vlSelf->__PVT__monitor__DOT__d_first_counter_2 
        = __Vdly__monitor__DOT__d_first_counter_2;
    vlSelf->__PVT__monitor__DOT__d_first_counter_1 
        = __Vdly__monitor__DOT__d_first_counter_1;
    vlSelf->__PVT__r_wins = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rvalid) 
                              & (7U != (IData)(vlSelf->__PVT__b_delay))) 
                             | (IData)(vlSelf->__PVT__r_holds_d));
    vlSelf->__PVT__monitor__DOT__a_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_2 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_2));
    vlSelf->__PVT__monitor__DOT__d_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_1));
    if (vlSelf->__PVT__r_wins) {
        vlSelf->auto_in_d_valid = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rvalid;
        vlSelf->auto_in_d_bits_denied = vlSelf->__PVT__r_denied;
        vlSelf->auto_in_d_bits_corrupt = ((0U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rresp)) 
                                          | (IData)(vlSelf->__PVT__r_denied));
    } else {
        vlSelf->auto_in_d_valid = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bvalid;
        vlSelf->auto_in_d_bits_denied = (0U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bresp));
        vlSelf->auto_in_d_bits_corrupt = 0U;
    }
}

VL_INLINE_OPT void VysyxSoCFull_TLToAXI4___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4__1(VysyxSoCFull_TLToAXI4* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLToAXI4___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4__1\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_hee9d390a__0;
    VlWide<4>/*127:0*/ __Vtemp_hcb07eeed__0;
    VlWide<3>/*95:0*/ __Vtemp_hc6a9858f__0;
    VlWide<4>/*127:0*/ __Vtemp_hab792b22__0;
    // Body
    __Vtemp_hee9d390a__0[0U] = (IData)((((QData)((IData)(
                                                         (0x7fU 
                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_1__DOT__ram) 
                                                             >> 1U)))) 
                                         << 0x38U) 
                                        | (((QData)((IData)(
                                                            (0x7fU 
                                                             & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap__DOT__ram) 
                                                                >> 1U)))) 
                                            << 0x31U) 
                                           | (((QData)((IData)(
                                                               (0x7fU 
                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data) 
                                                                   >> 1U)))) 
                                               << 0x2aU) 
                                              | (((QData)((IData)(
                                                                  (0x7fU 
                                                                   & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data) 
                                                                      >> 1U)))) 
                                                  << 0x23U) 
                                                 | (((QData)((IData)(
                                                                     (0x7fU 
                                                                      & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data) 
                                                                         >> 1U)))) 
                                                     << 0x1cU) 
                                                    | (QData)((IData)(
                                                                      ((0xfe00000U 
                                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data) 
                                                                           << 0x14U)) 
                                                                       | ((0x1fc000U 
                                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data) 
                                                                              << 0xdU)) 
                                                                          | ((0x3f80U 
                                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data) 
                                                                                << 6U)) 
                                                                             | (0x7fU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data) 
                                                                                >> 1U)))))))))))));
    __Vtemp_hee9d390a__0[1U] = ((0x80000000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_2__DOT__ram) 
                                                << 0x1eU)) 
                                | (IData)(((((QData)((IData)(
                                                             (0x7fU 
                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_1__DOT__ram) 
                                                                 >> 1U)))) 
                                             << 0x38U) 
                                            | (((QData)((IData)(
                                                                (0x7fU 
                                                                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap__DOT__ram) 
                                                                    >> 1U)))) 
                                                << 0x31U) 
                                               | (((QData)((IData)(
                                                                   (0x7fU 
                                                                    & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data) 
                                                                       >> 1U)))) 
                                                   << 0x2aU) 
                                                  | (((QData)((IData)(
                                                                      (0x7fU 
                                                                       & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data) 
                                                                          >> 1U)))) 
                                                      << 0x23U) 
                                                     | (((QData)((IData)(
                                                                         (0x7fU 
                                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data) 
                                                                             >> 1U)))) 
                                                         << 0x1cU) 
                                                        | (QData)((IData)(
                                                                          ((0xfe00000U 
                                                                            & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data) 
                                                                               << 0x14U)) 
                                                                           | ((0x1fc000U 
                                                                               & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data) 
                                                                                << 0xdU)) 
                                                                              | ((0x3f80U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data) 
                                                                                << 6U)) 
                                                                                | (0x7fU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data) 
                                                                                >> 1U)))))))))))) 
                                           >> 0x20U)));
    __Vtemp_hcb07eeed__0[0U] = __Vtemp_hee9d390a__0[0U];
    __Vtemp_hcb07eeed__0[1U] = __Vtemp_hee9d390a__0[1U];
    __Vtemp_hcb07eeed__0[2U] = ((0xf8000000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_6__DOT__ram) 
                                                << 0x1aU)) 
                                | ((0x7f00000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_5__DOT__ram) 
                                                  << 0x13U)) 
                                   | ((0xfe000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_4__DOT__ram) 
                                                   << 0xcU)) 
                                      | ((0x1fc0U & 
                                          ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_3__DOT__ram) 
                                           << 5U)) 
                                         | (0x3fU & 
                                            ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_2__DOT__ram) 
                                             >> 2U))))));
    __Vtemp_hcb07eeed__0[3U] = ((0xfe00U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_8__DOT__ram) 
                                            << 8U)) 
                                | ((0x1fcU & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_7__DOT__ram) 
                                              << 1U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_6__DOT__ram) 
                                            >> 6U))));
    __Vtemp_hc6a9858f__0[0U] = (IData)((((QData)((IData)(
                                                         (0x7fU 
                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_10__DOT__ram) 
                                                             >> 1U)))) 
                                         << 0x38U) 
                                        | (((QData)((IData)(
                                                            (0x7fU 
                                                             & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_9__DOT__ram) 
                                                                >> 1U)))) 
                                            << 0x31U) 
                                           | (((QData)((IData)(
                                                               (0x7fU 
                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data) 
                                                                   >> 1U)))) 
                                               << 0x2aU) 
                                              | (((QData)((IData)(
                                                                  (0x7fU 
                                                                   & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data) 
                                                                      >> 1U)))) 
                                                  << 0x23U) 
                                                 | (((QData)((IData)(
                                                                     (0x7fU 
                                                                      & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data) 
                                                                         >> 1U)))) 
                                                     << 0x1cU) 
                                                    | (QData)((IData)(
                                                                      ((0xfe00000U 
                                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data) 
                                                                           << 0x14U)) 
                                                                       | ((0x1fc000U 
                                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data) 
                                                                              << 0xdU)) 
                                                                          | ((0x3f80U 
                                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data) 
                                                                                << 6U)) 
                                                                             | (0x7fU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data) 
                                                                                >> 1U)))))))))))));
    __Vtemp_hc6a9858f__0[1U] = ((0x80000000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_11__DOT__ram) 
                                                << 0x1eU)) 
                                | (IData)(((((QData)((IData)(
                                                             (0x7fU 
                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_10__DOT__ram) 
                                                                 >> 1U)))) 
                                             << 0x38U) 
                                            | (((QData)((IData)(
                                                                (0x7fU 
                                                                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_9__DOT__ram) 
                                                                    >> 1U)))) 
                                                << 0x31U) 
                                               | (((QData)((IData)(
                                                                   (0x7fU 
                                                                    & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data) 
                                                                       >> 1U)))) 
                                                   << 0x2aU) 
                                                  | (((QData)((IData)(
                                                                      (0x7fU 
                                                                       & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data) 
                                                                          >> 1U)))) 
                                                      << 0x23U) 
                                                     | (((QData)((IData)(
                                                                         (0x7fU 
                                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data) 
                                                                             >> 1U)))) 
                                                         << 0x1cU) 
                                                        | (QData)((IData)(
                                                                          ((0xfe00000U 
                                                                            & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data) 
                                                                               << 0x14U)) 
                                                                           | ((0x1fc000U 
                                                                               & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data) 
                                                                                << 0xdU)) 
                                                                              | ((0x3f80U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data) 
                                                                                << 6U)) 
                                                                                | (0x7fU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data) 
                                                                                >> 1U)))))))))))) 
                                           >> 0x20U)));
    __Vtemp_hab792b22__0[0U] = __Vtemp_hc6a9858f__0[0U];
    __Vtemp_hab792b22__0[1U] = __Vtemp_hc6a9858f__0[1U];
    __Vtemp_hab792b22__0[2U] = ((0xf8000000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_15__DOT__ram) 
                                                << 0x1aU)) 
                                | ((0x7f00000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_14__DOT__ram) 
                                                  << 0x13U)) 
                                   | ((0xfe000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_13__DOT__ram) 
                                                   << 0xcU)) 
                                      | ((0x1fc0U & 
                                          ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_12__DOT__ram) 
                                           << 5U)) 
                                         | (0x3fU & 
                                            ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_11__DOT__ram) 
                                             >> 2U))))));
    __Vtemp_hab792b22__0[3U] = ((0xfe00U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_17__DOT__ram) 
                                            << 8U)) 
                                | ((0x1fcU & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_16__DOT__ram) 
                                              << 1U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_15__DOT__ram) 
                                            >> 6U))));
    if (vlSelf->__PVT__r_wins) {
        vlSelf->__VdfgTmp_h3c545424__0 = ((0x10U & 
                                           ((((0x8000U 
                                               & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_8__DOT__ram) 
                                                  << 0xfU)) 
                                              | ((0x4000U 
                                                  & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_7__DOT__ram) 
                                                     << 0xeU)) 
                                                 | ((0x2000U 
                                                     & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_6__DOT__ram) 
                                                        << 0xdU)) 
                                                    | ((0x1000U 
                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_5__DOT__ram) 
                                                           << 0xcU)) 
                                                       | ((0x800U 
                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_4__DOT__ram) 
                                                              << 0xbU)) 
                                                          | ((0x400U 
                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_3__DOT__ram) 
                                                                 << 0xaU)) 
                                                             | ((0x200U 
                                                                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_2__DOT__ram) 
                                                                    << 9U)) 
                                                                | ((0x100U 
                                                                    & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_1__DOT__ram) 
                                                                       << 8U)) 
                                                                   | ((0x80U 
                                                                       & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap__DOT__ram) 
                                                                          << 7U)) 
                                                                      | ((0x40U 
                                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data) 
                                                                             << 6U)) 
                                                                         | ((0x20U 
                                                                             & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data) 
                                                                                << 5U)) 
                                                                            | ((0x10U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data) 
                                                                                << 4U)) 
                                                                               | ((8U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data))))))))))))))))) 
                                             >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                                            << 4U)) 
                                          | (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid));
        vlSelf->auto_in_d_bits_size = (7U & (IData)(
                                                    ((((QData)((IData)(
                                                                       (0xfU 
                                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_8__DOT__ram) 
                                                                           >> 8U)))) 
                                                       << 0x3cU) 
                                                      | (((QData)((IData)(
                                                                          (0xfU 
                                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_7__DOT__ram) 
                                                                              >> 8U)))) 
                                                          << 0x38U) 
                                                         | (((QData)((IData)(
                                                                             (0xfU 
                                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_6__DOT__ram) 
                                                                                >> 8U)))) 
                                                             << 0x34U) 
                                                            | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_5__DOT__ram) 
                                                                                >> 8U)))) 
                                                                << 0x30U) 
                                                               | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_4__DOT__ram) 
                                                                                >> 8U)))) 
                                                                   << 0x2cU) 
                                                                  | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_3__DOT__ram) 
                                                                                >> 8U)))) 
                                                                      << 0x28U) 
                                                                     | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_2__DOT__ram) 
                                                                                >> 8U)))) 
                                                                         << 0x24U) 
                                                                        | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_1__DOT__ram) 
                                                                                >> 8U)))) 
                                                                            << 0x20U) 
                                                                           | (QData)((IData)(
                                                                                ((0xf0000000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap__DOT__ram) 
                                                                                << 0x14U)) 
                                                                                | ((0xf000000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data) 
                                                                                << 0x10U)) 
                                                                                | ((0xf00000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data) 
                                                                                << 0xcU)) 
                                                                                | ((0xf0000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data) 
                                                                                << 8U)) 
                                                                                | ((0xf000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data) 
                                                                                << 4U)) 
                                                                                | ((0xf00U 
                                                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data)) 
                                                                                | ((0xf0U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data) 
                                                                                >> 4U)) 
                                                                                | (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data) 
                                                                                >> 8U))))))))))))))))))) 
                                                     >> 
                                                     (0x3fU 
                                                      & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid) 
                                                         << 2U)))));
        vlSelf->auto_in_d_bits_source = (0x7fU & ((0x6fU 
                                                   >= 
                                                   (0x7fU 
                                                    & ((IData)(7U) 
                                                       * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid))))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid))))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_hcb07eeed__0[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(7U) 
                                                           * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)))))) 
                                                   | (__Vtemp_hcb07eeed__0[
                                                      (3U 
                                                       & (((IData)(7U) 
                                                           * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)))))
                                                   : 0U));
    } else {
        vlSelf->__VdfgTmp_h3c545424__0 = ((0x10U & 
                                           ((((0x8000U 
                                               & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_17__DOT__ram) 
                                                  << 0xfU)) 
                                              | ((0x4000U 
                                                  & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_16__DOT__ram) 
                                                     << 0xeU)) 
                                                 | ((0x2000U 
                                                     & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_15__DOT__ram) 
                                                        << 0xdU)) 
                                                    | ((0x1000U 
                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_14__DOT__ram) 
                                                           << 0xcU)) 
                                                       | ((0x800U 
                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_13__DOT__ram) 
                                                              << 0xbU)) 
                                                          | ((0x400U 
                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_12__DOT__ram) 
                                                                 << 0xaU)) 
                                                             | ((0x200U 
                                                                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_11__DOT__ram) 
                                                                    << 9U)) 
                                                                | ((0x100U 
                                                                    & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_10__DOT__ram) 
                                                                       << 8U)) 
                                                                   | ((0x80U 
                                                                       & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_9__DOT__ram) 
                                                                          << 7U)) 
                                                                      | ((0x40U 
                                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data) 
                                                                             << 6U)) 
                                                                         | ((0x20U 
                                                                             & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data) 
                                                                                << 5U)) 
                                                                            | ((0x10U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data) 
                                                                                << 4U)) 
                                                                               | ((8U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data))))))))))))))))) 
                                             >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                                            << 4U)) 
                                          | (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid));
        vlSelf->auto_in_d_bits_size = (7U & (IData)(
                                                    ((((QData)((IData)(
                                                                       (0xfU 
                                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_17__DOT__ram) 
                                                                           >> 8U)))) 
                                                       << 0x3cU) 
                                                      | (((QData)((IData)(
                                                                          (0xfU 
                                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_16__DOT__ram) 
                                                                              >> 8U)))) 
                                                          << 0x38U) 
                                                         | (((QData)((IData)(
                                                                             (0xfU 
                                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_15__DOT__ram) 
                                                                                >> 8U)))) 
                                                             << 0x34U) 
                                                            | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_14__DOT__ram) 
                                                                                >> 8U)))) 
                                                                << 0x30U) 
                                                               | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_13__DOT__ram) 
                                                                                >> 8U)))) 
                                                                   << 0x2cU) 
                                                                  | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_12__DOT__ram) 
                                                                                >> 8U)))) 
                                                                      << 0x28U) 
                                                                     | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_11__DOT__ram) 
                                                                                >> 8U)))) 
                                                                         << 0x24U) 
                                                                        | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_10__DOT__ram) 
                                                                                >> 8U)))) 
                                                                            << 0x20U) 
                                                                           | (QData)((IData)(
                                                                                ((0xf0000000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_9__DOT__ram) 
                                                                                << 0x14U)) 
                                                                                | ((0xf000000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data) 
                                                                                << 0x10U)) 
                                                                                | ((0xf00000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data) 
                                                                                << 0xcU)) 
                                                                                | ((0xf0000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data) 
                                                                                << 8U)) 
                                                                                | ((0xf000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data) 
                                                                                << 4U)) 
                                                                                | ((0xf00U 
                                                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data)) 
                                                                                | ((0xf0U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data) 
                                                                                >> 4U)) 
                                                                                | (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data) 
                                                                                >> 8U))))))))))))))))))) 
                                                     >> 
                                                     (0x3fU 
                                                      & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid) 
                                                         << 2U)))));
        vlSelf->auto_in_d_bits_source = (0x7fU & ((0x6fU 
                                                   >= 
                                                   (0x7fU 
                                                    & ((IData)(7U) 
                                                       * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid))))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid))))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_hab792b22__0[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(7U) 
                                                           * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)))))) 
                                                   | (__Vtemp_hab792b22__0[
                                                      (3U 
                                                       & (((IData)(7U) 
                                                           * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)))))
                                                   : 0U));
    }
}

VL_INLINE_OPT void VysyxSoCFull_TLToAXI4___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4__2(VysyxSoCFull_TLToAXI4* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLToAXI4___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4__2\n"); );
    // Body
    vlSelf->__VdfgTmp_hc0989b25__0 = (((~ (IData)(vlSelf->__PVT__r_wins)) 
                                       | (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast)) 
                                      & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_d_ready) 
                                         & (IData)(vlSelf->auto_in_d_valid)));
    vlSelf->auto_out_bready = ((~ (IData)(vlSelf->__PVT__r_wins)) 
                               & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_d_ready));
    vlSelf->auto_out_rready = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_d_ready) 
                               & (IData)(vlSelf->__PVT__r_wins));
}

extern const VlWide<20>/*639:0*/ VysyxSoCFull__ConstPool__CONST_h72c4c799_0;

VL_INLINE_OPT void VysyxSoCFull_TLToAXI4___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4__0(VysyxSoCFull_TLToAXI4* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLToAXI4___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __PVT___GEN_0;
    VL_ZERO_W(128, __PVT___GEN_0);
    CData/*0:0*/ __VdfgTmp_hbcc272f1__0;
    __VdfgTmp_hbcc272f1__0 = 0;
    VlWide<3>/*95:0*/ __Vtemp_hba612b4e__0;
    VlWide<3>/*95:0*/ __Vtemp_h15f08d96__0;
    // Body
    vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id 
        = ((0x27fU >= (0x3ffU & ((IData)(5U) * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source))))
            ? (0x1fU & (((0U == (0x1fU & ((IData)(5U) 
                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source))))
                          ? 0U : (VysyxSoCFull__ConstPool__CONST_h72c4c799_0[
                                  (((IData)(4U) + (0x3ffU 
                                                   & ((IData)(5U) 
                                                      * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source)))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source)))))) 
                        | (VysyxSoCFull__ConstPool__CONST_h72c4c799_0[
                           (0x1fU & (((IData)(5U) * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source)) 
                                     >> 5U))] >> (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source))))))
            : 0U);
    if (vlSelf->__PVT__queue_arw_deq_q__DOT__full) {
        vlSelf->auto_out_awecho_tl_state_size = (0xfU 
                                                 & (IData)(
                                                           (vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                                            >> 8U)));
        vlSelf->auto_out_awecho_tl_state_source = (0x7fU 
                                                   & (IData)(
                                                             (vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                                              >> 1U)));
        vlSelf->__PVT___queue_arw_deq_q_io_deq_bits_wen 
            = (1U & (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__ram));
        vlSelf->auto_out_awid = (0x1fU & (IData)((vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                                  >> 0x39U)));
    } else {
        vlSelf->auto_out_awecho_tl_state_size = (0xfU 
                                                 & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size));
        vlSelf->auto_out_awecho_tl_state_source = (0x7fU 
                                                   & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source));
        vlSelf->__PVT___queue_arw_deq_q_io_deq_bits_wen 
            = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                        >> 2U)));
        vlSelf->auto_out_awid = (0x1fU & (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id));
    }
    vlSelf->__PVT__r_beats1 = ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))
                                ? 0U : (7U & (~ (0x3ffU 
                                                 & (((IData)(0x1fU) 
                                                     << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size)) 
                                                    >> 2U)))));
    vlSelf->__PVT__idStall_4 = (((0U != (IData)(vlSelf->__PVT__count_4)) 
                                 & ((IData)(vlSelf->__PVT__write_4) 
                                    != (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                 >> 2U))))) 
                                | (0x10U == (IData)(vlSelf->__PVT__count_4)));
    vlSelf->__PVT__idStall_2 = (((0U != (IData)(vlSelf->__PVT__count_2)) 
                                 & ((IData)(vlSelf->__PVT__write_2) 
                                    != (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                 >> 2U))))) 
                                | (0x10U == (IData)(vlSelf->__PVT__count_2)));
    vlSelf->__PVT__idStall_0 = (((0U != (IData)(vlSelf->__PVT__count)) 
                                 & ((IData)(vlSelf->__PVT__write) 
                                    != (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                 >> 2U))))) 
                                | (0x10U == (IData)(vlSelf->__PVT__count)));
    vlSelf->__PVT__a_last = ((1U == (IData)(vlSelf->__PVT__r_counter)) 
                             | (0U == (IData)(vlSelf->__PVT__r_beats1)));
    __Vtemp_hba612b4e__0[0U] = (IData)((((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                         << 0x3fU) 
                                        | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                            << 0x3eU) 
                                           | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                               << 0x3dU) 
                                              | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                  << 0x3cU) 
                                                 | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                     << 0x3bU) 
                                                    | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                        << 0x3aU) 
                                                       | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                           << 0x39U) 
                                                          | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                              << 0x38U) 
                                                             | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                 << 0x37U) 
                                                                | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                    << 0x36U) 
                                                                   | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                       << 0x35U) 
                                                                      | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                          << 0x34U) 
                                                                         | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                             << 0x33U) 
                                                                            | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x32U) 
                                                                               | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffffU 
                                                                                & (- (IData)(
                                                                                (((0U 
                                                                                != (IData)(vlSelf->__PVT__count_1)) 
                                                                                & ((IData)(vlSelf->__PVT__write_1) 
                                                                                != 
                                                                                (1U 
                                                                                & (~ 
                                                                                ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                                                >> 2U))))) 
                                                                                | (0x10U 
                                                                                == (IData)(vlSelf->__PVT__count_1)))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1fU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1eU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1dU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1cU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1aU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->__PVT__count_22) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->__PVT__count_21) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->__PVT__count_20) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->__PVT__count_19) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->__PVT__count_18) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->__PVT__count_17) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->__PVT__count_16) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->__PVT__count_15) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->__PVT__count_14) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->__PVT__count_13) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->__PVT__count_12) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->__PVT__count_11) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->__PVT__count_10) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->__PVT__count_9) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->__PVT__count_8) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->__PVT__count_7))))))))))))))))))))))))))))))))))))))))))))))))))));
    __Vtemp_hba612b4e__0[1U] = (IData)(((((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                          << 0x3fU) 
                                         | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                             << 0x3eU) 
                                            | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                << 0x3dU) 
                                               | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                   << 0x3cU) 
                                                  | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                      << 0x3bU) 
                                                     | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                         << 0x3aU) 
                                                        | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                            << 0x39U) 
                                                           | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                               << 0x38U) 
                                                              | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                  << 0x37U) 
                                                                 | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                     << 0x36U) 
                                                                    | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                        << 0x35U) 
                                                                       | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                           << 0x34U) 
                                                                          | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                              << 0x33U) 
                                                                             | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x32U) 
                                                                                | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffffU 
                                                                                & (- (IData)(
                                                                                (((0U 
                                                                                != (IData)(vlSelf->__PVT__count_1)) 
                                                                                & ((IData)(vlSelf->__PVT__write_1) 
                                                                                != 
                                                                                (1U 
                                                                                & (~ 
                                                                                ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                                                >> 2U))))) 
                                                                                | (0x10U 
                                                                                == (IData)(vlSelf->__PVT__count_1)))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1fU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1eU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1dU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1cU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1aU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->__PVT__count_22) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->__PVT__count_21) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->__PVT__count_20) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->__PVT__count_19) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->__PVT__count_18) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->__PVT__count_17) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->__PVT__count_16) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->__PVT__count_15) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->__PVT__count_14) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->__PVT__count_13) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->__PVT__count_12) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->__PVT__count_11) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->__PVT__count_10) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->__PVT__count_9) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->__PVT__count_8) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->__PVT__count_7))))))))))))))))))))))))))))))))))))))))))))))))))) 
                                        >> 0x20U));
    __Vtemp_h15f08d96__0[2U] = (((IData)(vlSelf->__PVT__idStall_4) 
                                 << 0x1aU) | (((IData)(vlSelf->__PVT__idStall_4) 
                                               << 0x19U) 
                                              | (((IData)(vlSelf->__PVT__idStall_4) 
                                                  << 0x18U) 
                                                 | (((IData)(vlSelf->__PVT__idStall_4) 
                                                     << 0x17U) 
                                                    | (((IData)(vlSelf->__PVT__idStall_4) 
                                                        << 0x16U) 
                                                       | (((IData)(vlSelf->__PVT__idStall_4) 
                                                           << 0x15U) 
                                                          | (((IData)(vlSelf->__PVT__idStall_4) 
                                                              << 0x14U) 
                                                             | (((IData)(vlSelf->__PVT__idStall_4) 
                                                                 << 0x13U) 
                                                                | (((IData)(vlSelf->__PVT__idStall_4) 
                                                                    << 0x12U) 
                                                                   | (((IData)(vlSelf->__PVT__idStall_4) 
                                                                       << 0x11U) 
                                                                      | (((IData)(vlSelf->__PVT__idStall_4) 
                                                                          << 0x10U) 
                                                                         | (0xffffU 
                                                                            & (- (IData)(
                                                                                (((0U 
                                                                                != (IData)(vlSelf->__PVT__count_3)) 
                                                                                & ((IData)(vlSelf->__PVT__write_3) 
                                                                                != 
                                                                                (1U 
                                                                                & (~ 
                                                                                ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                                                >> 2U))))) 
                                                                                | (0x10U 
                                                                                == (IData)(vlSelf->__PVT__count_3)))))))))))))))));
    __PVT___GEN_0[0U] = __Vtemp_hba612b4e__0[0U];
    __PVT___GEN_0[1U] = __Vtemp_hba612b4e__0[1U];
    __PVT___GEN_0[2U] = (((IData)(vlSelf->__PVT__idStall_4) 
                          << 0x1fU) | (((IData)(vlSelf->__PVT__idStall_4) 
                                        << 0x1eU) | 
                                       (((IData)(vlSelf->__PVT__idStall_4) 
                                         << 0x1dU) 
                                        | (((IData)(vlSelf->__PVT__idStall_4) 
                                            << 0x1cU) 
                                           | (((IData)(vlSelf->__PVT__idStall_4) 
                                               << 0x1bU) 
                                              | __Vtemp_h15f08d96__0[2U])))));
    __PVT___GEN_0[3U] = (((- (IData)((((0U != (IData)(vlSelf->__PVT__count_6)) 
                                       & ((IData)(vlSelf->__PVT__write_6) 
                                          != (1U & 
                                              (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                  >> 2U))))) 
                                      | (0x10U == (IData)(vlSelf->__PVT__count_6))))) 
                          << 0x10U) | (0xffffU & (- (IData)(
                                                            (((0U 
                                                               != (IData)(vlSelf->__PVT__count_5)) 
                                                              & ((IData)(vlSelf->__PVT__write_5) 
                                                                 != 
                                                                 (1U 
                                                                  & (~ 
                                                                     ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                                      >> 2U))))) 
                                                             | (0x10U 
                                                                == (IData)(vlSelf->__PVT__count_5)))))));
    vlSelf->__Vcellinp__queue_arw_deq_q__io_deq_ready 
        = ((IData)(vlSelf->__PVT___queue_arw_deq_q_io_deq_bits_wen)
            ? ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_awready) 
               & (((0x8000U & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_17__DOT__full)) 
                               << 0xfU)) | ((0x4000U 
                                             & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_16__DOT__full)) 
                                                << 0xeU)) 
                                            | ((0x2000U 
                                                & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_15__DOT__full)) 
                                                   << 0xdU)) 
                                               | ((0x1000U 
                                                   & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_14__DOT__full)) 
                                                      << 0xcU)) 
                                                  | ((0x800U 
                                                      & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_13__DOT__full)) 
                                                         << 0xbU)) 
                                                     | ((0x400U 
                                                         & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_12__DOT__full)) 
                                                            << 0xaU)) 
                                                        | ((0x200U 
                                                            & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_11__DOT__full)) 
                                                               << 9U)) 
                                                           | ((0x100U 
                                                               & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_10__DOT__full)) 
                                                                  << 8U)) 
                                                              | ((0x80U 
                                                                  & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_9__DOT__full)) 
                                                                     << 7U)) 
                                                                 | ((0x40U 
                                                                     & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_13__DOT__full)) 
                                                                        << 6U)) 
                                                                    | ((0x20U 
                                                                        & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_12__DOT__full)) 
                                                                           << 5U)) 
                                                                       | ((0x10U 
                                                                           & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_11__DOT__full)) 
                                                                              << 4U)) 
                                                                          | ((8U 
                                                                              & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_10__DOT__full)) 
                                                                                << 3U)) 
                                                                             | ((4U 
                                                                                & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_9__DOT__full)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_8__DOT__full)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_7__DOT__full)))))))))))))))))) 
                  >> (0xfU & (IData)(vlSelf->auto_out_awid))))
            : ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_arready) 
               & (((0x8000U & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_8__DOT__full)) 
                               << 0xfU)) | ((0x4000U 
                                             & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_7__DOT__full)) 
                                                << 0xeU)) 
                                            | ((0x2000U 
                                                & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_6__DOT__full)) 
                                                   << 0xdU)) 
                                               | ((0x1000U 
                                                   & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_5__DOT__full)) 
                                                      << 0xcU)) 
                                                  | ((0x800U 
                                                      & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_4__DOT__full)) 
                                                         << 0xbU)) 
                                                     | ((0x400U 
                                                         & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_3__DOT__full)) 
                                                            << 0xaU)) 
                                                        | ((0x200U 
                                                            & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_2__DOT__full)) 
                                                               << 9U)) 
                                                           | ((0x100U 
                                                               & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_1__DOT__full)) 
                                                                  << 8U)) 
                                                              | ((0x80U 
                                                                  & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap__DOT__full)) 
                                                                     << 7U)) 
                                                                 | ((0x40U 
                                                                     & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_6__DOT__full)) 
                                                                        << 6U)) 
                                                                    | ((0x20U 
                                                                        & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_5__DOT__full)) 
                                                                           << 5U)) 
                                                                       | ((0x10U 
                                                                           & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_4__DOT__full)) 
                                                                              << 4U)) 
                                                                          | ((8U 
                                                                              & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_3__DOT__full)) 
                                                                                << 3U)) 
                                                                             | ((4U 
                                                                                & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_2__DOT__full)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_1__DOT__full)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap__DOT__full)))))))))))))))))) 
                  >> (0xfU & (IData)(vlSelf->auto_out_awid)))));
    vlSelf->__PVT__stall = ((__PVT___GEN_0[((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                            >> 5U)] 
                             >> (0x1fU & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source))) 
                            & (0U == (IData)(vlSelf->__PVT__r_counter)));
    __VdfgTmp_hbcc272f1__0 = ((~ (IData)(vlSelf->__PVT__stall)) 
                              & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid));
    vlSelf->auto_in_a_ready = (1U & ((~ (IData)(vlSelf->__PVT__stall)) 
                                     & ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))
                                         ? (~ (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full))
                                         : ((~ (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full)) 
                                            & (IData)(vlSelf->__PVT___out_wvalid_T_3)))));
    vlSelf->__Vcellinp__nodeOut_wdeq_q__io_enq_valid 
        = ((IData)(__VdfgTmp_hbcc272f1__0) & ((~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                  >> 2U)) 
                                              & (IData)(vlSelf->__PVT___out_wvalid_T_3)));
    vlSelf->__PVT__out_arw_valid = ((IData)(__VdfgTmp_hbcc272f1__0) 
                                    & (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                        >> 2U) | ((~ (IData)(vlSelf->__PVT__doneAW)) 
                                                  & (~ (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full)))));
    vlSelf->__PVT__monitor__DOT___a_first_T_1 = ((IData)(vlSelf->auto_in_a_ready) 
                                                 & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid));
    vlSelf->auto_out_wvalid = ((IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full) 
                               | (IData)(vlSelf->__Vcellinp__nodeOut_wdeq_q__io_enq_valid));
    vlSelf->__PVT__nodeOut_wdeq_q__DOT__do_enq = ((~ 
                                                   ((~ (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full)) 
                                                    & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_wready))) 
                                                  & ((~ (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full)) 
                                                     & (IData)(vlSelf->__Vcellinp__nodeOut_wdeq_q__io_enq_valid)));
    vlSelf->__PVT___inc_T_22 = ((~ (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full)) 
                                & (IData)(vlSelf->__PVT__out_arw_valid));
    vlSelf->__PVT__queue_arw_deq_q__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full) 
           | (IData)(vlSelf->__PVT__out_arw_valid));
    vlSelf->__PVT__monitor__DOT___GEN_1 = ((IData)(vlSelf->__PVT__monitor__DOT___a_first_T_1) 
                                           & (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1)));
    vlSelf->__PVT__inc = (((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                          & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_1 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 1U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_2 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 2U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_3 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 3U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_4 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 4U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_5 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 5U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_6 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 6U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__queue_arw_deq_q__DOT__do_enq = (
                                                   (~ 
                                                    ((~ (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full)) 
                                                     & (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_deq_ready))) 
                                                   & (IData)(vlSelf->__PVT___inc_T_22));
}

VL_INLINE_OPT void VysyxSoCFull_TLToAXI4___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4__0(VysyxSoCFull_TLToAXI4* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLToAXI4___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4__0\n"); );
    // Init
    SData/*11:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T;
    __PVT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T = 0;
    CData/*4:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_6;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_6 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_7;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_7 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_8;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_8 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_9;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_9 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_10;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_10 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_11;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_11 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_12;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_12 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_13;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_13 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_14;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_14 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_15;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_15 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_16;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_16 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_17;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_17 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_18;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_18 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_19;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_19 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_20;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_20 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_21;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_21 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_22;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_22 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_27;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_27 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_28;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_28 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_29;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_29 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_31;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_31 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_32;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_32 = 0;
    VlWide<16>/*511:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33;
    VL_ZERO_W(512, __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33);
    VlWide<16>/*511:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1;
    VL_ZERO_W(512, __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1);
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___same_cycle_resp_T_1;
    __PVT__monitor__DOT__unnamedblk1__DOT___same_cycle_resp_T_1 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_34;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_34 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_35;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_35 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_36;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_36 = 0;
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_37;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_37 = 0;
    VlWide<4>/*127:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39;
    VL_ZERO_W(128, __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39);
    VlWide<4>/*127:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___GEN_40;
    VL_ZERO_W(128, __PVT__monitor__DOT__unnamedblk1__DOT___GEN_40);
    VlWide<16>/*511:0*/ __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1;
    VL_ZERO_W(512, __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1);
    CData/*0:0*/ __PVT__monitor__DOT__unnamedblk2__DOT___d_first_T_2;
    __PVT__monitor__DOT__unnamedblk2__DOT___d_first_T_2 = 0;
    CData/*2:0*/ __Vdly__r_counter;
    __Vdly__r_counter = 0;
    CData/*2:0*/ __Vdly__monitor__DOT__d_first_counter;
    __Vdly__monitor__DOT__d_first_counter = 0;
    VlWide<4>/*127:0*/ __Vdly__monitor__DOT__inflight;
    VL_ZERO_W(128, __Vdly__monitor__DOT__inflight);
    VlWide<16>/*511:0*/ __Vdly__monitor__DOT__inflight_opcodes;
    VL_ZERO_W(512, __Vdly__monitor__DOT__inflight_opcodes);
    VlWide<16>/*511:0*/ __Vdly__monitor__DOT__inflight_sizes;
    VL_ZERO_W(512, __Vdly__monitor__DOT__inflight_sizes);
    CData/*2:0*/ __Vdly__monitor__DOT__d_first_counter_1;
    __Vdly__monitor__DOT__d_first_counter_1 = 0;
    IData/*31:0*/ __Vdly__monitor__DOT__watchdog;
    __Vdly__monitor__DOT__watchdog = 0;
    CData/*2:0*/ __Vdly__monitor__DOT__d_first_counter_2;
    __Vdly__monitor__DOT__d_first_counter_2 = 0;
    IData/*31:0*/ __Vdly__monitor__DOT__watchdog_1;
    __Vdly__monitor__DOT__watchdog_1 = 0;
    CData/*2:0*/ __Vdly__monitor__DOT__a_first_counter;
    __Vdly__monitor__DOT__a_first_counter = 0;
    CData/*2:0*/ __Vdly__monitor__DOT__a_first_counter_1;
    __Vdly__monitor__DOT__a_first_counter_1 = 0;
    CData/*0:0*/ __Vdly__nodeOut_wdeq_q__DOT__full;
    __Vdly__nodeOut_wdeq_q__DOT__full = 0;
    CData/*0:0*/ __Vdly__queue_arw_deq_q__DOT__full;
    __Vdly__queue_arw_deq_q__DOT__full = 0;
    VlWide<4>/*127:0*/ __Vtemp_hd2b6c582__0;
    VlWide<4>/*127:0*/ __Vtemp_h88366e99__0;
    VlWide<4>/*127:0*/ __Vtemp_h14449d32__0;
    VlWide<16>/*511:0*/ __Vtemp_h4da8319f__0;
    VlWide<4>/*127:0*/ __Vtemp_h88366e99__1;
    VlWide<4>/*127:0*/ __Vtemp_h463eddf8__0;
    VlWide<4>/*127:0*/ __Vtemp_hb6b3ff4d__0;
    VlWide<4>/*127:0*/ __Vtemp_hc4c123ef__0;
    VlWide<16>/*511:0*/ __Vtemp_hbd76628a__0;
    VlWide<4>/*127:0*/ __Vtemp_hd2b6c582__1;
    VlWide<4>/*127:0*/ __Vtemp_hb6b3ff4d__1;
    VlWide<4>/*127:0*/ __Vtemp_hc5f56152__0;
    VlWide<16>/*511:0*/ __Vtemp_hb529c94c__0;
    VlWide<4>/*127:0*/ __Vtemp_h3d43d0e3__0;
    VlWide<33>/*1055:0*/ __Vtemp_h0ac0b756__0;
    VlWide<33>/*1055:0*/ __Vtemp_hda04920f__0;
    VlWide<33>/*1055:0*/ __Vtemp_hd382eca0__0;
    VlWide<33>/*1055:0*/ __Vtemp_h0ac0b756__1;
    VlWide<33>/*1055:0*/ __Vtemp_ha8e41c71__0;
    VlWide<33>/*1055:0*/ __Vtemp_hdb76b3c0__0;
    VlWide<4>/*127:0*/ __Vtemp_hd2b6c582__2;
    VlWide<4>/*127:0*/ __Vtemp_h88366e99__2;
    VlWide<4>/*127:0*/ __Vtemp_hd72e69bc__0;
    VlWide<4>/*127:0*/ __Vtemp_hd2b6c582__3;
    VlWide<4>/*127:0*/ __Vtemp_hb6b3ff4d__2;
    VlWide<4>/*127:0*/ __Vtemp_h61d6301d__0;
    // Body
    __Vdly__nodeOut_wdeq_q__DOT__full = vlSelf->__PVT__nodeOut_wdeq_q__DOT__full;
    __Vdly__r_counter = vlSelf->__PVT__r_counter;
    __Vdly__queue_arw_deq_q__DOT__full = vlSelf->__PVT__queue_arw_deq_q__DOT__full;
    __Vdly__monitor__DOT__a_first_counter = vlSelf->__PVT__monitor__DOT__a_first_counter;
    __Vdly__monitor__DOT__a_first_counter_1 = vlSelf->__PVT__monitor__DOT__a_first_counter_1;
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ (((IData)(1U) 
                                              << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20318: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20318, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20320: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20320, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20324: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20324, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20326: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20326, "");
    }
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ ((((IData)(1U) 
                                               << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                              >> 1U) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count_1)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20330: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20330, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20332: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20332, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc_1)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count_1)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20336: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20336, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20338: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20338, "");
    }
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ ((((IData)(1U) 
                                               << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                              >> 2U) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count_2)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20342: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20342, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20344: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20344, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc_2)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count_2)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20348: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20348, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20350: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20350, "");
    }
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ ((((IData)(1U) 
                                               << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                              >> 3U) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count_3)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20354: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20354, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20356: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20356, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc_3)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count_3)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20360: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20360, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20362: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20362, "");
    }
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ ((((IData)(1U) 
                                               << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                              >> 4U) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count_4)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20366: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20366, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20368: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20368, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc_4)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count_4)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20372: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20372, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20374: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20374, "");
    }
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ ((((IData)(1U) 
                                               << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                              >> 5U) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count_5)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20378: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20378, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20380: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20380, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc_5)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count_5)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20384: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20384, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20386: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20386, "");
    }
    if (VL_UNLIKELY(((~ (IData)(vlSymsp->TOP.reset)) 
                     & (0U == ((0x20U & ((~ ((((IData)(1U) 
                                               << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                              >> 6U) 
                                             & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                         << 5U)) | (IData)(vlSelf->__PVT__count_6)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20390: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20390, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20392: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20392, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__inc_6)) 
                                 | (0x10U != (IData)(vlSelf->__PVT__count_6)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20396: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20396, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20398: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20398, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 7U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_7))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20402: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20402, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20404: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20404, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 7U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_7)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20408: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20408, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20410: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20410, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 8U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_8))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20414: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20414, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20416: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20416, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 8U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_8)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20420: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20420, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20422: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20422, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 9U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_9))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20426: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20426, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20428: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20428, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 9U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_9)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20432: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20432, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20434: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20434, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0xaU) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_10))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20438: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20438, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20440: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20440, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0xaU) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_10)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20444: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20444, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20446: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20446, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0xbU) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_11))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20450: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20450, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20452: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20452, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0xbU) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_11)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20456: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20456, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20458: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20458, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0xcU) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_12))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20462: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20462, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20464: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20464, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0xcU) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_12)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20468: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20468, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20470: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20470, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0xdU) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_13))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20474: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20474, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20476: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20476, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0xdU) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_13)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20480: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20480, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20482: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20482, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0xeU) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_14))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20486: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20486, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20488: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20488, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0xeU) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_14)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20492: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20492, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20494: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20494, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0xfU) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_15))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20498: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20498, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20500: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20500, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0xfU) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_15)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20504: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20504, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20506: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20506, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x10U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_16))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20510: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20510, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20512: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20512, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x10U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_16)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20516: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20516, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20518: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20518, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x11U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_17))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20522: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20522, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20524: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20524, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x11U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_17)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20528: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20528, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20530: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20530, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x12U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_18))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20534: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20534, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20536: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20536, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x12U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_18)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20540: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20540, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20542: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20542, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x13U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_19))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20546: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20546, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20548: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20548, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x13U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_19)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20552: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20552, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20554: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20554, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x14U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_20))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20558: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20558, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20560: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20560, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x14U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_20)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20564: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20564, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20566: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20566, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x15U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_21))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20570: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20570, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20572: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20572, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x15U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_21)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20576: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20576, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20578: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20578, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                      >> 0x16U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))) 
                                 | (IData)(vlSelf->__PVT__count_22))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20582: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:280\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20582, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20584: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20584, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ ((((IData)(1U) 
                                       << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                      >> 0x16U) & (IData)(vlSelf->__PVT___inc_T_22))) 
                                 | (~ (IData)(vlSelf->__PVT__count_22)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20588: Assertion failed in %NysyxSoCFull.fpga.tl2axi4: Assertion failed at ToAXI4.scala:281\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20588, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:20590: Assertion failed in %NysyxSoCFull.fpga.tl2axi4\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 20590, "");
    }
    __Vdly__monitor__DOT__watchdog_1 = vlSelf->__PVT__monitor__DOT__watchdog_1;
    __Vdly__monitor__DOT__watchdog = vlSelf->__PVT__monitor__DOT__watchdog;
    __Vdly__monitor__DOT__inflight_sizes[0U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0U];
    __Vdly__monitor__DOT__inflight_sizes[1U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[1U];
    __Vdly__monitor__DOT__inflight_sizes[2U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[2U];
    __Vdly__monitor__DOT__inflight_sizes[3U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[3U];
    __Vdly__monitor__DOT__inflight_sizes[4U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[4U];
    __Vdly__monitor__DOT__inflight_sizes[5U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[5U];
    __Vdly__monitor__DOT__inflight_sizes[6U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[6U];
    __Vdly__monitor__DOT__inflight_sizes[7U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[7U];
    __Vdly__monitor__DOT__inflight_sizes[8U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[8U];
    __Vdly__monitor__DOT__inflight_sizes[9U] = vlSelf->__PVT__monitor__DOT__inflight_sizes[9U];
    __Vdly__monitor__DOT__inflight_sizes[0xaU] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0xaU];
    __Vdly__monitor__DOT__inflight_sizes[0xbU] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0xbU];
    __Vdly__monitor__DOT__inflight_sizes[0xcU] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0xcU];
    __Vdly__monitor__DOT__inflight_sizes[0xdU] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0xdU];
    __Vdly__monitor__DOT__inflight_sizes[0xeU] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0xeU];
    __Vdly__monitor__DOT__inflight_sizes[0xfU] = vlSelf->__PVT__monitor__DOT__inflight_sizes[0xfU];
    __Vdly__monitor__DOT__inflight_opcodes[0U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[0U];
    __Vdly__monitor__DOT__inflight_opcodes[1U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[1U];
    __Vdly__monitor__DOT__inflight_opcodes[2U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[2U];
    __Vdly__monitor__DOT__inflight_opcodes[3U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[3U];
    __Vdly__monitor__DOT__inflight_opcodes[4U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[4U];
    __Vdly__monitor__DOT__inflight_opcodes[5U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[5U];
    __Vdly__monitor__DOT__inflight_opcodes[6U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[6U];
    __Vdly__monitor__DOT__inflight_opcodes[7U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[7U];
    __Vdly__monitor__DOT__inflight_opcodes[8U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[8U];
    __Vdly__monitor__DOT__inflight_opcodes[9U] = vlSelf->__PVT__monitor__DOT__inflight_opcodes[9U];
    __Vdly__monitor__DOT__inflight_opcodes[0xaU] = 
        vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xaU];
    __Vdly__monitor__DOT__inflight_opcodes[0xbU] = 
        vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xbU];
    __Vdly__monitor__DOT__inflight_opcodes[0xcU] = 
        vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xcU];
    __Vdly__monitor__DOT__inflight_opcodes[0xdU] = 
        vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xdU];
    __Vdly__monitor__DOT__inflight_opcodes[0xeU] = 
        vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xeU];
    __Vdly__monitor__DOT__inflight_opcodes[0xfU] = 
        vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xfU];
    __Vdly__monitor__DOT__inflight[0U] = vlSelf->__PVT__monitor__DOT__inflight[0U];
    __Vdly__monitor__DOT__inflight[1U] = vlSelf->__PVT__monitor__DOT__inflight[1U];
    __Vdly__monitor__DOT__inflight[2U] = vlSelf->__PVT__monitor__DOT__inflight[2U];
    __Vdly__monitor__DOT__inflight[3U] = vlSelf->__PVT__monitor__DOT__inflight[3U];
    __Vdly__monitor__DOT__d_first_counter = vlSelf->__PVT__monitor__DOT__d_first_counter;
    __Vdly__monitor__DOT__d_first_counter_2 = vlSelf->__PVT__monitor__DOT__d_first_counter_2;
    __Vdly__monitor__DOT__d_first_counter_1 = vlSelf->__PVT__monitor__DOT__d_first_counter_1;
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok 
        = (1U & ((((((((~ (IData)((0U != (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                                >> 4U))))) 
                       | (1U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                       >> 4U)))) | 
                      (2U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                    >> 4U)))) | (3U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                                     >> 4U)))) 
                    | (4U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                    >> 4U)))) | (5U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                                     >> 4U)))) 
                  | (6U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                  >> 4U)))) | (7U == 
                                               (7U 
                                                & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                                   >> 4U)))));
    __PVT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T 
        = ((0xbU >= (7U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size)))
            ? (0xfffU & ((IData)(0x1fU) << (7U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size))))
            : 0U);
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_6 = 
        (0x1fU & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address 
                  & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___is_aligned_mask_T))));
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1 
        = (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size))) 
                 | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size) 
                    & (~ (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address 
                          >> 1U)))));
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1 
        = (1U & ((0U != (6U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size))) 
                 | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size) 
                    & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address 
                       >> 1U))));
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask 
        = ((8U & (((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1) 
                   << 3U) | (0xfffffff8U & ((vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address 
                                             << 2U) 
                                            & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address 
                                               << 3U))))) 
           | ((((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_1_1) 
                | (2U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address))) 
               << 2U) | ((((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1) 
                           | (1U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address))) 
                          << 1U) | ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask_sub_0_1) 
                                    | (0U == (3U & vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address))))));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_7 = 
        (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid) 
          & (6U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))) 
         & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_8 = 
        (3U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size) 
                      >> 1U)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_9 = 
        (((~ (IData)((0U != (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                   >> 4U))))) & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_8)) 
         & (3U == (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address 
                   >> 0x1eU)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_10 
        = (2U < (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_param));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_11 
        = (0xfU != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_mask));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_12 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid) 
            & (7U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_13 
        = (1U & ((((((((~ (IData)((0U != (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                                >> 4U))))) 
                       | (1U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                       >> 4U)))) | 
                      (2U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                    >> 4U)))) | (3U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                                     >> 4U)))) 
                    | (4U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                    >> 4U)))) | (5U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                                     >> 4U)))) 
                  | (6U == (7U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                  >> 4U)))) | (7U == 
                                               (7U 
                                                & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                                   >> 4U)))));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_14 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid) 
            & (4U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_15 
        = ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_8) 
           & (3U == (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address 
                     >> 0x1eU)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_16 
        = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_mask) 
           != (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_17 
        = ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_13) 
           & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_15));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_18 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid) 
            & (0U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_19 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid) 
            & (1U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_20 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid) 
            & (2U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_21 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid) 
            & (3U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_22 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid) 
            & (5U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok_1 
        = ((((((((0U == (7U & ((IData)(vlSelf->auto_in_d_bits_source) 
                               >> 4U))) | (1U == (7U 
                                                  & ((IData)(vlSelf->auto_in_d_bits_source) 
                                                     >> 4U)))) 
                | (2U == (7U & ((IData)(vlSelf->auto_in_d_bits_source) 
                                >> 4U)))) | (3U == 
                                             (7U & 
                                              ((IData)(vlSelf->auto_in_d_bits_source) 
                                               >> 4U)))) 
              | (4U == (7U & ((IData)(vlSelf->auto_in_d_bits_source) 
                              >> 4U)))) | (5U == (7U 
                                                  & ((IData)(vlSelf->auto_in_d_bits_source) 
                                                     >> 4U)))) 
            | (6U == (7U & ((IData)(vlSelf->auto_in_d_bits_source) 
                            >> 4U)))) | (7U == (7U 
                                                & ((IData)(vlSelf->auto_in_d_bits_source) 
                                                   >> 4U))));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_27 
        = (1U & ((~ (IData)(vlSelf->auto_in_d_bits_denied)) 
                 | (IData)(vlSelf->auto_in_d_bits_corrupt)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_28 
        = (((IData)(vlSelf->auto_in_d_valid) & (~ (IData)(vlSelf->__PVT__r_wins))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_29 
        = (((IData)(vlSelf->auto_in_d_valid) & (IData)(vlSelf->__PVT__r_wins)) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0U] 
        = ((IData)(vlSelf->auto_in_d_bits_source) << 2U);
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[1U] 
        = ((IData)(vlSelf->auto_in_d_bits_source) >> 0x1eU);
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[2U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[3U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[4U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[5U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[6U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[7U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[8U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[9U] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0xaU] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0xbU] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0xcU] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0xdU] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0xeU] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33[0xfU] = 0U;
    __PVT__monitor__DOT__unnamedblk1__DOT___same_cycle_resp_T_1 
        = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid) 
           & (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1)));
    __Vtemp_hd2b6c582__0[0U] = 1U;
    __Vtemp_hd2b6c582__0[1U] = 0U;
    __Vtemp_hd2b6c582__0[2U] = 0U;
    __Vtemp_hd2b6c582__0[3U] = 0U;
    __Vtemp_h88366e99__0[0U] = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source;
    __Vtemp_h88366e99__0[1U] = 0U;
    __Vtemp_h88366e99__0[2U] = 0U;
    __Vtemp_h88366e99__0[3U] = 0U;
    VL_SHIFTL_WWW(128,128,128, __Vtemp_h14449d32__0, __Vtemp_hd2b6c582__0, __Vtemp_h88366e99__0);
    if (__PVT__monitor__DOT__unnamedblk1__DOT___same_cycle_resp_T_1) {
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[0U] 
            = __Vtemp_h14449d32__0[0U];
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[1U] 
            = __Vtemp_h14449d32__0[1U];
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[2U] 
            = __Vtemp_h14449d32__0[2U];
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[3U] 
            = __Vtemp_h14449d32__0[3U];
    } else {
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[0U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[1U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[2U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[3U] = 0U;
    }
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_34 
        = ((IData)(vlSelf->auto_in_d_valid) & (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_1)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_35 
        = __PVT__monitor__DOT__unnamedblk1__DOT___GEN_34;
    vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp 
        = ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___same_cycle_resp_T_1) 
           & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
              == (IData)(vlSelf->auto_in_d_bits_source)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_36 
        = (((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35) 
            & (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp)) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_37 
        = (((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35) 
            & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_31 
        = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid) 
            & (0U != (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_32 
        = (((IData)(vlSelf->auto_in_d_valid) & (0U 
                                                != (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter))) 
           & (~ (IData)(vlSymsp->TOP.reset)));
    VL_SHIFTR_WWW(512,512,512, __Vtemp_h4da8319f__0, vlSelf->__PVT__monitor__DOT__inflight_opcodes, __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33);
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0U] 
        = __Vtemp_h4da8319f__0[0U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[1U] 
        = __Vtemp_h4da8319f__0[1U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[2U] 
        = __Vtemp_h4da8319f__0[2U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[3U] 
        = __Vtemp_h4da8319f__0[3U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[4U] 
        = __Vtemp_h4da8319f__0[4U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[5U] 
        = __Vtemp_h4da8319f__0[5U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[6U] 
        = __Vtemp_h4da8319f__0[6U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[7U] 
        = __Vtemp_h4da8319f__0[7U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[8U] 
        = __Vtemp_h4da8319f__0[8U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[9U] 
        = __Vtemp_h4da8319f__0[9U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0xaU] 
        = __Vtemp_h4da8319f__0[0xaU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0xbU] 
        = __Vtemp_h4da8319f__0[0xbU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0xcU] 
        = __Vtemp_h4da8319f__0[0xcU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0xdU] 
        = __Vtemp_h4da8319f__0[0xdU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0xeU] 
        = __Vtemp_h4da8319f__0[0xeU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0xfU] 
        = __Vtemp_h4da8319f__0[0xfU];
    if (VL_UNLIKELY(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19009: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19009, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19011: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19011, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_9))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19015: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19015, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19017: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19017, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19021: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19021, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19023: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19023, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (~ (IData)((0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19027: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19027, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19029: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19029, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19033: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19033, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19035: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19035, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_10)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19039: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock carries invalid grow param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19039, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19041: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19041, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_11)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19045: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19045, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19047: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19047, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_7) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19051: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquireBlock is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19051, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19053: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19053, "");
    }
    if (VL_UNLIKELY(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19057: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19057, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19059: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19059, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_9))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19063: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19063, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19065: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19065, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19069: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19069, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19071: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19071, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (~ (IData)((0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size) 
                                                >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19075: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19075, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19077: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19077, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19081: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19081, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19083: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19083, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_10)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19087: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm carries invalid grow param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19087, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19089: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19089, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (~ (IData)((0U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_param))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19093: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19093, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19095: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19095, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_11)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19099: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19099, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19101: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19101, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_12) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19105: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel AcquirePerm is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19105, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19107: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19107, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_13))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19111: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries Get type which master claims it can't emit (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19111, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19113: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19113, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_15))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19117: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries Get type which slave claims it can't support (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19117, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19119: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19119, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19123: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Get carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19123, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19125: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19125, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19129: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Get address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19129, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19131: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19131, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (0U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19135: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Get carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19135, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19137: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19137, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_16)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19141: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Get contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19141, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19143: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19143, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_14) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19147: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Get is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19147, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19149: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19149, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_17))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19153: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries PutFull type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19153, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19155: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19155, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19159: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19159, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19161: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19161, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19165: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19165, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19167: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19167, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (0U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19171: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19171, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19173: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19173, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_18) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_16)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19177: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutFull contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19177, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19179: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19179, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_17))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19183: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries PutPartial type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19183, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19185: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19185, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19189: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19189, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19191: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19191, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19195: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19195, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19197: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19197, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (0U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19201: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial carries invalid param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19201, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19203: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19203, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_19) 
                     & (0U != ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_mask) 
                               & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__mask))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19207: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel PutPartial contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19207, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19209: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19209, "");
    }
    if (VL_UNLIKELY(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_20)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19213: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19213, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19215: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19215, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19219: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19219, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19221: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19221, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19225: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19225, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19227: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19227, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (4U < (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19231: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic carries invalid opcode param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19231, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19233: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19233, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_20) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_16)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19237: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19237, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19239: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19239, "");
    }
    if (VL_UNLIKELY(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_21)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19243: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19243, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19245: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19245, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_21) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19249: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Logical carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19249, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19251: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19251, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_21) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19255: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Logical address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19255, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19257: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19257, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_21) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_param) 
                        >> 2U)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19261: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Logical carries invalid opcode param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19261, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19263: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19263, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_21) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_16)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19267: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Logical contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19267, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19269: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19269, "");
    }
    if (VL_UNLIKELY(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_22)) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19273: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel carries Hint type which is unexpected using diplomatic parameters (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19273, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19275: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19275, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19279: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Hint carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19279, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19281: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19281, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (0U != (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_6))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19285: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Hint address not aligned to size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19285, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19287: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19287, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_param) 
                                     >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19291: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Hint carries invalid opcode param (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19291, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19293: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19293, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_16)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19297: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Hint contains invalid mask (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19297, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19299: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19299, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_22) 
                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19303: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel Hint is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19303, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19305: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19305, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19387: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19387, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19389: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19389, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_28) 
                     & (IData)(vlSelf->auto_in_d_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19393: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAck is corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19393, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19395: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19395, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & (~ (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__source_ok_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19399: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData carries invalid source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19399, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19401: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19401, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_29) 
                     & (~ (IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_27))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19405: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19405, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19407: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19407, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19423: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19423, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19425: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19425, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_param) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__param))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19429: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel param changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19429, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19431: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19431, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                     & ((7U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size)) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19435: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19435, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19437: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19437, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                     & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__source))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19441: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19441, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19443: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19443, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_31) 
                     & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address 
                        != vlSelf->__PVT__monitor__DOT__address)))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19447: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel address changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19447, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19449: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19449, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                     & ((IData)(vlSelf->__PVT__r_wins) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19453: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19453, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19455: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19455, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                     & ((IData)(vlSelf->auto_in_d_bits_size) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19459: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel size changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19459, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19461: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19461, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                     & ((IData)(vlSelf->auto_in_d_bits_source) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19465: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel source changed within multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19465, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19467: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19467, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_32) 
                     & ((IData)(vlSelf->auto_in_d_bits_denied) 
                        != (IData)(vlSelf->__PVT__monitor__DOT__denied))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19471: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel denied changed with multibeat operation (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19471, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19473: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19473, "");
    }
    __Vtemp_h88366e99__1[0U] = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source;
    __Vtemp_h88366e99__1[1U] = 0U;
    __Vtemp_h88366e99__1[2U] = 0U;
    __Vtemp_h88366e99__1[3U] = 0U;
    VL_SHIFTR_WWW(128,128,128, __Vtemp_h463eddf8__0, vlSelf->__PVT__monitor__DOT__inflight, __Vtemp_h88366e99__1);
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39[0U] 
        = __Vtemp_h463eddf8__0[0U];
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39[1U] 
        = __Vtemp_h463eddf8__0[1U];
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39[2U] 
        = __Vtemp_h463eddf8__0[2U];
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39[3U] 
        = __Vtemp_h463eddf8__0[3U];
    if (VL_UNLIKELY((((IData)(vlSelf->__PVT__monitor__DOT___GEN_1) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & __PVT__monitor__DOT__unnamedblk1__DOT___GEN_39[0U]))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19478: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' channel re-used a source ID (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19478, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19480: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19480, "");
    }
    __Vtemp_hb6b3ff4d__0[0U] = vlSelf->auto_in_d_bits_source;
    __Vtemp_hb6b3ff4d__0[1U] = 0U;
    __Vtemp_hb6b3ff4d__0[2U] = 0U;
    __Vtemp_hb6b3ff4d__0[3U] = 0U;
    VL_SHIFTR_WWW(128,128,128, __Vtemp_hc4c123ef__0, vlSelf->__PVT__monitor__DOT__inflight, __Vtemp_hb6b3ff4d__0);
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_40[0U] 
        = __Vtemp_hc4c123ef__0[0U];
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_40[1U] 
        = __Vtemp_hc4c123ef__0[1U];
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_40[2U] 
        = __Vtemp_hc4c123ef__0[2U];
    __PVT__monitor__DOT__unnamedblk1__DOT___GEN_40[3U] 
        = __Vtemp_hc4c123ef__0[3U];
    if (VL_UNLIKELY((((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ (__PVT__monitor__DOT__unnamedblk1__DOT___GEN_40[0U] 
                           | (IData)(vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19485: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19485, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19487: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19487, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_36) 
                     & (~ (((IData)(vlSelf->__PVT__r_wins) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode)))))
                                 : 0U)) | ((IData)(vlSelf->__PVT__r_wins) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode)))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19493: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19493, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19495: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19495, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_36) 
                     & ((7U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size)) 
                        != (IData)(vlSelf->auto_in_d_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19499: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19499, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19501: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19501, "");
    }
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_37) 
                     & (~ (((IData)(vlSelf->__PVT__r_wins) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & 
                                               (__PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0U] 
                                                >> 1U)))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (__PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0U] 
                                                     >> 1U))))))
                                 : 0U)) | ((IData)(vlSelf->__PVT__r_wins) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (__PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0U] 
                                                        >> 1U)))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (__PVT__monitor__DOT__unnamedblk1__DOT___a_opcode_lookup_T_1[0U] 
                                                              >> 1U))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19507: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper opcode response (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19507, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19509: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19509, "");
    }
    VL_SHIFTR_WWW(512,512,512, __Vtemp_hbd76628a__0, vlSelf->__PVT__monitor__DOT__inflight_sizes, __PVT__monitor__DOT__unnamedblk1__DOT___GEN_33);
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0U] 
        = __Vtemp_hbd76628a__0[0U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[1U] 
        = __Vtemp_hbd76628a__0[1U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[2U] 
        = __Vtemp_hbd76628a__0[2U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[3U] 
        = __Vtemp_hbd76628a__0[3U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[4U] 
        = __Vtemp_hbd76628a__0[4U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[5U] 
        = __Vtemp_hbd76628a__0[5U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[6U] 
        = __Vtemp_hbd76628a__0[6U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[7U] 
        = __Vtemp_hbd76628a__0[7U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[8U] 
        = __Vtemp_hbd76628a__0[8U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[9U] 
        = __Vtemp_hbd76628a__0[9U];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0xaU] 
        = __Vtemp_hbd76628a__0[0xaU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0xbU] 
        = __Vtemp_hbd76628a__0[0xbU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0xcU] 
        = __Vtemp_hbd76628a__0[0xcU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0xdU] 
        = __Vtemp_hbd76628a__0[0xdU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0xeU] 
        = __Vtemp_hbd76628a__0[0xeU];
    __PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0xfU] 
        = __Vtemp_hbd76628a__0[0xfU];
    if (VL_UNLIKELY(((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_37) 
                     & ((IData)(vlSelf->auto_in_d_bits_size) 
                        != (7U & (__PVT__monitor__DOT__unnamedblk1__DOT___a_size_lookup_T_1[0U] 
                                  >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19514: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'D' channel contains improper response size (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19514, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19516: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19516, "");
    }
    if (VL_UNLIKELY(((((((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_34) 
                         & (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1))) 
                        & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid)) 
                       & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                          == (IData)(vlSelf->auto_in_d_bits_source))) 
                      & (~ (IData)(vlSymsp->TOP.reset))) 
                     & (~ ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_d_ready)) 
                           | (IData)(vlSelf->auto_in_a_ready)))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19521: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: ready check\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19521, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19523: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19523, "");
    }
    __Vtemp_hd2b6c582__1[0U] = 1U;
    __Vtemp_hd2b6c582__1[1U] = 0U;
    __Vtemp_hd2b6c582__1[2U] = 0U;
    __Vtemp_hd2b6c582__1[3U] = 0U;
    __Vtemp_hb6b3ff4d__1[0U] = vlSelf->auto_in_d_bits_source;
    __Vtemp_hb6b3ff4d__1[1U] = 0U;
    __Vtemp_hb6b3ff4d__1[2U] = 0U;
    __Vtemp_hb6b3ff4d__1[3U] = 0U;
    VL_SHIFTL_WWW(128,128,128, __Vtemp_hc5f56152__0, __Vtemp_hd2b6c582__1, __Vtemp_hb6b3ff4d__1);
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((0U != ((((vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[0U] 
                                            ^ ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35)
                                                ? __Vtemp_hc5f56152__0[0U]
                                                : 0U)) 
                                           | (vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[1U] 
                                              ^ ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35)
                                                  ? 
                                                 __Vtemp_hc5f56152__0[1U]
                                                  : 0U))) 
                                          | (vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[2U] 
                                             ^ ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35)
                                                 ? 
                                                __Vtemp_hc5f56152__0[2U]
                                                 : 0U))) 
                                         | (vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[3U] 
                                            ^ ((IData)(__PVT__monitor__DOT__unnamedblk1__DOT___GEN_35)
                                                ? __Vtemp_hc5f56152__0[3U]
                                                : 0U)))) 
                                 | (0U == (((vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[0U] 
                                             | vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[1U]) 
                                            | vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[2U]) 
                                           | vlSelf->__PVT__monitor__DOT__unnamedblk1__DOT__a_set_wo_ready[3U])))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19529: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: 'A' and 'D' concurrent, despite minlatency > 0 (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19529, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19531: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19531, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (((vlSelf->__PVT__monitor__DOT__inflight[0U] 
                                            | vlSelf->__PVT__monitor__DOT__inflight[1U]) 
                                           | vlSelf->__PVT__monitor__DOT__inflight[2U]) 
                                          | vlSelf->__PVT__monitor__DOT__inflight[3U])) 
                                  | (0U == vlSelf->__PVT__monitor__DOT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->__PVT__monitor__DOT__watchdog 
                                    < vlSelf->__PVT__monitor__DOT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19537: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19537, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19539: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19539, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ (((0U == (((vlSelf->__PVT__monitor__DOT__inflight_1[0U] 
                                            | vlSelf->__PVT__monitor__DOT__inflight_1[1U]) 
                                           | vlSelf->__PVT__monitor__DOT__inflight_1[2U]) 
                                          | vlSelf->__PVT__monitor__DOT__inflight_1[3U])) 
                                  | (0U == vlSelf->__PVT__monitor__DOT__plusarg_reader_1__DOT__myplus)) 
                                 | (vlSelf->__PVT__monitor__DOT__watchdog_1 
                                    < vlSelf->__PVT__monitor__DOT__plusarg_reader_1__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19559: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1: Assertion failed: TileLink timeout expired (connected at home/yanlx/ysyx-workbench/ysyxSoC/src/device/ChipLinkBridge.scala:80:80)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19559, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:19561: Assertion failed in %NysyxSoCFull.fpga.tl2axi4.monitor.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 19561, "");
    }
    if (vlSymsp->TOP.reset) {
        __Vtemp_hb529c94c__0[1U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[1U];
        __Vtemp_hb529c94c__0[2U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[2U];
        __Vtemp_hb529c94c__0[3U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[3U];
        __Vtemp_hb529c94c__0[4U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[4U];
        __Vtemp_hb529c94c__0[5U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[5U];
        __Vtemp_hb529c94c__0[6U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[6U];
        __Vtemp_hb529c94c__0[7U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[7U];
        __Vtemp_hb529c94c__0[8U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[8U];
        __Vtemp_hb529c94c__0[9U] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[9U];
        __Vtemp_hb529c94c__0[0xaU] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xaU];
        __Vtemp_hb529c94c__0[0xbU] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xbU];
        __Vtemp_hb529c94c__0[0xcU] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xcU];
        __Vtemp_hb529c94c__0[0xdU] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xdU];
        __Vtemp_hb529c94c__0[0xeU] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xeU];
        __Vtemp_hb529c94c__0[0xfU] = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xfU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0U] 
            = VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[1U] 
            = __Vtemp_hb529c94c__0[1U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[2U] 
            = __Vtemp_hb529c94c__0[2U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[3U] 
            = __Vtemp_hb529c94c__0[3U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[4U] 
            = __Vtemp_hb529c94c__0[4U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[5U] 
            = __Vtemp_hb529c94c__0[5U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[6U] 
            = __Vtemp_hb529c94c__0[6U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[7U] 
            = __Vtemp_hb529c94c__0[7U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[8U] 
            = __Vtemp_hb529c94c__0[8U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[9U] 
            = __Vtemp_hb529c94c__0[9U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xaU] 
            = __Vtemp_hb529c94c__0[0xaU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xbU] 
            = __Vtemp_hb529c94c__0[0xbU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xcU] 
            = __Vtemp_hb529c94c__0[0xcU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xdU] 
            = __Vtemp_hb529c94c__0[0xdU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xeU] 
            = __Vtemp_hb529c94c__0[0xeU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xfU] 
            = __Vtemp_hb529c94c__0[0xfU];
        __Vtemp_h3d43d0e3__0[1U] = 0U;
        __Vtemp_h3d43d0e3__0[2U] = 0U;
        __Vtemp_h3d43d0e3__0[3U] = 0U;
        vlSelf->__PVT__monitor__DOT__inflight_1[0U] = 0U;
    } else {
        __Vtemp_hb529c94c__0[1U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[1U];
        __Vtemp_hb529c94c__0[2U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[2U];
        __Vtemp_hb529c94c__0[3U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[3U];
        __Vtemp_hb529c94c__0[4U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[4U];
        __Vtemp_hb529c94c__0[5U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[5U];
        __Vtemp_hb529c94c__0[6U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[6U];
        __Vtemp_hb529c94c__0[7U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[7U];
        __Vtemp_hb529c94c__0[8U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[8U];
        __Vtemp_hb529c94c__0[9U] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[9U];
        __Vtemp_hb529c94c__0[0xaU] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xaU];
        __Vtemp_hb529c94c__0[0xbU] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xbU];
        __Vtemp_hb529c94c__0[0xcU] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xcU];
        __Vtemp_hb529c94c__0[0xdU] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xdU];
        __Vtemp_hb529c94c__0[0xeU] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xeU];
        __Vtemp_hb529c94c__0[0xfU] = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xfU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0U] 
            = vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[1U] 
            = __Vtemp_hb529c94c__0[1U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[2U] 
            = __Vtemp_hb529c94c__0[2U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[3U] 
            = __Vtemp_hb529c94c__0[3U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[4U] 
            = __Vtemp_hb529c94c__0[4U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[5U] 
            = __Vtemp_hb529c94c__0[5U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[6U] 
            = __Vtemp_hb529c94c__0[6U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[7U] 
            = __Vtemp_hb529c94c__0[7U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[8U] 
            = __Vtemp_hb529c94c__0[8U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[9U] 
            = __Vtemp_hb529c94c__0[9U];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xaU] 
            = __Vtemp_hb529c94c__0[0xaU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xbU] 
            = __Vtemp_hb529c94c__0[0xbU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xcU] 
            = __Vtemp_hb529c94c__0[0xcU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xdU] 
            = __Vtemp_hb529c94c__0[0xdU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xeU] 
            = __Vtemp_hb529c94c__0[0xeU];
        vlSelf->__PVT__monitor__DOT__inflight_sizes_1[0xfU] 
            = __Vtemp_hb529c94c__0[0xfU];
        __Vtemp_h3d43d0e3__0[1U] = vlSelf->__PVT__monitor__DOT__inflight_1[1U];
        __Vtemp_h3d43d0e3__0[2U] = vlSelf->__PVT__monitor__DOT__inflight_1[2U];
        __Vtemp_h3d43d0e3__0[3U] = vlSelf->__PVT__monitor__DOT__inflight_1[3U];
        vlSelf->__PVT__monitor__DOT__inflight_1[0U] 
            = vlSelf->__PVT__monitor__DOT__inflight_1[0U];
    }
    vlSelf->__PVT__monitor__DOT__inflight_1[1U] = __Vtemp_h3d43d0e3__0[1U];
    vlSelf->__PVT__monitor__DOT__inflight_1[2U] = __Vtemp_h3d43d0e3__0[2U];
    vlSelf->__PVT__monitor__DOT__inflight_1[3U] = __Vtemp_h3d43d0e3__0[3U];
    vlSelf->__PVT__count_7 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                    & (((IData)(vlSelf->__PVT__count_7) 
                                        + ((((IData)(1U) 
                                             << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                            >> 7U) 
                                           & (IData)(vlSelf->__PVT___inc_T_22))) 
                                       - ((((IData)(1U) 
                                            << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                           >> 7U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_8 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                    & (((IData)(vlSelf->__PVT__count_8) 
                                        + ((((IData)(1U) 
                                             << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                            >> 8U) 
                                           & (IData)(vlSelf->__PVT___inc_T_22))) 
                                       - ((((IData)(1U) 
                                            << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                           >> 8U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_9 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                    & (((IData)(vlSelf->__PVT__count_9) 
                                        + ((((IData)(1U) 
                                             << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                            >> 9U) 
                                           & (IData)(vlSelf->__PVT___inc_T_22))) 
                                       - ((((IData)(1U) 
                                            << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                           >> 9U) & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_10 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_10) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0xaU) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0xaU) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_11 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_11) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0xbU) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0xbU) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_12 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_12) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0xcU) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0xcU) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_13 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_13) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0xdU) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0xdU) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_14 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_14) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0xeU) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0xeU) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_15 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_15) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0xfU) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0xfU) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_16 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_16) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x10U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x10U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_17 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_17) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x11U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x11U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_18 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_18) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x12U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x12U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_19 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_19) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x13U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x13U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_20 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_20) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x14U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x14U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_21 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_21) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x15U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x15U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__count_22 = (1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                                     & (((IData)(vlSelf->__PVT__count_22) 
                                         + ((((IData)(1U) 
                                              << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                                             >> 0x16U) 
                                            & (IData)(vlSelf->__PVT___inc_T_22))) 
                                        - ((((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            >> 0x16U) 
                                           & (IData)(vlSelf->__VdfgTmp_hc0989b25__0)))));
    vlSelf->__PVT__b_delay = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_bvalid) 
                               & (~ (IData)(vlSelf->auto_out_bready)))
                               ? (7U & ((IData)(1U) 
                                        + (IData)(vlSelf->__PVT__b_delay)))
                               : 0U);
    if (vlSelf->__PVT__nodeOut_wdeq_q__DOT__do_enq) {
        vlSelf->__PVT__nodeOut_wdeq_q__DOT__ram = (
                                                   ((QData)((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_data)) 
                                                    << 5U) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_mask) 
                                                                       << 1U) 
                                                                      | (IData)(vlSelf->__PVT__a_last)))));
    }
    if (vlSelf->__PVT__inc_6) {
        vlSelf->__PVT__write_6 = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                           >> 2U)));
    }
    if (vlSelf->__PVT__inc_3) {
        vlSelf->__PVT__write_3 = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                           >> 2U)));
    }
    if (vlSelf->__PVT__inc_1) {
        vlSelf->__PVT__write_1 = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                           >> 2U)));
    }
    if (vlSelf->__PVT__inc_5) {
        vlSelf->__PVT__write_5 = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                           >> 2U)));
    }
    if (vlSelf->__PVT__inc_4) {
        vlSelf->__PVT__write_4 = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                           >> 2U)));
    }
    if (vlSelf->__PVT__inc) {
        vlSelf->__PVT__write = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                         >> 2U)));
    }
    if (vlSelf->__PVT__inc_2) {
        vlSelf->__PVT__write_2 = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                           >> 2U)));
    }
    if (vlSelf->__PVT__queue_arw_deq_q__DOT__do_enq) {
        vlSelf->__PVT__queue_arw_deq_q__DOT__ram = 
            (((QData)((IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
              << 0x39U) | (((QData)((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address)) 
                            << 0x19U) | (QData)((IData)(
                                                        (0x1000U 
                                                         | ((0x1fe0000U 
                                                             & ((~ 
                                                                 (0x7fffU 
                                                                  & (((IData)(0x3ffU) 
                                                                      << 
                                                                      (7U 
                                                                       & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size))) 
                                                                     >> 2U))) 
                                                                << 0x11U)) 
                                                            | (((IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_size) 
                                                                << 0xeU) 
                                                               | ((0x700U 
                                                                   & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size) 
                                                                      << 8U)) 
                                                                  | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                                                      << 1U) 
                                                                     | (1U 
                                                                        & (~ 
                                                                           ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                                                            >> 2U))))))))))));
    }
    if (vlSelf->__PVT__r_first) {
        vlSelf->__PVT__r_denied_r = (3U == (3U & (IData)(
                                                         (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                          >> 2U))));
    }
    if (vlSymsp->TOP.reset) {
        __Vdly__nodeOut_wdeq_q__DOT__full = 0U;
        vlSelf->__PVT__nodeOut_wdeq_q__DOT__full = __Vdly__nodeOut_wdeq_q__DOT__full;
        vlSelf->__PVT__count_6 = 0U;
        vlSelf->__PVT__count_5 = 0U;
        vlSelf->__PVT__count_3 = 0U;
        vlSelf->__PVT__count_1 = 0U;
        vlSelf->__PVT__count_2 = 0U;
        vlSelf->__PVT__count = 0U;
        vlSelf->__PVT__count_4 = 0U;
        __Vdly__r_counter = 0U;
        vlSelf->__PVT__r_counter = __Vdly__r_counter;
        __Vdly__queue_arw_deq_q__DOT__full = 0U;
    } else {
        if (((((IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full) 
               & (~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__in_wdeq_q__DOT__full))) 
              & (IData)(vlSelf->auto_out_wvalid)) != (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__do_enq))) {
            __Vdly__nodeOut_wdeq_q__DOT__full = vlSelf->__PVT__nodeOut_wdeq_q__DOT__do_enq;
        }
        vlSelf->__PVT__nodeOut_wdeq_q__DOT__full = __Vdly__nodeOut_wdeq_q__DOT__full;
        vlSelf->__PVT__count_6 = (0x1fU & (((IData)(vlSelf->__PVT__count_6) 
                                            + (IData)(vlSelf->__PVT__inc_6)) 
                                           - ((((IData)(1U) 
                                                << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                               >> 6U) 
                                              & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        vlSelf->__PVT__count_5 = (0x1fU & (((IData)(vlSelf->__PVT__count_5) 
                                            + (IData)(vlSelf->__PVT__inc_5)) 
                                           - ((((IData)(1U) 
                                                << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                               >> 5U) 
                                              & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        vlSelf->__PVT__count_3 = (0x1fU & (((IData)(vlSelf->__PVT__count_3) 
                                            + (IData)(vlSelf->__PVT__inc_3)) 
                                           - ((((IData)(1U) 
                                                << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                               >> 3U) 
                                              & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        vlSelf->__PVT__count_1 = (0x1fU & (((IData)(vlSelf->__PVT__count_1) 
                                            + (IData)(vlSelf->__PVT__inc_1)) 
                                           - ((((IData)(1U) 
                                                << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                               >> 1U) 
                                              & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        vlSelf->__PVT__count_2 = (0x1fU & (((IData)(vlSelf->__PVT__count_2) 
                                            + (IData)(vlSelf->__PVT__inc_2)) 
                                           - ((((IData)(1U) 
                                                << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                               >> 2U) 
                                              & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        vlSelf->__PVT__count = (0x1fU & (((IData)(vlSelf->__PVT__count) 
                                          + (IData)(vlSelf->__PVT__inc)) 
                                         - (((IData)(1U) 
                                             << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                            & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        vlSelf->__PVT__count_4 = (0x1fU & (((IData)(vlSelf->__PVT__count_4) 
                                            + (IData)(vlSelf->__PVT__inc_4)) 
                                           - ((((IData)(1U) 
                                                << (IData)(vlSelf->__VdfgTmp_h3c545424__0)) 
                                               >> 4U) 
                                              & (IData)(vlSelf->__VdfgTmp_hc0989b25__0))));
        if (((IData)(vlSelf->auto_in_a_ready) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid))) {
            __Vdly__r_counter = (7U & ((IData)(vlSelf->__PVT__a_first)
                                        ? (IData)(vlSelf->__PVT__r_beats1)
                                        : ((IData)(vlSelf->__PVT__r_counter) 
                                           - (IData)(1U))));
        }
        vlSelf->__PVT__r_counter = __Vdly__r_counter;
        if (((IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__do_enq) 
             != (((IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full) 
                  & (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_deq_ready)) 
                 & (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__io_deq_valid_0)))) {
            __Vdly__queue_arw_deq_q__DOT__full = vlSelf->__PVT__queue_arw_deq_q__DOT__do_enq;
        }
    }
    vlSelf->__PVT__queue_arw_deq_q__DOT__full = __Vdly__queue_arw_deq_q__DOT__full;
    if (((IData)(vlSelf->__PVT__monitor__DOT___a_first_T_1) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter)))))) {
        vlSelf->__PVT__monitor__DOT__opcode = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode;
        vlSelf->__PVT__monitor__DOT__param = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_param;
        vlSelf->__PVT__monitor__DOT__size = (7U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size));
        vlSelf->__PVT__monitor__DOT__source = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source;
        vlSelf->__PVT__monitor__DOT__address = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address;
    }
    __PVT__monitor__DOT__unnamedblk2__DOT___d_first_T_2 
        = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_d_ready) 
           & (IData)(vlSelf->auto_in_d_valid));
    if (vlSymsp->TOP.reset) {
        vlSelf->__PVT__doneAW = 0U;
        vlSelf->__PVT__r_holds_d = 0U;
        __Vdly__monitor__DOT__a_first_counter = 0U;
        __Vdly__monitor__DOT__a_first_counter_1 = 0U;
        __Vdly__monitor__DOT__d_first_counter = 0U;
        __Vdly__monitor__DOT__inflight[0U] = 0U;
        __Vdly__monitor__DOT__inflight[1U] = 0U;
        __Vdly__monitor__DOT__inflight[2U] = 0U;
        __Vdly__monitor__DOT__inflight[3U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[1U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[2U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[3U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[4U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[5U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[6U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[7U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[8U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[9U] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0xaU] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0xbU] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0xcU] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0xdU] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0xeU] = 0U;
        __Vdly__monitor__DOT__inflight_opcodes[0xfU] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[1U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[2U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[3U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[4U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[5U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[6U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[7U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[8U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[9U] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0xaU] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0xbU] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0xcU] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0xdU] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0xeU] = 0U;
        __Vdly__monitor__DOT__inflight_sizes[0xfU] = 0U;
        __Vdly__monitor__DOT__d_first_counter_1 = 0U;
        __Vdly__monitor__DOT__watchdog = 0U;
        __Vdly__monitor__DOT__d_first_counter_2 = 0U;
        __Vdly__monitor__DOT__watchdog_1 = 0U;
        vlSelf->__PVT__r_first = 1U;
    } else {
        if (((IData)(vlSelf->auto_in_a_ready) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid))) {
            vlSelf->__PVT__doneAW = (1U & (~ (IData)(vlSelf->__PVT__a_last)));
        }
        if (((IData)(vlSelf->auto_out_rready) & (~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__empty)))) {
            vlSelf->__PVT__r_holds_d = (1U & (~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast)));
            vlSelf->__PVT__r_first = vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast;
        }
        if (vlSelf->__PVT__monitor__DOT___a_first_T_1) {
            vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3 
                = ((0xbU >= (7U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size)))
                    ? (0xfffU & ((IData)(0x1fU) << 
                                 (7U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size))))
                    : 0U);
            __Vdly__monitor__DOT__a_first_counter = 
                (7U & ((0U != (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter))
                        ? ((IData)(vlSelf->__PVT__monitor__DOT__a_first_counter) 
                           - (IData)(1U)) : ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))
                                              ? 0U : 
                                             (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3) 
                                                 >> 2U)))));
            __Vdly__monitor__DOT__a_first_counter_1 
                = (7U & ((IData)(vlSelf->__PVT__monitor__DOT__a_first_1)
                          ? ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))
                              ? 0U : (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT___a_first_beats1_decode_T_3) 
                                         >> 2U))) : 
                         ((IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1) 
                          - (IData)(1U))));
        }
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
               << 2U);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[1U] 
            = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
               >> 0x1eU);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[2U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[3U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[4U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[5U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[6U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[7U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[8U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[9U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0xaU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0xbU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0xcU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0xdU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0xeU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0xfU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x10U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x11U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x12U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x13U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x14U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x15U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x16U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x17U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x18U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x19U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x1aU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x1bU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x1cU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x1dU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x1eU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x1fU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42[0x20U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0U] 
            = ((IData)(vlSelf->auto_in_d_bits_source) 
               << 2U);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[1U] 
            = ((IData)(vlSelf->auto_in_d_bits_source) 
               >> 0x1eU);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[2U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[3U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[4U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[5U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[6U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[7U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[8U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[9U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0xaU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0xbU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0xcU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0xdU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0xeU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0xfU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x10U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x11U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x12U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x13U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x14U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x15U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x16U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x17U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x18U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x19U] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x1aU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x1bU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x1cU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x1dU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x1eU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x1fU] = 0U;
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44[0x20U] = 0U;
        VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h0ac0b756__0, VysyxSoCFull__ConstPool__CONST_h3892cc72_0, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0U] 
               & __Vtemp_h0ac0b756__0[0U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[1U] 
               & __Vtemp_h0ac0b756__0[1U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[2U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[2U] 
               & __Vtemp_h0ac0b756__0[2U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[3U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[3U] 
               & __Vtemp_h0ac0b756__0[3U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[4U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[4U] 
               & __Vtemp_h0ac0b756__0[4U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[5U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[5U] 
               & __Vtemp_h0ac0b756__0[5U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[6U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[6U] 
               & __Vtemp_h0ac0b756__0[6U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[7U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[7U] 
               & __Vtemp_h0ac0b756__0[7U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[8U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[8U] 
               & __Vtemp_h0ac0b756__0[8U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[9U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[9U] 
               & __Vtemp_h0ac0b756__0[9U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xaU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xaU] 
               & __Vtemp_h0ac0b756__0[0xaU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xbU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xbU] 
               & __Vtemp_h0ac0b756__0[0xbU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xcU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xcU] 
               & __Vtemp_h0ac0b756__0[0xcU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xdU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xdU] 
               & __Vtemp_h0ac0b756__0[0xdU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xeU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xeU] 
               & __Vtemp_h0ac0b756__0[0xeU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xfU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xfU] 
               & __Vtemp_h0ac0b756__0[0xfU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x10U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x10U] 
               & __Vtemp_h0ac0b756__0[0x10U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x11U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x11U] 
               & __Vtemp_h0ac0b756__0[0x11U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x12U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x12U] 
               & __Vtemp_h0ac0b756__0[0x12U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x13U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x13U] 
               & __Vtemp_h0ac0b756__0[0x13U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x14U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x14U] 
               & __Vtemp_h0ac0b756__0[0x14U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x15U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x15U] 
               & __Vtemp_h0ac0b756__0[0x15U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x16U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x16U] 
               & __Vtemp_h0ac0b756__0[0x16U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x17U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x17U] 
               & __Vtemp_h0ac0b756__0[0x17U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x18U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x18U] 
               & __Vtemp_h0ac0b756__0[0x18U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x19U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x19U] 
               & __Vtemp_h0ac0b756__0[0x19U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x1aU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1aU] 
               & __Vtemp_h0ac0b756__0[0x1aU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x1bU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1bU] 
               & __Vtemp_h0ac0b756__0[0x1bU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x1cU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1cU] 
               & __Vtemp_h0ac0b756__0[0x1cU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x1dU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1dU] 
               & __Vtemp_h0ac0b756__0[0x1dU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x1eU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1eU] 
               & __Vtemp_h0ac0b756__0[0x1eU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x1fU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1fU] 
               & __Vtemp_h0ac0b756__0[0x1fU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0x20U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x20U] 
               & __Vtemp_h0ac0b756__0[0x20U]);
        if (vlSelf->__PVT__monitor__DOT___GEN_1) {
            __Vtemp_hda04920f__0[0U] = (1U | ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                              << 1U));
            __Vtemp_ha8e41c71__0[0U] = (1U | (0xeU 
                                              & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size) 
                                                 << 1U)));
        } else {
            __Vtemp_hda04920f__0[0U] = 0U;
            __Vtemp_ha8e41c71__0[0U] = 0U;
        }
        __Vtemp_hda04920f__0[1U] = 0U;
        __Vtemp_hda04920f__0[2U] = 0U;
        __Vtemp_hda04920f__0[3U] = 0U;
        __Vtemp_hda04920f__0[4U] = 0U;
        __Vtemp_hda04920f__0[5U] = 0U;
        __Vtemp_hda04920f__0[6U] = 0U;
        __Vtemp_hda04920f__0[7U] = 0U;
        __Vtemp_hda04920f__0[8U] = 0U;
        __Vtemp_hda04920f__0[9U] = 0U;
        __Vtemp_hda04920f__0[0xaU] = 0U;
        __Vtemp_hda04920f__0[0xbU] = 0U;
        __Vtemp_hda04920f__0[0xcU] = 0U;
        __Vtemp_hda04920f__0[0xdU] = 0U;
        __Vtemp_hda04920f__0[0xeU] = 0U;
        __Vtemp_hda04920f__0[0xfU] = 0U;
        __Vtemp_hda04920f__0[0x10U] = 0U;
        __Vtemp_hda04920f__0[0x11U] = 0U;
        __Vtemp_hda04920f__0[0x12U] = 0U;
        __Vtemp_hda04920f__0[0x13U] = 0U;
        __Vtemp_hda04920f__0[0x14U] = 0U;
        __Vtemp_hda04920f__0[0x15U] = 0U;
        __Vtemp_hda04920f__0[0x16U] = 0U;
        __Vtemp_hda04920f__0[0x17U] = 0U;
        __Vtemp_hda04920f__0[0x18U] = 0U;
        __Vtemp_hda04920f__0[0x19U] = 0U;
        __Vtemp_hda04920f__0[0x1aU] = 0U;
        __Vtemp_hda04920f__0[0x1bU] = 0U;
        __Vtemp_hda04920f__0[0x1cU] = 0U;
        __Vtemp_hda04920f__0[0x1dU] = 0U;
        __Vtemp_hda04920f__0[0x1eU] = 0U;
        __Vtemp_hda04920f__0[0x1fU] = 0U;
        __Vtemp_hda04920f__0[0x20U] = 0U;
        VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_hd382eca0__0, __Vtemp_hda04920f__0, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0U] 
               & __Vtemp_hd382eca0__0[0U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[1U] 
               & __Vtemp_hd382eca0__0[1U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[2U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[2U] 
               & __Vtemp_hd382eca0__0[2U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[3U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[3U] 
               & __Vtemp_hd382eca0__0[3U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[4U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[4U] 
               & __Vtemp_hd382eca0__0[4U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[5U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[5U] 
               & __Vtemp_hd382eca0__0[5U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[6U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[6U] 
               & __Vtemp_hd382eca0__0[6U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[7U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[7U] 
               & __Vtemp_hd382eca0__0[7U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[8U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[8U] 
               & __Vtemp_hd382eca0__0[8U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[9U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[9U] 
               & __Vtemp_hd382eca0__0[9U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xaU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xaU] 
               & __Vtemp_hd382eca0__0[0xaU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xbU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xbU] 
               & __Vtemp_hd382eca0__0[0xbU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xcU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xcU] 
               & __Vtemp_hd382eca0__0[0xcU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xdU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xdU] 
               & __Vtemp_hd382eca0__0[0xdU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xeU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xeU] 
               & __Vtemp_hd382eca0__0[0xeU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xfU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xfU] 
               & __Vtemp_hd382eca0__0[0xfU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x10U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x10U] 
               & __Vtemp_hd382eca0__0[0x10U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x11U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x11U] 
               & __Vtemp_hd382eca0__0[0x11U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x12U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x12U] 
               & __Vtemp_hd382eca0__0[0x12U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x13U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x13U] 
               & __Vtemp_hd382eca0__0[0x13U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x14U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x14U] 
               & __Vtemp_hd382eca0__0[0x14U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x15U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x15U] 
               & __Vtemp_hd382eca0__0[0x15U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x16U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x16U] 
               & __Vtemp_hd382eca0__0[0x16U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x17U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x17U] 
               & __Vtemp_hd382eca0__0[0x17U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x18U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x18U] 
               & __Vtemp_hd382eca0__0[0x18U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x19U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x19U] 
               & __Vtemp_hd382eca0__0[0x19U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x1aU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1aU] 
               & __Vtemp_hd382eca0__0[0x1aU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x1bU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1bU] 
               & __Vtemp_hd382eca0__0[0x1bU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x1cU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1cU] 
               & __Vtemp_hd382eca0__0[0x1cU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x1dU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1dU] 
               & __Vtemp_hd382eca0__0[0x1dU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x1eU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1eU] 
               & __Vtemp_hd382eca0__0[0x1eU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x1fU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1fU] 
               & __Vtemp_hd382eca0__0[0x1fU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0x20U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x20U] 
               & __Vtemp_hd382eca0__0[0x20U]);
        VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h0ac0b756__1, VysyxSoCFull__ConstPool__CONST_h3892cc72_0, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_44);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0U] 
               & __Vtemp_h0ac0b756__1[0U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[1U] 
               & __Vtemp_h0ac0b756__1[1U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[2U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[2U] 
               & __Vtemp_h0ac0b756__1[2U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[3U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[3U] 
               & __Vtemp_h0ac0b756__1[3U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[4U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[4U] 
               & __Vtemp_h0ac0b756__1[4U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[5U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[5U] 
               & __Vtemp_h0ac0b756__1[5U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[6U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[6U] 
               & __Vtemp_h0ac0b756__1[6U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[7U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[7U] 
               & __Vtemp_h0ac0b756__1[7U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[8U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[8U] 
               & __Vtemp_h0ac0b756__1[8U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[9U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[9U] 
               & __Vtemp_h0ac0b756__1[9U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xaU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xaU] 
               & __Vtemp_h0ac0b756__1[0xaU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xbU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xbU] 
               & __Vtemp_h0ac0b756__1[0xbU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xcU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xcU] 
               & __Vtemp_h0ac0b756__1[0xcU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xdU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xdU] 
               & __Vtemp_h0ac0b756__1[0xdU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xeU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xeU] 
               & __Vtemp_h0ac0b756__1[0xeU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xfU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0xfU] 
               & __Vtemp_h0ac0b756__1[0xfU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x10U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x10U] 
               & __Vtemp_h0ac0b756__1[0x10U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x11U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x11U] 
               & __Vtemp_h0ac0b756__1[0x11U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x12U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x12U] 
               & __Vtemp_h0ac0b756__1[0x12U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x13U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x13U] 
               & __Vtemp_h0ac0b756__1[0x13U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x14U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x14U] 
               & __Vtemp_h0ac0b756__1[0x14U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x15U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x15U] 
               & __Vtemp_h0ac0b756__1[0x15U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x16U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x16U] 
               & __Vtemp_h0ac0b756__1[0x16U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x17U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x17U] 
               & __Vtemp_h0ac0b756__1[0x17U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x18U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x18U] 
               & __Vtemp_h0ac0b756__1[0x18U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x19U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x19U] 
               & __Vtemp_h0ac0b756__1[0x19U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x1aU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1aU] 
               & __Vtemp_h0ac0b756__1[0x1aU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x1bU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1bU] 
               & __Vtemp_h0ac0b756__1[0x1bU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x1cU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1cU] 
               & __Vtemp_h0ac0b756__1[0x1cU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x1dU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1dU] 
               & __Vtemp_h0ac0b756__1[0x1dU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x1eU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1eU] 
               & __Vtemp_h0ac0b756__1[0x1eU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x1fU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x1fU] 
               & __Vtemp_h0ac0b756__1[0x1fU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0x20U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d81c7e_0[0x20U] 
               & __Vtemp_h0ac0b756__1[0x20U]);
        __Vtemp_ha8e41c71__0[1U] = 0U;
        __Vtemp_ha8e41c71__0[2U] = 0U;
        __Vtemp_ha8e41c71__0[3U] = 0U;
        __Vtemp_ha8e41c71__0[4U] = 0U;
        __Vtemp_ha8e41c71__0[5U] = 0U;
        __Vtemp_ha8e41c71__0[6U] = 0U;
        __Vtemp_ha8e41c71__0[7U] = 0U;
        __Vtemp_ha8e41c71__0[8U] = 0U;
        __Vtemp_ha8e41c71__0[9U] = 0U;
        __Vtemp_ha8e41c71__0[0xaU] = 0U;
        __Vtemp_ha8e41c71__0[0xbU] = 0U;
        __Vtemp_ha8e41c71__0[0xcU] = 0U;
        __Vtemp_ha8e41c71__0[0xdU] = 0U;
        __Vtemp_ha8e41c71__0[0xeU] = 0U;
        __Vtemp_ha8e41c71__0[0xfU] = 0U;
        __Vtemp_ha8e41c71__0[0x10U] = 0U;
        __Vtemp_ha8e41c71__0[0x11U] = 0U;
        __Vtemp_ha8e41c71__0[0x12U] = 0U;
        __Vtemp_ha8e41c71__0[0x13U] = 0U;
        __Vtemp_ha8e41c71__0[0x14U] = 0U;
        __Vtemp_ha8e41c71__0[0x15U] = 0U;
        __Vtemp_ha8e41c71__0[0x16U] = 0U;
        __Vtemp_ha8e41c71__0[0x17U] = 0U;
        __Vtemp_ha8e41c71__0[0x18U] = 0U;
        __Vtemp_ha8e41c71__0[0x19U] = 0U;
        __Vtemp_ha8e41c71__0[0x1aU] = 0U;
        __Vtemp_ha8e41c71__0[0x1bU] = 0U;
        __Vtemp_ha8e41c71__0[0x1cU] = 0U;
        __Vtemp_ha8e41c71__0[0x1dU] = 0U;
        __Vtemp_ha8e41c71__0[0x1eU] = 0U;
        __Vtemp_ha8e41c71__0[0x1fU] = 0U;
        __Vtemp_ha8e41c71__0[0x20U] = 0U;
        VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_hdb76b3c0__0, __Vtemp_ha8e41c71__0, vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_42);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0U] 
               & __Vtemp_hdb76b3c0__0[0U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[1U] 
               & __Vtemp_hdb76b3c0__0[1U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[2U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[2U] 
               & __Vtemp_hdb76b3c0__0[2U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[3U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[3U] 
               & __Vtemp_hdb76b3c0__0[3U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[4U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[4U] 
               & __Vtemp_hdb76b3c0__0[4U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[5U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[5U] 
               & __Vtemp_hdb76b3c0__0[5U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[6U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[6U] 
               & __Vtemp_hdb76b3c0__0[6U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[7U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[7U] 
               & __Vtemp_hdb76b3c0__0[7U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[8U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[8U] 
               & __Vtemp_hdb76b3c0__0[8U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[9U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[9U] 
               & __Vtemp_hdb76b3c0__0[9U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xaU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xaU] 
               & __Vtemp_hdb76b3c0__0[0xaU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xbU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xbU] 
               & __Vtemp_hdb76b3c0__0[0xbU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xcU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xcU] 
               & __Vtemp_hdb76b3c0__0[0xcU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xdU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xdU] 
               & __Vtemp_hdb76b3c0__0[0xdU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xeU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xeU] 
               & __Vtemp_hdb76b3c0__0[0xeU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xfU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0xfU] 
               & __Vtemp_hdb76b3c0__0[0xfU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x10U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x10U] 
               & __Vtemp_hdb76b3c0__0[0x10U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x11U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x11U] 
               & __Vtemp_hdb76b3c0__0[0x11U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x12U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x12U] 
               & __Vtemp_hdb76b3c0__0[0x12U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x13U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x13U] 
               & __Vtemp_hdb76b3c0__0[0x13U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x14U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x14U] 
               & __Vtemp_hdb76b3c0__0[0x14U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x15U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x15U] 
               & __Vtemp_hdb76b3c0__0[0x15U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x16U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x16U] 
               & __Vtemp_hdb76b3c0__0[0x16U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x17U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x17U] 
               & __Vtemp_hdb76b3c0__0[0x17U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x18U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x18U] 
               & __Vtemp_hdb76b3c0__0[0x18U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x19U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x19U] 
               & __Vtemp_hdb76b3c0__0[0x19U]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x1aU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1aU] 
               & __Vtemp_hdb76b3c0__0[0x1aU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x1bU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1bU] 
               & __Vtemp_hdb76b3c0__0[0x1bU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x1cU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1cU] 
               & __Vtemp_hdb76b3c0__0[0x1cU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x1dU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1dU] 
               & __Vtemp_hdb76b3c0__0[0x1dU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x1eU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1eU] 
               & __Vtemp_hdb76b3c0__0[0x1eU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x1fU] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x1fU] 
               & __Vtemp_hdb76b3c0__0[0x1fU]);
        vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0x20U] 
            = (VysyxSoCFull__ConstPool__CONST_hf1d99c76_0[0x20U] 
               & __Vtemp_hdb76b3c0__0[0x20U]);
        if (__PVT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) {
            vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43 
                = vlSelf->__PVT__monitor__DOT__d_first_1;
            vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6 
                = (0xfffU & ((IData)(0x1fU) << (IData)(vlSelf->auto_in_d_bits_size)));
            __Vdly__monitor__DOT__d_first_counter = 
                (7U & ((0U != (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter))
                        ? ((IData)(vlSelf->__PVT__monitor__DOT__d_first_counter) 
                           - (IData)(1U)) : ((IData)(vlSelf->__PVT__r_wins)
                                              ? (~ 
                                                 ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                                  >> 2U))
                                              : 0U)));
            __Vdly__monitor__DOT__d_first_counter_1 
                = (7U & ((IData)(vlSelf->__PVT__monitor__DOT__d_first_1)
                          ? ((IData)(vlSelf->__PVT__r_wins)
                              ? (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                    >> 2U)) : 0U) : 
                         ((IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_1) 
                          - (IData)(1U))));
            __Vdly__monitor__DOT__d_first_counter_2 
                = (7U & ((IData)(vlSelf->__PVT__monitor__DOT__d_first_2)
                          ? ((IData)(vlSelf->__PVT__r_wins)
                              ? (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk5__DOT___d_first_beats1_decode_T_6) 
                                    >> 2U)) : 0U) : 
                         ((IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_2) 
                          - (IData)(1U))));
            __Vdly__monitor__DOT__watchdog_1 = 0U;
        } else {
            vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43 = 0U;
            __Vdly__monitor__DOT__watchdog_1 = ((IData)(1U) 
                                                + vlSelf->__PVT__monitor__DOT__watchdog_1);
        }
        __Vtemp_hd2b6c582__2[0U] = 1U;
        __Vtemp_hd2b6c582__2[1U] = 0U;
        __Vtemp_hd2b6c582__2[2U] = 0U;
        __Vtemp_hd2b6c582__2[3U] = 0U;
        __Vtemp_h88366e99__2[0U] = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source;
        __Vtemp_h88366e99__2[1U] = 0U;
        __Vtemp_h88366e99__2[2U] = 0U;
        __Vtemp_h88366e99__2[3U] = 0U;
        VL_SHIFTL_WWW(128,128,128, __Vtemp_hd72e69bc__0, __Vtemp_hd2b6c582__2, __Vtemp_h88366e99__2);
        __Vtemp_hd2b6c582__3[0U] = 1U;
        __Vtemp_hd2b6c582__3[1U] = 0U;
        __Vtemp_hd2b6c582__3[2U] = 0U;
        __Vtemp_hd2b6c582__3[3U] = 0U;
        __Vtemp_hb6b3ff4d__2[0U] = vlSelf->auto_in_d_bits_source;
        __Vtemp_hb6b3ff4d__2[1U] = 0U;
        __Vtemp_hb6b3ff4d__2[2U] = 0U;
        __Vtemp_hb6b3ff4d__2[3U] = 0U;
        VL_SHIFTL_WWW(128,128,128, __Vtemp_h61d6301d__0, __Vtemp_hd2b6c582__3, __Vtemp_hb6b3ff4d__2);
        __Vdly__monitor__DOT__inflight[0U] = ((vlSelf->__PVT__monitor__DOT__inflight[0U] 
                                               | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                                                   ? 
                                                  __Vtemp_hd72e69bc__0[0U]
                                                   : 0U)) 
                                              & (~ 
                                                 ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                                                   ? 
                                                  __Vtemp_h61d6301d__0[0U]
                                                   : 0U)));
        __Vdly__monitor__DOT__inflight[1U] = ((vlSelf->__PVT__monitor__DOT__inflight[1U] 
                                               | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                                                   ? 
                                                  __Vtemp_hd72e69bc__0[1U]
                                                   : 0U)) 
                                              & (~ 
                                                 ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                                                   ? 
                                                  __Vtemp_h61d6301d__0[1U]
                                                   : 0U)));
        __Vdly__monitor__DOT__inflight[2U] = ((vlSelf->__PVT__monitor__DOT__inflight[2U] 
                                               | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                                                   ? 
                                                  __Vtemp_hd72e69bc__0[2U]
                                                   : 0U)) 
                                              & (~ 
                                                 ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                                                   ? 
                                                  __Vtemp_h61d6301d__0[2U]
                                                   : 0U)));
        __Vdly__monitor__DOT__inflight[3U] = ((vlSelf->__PVT__monitor__DOT__inflight[3U] 
                                               | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                                                   ? 
                                                  __Vtemp_hd72e69bc__0[3U]
                                                   : 0U)) 
                                              & (~ 
                                                 ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                                                   ? 
                                                  __Vtemp_h61d6301d__0[3U]
                                                   : 0U)));
        __Vdly__monitor__DOT__inflight_opcodes[0U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0U])));
        __Vdly__monitor__DOT__inflight_opcodes[1U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[1U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[1U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[1U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[1U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[1U])));
        __Vdly__monitor__DOT__inflight_opcodes[2U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[2U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[2U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[2U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[2U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[2U])));
        __Vdly__monitor__DOT__inflight_opcodes[3U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[3U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[3U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[3U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[3U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[3U])));
        __Vdly__monitor__DOT__inflight_opcodes[4U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[4U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[4U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[4U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[4U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[4U])));
        __Vdly__monitor__DOT__inflight_opcodes[5U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[5U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[5U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[5U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[5U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[5U])));
        __Vdly__monitor__DOT__inflight_opcodes[6U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[6U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[6U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[6U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[6U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[6U])));
        __Vdly__monitor__DOT__inflight_opcodes[7U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[7U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[7U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[7U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[7U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[7U])));
        __Vdly__monitor__DOT__inflight_opcodes[8U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[8U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[8U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[8U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[8U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[8U])));
        __Vdly__monitor__DOT__inflight_opcodes[9U] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[9U] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[9U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[9U])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[9U]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[9U])));
        __Vdly__monitor__DOT__inflight_opcodes[0xaU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xaU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xaU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xaU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xaU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xaU])));
        __Vdly__monitor__DOT__inflight_opcodes[0xbU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xbU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xbU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xbU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xbU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xbU])));
        __Vdly__monitor__DOT__inflight_opcodes[0xcU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xcU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xcU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xcU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xcU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xcU])));
        __Vdly__monitor__DOT__inflight_opcodes[0xdU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xdU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xdU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xdU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xdU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xdU])));
        __Vdly__monitor__DOT__inflight_opcodes[0xeU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xeU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xeU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xeU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xeU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xeU])));
        __Vdly__monitor__DOT__inflight_opcodes[0xfU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xfU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_opcodes_set_T_1[0xfU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xfU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_opcodes_clr_T_5[0xfU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xfU])));
        __Vdly__monitor__DOT__inflight_sizes[0U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0U])));
        __Vdly__monitor__DOT__inflight_sizes[1U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[1U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[1U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[1U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[1U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[1U])));
        __Vdly__monitor__DOT__inflight_sizes[2U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[2U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[2U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[2U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[2U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[2U])));
        __Vdly__monitor__DOT__inflight_sizes[3U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[3U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[3U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[3U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[3U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[3U])));
        __Vdly__monitor__DOT__inflight_sizes[4U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[4U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[4U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[4U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[4U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[4U])));
        __Vdly__monitor__DOT__inflight_sizes[5U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[5U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[5U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[5U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[5U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[5U])));
        __Vdly__monitor__DOT__inflight_sizes[6U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[6U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[6U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[6U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[6U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[6U])));
        __Vdly__monitor__DOT__inflight_sizes[7U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[7U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[7U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[7U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[7U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[7U])));
        __Vdly__monitor__DOT__inflight_sizes[8U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[8U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[8U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[8U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[8U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[8U])));
        __Vdly__monitor__DOT__inflight_sizes[9U] = 
            ((vlSelf->__PVT__monitor__DOT__inflight_sizes[9U] 
              | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                  ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[9U]
                  : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[9U])) 
             & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[9U]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[9U])));
        __Vdly__monitor__DOT__inflight_sizes[0xaU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0xaU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xaU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xaU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xaU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xaU])));
        __Vdly__monitor__DOT__inflight_sizes[0xbU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0xbU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xbU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xbU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xbU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xbU])));
        __Vdly__monitor__DOT__inflight_sizes[0xcU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0xcU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xcU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xcU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xcU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xcU])));
        __Vdly__monitor__DOT__inflight_sizes[0xdU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0xdU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xdU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xdU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xdU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xdU])));
        __Vdly__monitor__DOT__inflight_sizes[0xeU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0xeU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xeU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xeU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xeU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xeU])));
        __Vdly__monitor__DOT__inflight_sizes[0xfU] 
            = ((vlSelf->__PVT__monitor__DOT__inflight_sizes[0xfU] 
                | ((IData)(vlSelf->__PVT__monitor__DOT___GEN_1)
                    ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___a_sizes_set_T_1[0xfU]
                    : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xfU])) 
               & (~ ((IData)(vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___GEN_43)
                      ? vlSelf->__PVT__monitor__DOT__unnamedblk2__DOT__unnamedblk3__DOT___d_sizes_clr_T_5[0xfU]
                      : VysyxSoCFull__ConstPool__CONST_h93e1b771_0[0xfU])));
        __Vdly__monitor__DOT__watchdog = (((IData)(vlSelf->__PVT__monitor__DOT___a_first_T_1) 
                                           | (IData)(__PVT__monitor__DOT__unnamedblk2__DOT___d_first_T_2))
                                           ? 0U : ((IData)(1U) 
                                                   + vlSelf->__PVT__monitor__DOT__watchdog));
    }
    if (((IData)(__PVT__monitor__DOT__unnamedblk2__DOT___d_first_T_2) 
         & (~ (IData)((0U != (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter)))))) {
        vlSelf->__PVT__monitor__DOT__opcode_1 = vlSelf->__PVT__r_wins;
        vlSelf->__PVT__monitor__DOT__size_1 = vlSelf->auto_in_d_bits_size;
        vlSelf->__PVT__monitor__DOT__source_1 = vlSelf->auto_in_d_bits_source;
        vlSelf->__PVT__monitor__DOT__denied = vlSelf->auto_in_d_bits_denied;
    }
    vlSelf->__PVT__a_first = (0U == (IData)(vlSelf->__PVT__r_counter));
    vlSelf->__PVT___out_wvalid_T_3 = (1U & ((~ (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full)) 
                                            | (IData)(vlSelf->__PVT__doneAW)));
    vlSelf->auto_out_awburst = ((IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full)
                                 ? (3U & (IData)((vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                                  >> 0xcU)))
                                 : 1U);
    vlSelf->__PVT__monitor__DOT__a_first_counter = __Vdly__monitor__DOT__a_first_counter;
    vlSelf->__PVT__monitor__DOT__a_first_counter_1 
        = __Vdly__monitor__DOT__a_first_counter_1;
    vlSelf->__PVT__monitor__DOT__d_first_counter = __Vdly__monitor__DOT__d_first_counter;
    vlSelf->__PVT__monitor__DOT__inflight[0U] = __Vdly__monitor__DOT__inflight[0U];
    vlSelf->__PVT__monitor__DOT__inflight[1U] = __Vdly__monitor__DOT__inflight[1U];
    vlSelf->__PVT__monitor__DOT__inflight[2U] = __Vdly__monitor__DOT__inflight[2U];
    vlSelf->__PVT__monitor__DOT__inflight[3U] = __Vdly__monitor__DOT__inflight[3U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0U] 
        = __Vdly__monitor__DOT__inflight_opcodes[0U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[1U] 
        = __Vdly__monitor__DOT__inflight_opcodes[1U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[2U] 
        = __Vdly__monitor__DOT__inflight_opcodes[2U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[3U] 
        = __Vdly__monitor__DOT__inflight_opcodes[3U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[4U] 
        = __Vdly__monitor__DOT__inflight_opcodes[4U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[5U] 
        = __Vdly__monitor__DOT__inflight_opcodes[5U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[6U] 
        = __Vdly__monitor__DOT__inflight_opcodes[6U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[7U] 
        = __Vdly__monitor__DOT__inflight_opcodes[7U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[8U] 
        = __Vdly__monitor__DOT__inflight_opcodes[8U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[9U] 
        = __Vdly__monitor__DOT__inflight_opcodes[9U];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xaU] 
        = __Vdly__monitor__DOT__inflight_opcodes[0xaU];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xbU] 
        = __Vdly__monitor__DOT__inflight_opcodes[0xbU];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xcU] 
        = __Vdly__monitor__DOT__inflight_opcodes[0xcU];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xdU] 
        = __Vdly__monitor__DOT__inflight_opcodes[0xdU];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xeU] 
        = __Vdly__monitor__DOT__inflight_opcodes[0xeU];
    vlSelf->__PVT__monitor__DOT__inflight_opcodes[0xfU] 
        = __Vdly__monitor__DOT__inflight_opcodes[0xfU];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0U] 
        = __Vdly__monitor__DOT__inflight_sizes[0U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[1U] 
        = __Vdly__monitor__DOT__inflight_sizes[1U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[2U] 
        = __Vdly__monitor__DOT__inflight_sizes[2U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[3U] 
        = __Vdly__monitor__DOT__inflight_sizes[3U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[4U] 
        = __Vdly__monitor__DOT__inflight_sizes[4U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[5U] 
        = __Vdly__monitor__DOT__inflight_sizes[5U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[6U] 
        = __Vdly__monitor__DOT__inflight_sizes[6U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[7U] 
        = __Vdly__monitor__DOT__inflight_sizes[7U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[8U] 
        = __Vdly__monitor__DOT__inflight_sizes[8U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[9U] 
        = __Vdly__monitor__DOT__inflight_sizes[9U];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0xaU] 
        = __Vdly__monitor__DOT__inflight_sizes[0xaU];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0xbU] 
        = __Vdly__monitor__DOT__inflight_sizes[0xbU];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0xcU] 
        = __Vdly__monitor__DOT__inflight_sizes[0xcU];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0xdU] 
        = __Vdly__monitor__DOT__inflight_sizes[0xdU];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0xeU] 
        = __Vdly__monitor__DOT__inflight_sizes[0xeU];
    vlSelf->__PVT__monitor__DOT__inflight_sizes[0xfU] 
        = __Vdly__monitor__DOT__inflight_sizes[0xfU];
    vlSelf->__PVT__monitor__DOT__watchdog = __Vdly__monitor__DOT__watchdog;
    vlSelf->__PVT__monitor__DOT__watchdog_1 = __Vdly__monitor__DOT__watchdog_1;
    vlSelf->__PVT__monitor__DOT__d_first_counter_2 
        = __Vdly__monitor__DOT__d_first_counter_2;
    vlSelf->__PVT__monitor__DOT__d_first_counter_1 
        = __Vdly__monitor__DOT__d_first_counter_1;
    vlSelf->__PVT__monitor__DOT__a_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_2 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_2));
    vlSelf->__PVT__monitor__DOT__d_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_1));
}
