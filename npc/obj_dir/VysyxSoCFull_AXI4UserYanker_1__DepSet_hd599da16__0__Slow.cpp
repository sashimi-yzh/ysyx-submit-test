// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_AXI4UserYanker_1.h"

VL_ATTR_COLD void VysyxSoCFull_AXI4UserYanker_1___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1__0(VysyxSoCFull_AXI4UserYanker_1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_AXI4UserYanker_1___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1__0\n"); );
    // Body
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap__DOT__empty = 
        ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__maybe_full)) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap__DOT__full = ((IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__ptr_match) 
                                                   & (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__maybe_full));
}

VL_ATTR_COLD void VysyxSoCFull_AXI4UserYanker_1___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank__0(VysyxSoCFull_AXI4UserYanker_1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_AXI4UserYanker_1___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank__0\n"); );
    // Body
    vlSelf->__PVT__Queue17_BundleMap__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__ptr_match 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value) 
           == (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data 
        = ((0x10U >= (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value))
            ? vlSelf->__PVT__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory
           [vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value]
            : 0U);
    vlSelf->__PVT__Queue17_BundleMap__DOT__empty = 
        ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__maybe_full)) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap__DOT__full = ((IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__ptr_match) 
                                                   & (IData)(vlSelf->__PVT__Queue17_BundleMap__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_1__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_2__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_3__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_4__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_5__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_6__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_7__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_8__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__full = 
        ((IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__ptr_match) 
         & (IData)(vlSelf->__PVT__Queue17_BundleMap_9__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_10__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_11__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_12__DOT__maybe_full));
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__empty 
        = ((~ (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__maybe_full)) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__ptr_match));
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__full 
        = ((IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__ptr_match) 
           & (IData)(vlSelf->__PVT__Queue17_BundleMap_13__DOT__maybe_full));
}

