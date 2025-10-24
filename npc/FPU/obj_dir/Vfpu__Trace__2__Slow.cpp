// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfpu__Syms.h"


VL_ATTR_COLD void Vfpu___024root__trace_full_sub_2(Vfpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root__trace_full_sub_2\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+4743,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x37U] >> 5U))),3);
    bufp->fullBit(oldp+4744,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x37U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x37U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x37U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x37U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x37U] >> 5U))))));
    bufp->fullBit(oldp+4745,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4746,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 7U))));
    bufp->fullBit(oldp+4747,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 6U))));
    bufp->fullBit(oldp+4748,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 5U))));
    bufp->fullCData(oldp+4749,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x37U] >> 2U))),3);
    bufp->fullBit(oldp+4750,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x37U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x37U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x37U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x37U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x37U] >> 2U))))));
    bufp->fullBit(oldp+4751,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4752,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 4U))));
    bufp->fullBit(oldp+4753,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 3U))));
    bufp->fullBit(oldp+4754,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 2U))));
    bufp->fullCData(oldp+4755,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4756,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4757,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4758,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x37U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4759,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 1U)))));
    bufp->fullBit(oldp+4760,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4761,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 1U))));
    bufp->fullCData(oldp+4762,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x37U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4763,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x37U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x37U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4764,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4765,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x37U])));
    bufp->fullBit(oldp+4766,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4767,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4768,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4769,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4770,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4771,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4772,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4773,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4774,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4775,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4776,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4777,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4778,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4779,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4780,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4781,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4782,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4783,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4784,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4785,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4786,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4787,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4788,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4789,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4790,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4791,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4792,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4793,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4794,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4795,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4796,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4797,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4798,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x38U]),17);
    bufp->fullSData(oldp+4799,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4800,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4801,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4802,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4803,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4804,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4805,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4806,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4807,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x38U] >> 0xeU))),3);
    bufp->fullBit(oldp+4808,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x38U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x38U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x38U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x38U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x38U] >> 0xeU))))));
    bufp->fullBit(oldp+4809,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4810,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 0x10U))));
    bufp->fullBit(oldp+4811,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 0xfU))));
    bufp->fullBit(oldp+4812,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 0xeU))));
    bufp->fullCData(oldp+4813,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x38U] >> 0xbU))),3);
    bufp->fullBit(oldp+4814,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x38U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x38U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x38U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x38U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x38U] >> 0xbU))))));
    bufp->fullBit(oldp+4815,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4816,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 0xdU))));
    bufp->fullBit(oldp+4817,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 0xcU))));
    bufp->fullBit(oldp+4818,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 0xbU))));
    bufp->fullCData(oldp+4819,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x38U] >> 8U))),3);
    bufp->fullBit(oldp+4820,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x38U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x38U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x38U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x38U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x38U] >> 8U))))));
    bufp->fullBit(oldp+4821,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4822,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 0xaU))));
    bufp->fullBit(oldp+4823,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 9U))));
    bufp->fullBit(oldp+4824,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 8U))));
    bufp->fullCData(oldp+4825,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x38U] >> 5U))),3);
    bufp->fullBit(oldp+4826,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x38U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x38U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x38U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x38U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x38U] >> 5U))))));
    bufp->fullBit(oldp+4827,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4828,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 7U))));
    bufp->fullBit(oldp+4829,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 6U))));
    bufp->fullBit(oldp+4830,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 5U))));
    bufp->fullCData(oldp+4831,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x38U] >> 2U))),3);
    bufp->fullBit(oldp+4832,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x38U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x38U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x38U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x38U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x38U] >> 2U))))));
    bufp->fullBit(oldp+4833,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4834,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 4U))));
    bufp->fullBit(oldp+4835,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 3U))));
    bufp->fullBit(oldp+4836,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 2U))));
    bufp->fullCData(oldp+4837,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4838,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4839,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4840,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x38U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4841,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 1U)))));
    bufp->fullBit(oldp+4842,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4843,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x38U] >> 1U))));
    bufp->fullCData(oldp+4844,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x38U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4845,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x38U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4846,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4847,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x38U])));
    bufp->fullBit(oldp+4848,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4849,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4850,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4851,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4852,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4853,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4854,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4855,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4856,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4857,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4858,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4859,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4860,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4861,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4862,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4863,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4864,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4865,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4866,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4867,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4868,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4869,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4870,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4871,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4872,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4873,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4874,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4875,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4876,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4877,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4878,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4879,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4880,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x39U]),17);
    bufp->fullSData(oldp+4881,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4882,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4883,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4884,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4885,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4886,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4887,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4888,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4889,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 0xeU))),3);
    bufp->fullBit(oldp+4890,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x39U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x39U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x39U] >> 0xeU))))));
    bufp->fullBit(oldp+4891,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4892,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 0x10U))));
    bufp->fullBit(oldp+4893,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 0xfU))));
    bufp->fullBit(oldp+4894,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 0xeU))));
    bufp->fullCData(oldp+4895,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 0xbU))),3);
    bufp->fullBit(oldp+4896,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x39U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x39U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x39U] >> 0xbU))))));
    bufp->fullBit(oldp+4897,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4898,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 0xdU))));
    bufp->fullBit(oldp+4899,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 0xcU))));
    bufp->fullBit(oldp+4900,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 0xbU))));
    bufp->fullCData(oldp+4901,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 8U))),3);
    bufp->fullBit(oldp+4902,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x39U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x39U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x39U] >> 8U))))));
    bufp->fullBit(oldp+4903,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4904,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 0xaU))));
    bufp->fullBit(oldp+4905,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 9U))));
    bufp->fullBit(oldp+4906,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 8U))));
    bufp->fullCData(oldp+4907,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 5U))),3);
    bufp->fullBit(oldp+4908,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x39U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x39U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x39U] >> 5U))))));
    bufp->fullBit(oldp+4909,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4910,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 7U))));
    bufp->fullBit(oldp+4911,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 6U))));
    bufp->fullBit(oldp+4912,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 5U))));
    bufp->fullCData(oldp+4913,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 2U))),3);
    bufp->fullBit(oldp+4914,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x39U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x39U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x39U] >> 2U))))));
    bufp->fullBit(oldp+4915,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4916,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 4U))));
    bufp->fullBit(oldp+4917,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 3U))));
    bufp->fullBit(oldp+4918,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 2U))));
    bufp->fullCData(oldp+4919,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4920,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4921,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4922,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x39U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4923,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 1U)))));
    bufp->fullBit(oldp+4924,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4925,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x39U] >> 1U))));
    bufp->fullCData(oldp+4926,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x39U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4927,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x39U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4928,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4929,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x39U])));
    bufp->fullBit(oldp+4930,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4931,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4932,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4933,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4934,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4935,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4936,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4937,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4938,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4939,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4940,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4941,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4942,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4943,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4944,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4945,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4946,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4947,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4948,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4949,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4950,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4951,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4952,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4953,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4954,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4955,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4956,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4957,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4958,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4959,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4960,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4961,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4962,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x3aU]),17);
    bufp->fullSData(oldp+4963,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4964,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4965,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4966,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4967,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4968,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4969,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4970,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4971,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 0xeU))),3);
    bufp->fullBit(oldp+4972,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3aU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3aU] >> 0xeU))))));
    bufp->fullBit(oldp+4973,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4974,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 0x10U))));
    bufp->fullBit(oldp+4975,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 0xfU))));
    bufp->fullBit(oldp+4976,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 0xeU))));
    bufp->fullCData(oldp+4977,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 0xbU))),3);
    bufp->fullBit(oldp+4978,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3aU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3aU] >> 0xbU))))));
    bufp->fullBit(oldp+4979,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4980,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 0xdU))));
    bufp->fullBit(oldp+4981,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 0xcU))));
    bufp->fullBit(oldp+4982,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 0xbU))));
    bufp->fullCData(oldp+4983,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 8U))),3);
    bufp->fullBit(oldp+4984,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3aU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3aU] >> 8U))))));
    bufp->fullBit(oldp+4985,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4986,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 0xaU))));
    bufp->fullBit(oldp+4987,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 9U))));
    bufp->fullBit(oldp+4988,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 8U))));
    bufp->fullCData(oldp+4989,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 5U))),3);
    bufp->fullBit(oldp+4990,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3aU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3aU] >> 5U))))));
    bufp->fullBit(oldp+4991,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4992,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 7U))));
    bufp->fullBit(oldp+4993,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 6U))));
    bufp->fullBit(oldp+4994,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 5U))));
    bufp->fullCData(oldp+4995,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 2U))),3);
    bufp->fullBit(oldp+4996,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3aU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3aU] >> 2U))))));
    bufp->fullBit(oldp+4997,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4998,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 4U))));
    bufp->fullBit(oldp+4999,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 3U))));
    bufp->fullBit(oldp+5000,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 2U))));
    bufp->fullCData(oldp+5001,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5002,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5003,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5004,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x3aU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5005,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 1U)))));
    bufp->fullBit(oldp+5006,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5007,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3aU] >> 1U))));
    bufp->fullCData(oldp+5008,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x3aU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5009,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x3aU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5010,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5011,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x3aU])));
    bufp->fullBit(oldp+5012,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5013,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5014,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5015,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5016,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5017,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5018,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5019,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5020,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5021,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5022,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5023,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5024,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5025,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5026,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5027,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5028,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5029,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5030,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5031,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5032,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5033,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5034,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5035,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5036,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5037,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5038,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5039,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5040,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5041,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5042,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5043,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5044,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x3bU]),17);
    bufp->fullSData(oldp+5045,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5046,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5047,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5048,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5049,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5050,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5051,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5052,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5053,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 0xeU))),3);
    bufp->fullBit(oldp+5054,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3bU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3bU] >> 0xeU))))));
    bufp->fullBit(oldp+5055,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5056,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 0x10U))));
    bufp->fullBit(oldp+5057,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 0xfU))));
    bufp->fullBit(oldp+5058,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 0xeU))));
    bufp->fullCData(oldp+5059,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 0xbU))),3);
    bufp->fullBit(oldp+5060,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3bU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3bU] >> 0xbU))))));
    bufp->fullBit(oldp+5061,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5062,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 0xdU))));
    bufp->fullBit(oldp+5063,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 0xcU))));
    bufp->fullBit(oldp+5064,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 0xbU))));
    bufp->fullCData(oldp+5065,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 8U))),3);
    bufp->fullBit(oldp+5066,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3bU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3bU] >> 8U))))));
    bufp->fullBit(oldp+5067,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5068,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 0xaU))));
    bufp->fullBit(oldp+5069,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 9U))));
    bufp->fullBit(oldp+5070,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 8U))));
    bufp->fullCData(oldp+5071,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 5U))),3);
    bufp->fullBit(oldp+5072,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3bU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3bU] >> 5U))))));
    bufp->fullBit(oldp+5073,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5074,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 7U))));
    bufp->fullBit(oldp+5075,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 6U))));
    bufp->fullBit(oldp+5076,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 5U))));
    bufp->fullCData(oldp+5077,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 2U))),3);
    bufp->fullBit(oldp+5078,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3bU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3bU] >> 2U))))));
    bufp->fullBit(oldp+5079,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5080,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 4U))));
    bufp->fullBit(oldp+5081,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 3U))));
    bufp->fullBit(oldp+5082,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 2U))));
    bufp->fullCData(oldp+5083,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5084,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5085,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5086,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x3bU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5087,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 1U)))));
    bufp->fullBit(oldp+5088,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5089,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3bU] >> 1U))));
    bufp->fullCData(oldp+5090,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x3bU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5091,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x3bU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5092,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5093,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x3bU])));
    bufp->fullBit(oldp+5094,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5095,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5096,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5097,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5098,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5099,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5100,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5101,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5102,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5103,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5104,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5105,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5106,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5107,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5108,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5109,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5110,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5111,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5112,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5113,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5114,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5115,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5116,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5117,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5118,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5119,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5120,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5121,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5122,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5123,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5124,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5125,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5126,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x3cU]),17);
    bufp->fullSData(oldp+5127,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5128,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5129,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5130,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5131,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5132,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5133,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5134,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5135,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 0xeU))),3);
    bufp->fullBit(oldp+5136,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3cU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3cU] >> 0xeU))))));
    bufp->fullBit(oldp+5137,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5138,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 0x10U))));
    bufp->fullBit(oldp+5139,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 0xfU))));
    bufp->fullBit(oldp+5140,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 0xeU))));
    bufp->fullCData(oldp+5141,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 0xbU))),3);
    bufp->fullBit(oldp+5142,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3cU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3cU] >> 0xbU))))));
    bufp->fullBit(oldp+5143,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5144,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 0xdU))));
    bufp->fullBit(oldp+5145,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 0xcU))));
    bufp->fullBit(oldp+5146,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 0xbU))));
    bufp->fullCData(oldp+5147,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 8U))),3);
    bufp->fullBit(oldp+5148,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3cU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3cU] >> 8U))))));
    bufp->fullBit(oldp+5149,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5150,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 0xaU))));
    bufp->fullBit(oldp+5151,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 9U))));
    bufp->fullBit(oldp+5152,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 8U))));
    bufp->fullCData(oldp+5153,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 5U))),3);
    bufp->fullBit(oldp+5154,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3cU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3cU] >> 5U))))));
    bufp->fullBit(oldp+5155,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5156,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 7U))));
    bufp->fullBit(oldp+5157,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 6U))));
    bufp->fullBit(oldp+5158,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 5U))));
    bufp->fullCData(oldp+5159,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 2U))),3);
    bufp->fullBit(oldp+5160,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3cU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3cU] >> 2U))))));
    bufp->fullBit(oldp+5161,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5162,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 4U))));
    bufp->fullBit(oldp+5163,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 3U))));
    bufp->fullBit(oldp+5164,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 2U))));
    bufp->fullCData(oldp+5165,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5166,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5167,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5168,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x3cU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5169,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 1U)))));
    bufp->fullBit(oldp+5170,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5171,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3cU] >> 1U))));
    bufp->fullCData(oldp+5172,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x3cU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5173,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x3cU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5174,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5175,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x3cU])));
    bufp->fullBit(oldp+5176,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5177,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5178,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5179,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5180,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5181,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5182,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5183,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5184,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5185,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5186,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5187,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5188,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5189,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5190,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5191,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5192,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5193,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5194,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5195,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5196,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5197,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5198,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5199,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5200,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5201,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5202,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5203,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5204,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5205,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5206,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5207,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5208,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x3dU]),17);
    bufp->fullSData(oldp+5209,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5210,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5211,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5212,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5213,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5214,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5215,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5216,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5217,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 0xeU))),3);
    bufp->fullBit(oldp+5218,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3dU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3dU] >> 0xeU))))));
    bufp->fullBit(oldp+5219,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5220,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 0x10U))));
    bufp->fullBit(oldp+5221,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 0xfU))));
    bufp->fullBit(oldp+5222,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 0xeU))));
    bufp->fullCData(oldp+5223,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 0xbU))),3);
    bufp->fullBit(oldp+5224,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3dU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3dU] >> 0xbU))))));
    bufp->fullBit(oldp+5225,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5226,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 0xdU))));
    bufp->fullBit(oldp+5227,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 0xcU))));
    bufp->fullBit(oldp+5228,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 0xbU))));
    bufp->fullCData(oldp+5229,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 8U))),3);
    bufp->fullBit(oldp+5230,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3dU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3dU] >> 8U))))));
    bufp->fullBit(oldp+5231,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5232,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 0xaU))));
    bufp->fullBit(oldp+5233,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 9U))));
    bufp->fullBit(oldp+5234,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 8U))));
    bufp->fullCData(oldp+5235,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 5U))),3);
    bufp->fullBit(oldp+5236,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3dU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3dU] >> 5U))))));
    bufp->fullBit(oldp+5237,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5238,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 7U))));
    bufp->fullBit(oldp+5239,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 6U))));
    bufp->fullBit(oldp+5240,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 5U))));
    bufp->fullCData(oldp+5241,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 2U))),3);
    bufp->fullBit(oldp+5242,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3dU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3dU] >> 2U))))));
    bufp->fullBit(oldp+5243,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5244,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 4U))));
    bufp->fullBit(oldp+5245,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 3U))));
    bufp->fullBit(oldp+5246,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 2U))));
    bufp->fullCData(oldp+5247,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5248,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5249,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5250,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x3dU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5251,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 1U)))));
    bufp->fullBit(oldp+5252,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5253,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3dU] >> 1U))));
    bufp->fullCData(oldp+5254,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x3dU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5255,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x3dU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5256,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5257,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x3dU])));
    bufp->fullBit(oldp+5258,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5259,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5260,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5261,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5262,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5263,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5264,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5265,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5266,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5267,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5268,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5269,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5270,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5271,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5272,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5273,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5274,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5275,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5276,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5277,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5278,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5279,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5280,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5281,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5282,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5283,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5284,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5285,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5286,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5287,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5288,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5289,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5290,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x3eU]),17);
    bufp->fullSData(oldp+5291,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5292,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5293,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5294,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5295,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5296,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5297,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5298,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5299,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 0xeU))),3);
    bufp->fullBit(oldp+5300,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3eU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3eU] >> 0xeU))))));
    bufp->fullBit(oldp+5301,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5302,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 0x10U))));
    bufp->fullBit(oldp+5303,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 0xfU))));
    bufp->fullBit(oldp+5304,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 0xeU))));
    bufp->fullCData(oldp+5305,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 0xbU))),3);
    bufp->fullBit(oldp+5306,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3eU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3eU] >> 0xbU))))));
    bufp->fullBit(oldp+5307,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5308,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 0xdU))));
    bufp->fullBit(oldp+5309,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 0xcU))));
    bufp->fullBit(oldp+5310,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 0xbU))));
    bufp->fullCData(oldp+5311,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 8U))),3);
    bufp->fullBit(oldp+5312,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3eU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3eU] >> 8U))))));
    bufp->fullBit(oldp+5313,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5314,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 0xaU))));
    bufp->fullBit(oldp+5315,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 9U))));
    bufp->fullBit(oldp+5316,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 8U))));
    bufp->fullCData(oldp+5317,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 5U))),3);
    bufp->fullBit(oldp+5318,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3eU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3eU] >> 5U))))));
    bufp->fullBit(oldp+5319,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5320,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 7U))));
    bufp->fullBit(oldp+5321,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 6U))));
    bufp->fullBit(oldp+5322,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 5U))));
    bufp->fullCData(oldp+5323,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 2U))),3);
    bufp->fullBit(oldp+5324,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3eU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3eU] >> 2U))))));
    bufp->fullBit(oldp+5325,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5326,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 4U))));
    bufp->fullBit(oldp+5327,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 3U))));
    bufp->fullBit(oldp+5328,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 2U))));
    bufp->fullCData(oldp+5329,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5330,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5331,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5332,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x3eU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5333,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 1U)))));
    bufp->fullBit(oldp+5334,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5335,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3eU] >> 1U))));
    bufp->fullCData(oldp+5336,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x3eU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5337,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x3eU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5338,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5339,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x3eU])));
    bufp->fullBit(oldp+5340,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5341,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5342,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5343,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5344,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5345,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5346,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5347,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5348,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5349,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5350,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5351,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5352,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5353,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5354,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5355,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5356,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5357,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5358,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5359,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5360,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5361,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5362,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5363,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5364,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5365,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5366,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5367,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5368,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5369,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5370,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5371,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5372,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x3fU]),17);
    bufp->fullSData(oldp+5373,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5374,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5375,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5376,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5377,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5378,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5379,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5380,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5381,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 0xeU))),3);
    bufp->fullBit(oldp+5382,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3fU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3fU] >> 0xeU))))));
    bufp->fullBit(oldp+5383,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5384,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 0x10U))));
    bufp->fullBit(oldp+5385,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 0xfU))));
    bufp->fullBit(oldp+5386,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 0xeU))));
    bufp->fullCData(oldp+5387,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 0xbU))),3);
    bufp->fullBit(oldp+5388,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3fU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3fU] >> 0xbU))))));
    bufp->fullBit(oldp+5389,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5390,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 0xdU))));
    bufp->fullBit(oldp+5391,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 0xcU))));
    bufp->fullBit(oldp+5392,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 0xbU))));
    bufp->fullCData(oldp+5393,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 8U))),3);
    bufp->fullBit(oldp+5394,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3fU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3fU] >> 8U))))));
    bufp->fullBit(oldp+5395,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5396,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 0xaU))));
    bufp->fullBit(oldp+5397,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 9U))));
    bufp->fullBit(oldp+5398,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 8U))));
    bufp->fullCData(oldp+5399,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 5U))),3);
    bufp->fullBit(oldp+5400,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3fU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3fU] >> 5U))))));
    bufp->fullBit(oldp+5401,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5402,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 7U))));
    bufp->fullBit(oldp+5403,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 6U))));
    bufp->fullBit(oldp+5404,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 5U))));
    bufp->fullCData(oldp+5405,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 2U))),3);
    bufp->fullBit(oldp+5406,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3fU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3fU] >> 2U))))));
    bufp->fullBit(oldp+5407,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5408,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 4U))));
    bufp->fullBit(oldp+5409,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 3U))));
    bufp->fullBit(oldp+5410,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 2U))));
    bufp->fullCData(oldp+5411,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5412,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5413,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5414,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x3fU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5415,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 1U)))));
    bufp->fullBit(oldp+5416,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5417,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x3fU] >> 1U))));
    bufp->fullCData(oldp+5418,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x3fU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5419,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x3fU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5420,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5421,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x3fU])));
    bufp->fullBit(oldp+5422,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5423,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5424,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5425,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5426,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5427,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5428,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5429,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5430,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5431,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5432,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5433,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5434,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5435,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5436,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5437,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5438,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5439,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5440,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5441,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5442,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5443,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5444,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5445,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5446,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5447,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5448,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5449,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5450,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5451,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5452,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5453,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5454,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x40U]),17);
    bufp->fullSData(oldp+5455,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5456,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5457,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5458,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5459,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5460,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5461,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5462,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5463,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 0xeU))),3);
    bufp->fullBit(oldp+5464,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x40U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x40U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x40U] >> 0xeU))))));
    bufp->fullBit(oldp+5465,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5466,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 0x10U))));
    bufp->fullBit(oldp+5467,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 0xfU))));
    bufp->fullBit(oldp+5468,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 0xeU))));
    bufp->fullCData(oldp+5469,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 0xbU))),3);
    bufp->fullBit(oldp+5470,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x40U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x40U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x40U] >> 0xbU))))));
    bufp->fullBit(oldp+5471,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5472,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 0xdU))));
    bufp->fullBit(oldp+5473,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 0xcU))));
    bufp->fullBit(oldp+5474,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 0xbU))));
    bufp->fullCData(oldp+5475,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 8U))),3);
    bufp->fullBit(oldp+5476,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x40U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x40U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x40U] >> 8U))))));
    bufp->fullBit(oldp+5477,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5478,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 0xaU))));
    bufp->fullBit(oldp+5479,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 9U))));
    bufp->fullBit(oldp+5480,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 8U))));
    bufp->fullCData(oldp+5481,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 5U))),3);
    bufp->fullBit(oldp+5482,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x40U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x40U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x40U] >> 5U))))));
    bufp->fullBit(oldp+5483,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5484,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 7U))));
    bufp->fullBit(oldp+5485,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 6U))));
    bufp->fullBit(oldp+5486,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 5U))));
    bufp->fullCData(oldp+5487,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 2U))),3);
    bufp->fullBit(oldp+5488,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x40U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x40U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x40U] >> 2U))))));
    bufp->fullBit(oldp+5489,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5490,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 4U))));
    bufp->fullBit(oldp+5491,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 3U))));
    bufp->fullBit(oldp+5492,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 2U))));
    bufp->fullCData(oldp+5493,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5494,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5495,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5496,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x40U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5497,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 1U)))));
    bufp->fullBit(oldp+5498,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5499,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x40U] >> 1U))));
    bufp->fullCData(oldp+5500,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x40U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5501,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x40U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5502,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5503,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x40U])));
    bufp->fullBit(oldp+5504,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5505,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5506,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5507,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5508,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5509,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5510,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5511,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5512,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5513,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5514,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5515,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5516,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5517,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5518,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5519,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5520,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5521,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5522,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5523,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5524,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5525,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5526,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5527,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5528,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5529,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5530,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5531,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5532,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5533,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5534,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5535,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5536,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x41U]),17);
    bufp->fullSData(oldp+5537,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5538,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5539,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5540,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5541,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5542,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5543,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5544,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5545,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 0xeU))),3);
    bufp->fullBit(oldp+5546,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x41U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x41U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x41U] >> 0xeU))))));
    bufp->fullBit(oldp+5547,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5548,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 0x10U))));
    bufp->fullBit(oldp+5549,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 0xfU))));
    bufp->fullBit(oldp+5550,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 0xeU))));
    bufp->fullCData(oldp+5551,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 0xbU))),3);
    bufp->fullBit(oldp+5552,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x41U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x41U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x41U] >> 0xbU))))));
    bufp->fullBit(oldp+5553,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5554,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 0xdU))));
    bufp->fullBit(oldp+5555,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 0xcU))));
    bufp->fullBit(oldp+5556,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 0xbU))));
    bufp->fullCData(oldp+5557,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 8U))),3);
    bufp->fullBit(oldp+5558,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x41U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x41U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x41U] >> 8U))))));
    bufp->fullBit(oldp+5559,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5560,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 0xaU))));
    bufp->fullBit(oldp+5561,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 9U))));
    bufp->fullBit(oldp+5562,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 8U))));
    bufp->fullCData(oldp+5563,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 5U))),3);
    bufp->fullBit(oldp+5564,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x41U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x41U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x41U] >> 5U))))));
    bufp->fullBit(oldp+5565,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5566,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 7U))));
    bufp->fullBit(oldp+5567,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 6U))));
    bufp->fullBit(oldp+5568,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 5U))));
    bufp->fullCData(oldp+5569,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 2U))),3);
    bufp->fullBit(oldp+5570,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x41U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x41U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x41U] >> 2U))))));
    bufp->fullBit(oldp+5571,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5572,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 4U))));
    bufp->fullBit(oldp+5573,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 3U))));
    bufp->fullBit(oldp+5574,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 2U))));
    bufp->fullCData(oldp+5575,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5576,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5577,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5578,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x41U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5579,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 1U)))));
    bufp->fullBit(oldp+5580,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5581,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x41U] >> 1U))));
    bufp->fullCData(oldp+5582,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x41U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5583,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x41U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5584,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5585,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x41U])));
    bufp->fullBit(oldp+5586,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5587,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5588,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5589,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5590,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5591,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5592,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5593,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5594,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5595,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5596,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5597,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5598,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5599,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5600,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5601,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5602,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5603,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5604,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5605,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5606,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5607,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5608,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5609,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5610,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5611,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5612,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5613,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5614,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5615,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5616,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5617,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5618,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x42U]),17);
    bufp->fullSData(oldp+5619,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+5620,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5621,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5622,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5623,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5624,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5625,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5626,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5627,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 0xeU))),3);
    bufp->fullBit(oldp+5628,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x42U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x42U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x42U] >> 0xeU))))));
    bufp->fullBit(oldp+5629,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5630,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 0x10U))));
    bufp->fullBit(oldp+5631,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 0xfU))));
    bufp->fullBit(oldp+5632,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 0xeU))));
    bufp->fullCData(oldp+5633,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 0xbU))),3);
    bufp->fullBit(oldp+5634,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x42U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x42U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x42U] >> 0xbU))))));
    bufp->fullBit(oldp+5635,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5636,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 0xdU))));
    bufp->fullBit(oldp+5637,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 0xcU))));
    bufp->fullBit(oldp+5638,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 0xbU))));
    bufp->fullCData(oldp+5639,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 8U))),3);
    bufp->fullBit(oldp+5640,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x42U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x42U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x42U] >> 8U))))));
    bufp->fullBit(oldp+5641,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5642,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 0xaU))));
    bufp->fullBit(oldp+5643,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 9U))));
    bufp->fullBit(oldp+5644,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 8U))));
    bufp->fullCData(oldp+5645,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 5U))),3);
    bufp->fullBit(oldp+5646,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x42U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x42U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x42U] >> 5U))))));
    bufp->fullBit(oldp+5647,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5648,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 7U))));
    bufp->fullBit(oldp+5649,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 6U))));
    bufp->fullBit(oldp+5650,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 5U))));
    bufp->fullCData(oldp+5651,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 2U))),3);
    bufp->fullBit(oldp+5652,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x42U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x42U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x42U] >> 2U))))));
    bufp->fullBit(oldp+5653,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5654,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 4U))));
    bufp->fullBit(oldp+5655,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 3U))));
    bufp->fullBit(oldp+5656,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 2U))));
    bufp->fullCData(oldp+5657,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5658,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5659,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5660,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x42U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5661,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 1U)))));
    bufp->fullBit(oldp+5662,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5663,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x42U] >> 1U))));
    bufp->fullCData(oldp+5664,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x42U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5665,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x42U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5666,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5667,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x42U])));
    bufp->fullBit(oldp+5668,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5669,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5670,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5671,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5672,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5673,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5674,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5675,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5676,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5677,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5678,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5679,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5680,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5681,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5682,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5683,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5684,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5685,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5686,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5687,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5688,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5689,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5690,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5691,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5692,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5693,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5694,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5695,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5696,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5697,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5698,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5699,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+5700,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x43U]),17);
    bufp->fullSData(oldp+5701,((((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s)) 
                                  << 0xdU) | (0xffffe000U 
                                              & ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s)) 
                                                  << 0xdU) 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                    << 2U)))) 
                                | (((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s)) 
                                     << 0xcU) | (0xfffff000U 
                                                 & ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s) 
                                                      | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s)) 
                                                     << 0xcU) 
                                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                       << 2U)))) 
                                   | ((0x800U & (((IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                                  << 0xbU) 
                                                 | (0xfffff800U 
                                                    & (((IData)(
                                                                (0U 
                                                                 != 
                                                                 (0x300U 
                                                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                                        << 0xbU) 
                                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                          << 4U))))) 
                                      | (((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                                            & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s)) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                               | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s)) 
                                              & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s))) 
                                          << 0xaU) 
                                         | ((0x200U 
                                             & ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s) 
                                                  << 9U) 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                    << 3U)) 
                                                | (((0xfffffe00U 
                                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                        << 3U)) 
                                                    | ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s) 
                                                       << 9U)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                      << 4U)))) 
                                            | (((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s)) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s)) 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s))) 
                                                << 8U) 
                                               | (((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s)) 
                                                    << 7U) 
                                                   | (0xffffff80U 
                                                      & ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s) 
                                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s)) 
                                                          << 7U) 
                                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                            [0x43U] 
                                                            << 6U)))) 
                                                  | ((0x40U 
                                                      & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                           [0x43U] 
                                                           << 6U) 
                                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                             << 2U)) 
                                                         | (((0xffffffc0U 
                                                              & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                                 << 2U)) 
                                                             | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                [0x43U] 
                                                                << 6U)) 
                                                            & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                               << 3U)))) 
                                                     | ((0x20U 
                                                         & (((IData)(
                                                                     (6U 
                                                                      == 
                                                                      (6U 
                                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                                             | ((IData)(
                                                                        (0U 
                                                                         != 
                                                                         (6U 
                                                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))) 
                                                            << 5U)) 
                                                        | ((0x10U 
                                                            & ((0xffff0U 
                                                                & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                    [0x43U] 
                                                                    >> 0xcU) 
                                                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                      [0x43U] 
                                                                      >> 0xbU))) 
                                                               | (0x3ffff0U 
                                                                  & (((0x1ffff0U 
                                                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                          [0x43U] 
                                                                          >> 0xbU)) 
                                                                      | (0xffff0U 
                                                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                            [0x43U] 
                                                                            >> 0xcU))) 
                                                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                        [0x43U] 
                                                                        >> 0xaU))))) 
                                                           | ((8U 
                                                               & ((0x3ffff8U 
                                                                   & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                       [0x43U] 
                                                                       >> 0xaU) 
                                                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                         [0x43U] 
                                                                         >> 9U))) 
                                                                  | (0xfffff8U 
                                                                     & (((0x7ffff8U 
                                                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                             [0x43U] 
                                                                             >> 9U)) 
                                                                         | (0x3ffff8U 
                                                                            & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                               [0x43U] 
                                                                               >> 0xaU))) 
                                                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                           [0x43U] 
                                                                           >> 8U))))) 
                                                              | ((4U 
                                                                  & ((0xfffffcU 
                                                                      & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                          [0x43U] 
                                                                          >> 8U) 
                                                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                            [0x43U] 
                                                                            >> 7U))) 
                                                                     | (0x3fffffcU 
                                                                        & (((0x1fffffcU 
                                                                             & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 7U)) 
                                                                            | (0xfffffcU 
                                                                               & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 8U))) 
                                                                           & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                              [0x43U] 
                                                                              >> 6U))))) 
                                                                 | ((2U 
                                                                     & ((0x3fffffeU 
                                                                         & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                             [0x43U] 
                                                                             >> 6U) 
                                                                            & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                               [0x43U] 
                                                                               >> 5U))) 
                                                                        | (0xffffffeU 
                                                                           & (((0x7fffffeU 
                                                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 5U)) 
                                                                               | (0x3fffffeU 
                                                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 6U))) 
                                                                              & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 4U))))) 
                                                                    | (1U 
                                                                       & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                            [0x43U] 
                                                                            >> 4U) 
                                                                           & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                              [0x43U] 
                                                                              >> 3U)) 
                                                                          | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                               [0x43U] 
                                                                               >> 3U) 
                                                                              | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 4U)) 
                                                                             & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                                [0x43U] 
                                                                                >> 2U)))))))))))))))))),14);
    bufp->fullBit(oldp+5702,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.cout));
    bufp->fullBit(oldp+5703,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+5704,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+5705,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+5706,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+5707,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+5708,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+5709,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 0xeU))),3);
    bufp->fullBit(oldp+5710,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x43U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x43U] >> 0xeU))))));
    bufp->fullBit(oldp+5711,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+5712,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 0x10U))));
    bufp->fullBit(oldp+5713,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 0xfU))));
    bufp->fullBit(oldp+5714,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 0xeU))));
    bufp->fullCData(oldp+5715,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 0xbU))),3);
    bufp->fullBit(oldp+5716,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x43U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x43U] >> 0xbU))))));
    bufp->fullBit(oldp+5717,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+5718,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 0xdU))));
    bufp->fullBit(oldp+5719,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 0xcU))));
    bufp->fullBit(oldp+5720,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 0xbU))));
    bufp->fullCData(oldp+5721,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 8U))),3);
    bufp->fullBit(oldp+5722,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x43U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x43U] >> 8U))))));
    bufp->fullBit(oldp+5723,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+5724,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 0xaU))));
    bufp->fullBit(oldp+5725,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 9U))));
    bufp->fullBit(oldp+5726,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 8U))));
    bufp->fullCData(oldp+5727,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 5U))),3);
    bufp->fullBit(oldp+5728,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x43U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x43U] >> 5U))))));
    bufp->fullBit(oldp+5729,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+5730,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 7U))));
    bufp->fullBit(oldp+5731,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 6U))));
    bufp->fullBit(oldp+5732,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 5U))));
    bufp->fullCData(oldp+5733,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 2U))),3);
    bufp->fullBit(oldp+5734,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x43U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x43U] >> 2U))))));
    bufp->fullBit(oldp+5735,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+5736,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 4U))));
    bufp->fullBit(oldp+5737,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 3U))));
    bufp->fullBit(oldp+5738,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 2U))));
    bufp->fullCData(oldp+5739,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+5740,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+5741,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+5742,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x43U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+5743,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 1U)))));
    bufp->fullBit(oldp+5744,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+5745,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x43U] >> 1U))));
    bufp->fullCData(oldp+5746,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x43U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+5747,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x43U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+5748,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+5749,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x43U])));
    bufp->fullBit(oldp+5750,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+5751,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+5752,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+5753,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+5754,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+5755,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+5756,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+5757,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+5758,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+5759,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+5760,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+5761,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+5762,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+5763,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+5764,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+5765,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+5766,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+5767,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+5768,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+5769,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+5770,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+5771,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+5772,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+5773,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+5774,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+5775,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+5776,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+5777,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+5778,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+5779,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+5780,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+5781,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullCData(oldp+5782,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__state),2);
    bufp->fullIData(oldp+5783,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__temp_result),32);
    bufp->fullIData(oldp+5784,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__temp_int_result),32);
    bufp->fullCData(oldp+5785,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__temp_exception),5);
    bufp->fullSData(oldp+5786,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__stored_true_exp1),9);
    bufp->fullSData(oldp+5787,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__stored_true_exp2),9);
    bufp->fullQData(oldp+5788,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_product),64);
    bufp->fullBit(oldp+5790,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_valid));
    bufp->fullIData(oldp+5791,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0]),32);
    bufp->fullIData(oldp+5792,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[1]),32);
    bufp->fullIData(oldp+5793,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[2]),32);
    bufp->fullIData(oldp+5794,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[3]),32);
    bufp->fullIData(oldp+5795,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[4]),32);
    bufp->fullIData(oldp+5796,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[5]),32);
    bufp->fullIData(oldp+5797,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[6]),32);
    bufp->fullIData(oldp+5798,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[7]),32);
    bufp->fullIData(oldp+5799,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[8]),32);
    bufp->fullIData(oldp+5800,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[9]),32);
    bufp->fullIData(oldp+5801,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[10]),32);
    bufp->fullIData(oldp+5802,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[11]),32);
    bufp->fullIData(oldp+5803,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[12]),32);
    bufp->fullIData(oldp+5804,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[13]),32);
    bufp->fullIData(oldp+5805,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[14]),32);
    bufp->fullIData(oldp+5806,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[15]),32);
    bufp->fullIData(oldp+5807,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[16]),32);
    bufp->fullIData(oldp+5808,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[17]),32);
    bufp->fullIData(oldp+5809,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[18]),32);
    bufp->fullIData(oldp+5810,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[19]),32);
    bufp->fullIData(oldp+5811,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[20]),32);
    bufp->fullIData(oldp+5812,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[21]),32);
    bufp->fullIData(oldp+5813,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[22]),32);
    bufp->fullIData(oldp+5814,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[23]),32);
    bufp->fullIData(oldp+5815,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[24]),32);
    bufp->fullIData(oldp+5816,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[25]),32);
    bufp->fullIData(oldp+5817,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[26]),32);
    bufp->fullIData(oldp+5818,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[27]),32);
    bufp->fullIData(oldp+5819,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[28]),32);
    bufp->fullIData(oldp+5820,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[29]),32);
    bufp->fullIData(oldp+5821,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[30]),32);
    bufp->fullIData(oldp+5822,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[31]),32);
    bufp->fullIData(oldp+5823,(vlSelf->fpu_tb__DOT__freg_inst__DOT__i),32);
    bufp->fullBit(oldp+5824,(vlSelf->clk));
    bufp->fullBit(oldp+5825,(vlSelf->reset));
    bufp->fullCData(oldp+5826,(vlSelf->freg_rs1),5);
    bufp->fullCData(oldp+5827,(vlSelf->freg_rs2),5);
    bufp->fullCData(oldp+5828,(vlSelf->freg_rd),5);
    bufp->fullIData(oldp+5829,(vlSelf->freg_write_data),32);
    bufp->fullBit(oldp+5830,(vlSelf->freg_write_en));
    bufp->fullIData(oldp+5831,(vlSelf->freg_read_data1),32);
    bufp->fullIData(oldp+5832,(vlSelf->freg_read_data2),32);
    bufp->fullBit(oldp+5833,(vlSelf->fpu_op_valid));
    bufp->fullCData(oldp+5834,(vlSelf->fpu_op_type),6);
    bufp->fullCData(oldp+5835,(vlSelf->fpu_op_round),3);
    bufp->fullIData(oldp+5836,(vlSelf->operand1_fp),32);
    bufp->fullIData(oldp+5837,(vlSelf->operand2_fp),32);
    bufp->fullIData(oldp+5838,(vlSelf->operand3_fp),32);
    bufp->fullIData(oldp+5839,(vlSelf->operand4_int),32);
    bufp->fullBit(oldp+5840,(vlSelf->downstream_valid));
    bufp->fullBit(oldp+5841,(vlSelf->fpu_ready));
    bufp->fullIData(oldp+5842,(vlSelf->fpu_result),32);
    bufp->fullIData(oldp+5843,(vlSelf->int_result),32);
    bufp->fullCData(oldp+5844,(vlSelf->exception_flags),5);
    bufp->fullBit(oldp+5845,(vlSelf->fpu_result_valid));
    bufp->fullBit(oldp+5846,((vlSelf->operand1_fp >> 0x1fU)));
    bufp->fullCData(oldp+5847,((0xffU & (vlSelf->operand1_fp 
                                         >> 0x17U))),8);
    bufp->fullIData(oldp+5848,((0x7fffffU & vlSelf->operand1_fp)),23);
    bufp->fullBit(oldp+5849,((vlSelf->operand2_fp >> 0x1fU)));
    bufp->fullCData(oldp+5850,((0xffU & (vlSelf->operand2_fp 
                                         >> 0x17U))),8);
    bufp->fullIData(oldp+5851,((0x7fffffU & vlSelf->operand2_fp)),23);
    bufp->fullBit(oldp+5852,((1U & (~ (IData)(vlSelf->reset)))));
    bufp->fullBit(oldp+5853,(0U));
    bufp->fullCData(oldp+5854,(1U),6);
    bufp->fullCData(oldp+5855,(2U),6);
    bufp->fullCData(oldp+5856,(3U),6);
    bufp->fullCData(oldp+5857,(4U),6);
    bufp->fullCData(oldp+5858,(5U),6);
    bufp->fullCData(oldp+5859,(6U),6);
    bufp->fullCData(oldp+5860,(7U),6);
    bufp->fullCData(oldp+5861,(8U),6);
    bufp->fullCData(oldp+5862,(9U),6);
    bufp->fullCData(oldp+5863,(0xaU),6);
    bufp->fullCData(oldp+5864,(0xbU),6);
    bufp->fullCData(oldp+5865,(0xcU),6);
    bufp->fullCData(oldp+5866,(0xdU),6);
    bufp->fullCData(oldp+5867,(0xeU),6);
    bufp->fullCData(oldp+5868,(0xfU),6);
    bufp->fullCData(oldp+5869,(0x10U),6);
    bufp->fullCData(oldp+5870,(0U),2);
    bufp->fullCData(oldp+5871,(1U),2);
    bufp->fullCData(oldp+5872,(3U),2);
    bufp->fullCData(oldp+5873,(2U),2);
    bufp->fullBit(oldp+5874,(1U));
    bufp->fullBit(oldp+5875,(0U));
    bufp->fullSData(oldp+5876,(0U),14);
    bufp->fullCData(oldp+5877,(0U),3);
}
