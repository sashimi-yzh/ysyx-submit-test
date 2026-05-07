// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_AsyncQueueSource_UInt32.h"
#include "VysyxSoCFull_RX.h"

VL_INLINE_OPT void VysyxSoCFull_RX___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__0(VysyxSoCFull_RX* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              VysyxSoCFull_RX___nba_comb__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__chiplink__DOT__rx__0\n"); );
    // Body
    vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__io_enq_ready_0 
        = (1U & ((~ (IData)(vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__full)) 
                 | (IData)(vlSelf->__PVT__io_a_source->__PVT__io_enq_ready)));
    vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__io_enq_ready_0 
        = (1U & ((~ (IData)(vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__full)) 
                 | (IData)(vlSelf->__PVT__io_bsource->__PVT__io_enq_ready)));
    vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__io_enq_ready_0 
        = (1U & ((~ (IData)(vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__full)) 
                 | (IData)(vlSelf->__PVT__io_c_source->__PVT__io_enq_ready)));
    vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__io_enq_ready_0 
        = (1U & ((~ (IData)(vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__full)) 
                 | (IData)(vlSelf->__PVT__io_d_source->__PVT__io_enq_ready)));
    vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__io_enq_ready_0 
        = (1U & ((~ (IData)(vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__full)) 
                 | (IData)(vlSelf->__PVT__io_e_source->__PVT__io_enq_ready)));
    vlSelf->__PVT__hqa__DOT__fq__DOT__do_flow = ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__empty) 
                                                 & (IData)(vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__io_enq_ready_0));
    vlSelf->__PVT__hqa__DOT__fq__DOT__ren = ((IData)(vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__io_enq_ready_0) 
                                             & ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__full) 
                                                | ((~ 
                                                    ((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__io_deq_valid_0) 
                                                     | (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__empty))) 
                                                   | (0U 
                                                      != 
                                                      (0xfU 
                                                       & (((IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__enq_ptr) 
                                                           - (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__deq_ptr)) 
                                                          >> 1U))))));
    vlSelf->__PVT__hqb__DOT__fq__DOT__do_flow = ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__empty) 
                                                 & (IData)(vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__io_enq_ready_0));
    vlSelf->__PVT__hqb__DOT__fq__DOT__ren = ((IData)(vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__io_enq_ready_0) 
                                             & ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__full) 
                                                | ((~ 
                                                    ((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__io_deq_valid_0) 
                                                     | (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__empty))) 
                                                   | (0U 
                                                      != 
                                                      (0xfU 
                                                       & (((IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__enq_ptr) 
                                                           - (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__deq_ptr)) 
                                                          >> 1U))))));
    vlSelf->__PVT__hqc__DOT__fq__DOT__do_flow = ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__empty) 
                                                 & (IData)(vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__io_enq_ready_0));
    vlSelf->__PVT__hqc__DOT__fq__DOT__ren = ((IData)(vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__io_enq_ready_0) 
                                             & ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__full) 
                                                | ((~ 
                                                    ((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__io_deq_valid_0) 
                                                     | (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__empty))) 
                                                   | (0U 
                                                      != 
                                                      (0xfU 
                                                       & (((IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__enq_ptr) 
                                                           - (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__deq_ptr)) 
                                                          >> 1U))))));
    vlSelf->__PVT__hqd__DOT__fq__DOT__do_flow = ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__empty) 
                                                 & (IData)(vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__io_enq_ready_0));
    vlSelf->__PVT__hqd__DOT__fq__DOT__ren = ((IData)(vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__io_enq_ready_0) 
                                             & ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__full) 
                                                | ((~ 
                                                    ((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__io_deq_valid_0) 
                                                     | (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__empty))) 
                                                   | (0U 
                                                      != 
                                                      (0xfU 
                                                       & (((IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__enq_ptr) 
                                                           - (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__deq_ptr)) 
                                                          >> 1U))))));
    vlSelf->__PVT__hqe__DOT__fq__DOT__do_flow = ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__empty) 
                                                 & (IData)(vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__io_enq_ready_0));
    vlSelf->__PVT__hqe__DOT__fq__DOT__ren = ((IData)(vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__io_enq_ready_0) 
                                             & ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__full) 
                                                | ((~ 
                                                    ((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__io_deq_valid_0) 
                                                     | (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__empty))) 
                                                   | (0U 
                                                      != 
                                                      (0xfU 
                                                       & (((IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__enq_ptr) 
                                                           - (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__deq_ptr)) 
                                                          >> 1U))))));
    vlSelf->__PVT__hqa__DOT__fq__DOT__do_enq = ((~ (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__full)) 
                                                & ((~ (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__do_flow)) 
                                                   & (IData)(vlSelf->__PVT__hqa_io_enq_valid)));
    vlSelf->__PVT__hqa__DOT__fq__DOT__do_deq = ((IData)(vlSelf->__PVT__hqa__DOT__io_deq_q__DOT__io_enq_ready_0) 
                                                & ((~ (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__do_flow)) 
                                                   & (IData)(vlSelf->__PVT__hqa__DOT__fq__DOT__io_deq_valid_0)));
    vlSelf->__PVT__hqb__DOT__fq__DOT__do_enq = ((~ (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__full)) 
                                                & ((~ (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__do_flow)) 
                                                   & (IData)(vlSelf->__PVT__hqb_io_enq_valid)));
    vlSelf->__PVT__hqb__DOT__fq__DOT__do_deq = ((IData)(vlSelf->__PVT__hqb__DOT__io_deq_q__DOT__io_enq_ready_0) 
                                                & ((~ (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__do_flow)) 
                                                   & (IData)(vlSelf->__PVT__hqb__DOT__fq__DOT__io_deq_valid_0)));
    vlSelf->__PVT__hqc__DOT__fq__DOT__do_enq = ((~ (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__full)) 
                                                & ((~ (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__do_flow)) 
                                                   & (IData)(vlSelf->__PVT__hqc_io_enq_valid)));
    vlSelf->__PVT__hqc__DOT__fq__DOT__do_deq = ((IData)(vlSelf->__PVT__hqc__DOT__io_deq_q__DOT__io_enq_ready_0) 
                                                & ((~ (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__do_flow)) 
                                                   & (IData)(vlSelf->__PVT__hqc__DOT__fq__DOT__io_deq_valid_0)));
    vlSelf->__PVT__hqd__DOT__fq__DOT__do_enq = ((~ (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__full)) 
                                                & ((~ (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__do_flow)) 
                                                   & (IData)(vlSelf->__PVT__hqd_io_enq_valid)));
    vlSelf->__PVT__hqd__DOT__fq__DOT__do_deq = ((IData)(vlSelf->__PVT__hqd__DOT__io_deq_q__DOT__io_enq_ready_0) 
                                                & ((~ (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__do_flow)) 
                                                   & (IData)(vlSelf->__PVT__hqd__DOT__fq__DOT__io_deq_valid_0)));
    vlSelf->__PVT__hqe__DOT__fq__DOT__do_enq = ((~ (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__full)) 
                                                & ((~ (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__do_flow)) 
                                                   & (IData)(vlSelf->__PVT__hqe_io_enq_valid)));
    vlSelf->__PVT__hqe__DOT__fq__DOT__do_deq = ((IData)(vlSelf->__PVT__hqe__DOT__io_deq_q__DOT__io_enq_ready_0) 
                                                & ((~ (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__do_flow)) 
                                                   & (IData)(vlSelf->__PVT__hqe__DOT__fq__DOT__io_deq_valid_0)));
}
