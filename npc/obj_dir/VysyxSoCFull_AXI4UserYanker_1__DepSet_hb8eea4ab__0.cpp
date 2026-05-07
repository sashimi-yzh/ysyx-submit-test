// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_AXI4UserYanker_1.h"
#include "VysyxSoCFull__Syms.h"

VL_INLINE_OPT void VysyxSoCFull_AXI4UserYanker_1___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1__0(VysyxSoCFull_AXI4UserYanker_1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_AXI4UserYanker_1___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1__0\n"); );
    // Init
    SData/*15:0*/ __PVT__unnamedblk1__DOT___GEN_6;
    __PVT__unnamedblk1__DOT___GEN_6 = 0;
    SData/*15:0*/ __PVT__unnamedblk1__DOT___GEN_7;
    __PVT__unnamedblk1__DOT___GEN_7 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_1__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_1__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_1__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_1__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_2__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_2__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_2__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_2__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_3__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_3__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_3__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_3__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_4__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_4__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_4__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_4__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_5__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_5__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_5__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_5__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_6__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_6__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_6__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_6__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap__DOT__full;
    __Vdly__Queue1_BundleMap__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_1__DOT__full;
    __Vdly__Queue1_BundleMap_1__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_2__DOT__full;
    __Vdly__Queue1_BundleMap_2__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_3__DOT__full;
    __Vdly__Queue1_BundleMap_3__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_4__DOT__full;
    __Vdly__Queue1_BundleMap_4__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_5__DOT__full;
    __Vdly__Queue1_BundleMap_5__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_6__DOT__full;
    __Vdly__Queue1_BundleMap_6__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_7__DOT__full;
    __Vdly__Queue1_BundleMap_7__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_8__DOT__full;
    __Vdly__Queue1_BundleMap_8__DOT__full = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_7__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_7__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_7__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_7__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_8__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_8__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_8__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_8__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_9__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_9__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_9__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_9__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_10__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_10__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_10__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_10__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_11__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_11__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_11__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_11__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_12__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_12__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_12__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_12__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_13__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_13__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_13__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_13__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_9__DOT__full;
    __Vdly__Queue1_BundleMap_9__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_10__DOT__full;
    __Vdly__Queue1_BundleMap_10__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_11__DOT__full;
    __Vdly__Queue1_BundleMap_11__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_12__DOT__full;
    __Vdly__Queue1_BundleMap_12__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_13__DOT__full;
    __Vdly__Queue1_BundleMap_13__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_14__DOT__full;
    __Vdly__Queue1_BundleMap_14__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_15__DOT__full;
    __Vdly__Queue1_BundleMap_15__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_16__DOT__full;
    __Vdly__Queue1_BundleMap_16__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_17__DOT__full;
    __Vdly__Queue1_BundleMap_17__DOT__full = 0;
    // Body
    __Vdly__Queue17_BundleMap_13__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_12__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_11__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_10__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_9__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_8__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_7__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_6__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_5__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_4__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_3__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_2__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_1__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap__DOT__enq_ptr_value = vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value;
    __Vdlyvset__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdly__Queue1_BundleMap_17__DOT__full = vlSelf->__PVT__Queue1_BundleMap_17__DOT__full;
    __Vdly__Queue1_BundleMap_16__DOT__full = vlSelf->__PVT__Queue1_BundleMap_16__DOT__full;
    __Vdly__Queue1_BundleMap_15__DOT__full = vlSelf->__PVT__Queue1_BundleMap_15__DOT__full;
    __Vdly__Queue1_BundleMap_14__DOT__full = vlSelf->__PVT__Queue1_BundleMap_14__DOT__full;
    __Vdly__Queue1_BundleMap_13__DOT__full = vlSelf->__PVT__Queue1_BundleMap_13__DOT__full;
    __Vdly__Queue1_BundleMap_12__DOT__full = vlSelf->__PVT__Queue1_BundleMap_12__DOT__full;
    __Vdly__Queue1_BundleMap_11__DOT__full = vlSelf->__PVT__Queue1_BundleMap_11__DOT__full;
    __Vdly__Queue1_BundleMap_10__DOT__full = vlSelf->__PVT__Queue1_BundleMap_10__DOT__full;
    __Vdly__Queue1_BundleMap_9__DOT__full = vlSelf->__PVT__Queue1_BundleMap_9__DOT__full;
    __Vdly__Queue1_BundleMap_8__DOT__full = vlSelf->__PVT__Queue1_BundleMap_8__DOT__full;
    __Vdly__Queue1_BundleMap_7__DOT__full = vlSelf->__PVT__Queue1_BundleMap_7__DOT__full;
    __Vdly__Queue1_BundleMap_6__DOT__full = vlSelf->__PVT__Queue1_BundleMap_6__DOT__full;
    __Vdly__Queue1_BundleMap_5__DOT__full = vlSelf->__PVT__Queue1_BundleMap_5__DOT__full;
    __Vdly__Queue1_BundleMap_4__DOT__full = vlSelf->__PVT__Queue1_BundleMap_4__DOT__full;
    __Vdly__Queue1_BundleMap_3__DOT__full = vlSelf->__PVT__Queue1_BundleMap_3__DOT__full;
    __Vdly__Queue1_BundleMap_2__DOT__full = vlSelf->__PVT__Queue1_BundleMap_2__DOT__full;
    __Vdly__Queue1_BundleMap_1__DOT__full = vlSelf->__PVT__Queue1_BundleMap_1__DOT__full;
    __Vdly__Queue1_BundleMap__DOT__full = vlSelf->__PVT__Queue1_BundleMap__DOT__full;
    __Vdly__Queue17_BundleMap_13__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_12__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_11__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_10__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_9__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_8__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_7__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_6__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_5__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_4__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_3__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_2__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_1__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap__DOT__deq_ptr_value = vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value;
    __PVT__unnamedblk1__DOT___GEN_6 = (((IData)(vlSelf->__PVT__Queue1_BundleMap_8__DOT__full) 
                                        << 0xfU) | 
                                       (((IData)(vlSelf->__PVT__Queue1_BundleMap_7__DOT__full) 
                                         << 0xeU) | 
                                        (((IData)(vlSelf->__PVT__Queue1_BundleMap_6__DOT__full) 
                                          << 0xdU) 
                                         | (((IData)(vlSelf->__PVT__Queue1_BundleMap_5__DOT__full) 
                                             << 0xcU) 
                                            | (((IData)(vlSelf->__PVT__Queue1_BundleMap_4__DOT__full) 
                                                << 0xbU) 
                                               | (((IData)(vlSelf->__PVT__Queue1_BundleMap_3__DOT__full) 
                                                   << 0xaU) 
                                                  | (((IData)(vlSelf->__PVT__Queue1_BundleMap_2__DOT__full) 
                                                      << 9U) 
                                                     | (((IData)(vlSelf->__PVT__Queue1_BundleMap_1__DOT__full) 
                                                         << 8U) 
                                                        | (((IData)(vlSelf->__PVT__Queue1_BundleMap__DOT__full) 
                                                            << 7U) 
                                                           | ((0x40U 
                                                               & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__empty)) 
                                                                  << 6U)) 
                                                              | ((0x20U 
                                                                  & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__empty)) 
                                                                     << 5U)) 
                                                                 | ((0x10U 
                                                                     & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__empty)) 
                                                                        << 4U)) 
                                                                    | ((8U 
                                                                        & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__empty)) 
                                                                           << 3U)) 
                                                                       | ((4U 
                                                                           & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__empty)) 
                                                                              << 2U)) 
                                                                          | ((2U 
                                                                              & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__empty)) 
                                                                                << 1U)) 
                                                                             | (1U 
                                                                                & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__empty))))))))))))))))));
    __PVT__unnamedblk1__DOT___GEN_7 = (((IData)(vlSelf->__PVT__Queue1_BundleMap_17__DOT__full) 
                                        << 0xfU) | 
                                       (((IData)(vlSelf->__PVT__Queue1_BundleMap_16__DOT__full) 
                                         << 0xeU) | 
                                        (((IData)(vlSelf->__PVT__Queue1_BundleMap_15__DOT__full) 
                                          << 0xdU) 
                                         | (((IData)(vlSelf->__PVT__Queue1_BundleMap_14__DOT__full) 
                                             << 0xcU) 
                                            | (((IData)(vlSelf->__PVT__Queue1_BundleMap_13__DOT__full) 
                                                << 0xbU) 
                                               | (((IData)(vlSelf->__PVT__Queue1_BundleMap_12__DOT__full) 
                                                   << 0xaU) 
                                                  | (((IData)(vlSelf->__PVT__Queue1_BundleMap_11__DOT__full) 
                                                      << 9U) 
                                                     | (((IData)(vlSelf->__PVT__Queue1_BundleMap_10__DOT__full) 
                                                         << 8U) 
                                                        | (((IData)(vlSelf->__PVT__Queue1_BundleMap_9__DOT__full) 
                                                            << 7U) 
                                                           | ((0x40U 
                                                               & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__empty)) 
                                                                  << 6U)) 
                                                              | ((0x20U 
                                                                  & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__empty)) 
                                                                     << 5U)) 
                                                                 | ((0x10U 
                                                                     & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__empty)) 
                                                                        << 4U)) 
                                                                    | ((8U 
                                                                        & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__empty)) 
                                                                           << 3U)) 
                                                                       | ((4U 
                                                                           & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__empty)) 
                                                                              << 2U)) 
                                                                          | ((2U 
                                                                              & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__empty)) 
                                                                                << 1U)) 
                                                                             | (1U 
                                                                                & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__empty))))))))))))))))));
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rvalid)) 
                                 | ((IData)(__PVT__unnamedblk1__DOT___GEN_6) 
                                    >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:18185: Assertion failed in %NysyxSoCFull.asic.chipMaster.axi4yank_1.unnamedblk1: Assertion failed at UserYanker.scala:69\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 18185, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:18187: Assertion failed in %NysyxSoCFull.asic.chipMaster.axi4yank_1.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 18187, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bvalid)) 
                                 | ((IData)(__PVT__unnamedblk1__DOT___GEN_7) 
                                    >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:18191: Assertion failed in %NysyxSoCFull.asic.chipMaster.axi4yank_1.unnamedblk1: Assertion failed at UserYanker.scala:98\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 18191, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:18193: Assertion failed in %NysyxSoCFull.asic.chipMaster.axi4yank_1.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 18193, "");
    }
    if (vlSelf->__PVT__Queue17_BundleMap_13__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_13__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_13__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_12__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_12__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_12__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_11__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_11__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_11__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_10__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_10__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_10__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_9__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_9__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_9__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_8__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_8__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_8__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_7__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_7__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_7__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_6__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_6__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_6__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_5__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_5__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_5__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_4__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_4__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_4__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_3__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_3__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_3__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_2__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_2__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_2__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_1__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_1__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_1__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap__DOT__do_enq) {
        vlSelf->Queue17_BundleMap__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value;
        }
    }
    vlSelf->__PVT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq 
        = (((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_17__DOT__full)) 
            & (IData)(vlSelf->__PVT___GEN_12)) & (((IData)(1U) 
                                                   << 
                                                   (0xfU 
                                                    & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                                                  >> 0xfU));
    if (vlSelf->__PVT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_17__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq 
        = (3U & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_16__DOT__full)) 
                 & ((IData)(vlSelf->__PVT___GEN_12) 
                    & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                       >> 0xeU))));
    if (vlSelf->__PVT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_16__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq 
        = (7U & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_15__DOT__full)) 
                 & ((IData)(vlSelf->__PVT___GEN_12) 
                    & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                       >> 0xdU))));
    if (vlSelf->__PVT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_15__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq 
        = (0xfU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_14__DOT__full)) 
                   & ((IData)(vlSelf->__PVT___GEN_12) 
                      & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                         >> 0xcU))));
    if (vlSelf->__PVT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_14__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq 
        = (0x1fU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_13__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_12) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                          >> 0xbU))));
    if (vlSelf->__PVT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_13__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq 
        = (0x3fU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_12__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_12) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                          >> 0xaU))));
    if (vlSelf->__PVT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_12__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq 
        = (0x7fU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_11__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_12) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                          >> 9U))));
    if (vlSelf->__PVT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_11__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq 
        = (0xffU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_10__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_12) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                          >> 8U))));
    if (vlSelf->__PVT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_10__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq 
        = (0x1ffU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_9__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_12) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                           >> 7U))));
    if (vlSelf->__PVT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_9__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq 
        = (((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_8__DOT__full)) 
            & (IData)(vlSelf->__PVT___GEN_4)) & (((IData)(1U) 
                                                  << 
                                                  (0xfU 
                                                   & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                                                 >> 0xfU));
    if (vlSelf->__PVT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_8__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq 
        = (3U & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_7__DOT__full)) 
                 & ((IData)(vlSelf->__PVT___GEN_4) 
                    & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                       >> 0xeU))));
    if (vlSelf->__PVT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_7__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq 
        = (7U & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_6__DOT__full)) 
                 & ((IData)(vlSelf->__PVT___GEN_4) 
                    & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                       >> 0xdU))));
    if (vlSelf->__PVT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_6__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq 
        = (0xfU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_5__DOT__full)) 
                   & ((IData)(vlSelf->__PVT___GEN_4) 
                      & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                         >> 0xcU))));
    if (vlSelf->__PVT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_5__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq 
        = (0x1fU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_4__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_4) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                          >> 0xbU))));
    if (vlSelf->__PVT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_4__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq 
        = (0x3fU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_3__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_4) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                          >> 0xaU))));
    if (vlSelf->__PVT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_3__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq 
        = (0x7fU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_2__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_4) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                          >> 9U))));
    if (vlSelf->__PVT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_2__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq 
        = (0xffU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_1__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_4) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                          >> 8U))));
    if (vlSelf->__PVT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_1__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq 
        = (0x1ffU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_4) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                           >> 7U))));
    if (vlSymsp->TOP.reset) {
        __Vdly__Queue17_BundleMap_13__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_12__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_11__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_10__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_9__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_8__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_7__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_6__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_5__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_4__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_3__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_2__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_1__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_13__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_13__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_12__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_12__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_11__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_11__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_10__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_10__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_9__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_9__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_8__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_8__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_7__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_7__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_6__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_6__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_5__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_5__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_4__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_4__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_3__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_3__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_2__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_2__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_1__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_1__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap__DOT__maybe_full = 0U;
        __Vdly__Queue1_BundleMap_17__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_16__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_15__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_14__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_13__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_12__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_11__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_10__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_9__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_8__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_7__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_6__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_5__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_4__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_3__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_2__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_1__DOT__full = 0U;
        __Vdly__Queue1_BundleMap__DOT__full = 0U;
    } else {
        if (vlSelf->__PVT__Queue17_BundleMap_13__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_13__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_12__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_12__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_11__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_11__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_10__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_10__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_9__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_9__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_8__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_8__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_7__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_7__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_6__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_6__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_5__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_5__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_4__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_4__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_3__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_3__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_2__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_2__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_1__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_1__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap__DOT__do_enq) {
            __Vdly__Queue17_BundleMap__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value))));
        }
        vlSelf->__PVT__Queue17_BundleMap_13__DOT__unnamedblk1__DOT__do_deq 
            = (0x3ffU & (((IData)(vlSelf->__PVT___GEN_11) 
                          & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                             >> 6U)) & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_13__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_13__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_13__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_13__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_12__DOT__unnamedblk1__DOT__do_deq 
            = (0x7ffU & (((IData)(vlSelf->__PVT___GEN_11) 
                          & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                             >> 5U)) & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_12__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_12__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_12__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_12__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_11__DOT__unnamedblk1__DOT__do_deq 
            = (0xfffU & (((IData)(vlSelf->__PVT___GEN_11) 
                          & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                             >> 4U)) & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_11__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_11__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_11__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_11__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_10__DOT__unnamedblk1__DOT__do_deq 
            = (0x1fffU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                              >> 3U)) & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_10__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_10__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_10__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_10__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_9__DOT__unnamedblk1__DOT__do_deq 
            = (0x3fffU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                              >> 2U)) & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_9__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_9__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_9__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_9__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_8__DOT__unnamedblk1__DOT__do_deq 
            = (0x7fffU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                              >> 1U)) & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_8__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_8__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_8__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_8__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_7__DOT__unnamedblk1__DOT__do_deq 
            = (((IData)(vlSelf->__PVT___GEN_11) & ((IData)(1U) 
                                                   << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid))) 
               & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__empty)));
        if (vlSelf->__PVT__Queue17_BundleMap_7__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_7__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_7__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_7__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_6__DOT__unnamedblk1__DOT__do_deq 
            = (0x3ffU & (((IData)(vlSelf->__PVT___GEN_3) 
                          & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                              >> 6U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                         & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_6__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_6__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_6__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_6__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_5__DOT__unnamedblk1__DOT__do_deq 
            = (0x7ffU & (((IData)(vlSelf->__PVT___GEN_3) 
                          & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                              >> 5U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                         & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_5__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_5__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_5__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_5__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_4__DOT__unnamedblk1__DOT__do_deq 
            = (0xfffU & (((IData)(vlSelf->__PVT___GEN_3) 
                          & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                              >> 4U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                         & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_4__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_4__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_4__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_4__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_3__DOT__unnamedblk1__DOT__do_deq 
            = (0x1fffU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                               >> 3U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                          & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_3__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_3__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_3__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_3__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_2__DOT__unnamedblk1__DOT__do_deq 
            = (0x3fffU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                               >> 2U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                          & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_2__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_2__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_2__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_2__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_1__DOT__unnamedblk1__DOT__do_deq 
            = (0x7fffU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                               >> 1U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                          & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_1__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_1__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_1__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_1__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap__DOT__unnamedblk1__DOT__do_deq 
            = (((IData)(vlSelf->__PVT___GEN_3) & (((IData)(1U) 
                                                   << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                                                  & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
               & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__empty)));
        if (vlSelf->__PVT__Queue17_BundleMap__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelf->__PVT___GEN_11) & (IData)(vlSelf->__PVT__Queue1_BundleMap_17__DOT__full)) 
                 & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                    >> 0xfU)))) {
            __Vdly__Queue1_BundleMap_17__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq) 
             != (3U & (((IData)(vlSelf->__PVT___GEN_11) 
                        & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                           >> 0xeU)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_16__DOT__full))))) {
            __Vdly__Queue1_BundleMap_16__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq) 
             != (7U & (((IData)(vlSelf->__PVT___GEN_11) 
                        & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                           >> 0xdU)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_15__DOT__full))))) {
            __Vdly__Queue1_BundleMap_15__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq) 
             != (0xfU & (((IData)(vlSelf->__PVT___GEN_11) 
                          & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                             >> 0xcU)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_14__DOT__full))))) {
            __Vdly__Queue1_BundleMap_14__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq) 
             != (0x1fU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                              >> 0xbU)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_13__DOT__full))))) {
            __Vdly__Queue1_BundleMap_13__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq) 
             != (0x3fU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                              >> 0xaU)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_12__DOT__full))))) {
            __Vdly__Queue1_BundleMap_12__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq) 
             != (0x7fU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                              >> 9U)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_11__DOT__full))))) {
            __Vdly__Queue1_BundleMap_11__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq) 
             != (0xffU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                              >> 8U)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_10__DOT__full))))) {
            __Vdly__Queue1_BundleMap_10__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq) 
             != (0x1ffU & (((IData)(vlSelf->__PVT___GEN_11) 
                            & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                               >> 7U)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_9__DOT__full))))) {
            __Vdly__Queue1_BundleMap_9__DOT__full = vlSelf->__PVT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq) 
             != ((((IData)(vlSelf->__PVT___GEN_3) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast)) 
                  & (IData)(vlSelf->__PVT__Queue1_BundleMap_8__DOT__full)) 
                 & (((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                    >> 0xfU)))) {
            __Vdly__Queue1_BundleMap_8__DOT__full = vlSelf->__PVT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq) 
             != (3U & (((IData)(vlSelf->__PVT___GEN_3) 
                        & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                            >> 0xeU) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                       & (IData)(vlSelf->__PVT__Queue1_BundleMap_7__DOT__full))))) {
            __Vdly__Queue1_BundleMap_7__DOT__full = vlSelf->__PVT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq) 
             != (7U & (((IData)(vlSelf->__PVT___GEN_3) 
                        & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                            >> 0xdU) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                       & (IData)(vlSelf->__PVT__Queue1_BundleMap_6__DOT__full))))) {
            __Vdly__Queue1_BundleMap_6__DOT__full = vlSelf->__PVT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq) 
             != (0xfU & (((IData)(vlSelf->__PVT___GEN_3) 
                          & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                              >> 0xcU) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                         & (IData)(vlSelf->__PVT__Queue1_BundleMap_5__DOT__full))))) {
            __Vdly__Queue1_BundleMap_5__DOT__full = vlSelf->__PVT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq) 
             != (0x1fU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                               >> 0xbU) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                          & (IData)(vlSelf->__PVT__Queue1_BundleMap_4__DOT__full))))) {
            __Vdly__Queue1_BundleMap_4__DOT__full = vlSelf->__PVT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq) 
             != (0x3fU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                               >> 0xaU) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                          & (IData)(vlSelf->__PVT__Queue1_BundleMap_3__DOT__full))))) {
            __Vdly__Queue1_BundleMap_3__DOT__full = vlSelf->__PVT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq) 
             != (0x7fU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                               >> 9U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                          & (IData)(vlSelf->__PVT__Queue1_BundleMap_2__DOT__full))))) {
            __Vdly__Queue1_BundleMap_2__DOT__full = vlSelf->__PVT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq) 
             != (0xffU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                               >> 8U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                          & (IData)(vlSelf->__PVT__Queue1_BundleMap_1__DOT__full))))) {
            __Vdly__Queue1_BundleMap_1__DOT__full = vlSelf->__PVT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq) 
             != (0x1ffU & (((IData)(vlSelf->__PVT___GEN_3) 
                            & ((((IData)(1U) << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                                >> 7U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rlast))) 
                           & (IData)(vlSelf->__PVT__Queue1_BundleMap__DOT__full))))) {
            __Vdly__Queue1_BundleMap__DOT__full = vlSelf->__PVT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq;
        }
    }
    if (vlSelf->__PVT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap__DOT__ram = 
            (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
              << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                         << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                         >> 4U))));
    }
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_13__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_12__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_11__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_10__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_9__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_8__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_7__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_6__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_5__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_4__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_3__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_2__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_1__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_13__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_12__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_11__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_10__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_9__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_8__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_7__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_6__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_5__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_4__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_3__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_2__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_1__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue1_BundleMap_17__DOT__full = __Vdly__Queue1_BundleMap_17__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_16__DOT__full = __Vdly__Queue1_BundleMap_16__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_15__DOT__full = __Vdly__Queue1_BundleMap_15__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_14__DOT__full = __Vdly__Queue1_BundleMap_14__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_13__DOT__full = __Vdly__Queue1_BundleMap_13__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_12__DOT__full = __Vdly__Queue1_BundleMap_12__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_11__DOT__full = __Vdly__Queue1_BundleMap_11__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_10__DOT__full = __Vdly__Queue1_BundleMap_10__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_9__DOT__full = __Vdly__Queue1_BundleMap_9__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_8__DOT__full = __Vdly__Queue1_BundleMap_8__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_7__DOT__full = __Vdly__Queue1_BundleMap_7__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_6__DOT__full = __Vdly__Queue1_BundleMap_6__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_5__DOT__full = __Vdly__Queue1_BundleMap_5__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_4__DOT__full = __Vdly__Queue1_BundleMap_4__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_3__DOT__full = __Vdly__Queue1_BundleMap_3__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_2__DOT__full = __Vdly__Queue1_BundleMap_2__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_1__DOT__full = __Vdly__Queue1_BundleMap_1__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap__DOT__full = __Vdly__Queue1_BundleMap__DOT__full;
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap__DOT__empty = 
        ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__maybe_full)) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap__DOT__full = ((IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__ptr_match) 
                                                   & (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__maybe_full));
}

