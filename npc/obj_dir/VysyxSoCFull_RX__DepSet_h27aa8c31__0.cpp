// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_AsyncQueueSource_UInt32.h"
#include "VysyxSoCFull_RX.h"
#include "VysyxSoCFull__Syms.h"

VL_INLINE_OPT void VysyxSoCFull_RX___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__0(VysyxSoCFull_RX* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_RX___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__0\n"); );
    // Init
    IData/*19:0*/ __Vdly__rx_a;
    __Vdly__rx_a = 0;
    CData/*4:0*/ __Vdly__first_count;
    __Vdly__first_count = 0;
    IData/*19:0*/ __Vdly__tx_a;
    __Vdly__tx_a = 0;
    IData/*19:0*/ __Vdly__tx_b;
    __Vdly__tx_b = 0;
    IData/*19:0*/ __Vdly__tx_c;
    __Vdly__tx_c = 0;
    IData/*19:0*/ __Vdly__tx_d;
    __Vdly__tx_d = 0;
    IData/*19:0*/ __Vdly__tx_e;
    __Vdly__tx_e = 0;
    IData/*19:0*/ __Vdly__rx_b;
    __Vdly__rx_b = 0;
    IData/*19:0*/ __Vdly__rx_d;
    __Vdly__rx_d = 0;
    IData/*19:0*/ __Vdly__rx_c;
    __Vdly__rx_c = 0;
    IData/*19:0*/ __Vdly__rx_e;
    __Vdly__rx_e = 0;
    CData/*4:0*/ __Vdly__hqa__DOT__fq__DOT__enq_ptr;
    __Vdly__hqa__DOT__fq__DOT__enq_ptr = 0;
    CData/*4:0*/ __Vdly__hqb__DOT__fq__DOT__enq_ptr;
    __Vdly__hqb__DOT__fq__DOT__enq_ptr = 0;
    CData/*4:0*/ __Vdly__hqc__DOT__fq__DOT__enq_ptr;
    __Vdly__hqc__DOT__fq__DOT__enq_ptr = 0;
    CData/*4:0*/ __Vdly__hqd__DOT__fq__DOT__enq_ptr;
    __Vdly__hqd__DOT__fq__DOT__enq_ptr = 0;
    CData/*4:0*/ __Vdly__hqe__DOT__fq__DOT__enq_ptr;
    __Vdly__hqe__DOT__fq__DOT__enq_ptr = 0;
    // Body
    __Vdly__rx_e = vlSelf->__PVT__rx_e;
    __Vdly__rx_c = vlSelf->__PVT__rx_c;
    __Vdly__rx_d = vlSelf->__PVT__rx_d;
    __Vdly__rx_b = vlSelf->__PVT__rx_b;
    __Vdly__rx_a = vlSelf->__PVT__rx_a;
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__hqa_io_enq_valid)) 
                                 | (~ (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__full)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13035: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.rx: Assertion failed at RX.scala:56\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13035, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13037: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.rx\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13037, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__hqb_io_enq_valid)) 
                                 | (~ (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__full)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13041: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.rx: Assertion failed at RX.scala:56\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13041, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13043: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.rx\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13043, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__hqc_io_enq_valid)) 
                                 | (~ (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__full)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13047: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.rx: Assertion failed at RX.scala:56\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13047, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13049: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.rx\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13049, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__hqd_io_enq_valid)) 
                                 | (~ (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__full)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13053: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.rx: Assertion failed at RX.scala:56\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13053, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13055: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.rx\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13055, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__hqe_io_enq_valid)) 
                                 | (~ (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__full)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13059: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.rx: Assertion failed at RX.scala:56\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13059, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13061: Assertion failed in %NysyxSoCFull.asic.chipMaster.chiplink.rx\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13061, "");
    }
    vlSelf->__Vdly__hqe__DOT__fq__DOT__deq_ptr = vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr;
    __Vdly__hqe__DOT__fq__DOT__enq_ptr = vlSelf->__PVT__hqe__DOT__fq__DOT__enq_ptr;
    vlSelf->__Vdly__hqd__DOT__fq__DOT__deq_ptr = vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr;
    __Vdly__hqd__DOT__fq__DOT__enq_ptr = vlSelf->__PVT__hqd__DOT__fq__DOT__enq_ptr;
    vlSelf->__Vdly__hqc__DOT__fq__DOT__deq_ptr = vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr;
    __Vdly__hqc__DOT__fq__DOT__enq_ptr = vlSelf->__PVT__hqc__DOT__fq__DOT__enq_ptr;
    vlSelf->__Vdly__hqb__DOT__fq__DOT__deq_ptr = vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr;
    __Vdly__hqb__DOT__fq__DOT__enq_ptr = vlSelf->__PVT__hqb__DOT__fq__DOT__enq_ptr;
    vlSelf->__Vdly__hqa__DOT__fq__DOT__deq_ptr = vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr;
    __Vdly__hqa__DOT__fq__DOT__enq_ptr = vlSelf->__PVT__hqa__DOT__fq__DOT__enq_ptr;
    vlSelf->__Vdlyvset__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__hqe__DOT__io_deq_q__DOT__full = vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__full;
    vlSelf->__Vdly__hqd__DOT__io_deq_q__DOT__full = vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__full;
    vlSelf->__Vdly__hqc__DOT__io_deq_q__DOT__full = vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__full;
    vlSelf->__Vdly__hqb__DOT__io_deq_q__DOT__full = vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__full;
    vlSelf->__Vdly__hqa__DOT__io_deq_q__DOT__full = vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__full;
    __Vdly__tx_e = vlSelf->__PVT__tx_e;
    __Vdly__tx_d = vlSelf->__PVT__tx_d;
    __Vdly__tx_c = vlSelf->__PVT__tx_c;
    __Vdly__tx_b = vlSelf->__PVT__tx_b;
    __Vdly__tx_a = vlSelf->__PVT__tx_a;
    __Vdly__first_count = vlSelf->__PVT__first_count;
    if (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        __Vdly__rx_e = 0x20U;
        __Vdly__rx_c = 0x20U;
        __Vdly__rx_d = 0x20U;
        __Vdly__rx_b = 0x20U;
        __Vdly__rx_a = 0x20U;
        vlSelf->__Vdly__hqe__DOT__fq__DOT__deq_ptr = 0U;
        __Vdly__hqe__DOT__fq__DOT__enq_ptr = 0U;
        vlSelf->__Vdly__hqd__DOT__fq__DOT__deq_ptr = 0U;
        __Vdly__hqd__DOT__fq__DOT__enq_ptr = 0U;
        vlSelf->__Vdly__hqc__DOT__fq__DOT__deq_ptr = 0U;
        __Vdly__hqc__DOT__fq__DOT__enq_ptr = 0U;
        vlSelf->__Vdly__hqb__DOT__fq__DOT__deq_ptr = 0U;
        __Vdly__hqb__DOT__fq__DOT__enq_ptr = 0U;
        vlSelf->__Vdly__hqa__DOT__fq__DOT__deq_ptr = 0U;
        __Vdly__hqa__DOT__fq__DOT__enq_ptr = 0U;
        vlSelf->__PVT__hqe__DOT__fq__DOT__maybe_full = 0U;
        vlSelf->__PVT__hqd__DOT__fq__DOT__maybe_full = 0U;
        vlSelf->__PVT__hqc__DOT__fq__DOT__maybe_full = 0U;
        vlSelf->__PVT__hqb__DOT__fq__DOT__maybe_full = 0U;
        vlSelf->__PVT__hqa__DOT__fq__DOT__maybe_full = 0U;
        __Vdly__first_count = 0U;
        __Vdly__tx_a = 0U;
        __Vdly__tx_b = 0U;
        __Vdly__tx_c = 0U;
        __Vdly__tx_d = 0U;
        __Vdly__tx_e = 0U;
    } else {
        vlSelf->__PVT__unnamedblk1__DOT___rxInc_e_T 
            = ((IData)(vlSelf->__PVT__io_e_source->__PVT__io_enq_ready) 
               & (IData)(vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__full));
        vlSelf->__PVT__unnamedblk1__DOT__rx_z_4 = (0x1fffffU 
                                                   & (vlSelf->__PVT__rx_e 
                                                      + (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_e_T)));
        vlSelf->__PVT__unnamedblk1__DOT___rxInc_c_T 
            = ((IData)(vlSelf->__PVT__io_c_source->__PVT__io_enq_ready) 
               & (IData)(vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__full));
        vlSelf->__PVT__unnamedblk1__DOT__rx_z_2 = (0x1fffffU 
                                                   & (vlSelf->__PVT__rx_c 
                                                      + (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_c_T)));
        vlSelf->__PVT__unnamedblk1__DOT___rxInc_d_T 
            = ((IData)(vlSelf->__PVT__io_d_source->__PVT__io_enq_ready) 
               & (IData)(vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__full));
        vlSelf->__PVT__unnamedblk1__DOT__rx_z_3 = (0x1fffffU 
                                                   & (vlSelf->__PVT__rx_d 
                                                      + (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_d_T)));
        vlSelf->__PVT__unnamedblk1__DOT___rxInc_bT 
            = ((IData)(vlSelf->__PVT__io_bsource->__PVT__io_enq_ready) 
               & (IData)(vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__full));
        vlSelf->__PVT__unnamedblk1__DOT__rx_z_1 = (0x1fffffU 
                                                   & (vlSelf->__PVT__rx_b 
                                                      + (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_bT)));
        vlSelf->__PVT__unnamedblk1__DOT___rxInc_a_T 
            = ((IData)(vlSelf->__PVT__io_a_source->__PVT__io_enq_ready) 
               & (IData)(vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__full));
        vlSelf->__PVT__unnamedblk1__DOT__rx_z = (0x1fffffU 
                                                 & (vlSelf->__PVT__rx_a 
                                                    + (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_a_T)));
        if (vlSelf->__PVT__io_rxc_source__DOT__io_enq_ready_0) {
            __Vdly__rx_e = (0xfffffU & (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_e_T));
            __Vdly__rx_c = (0xfffffU & (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_c_T));
            __Vdly__rx_d = (0xfffffU & (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_d_T));
            __Vdly__rx_b = (0xfffffU & (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_bT));
            __Vdly__rx_a = (0xfffffU & (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_a_T));
        } else {
            __Vdly__rx_e = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__rx_z_4)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__rx_z_4));
            __Vdly__rx_c = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__rx_z_2)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__rx_z_2));
            __Vdly__rx_d = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__rx_z_3)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__rx_z_3));
            __Vdly__rx_b = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__rx_z_1)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__rx_z_1));
            __Vdly__rx_a = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__rx_z)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__rx_z));
        }
        if (vlSelf->__PVT__hqe__DOT__fq__DOT__do_deq) {
            vlSelf->__Vdly__hqe__DOT__fq__DOT__deq_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr)));
        }
        if (vlSelf->__PVT__hqe__DOT__fq__DOT__do_enq) {
            __Vdly__hqe__DOT__fq__DOT__enq_ptr = (0x1fU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__enq_ptr)));
        }
        if (vlSelf->__PVT__hqd__DOT__fq__DOT__do_deq) {
            vlSelf->__Vdly__hqd__DOT__fq__DOT__deq_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr)));
        }
        if (vlSelf->__PVT__hqd__DOT__fq__DOT__do_enq) {
            __Vdly__hqd__DOT__fq__DOT__enq_ptr = (0x1fU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__enq_ptr)));
        }
        if (vlSelf->__PVT__hqc__DOT__fq__DOT__do_deq) {
            vlSelf->__Vdly__hqc__DOT__fq__DOT__deq_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr)));
        }
        if (vlSelf->__PVT__hqc__DOT__fq__DOT__do_enq) {
            __Vdly__hqc__DOT__fq__DOT__enq_ptr = (0x1fU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__enq_ptr)));
        }
        if (vlSelf->__PVT__hqb__DOT__fq__DOT__do_deq) {
            vlSelf->__Vdly__hqb__DOT__fq__DOT__deq_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr)));
        }
        if (vlSelf->__PVT__hqb__DOT__fq__DOT__do_enq) {
            __Vdly__hqb__DOT__fq__DOT__enq_ptr = (0x1fU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__enq_ptr)));
        }
        if (vlSelf->__PVT__hqa__DOT__fq__DOT__do_deq) {
            vlSelf->__Vdly__hqa__DOT__fq__DOT__deq_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr)));
        }
        if (vlSelf->__PVT__hqa__DOT__fq__DOT__do_enq) {
            __Vdly__hqa__DOT__fq__DOT__enq_ptr = (0x1fU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__enq_ptr)));
        }
        if (((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__do_deq))) {
            vlSelf->__PVT__hqe__DOT__fq__DOT__maybe_full 
                = vlSelf->__PVT__hqe__DOT__fq__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__do_deq))) {
            vlSelf->__PVT__hqd__DOT__fq__DOT__maybe_full 
                = vlSelf->__PVT__hqd__DOT__fq__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__do_deq))) {
            vlSelf->__PVT__hqc__DOT__fq__DOT__maybe_full 
                = vlSelf->__PVT__hqc__DOT__fq__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__do_deq))) {
            vlSelf->__PVT__hqb__DOT__fq__DOT__maybe_full 
                = vlSelf->__PVT__hqb__DOT__fq__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__do_deq))) {
            vlSelf->__PVT__hqa__DOT__fq__DOT__maybe_full 
                = vlSelf->__PVT__hqa__DOT__fq__DOT__do_enq;
        }
        if (vlSelf->__PVT__b2c_send) {
            vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___first_beats_beats_T_1 
                = (0xffU & ((IData)(1U) << (7U & (vlSelf->__PVT__b2c_data 
                                                  >> 9U))));
            vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT__first_beats_beats 
                = ((0x1eU & ((IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___first_beats_beats_T_1) 
                             >> 2U)) | (3U > (0xfU 
                                              & (vlSelf->__PVT__b2c_data 
                                                 >> 9U))));
            vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___GEN 
                = ((1U == (7U & (vlSelf->__PVT__b2c_data 
                                 >> 3U))) ? (((6U == 
                                               (7U 
                                                & (vlSelf->__PVT__b2c_data 
                                                   >> 9U))) 
                                              << 1U) 
                                             | (6U 
                                                > (0xfU 
                                                   & (vlSelf->__PVT__b2c_data 
                                                      >> 9U))))
                    : 0U);
            vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___first_beats_a_T_5 
                = (0x1fU & ((IData)(2U) + (((0x20U 
                                             & vlSelf->__PVT__b2c_data)
                                             ? 0U : (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT__first_beats_beats)) 
                                           + (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___GEN))));
            vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_0 
                = (((QData)((IData)((0x3ffU & (((IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___first_beats_a_T_5) 
                                                << 5U) 
                                               | (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___first_beats_a_T_5))))) 
                    << 0x1eU) | (QData)((IData)(((0xf8000U 
                                                  & ((((8U 
                                                        & vlSelf->__PVT__b2c_data)
                                                        ? (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT__first_beats_beats)
                                                        : 0U) 
                                                      + 
                                                      ((4U 
                                                        == 
                                                        (7U 
                                                         & (vlSelf->__PVT__b2c_data 
                                                            >> 3U))) 
                                                       | (5U 
                                                          == 
                                                          (7U 
                                                           & (vlSelf->__PVT__b2c_data 
                                                              >> 3U))))) 
                                                     << 0xfU)) 
                                                 | ((0x7c00U 
                                                     & (((IData)(2U) 
                                                         + 
                                                         ((8U 
                                                           & vlSelf->__PVT__b2c_data)
                                                           ? (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT__first_beats_beats)
                                                           : 0U)) 
                                                        << 0xaU)) 
                                                    | ((0x3e0U 
                                                        & (((IData)(2U) 
                                                            + 
                                                            (((0x20U 
                                                               & vlSelf->__PVT__b2c_data)
                                                               ? 0U
                                                               : (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT__first_beats_beats)) 
                                                             + (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___GEN))) 
                                                           << 5U)) 
                                                       | (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___first_beats_a_T_5)))))));
            __Vdly__first_count = (0x1fU & ((IData)(vlSelf->__PVT__first)
                                             ? ((0x27U 
                                                 >= 
                                                 (0x3fU 
                                                  & ((IData)(5U) 
                                                     * 
                                                     (7U 
                                                      & vlSelf->__PVT__b2c_data))))
                                                 ? (IData)(
                                                           (vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_0 
                                                            >> 
                                                            (0x3fU 
                                                             & ((IData)(5U) 
                                                                * 
                                                                (7U 
                                                                 & vlSelf->__PVT__b2c_data)))))
                                                 : 0U)
                                             : ((IData)(vlSelf->__PVT__first_count) 
                                                - (IData)(1U))));
        }
        vlSelf->__PVT__unnamedblk1__DOT___txInc_T_1 
            = (7U & ((IData)(vlSelf->__PVT__b2c_send) 
                     & (((IData)(1U) << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                        >> 5U)));
        vlSelf->__PVT__unnamedblk1__DOT___txInc_out_a_T_3 
            = ((IData)(1U) << (0x1fU & (vlSelf->__PVT__b2c_data 
                                        >> 7U)));
        vlSelf->__PVT__unnamedblk1__DOT___txInc_out_bT_3 
            = ((IData)(1U) << (0x1fU & (vlSelf->__PVT__b2c_data 
                                        >> 0xcU)));
        vlSelf->__PVT__unnamedblk1__DOT___txInc_out_c_T_3 
            = ((IData)(1U) << (0x1fU & (vlSelf->__PVT__b2c_data 
                                        >> 0x11U)));
        vlSelf->__PVT__unnamedblk1__DOT___txInc_out_d_T_3 
            = ((IData)(1U) << (0x1fU & (vlSelf->__PVT__b2c_data 
                                        >> 0x16U)));
        vlSelf->__PVT__unnamedblk1__DOT___txInc_out_e_T_3 
            = ((IData)(1U) << (vlSelf->__PVT__b2c_data 
                               >> 0x1bU));
        if (vlSelf->__PVT__unnamedblk1__DOT___txInc_T_1) {
            vlSelf->__PVT__unnamedblk1__DOT__txInc_a 
                = ((0x14U < (0x1fU & (vlSelf->__PVT__b2c_data 
                                      >> 7U))) ? 0xfffffU
                    : (0xfffffU & (vlSelf->__PVT__unnamedblk1__DOT___txInc_out_a_T_3 
                                   >> 1U)));
            vlSelf->__PVT__unnamedblk1__DOT__txInc_b 
                = ((0x14U < (0x1fU & (vlSelf->__PVT__b2c_data 
                                      >> 0xcU))) ? 0xfffffU
                    : (0xfffffU & (vlSelf->__PVT__unnamedblk1__DOT___txInc_out_bT_3 
                                   >> 1U)));
            vlSelf->__PVT__unnamedblk1__DOT__txInc_c 
                = ((0x14U < (0x1fU & (vlSelf->__PVT__b2c_data 
                                      >> 0x11U))) ? 0xfffffU
                    : (0xfffffU & (vlSelf->__PVT__unnamedblk1__DOT___txInc_out_c_T_3 
                                   >> 1U)));
            vlSelf->__PVT__unnamedblk1__DOT__txInc_d 
                = ((0x14U < (0x1fU & (vlSelf->__PVT__b2c_data 
                                      >> 0x16U))) ? 0xfffffU
                    : (0xfffffU & (vlSelf->__PVT__unnamedblk1__DOT___txInc_out_d_T_3 
                                   >> 1U)));
            vlSelf->__PVT__unnamedblk1__DOT__txInc_e 
                = ((0x14U < (vlSelf->__PVT__b2c_data 
                             >> 0x1bU)) ? 0xfffffU : 
                   (0xfffffU & (vlSelf->__PVT__unnamedblk1__DOT___txInc_out_e_T_3 
                                >> 1U)));
        } else {
            vlSelf->__PVT__unnamedblk1__DOT__txInc_a = 0U;
            vlSelf->__PVT__unnamedblk1__DOT__txInc_b = 0U;
            vlSelf->__PVT__unnamedblk1__DOT__txInc_c = 0U;
            vlSelf->__PVT__unnamedblk1__DOT__txInc_d = 0U;
            vlSelf->__PVT__unnamedblk1__DOT__txInc_e = 0U;
        }
        vlSelf->__PVT__unnamedblk1__DOT__tx_z = (0x1fffffU 
                                                 & (vlSelf->__PVT__tx_a 
                                                    + vlSelf->__PVT__unnamedblk1__DOT__txInc_a));
        vlSelf->__PVT__unnamedblk1__DOT__tx_z_1 = (0x1fffffU 
                                                   & (vlSelf->__PVT__tx_b 
                                                      + vlSelf->__PVT__unnamedblk1__DOT__txInc_b));
        vlSelf->__PVT__unnamedblk1__DOT__tx_z_2 = (0x1fffffU 
                                                   & (vlSelf->__PVT__tx_c 
                                                      + vlSelf->__PVT__unnamedblk1__DOT__txInc_c));
        vlSelf->__PVT__unnamedblk1__DOT__tx_z_3 = (0x1fffffU 
                                                   & (vlSelf->__PVT__tx_d 
                                                      + vlSelf->__PVT__unnamedblk1__DOT__txInc_d));
        vlSelf->__PVT__unnamedblk1__DOT__tx_z_4 = (0x1fffffU 
                                                   & (vlSelf->__PVT__tx_e 
                                                      + vlSelf->__PVT__unnamedblk1__DOT__txInc_e));
        if (vlSelf->__PVT__io_txc_source__DOT__io_enq_ready_0) {
            __Vdly__tx_a = (0xfffffU & vlSelf->__PVT__unnamedblk1__DOT__txInc_a);
            __Vdly__tx_b = (0xfffffU & vlSelf->__PVT__unnamedblk1__DOT__txInc_b);
            __Vdly__tx_c = (0xfffffU & vlSelf->__PVT__unnamedblk1__DOT__txInc_c);
            __Vdly__tx_d = (0xfffffU & vlSelf->__PVT__unnamedblk1__DOT__txInc_d);
            __Vdly__tx_e = (0xfffffU & vlSelf->__PVT__unnamedblk1__DOT__txInc_e);
        } else {
            __Vdly__tx_a = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__tx_z)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__tx_z));
            __Vdly__tx_b = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__tx_z_1)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__tx_z_1));
            __Vdly__tx_c = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__tx_z_2)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__tx_z_2));
            __Vdly__tx_d = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__tx_z_3)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__tx_z_3));
            __Vdly__tx_e = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__tx_z_4)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__tx_z_4));
        }
    }
    if (vlSelf->__PVT__hqe__DOT__fq__DOT__do_enq) {
        vlSelf->__Vdlyvval__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__b2c_data;
        vlSelf->__Vdlyvset__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__hqe__DOT__fq__DOT__enq_ptr;
    }
    if (vlSelf->__PVT__hqd__DOT__fq__DOT__do_enq) {
        vlSelf->__Vdlyvval__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__b2c_data;
        vlSelf->__Vdlyvset__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__hqd__DOT__fq__DOT__enq_ptr;
    }
    if (vlSelf->__PVT__hqc__DOT__fq__DOT__do_enq) {
        vlSelf->__Vdlyvval__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__b2c_data;
        vlSelf->__Vdlyvset__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__hqc__DOT__fq__DOT__enq_ptr;
    }
    if (vlSelf->__PVT__hqb__DOT__fq__DOT__do_enq) {
        vlSelf->__Vdlyvval__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__b2c_data;
        vlSelf->__Vdlyvset__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__hqb__DOT__fq__DOT__enq_ptr;
    }
    if (vlSelf->__PVT__hqa__DOT__fq__DOT__do_enq) {
        vlSelf->__Vdlyvval__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__b2c_data;
        vlSelf->__Vdlyvset__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__hqa__DOT__fq__DOT__enq_ptr;
    }
    vlSelf->__PVT__hqe__DOT__fq__DOT__ram_out_valid 
        = vlSelf->__PVT__hqe__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqd__DOT__fq__DOT__ram_out_valid 
        = vlSelf->__PVT__hqd__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqc__DOT__fq__DOT__ram_out_valid 
        = vlSelf->__PVT__hqc__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqb__DOT__fq__DOT__ram_out_valid 
        = vlSelf->__PVT__hqb__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqa__DOT__fq__DOT__ram_out_valid 
        = vlSelf->__PVT__hqa__DOT__fq__DOT__ren;
    if (vlSelf->__PVT__formatValid) {
        vlSelf->__PVT__format_r = (7U & vlSelf->__PVT__b2c_data);
    }
    if (vlSelf->__PVT__io_rxc_source__DOT__io_enq_ready_0) {
        vlSelf->__PVT__io_rxc_source__DOT__mem_0_a 
            = vlSelf->__PVT__rx_a;
        vlSelf->__PVT__io_rxc_source__DOT__mem_0_b 
            = vlSelf->__PVT__rx_b;
        vlSelf->__PVT__io_rxc_source__DOT__mem_0_c 
            = vlSelf->__PVT__rx_c;
        vlSelf->__PVT__io_rxc_source__DOT__mem_0_d 
            = vlSelf->__PVT__rx_d;
        vlSelf->__PVT__io_rxc_source__DOT__mem_0_e 
            = vlSelf->__PVT__rx_e;
    }
    if (vlSelf->__PVT__io_txc_source__DOT__io_enq_ready_0) {
        vlSelf->__PVT__io_txc_source__DOT__mem_0_a 
            = vlSelf->__PVT__tx_a;
        vlSelf->__PVT__io_txc_source__DOT__mem_0_b 
            = vlSelf->__PVT__tx_b;
        vlSelf->__PVT__io_txc_source__DOT__mem_0_c 
            = vlSelf->__PVT__tx_c;
        vlSelf->__PVT__io_txc_source__DOT__mem_0_d 
            = vlSelf->__PVT__tx_d;
        vlSelf->__PVT__io_txc_source__DOT__mem_0_e 
            = vlSelf->__PVT__tx_e;
    }
    vlSelf->__PVT__hqe__DOT__fq__DOT__enq_ptr = __Vdly__hqe__DOT__fq__DOT__enq_ptr;
    vlSelf->__PVT__hqd__DOT__fq__DOT__enq_ptr = __Vdly__hqd__DOT__fq__DOT__enq_ptr;
    vlSelf->__PVT__hqc__DOT__fq__DOT__enq_ptr = __Vdly__hqc__DOT__fq__DOT__enq_ptr;
    vlSelf->__PVT__hqb__DOT__fq__DOT__enq_ptr = __Vdly__hqb__DOT__fq__DOT__enq_ptr;
    vlSelf->__PVT__hqa__DOT__fq__DOT__enq_ptr = __Vdly__hqa__DOT__fq__DOT__enq_ptr;
    vlSelf->__PVT__first_count = __Vdly__first_count;
    vlSelf->__PVT__rx_a = __Vdly__rx_a;
    vlSelf->__PVT__rx_b = __Vdly__rx_b;
    vlSelf->__PVT__rx_c = __Vdly__rx_c;
    vlSelf->__PVT__rx_d = __Vdly__rx_d;
    vlSelf->__PVT__rx_e = __Vdly__rx_e;
    vlSelf->__PVT__tx_a = __Vdly__tx_a;
    vlSelf->__PVT__tx_b = __Vdly__tx_b;
    vlSelf->__PVT__tx_c = __Vdly__tx_c;
    vlSelf->__PVT__tx_d = __Vdly__tx_d;
    vlSelf->__PVT__tx_e = __Vdly__tx_e;
    vlSelf->__PVT__first = (0U == (IData)(vlSelf->__PVT__first_count));
    vlSelf->__PVT__b2c_send = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                               & (IData)(vlSelf->__PVT__b2c_send_REG));
    vlSelf->__PVT__formatValid = ((IData)(vlSelf->__PVT__b2c_send) 
                                  & (0U == (IData)(vlSelf->__PVT__first_count)));
    vlSelf->__PVT__b2c_send_REG = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__tx.__PVT__io_c2b_send_REG_1;
}

