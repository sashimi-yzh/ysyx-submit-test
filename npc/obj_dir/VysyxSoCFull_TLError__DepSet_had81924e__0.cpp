// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLError.h"

VL_INLINE_OPT void VysyxSoCFull_TLError___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__ferr__1(VysyxSoCFull_TLError* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLError___nba_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__ferr__1\n"); );
    // Body
    vlSelf->auto_in_d_valid = ((IData)(vlSelf->__VdfgTmp_hec6944b2__0) 
                               & (IData)(vlSelf->__PVT__winner_1));
    if (vlSelf->auto_in_d_bits_denied) {
        vlSelf->auto_in_d_bits_size = (7U & (IData)(
                                                    (vlSelf->__PVT__a_q__DOT__ram 
                                                     >> 0x36U)));
        vlSelf->auto_in_d_bits_opcode = vlSelf->__PVT__da_bits_opcode;
    } else {
        vlSelf->auto_in_d_bits_size = 0U;
        vlSelf->auto_in_d_bits_opcode = 0U;
    }
}
