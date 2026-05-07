// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLFIFOFixer.h"
#include "VysyxSoCFull__Syms.h"

VL_ATTR_COLD void VysyxSoCFull_TLFIFOFixer___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__fixer__0(VysyxSoCFull_TLFIFOFixer* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLFIFOFixer___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__fixer__0\n"); );
    // Body
    vlSelf->__PVT__a_first = (0U == (IData)(vlSelf->__PVT__a_first_counter));
    vlSelf->__PVT__monitor__DOT__a_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_2 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_2));
    vlSelf->__PVT__a_id = ((2U & ((~ (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                      >> 0x1eU)) << 1U)) 
                           | (1U & (vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_address 
                                    >> 0x1eU)));
    vlSelf->__PVT__stall = (((~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
                                 >> 3U)) & ((0U == (IData)(vlSelf->__PVT__a_first_counter)) 
                                            & (((IData)(vlSelf->__PVT__flight_0) 
                                                | ((IData)(vlSelf->__PVT__flight_1) 
                                                   | ((IData)(vlSelf->__PVT__flight_2) 
                                                      | ((IData)(vlSelf->__PVT__flight_3) 
                                                         | ((IData)(vlSelf->__PVT__flight_4) 
                                                            | ((IData)(vlSelf->__PVT__flight_5) 
                                                               | ((IData)(vlSelf->__PVT__flight_6) 
                                                                  | (IData)(vlSelf->__PVT__flight_7)))))))) 
                                               & ((0U 
                                                   == (IData)(vlSelf->__PVT__a_id)) 
                                                  | ((IData)(vlSelf->__PVT__stalls_id) 
                                                     != (IData)(vlSelf->__PVT__a_id)))))) 
                            | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___axi42tl_auto_out_a_bits_source) 
                                >> 3U) & ((0U == (IData)(vlSelf->__PVT__a_first_counter)) 
                                          & (((IData)(vlSelf->__PVT__flight_8) 
                                              | ((IData)(vlSelf->__PVT__flight_9) 
                                                 | ((IData)(vlSelf->__PVT__flight_10) 
                                                    | ((IData)(vlSelf->__PVT__flight_11) 
                                                       | ((IData)(vlSelf->__PVT__flight_12) 
                                                          | ((IData)(vlSelf->__PVT__flight_13) 
                                                             | ((IData)(vlSelf->__PVT__flight_14) 
                                                                | (IData)(vlSelf->__PVT__flight_15)))))))) 
                                             & ((0U 
                                                 == (IData)(vlSelf->__PVT__a_id)) 
                                                | ((IData)(vlSelf->__PVT__stalls_id_1) 
                                                   != (IData)(vlSelf->__PVT__a_id)))))));
    vlSelf->auto_anon_out_a_valid = ((~ (IData)(vlSelf->__PVT__stall)) 
                                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi42tl__DOT__nodeOut_a_valid));
}

VL_ATTR_COLD void VysyxSoCFull_TLFIFOFixer___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__fixer__0(VysyxSoCFull_TLFIFOFixer* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLFIFOFixer___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__fixer__0\n"); );
    // Body
    vlSelf->__PVT__a_first = (0U == (IData)(vlSelf->__PVT__a_first_counter));
    vlSelf->__PVT__monitor__DOT__a_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_2 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_2));
    vlSelf->__PVT__a_id = ((2U & ((~ (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                      >> 0x1eU)) << 1U)) 
                           | (1U & (vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_address 
                                    >> 0x1eU)));
    vlSelf->__PVT__stall = (((~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
                                 >> 3U)) & ((0U == (IData)(vlSelf->__PVT__a_first_counter)) 
                                            & (((IData)(vlSelf->__PVT__flight_0) 
                                                | ((IData)(vlSelf->__PVT__flight_1) 
                                                   | ((IData)(vlSelf->__PVT__flight_2) 
                                                      | ((IData)(vlSelf->__PVT__flight_3) 
                                                         | ((IData)(vlSelf->__PVT__flight_4) 
                                                            | ((IData)(vlSelf->__PVT__flight_5) 
                                                               | ((IData)(vlSelf->__PVT__flight_6) 
                                                                  | (IData)(vlSelf->__PVT__flight_7)))))))) 
                                               & ((0U 
                                                   == (IData)(vlSelf->__PVT__a_id)) 
                                                  | ((IData)(vlSelf->__PVT__stalls_id) 
                                                     != (IData)(vlSelf->__PVT__a_id)))))) 
                            | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___axi42tl_auto_out_a_bits_source) 
                                >> 3U) & ((0U == (IData)(vlSelf->__PVT__a_first_counter)) 
                                          & (((IData)(vlSelf->__PVT__flight_8) 
                                              | ((IData)(vlSelf->__PVT__flight_9) 
                                                 | ((IData)(vlSelf->__PVT__flight_10) 
                                                    | ((IData)(vlSelf->__PVT__flight_11) 
                                                       | ((IData)(vlSelf->__PVT__flight_12) 
                                                          | ((IData)(vlSelf->__PVT__flight_13) 
                                                             | ((IData)(vlSelf->__PVT__flight_14) 
                                                                | (IData)(vlSelf->__PVT__flight_15)))))))) 
                                             & ((0U 
                                                 == (IData)(vlSelf->__PVT__a_id)) 
                                                | ((IData)(vlSelf->__PVT__stalls_id_1) 
                                                   != (IData)(vlSelf->__PVT__a_id)))))));
    vlSelf->auto_anon_out_a_valid = ((~ (IData)(vlSelf->__PVT__stall)) 
                                     & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT__axi42tl__DOT__nodeOut_a_valid));
}