VL_INLINE_OPT void VysyxSoCFull_RX___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__1(VysyxSoCFull_RX* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_RX___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__1\n"); );
    // Body
    vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq 
        = ((IData)(vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__io_enq_ready_0) 
           & (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__io_deq_valid_0));
    if (vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__ram 
            = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__empty)
                ? vlSelf->__PVT__b2c_data : ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ram_ext__DOT___R0_en_d0)
                                              ? vlSelf->__PVT__hqe__DOT__fq__DOT__ram_ext__DOT__Memory
                                             [vlSelf->__PVT__hqe__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0]
                                              : 0U));
    }
    vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq 
        = ((IData)(vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__io_enq_ready_0) 
           & (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__io_deq_valid_0));
    if (vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__ram 
            = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__empty)
                ? vlSelf->__PVT__b2c_data : ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ram_ext__DOT___R0_en_d0)
                                              ? vlSelf->__PVT__hqb__DOT__fq__DOT__ram_ext__DOT__Memory
                                             [vlSelf->__PVT__hqb__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0]
                                              : 0U));
    }
    vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq 
        = ((IData)(vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__io_enq_ready_0) 
           & (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__io_deq_valid_0));
    if (vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__ram 
            = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__empty)
                ? vlSelf->__PVT__b2c_data : ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ram_ext__DOT___R0_en_d0)
                                              ? vlSelf->__PVT__hqc__DOT__fq__DOT__ram_ext__DOT__Memory
                                             [vlSelf->__PVT__hqc__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0]
                                              : 0U));
    }
    vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq 
        = ((IData)(vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__io_enq_ready_0) 
           & (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__io_deq_valid_0));
    if (vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__ram 
            = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__empty)
                ? vlSelf->__PVT__b2c_data : ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ram_ext__DOT___R0_en_d0)
                                              ? vlSelf->__PVT__hqd__DOT__fq__DOT__ram_ext__DOT__Memory
                                             [vlSelf->__PVT__hqd__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0]
                                              : 0U));
    }
    vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq 
        = ((IData)(vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__io_enq_ready_0) 
           & (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__io_deq_valid_0));
    if (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        vlSelf->__Vdly__hqe__DOT__io_deq_q__DOT__full = 0U;
        vlSelf->__Vdly__hqb__DOT__io_deq_q__DOT__full = 0U;
        vlSelf->__Vdly__hqc__DOT__io_deq_q__DOT__full = 0U;
        vlSelf->__Vdly__hqd__DOT__io_deq_q__DOT__full = 0U;
        vlSelf->__Vdly__hqa__DOT__io_deq_q__DOT__full = 0U;
    } else {
        if (((IData)(vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) 
             != ((IData)(vlSelf->__PVT__io_e_source->__PVT__io_enq_ready) 
                 & (IData)(vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__full)))) {
            vlSelf->__Vdly__hqe__DOT__io_deq_q__DOT__full 
                = vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) 
             != ((IData)(vlSelf->__PVT__io_bsource->__PVT__io_enq_ready) 
                 & (IData)(vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__full)))) {
            vlSelf->__Vdly__hqb__DOT__io_deq_q__DOT__full 
                = vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) 
             != ((IData)(vlSelf->__PVT__io_c_source->__PVT__io_enq_ready) 
                 & (IData)(vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__full)))) {
            vlSelf->__Vdly__hqc__DOT__io_deq_q__DOT__full 
                = vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) 
             != ((IData)(vlSelf->__PVT__io_d_source->__PVT__io_enq_ready) 
                 & (IData)(vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__full)))) {
            vlSelf->__Vdly__hqd__DOT__io_deq_q__DOT__full 
                = vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) 
             != ((IData)(vlSelf->__PVT__io_a_source->__PVT__io_enq_ready) 
                 & (IData)(vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__full)))) {
            vlSelf->__Vdly__hqa__DOT__io_deq_q__DOT__full 
                = vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq;
        }
    }
    if (vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__ram 
            = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__empty)
                ? vlSelf->__PVT__b2c_data : ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ram_ext__DOT___R0_en_d0)
                                              ? vlSelf->__PVT__hqa__DOT__fq__DOT__ram_ext__DOT__Memory
                                             [vlSelf->__PVT__hqa__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0]
                                              : 0U));
    }
    if (vlSelf->__Vdlyvset__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__hqe__DOT__fq__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0] 
            = vlSelf->__Vdlyvval__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__full = vlSelf->__Vdly__hqe__DOT__io_deq_q__DOT__full;
    if (vlSelf->__Vdlyvset__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__hqb__DOT__fq__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0] 
            = vlSelf->__Vdlyvval__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__full = vlSelf->__Vdly__hqb__DOT__io_deq_q__DOT__full;
    if (vlSelf->__Vdlyvset__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__hqc__DOT__fq__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0] 
            = vlSelf->__Vdlyvval__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__full = vlSelf->__Vdly__hqc__DOT__io_deq_q__DOT__full;
    if (vlSelf->__Vdlyvset__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__hqd__DOT__fq__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0] 
            = vlSelf->__Vdlyvval__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__full = vlSelf->__Vdly__hqd__DOT__io_deq_q__DOT__full;
    if (vlSelf->__Vdlyvset__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__hqa__DOT__fq__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0] 
            = vlSelf->__Vdlyvval__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__full = vlSelf->__Vdly__hqa__DOT__io_deq_q__DOT__full;
    vlSelf->__PVT__hqe__DOT__fq__DOT__ram_ext__DOT___R0_en_d0 
        = vlSelf->__PVT__hqe__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqe__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0 
        = (0x1fU & ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__io_deq_valid_0)
                     ? (((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__do_deq) 
                         & (0x1fU == (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr)))
                         ? 0U : ((IData)(1U) + (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr)))
                     : (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr)));
    vlSelf->__PVT__hqb__DOT__fq__DOT__ram_ext__DOT___R0_en_d0 
        = vlSelf->__PVT__hqb__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqb__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0 
        = (0x1fU & ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__io_deq_valid_0)
                     ? (((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__do_deq) 
                         & (0x1fU == (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr)))
                         ? 0U : ((IData)(1U) + (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr)))
                     : (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr)));
    vlSelf->__PVT__hqc__DOT__fq__DOT__ram_ext__DOT___R0_en_d0 
        = vlSelf->__PVT__hqc__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqc__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0 
        = (0x1fU & ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__io_deq_valid_0)
                     ? (((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__do_deq) 
                         & (0x1fU == (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr)))
                         ? 0U : ((IData)(1U) + (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr)))
                     : (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr)));
    vlSelf->__PVT__hqd__DOT__fq__DOT__ram_ext__DOT___R0_en_d0 
        = vlSelf->__PVT__hqd__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqd__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0 
        = (0x1fU & ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__io_deq_valid_0)
                     ? (((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__do_deq) 
                         & (0x1fU == (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr)))
                         ? 0U : ((IData)(1U) + (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr)))
                     : (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr)));
    vlSelf->__PVT__hqa__DOT__fq__DOT__ram_ext__DOT___R0_en_d0 
        = vlSelf->__PVT__hqa__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqa__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0 
        = (0x1fU & ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__io_deq_valid_0)
                     ? (((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__do_deq) 
                         & (0x1fU == (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr)))
                         ? 0U : ((IData)(1U) + (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr)))
                     : (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr)));
    vlSelf->__PVT__b2c_data = vlSelf->__PVT__b2c_data_REG;
    vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr = vlSelf->__Vdly__hqe__DOT__fq__DOT__deq_ptr;
    vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr = vlSelf->__Vdly__hqb__DOT__fq__DOT__deq_ptr;
    vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr = vlSelf->__Vdly__hqc__DOT__fq__DOT__deq_ptr;
    vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr = vlSelf->__Vdly__hqd__DOT__fq__DOT__deq_ptr;
    vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr = vlSelf->__Vdly__hqa__DOT__fq__DOT__deq_ptr;
    vlSelf->__PVT__hqe__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqb__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqc__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqd__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqa__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__enq_ptr));
    vlSelf->__VdfgTmp_h8f767e1a__0 = (7U & ((IData)(vlSelf->__PVT__formatValid)
                                             ? vlSelf->__PVT__b2c_data
                                             : (IData)(vlSelf->__PVT__format_r)));
    vlSelf->__PVT__b2c_data_REG = vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__tx.__PVT__io_c2b_data_REG_2;
    vlSelf->__PVT__hqe__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqe__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqb__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqb__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqc__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqc__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqd__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqd__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqa__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqa__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqa_io_enq_valid = ((IData)(vlSelf->__PVT__b2c_send) 
                                       & ((IData)(1U) 
                                          << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)));
    vlSelf->__PVT__hqb_io_enq_valid = (0x7fU & ((IData)(vlSelf->__PVT__b2c_send) 
                                                & (((IData)(1U) 
                                                    << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                   >> 1U)));
    vlSelf->__PVT__hqc_io_enq_valid = (0x3fU & ((IData)(vlSelf->__PVT__b2c_send) 
                                                & (((IData)(1U) 
                                                    << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                   >> 2U)));
    vlSelf->__PVT__hqd_io_enq_valid = (0x1fU & ((IData)(vlSelf->__PVT__b2c_send) 
                                                & (((IData)(1U) 
                                                    << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                   >> 3U)));
    vlSelf->__PVT__hqe_io_enq_valid = (0xfU & ((IData)(vlSelf->__PVT__b2c_send) 
                                               & (((IData)(1U) 
                                                   << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                  >> 4U)));
    vlSelf->__PVT__hqa__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqa_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqb__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqb_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqc__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqc_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqd__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqd_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqe__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqe_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ram_out_valid));
}

VL_INLINE_OPT void VysyxSoCFull_RX___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__0(VysyxSoCFull_RX* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_RX___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__0\n"); );
    // Init
    IData/*19:0*/ __Vdly__rx_a;
    __Vdly__rx_a = 0;
    CData/*4:0*/ __Vdly__first_count;
    __Vdly__first_count = 0;
    IData/*19:0*/ __Vdly__tx_a;
    __Vdly__tx_a = 0;
    IData/*19:0*/ __Vdly__tx_b;
    __Vdly__tx_b = 0;
    IData/*19:0*/ __Vdly__tx_c;
    __Vdly__tx_c = 0;
    IData/*19:0*/ __Vdly__tx_d;
    __Vdly__tx_d = 0;
    IData/*19:0*/ __Vdly__tx_e;
    __Vdly__tx_e = 0;
    IData/*19:0*/ __Vdly__rx_b;
    __Vdly__rx_b = 0;
    IData/*19:0*/ __Vdly__rx_d;
    __Vdly__rx_d = 0;
    IData/*19:0*/ __Vdly__rx_c;
    __Vdly__rx_c = 0;
    IData/*19:0*/ __Vdly__rx_e;
    __Vdly__rx_e = 0;
    CData/*4:0*/ __Vdly__hqa__DOT__fq__DOT__enq_ptr;
    __Vdly__hqa__DOT__fq__DOT__enq_ptr = 0;
    CData/*4:0*/ __Vdly__hqb__DOT__fq__DOT__enq_ptr;
    __Vdly__hqb__DOT__fq__DOT__enq_ptr = 0;
    CData/*4:0*/ __Vdly__hqc__DOT__fq__DOT__enq_ptr;
    __Vdly__hqc__DOT__fq__DOT__enq_ptr = 0;
    CData/*4:0*/ __Vdly__hqd__DOT__fq__DOT__enq_ptr;
    __Vdly__hqd__DOT__fq__DOT__enq_ptr = 0;
    CData/*4:0*/ __Vdly__hqe__DOT__fq__DOT__enq_ptr;
    __Vdly__hqe__DOT__fq__DOT__enq_ptr = 0;
    // Body
    __Vdly__rx_e = vlSelf->__PVT__rx_e;
    __Vdly__rx_c = vlSelf->__PVT__rx_c;
    __Vdly__rx_d = vlSelf->__PVT__rx_d;
    __Vdly__rx_b = vlSelf->__PVT__rx_b;
    __Vdly__rx_a = vlSelf->__PVT__rx_a;
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__hqa_io_enq_valid)) 
                                 | (~ (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__full)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13035: Assertion failed in %NysyxSoCFull.fpga.chiplink.rx: Assertion failed at RX.scala:56\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13035, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13037: Assertion failed in %NysyxSoCFull.fpga.chiplink.rx\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13037, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__hqb_io_enq_valid)) 
                                 | (~ (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__full)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13041: Assertion failed in %NysyxSoCFull.fpga.chiplink.rx: Assertion failed at RX.scala:56\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13041, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13043: Assertion failed in %NysyxSoCFull.fpga.chiplink.rx\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13043, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__hqc_io_enq_valid)) 
                                 | (~ (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__full)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13047: Assertion failed in %NysyxSoCFull.fpga.chiplink.rx: Assertion failed at RX.scala:56\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13047, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13049: Assertion failed in %NysyxSoCFull.fpga.chiplink.rx\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13049, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__hqd_io_enq_valid)) 
                                 | (~ (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__full)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13053: Assertion failed in %NysyxSoCFull.fpga.chiplink.rx: Assertion failed at RX.scala:56\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13053, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13055: Assertion failed in %NysyxSoCFull.fpga.chiplink.rx\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13055, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                           & (~ ((~ (IData)(vlSelf->__PVT__hqe_io_enq_valid)) 
                                 | (~ (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__full)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13059: Assertion failed in %NysyxSoCFull.fpga.chiplink.rx: Assertion failed at RX.scala:56\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13059, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:13061: Assertion failed in %NysyxSoCFull.fpga.chiplink.rx\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 13061, "");
    }
    vlSelf->__Vdly__hqe__DOT__fq__DOT__deq_ptr = vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr;
    __Vdly__hqe__DOT__fq__DOT__enq_ptr = vlSelf->__PVT__hqe__DOT__fq__DOT__enq_ptr;
    vlSelf->__Vdly__hqd__DOT__fq__DOT__deq_ptr = vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr;
    __Vdly__hqd__DOT__fq__DOT__enq_ptr = vlSelf->__PVT__hqd__DOT__fq__DOT__enq_ptr;
    vlSelf->__Vdly__hqc__DOT__fq__DOT__deq_ptr = vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr;
    __Vdly__hqc__DOT__fq__DOT__enq_ptr = vlSelf->__PVT__hqc__DOT__fq__DOT__enq_ptr;
    vlSelf->__Vdly__hqb__DOT__fq__DOT__deq_ptr = vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr;
    __Vdly__hqb__DOT__fq__DOT__enq_ptr = vlSelf->__PVT__hqb__DOT__fq__DOT__enq_ptr;
    vlSelf->__Vdly__hqa__DOT__fq__DOT__deq_ptr = vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr;
    __Vdly__hqa__DOT__fq__DOT__enq_ptr = vlSelf->__PVT__hqa__DOT__fq__DOT__enq_ptr;
    vlSelf->__Vdlyvset__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__hqe__DOT__io_deq_q__DOT__full = vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__full;
    vlSelf->__Vdly__hqd__DOT__io_deq_q__DOT__full = vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__full;
    vlSelf->__Vdly__hqc__DOT__io_deq_q__DOT__full = vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__full;
    vlSelf->__Vdly__hqb__DOT__io_deq_q__DOT__full = vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__full;
    vlSelf->__Vdly__hqa__DOT__io_deq_q__DOT__full = vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__full;
    __Vdly__tx_e = vlSelf->__PVT__tx_e;
    __Vdly__tx_d = vlSelf->__PVT__tx_d;
    __Vdly__tx_c = vlSelf->__PVT__tx_c;
    __Vdly__tx_b = vlSelf->__PVT__tx_b;
    __Vdly__tx_a = vlSelf->__PVT__tx_a;
    __Vdly__first_count = vlSelf->__PVT__first_count;
    if (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        __Vdly__rx_e = 0x20U;
        __Vdly__rx_c = 0x20U;
        __Vdly__rx_d = 0x20U;
        __Vdly__rx_b = 0x20U;
        __Vdly__rx_a = 0x20U;
        vlSelf->__Vdly__hqe__DOT__fq__DOT__deq_ptr = 0U;
        __Vdly__hqe__DOT__fq__DOT__enq_ptr = 0U;
        vlSelf->__Vdly__hqd__DOT__fq__DOT__deq_ptr = 0U;
        __Vdly__hqd__DOT__fq__DOT__enq_ptr = 0U;
        vlSelf->__Vdly__hqc__DOT__fq__DOT__deq_ptr = 0U;
        __Vdly__hqc__DOT__fq__DOT__enq_ptr = 0U;
        vlSelf->__Vdly__hqb__DOT__fq__DOT__deq_ptr = 0U;
        __Vdly__hqb__DOT__fq__DOT__enq_ptr = 0U;
        vlSelf->__Vdly__hqa__DOT__fq__DOT__deq_ptr = 0U;
        __Vdly__hqa__DOT__fq__DOT__enq_ptr = 0U;
        vlSelf->__PVT__hqe__DOT__fq__DOT__maybe_full = 0U;
        vlSelf->__PVT__hqd__DOT__fq__DOT__maybe_full = 0U;
        vlSelf->__PVT__hqc__DOT__fq__DOT__maybe_full = 0U;
        vlSelf->__PVT__hqb__DOT__fq__DOT__maybe_full = 0U;
        vlSelf->__PVT__hqa__DOT__fq__DOT__maybe_full = 0U;
        __Vdly__first_count = 0U;
        __Vdly__tx_a = 0U;
        __Vdly__tx_b = 0U;
        __Vdly__tx_c = 0U;
        __Vdly__tx_d = 0U;
        __Vdly__tx_e = 0U;
    } else {
        vlSelf->__PVT__unnamedblk1__DOT___rxInc_e_T 
            = ((IData)(vlSelf->__PVT__io_e_source->__PVT__io_enq_ready) 
               & (IData)(vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__full));
        vlSelf->__PVT__unnamedblk1__DOT__rx_z_4 = (0x1fffffU 
                                                   & (vlSelf->__PVT__rx_e 
                                                      + (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_e_T)));
        vlSelf->__PVT__unnamedblk1__DOT___rxInc_c_T 
            = ((IData)(vlSelf->__PVT__io_c_source->__PVT__io_enq_ready) 
               & (IData)(vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__full));
        vlSelf->__PVT__unnamedblk1__DOT__rx_z_2 = (0x1fffffU 
                                                   & (vlSelf->__PVT__rx_c 
                                                      + (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_c_T)));
        vlSelf->__PVT__unnamedblk1__DOT___rxInc_d_T 
            = ((IData)(vlSelf->__PVT__io_d_source->__PVT__io_enq_ready) 
               & (IData)(vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__full));
        vlSelf->__PVT__unnamedblk1__DOT__rx_z_3 = (0x1fffffU 
                                                   & (vlSelf->__PVT__rx_d 
                                                      + (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_d_T)));
        vlSelf->__PVT__unnamedblk1__DOT___rxInc_bT 
            = ((IData)(vlSelf->__PVT__io_bsource->__PVT__io_enq_ready) 
               & (IData)(vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__full));
        vlSelf->__PVT__unnamedblk1__DOT__rx_z_1 = (0x1fffffU 
                                                   & (vlSelf->__PVT__rx_b 
                                                      + (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_bT)));
        vlSelf->__PVT__unnamedblk1__DOT___rxInc_a_T 
            = ((IData)(vlSelf->__PVT__io_a_source->__PVT__io_enq_ready) 
               & (IData)(vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__full));
        vlSelf->__PVT__unnamedblk1__DOT__rx_z = (0x1fffffU 
                                                 & (vlSelf->__PVT__rx_a 
                                                    + (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_a_T)));
        if (vlSelf->__PVT__io_rxc_source__DOT__io_enq_ready_0) {
            __Vdly__rx_e = (0xfffffU & (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_e_T));
            __Vdly__rx_c = (0xfffffU & (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_c_T));
            __Vdly__rx_d = (0xfffffU & (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_d_T));
            __Vdly__rx_b = (0xfffffU & (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_bT));
            __Vdly__rx_a = (0xfffffU & (IData)(vlSelf->__PVT__unnamedblk1__DOT___rxInc_a_T));
        } else {
            __Vdly__rx_e = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__rx_z_4)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__rx_z_4));
            __Vdly__rx_c = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__rx_z_2)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__rx_z_2));
            __Vdly__rx_d = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__rx_z_3)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__rx_z_3));
            __Vdly__rx_b = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__rx_z_1)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__rx_z_1));
            __Vdly__rx_a = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__rx_z)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__rx_z));
        }
        if (vlSelf->__PVT__hqe__DOT__fq__DOT__do_deq) {
            vlSelf->__Vdly__hqe__DOT__fq__DOT__deq_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr)));
        }
        if (vlSelf->__PVT__hqe__DOT__fq__DOT__do_enq) {
            __Vdly__hqe__DOT__fq__DOT__enq_ptr = (0x1fU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__enq_ptr)));
        }
        if (vlSelf->__PVT__hqd__DOT__fq__DOT__do_deq) {
            vlSelf->__Vdly__hqd__DOT__fq__DOT__deq_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr)));
        }
        if (vlSelf->__PVT__hqd__DOT__fq__DOT__do_enq) {
            __Vdly__hqd__DOT__fq__DOT__enq_ptr = (0x1fU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__enq_ptr)));
        }
        if (vlSelf->__PVT__hqc__DOT__fq__DOT__do_deq) {
            vlSelf->__Vdly__hqc__DOT__fq__DOT__deq_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr)));
        }
        if (vlSelf->__PVT__hqc__DOT__fq__DOT__do_enq) {
            __Vdly__hqc__DOT__fq__DOT__enq_ptr = (0x1fU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__enq_ptr)));
        }
        if (vlSelf->__PVT__hqb__DOT__fq__DOT__do_deq) {
            vlSelf->__Vdly__hqb__DOT__fq__DOT__deq_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr)));
        }
        if (vlSelf->__PVT__hqb__DOT__fq__DOT__do_enq) {
            __Vdly__hqb__DOT__fq__DOT__enq_ptr = (0x1fU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__enq_ptr)));
        }
        if (vlSelf->__PVT__hqa__DOT__fq__DOT__do_deq) {
            vlSelf->__Vdly__hqa__DOT__fq__DOT__deq_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr)));
        }
        if (vlSelf->__PVT__hqa__DOT__fq__DOT__do_enq) {
            __Vdly__hqa__DOT__fq__DOT__enq_ptr = (0x1fU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__enq_ptr)));
        }
        if (((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__do_deq))) {
            vlSelf->__PVT__hqe__DOT__fq__DOT__maybe_full 
                = vlSelf->__PVT__hqe__DOT__fq__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__do_deq))) {
            vlSelf->__PVT__hqd__DOT__fq__DOT__maybe_full 
                = vlSelf->__PVT__hqd__DOT__fq__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__do_deq))) {
            vlSelf->__PVT__hqc__DOT__fq__DOT__maybe_full 
                = vlSelf->__PVT__hqc__DOT__fq__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__do_deq))) {
            vlSelf->__PVT__hqb__DOT__fq__DOT__maybe_full 
                = vlSelf->__PVT__hqb__DOT__fq__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__do_deq))) {
            vlSelf->__PVT__hqa__DOT__fq__DOT__maybe_full 
                = vlSelf->__PVT__hqa__DOT__fq__DOT__do_enq;
        }
        if (vlSelf->__PVT__b2c_send) {
            vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___first_beats_beats_T_1 
                = (0xffU & ((IData)(1U) << (7U & (vlSelf->__PVT__b2c_data 
                                                  >> 9U))));
            vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT__first_beats_beats 
                = ((0x1eU & ((IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___first_beats_beats_T_1) 
                             >> 2U)) | (3U > (0xfU 
                                              & (vlSelf->__PVT__b2c_data 
                                                 >> 9U))));
            vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___GEN 
                = ((1U == (7U & (vlSelf->__PVT__b2c_data 
                                 >> 3U))) ? (((6U == 
                                               (7U 
                                                & (vlSelf->__PVT__b2c_data 
                                                   >> 9U))) 
                                              << 1U) 
                                             | (6U 
                                                > (0xfU 
                                                   & (vlSelf->__PVT__b2c_data 
                                                      >> 9U))))
                    : 0U);
            vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___first_beats_a_T_5 
                = (0x1fU & ((IData)(2U) + (((0x20U 
                                             & vlSelf->__PVT__b2c_data)
                                             ? 0U : (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT__first_beats_beats)) 
                                           + (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___GEN))));
            vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_0 
                = (((QData)((IData)((0x3ffU & (((IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___first_beats_a_T_5) 
                                                << 5U) 
                                               | (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___first_beats_a_T_5))))) 
                    << 0x1eU) | (QData)((IData)(((0xf8000U 
                                                  & ((((8U 
                                                        & vlSelf->__PVT__b2c_data)
                                                        ? (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT__first_beats_beats)
                                                        : 0U) 
                                                      + 
                                                      ((4U 
                                                        == 
                                                        (7U 
                                                         & (vlSelf->__PVT__b2c_data 
                                                            >> 3U))) 
                                                       | (5U 
                                                          == 
                                                          (7U 
                                                           & (vlSelf->__PVT__b2c_data 
                                                              >> 3U))))) 
                                                     << 0xfU)) 
                                                 | ((0x7c00U 
                                                     & (((IData)(2U) 
                                                         + 
                                                         ((8U 
                                                           & vlSelf->__PVT__b2c_data)
                                                           ? (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT__first_beats_beats)
                                                           : 0U)) 
                                                        << 0xaU)) 
                                                    | ((0x3e0U 
                                                        & (((IData)(2U) 
                                                            + 
                                                            (((0x20U 
                                                               & vlSelf->__PVT__b2c_data)
                                                               ? 0U
                                                               : (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT__first_beats_beats)) 
                                                             + (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___GEN))) 
                                                           << 5U)) 
                                                       | (IData)(vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___first_beats_a_T_5)))))));
            __Vdly__first_count = (0x1fU & ((IData)(vlSelf->__PVT__first)
                                             ? ((0x27U 
                                                 >= 
                                                 (0x3fU 
                                                  & ((IData)(5U) 
                                                     * 
                                                     (7U 
                                                      & vlSelf->__PVT__b2c_data))))
                                                 ? (IData)(
                                                           (vlSelf->__PVT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_0 
                                                            >> 
                                                            (0x3fU 
                                                             & ((IData)(5U) 
                                                                * 
                                                                (7U 
                                                                 & vlSelf->__PVT__b2c_data)))))
                                                 : 0U)
                                             : ((IData)(vlSelf->__PVT__first_count) 
                                                - (IData)(1U))));
        }
        vlSelf->__PVT__unnamedblk1__DOT___txInc_T_1 
            = (7U & ((IData)(vlSelf->__PVT__b2c_send) 
                     & (((IData)(1U) << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                        >> 5U)));
        vlSelf->__PVT__unnamedblk1__DOT___txInc_out_a_T_3 
            = ((IData)(1U) << (0x1fU & (vlSelf->__PVT__b2c_data 
                                        >> 7U)));
        vlSelf->__PVT__unnamedblk1__DOT___txInc_out_bT_3 
            = ((IData)(1U) << (0x1fU & (vlSelf->__PVT__b2c_data 
                                        >> 0xcU)));
        vlSelf->__PVT__unnamedblk1__DOT___txInc_out_c_T_3 
            = ((IData)(1U) << (0x1fU & (vlSelf->__PVT__b2c_data 
                                        >> 0x11U)));
        vlSelf->__PVT__unnamedblk1__DOT___txInc_out_d_T_3 
            = ((IData)(1U) << (0x1fU & (vlSelf->__PVT__b2c_data 
                                        >> 0x16U)));
        vlSelf->__PVT__unnamedblk1__DOT___txInc_out_e_T_3 
            = ((IData)(1U) << (vlSelf->__PVT__b2c_data 
                               >> 0x1bU));
        if (vlSelf->__PVT__unnamedblk1__DOT___txInc_T_1) {
            vlSelf->__PVT__unnamedblk1__DOT__txInc_a 
                = ((0x14U < (0x1fU & (vlSelf->__PVT__b2c_data 
                                      >> 7U))) ? 0xfffffU
                    : (0xfffffU & (vlSelf->__PVT__unnamedblk1__DOT___txInc_out_a_T_3 
                                   >> 1U)));
            vlSelf->__PVT__unnamedblk1__DOT__txInc_b 
                = ((0x14U < (0x1fU & (vlSelf->__PVT__b2c_data 
                                      >> 0xcU))) ? 0xfffffU
                    : (0xfffffU & (vlSelf->__PVT__unnamedblk1__DOT___txInc_out_bT_3 
                                   >> 1U)));
            vlSelf->__PVT__unnamedblk1__DOT__txInc_c 
                = ((0x14U < (0x1fU & (vlSelf->__PVT__b2c_data 
                                      >> 0x11U))) ? 0xfffffU
                    : (0xfffffU & (vlSelf->__PVT__unnamedblk1__DOT___txInc_out_c_T_3 
                                   >> 1U)));
            vlSelf->__PVT__unnamedblk1__DOT__txInc_d 
                = ((0x14U < (0x1fU & (vlSelf->__PVT__b2c_data 
                                      >> 0x16U))) ? 0xfffffU
                    : (0xfffffU & (vlSelf->__PVT__unnamedblk1__DOT___txInc_out_d_T_3 
                                   >> 1U)));
            vlSelf->__PVT__unnamedblk1__DOT__txInc_e 
                = ((0x14U < (vlSelf->__PVT__b2c_data 
                             >> 0x1bU)) ? 0xfffffU : 
                   (0xfffffU & (vlSelf->__PVT__unnamedblk1__DOT___txInc_out_e_T_3 
                                >> 1U)));
        } else {
            vlSelf->__PVT__unnamedblk1__DOT__txInc_a = 0U;
            vlSelf->__PVT__unnamedblk1__DOT__txInc_b = 0U;
            vlSelf->__PVT__unnamedblk1__DOT__txInc_c = 0U;
            vlSelf->__PVT__unnamedblk1__DOT__txInc_d = 0U;
            vlSelf->__PVT__unnamedblk1__DOT__txInc_e = 0U;
        }
        vlSelf->__PVT__unnamedblk1__DOT__tx_z = (0x1fffffU 
                                                 & (vlSelf->__PVT__tx_a 
                                                    + vlSelf->__PVT__unnamedblk1__DOT__txInc_a));
        vlSelf->__PVT__unnamedblk1__DOT__tx_z_1 = (0x1fffffU 
                                                   & (vlSelf->__PVT__tx_b 
                                                      + vlSelf->__PVT__unnamedblk1__DOT__txInc_b));
        vlSelf->__PVT__unnamedblk1__DOT__tx_z_2 = (0x1fffffU 
                                                   & (vlSelf->__PVT__tx_c 
                                                      + vlSelf->__PVT__unnamedblk1__DOT__txInc_c));
        vlSelf->__PVT__unnamedblk1__DOT__tx_z_3 = (0x1fffffU 
                                                   & (vlSelf->__PVT__tx_d 
                                                      + vlSelf->__PVT__unnamedblk1__DOT__txInc_d));
        vlSelf->__PVT__unnamedblk1__DOT__tx_z_4 = (0x1fffffU 
                                                   & (vlSelf->__PVT__tx_e 
                                                      + vlSelf->__PVT__unnamedblk1__DOT__txInc_e));
        if (vlSelf->__PVT__io_txc_source__DOT__io_enq_ready_0) {
            __Vdly__tx_a = (0xfffffU & vlSelf->__PVT__unnamedblk1__DOT__txInc_a);
            __Vdly__tx_b = (0xfffffU & vlSelf->__PVT__unnamedblk1__DOT__txInc_b);
            __Vdly__tx_c = (0xfffffU & vlSelf->__PVT__unnamedblk1__DOT__txInc_c);
            __Vdly__tx_d = (0xfffffU & vlSelf->__PVT__unnamedblk1__DOT__txInc_d);
            __Vdly__tx_e = (0xfffffU & vlSelf->__PVT__unnamedblk1__DOT__txInc_e);
        } else {
            __Vdly__tx_a = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__tx_z)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__tx_z));
            __Vdly__tx_b = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__tx_z_1)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__tx_z_1));
            __Vdly__tx_c = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__tx_z_2)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__tx_z_2));
            __Vdly__tx_d = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__tx_z_3)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__tx_z_3));
            __Vdly__tx_e = (0xfffffU & ((0x100000U 
                                         & vlSelf->__PVT__unnamedblk1__DOT__tx_z_4)
                                         ? 0xfffffU
                                         : vlSelf->__PVT__unnamedblk1__DOT__tx_z_4));
        }
    }
    if (vlSelf->__PVT__hqe__DOT__fq__DOT__do_enq) {
        vlSelf->__Vdlyvval__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__b2c_data;
        vlSelf->__Vdlyvset__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__hqe__DOT__fq__DOT__enq_ptr;
    }
    if (vlSelf->__PVT__hqd__DOT__fq__DOT__do_enq) {
        vlSelf->__Vdlyvval__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__b2c_data;
        vlSelf->__Vdlyvset__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__hqd__DOT__fq__DOT__enq_ptr;
    }
    if (vlSelf->__PVT__hqc__DOT__fq__DOT__do_enq) {
        vlSelf->__Vdlyvval__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__b2c_data;
        vlSelf->__Vdlyvset__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__hqc__DOT__fq__DOT__enq_ptr;
    }
    if (vlSelf->__PVT__hqb__DOT__fq__DOT__do_enq) {
        vlSelf->__Vdlyvval__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__b2c_data;
        vlSelf->__Vdlyvset__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__hqb__DOT__fq__DOT__enq_ptr;
    }
    if (vlSelf->__PVT__hqa__DOT__fq__DOT__do_enq) {
        vlSelf->__Vdlyvval__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__b2c_data;
        vlSelf->__Vdlyvset__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->__PVT__hqa__DOT__fq__DOT__enq_ptr;
    }
    vlSelf->__PVT__hqe__DOT__fq__DOT__ram_out_valid 
        = vlSelf->__PVT__hqe__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqd__DOT__fq__DOT__ram_out_valid 
        = vlSelf->__PVT__hqd__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqc__DOT__fq__DOT__ram_out_valid 
        = vlSelf->__PVT__hqc__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqb__DOT__fq__DOT__ram_out_valid 
        = vlSelf->__PVT__hqb__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqa__DOT__fq__DOT__ram_out_valid 
        = vlSelf->__PVT__hqa__DOT__fq__DOT__ren;
    if (vlSelf->__PVT__formatValid) {
        vlSelf->__PVT__format_r = (7U & vlSelf->__PVT__b2c_data);
    }
    if (vlSelf->__PVT__io_rxc_source__DOT__io_enq_ready_0) {
        vlSelf->__PVT__io_rxc_source__DOT__mem_0_a 
            = vlSelf->__PVT__rx_a;
        vlSelf->__PVT__io_rxc_source__DOT__mem_0_b 
            = vlSelf->__PVT__rx_b;
        vlSelf->__PVT__io_rxc_source__DOT__mem_0_c 
            = vlSelf->__PVT__rx_c;
        vlSelf->__PVT__io_rxc_source__DOT__mem_0_d 
            = vlSelf->__PVT__rx_d;
        vlSelf->__PVT__io_rxc_source__DOT__mem_0_e 
            = vlSelf->__PVT__rx_e;
    }
    if (vlSelf->__PVT__io_txc_source__DOT__io_enq_ready_0) {
        vlSelf->__PVT__io_txc_source__DOT__mem_0_a 
            = vlSelf->__PVT__tx_a;
        vlSelf->__PVT__io_txc_source__DOT__mem_0_b 
            = vlSelf->__PVT__tx_b;
        vlSelf->__PVT__io_txc_source__DOT__mem_0_c 
            = vlSelf->__PVT__tx_c;
        vlSelf->__PVT__io_txc_source__DOT__mem_0_d 
            = vlSelf->__PVT__tx_d;
        vlSelf->__PVT__io_txc_source__DOT__mem_0_e 
            = vlSelf->__PVT__tx_e;
    }
    vlSelf->__PVT__hqe__DOT__fq__DOT__enq_ptr = __Vdly__hqe__DOT__fq__DOT__enq_ptr;
    vlSelf->__PVT__hqd__DOT__fq__DOT__enq_ptr = __Vdly__hqd__DOT__fq__DOT__enq_ptr;
    vlSelf->__PVT__hqc__DOT__fq__DOT__enq_ptr = __Vdly__hqc__DOT__fq__DOT__enq_ptr;
    vlSelf->__PVT__hqb__DOT__fq__DOT__enq_ptr = __Vdly__hqb__DOT__fq__DOT__enq_ptr;
    vlSelf->__PVT__hqa__DOT__fq__DOT__enq_ptr = __Vdly__hqa__DOT__fq__DOT__enq_ptr;
    vlSelf->__PVT__first_count = __Vdly__first_count;
    vlSelf->__PVT__rx_a = __Vdly__rx_a;
    vlSelf->__PVT__rx_b = __Vdly__rx_b;
    vlSelf->__PVT__rx_c = __Vdly__rx_c;
    vlSelf->__PVT__rx_d = __Vdly__rx_d;
    vlSelf->__PVT__rx_e = __Vdly__rx_e;
    vlSelf->__PVT__tx_a = __Vdly__tx_a;
    vlSelf->__PVT__tx_b = __Vdly__tx_b;
    vlSelf->__PVT__tx_c = __Vdly__tx_c;
    vlSelf->__PVT__tx_d = __Vdly__tx_d;
    vlSelf->__PVT__tx_e = __Vdly__tx_e;
    vlSelf->__PVT__first = (0U == (IData)(vlSelf->__PVT__first_count));
    vlSelf->__PVT__b2c_send = ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0)) 
                               & (IData)(vlSelf->__PVT__b2c_send_REG));
    vlSelf->__PVT__formatValid = ((IData)(vlSelf->__PVT__b2c_send) 
                                  & (0U == (IData)(vlSelf->__PVT__first_count)));
    vlSelf->__PVT__b2c_send_REG = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__tx.__PVT__io_c2b_send_REG_1;
}

