// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbooth_wallace_multiplier__Syms.h"


VL_ATTR_COLD void Vbooth_wallace_multiplier___024root__trace_full_sub_2(Vbooth_wallace_multiplier___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root__trace_full_sub_2\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+4705,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x37U] >> 2U))),3);
    bufp->fullBit(oldp+4706,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x37U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x37U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x37U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x37U] >> 2U))))));
    bufp->fullBit(oldp+4707,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4708,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 4U))));
    bufp->fullBit(oldp+4709,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 3U))));
    bufp->fullBit(oldp+4710,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 2U))));
    bufp->fullCData(oldp+4711,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4712,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4713,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4714,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x37U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4715,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 1U)))));
    bufp->fullBit(oldp+4716,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4717,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 1U))));
    bufp->fullCData(oldp+4718,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x37U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4719,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x37U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x37U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4720,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4721,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x37U])));
    bufp->fullBit(oldp+4722,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4723,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4724,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4725,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4726,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4727,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4728,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4729,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4730,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4731,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4732,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4733,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4734,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4735,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4736,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4737,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4738,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4739,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4740,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4741,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4742,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4743,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4744,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4745,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4746,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4747,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4748,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4749,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4750,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4751,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4752,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4753,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4754,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x38U]),17);
    bufp->fullSData(oldp+4755,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4756,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4757,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4758,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4759,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4760,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4761,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4762,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4763,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x38U] >> 0xeU))),3);
    bufp->fullBit(oldp+4764,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x38U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x38U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x38U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x38U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 0xeU))))));
    bufp->fullBit(oldp+4765,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4766,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 0x10U))));
    bufp->fullBit(oldp+4767,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 0xfU))));
    bufp->fullBit(oldp+4768,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 0xeU))));
    bufp->fullCData(oldp+4769,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x38U] >> 0xbU))),3);
    bufp->fullBit(oldp+4770,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x38U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x38U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x38U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x38U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 0xbU))))));
    bufp->fullBit(oldp+4771,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4772,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 0xdU))));
    bufp->fullBit(oldp+4773,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 0xcU))));
    bufp->fullBit(oldp+4774,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 0xbU))));
    bufp->fullCData(oldp+4775,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x38U] >> 8U))),3);
    bufp->fullBit(oldp+4776,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x38U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x38U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x38U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x38U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 8U))))));
    bufp->fullBit(oldp+4777,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4778,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 0xaU))));
    bufp->fullBit(oldp+4779,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 9U))));
    bufp->fullBit(oldp+4780,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 8U))));
    bufp->fullCData(oldp+4781,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x38U] >> 5U))),3);
    bufp->fullBit(oldp+4782,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x38U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x38U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x38U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x38U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 5U))))));
    bufp->fullBit(oldp+4783,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4784,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 7U))));
    bufp->fullBit(oldp+4785,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 6U))));
    bufp->fullBit(oldp+4786,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 5U))));
    bufp->fullCData(oldp+4787,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x38U] >> 2U))),3);
    bufp->fullBit(oldp+4788,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x38U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x38U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x38U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x38U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 2U))))));
    bufp->fullBit(oldp+4789,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4790,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 4U))));
    bufp->fullBit(oldp+4791,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 3U))));
    bufp->fullBit(oldp+4792,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 2U))));
    bufp->fullCData(oldp+4793,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4794,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4795,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4796,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x38U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4797,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 1U)))));
    bufp->fullBit(oldp+4798,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4799,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x38U] >> 1U))));
    bufp->fullCData(oldp+4800,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x38U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4801,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x38U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4802,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4803,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x38U])));
    bufp->fullBit(oldp+4804,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4805,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4806,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4807,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4808,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4809,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4810,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4811,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4812,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4813,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4814,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4815,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4816,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4817,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4818,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4819,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4820,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4821,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4822,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4823,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4824,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4825,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4826,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4827,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4828,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4829,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4830,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4831,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4832,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4833,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4834,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4835,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4836,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x39U]),17);
    bufp->fullSData(oldp+4837,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4838,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4839,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4840,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4841,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4842,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4843,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4844,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4845,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 0xeU))),3);
    bufp->fullBit(oldp+4846,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x39U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x39U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 0xeU))))));
    bufp->fullBit(oldp+4847,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4848,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 0x10U))));
    bufp->fullBit(oldp+4849,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 0xfU))));
    bufp->fullBit(oldp+4850,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 0xeU))));
    bufp->fullCData(oldp+4851,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 0xbU))),3);
    bufp->fullBit(oldp+4852,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x39U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x39U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 0xbU))))));
    bufp->fullBit(oldp+4853,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4854,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 0xdU))));
    bufp->fullBit(oldp+4855,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 0xcU))));
    bufp->fullBit(oldp+4856,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 0xbU))));
    bufp->fullCData(oldp+4857,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 8U))),3);
    bufp->fullBit(oldp+4858,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x39U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x39U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 8U))))));
    bufp->fullBit(oldp+4859,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4860,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 0xaU))));
    bufp->fullBit(oldp+4861,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 9U))));
    bufp->fullBit(oldp+4862,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 8U))));
    bufp->fullCData(oldp+4863,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 5U))),3);
    bufp->fullBit(oldp+4864,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x39U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x39U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 5U))))));
    bufp->fullBit(oldp+4865,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4866,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 7U))));
    bufp->fullBit(oldp+4867,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 6U))));
    bufp->fullBit(oldp+4868,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 5U))));
    bufp->fullCData(oldp+4869,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 2U))),3);
    bufp->fullBit(oldp+4870,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x39U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x39U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 2U))))));
    bufp->fullBit(oldp+4871,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4872,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 4U))));
    bufp->fullBit(oldp+4873,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 3U))));
    bufp->fullBit(oldp+4874,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 2U))));
    bufp->fullCData(oldp+4875,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4876,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4877,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4878,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x39U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4879,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 1U)))));
    bufp->fullBit(oldp+4880,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4881,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x39U] >> 1U))));
    bufp->fullCData(oldp+4882,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x39U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4883,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x39U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4884,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4885,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x39U])));
    bufp->fullBit(oldp+4886,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4887,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4888,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4889,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4890,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4891,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4892,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4893,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4894,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4895,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4896,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4897,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4898,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4899,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4900,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4901,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4902,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4903,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4904,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4905,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4906,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4907,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4908,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4909,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4910,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4911,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4912,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4913,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4914,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4915,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4916,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4917,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4918,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x3aU]),17);
    bufp->fullSData(oldp+4919,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4920,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4921,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4922,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4923,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4924,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4925,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4926,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4927,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 0xeU))),3);
    bufp->fullBit(oldp+4928,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3aU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 0xeU))))));
    bufp->fullBit(oldp+4929,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4930,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 0x10U))));
    bufp->fullBit(oldp+4931,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 0xfU))));
    bufp->fullBit(oldp+4932,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 0xeU))));
    bufp->fullCData(oldp+4933,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 0xbU))),3);
    bufp->fullBit(oldp+4934,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3aU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 0xbU))))));
    bufp->fullBit(oldp+4935,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4936,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 0xdU))));
    bufp->fullBit(oldp+4937,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 0xcU))));
    bufp->fullBit(oldp+4938,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 0xbU))));
    bufp->fullCData(oldp+4939,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 8U))),3);
    bufp->fullBit(oldp+4940,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3aU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 8U))))));
    bufp->fullBit(oldp+4941,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4942,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 0xaU))));
    bufp->fullBit(oldp+4943,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 9U))));
    bufp->fullBit(oldp+4944,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 8U))));
    bufp->fullCData(oldp+4945,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 5U))),3);
    bufp->fullBit(oldp+4946,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3aU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 5U))))));
    bufp->fullBit(oldp+4947,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4948,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 7U))));
    bufp->fullBit(oldp+4949,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 6U))));
    bufp->fullBit(oldp+4950,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 5U))));
    bufp->fullCData(oldp+4951,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 2U))),3);
    bufp->fullBit(oldp+4952,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3aU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 2U))))));
    bufp->fullBit(oldp+4953,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4954,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 4U))));
    bufp->fullBit(oldp+4955,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 3U))));
    bufp->fullBit(oldp+4956,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 2U))));
    bufp->fullCData(oldp+4957,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4958,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4959,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4960,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3aU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4961,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 1U)))));
    bufp->fullBit(oldp+4962,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4963,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3aU] >> 1U))));
    bufp->fullCData(oldp+4964,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x3aU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4965,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x3aU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4966,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4967,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x3aU])));
    bufp->fullBit(oldp+4968,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4969,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4970,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4971,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4972,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4973,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4974,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4975,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4976,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4977,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4978,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4979,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4980,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4981,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4982,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4983,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4984,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4985,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4986,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4987,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4988,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4989,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4990,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4991,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4992,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4993,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4994,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4995,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4996,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4997,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4998,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4999,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5000,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x3bU]),17);
    bufp->fullSData(oldp+5001,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5002,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5003,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5004,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5005,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5006,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5007,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5008,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5009,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 0xeU))),3);
    bufp->fullBit(oldp+5010,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3bU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 0xeU))))));
    bufp->fullBit(oldp+5011,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5012,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 0x10U))));
    bufp->fullBit(oldp+5013,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 0xfU))));
    bufp->fullBit(oldp+5014,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 0xeU))));
    bufp->fullCData(oldp+5015,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 0xbU))),3);
    bufp->fullBit(oldp+5016,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3bU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 0xbU))))));
    bufp->fullBit(oldp+5017,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5018,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 0xdU))));
    bufp->fullBit(oldp+5019,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 0xcU))));
    bufp->fullBit(oldp+5020,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 0xbU))));
    bufp->fullCData(oldp+5021,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 8U))),3);
    bufp->fullBit(oldp+5022,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3bU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 8U))))));
    bufp->fullBit(oldp+5023,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5024,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 0xaU))));
    bufp->fullBit(oldp+5025,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 9U))));
    bufp->fullBit(oldp+5026,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 8U))));
    bufp->fullCData(oldp+5027,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 5U))),3);
    bufp->fullBit(oldp+5028,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3bU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 5U))))));
    bufp->fullBit(oldp+5029,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5030,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 7U))));
    bufp->fullBit(oldp+5031,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 6U))));
    bufp->fullBit(oldp+5032,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 5U))));
    bufp->fullCData(oldp+5033,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 2U))),3);
    bufp->fullBit(oldp+5034,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3bU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 2U))))));
    bufp->fullBit(oldp+5035,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5036,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 4U))));
    bufp->fullBit(oldp+5037,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 3U))));
    bufp->fullBit(oldp+5038,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 2U))));
    bufp->fullCData(oldp+5039,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5040,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5041,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5042,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3bU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5043,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 1U)))));
    bufp->fullBit(oldp+5044,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5045,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3bU] >> 1U))));
    bufp->fullCData(oldp+5046,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x3bU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5047,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x3bU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5048,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5049,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x3bU])));
    bufp->fullBit(oldp+5050,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5051,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5052,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5053,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5054,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5055,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5056,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5057,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5058,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5059,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5060,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5061,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5062,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5063,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5064,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5065,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5066,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5067,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5068,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5069,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5070,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5071,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5072,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5073,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5074,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5075,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5076,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5077,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5078,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5079,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5080,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5081,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5082,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x3cU]),17);
    bufp->fullSData(oldp+5083,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5084,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5085,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5086,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5087,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5088,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5089,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5090,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5091,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 0xeU))),3);
    bufp->fullBit(oldp+5092,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3cU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 0xeU))))));
    bufp->fullBit(oldp+5093,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5094,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 0x10U))));
    bufp->fullBit(oldp+5095,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 0xfU))));
    bufp->fullBit(oldp+5096,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 0xeU))));
    bufp->fullCData(oldp+5097,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 0xbU))),3);
    bufp->fullBit(oldp+5098,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3cU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 0xbU))))));
    bufp->fullBit(oldp+5099,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5100,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 0xdU))));
    bufp->fullBit(oldp+5101,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 0xcU))));
    bufp->fullBit(oldp+5102,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 0xbU))));
    bufp->fullCData(oldp+5103,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 8U))),3);
    bufp->fullBit(oldp+5104,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3cU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 8U))))));
    bufp->fullBit(oldp+5105,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5106,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 0xaU))));
    bufp->fullBit(oldp+5107,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 9U))));
    bufp->fullBit(oldp+5108,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 8U))));
    bufp->fullCData(oldp+5109,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 5U))),3);
    bufp->fullBit(oldp+5110,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3cU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 5U))))));
    bufp->fullBit(oldp+5111,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5112,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 7U))));
    bufp->fullBit(oldp+5113,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 6U))));
    bufp->fullBit(oldp+5114,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 5U))));
    bufp->fullCData(oldp+5115,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 2U))),3);
    bufp->fullBit(oldp+5116,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3cU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 2U))))));
    bufp->fullBit(oldp+5117,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5118,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 4U))));
    bufp->fullBit(oldp+5119,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 3U))));
    bufp->fullBit(oldp+5120,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 2U))));
    bufp->fullCData(oldp+5121,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5122,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5123,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5124,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3cU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5125,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 1U)))));
    bufp->fullBit(oldp+5126,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5127,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3cU] >> 1U))));
    bufp->fullCData(oldp+5128,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x3cU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5129,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x3cU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5130,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5131,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x3cU])));
    bufp->fullBit(oldp+5132,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5133,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5134,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5135,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5136,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5137,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5138,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5139,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5140,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5141,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5142,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5143,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5144,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5145,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5146,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5147,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5148,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5149,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5150,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5151,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5152,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5153,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5154,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5155,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5156,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5157,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5158,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5159,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5160,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5161,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5162,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5163,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5164,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x3dU]),17);
    bufp->fullSData(oldp+5165,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5166,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5167,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5168,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5169,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5170,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5171,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5172,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5173,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 0xeU))),3);
    bufp->fullBit(oldp+5174,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3dU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 0xeU))))));
    bufp->fullBit(oldp+5175,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5176,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 0x10U))));
    bufp->fullBit(oldp+5177,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 0xfU))));
    bufp->fullBit(oldp+5178,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 0xeU))));
    bufp->fullCData(oldp+5179,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 0xbU))),3);
    bufp->fullBit(oldp+5180,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3dU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 0xbU))))));
    bufp->fullBit(oldp+5181,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5182,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 0xdU))));
    bufp->fullBit(oldp+5183,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 0xcU))));
    bufp->fullBit(oldp+5184,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 0xbU))));
    bufp->fullCData(oldp+5185,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 8U))),3);
    bufp->fullBit(oldp+5186,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3dU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 8U))))));
    bufp->fullBit(oldp+5187,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5188,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 0xaU))));
    bufp->fullBit(oldp+5189,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 9U))));
    bufp->fullBit(oldp+5190,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 8U))));
    bufp->fullCData(oldp+5191,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 5U))),3);
    bufp->fullBit(oldp+5192,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3dU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 5U))))));
    bufp->fullBit(oldp+5193,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5194,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 7U))));
    bufp->fullBit(oldp+5195,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 6U))));
    bufp->fullBit(oldp+5196,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 5U))));
    bufp->fullCData(oldp+5197,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 2U))),3);
    bufp->fullBit(oldp+5198,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3dU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 2U))))));
    bufp->fullBit(oldp+5199,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5200,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 4U))));
    bufp->fullBit(oldp+5201,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 3U))));
    bufp->fullBit(oldp+5202,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 2U))));
    bufp->fullCData(oldp+5203,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5204,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5205,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5206,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3dU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5207,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 1U)))));
    bufp->fullBit(oldp+5208,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5209,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3dU] >> 1U))));
    bufp->fullCData(oldp+5210,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x3dU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5211,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x3dU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5212,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5213,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x3dU])));
    bufp->fullBit(oldp+5214,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5215,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5216,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5217,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5218,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5219,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5220,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5221,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5222,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5223,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5224,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5225,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5226,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5227,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5228,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5229,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5230,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5231,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5232,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5233,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5234,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5235,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5236,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5237,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5238,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5239,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5240,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5241,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5242,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5243,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5244,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5245,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5246,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x3eU]),17);
    bufp->fullSData(oldp+5247,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5248,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5249,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5250,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5251,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5252,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5253,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5254,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5255,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 0xeU))),3);
    bufp->fullBit(oldp+5256,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3eU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 0xeU))))));
    bufp->fullBit(oldp+5257,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5258,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 0x10U))));
    bufp->fullBit(oldp+5259,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 0xfU))));
    bufp->fullBit(oldp+5260,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 0xeU))));
    bufp->fullCData(oldp+5261,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 0xbU))),3);
    bufp->fullBit(oldp+5262,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3eU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 0xbU))))));
    bufp->fullBit(oldp+5263,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5264,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 0xdU))));
    bufp->fullBit(oldp+5265,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 0xcU))));
    bufp->fullBit(oldp+5266,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 0xbU))));
    bufp->fullCData(oldp+5267,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 8U))),3);
    bufp->fullBit(oldp+5268,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3eU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 8U))))));
    bufp->fullBit(oldp+5269,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5270,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 0xaU))));
    bufp->fullBit(oldp+5271,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 9U))));
    bufp->fullBit(oldp+5272,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 8U))));
    bufp->fullCData(oldp+5273,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 5U))),3);
    bufp->fullBit(oldp+5274,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3eU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 5U))))));
    bufp->fullBit(oldp+5275,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5276,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 7U))));
    bufp->fullBit(oldp+5277,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 6U))));
    bufp->fullBit(oldp+5278,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 5U))));
    bufp->fullCData(oldp+5279,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 2U))),3);
    bufp->fullBit(oldp+5280,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3eU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 2U))))));
    bufp->fullBit(oldp+5281,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5282,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 4U))));
    bufp->fullBit(oldp+5283,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 3U))));
    bufp->fullBit(oldp+5284,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 2U))));
    bufp->fullCData(oldp+5285,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5286,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5287,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5288,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3eU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5289,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 1U)))));
    bufp->fullBit(oldp+5290,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5291,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3eU] >> 1U))));
    bufp->fullCData(oldp+5292,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x3eU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5293,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x3eU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5294,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5295,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x3eU])));
    bufp->fullBit(oldp+5296,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5297,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5298,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5299,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5300,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5301,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5302,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5303,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5304,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5305,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5306,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5307,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5308,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5309,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5310,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5311,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5312,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5313,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5314,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5315,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5316,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5317,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5318,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5319,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5320,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5321,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5322,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5323,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5324,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5325,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5326,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5327,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5328,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x3fU]),17);
    bufp->fullSData(oldp+5329,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5330,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5331,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5332,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5333,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5334,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5335,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5336,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5337,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 0xeU))),3);
    bufp->fullBit(oldp+5338,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3fU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 0xeU))))));
    bufp->fullBit(oldp+5339,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5340,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 0x10U))));
    bufp->fullBit(oldp+5341,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 0xfU))));
    bufp->fullBit(oldp+5342,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 0xeU))));
    bufp->fullCData(oldp+5343,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 0xbU))),3);
    bufp->fullBit(oldp+5344,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3fU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 0xbU))))));
    bufp->fullBit(oldp+5345,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5346,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 0xdU))));
    bufp->fullBit(oldp+5347,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 0xcU))));
    bufp->fullBit(oldp+5348,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 0xbU))));
    bufp->fullCData(oldp+5349,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 8U))),3);
    bufp->fullBit(oldp+5350,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3fU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 8U))))));
    bufp->fullBit(oldp+5351,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5352,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 0xaU))));
    bufp->fullBit(oldp+5353,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 9U))));
    bufp->fullBit(oldp+5354,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 8U))));
    bufp->fullCData(oldp+5355,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 5U))),3);
    bufp->fullBit(oldp+5356,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3fU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 5U))))));
    bufp->fullBit(oldp+5357,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5358,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 7U))));
    bufp->fullBit(oldp+5359,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 6U))));
    bufp->fullBit(oldp+5360,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 5U))));
    bufp->fullCData(oldp+5361,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 2U))),3);
    bufp->fullBit(oldp+5362,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3fU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 2U))))));
    bufp->fullBit(oldp+5363,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5364,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 4U))));
    bufp->fullBit(oldp+5365,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 3U))));
    bufp->fullBit(oldp+5366,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 2U))));
    bufp->fullCData(oldp+5367,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5368,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5369,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5370,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3fU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5371,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 1U)))));
    bufp->fullBit(oldp+5372,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5373,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x3fU] >> 1U))));
    bufp->fullCData(oldp+5374,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x3fU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5375,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x3fU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5376,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5377,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x3fU])));
    bufp->fullBit(oldp+5378,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5379,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5380,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5381,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5382,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5383,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5384,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5385,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5386,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5387,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5388,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5389,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5390,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5391,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5392,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5393,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5394,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5395,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5396,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5397,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5398,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5399,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5400,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5401,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5402,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5403,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5404,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5405,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5406,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5407,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5408,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5409,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5410,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x40U]),17);
    bufp->fullSData(oldp+5411,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5412,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5413,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5414,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5415,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5416,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5417,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5418,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5419,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 0xeU))),3);
    bufp->fullBit(oldp+5420,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x40U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x40U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 0xeU))))));
    bufp->fullBit(oldp+5421,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5422,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 0x10U))));
    bufp->fullBit(oldp+5423,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 0xfU))));
    bufp->fullBit(oldp+5424,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 0xeU))));
    bufp->fullCData(oldp+5425,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 0xbU))),3);
    bufp->fullBit(oldp+5426,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x40U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x40U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 0xbU))))));
    bufp->fullBit(oldp+5427,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5428,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 0xdU))));
    bufp->fullBit(oldp+5429,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 0xcU))));
    bufp->fullBit(oldp+5430,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 0xbU))));
    bufp->fullCData(oldp+5431,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 8U))),3);
    bufp->fullBit(oldp+5432,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x40U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x40U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 8U))))));
    bufp->fullBit(oldp+5433,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5434,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 0xaU))));
    bufp->fullBit(oldp+5435,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 9U))));
    bufp->fullBit(oldp+5436,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 8U))));
    bufp->fullCData(oldp+5437,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 5U))),3);
    bufp->fullBit(oldp+5438,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x40U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x40U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 5U))))));
    bufp->fullBit(oldp+5439,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5440,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 7U))));
    bufp->fullBit(oldp+5441,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 6U))));
    bufp->fullBit(oldp+5442,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 5U))));
    bufp->fullCData(oldp+5443,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 2U))),3);
    bufp->fullBit(oldp+5444,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x40U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x40U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 2U))))));
    bufp->fullBit(oldp+5445,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5446,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 4U))));
    bufp->fullBit(oldp+5447,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 3U))));
    bufp->fullBit(oldp+5448,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 2U))));
    bufp->fullCData(oldp+5449,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5450,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5451,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5452,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x40U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5453,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 1U)))));
    bufp->fullBit(oldp+5454,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5455,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x40U] >> 1U))));
    bufp->fullCData(oldp+5456,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x40U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5457,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x40U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5458,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5459,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x40U])));
    bufp->fullBit(oldp+5460,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5461,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5462,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5463,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5464,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5465,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5466,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5467,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5468,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5469,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5470,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5471,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5472,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5473,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5474,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5475,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5476,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5477,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5478,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5479,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5480,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5481,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5482,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5483,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5484,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5485,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5486,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5487,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5488,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5489,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5490,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5491,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5492,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x41U]),17);
    bufp->fullSData(oldp+5493,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5494,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5495,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5496,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5497,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5498,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5499,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5500,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5501,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 0xeU))),3);
    bufp->fullBit(oldp+5502,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x41U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x41U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 0xeU))))));
    bufp->fullBit(oldp+5503,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5504,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 0x10U))));
    bufp->fullBit(oldp+5505,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 0xfU))));
    bufp->fullBit(oldp+5506,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 0xeU))));
    bufp->fullCData(oldp+5507,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 0xbU))),3);
    bufp->fullBit(oldp+5508,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x41U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x41U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 0xbU))))));
    bufp->fullBit(oldp+5509,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5510,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 0xdU))));
    bufp->fullBit(oldp+5511,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 0xcU))));
    bufp->fullBit(oldp+5512,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 0xbU))));
    bufp->fullCData(oldp+5513,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 8U))),3);
    bufp->fullBit(oldp+5514,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x41U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x41U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 8U))))));
    bufp->fullBit(oldp+5515,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5516,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 0xaU))));
    bufp->fullBit(oldp+5517,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 9U))));
    bufp->fullBit(oldp+5518,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 8U))));
    bufp->fullCData(oldp+5519,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 5U))),3);
    bufp->fullBit(oldp+5520,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x41U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x41U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 5U))))));
    bufp->fullBit(oldp+5521,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5522,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 7U))));
    bufp->fullBit(oldp+5523,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 6U))));
    bufp->fullBit(oldp+5524,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 5U))));
    bufp->fullCData(oldp+5525,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 2U))),3);
    bufp->fullBit(oldp+5526,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x41U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x41U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 2U))))));
    bufp->fullBit(oldp+5527,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5528,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 4U))));
    bufp->fullBit(oldp+5529,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 3U))));
    bufp->fullBit(oldp+5530,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 2U))));
    bufp->fullCData(oldp+5531,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5532,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5533,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5534,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x41U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5535,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 1U)))));
    bufp->fullBit(oldp+5536,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5537,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x41U] >> 1U))));
    bufp->fullCData(oldp+5538,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x41U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5539,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x41U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5540,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5541,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x41U])));
    bufp->fullBit(oldp+5542,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5543,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5544,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5545,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5546,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5547,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5548,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5549,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5550,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5551,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5552,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5553,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5554,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5555,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5556,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5557,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5558,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5559,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5560,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5561,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5562,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5563,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5564,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5565,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5566,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5567,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5568,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5569,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5570,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5571,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5572,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5573,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5574,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x42U]),17);
    bufp->fullSData(oldp+5575,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5576,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5577,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5578,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5579,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5580,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5581,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5582,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5583,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 0xeU))),3);
    bufp->fullBit(oldp+5584,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x42U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x42U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 0xeU))))));
    bufp->fullBit(oldp+5585,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5586,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 0x10U))));
    bufp->fullBit(oldp+5587,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 0xfU))));
    bufp->fullBit(oldp+5588,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 0xeU))));
    bufp->fullCData(oldp+5589,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 0xbU))),3);
    bufp->fullBit(oldp+5590,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x42U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x42U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 0xbU))))));
    bufp->fullBit(oldp+5591,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5592,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 0xdU))));
    bufp->fullBit(oldp+5593,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 0xcU))));
    bufp->fullBit(oldp+5594,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 0xbU))));
    bufp->fullCData(oldp+5595,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 8U))),3);
    bufp->fullBit(oldp+5596,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x42U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x42U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 8U))))));
    bufp->fullBit(oldp+5597,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5598,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 0xaU))));
    bufp->fullBit(oldp+5599,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 9U))));
    bufp->fullBit(oldp+5600,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 8U))));
    bufp->fullCData(oldp+5601,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 5U))),3);
    bufp->fullBit(oldp+5602,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x42U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x42U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 5U))))));
    bufp->fullBit(oldp+5603,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5604,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 7U))));
    bufp->fullBit(oldp+5605,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 6U))));
    bufp->fullBit(oldp+5606,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 5U))));
    bufp->fullCData(oldp+5607,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 2U))),3);
    bufp->fullBit(oldp+5608,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x42U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x42U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 2U))))));
    bufp->fullBit(oldp+5609,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5610,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 4U))));
    bufp->fullBit(oldp+5611,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 3U))));
    bufp->fullBit(oldp+5612,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 2U))));
    bufp->fullCData(oldp+5613,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5614,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5615,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5616,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x42U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5617,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 1U)))));
    bufp->fullBit(oldp+5618,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5619,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x42U] >> 1U))));
    bufp->fullCData(oldp+5620,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x42U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5621,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x42U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5622,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5623,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x42U])));
    bufp->fullBit(oldp+5624,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5625,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5626,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5627,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5628,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5629,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5630,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5631,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5632,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5633,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5634,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5635,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5636,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5637,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5638,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5639,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5640,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5641,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5642,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5643,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5644,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5645,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5646,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5647,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5648,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5649,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5650,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5651,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5652,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5653,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5654,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5655,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5656,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x43U]),17);
    bufp->fullSData(oldp+5657,((((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s)) 
                                  << 0xdU) | (0xffffe000U 
                                              & ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s)) 
                                                  << 0xdU) 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                    << 2U)))) 
                                | (((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s)) 
                                     << 0xcU) | (0xfffff000U 
                                                 & ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s) 
                                                      | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s)) 
                                                     << 0xcU) 
                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                       << 2U)))) 
                                   | ((0x800U & (((IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                                  << 0xbU) 
                                                 | (0xfffff800U 
                                                    & (((IData)(
                                                                (0U 
                                                                 != 
                                                                 (0x300U 
                                                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                                        << 0xbU) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                          << 4U))))) 
                                      | (((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                                            & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s)) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                               | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s)) 
                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s))) 
                                          << 0xaU) 
                                         | ((0x200U 
                                             & ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s) 
                                                  << 9U) 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                    << 3U)) 
                                                | (((0xfffffe00U 
                                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                        << 3U)) 
                                                    | ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s) 
                                                       << 9U)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                      << 4U)))) 
                                            | (((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s)) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s)) 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s))) 
                                                << 8U) 
                                               | (((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s)) 
                                                    << 7U) 
                                                   | (0xffffff80U 
                                                      & ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s) 
                                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s)) 
                                                          << 7U) 
                                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                            [0x43U] 
                                                            << 6U)))) 
                                                  | ((0x40U 
                                                      & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                           [0x43U] 
                                                           << 6U) 
                                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                             << 2U)) 
                                                         | (((0xffffffc0U 
                                                              & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                                 << 2U)) 
                                                             | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                [0x43U] 
                                                                << 6U)) 
                                                            & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                               << 3U)))) 
                                                     | ((0x20U 
                                                         & (((IData)(
                                                                     (6U 
                                                                      == 
                                                                      (6U 
                                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                                             | ((IData)(
                                                                        (0U 
                                                                         != 
                                                                         (6U 
                                                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))) 
                                                            << 5U)) 
                                                        | ((0x10U 
                                                            & ((0xffff0U 
                                                                & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                    [0x43U] 
                                                                    >> 0xcU) 
                                                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x43U] 
                                                                      >> 0xbU))) 
                                                               | (0x3ffff0U 
                                                                  & (((0x1ffff0U 
                                                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x43U] 
                                                                          >> 0xbU)) 
                                                                      | (0xffff0U 
                                                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x43U] 
                                                                            >> 0xcU))) 
                                                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                        [0x43U] 
                                                                        >> 0xaU))))) 
                                                           | ((8U 
                                                               & ((0x3ffff8U 
                                                                   & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                       [0x43U] 
                                                                       >> 0xaU) 
                                                                      & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                         [0x43U] 
                                                                         >> 9U))) 
                                                                  | (0xfffff8U 
                                                                     & (((0x7ffff8U 
                                                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x43U] 
                                                                             >> 9U)) 
                                                                         | (0x3ffff8U 
                                                                            & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x43U] 
                                                                               >> 0xaU))) 
                                                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                           [0x43U] 
                                                                           >> 8U))))) 
                                                              | ((4U 
                                                                  & ((0xfffffcU 
                                                                      & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x43U] 
                                                                          >> 8U) 
                                                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x43U] 
                                                                            >> 7U))) 
                                                                     | (0x3fffffcU 
                                                                        & (((0x1fffffcU 
                                                                             & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 7U)) 
                                                                            | (0xfffffcU 
                                                                               & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 8U))) 
                                                                           & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x43U] 
                                                                              >> 6U))))) 
                                                                 | ((2U 
                                                                     & ((0x3fffffeU 
                                                                         & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x43U] 
                                                                             >> 6U) 
                                                                            & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x43U] 
                                                                               >> 5U))) 
                                                                        | (0xffffffeU 
                                                                           & (((0x7fffffeU 
                                                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 5U)) 
                                                                               | (0x3fffffeU 
                                                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 6U))) 
                                                                              & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 4U))))) 
                                                                    | (1U 
                                                                       & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x43U] 
                                                                            >> 4U) 
                                                                           & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x43U] 
                                                                              >> 3U)) 
                                                                          | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x43U] 
                                                                               >> 3U) 
                                                                              | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 4U)) 
                                                                             & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 2U)))))))))))))))))),14);
    bufp->fullBit(oldp+5658,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5659,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5660,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5661,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5662,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5663,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5664,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5665,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 0xeU))),3);
    bufp->fullBit(oldp+5666,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x43U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 0xeU))))));
    bufp->fullBit(oldp+5667,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5668,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 0x10U))));
    bufp->fullBit(oldp+5669,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 0xfU))));
    bufp->fullBit(oldp+5670,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 0xeU))));
    bufp->fullCData(oldp+5671,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 0xbU))),3);
    bufp->fullBit(oldp+5672,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x43U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 0xbU))))));
    bufp->fullBit(oldp+5673,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5674,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 0xdU))));
    bufp->fullBit(oldp+5675,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 0xcU))));
    bufp->fullBit(oldp+5676,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 0xbU))));
    bufp->fullCData(oldp+5677,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 8U))),3);
    bufp->fullBit(oldp+5678,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x43U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 8U))))));
    bufp->fullBit(oldp+5679,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5680,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 0xaU))));
    bufp->fullBit(oldp+5681,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 9U))));
    bufp->fullBit(oldp+5682,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 8U))));
    bufp->fullCData(oldp+5683,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 5U))),3);
    bufp->fullBit(oldp+5684,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x43U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 5U))))));
    bufp->fullBit(oldp+5685,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5686,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 7U))));
    bufp->fullBit(oldp+5687,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 6U))));
    bufp->fullBit(oldp+5688,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 5U))));
    bufp->fullCData(oldp+5689,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 2U))),3);
    bufp->fullBit(oldp+5690,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x43U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 2U))))));
    bufp->fullBit(oldp+5691,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5692,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 4U))));
    bufp->fullBit(oldp+5693,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 3U))));
    bufp->fullBit(oldp+5694,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 2U))));
    bufp->fullCData(oldp+5695,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5696,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5697,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5698,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x43U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5699,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 1U)))));
    bufp->fullBit(oldp+5700,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5701,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x43U] >> 1U))));
    bufp->fullCData(oldp+5702,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x43U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5703,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x43U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5704,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5705,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x43U])));
    bufp->fullBit(oldp+5706,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5707,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5708,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5709,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5710,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5711,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5712,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5713,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5714,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5715,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5716,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5717,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5718,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5719,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5720,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5721,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5722,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5723,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5724,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5725,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5726,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5727,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5728,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5729,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5730,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5731,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5732,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5733,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5734,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5735,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5736,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5737,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullBit(oldp+5738,(vlSelf->clk));
    bufp->fullBit(oldp+5739,(vlSelf->rst_n));
    bufp->fullIData(oldp+5740,(vlSelf->multiplicand),32);
    bufp->fullIData(oldp+5741,(vlSelf->multiplier),32);
    bufp->fullBit(oldp+5742,(vlSelf->is_signed));
    bufp->fullQData(oldp+5743,(vlSelf->product),64);
    bufp->fullBit(oldp+5745,(vlSelf->valid));
    bufp->fullSData(oldp+5746,(0U),14);
    bufp->fullBit(oldp+5747,(0U));
    bufp->fullCData(oldp+5748,(0U),3);
}