VL_INLINE_OPT void VysyxSoCFull_AXI4UserYanker_1___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1__1(VysyxSoCFull_AXI4UserYanker_1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_AXI4UserYanker_1___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1__1\n"); );
    // Body
    vlSelf->__PVT___GEN_11 = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_bready) 
                              & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bvalid));
    vlSelf->__PVT___GEN_3 = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_rready) 
                             & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rvalid));
}

VL_INLINE_OPT void VysyxSoCFull_AXI4UserYanker_1___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1__0(VysyxSoCFull_AXI4UserYanker_1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_AXI4UserYanker_1___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1__0\n"); );
    // Body
    vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
            << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                       << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                       >> 4U))));
    vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
            << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                       << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid) 
                                       >> 4U))));
    vlSelf->__PVT___GEN_12 = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.__PVT___queue_arw_deq_q_io_deq_bits_wen) 
                               & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.__PVT__queue_arw_deq_q__DOT__io_deq_valid_0)) 
                              & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_awready));
    vlSelf->__PVT___GEN_4 = (((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.__PVT___queue_arw_deq_q_io_deq_bits_wen)) 
                              & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.__PVT__queue_arw_deq_q__DOT__io_deq_valid_0)) 
                             & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_arready));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__do_enq 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__full)) 
           & ((IData)(vlSelf->__PVT___GEN_12) & ((IData)(1U) 
                                                 << 
                                                 (0xfU 
                                                  & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid)))));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__do_enq 
        = (0x7fffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__full)) 
                      & ((IData)(vlSelf->__PVT___GEN_12) 
                         & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                            >> 1U))));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__do_enq 
        = (0x3fffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__full)) 
                      & ((IData)(vlSelf->__PVT___GEN_12) 
                         & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                            >> 2U))));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__do_enq 
        = (0x1fffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__full)) 
                      & ((IData)(vlSelf->__PVT___GEN_12) 
                         & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                            >> 3U))));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__do_enq 
        = (0xfffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_12) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                           >> 4U))));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__do_enq 
        = (0x7ffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_12) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                           >> 5U))));
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__do_enq 
        = (0x3ffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_12) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                           >> 6U))));
    vlSelf->__PVT__Queue17_BundleMap__DOT__do_enq = 
        ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__full)) 
         & ((IData)(vlSelf->__PVT___GEN_4) & ((IData)(1U) 
                                              << (0xfU 
                                                  & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid)))));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__do_enq 
        = (0x7fffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__full)) 
                      & ((IData)(vlSelf->__PVT___GEN_4) 
                         & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                            >> 1U))));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__do_enq 
        = (0x3fffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__full)) 
                      & ((IData)(vlSelf->__PVT___GEN_4) 
                         & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                            >> 2U))));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__do_enq 
        = (0x1fffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__full)) 
                      & ((IData)(vlSelf->__PVT___GEN_4) 
                         & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                            >> 3U))));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__do_enq 
        = (0xfffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_4) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                           >> 4U))));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__do_enq 
        = (0x7ffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_4) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                           >> 5U))));
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__do_enq 
        = (0x3ffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_4) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4.auto_out_awid))) 
                           >> 6U))));
}