VL_INLINE_OPT void VysyxSoCFull_RX___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__1(VysyxSoCFull_RX* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_RX___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx__1\n"); );
    // Body
    vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq 
        = ((IData)(vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__io_enq_ready_0) 
           & (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__io_deq_valid_0));
    if (vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__ram 
            = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__empty)
                ? vlSelf->__PVT__b2c_data : ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ram_ext__DOT___R0_en_d0)
                                              ? vlSelf->__PVT__hqe__DOT__fq__DOT__ram_ext__DOT__Memory
                                             [vlSelf->__PVT__hqe__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0]
                                              : 0U));
    }
    vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq 
        = ((IData)(vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__io_enq_ready_0) 
           & (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__io_deq_valid_0));
    if (vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__ram 
            = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__empty)
                ? vlSelf->__PVT__b2c_data : ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ram_ext__DOT___R0_en_d0)
                                              ? vlSelf->__PVT__hqb__DOT__fq__DOT__ram_ext__DOT__Memory
                                             [vlSelf->__PVT__hqb__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0]
                                              : 0U));
    }
    vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq 
        = ((IData)(vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__io_enq_ready_0) 
           & (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__io_deq_valid_0));
    if (vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__ram 
            = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__empty)
                ? vlSelf->__PVT__b2c_data : ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ram_ext__DOT___R0_en_d0)
                                              ? vlSelf->__PVT__hqd__DOT__fq__DOT__ram_ext__DOT__Memory
                                             [vlSelf->__PVT__hqd__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0]
                                              : 0U));
    }
    vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq 
        = ((IData)(vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__io_enq_ready_0) 
           & (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__io_deq_valid_0));
    if (vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__ram 
            = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__empty)
                ? vlSelf->__PVT__b2c_data : ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ram_ext__DOT___R0_en_d0)
                                              ? vlSelf->__PVT__hqc__DOT__fq__DOT__ram_ext__DOT__Memory
                                             [vlSelf->__PVT__hqc__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0]
                                              : 0U));
    }
    vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq 
        = ((IData)(vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__io_enq_ready_0) 
           & (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__io_deq_valid_0));
    if (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__chiplink__DOT__rx_reset_reg__DOT__reg_0) {
        vlSelf->__Vdly__hqe__DOT__io_deq_q__DOT__full = 0U;
        vlSelf->__Vdly__hqb__DOT__io_deq_q__DOT__full = 0U;
        vlSelf->__Vdly__hqd__DOT__io_deq_q__DOT__full = 0U;
        vlSelf->__Vdly__hqc__DOT__io_deq_q__DOT__full = 0U;
        vlSelf->__Vdly__hqa__DOT__io_deq_q__DOT__full = 0U;
    } else {
        if (((IData)(vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) 
             != ((IData)(vlSelf->__PVT__io_e_source->__PVT__io_enq_ready) 
                 & (IData)(vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__full)))) {
            vlSelf->__Vdly__hqe__DOT__io_deq_q__DOT__full 
                = vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) 
             != ((IData)(vlSelf->__PVT__io_bsource->__PVT__io_enq_ready) 
                 & (IData)(vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__full)))) {
            vlSelf->__Vdly__hqb__DOT__io_deq_q__DOT__full 
                = vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) 
             != ((IData)(vlSelf->__PVT__io_d_source->__PVT__io_enq_ready) 
                 & (IData)(vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__full)))) {
            vlSelf->__Vdly__hqd__DOT__io_deq_q__DOT__full 
                = vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) 
             != ((IData)(vlSelf->__PVT__io_c_source->__PVT__io_enq_ready) 
                 & (IData)(vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__full)))) {
            vlSelf->__Vdly__hqc__DOT__io_deq_q__DOT__full 
                = vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) 
             != ((IData)(vlSelf->__PVT__io_a_source->__PVT__io_enq_ready) 
                 & (IData)(vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__full)))) {
            vlSelf->__Vdly__hqa__DOT__io_deq_q__DOT__full 
                = vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq;
        }
    }
    if (vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__ram 
            = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__empty)
                ? vlSelf->__PVT__b2c_data : ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ram_ext__DOT___R0_en_d0)
                                              ? vlSelf->__PVT__hqa__DOT__fq__DOT__ram_ext__DOT__Memory
                                             [vlSelf->__PVT__hqa__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0]
                                              : 0U));
    }
    if (vlSelf->__Vdlyvset__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__hqe__DOT__fq__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0] 
            = vlSelf->__Vdlyvval__hqe__DOT__fq__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__full = vlSelf->__Vdly__hqe__DOT__io_deq_q__DOT__full;
    if (vlSelf->__Vdlyvset__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__hqb__DOT__fq__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0] 
            = vlSelf->__Vdlyvval__hqb__DOT__fq__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__full = vlSelf->__Vdly__hqb__DOT__io_deq_q__DOT__full;
    if (vlSelf->__Vdlyvset__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__hqd__DOT__fq__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0] 
            = vlSelf->__Vdlyvval__hqd__DOT__fq__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__full = vlSelf->__Vdly__hqd__DOT__io_deq_q__DOT__full;
    if (vlSelf->__Vdlyvset__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__hqc__DOT__fq__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0] 
            = vlSelf->__Vdlyvval__hqc__DOT__fq__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__full = vlSelf->__Vdly__hqc__DOT__io_deq_q__DOT__full;
    if (vlSelf->__Vdlyvset__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__hqa__DOT__fq__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0] 
            = vlSelf->__Vdlyvval__hqa__DOT__fq__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__full = vlSelf->__Vdly__hqa__DOT__io_deq_q__DOT__full;
    vlSelf->__PVT__hqe__DOT__fq__DOT__ram_ext__DOT___R0_en_d0 
        = vlSelf->__PVT__hqe__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqe__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0 
        = (0x1fU & ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__io_deq_valid_0)
                     ? (((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__do_deq) 
                         & (0x1fU == (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr)))
                         ? 0U : ((IData)(1U) + (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr)))
                     : (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr)));
    vlSelf->__PVT__hqb__DOT__fq__DOT__ram_ext__DOT___R0_en_d0 
        = vlSelf->__PVT__hqb__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqb__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0 
        = (0x1fU & ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__io_deq_valid_0)
                     ? (((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__do_deq) 
                         & (0x1fU == (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr)))
                         ? 0U : ((IData)(1U) + (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr)))
                     : (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr)));
    vlSelf->__PVT__hqd__DOT__fq__DOT__ram_ext__DOT___R0_en_d0 
        = vlSelf->__PVT__hqd__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqd__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0 
        = (0x1fU & ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__io_deq_valid_0)
                     ? (((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__do_deq) 
                         & (0x1fU == (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr)))
                         ? 0U : ((IData)(1U) + (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr)))
                     : (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr)));
    vlSelf->__PVT__hqc__DOT__fq__DOT__ram_ext__DOT___R0_en_d0 
        = vlSelf->__PVT__hqc__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqc__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0 
        = (0x1fU & ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__io_deq_valid_0)
                     ? (((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__do_deq) 
                         & (0x1fU == (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr)))
                         ? 0U : ((IData)(1U) + (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr)))
                     : (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr)));
    vlSelf->__PVT__hqa__DOT__fq__DOT__ram_ext__DOT___R0_en_d0 
        = vlSelf->__PVT__hqa__DOT__fq__DOT__ren;
    vlSelf->__PVT__hqa__DOT__fq__DOT__ram_ext__DOT___R0_addr_d0 
        = (0x1fU & ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__io_deq_valid_0)
                     ? (((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__do_deq) 
                         & (0x1fU == (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr)))
                         ? 0U : ((IData)(1U) + (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr)))
                     : (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr)));
    vlSelf->__PVT__b2c_data = vlSelf->__PVT__b2c_data_REG;
    vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr = vlSelf->__Vdly__hqe__DOT__fq__DOT__deq_ptr;
    vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr = vlSelf->__Vdly__hqb__DOT__fq__DOT__deq_ptr;
    vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr = vlSelf->__Vdly__hqd__DOT__fq__DOT__deq_ptr;
    vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr = vlSelf->__Vdly__hqc__DOT__fq__DOT__deq_ptr;
    vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr = vlSelf->__Vdly__hqa__DOT__fq__DOT__deq_ptr;
    vlSelf->__PVT__hqe__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqb__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqd__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqc__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__enq_ptr));
    vlSelf->__PVT__hqa__DOT__fq__DOT__ptr_match = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr) 
                                                   == (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__enq_ptr));
    vlSelf->__VdfgTmp_h8f767e1a__0 = (7U & ((IData)(vlSelf->__PVT__formatValid)
                                             ? vlSelf->__PVT__b2c_data
                                             : (IData)(vlSelf->__PVT__format_r)));
    vlSelf->__PVT__b2c_data_REG = vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__tx.__PVT__io_c2b_data_REG_2;
    vlSelf->__PVT__hqe__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqe__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqb__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqb__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqd__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqd__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqc__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqc__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqa__DOT__fq__DOT__full = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ptr_match) 
                                              & (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__maybe_full));
    vlSelf->__PVT__hqa__DOT__fq__DOT__empty = ((~ (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__maybe_full)) 
                                               & (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ptr_match));
    vlSelf->__PVT__hqa_io_enq_valid = ((IData)(vlSelf->__PVT__b2c_send) 
                                       & ((IData)(1U) 
                                          << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)));
    vlSelf->__PVT__hqb_io_enq_valid = (0x7fU & ((IData)(vlSelf->__PVT__b2c_send) 
                                                & (((IData)(1U) 
                                                    << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                   >> 1U)));
    vlSelf->__PVT__hqc_io_enq_valid = (0x3fU & ((IData)(vlSelf->__PVT__b2c_send) 
                                                & (((IData)(1U) 
                                                    << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                   >> 2U)));
    vlSelf->__PVT__hqd_io_enq_valid = (0x1fU & ((IData)(vlSelf->__PVT__b2c_send) 
                                                & (((IData)(1U) 
                                                    << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                   >> 3U)));
    vlSelf->__PVT__hqe_io_enq_valid = (0xfU & ((IData)(vlSelf->__PVT__b2c_send) 
                                               & (((IData)(1U) 
                                                   << (IData)(vlSelf->__VdfgTmp_h8f767e1a__0)) 
                                                  >> 4U)));
    vlSelf->__PVT__hqa__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqa_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqb__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqb_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqc__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqc_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqd__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqd_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__ram_out_valid));
    vlSelf->__PVT__hqe__DOT__fq__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__empty)
            ? (IData)(vlSelf->__PVT__hqe_io_enq_valid)
            : (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__ram_out_valid));
}