VL_ATTR_COLD void VysyxSoCFull_AXI4UserYanker_1___ctor_var_reset(VysyxSoCFull_AXI4UserYanker_1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_AXI4UserYanker_1___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->auto_in_awready = VL_RAND_RESET_I(1);
    vlSelf->auto_in_awvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_in_awid = VL_RAND_RESET_I(4);
    vlSelf->auto_in_awaddr = VL_RAND_RESET_I(32);
    vlSelf->auto_in_awlen = VL_RAND_RESET_I(8);
    vlSelf->auto_in_awsize = VL_RAND_RESET_I(3);
    vlSelf->auto_in_awburst = VL_RAND_RESET_I(2);
    vlSelf->auto_in_awecho_tl_state_size = VL_RAND_RESET_I(4);
    vlSelf->auto_in_awecho_tl_state_source = VL_RAND_RESET_I(7);
    vlSelf->auto_in_awecho_extra_id = VL_RAND_RESET_I(1);
    vlSelf->auto_in_wready = VL_RAND_RESET_I(1);
    vlSelf->auto_in_wvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_in_wdata = VL_RAND_RESET_I(32);
    vlSelf->auto_in_wstrb = VL_RAND_RESET_I(4);
    vlSelf->auto_in_wlast = VL_RAND_RESET_I(1);
    vlSelf->auto_in_bready = VL_RAND_RESET_I(1);
    vlSelf->auto_in_bvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_in_bid = VL_RAND_RESET_I(4);
    vlSelf->auto_in_bresp = VL_RAND_RESET_I(2);
    vlSelf->auto_in_becho_tl_state_size = VL_RAND_RESET_I(4);
    vlSelf->auto_in_becho_tl_state_source = VL_RAND_RESET_I(7);
    vlSelf->auto_in_becho_extra_id = VL_RAND_RESET_I(1);
    vlSelf->auto_in_arready = VL_RAND_RESET_I(1);
    vlSelf->auto_in_arvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_in_arid = VL_RAND_RESET_I(4);
    vlSelf->auto_in_araddr = VL_RAND_RESET_I(32);
    vlSelf->auto_in_arlen = VL_RAND_RESET_I(8);
    vlSelf->auto_in_arsize = VL_RAND_RESET_I(3);
    vlSelf->auto_in_arburst = VL_RAND_RESET_I(2);
    vlSelf->auto_in_arecho_tl_state_size = VL_RAND_RESET_I(4);
    vlSelf->auto_in_arecho_tl_state_source = VL_RAND_RESET_I(7);
    vlSelf->auto_in_arecho_extra_id = VL_RAND_RESET_I(1);
    vlSelf->auto_in_rready = VL_RAND_RESET_I(1);
    vlSelf->auto_in_rvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_in_rid = VL_RAND_RESET_I(4);
    vlSelf->auto_in_rdata = VL_RAND_RESET_I(32);
    vlSelf->auto_in_rresp = VL_RAND_RESET_I(2);
    vlSelf->auto_in_recho_tl_state_size = VL_RAND_RESET_I(4);
    vlSelf->auto_in_recho_tl_state_source = VL_RAND_RESET_I(7);
    vlSelf->auto_in_recho_extra_id = VL_RAND_RESET_I(1);
    vlSelf->auto_in_rlast = VL_RAND_RESET_I(1);
    vlSelf->auto_out_awready = VL_RAND_RESET_I(1);
    vlSelf->auto_out_awvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_out_awid = VL_RAND_RESET_I(4);
    vlSelf->auto_out_awaddr = VL_RAND_RESET_I(32);
    vlSelf->auto_out_awlen = VL_RAND_RESET_I(8);
    vlSelf->auto_out_awsize = VL_RAND_RESET_I(3);
    vlSelf->auto_out_awburst = VL_RAND_RESET_I(2);
    vlSelf->auto_out_wready = VL_RAND_RESET_I(1);
    vlSelf->auto_out_wvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_out_wdata = VL_RAND_RESET_I(32);
    vlSelf->auto_out_wstrb = VL_RAND_RESET_I(4);
    vlSelf->auto_out_wlast = VL_RAND_RESET_I(1);
    vlSelf->auto_out_bready = VL_RAND_RESET_I(1);
    vlSelf->auto_out_bvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_out_bid = VL_RAND_RESET_I(4);
    vlSelf->auto_out_bresp = VL_RAND_RESET_I(2);
    vlSelf->auto_out_arready = VL_RAND_RESET_I(1);
    vlSelf->auto_out_arvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_out_arid = VL_RAND_RESET_I(4);
    vlSelf->auto_out_araddr = VL_RAND_RESET_I(32);
    vlSelf->auto_out_arlen = VL_RAND_RESET_I(8);
    vlSelf->auto_out_arsize = VL_RAND_RESET_I(3);
    vlSelf->auto_out_arburst = VL_RAND_RESET_I(2);
    vlSelf->auto_out_rready = VL_RAND_RESET_I(1);
    vlSelf->auto_out_rvalid = VL_RAND_RESET_I(1);
    vlSelf->auto_out_rid = VL_RAND_RESET_I(4);
    vlSelf->auto_out_rdata = VL_RAND_RESET_I(32);
    vlSelf->auto_out_rresp = VL_RAND_RESET_I(2);
    vlSelf->auto_out_rlast = VL_RAND_RESET_I(1);
    vlSelf->__PVT___GEN_3 = VL_RAND_RESET_I(1);
    vlSelf->__PVT___GEN_4 = VL_RAND_RESET_I(1);
    vlSelf->__PVT___GEN_11 = VL_RAND_RESET_I(1);
    vlSelf->__PVT___GEN_12 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgTmp_h3deb4dd1__0 = 0;
    vlSelf->__VdfgTmp_h6bd82316__0 = 0;
    vlSelf->__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->Queue17_BundleMap_1__DOT____Vcellinp__ram_ext__W0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_1__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap_1__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap_1__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_2__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap_2__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap_2__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_3__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap_3__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap_3__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_4__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap_4__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap_4__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_5__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap_5__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap_5__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_6__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap_6__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap_6__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_1__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_1__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_2__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_2__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_3__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_3__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_4__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_4__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_5__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_5__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_6__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_6__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_7__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_7__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_8__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_8__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_7__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap_7__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap_7__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_8__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap_8__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap_8__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_9__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap_9__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap_9__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->Queue17_BundleMap_10__DOT____Vcellinp__ram_ext__W0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_10__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap_10__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap_10__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_11__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap_11__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap_11__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_12__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap_12__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap_12__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__enq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__deq_ptr_value = VL_RAND_RESET_I(5);
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue17_BundleMap_13__DOT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__Queue17_BundleMap_13__DOT__ram_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->Queue17_BundleMap_13__DOT__ram_ext__DOT____Vlvbound_hdaea10f3__0 = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_9__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_9__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_10__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_10__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_11__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_11__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_12__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_12__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_13__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_13__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_14__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_14__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_15__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_15__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_16__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_16__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_17__DOT__ram = VL_RAND_RESET_I(12);
    vlSelf->__PVT__Queue1_BundleMap_17__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq = VL_RAND_RESET_I(1);
}