VL_INLINE_OPT void VysyxSoCFull_AXI4UserYanker_1___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank__0(VysyxSoCFull_AXI4UserYanker_1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_AXI4UserYanker_1___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank__0\n"); );
    // Init
    SData/*15:0*/ __PVT__unnamedblk1__DOT___GEN_6;
    __PVT__unnamedblk1__DOT___GEN_6 = 0;
    SData/*15:0*/ __PVT__unnamedblk1__DOT___GEN_7;
    __PVT__unnamedblk1__DOT___GEN_7 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_1__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_1__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_1__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_1__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_2__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_2__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_2__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_2__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_3__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_3__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_3__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_3__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_4__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_4__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_4__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_4__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_5__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_5__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_5__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_5__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_6__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_6__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_6__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_6__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap__DOT__full;
    __Vdly__Queue1_BundleMap__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_1__DOT__full;
    __Vdly__Queue1_BundleMap_1__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_2__DOT__full;
    __Vdly__Queue1_BundleMap_2__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_3__DOT__full;
    __Vdly__Queue1_BundleMap_3__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_4__DOT__full;
    __Vdly__Queue1_BundleMap_4__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_5__DOT__full;
    __Vdly__Queue1_BundleMap_5__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_6__DOT__full;
    __Vdly__Queue1_BundleMap_6__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_7__DOT__full;
    __Vdly__Queue1_BundleMap_7__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_8__DOT__full;
    __Vdly__Queue1_BundleMap_8__DOT__full = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_7__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_7__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_7__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_7__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_8__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_8__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_8__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_8__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_9__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_9__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_9__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_9__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_10__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_10__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_10__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_10__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_11__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_11__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_11__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_11__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_12__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_12__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_12__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_12__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_13__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_13__DOT__enq_ptr_value = 0;
    CData/*4:0*/ __Vdly__Queue17_BundleMap_13__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_13__DOT__deq_ptr_value = 0;
    CData/*4:0*/ __Vdlyvdim0__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvdim0__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 = 0;
    SData/*11:0*/ __Vdlyvval__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvval__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0;
    __Vdlyvset__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_9__DOT__full;
    __Vdly__Queue1_BundleMap_9__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_10__DOT__full;
    __Vdly__Queue1_BundleMap_10__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_11__DOT__full;
    __Vdly__Queue1_BundleMap_11__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_12__DOT__full;
    __Vdly__Queue1_BundleMap_12__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_13__DOT__full;
    __Vdly__Queue1_BundleMap_13__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_14__DOT__full;
    __Vdly__Queue1_BundleMap_14__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_15__DOT__full;
    __Vdly__Queue1_BundleMap_15__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_16__DOT__full;
    __Vdly__Queue1_BundleMap_16__DOT__full = 0;
    CData/*0:0*/ __Vdly__Queue1_BundleMap_17__DOT__full;
    __Vdly__Queue1_BundleMap_17__DOT__full = 0;
    // Body
    __Vdly__Queue17_BundleMap_6__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_5__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_4__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_3__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_2__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_1__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap__DOT__enq_ptr_value = vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_13__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_12__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_11__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_10__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_9__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_8__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value;
    __Vdly__Queue17_BundleMap_7__DOT__enq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value;
    __Vdlyvset__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdlyvset__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdly__Queue1_BundleMap_8__DOT__full = vlSelf->__PVT__Queue1_BundleMap_8__DOT__full;
    __Vdly__Queue1_BundleMap_7__DOT__full = vlSelf->__PVT__Queue1_BundleMap_7__DOT__full;
    __Vdly__Queue1_BundleMap_6__DOT__full = vlSelf->__PVT__Queue1_BundleMap_6__DOT__full;
    __Vdly__Queue1_BundleMap_5__DOT__full = vlSelf->__PVT__Queue1_BundleMap_5__DOT__full;
    __Vdly__Queue1_BundleMap_4__DOT__full = vlSelf->__PVT__Queue1_BundleMap_4__DOT__full;
    __Vdly__Queue1_BundleMap_3__DOT__full = vlSelf->__PVT__Queue1_BundleMap_3__DOT__full;
    __Vdly__Queue1_BundleMap_2__DOT__full = vlSelf->__PVT__Queue1_BundleMap_2__DOT__full;
    __Vdly__Queue1_BundleMap_1__DOT__full = vlSelf->__PVT__Queue1_BundleMap_1__DOT__full;
    __Vdly__Queue1_BundleMap__DOT__full = vlSelf->__PVT__Queue1_BundleMap__DOT__full;
    __Vdly__Queue17_BundleMap_6__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_5__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_4__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_3__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_2__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_1__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap__DOT__deq_ptr_value = vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value;
    __Vdly__Queue1_BundleMap_17__DOT__full = vlSelf->__PVT__Queue1_BundleMap_17__DOT__full;
    __Vdly__Queue1_BundleMap_16__DOT__full = vlSelf->__PVT__Queue1_BundleMap_16__DOT__full;
    __Vdly__Queue1_BundleMap_15__DOT__full = vlSelf->__PVT__Queue1_BundleMap_15__DOT__full;
    __Vdly__Queue1_BundleMap_14__DOT__full = vlSelf->__PVT__Queue1_BundleMap_14__DOT__full;
    __Vdly__Queue1_BundleMap_13__DOT__full = vlSelf->__PVT__Queue1_BundleMap_13__DOT__full;
    __Vdly__Queue1_BundleMap_12__DOT__full = vlSelf->__PVT__Queue1_BundleMap_12__DOT__full;
    __Vdly__Queue1_BundleMap_11__DOT__full = vlSelf->__PVT__Queue1_BundleMap_11__DOT__full;
    __Vdly__Queue1_BundleMap_10__DOT__full = vlSelf->__PVT__Queue1_BundleMap_10__DOT__full;
    __Vdly__Queue1_BundleMap_9__DOT__full = vlSelf->__PVT__Queue1_BundleMap_9__DOT__full;
    __Vdly__Queue17_BundleMap_13__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_12__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_11__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_10__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_9__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_8__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value;
    __Vdly__Queue17_BundleMap_7__DOT__deq_ptr_value 
        = vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value;
    __PVT__unnamedblk1__DOT___GEN_6 = (((IData)(vlSelf->__PVT__Queue1_BundleMap_8__DOT__full) 
                                        << 0xfU) | 
                                       (((IData)(vlSelf->__PVT__Queue1_BundleMap_7__DOT__full) 
                                         << 0xeU) | 
                                        (((IData)(vlSelf->__PVT__Queue1_BundleMap_6__DOT__full) 
                                          << 0xdU) 
                                         | (((IData)(vlSelf->__PVT__Queue1_BundleMap_5__DOT__full) 
                                             << 0xcU) 
                                            | (((IData)(vlSelf->__PVT__Queue1_BundleMap_4__DOT__full) 
                                                << 0xbU) 
                                               | (((IData)(vlSelf->__PVT__Queue1_BundleMap_3__DOT__full) 
                                                   << 0xaU) 
                                                  | (((IData)(vlSelf->__PVT__Queue1_BundleMap_2__DOT__full) 
                                                      << 9U) 
                                                     | (((IData)(vlSelf->__PVT__Queue1_BundleMap_1__DOT__full) 
                                                         << 8U) 
                                                        | (((IData)(vlSelf->__PVT__Queue1_BundleMap__DOT__full) 
                                                            << 7U) 
                                                           | ((0x40U 
                                                               & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__empty)) 
                                                                  << 6U)) 
                                                              | ((0x20U 
                                                                  & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__empty)) 
                                                                     << 5U)) 
                                                                 | ((0x10U 
                                                                     & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__empty)) 
                                                                        << 4U)) 
                                                                    | ((8U 
                                                                        & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__empty)) 
                                                                           << 3U)) 
                                                                       | ((4U 
                                                                           & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__empty)) 
                                                                              << 2U)) 
                                                                          | ((2U 
                                                                              & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__empty)) 
                                                                                << 1U)) 
                                                                             | (1U 
                                                                                & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__empty))))))))))))))))));
    __PVT__unnamedblk1__DOT___GEN_7 = (((IData)(vlSelf->__PVT__Queue1_BundleMap_17__DOT__full) 
                                        << 0xfU) | 
                                       (((IData)(vlSelf->__PVT__Queue1_BundleMap_16__DOT__full) 
                                         << 0xeU) | 
                                        (((IData)(vlSelf->__PVT__Queue1_BundleMap_15__DOT__full) 
                                          << 0xdU) 
                                         | (((IData)(vlSelf->__PVT__Queue1_BundleMap_14__DOT__full) 
                                             << 0xcU) 
                                            | (((IData)(vlSelf->__PVT__Queue1_BundleMap_13__DOT__full) 
                                                << 0xbU) 
                                               | (((IData)(vlSelf->__PVT__Queue1_BundleMap_12__DOT__full) 
                                                   << 0xaU) 
                                                  | (((IData)(vlSelf->__PVT__Queue1_BundleMap_11__DOT__full) 
                                                      << 9U) 
                                                     | (((IData)(vlSelf->__PVT__Queue1_BundleMap_10__DOT__full) 
                                                         << 8U) 
                                                        | (((IData)(vlSelf->__PVT__Queue1_BundleMap_9__DOT__full) 
                                                            << 7U) 
                                                           | ((0x40U 
                                                               & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__empty)) 
                                                                  << 6U)) 
                                                              | ((0x20U 
                                                                  & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__empty)) 
                                                                     << 5U)) 
                                                                 | ((0x10U 
                                                                     & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__empty)) 
                                                                        << 4U)) 
                                                                    | ((8U 
                                                                        & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__empty)) 
                                                                           << 3U)) 
                                                                       | ((4U 
                                                                           & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__empty)) 
                                                                              << 2U)) 
                                                                          | ((2U 
                                                                              & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__empty)) 
                                                                                << 1U)) 
                                                                             | (1U 
                                                                                & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__empty))))))))))))))))));
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__empty) 
                                 | ((IData)(__PVT__unnamedblk1__DOT___GEN_6) 
                                    >> (0xfU & (IData)(
                                                       (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                        >> 0x24U)))))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:18185: Assertion failed in %NysyxSoCFull.fpga.axi4yank.unnamedblk1: Assertion failed at UserYanker.scala:69\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 18185, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:18187: Assertion failed in %NysyxSoCFull.fpga.axi4yank.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 18187, "");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSymsp->TOP.reset)) 
                           & (~ ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_bvalid)) 
                                 | ((IData)(__PVT__unnamedblk1__DOT___GEN_7) 
                                    >> (0xfU & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                >> 3U))))))))) {
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:18191: Assertion failed in %NysyxSoCFull.fpga.axi4yank.unnamedblk1: Assertion failed at UserYanker.scala:98\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 18191, "");
        VL_WRITEF("[%0t] %%Error: ysyxSoCFull.v:18193: Assertion failed in %NysyxSoCFull.fpga.axi4yank.unnamedblk1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("/home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v", 18193, "");
    }
    if (vlSelf->__PVT__Queue17_BundleMap_6__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_6__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_6__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_5__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_5__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_5__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_4__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_4__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_4__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_3__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_3__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_3__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_2__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_2__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_2__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_1__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_1__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_1__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap__DOT__do_enq) {
        vlSelf->Queue17_BundleMap__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_13__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_13__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_13__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_12__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_12__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_12__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_11__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_11__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_11__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_10__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_10__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_10__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_9__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_9__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_9__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_8__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_8__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_8__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value;
        }
    }
    if (vlSelf->__PVT__Queue17_BundleMap_7__DOT__do_enq) {
        vlSelf->Queue17_BundleMap_7__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 
            = vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data;
        if ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value))) {
            __Vdlyvval__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->Queue17_BundleMap_7__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0;
            __Vdlyvset__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 = 1U;
            __Vdlyvdim0__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0 
                = vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value;
        }
    }
    vlSelf->__PVT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq 
        = (((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_8__DOT__full)) 
            & (IData)(vlSelf->__PVT___GEN_4)) & (((IData)(1U) 
                                                  << 
                                                  (0xfU 
                                                   & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                                                 >> 0xfU));
    if (vlSelf->__PVT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_8__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq 
        = (3U & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_7__DOT__full)) 
                 & ((IData)(vlSelf->__PVT___GEN_4) 
                    & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                       >> 0xeU))));
    if (vlSelf->__PVT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_7__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq 
        = (7U & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_6__DOT__full)) 
                 & ((IData)(vlSelf->__PVT___GEN_4) 
                    & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                       >> 0xdU))));
    if (vlSelf->__PVT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_6__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq 
        = (0xfU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_5__DOT__full)) 
                   & ((IData)(vlSelf->__PVT___GEN_4) 
                      & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                         >> 0xcU))));
    if (vlSelf->__PVT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_5__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq 
        = (0x1fU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_4__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_4) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                          >> 0xbU))));
    if (vlSelf->__PVT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_4__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq 
        = (0x3fU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_3__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_4) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                          >> 0xaU))));
    if (vlSelf->__PVT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_3__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq 
        = (0x7fU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_2__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_4) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                          >> 9U))));
    if (vlSelf->__PVT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_2__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq 
        = (0xffU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_1__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_4) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                          >> 8U))));
    if (vlSelf->__PVT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_1__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq 
        = (0x1ffU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_4) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                           >> 7U))));
    if (vlSelf->__PVT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap__DOT__ram = 
            (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
              << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                         << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                         >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq 
        = (((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_17__DOT__full)) 
            & (IData)(vlSelf->__PVT___GEN_12)) & (((IData)(1U) 
                                                   << 
                                                   (0xfU 
                                                    & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                                                  >> 0xfU));
    if (vlSelf->__PVT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_17__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq 
        = (3U & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_16__DOT__full)) 
                 & ((IData)(vlSelf->__PVT___GEN_12) 
                    & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                       >> 0xeU))));
    if (vlSelf->__PVT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_16__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq 
        = (7U & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_15__DOT__full)) 
                 & ((IData)(vlSelf->__PVT___GEN_12) 
                    & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                       >> 0xdU))));
    if (vlSelf->__PVT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_15__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq 
        = (0xfU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_14__DOT__full)) 
                   & ((IData)(vlSelf->__PVT___GEN_12) 
                      & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                         >> 0xcU))));
    if (vlSelf->__PVT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_14__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq 
        = (0x1fU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_13__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_12) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                          >> 0xbU))));
    if (vlSelf->__PVT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_13__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq 
        = (0x3fU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_12__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_12) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                          >> 0xaU))));
    if (vlSelf->__PVT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_12__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq 
        = (0x7fU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_11__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_12) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                          >> 9U))));
    if (vlSelf->__PVT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_11__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq 
        = (0xffU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_10__DOT__full)) 
                    & ((IData)(vlSelf->__PVT___GEN_12) 
                       & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                          >> 8U))));
    if (vlSelf->__PVT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_10__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq 
        = (0x1ffU & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_9__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_12) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                           >> 7U))));
    if (vlSymsp->TOP.reset) {
        __Vdly__Queue17_BundleMap_6__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_5__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_4__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_3__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_2__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_1__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_13__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_12__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_11__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_10__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_9__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_8__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_7__DOT__enq_ptr_value = 0U;
        __Vdly__Queue17_BundleMap_6__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_6__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_5__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_5__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_4__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_4__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_3__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_3__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_2__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_2__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_1__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_1__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap__DOT__maybe_full = 0U;
        __Vdly__Queue1_BundleMap_8__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_7__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_6__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_5__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_4__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_3__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_2__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_1__DOT__full = 0U;
        __Vdly__Queue1_BundleMap__DOT__full = 0U;
        __Vdly__Queue17_BundleMap_13__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_13__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_12__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_12__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_11__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_11__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_10__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_10__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_9__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_9__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_8__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_8__DOT__maybe_full = 0U;
        __Vdly__Queue17_BundleMap_7__DOT__deq_ptr_value = 0U;
        vlSelf->__PVT__Queue17_BundleMap_7__DOT__maybe_full = 0U;
        __Vdly__Queue1_BundleMap_17__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_16__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_15__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_14__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_13__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_12__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_11__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_10__DOT__full = 0U;
        __Vdly__Queue1_BundleMap_9__DOT__full = 0U;
    } else {
        if (vlSelf->__PVT__Queue17_BundleMap_6__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_6__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_5__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_5__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_4__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_4__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_3__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_3__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_2__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_2__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_1__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_1__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap__DOT__do_enq) {
            __Vdly__Queue17_BundleMap__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_13__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_13__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_12__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_12__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_11__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_11__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_10__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_10__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_9__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_9__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_8__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_8__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value))));
        }
        if (vlSelf->__PVT__Queue17_BundleMap_7__DOT__do_enq) {
            __Vdly__Queue17_BundleMap_7__DOT__enq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value))));
        }
        vlSelf->__PVT__Queue17_BundleMap_6__DOT__unnamedblk1__DOT__do_deq 
            = (0x3ffU & (((IData)(vlSelf->__PVT___GEN_3) 
                          & ((((IData)(1U) << (0xfU 
                                               & (IData)(
                                                         (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                          >> 0x24U)))) 
                              >> 6U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                         & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_6__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_6__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_6__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_6__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_5__DOT__unnamedblk1__DOT__do_deq 
            = (0x7ffU & (((IData)(vlSelf->__PVT___GEN_3) 
                          & ((((IData)(1U) << (0xfU 
                                               & (IData)(
                                                         (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                          >> 0x24U)))) 
                              >> 5U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                         & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_5__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_5__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_5__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_5__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_4__DOT__unnamedblk1__DOT__do_deq 
            = (0xfffU & (((IData)(vlSelf->__PVT___GEN_3) 
                          & ((((IData)(1U) << (0xfU 
                                               & (IData)(
                                                         (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                          >> 0x24U)))) 
                              >> 4U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                         & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_4__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_4__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_4__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_4__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_3__DOT__unnamedblk1__DOT__do_deq 
            = (0x1fffU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (0xfU 
                                                & (IData)(
                                                          (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                           >> 0x24U)))) 
                               >> 3U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                          & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_3__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_3__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_3__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_3__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_2__DOT__unnamedblk1__DOT__do_deq 
            = (0x3fffU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (0xfU 
                                                & (IData)(
                                                          (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                           >> 0x24U)))) 
                               >> 2U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                          & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_2__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_2__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_2__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_2__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_1__DOT__unnamedblk1__DOT__do_deq 
            = (0x7fffU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (0xfU 
                                                & (IData)(
                                                          (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                           >> 0x24U)))) 
                               >> 1U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                          & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_1__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_1__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_1__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_1__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap__DOT__unnamedblk1__DOT__do_deq 
            = (((IData)(vlSelf->__PVT___GEN_3) & (((IData)(1U) 
                                                   << 
                                                   (0xfU 
                                                    & (IData)(
                                                              (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                               >> 0x24U)))) 
                                                  & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
               & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__empty)));
        if (vlSelf->__PVT__Queue17_BundleMap__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq) 
             != ((((IData)(vlSelf->__PVT___GEN_3) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast)) 
                  & (IData)(vlSelf->__PVT__Queue1_BundleMap_8__DOT__full)) 
                 & (((IData)(1U) << (0xfU & (IData)(
                                                    (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                     >> 0x24U)))) 
                    >> 0xfU)))) {
            __Vdly__Queue1_BundleMap_8__DOT__full = vlSelf->__PVT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq) 
             != (3U & (((IData)(vlSelf->__PVT___GEN_3) 
                        & ((((IData)(1U) << (0xfU & (IData)(
                                                            (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                             >> 0x24U)))) 
                            >> 0xeU) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                       & (IData)(vlSelf->__PVT__Queue1_BundleMap_7__DOT__full))))) {
            __Vdly__Queue1_BundleMap_7__DOT__full = vlSelf->__PVT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq) 
             != (7U & (((IData)(vlSelf->__PVT___GEN_3) 
                        & ((((IData)(1U) << (0xfU & (IData)(
                                                            (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                             >> 0x24U)))) 
                            >> 0xdU) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                       & (IData)(vlSelf->__PVT__Queue1_BundleMap_6__DOT__full))))) {
            __Vdly__Queue1_BundleMap_6__DOT__full = vlSelf->__PVT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq) 
             != (0xfU & (((IData)(vlSelf->__PVT___GEN_3) 
                          & ((((IData)(1U) << (0xfU 
                                               & (IData)(
                                                         (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                          >> 0x24U)))) 
                              >> 0xcU) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                         & (IData)(vlSelf->__PVT__Queue1_BundleMap_5__DOT__full))))) {
            __Vdly__Queue1_BundleMap_5__DOT__full = vlSelf->__PVT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq) 
             != (0x1fU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (0xfU 
                                                & (IData)(
                                                          (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                           >> 0x24U)))) 
                               >> 0xbU) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                          & (IData)(vlSelf->__PVT__Queue1_BundleMap_4__DOT__full))))) {
            __Vdly__Queue1_BundleMap_4__DOT__full = vlSelf->__PVT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq) 
             != (0x3fU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (0xfU 
                                                & (IData)(
                                                          (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                           >> 0x24U)))) 
                               >> 0xaU) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                          & (IData)(vlSelf->__PVT__Queue1_BundleMap_3__DOT__full))))) {
            __Vdly__Queue1_BundleMap_3__DOT__full = vlSelf->__PVT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq) 
             != (0x7fU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (0xfU 
                                                & (IData)(
                                                          (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                           >> 0x24U)))) 
                               >> 9U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                          & (IData)(vlSelf->__PVT__Queue1_BundleMap_2__DOT__full))))) {
            __Vdly__Queue1_BundleMap_2__DOT__full = vlSelf->__PVT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq) 
             != (0xffU & (((IData)(vlSelf->__PVT___GEN_3) 
                           & ((((IData)(1U) << (0xfU 
                                                & (IData)(
                                                          (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                           >> 0x24U)))) 
                               >> 8U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                          & (IData)(vlSelf->__PVT__Queue1_BundleMap_1__DOT__full))))) {
            __Vdly__Queue1_BundleMap_1__DOT__full = vlSelf->__PVT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq) 
             != (0x1ffU & (((IData)(vlSelf->__PVT___GEN_3) 
                            & ((((IData)(1U) << (0xfU 
                                                 & (IData)(
                                                           (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                            >> 0x24U)))) 
                                >> 7U) & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast))) 
                           & (IData)(vlSelf->__PVT__Queue1_BundleMap__DOT__full))))) {
            __Vdly__Queue1_BundleMap__DOT__full = vlSelf->__PVT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_13__DOT__unnamedblk1__DOT__do_deq 
            = (0x3ffU & (((IData)(vlSelf->__PVT___GEN_11) 
                          & (((IData)(1U) << (0xfU 
                                              & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                 >> 3U))) 
                             >> 6U)) & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_13__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_13__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_13__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_13__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_12__DOT__unnamedblk1__DOT__do_deq 
            = (0x7ffU & (((IData)(vlSelf->__PVT___GEN_11) 
                          & (((IData)(1U) << (0xfU 
                                              & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                 >> 3U))) 
                             >> 5U)) & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_12__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_12__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_12__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_12__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_11__DOT__unnamedblk1__DOT__do_deq 
            = (0xfffU & (((IData)(vlSelf->__PVT___GEN_11) 
                          & (((IData)(1U) << (0xfU 
                                              & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                 >> 3U))) 
                             >> 4U)) & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_11__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_11__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_11__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_11__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_10__DOT__unnamedblk1__DOT__do_deq 
            = (0x1fffU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (0xfU 
                                               & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                  >> 3U))) 
                              >> 3U)) & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_10__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_10__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_10__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_10__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_9__DOT__unnamedblk1__DOT__do_deq 
            = (0x3fffU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (0xfU 
                                               & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                  >> 3U))) 
                              >> 2U)) & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_9__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_9__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_9__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_9__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_8__DOT__unnamedblk1__DOT__do_deq 
            = (0x7fffU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (0xfU 
                                               & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                  >> 3U))) 
                              >> 1U)) & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__empty))));
        if (vlSelf->__PVT__Queue17_BundleMap_8__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_8__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_8__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_8__DOT__do_enq;
        }
        vlSelf->__PVT__Queue17_BundleMap_7__DOT__unnamedblk1__DOT__do_deq 
            = (((IData)(vlSelf->__PVT___GEN_11) & ((IData)(1U) 
                                                   << 
                                                   (0xfU 
                                                    & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                       >> 3U)))) 
               & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__empty)));
        if (vlSelf->__PVT__Queue17_BundleMap_7__DOT__unnamedblk1__DOT__do_deq) {
            __Vdly__Queue17_BundleMap_7__DOT__deq_ptr_value 
                = ((0x10U == (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value))
                    ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value))));
        }
        if (((IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__do_enq) 
             != (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__unnamedblk1__DOT__do_deq))) {
            vlSelf->__PVT__Queue17_BundleMap_7__DOT__maybe_full 
                = vlSelf->__PVT__Queue17_BundleMap_7__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelf->__PVT___GEN_11) & (IData)(vlSelf->__PVT__Queue1_BundleMap_17__DOT__full)) 
                 & (((IData)(1U) << (0xfU & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                             >> 3U))) 
                    >> 0xfU)))) {
            __Vdly__Queue1_BundleMap_17__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq) 
             != (3U & (((IData)(vlSelf->__PVT___GEN_11) 
                        & (((IData)(1U) << (0xfU & 
                                            ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                             >> 3U))) 
                           >> 0xeU)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_16__DOT__full))))) {
            __Vdly__Queue1_BundleMap_16__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq) 
             != (7U & (((IData)(vlSelf->__PVT___GEN_11) 
                        & (((IData)(1U) << (0xfU & 
                                            ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                             >> 3U))) 
                           >> 0xdU)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_15__DOT__full))))) {
            __Vdly__Queue1_BundleMap_15__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq) 
             != (0xfU & (((IData)(vlSelf->__PVT___GEN_11) 
                          & (((IData)(1U) << (0xfU 
                                              & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                 >> 3U))) 
                             >> 0xcU)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_14__DOT__full))))) {
            __Vdly__Queue1_BundleMap_14__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq) 
             != (0x1fU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (0xfU 
                                               & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                  >> 3U))) 
                              >> 0xbU)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_13__DOT__full))))) {
            __Vdly__Queue1_BundleMap_13__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq) 
             != (0x3fU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (0xfU 
                                               & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                  >> 3U))) 
                              >> 0xaU)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_12__DOT__full))))) {
            __Vdly__Queue1_BundleMap_12__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq) 
             != (0x7fU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (0xfU 
                                               & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                  >> 3U))) 
                              >> 9U)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_11__DOT__full))))) {
            __Vdly__Queue1_BundleMap_11__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq) 
             != (0xffU & (((IData)(vlSelf->__PVT___GEN_11) 
                           & (((IData)(1U) << (0xfU 
                                               & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                  >> 3U))) 
                              >> 8U)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_10__DOT__full))))) {
            __Vdly__Queue1_BundleMap_10__DOT__full 
                = vlSelf->__PVT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelf->__PVT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq) 
             != (0x1ffU & (((IData)(vlSelf->__PVT___GEN_11) 
                            & (((IData)(1U) << (0xfU 
                                                & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                   >> 3U))) 
                               >> 7U)) & (IData)(vlSelf->__PVT__Queue1_BundleMap_9__DOT__full))))) {
            __Vdly__Queue1_BundleMap_9__DOT__full = vlSelf->__PVT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq;
        }
    }
    if (vlSelf->__PVT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq) {
        vlSelf->__PVT__Queue1_BundleMap_9__DOT__ram 
            = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
                << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                           << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                           >> 4U))));
    }
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_6__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_5__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_4__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_3__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_2__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_1__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_13__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_12__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_11__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_10__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_9__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_8__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value 
        = __Vdly__Queue17_BundleMap_7__DOT__enq_ptr_value;
    if (__Vdlyvset__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->__PVT__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory[__Vdlyvdim0__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0] 
            = __Vdlyvval__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_6__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_5__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_4__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_3__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_2__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_1__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue1_BundleMap_8__DOT__full = __Vdly__Queue1_BundleMap_8__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_7__DOT__full = __Vdly__Queue1_BundleMap_7__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_6__DOT__full = __Vdly__Queue1_BundleMap_6__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_5__DOT__full = __Vdly__Queue1_BundleMap_5__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_4__DOT__full = __Vdly__Queue1_BundleMap_4__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_3__DOT__full = __Vdly__Queue1_BundleMap_3__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_2__DOT__full = __Vdly__Queue1_BundleMap_2__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_1__DOT__full = __Vdly__Queue1_BundleMap_1__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap__DOT__full = __Vdly__Queue1_BundleMap__DOT__full;
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_13__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_12__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_11__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_10__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_9__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_8__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value 
        = __Vdly__Queue17_BundleMap_7__DOT__deq_ptr_value;
    vlSelf->__PVT__Queue1_BundleMap_17__DOT__full = __Vdly__Queue1_BundleMap_17__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_16__DOT__full = __Vdly__Queue1_BundleMap_16__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_15__DOT__full = __Vdly__Queue1_BundleMap_15__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_14__DOT__full = __Vdly__Queue1_BundleMap_14__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_13__DOT__full = __Vdly__Queue1_BundleMap_13__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_12__DOT__full = __Vdly__Queue1_BundleMap_12__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_11__DOT__full = __Vdly__Queue1_BundleMap_11__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_10__DOT__full = __Vdly__Queue1_BundleMap_10__DOT__full;
    vlSelf->__PVT__Queue1_BundleMap_9__DOT__full = __Vdly__Queue1_BundleMap_9__DOT__full;
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap__DOT__empty = 
        ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__maybe_full)) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap__DOT__full = ((IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__ptr_match) 
                                                   & (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__maybe_full));
}

VL_INLINE_OPT void VysyxSoCFull_AXI4UserYanker_1___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank__1(VysyxSoCFull_AXI4UserYanker_1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_AXI4UserYanker_1___nba_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank__1\n"); );
    // Body
    vlSelf->__PVT___GEN_3 = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_rready) 
                             & (~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__empty)));
    vlSelf->__PVT___GEN_11 = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_bready) 
                              & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_bvalid));
}

VL_INLINE_OPT void VysyxSoCFull_AXI4UserYanker_1___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank__0(VysyxSoCFull_AXI4UserYanker_1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_AXI4UserYanker_1___nba_comb__TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank__0\n"); );
    // Body
    vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
            << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                       << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                       >> 4U))));
    vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data 
        = (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_size) 
            << 8U) | (((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awecho_tl_state_source) 
                       << 1U) | (1U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid) 
                                       >> 4U))));
    vlSelf->__VdfgTmp_h6bd82316__0 = (1U & (((0x8000U 
                                              & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_8__DOT__full)) 
                                                 << 0xfU)) 
                                             | ((0x4000U 
                                                 & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_7__DOT__full)) 
                                                    << 0xeU)) 
                                                | ((0x2000U 
                                                    & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_6__DOT__full)) 
                                                       << 0xdU)) 
                                                   | ((0x1000U 
                                                       & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_5__DOT__full)) 
                                                          << 0xcU)) 
                                                      | ((0x800U 
                                                          & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_4__DOT__full)) 
                                                             << 0xbU)) 
                                                         | ((0x400U 
                                                             & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_3__DOT__full)) 
                                                                << 0xaU)) 
                                                            | ((0x200U 
                                                                & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_2__DOT__full)) 
                                                                   << 9U)) 
                                                               | ((0x100U 
                                                                   & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_1__DOT__full)) 
                                                                      << 8U)) 
                                                                  | ((0x80U 
                                                                      & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap__DOT__full)) 
                                                                         << 7U)) 
                                                                     | ((0x40U 
                                                                         & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__full)) 
                                                                            << 6U)) 
                                                                        | ((0x20U 
                                                                            & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__full)) 
                                                                               << 5U)) 
                                                                           | ((0x10U 
                                                                               & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__full)) 
                                                                                << 4U)) 
                                                                              | ((8U 
                                                                                & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__full)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__full)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__full)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__full)))))))))))))))))) 
                                            >> (0xfU 
                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))));
    vlSelf->__VdfgTmp_h3deb4dd1__0 = (1U & (((0x8000U 
                                              & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_17__DOT__full)) 
                                                 << 0xfU)) 
                                             | ((0x4000U 
                                                 & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_16__DOT__full)) 
                                                    << 0xeU)) 
                                                | ((0x2000U 
                                                    & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_15__DOT__full)) 
                                                       << 0xdU)) 
                                                   | ((0x1000U 
                                                       & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_14__DOT__full)) 
                                                          << 0xcU)) 
                                                      | ((0x800U 
                                                          & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_13__DOT__full)) 
                                                             << 0xbU)) 
                                                         | ((0x400U 
                                                             & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_12__DOT__full)) 
                                                                << 0xaU)) 
                                                            | ((0x200U 
                                                                & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_11__DOT__full)) 
                                                                   << 9U)) 
                                                               | ((0x100U 
                                                                   & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_10__DOT__full)) 
                                                                      << 8U)) 
                                                                  | ((0x80U 
                                                                      & ((~ (IData)(vlSelf->__PVT__Queue1_BundleMap_9__DOT__full)) 
                                                                         << 7U)) 
                                                                     | ((0x40U 
                                                                         & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__full)) 
                                                                            << 6U)) 
                                                                        | ((0x20U 
                                                                            & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__full)) 
                                                                               << 5U)) 
                                                                           | ((0x10U 
                                                                               & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__full)) 
                                                                                << 4U)) 
                                                                              | ((8U 
                                                                                & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__full)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__full)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__full)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__full)))))))))))))))))) 
                                            >> (0xfU 
                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))));
    vlSelf->__PVT___GEN_4 = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_arvalid) 
                             & (~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__deq_q__DOT__full)));
    vlSelf->__PVT___GEN_12 = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awvalid) 
                              & (~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__deq_q_1__DOT__full)));
    vlSelf->auto_out_arvalid = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_arvalid) 
                                & (IData)(vlSelf->__VdfgTmp_h6bd82316__0));
    vlSelf->auto_out_awvalid = ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awvalid) 
                                & (IData)(vlSelf->__VdfgTmp_h3deb4dd1__0));
    vlSelf->__PVT__Queue17_BundleMap__DOT__do_enq = 
        ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__full)) 
         & ((IData)(vlSelf->__PVT___GEN_4) & ((IData)(1U) 
                                              << (0xfU 
                                                  & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid)))));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__do_enq 
        = (0x7fffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__full)) 
                      & ((IData)(vlSelf->__PVT___GEN_4) 
                         & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                            >> 1U))));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__do_enq 
        = (0x3fffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__full)) 
                      & ((IData)(vlSelf->__PVT___GEN_4) 
                         & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                            >> 2U))));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__do_enq 
        = (0x1fffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__full)) 
                      & ((IData)(vlSelf->__PVT___GEN_4) 
                         & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                            >> 3U))));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__do_enq 
        = (0xfffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_4) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                           >> 4U))));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__do_enq 
        = (0x7ffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_4) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                           >> 5U))));
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__do_enq 
        = (0x3ffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_4) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                           >> 6U))));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__do_enq 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__full)) 
           & ((IData)(vlSelf->__PVT___GEN_12) & ((IData)(1U) 
                                                 << 
                                                 (0xfU 
                                                  & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid)))));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__do_enq 
        = (0x7fffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__full)) 
                      & ((IData)(vlSelf->__PVT___GEN_12) 
                         & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                            >> 1U))));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__do_enq 
        = (0x3fffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__full)) 
                      & ((IData)(vlSelf->__PVT___GEN_12) 
                         & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                            >> 2U))));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__do_enq 
        = (0x1fffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__full)) 
                      & ((IData)(vlSelf->__PVT___GEN_12) 
                         & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                            >> 3U))));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__do_enq 
        = (0xfffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_12) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                           >> 4U))));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__do_enq 
        = (0x7ffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_12) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                           >> 5U))));
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__do_enq 
        = (0x3ffU & ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__full)) 
                     & ((IData)(vlSelf->__PVT___GEN_12) 
                        & (((IData)(1U) << (0xfU & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4.auto_out_awid))) 
                           >> 6U))));
}
