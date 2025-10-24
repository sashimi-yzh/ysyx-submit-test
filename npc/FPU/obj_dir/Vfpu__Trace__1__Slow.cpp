// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfpu__Syms.h"


VL_ATTR_COLD void Vfpu___024root__trace_full_sub_1(Vfpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root__trace_full_sub_1\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+2431,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2432,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 0x10U))));
    bufp->fullBit(oldp+2433,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 0xfU))));
    bufp->fullBit(oldp+2434,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 0xeU))));
    bufp->fullCData(oldp+2435,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1bU] >> 0xbU))),3);
    bufp->fullBit(oldp+2436,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1bU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1bU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1bU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1bU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1bU] >> 0xbU))))));
    bufp->fullBit(oldp+2437,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2438,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 0xdU))));
    bufp->fullBit(oldp+2439,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 0xcU))));
    bufp->fullBit(oldp+2440,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 0xbU))));
    bufp->fullCData(oldp+2441,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1bU] >> 8U))),3);
    bufp->fullBit(oldp+2442,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1bU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1bU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1bU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1bU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1bU] >> 8U))))));
    bufp->fullBit(oldp+2443,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2444,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 0xaU))));
    bufp->fullBit(oldp+2445,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 9U))));
    bufp->fullBit(oldp+2446,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 8U))));
    bufp->fullCData(oldp+2447,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1bU] >> 5U))),3);
    bufp->fullBit(oldp+2448,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1bU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1bU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1bU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1bU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1bU] >> 5U))))));
    bufp->fullBit(oldp+2449,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2450,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 7U))));
    bufp->fullBit(oldp+2451,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 6U))));
    bufp->fullBit(oldp+2452,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 5U))));
    bufp->fullCData(oldp+2453,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1bU] >> 2U))),3);
    bufp->fullBit(oldp+2454,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1bU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1bU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1bU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1bU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1bU] >> 2U))))));
    bufp->fullBit(oldp+2455,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2456,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 4U))));
    bufp->fullBit(oldp+2457,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 3U))));
    bufp->fullBit(oldp+2458,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 2U))));
    bufp->fullCData(oldp+2459,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2460,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2461,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2462,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x1bU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2463,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 1U)))));
    bufp->fullBit(oldp+2464,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2465,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1bU] >> 1U))));
    bufp->fullCData(oldp+2466,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1bU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2467,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x1bU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1bU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2468,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2469,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x1bU])));
    bufp->fullBit(oldp+2470,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2471,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2472,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2473,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2474,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2475,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2476,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2477,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2478,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2479,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2480,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2481,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2482,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2483,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2484,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2485,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2486,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2487,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2488,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2489,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2490,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2491,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2492,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2493,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2494,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2495,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2496,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2497,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2498,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2499,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2500,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2501,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2502,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x1cU]),17);
    bufp->fullSData(oldp+2503,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2504,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2505,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2506,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2507,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+2508,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+2509,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+2510,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+2511,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1cU] >> 0xeU))),3);
    bufp->fullBit(oldp+2512,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1cU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1cU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1cU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1cU] >> 0xeU))))));
    bufp->fullBit(oldp+2513,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2514,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 0x10U))));
    bufp->fullBit(oldp+2515,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 0xfU))));
    bufp->fullBit(oldp+2516,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 0xeU))));
    bufp->fullCData(oldp+2517,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1cU] >> 0xbU))),3);
    bufp->fullBit(oldp+2518,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1cU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1cU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1cU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1cU] >> 0xbU))))));
    bufp->fullBit(oldp+2519,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2520,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 0xdU))));
    bufp->fullBit(oldp+2521,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 0xcU))));
    bufp->fullBit(oldp+2522,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 0xbU))));
    bufp->fullCData(oldp+2523,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1cU] >> 8U))),3);
    bufp->fullBit(oldp+2524,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1cU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1cU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1cU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1cU] >> 8U))))));
    bufp->fullBit(oldp+2525,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2526,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 0xaU))));
    bufp->fullBit(oldp+2527,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 9U))));
    bufp->fullBit(oldp+2528,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 8U))));
    bufp->fullCData(oldp+2529,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1cU] >> 5U))),3);
    bufp->fullBit(oldp+2530,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1cU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1cU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1cU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1cU] >> 5U))))));
    bufp->fullBit(oldp+2531,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2532,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 7U))));
    bufp->fullBit(oldp+2533,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 6U))));
    bufp->fullBit(oldp+2534,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 5U))));
    bufp->fullCData(oldp+2535,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1cU] >> 2U))),3);
    bufp->fullBit(oldp+2536,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1cU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1cU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1cU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1cU] >> 2U))))));
    bufp->fullBit(oldp+2537,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2538,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 4U))));
    bufp->fullBit(oldp+2539,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 3U))));
    bufp->fullBit(oldp+2540,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 2U))));
    bufp->fullCData(oldp+2541,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2542,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2543,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2544,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x1cU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2545,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 1U)))));
    bufp->fullBit(oldp+2546,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2547,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1cU] >> 1U))));
    bufp->fullCData(oldp+2548,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1cU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2549,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x1cU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1cU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2550,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2551,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x1cU])));
    bufp->fullBit(oldp+2552,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2553,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2554,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2555,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2556,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2557,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2558,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2559,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2560,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2561,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2562,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2563,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2564,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2565,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2566,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2567,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2568,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2569,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2570,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2571,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2572,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2573,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2574,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2575,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2576,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2577,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2578,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2579,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2580,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2581,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2582,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2583,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2584,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x1dU]),17);
    bufp->fullSData(oldp+2585,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2586,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2587,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2588,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2589,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+2590,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+2591,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+2592,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+2593,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1dU] >> 0xeU))),3);
    bufp->fullBit(oldp+2594,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1dU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1dU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1dU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1dU] >> 0xeU))))));
    bufp->fullBit(oldp+2595,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2596,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 0x10U))));
    bufp->fullBit(oldp+2597,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 0xfU))));
    bufp->fullBit(oldp+2598,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 0xeU))));
    bufp->fullCData(oldp+2599,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1dU] >> 0xbU))),3);
    bufp->fullBit(oldp+2600,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1dU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1dU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1dU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1dU] >> 0xbU))))));
    bufp->fullBit(oldp+2601,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2602,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 0xdU))));
    bufp->fullBit(oldp+2603,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 0xcU))));
    bufp->fullBit(oldp+2604,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 0xbU))));
    bufp->fullCData(oldp+2605,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1dU] >> 8U))),3);
    bufp->fullBit(oldp+2606,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1dU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1dU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1dU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1dU] >> 8U))))));
    bufp->fullBit(oldp+2607,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2608,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 0xaU))));
    bufp->fullBit(oldp+2609,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 9U))));
    bufp->fullBit(oldp+2610,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 8U))));
    bufp->fullCData(oldp+2611,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1dU] >> 5U))),3);
    bufp->fullBit(oldp+2612,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1dU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1dU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1dU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1dU] >> 5U))))));
    bufp->fullBit(oldp+2613,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2614,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 7U))));
    bufp->fullBit(oldp+2615,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 6U))));
    bufp->fullBit(oldp+2616,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 5U))));
    bufp->fullCData(oldp+2617,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1dU] >> 2U))),3);
    bufp->fullBit(oldp+2618,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1dU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1dU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1dU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1dU] >> 2U))))));
    bufp->fullBit(oldp+2619,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2620,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 4U))));
    bufp->fullBit(oldp+2621,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 3U))));
    bufp->fullBit(oldp+2622,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 2U))));
    bufp->fullCData(oldp+2623,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2624,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2625,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2626,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x1dU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2627,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 1U)))));
    bufp->fullBit(oldp+2628,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2629,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1dU] >> 1U))));
    bufp->fullCData(oldp+2630,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1dU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2631,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x1dU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1dU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2632,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2633,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x1dU])));
    bufp->fullBit(oldp+2634,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2635,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2636,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2637,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2638,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2639,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2640,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2641,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2642,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2643,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2644,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2645,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2646,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2647,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2648,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2649,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2650,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2651,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2652,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2653,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2654,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2655,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2656,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2657,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2658,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2659,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2660,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2661,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2662,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2663,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2664,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2665,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2666,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x1eU]),17);
    bufp->fullSData(oldp+2667,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2668,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2669,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2670,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2671,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+2672,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+2673,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+2674,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+2675,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1eU] >> 0xeU))),3);
    bufp->fullBit(oldp+2676,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1eU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1eU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1eU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1eU] >> 0xeU))))));
    bufp->fullBit(oldp+2677,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2678,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 0x10U))));
    bufp->fullBit(oldp+2679,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 0xfU))));
    bufp->fullBit(oldp+2680,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 0xeU))));
    bufp->fullCData(oldp+2681,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1eU] >> 0xbU))),3);
    bufp->fullBit(oldp+2682,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1eU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1eU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1eU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1eU] >> 0xbU))))));
    bufp->fullBit(oldp+2683,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2684,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 0xdU))));
    bufp->fullBit(oldp+2685,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 0xcU))));
    bufp->fullBit(oldp+2686,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 0xbU))));
    bufp->fullCData(oldp+2687,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1eU] >> 8U))),3);
    bufp->fullBit(oldp+2688,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1eU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1eU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1eU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1eU] >> 8U))))));
    bufp->fullBit(oldp+2689,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2690,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 0xaU))));
    bufp->fullBit(oldp+2691,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 9U))));
    bufp->fullBit(oldp+2692,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 8U))));
    bufp->fullCData(oldp+2693,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1eU] >> 5U))),3);
    bufp->fullBit(oldp+2694,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1eU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1eU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1eU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1eU] >> 5U))))));
    bufp->fullBit(oldp+2695,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2696,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 7U))));
    bufp->fullBit(oldp+2697,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 6U))));
    bufp->fullBit(oldp+2698,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 5U))));
    bufp->fullCData(oldp+2699,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1eU] >> 2U))),3);
    bufp->fullBit(oldp+2700,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1eU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1eU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1eU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1eU] >> 2U))))));
    bufp->fullBit(oldp+2701,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2702,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 4U))));
    bufp->fullBit(oldp+2703,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 3U))));
    bufp->fullBit(oldp+2704,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 2U))));
    bufp->fullCData(oldp+2705,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2706,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2707,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2708,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x1eU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2709,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 1U)))));
    bufp->fullBit(oldp+2710,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2711,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1eU] >> 1U))));
    bufp->fullCData(oldp+2712,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1eU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2713,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x1eU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1eU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2714,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2715,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x1eU])));
    bufp->fullBit(oldp+2716,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2717,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2718,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2719,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2720,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2721,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2722,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2723,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2724,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2725,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2726,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2727,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2728,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2729,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2730,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2731,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2732,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2733,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2734,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2735,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2736,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2737,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2738,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2739,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2740,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2741,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2742,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2743,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2744,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2745,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2746,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2747,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2748,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x1fU]),17);
    bufp->fullSData(oldp+2749,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2750,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2751,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2752,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2753,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+2754,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+2755,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+2756,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+2757,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1fU] >> 0xeU))),3);
    bufp->fullBit(oldp+2758,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1fU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1fU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1fU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1fU] >> 0xeU))))));
    bufp->fullBit(oldp+2759,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2760,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 0x10U))));
    bufp->fullBit(oldp+2761,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 0xfU))));
    bufp->fullBit(oldp+2762,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 0xeU))));
    bufp->fullCData(oldp+2763,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1fU] >> 0xbU))),3);
    bufp->fullBit(oldp+2764,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1fU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1fU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1fU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1fU] >> 0xbU))))));
    bufp->fullBit(oldp+2765,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2766,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 0xdU))));
    bufp->fullBit(oldp+2767,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 0xcU))));
    bufp->fullBit(oldp+2768,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 0xbU))));
    bufp->fullCData(oldp+2769,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1fU] >> 8U))),3);
    bufp->fullBit(oldp+2770,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1fU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1fU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1fU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1fU] >> 8U))))));
    bufp->fullBit(oldp+2771,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2772,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 0xaU))));
    bufp->fullBit(oldp+2773,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 9U))));
    bufp->fullBit(oldp+2774,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 8U))));
    bufp->fullCData(oldp+2775,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1fU] >> 5U))),3);
    bufp->fullBit(oldp+2776,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1fU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1fU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1fU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1fU] >> 5U))))));
    bufp->fullBit(oldp+2777,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2778,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 7U))));
    bufp->fullBit(oldp+2779,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 6U))));
    bufp->fullBit(oldp+2780,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 5U))));
    bufp->fullCData(oldp+2781,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1fU] >> 2U))),3);
    bufp->fullBit(oldp+2782,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x1fU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1fU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1fU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1fU] >> 2U))))));
    bufp->fullBit(oldp+2783,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2784,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 4U))));
    bufp->fullBit(oldp+2785,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 3U))));
    bufp->fullBit(oldp+2786,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 2U))));
    bufp->fullCData(oldp+2787,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2788,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2789,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2790,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x1fU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2791,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 1U)))));
    bufp->fullBit(oldp+2792,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2793,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x1fU] >> 1U))));
    bufp->fullCData(oldp+2794,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1fU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2795,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x1fU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1fU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2796,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2797,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x1fU])));
    bufp->fullBit(oldp+2798,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2799,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2800,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2801,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2802,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2803,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2804,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2805,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2806,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2807,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2808,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2809,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2810,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2811,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2812,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2813,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2814,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2815,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2816,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2817,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2818,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2819,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2820,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2821,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2822,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2823,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2824,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2825,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2826,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2827,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2828,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2829,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2830,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x20U]),17);
    bufp->fullSData(oldp+2831,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2832,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2833,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2834,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2835,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+2836,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+2837,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+2838,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+2839,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x20U] >> 0xeU))),3);
    bufp->fullBit(oldp+2840,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x20U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x20U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x20U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x20U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x20U] >> 0xeU))))));
    bufp->fullBit(oldp+2841,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2842,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 0x10U))));
    bufp->fullBit(oldp+2843,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 0xfU))));
    bufp->fullBit(oldp+2844,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 0xeU))));
    bufp->fullCData(oldp+2845,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x20U] >> 0xbU))),3);
    bufp->fullBit(oldp+2846,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x20U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x20U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x20U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x20U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x20U] >> 0xbU))))));
    bufp->fullBit(oldp+2847,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2848,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 0xdU))));
    bufp->fullBit(oldp+2849,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 0xcU))));
    bufp->fullBit(oldp+2850,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 0xbU))));
    bufp->fullCData(oldp+2851,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x20U] >> 8U))),3);
    bufp->fullBit(oldp+2852,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x20U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x20U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x20U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x20U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x20U] >> 8U))))));
    bufp->fullBit(oldp+2853,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2854,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 0xaU))));
    bufp->fullBit(oldp+2855,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 9U))));
    bufp->fullBit(oldp+2856,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 8U))));
    bufp->fullCData(oldp+2857,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x20U] >> 5U))),3);
    bufp->fullBit(oldp+2858,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x20U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x20U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x20U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x20U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x20U] >> 5U))))));
    bufp->fullBit(oldp+2859,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2860,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 7U))));
    bufp->fullBit(oldp+2861,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 6U))));
    bufp->fullBit(oldp+2862,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 5U))));
    bufp->fullCData(oldp+2863,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x20U] >> 2U))),3);
    bufp->fullBit(oldp+2864,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x20U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x20U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x20U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x20U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x20U] >> 2U))))));
    bufp->fullBit(oldp+2865,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2866,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 4U))));
    bufp->fullBit(oldp+2867,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 3U))));
    bufp->fullBit(oldp+2868,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 2U))));
    bufp->fullCData(oldp+2869,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2870,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2871,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2872,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x20U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2873,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 1U)))));
    bufp->fullBit(oldp+2874,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2875,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x20U] >> 1U))));
    bufp->fullCData(oldp+2876,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x20U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2877,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x20U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x20U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2878,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2879,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x20U])));
    bufp->fullBit(oldp+2880,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2881,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2882,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2883,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2884,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2885,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2886,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2887,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2888,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2889,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2890,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2891,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2892,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2893,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2894,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2895,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2896,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2897,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2898,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2899,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2900,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2901,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2902,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2903,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2904,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2905,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2906,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2907,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2908,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2909,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2910,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2911,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2912,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x21U]),17);
    bufp->fullSData(oldp+2913,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2914,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2915,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2916,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2917,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+2918,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+2919,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+2920,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+2921,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x21U] >> 0xeU))),3);
    bufp->fullBit(oldp+2922,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x21U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x21U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x21U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x21U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x21U] >> 0xeU))))));
    bufp->fullBit(oldp+2923,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2924,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 0x10U))));
    bufp->fullBit(oldp+2925,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 0xfU))));
    bufp->fullBit(oldp+2926,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 0xeU))));
    bufp->fullCData(oldp+2927,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x21U] >> 0xbU))),3);
    bufp->fullBit(oldp+2928,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x21U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x21U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x21U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x21U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x21U] >> 0xbU))))));
    bufp->fullBit(oldp+2929,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2930,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 0xdU))));
    bufp->fullBit(oldp+2931,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 0xcU))));
    bufp->fullBit(oldp+2932,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 0xbU))));
    bufp->fullCData(oldp+2933,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x21U] >> 8U))),3);
    bufp->fullBit(oldp+2934,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x21U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x21U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x21U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x21U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x21U] >> 8U))))));
    bufp->fullBit(oldp+2935,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2936,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 0xaU))));
    bufp->fullBit(oldp+2937,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 9U))));
    bufp->fullBit(oldp+2938,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 8U))));
    bufp->fullCData(oldp+2939,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x21U] >> 5U))),3);
    bufp->fullBit(oldp+2940,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x21U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x21U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x21U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x21U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x21U] >> 5U))))));
    bufp->fullBit(oldp+2941,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2942,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 7U))));
    bufp->fullBit(oldp+2943,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 6U))));
    bufp->fullBit(oldp+2944,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 5U))));
    bufp->fullCData(oldp+2945,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x21U] >> 2U))),3);
    bufp->fullBit(oldp+2946,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x21U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x21U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x21U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x21U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x21U] >> 2U))))));
    bufp->fullBit(oldp+2947,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2948,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 4U))));
    bufp->fullBit(oldp+2949,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 3U))));
    bufp->fullBit(oldp+2950,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 2U))));
    bufp->fullCData(oldp+2951,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2952,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2953,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2954,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x21U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2955,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 1U)))));
    bufp->fullBit(oldp+2956,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2957,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x21U] >> 1U))));
    bufp->fullCData(oldp+2958,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x21U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2959,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x21U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x21U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2960,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2961,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x21U])));
    bufp->fullBit(oldp+2962,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2963,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2964,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2965,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2966,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2967,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2968,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2969,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2970,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2971,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2972,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2973,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2974,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2975,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2976,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2977,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2978,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2979,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2980,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2981,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2982,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2983,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2984,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2985,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2986,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2987,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2988,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2989,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2990,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2991,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2992,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2993,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2994,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x22U]),17);
    bufp->fullSData(oldp+2995,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2996,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2997,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2998,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2999,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3000,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3001,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3002,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3003,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x22U] >> 0xeU))),3);
    bufp->fullBit(oldp+3004,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x22U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x22U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x22U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x22U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x22U] >> 0xeU))))));
    bufp->fullBit(oldp+3005,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3006,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 0x10U))));
    bufp->fullBit(oldp+3007,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 0xfU))));
    bufp->fullBit(oldp+3008,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 0xeU))));
    bufp->fullCData(oldp+3009,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x22U] >> 0xbU))),3);
    bufp->fullBit(oldp+3010,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x22U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x22U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x22U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x22U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x22U] >> 0xbU))))));
    bufp->fullBit(oldp+3011,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3012,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 0xdU))));
    bufp->fullBit(oldp+3013,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 0xcU))));
    bufp->fullBit(oldp+3014,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 0xbU))));
    bufp->fullCData(oldp+3015,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x22U] >> 8U))),3);
    bufp->fullBit(oldp+3016,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x22U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x22U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x22U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x22U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x22U] >> 8U))))));
    bufp->fullBit(oldp+3017,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3018,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 0xaU))));
    bufp->fullBit(oldp+3019,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 9U))));
    bufp->fullBit(oldp+3020,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 8U))));
    bufp->fullCData(oldp+3021,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x22U] >> 5U))),3);
    bufp->fullBit(oldp+3022,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x22U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x22U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x22U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x22U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x22U] >> 5U))))));
    bufp->fullBit(oldp+3023,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3024,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 7U))));
    bufp->fullBit(oldp+3025,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 6U))));
    bufp->fullBit(oldp+3026,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 5U))));
    bufp->fullCData(oldp+3027,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x22U] >> 2U))),3);
    bufp->fullBit(oldp+3028,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x22U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x22U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x22U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x22U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x22U] >> 2U))))));
    bufp->fullBit(oldp+3029,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3030,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 4U))));
    bufp->fullBit(oldp+3031,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 3U))));
    bufp->fullBit(oldp+3032,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 2U))));
    bufp->fullCData(oldp+3033,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3034,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3035,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3036,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x22U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3037,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 1U)))));
    bufp->fullBit(oldp+3038,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3039,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x22U] >> 1U))));
    bufp->fullCData(oldp+3040,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x22U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3041,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x22U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x22U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3042,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3043,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x22U])));
    bufp->fullBit(oldp+3044,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3045,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3046,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3047,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3048,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3049,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3050,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3051,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3052,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3053,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3054,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3055,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3056,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3057,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3058,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3059,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3060,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3061,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3062,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3063,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3064,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3065,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3066,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3067,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3068,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3069,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3070,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3071,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3072,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3073,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3074,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3075,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3076,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x23U]),17);
    bufp->fullSData(oldp+3077,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3078,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3079,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3080,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3081,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3082,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3083,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3084,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3085,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x23U] >> 0xeU))),3);
    bufp->fullBit(oldp+3086,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x23U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x23U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x23U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x23U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x23U] >> 0xeU))))));
    bufp->fullBit(oldp+3087,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3088,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 0x10U))));
    bufp->fullBit(oldp+3089,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 0xfU))));
    bufp->fullBit(oldp+3090,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 0xeU))));
    bufp->fullCData(oldp+3091,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x23U] >> 0xbU))),3);
    bufp->fullBit(oldp+3092,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x23U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x23U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x23U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x23U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x23U] >> 0xbU))))));
    bufp->fullBit(oldp+3093,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3094,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 0xdU))));
    bufp->fullBit(oldp+3095,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 0xcU))));
    bufp->fullBit(oldp+3096,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 0xbU))));
    bufp->fullCData(oldp+3097,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x23U] >> 8U))),3);
    bufp->fullBit(oldp+3098,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x23U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x23U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x23U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x23U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x23U] >> 8U))))));
    bufp->fullBit(oldp+3099,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3100,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 0xaU))));
    bufp->fullBit(oldp+3101,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 9U))));
    bufp->fullBit(oldp+3102,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 8U))));
    bufp->fullCData(oldp+3103,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x23U] >> 5U))),3);
    bufp->fullBit(oldp+3104,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x23U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x23U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x23U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x23U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x23U] >> 5U))))));
    bufp->fullBit(oldp+3105,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3106,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 7U))));
    bufp->fullBit(oldp+3107,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 6U))));
    bufp->fullBit(oldp+3108,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 5U))));
    bufp->fullCData(oldp+3109,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x23U] >> 2U))),3);
    bufp->fullBit(oldp+3110,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x23U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x23U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x23U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x23U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x23U] >> 2U))))));
    bufp->fullBit(oldp+3111,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3112,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 4U))));
    bufp->fullBit(oldp+3113,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 3U))));
    bufp->fullBit(oldp+3114,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 2U))));
    bufp->fullCData(oldp+3115,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3116,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3117,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3118,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x23U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3119,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 1U)))));
    bufp->fullBit(oldp+3120,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3121,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x23U] >> 1U))));
    bufp->fullCData(oldp+3122,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x23U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3123,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x23U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x23U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3124,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3125,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x23U])));
    bufp->fullBit(oldp+3126,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3127,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3128,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3129,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3130,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3131,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3132,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3133,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3134,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3135,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3136,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3137,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3138,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3139,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3140,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3141,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3142,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3143,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3144,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3145,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3146,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3147,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3148,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3149,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3150,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3151,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3152,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3153,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3154,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3155,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3156,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3157,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3158,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x24U]),17);
    bufp->fullSData(oldp+3159,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3160,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3161,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3162,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3163,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3164,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3165,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3166,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3167,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x24U] >> 0xeU))),3);
    bufp->fullBit(oldp+3168,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x24U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x24U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x24U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x24U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x24U] >> 0xeU))))));
    bufp->fullBit(oldp+3169,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3170,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 0x10U))));
    bufp->fullBit(oldp+3171,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 0xfU))));
    bufp->fullBit(oldp+3172,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 0xeU))));
    bufp->fullCData(oldp+3173,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x24U] >> 0xbU))),3);
    bufp->fullBit(oldp+3174,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x24U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x24U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x24U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x24U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x24U] >> 0xbU))))));
    bufp->fullBit(oldp+3175,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3176,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 0xdU))));
    bufp->fullBit(oldp+3177,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 0xcU))));
    bufp->fullBit(oldp+3178,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 0xbU))));
    bufp->fullCData(oldp+3179,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x24U] >> 8U))),3);
    bufp->fullBit(oldp+3180,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x24U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x24U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x24U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x24U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x24U] >> 8U))))));
    bufp->fullBit(oldp+3181,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3182,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 0xaU))));
    bufp->fullBit(oldp+3183,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 9U))));
    bufp->fullBit(oldp+3184,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 8U))));
    bufp->fullCData(oldp+3185,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x24U] >> 5U))),3);
    bufp->fullBit(oldp+3186,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x24U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x24U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x24U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x24U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x24U] >> 5U))))));
    bufp->fullBit(oldp+3187,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3188,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 7U))));
    bufp->fullBit(oldp+3189,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 6U))));
    bufp->fullBit(oldp+3190,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 5U))));
    bufp->fullCData(oldp+3191,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x24U] >> 2U))),3);
    bufp->fullBit(oldp+3192,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x24U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x24U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x24U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x24U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x24U] >> 2U))))));
    bufp->fullBit(oldp+3193,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3194,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 4U))));
    bufp->fullBit(oldp+3195,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 3U))));
    bufp->fullBit(oldp+3196,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 2U))));
    bufp->fullCData(oldp+3197,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3198,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3199,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3200,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x24U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3201,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 1U)))));
    bufp->fullBit(oldp+3202,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3203,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x24U] >> 1U))));
    bufp->fullCData(oldp+3204,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x24U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3205,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x24U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x24U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3206,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3207,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x24U])));
    bufp->fullBit(oldp+3208,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3209,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3210,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3211,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3212,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3213,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3214,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3215,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3216,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3217,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3218,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3219,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3220,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3221,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3222,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3223,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3224,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3225,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3226,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3227,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3228,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3229,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3230,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3231,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3232,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3233,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3234,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3235,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3236,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3237,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3238,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3239,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3240,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x25U]),17);
    bufp->fullSData(oldp+3241,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3242,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3243,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3244,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3245,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3246,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3247,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3248,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3249,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x25U] >> 0xeU))),3);
    bufp->fullBit(oldp+3250,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x25U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x25U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x25U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x25U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x25U] >> 0xeU))))));
    bufp->fullBit(oldp+3251,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3252,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 0x10U))));
    bufp->fullBit(oldp+3253,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 0xfU))));
    bufp->fullBit(oldp+3254,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 0xeU))));
    bufp->fullCData(oldp+3255,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x25U] >> 0xbU))),3);
    bufp->fullBit(oldp+3256,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x25U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x25U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x25U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x25U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x25U] >> 0xbU))))));
    bufp->fullBit(oldp+3257,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3258,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 0xdU))));
    bufp->fullBit(oldp+3259,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 0xcU))));
    bufp->fullBit(oldp+3260,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 0xbU))));
    bufp->fullCData(oldp+3261,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x25U] >> 8U))),3);
    bufp->fullBit(oldp+3262,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x25U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x25U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x25U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x25U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x25U] >> 8U))))));
    bufp->fullBit(oldp+3263,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3264,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 0xaU))));
    bufp->fullBit(oldp+3265,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 9U))));
    bufp->fullBit(oldp+3266,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 8U))));
    bufp->fullCData(oldp+3267,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x25U] >> 5U))),3);
    bufp->fullBit(oldp+3268,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x25U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x25U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x25U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x25U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x25U] >> 5U))))));
    bufp->fullBit(oldp+3269,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3270,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 7U))));
    bufp->fullBit(oldp+3271,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 6U))));
    bufp->fullBit(oldp+3272,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 5U))));
    bufp->fullCData(oldp+3273,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x25U] >> 2U))),3);
    bufp->fullBit(oldp+3274,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x25U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x25U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x25U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x25U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x25U] >> 2U))))));
    bufp->fullBit(oldp+3275,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3276,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 4U))));
    bufp->fullBit(oldp+3277,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 3U))));
    bufp->fullBit(oldp+3278,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 2U))));
    bufp->fullCData(oldp+3279,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3280,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3281,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3282,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x25U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3283,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 1U)))));
    bufp->fullBit(oldp+3284,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3285,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x25U] >> 1U))));
    bufp->fullCData(oldp+3286,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x25U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3287,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x25U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x25U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3288,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3289,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x25U])));
    bufp->fullBit(oldp+3290,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3291,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3292,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3293,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3294,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3295,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3296,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3297,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3298,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3299,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3300,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3301,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3302,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3303,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3304,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3305,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3306,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3307,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3308,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3309,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3310,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3311,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3312,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3313,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3314,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3315,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3316,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3317,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3318,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3319,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3320,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3321,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3322,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x26U]),17);
    bufp->fullSData(oldp+3323,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3324,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3325,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3326,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3327,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3328,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3329,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3330,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3331,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x26U] >> 0xeU))),3);
    bufp->fullBit(oldp+3332,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x26U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x26U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x26U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x26U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x26U] >> 0xeU))))));
    bufp->fullBit(oldp+3333,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3334,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 0x10U))));
    bufp->fullBit(oldp+3335,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 0xfU))));
    bufp->fullBit(oldp+3336,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 0xeU))));
    bufp->fullCData(oldp+3337,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x26U] >> 0xbU))),3);
    bufp->fullBit(oldp+3338,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x26U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x26U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x26U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x26U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x26U] >> 0xbU))))));
    bufp->fullBit(oldp+3339,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3340,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 0xdU))));
    bufp->fullBit(oldp+3341,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 0xcU))));
    bufp->fullBit(oldp+3342,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 0xbU))));
    bufp->fullCData(oldp+3343,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x26U] >> 8U))),3);
    bufp->fullBit(oldp+3344,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x26U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x26U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x26U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x26U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x26U] >> 8U))))));
    bufp->fullBit(oldp+3345,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3346,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 0xaU))));
    bufp->fullBit(oldp+3347,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 9U))));
    bufp->fullBit(oldp+3348,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 8U))));
    bufp->fullCData(oldp+3349,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x26U] >> 5U))),3);
    bufp->fullBit(oldp+3350,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x26U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x26U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x26U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x26U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x26U] >> 5U))))));
    bufp->fullBit(oldp+3351,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3352,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 7U))));
    bufp->fullBit(oldp+3353,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 6U))));
    bufp->fullBit(oldp+3354,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 5U))));
    bufp->fullCData(oldp+3355,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x26U] >> 2U))),3);
    bufp->fullBit(oldp+3356,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x26U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x26U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x26U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x26U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x26U] >> 2U))))));
    bufp->fullBit(oldp+3357,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3358,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 4U))));
    bufp->fullBit(oldp+3359,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 3U))));
    bufp->fullBit(oldp+3360,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 2U))));
    bufp->fullCData(oldp+3361,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3362,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3363,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3364,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x26U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3365,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 1U)))));
    bufp->fullBit(oldp+3366,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3367,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x26U] >> 1U))));
    bufp->fullCData(oldp+3368,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x26U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3369,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x26U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x26U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3370,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3371,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x26U])));
    bufp->fullBit(oldp+3372,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3373,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3374,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3375,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3376,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3377,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3378,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3379,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3380,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3381,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3382,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3383,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3384,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3385,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3386,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3387,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3388,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3389,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3390,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3391,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3392,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3393,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3394,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3395,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3396,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3397,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3398,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3399,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3400,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3401,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3402,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3403,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3404,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x27U]),17);
    bufp->fullSData(oldp+3405,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3406,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3407,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3408,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3409,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3410,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3411,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3412,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3413,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x27U] >> 0xeU))),3);
    bufp->fullBit(oldp+3414,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x27U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x27U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x27U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x27U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x27U] >> 0xeU))))));
    bufp->fullBit(oldp+3415,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3416,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 0x10U))));
    bufp->fullBit(oldp+3417,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 0xfU))));
    bufp->fullBit(oldp+3418,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 0xeU))));
    bufp->fullCData(oldp+3419,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x27U] >> 0xbU))),3);
    bufp->fullBit(oldp+3420,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x27U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x27U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x27U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x27U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x27U] >> 0xbU))))));
    bufp->fullBit(oldp+3421,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3422,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 0xdU))));
    bufp->fullBit(oldp+3423,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 0xcU))));
    bufp->fullBit(oldp+3424,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 0xbU))));
    bufp->fullCData(oldp+3425,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x27U] >> 8U))),3);
    bufp->fullBit(oldp+3426,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x27U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x27U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x27U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x27U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x27U] >> 8U))))));
    bufp->fullBit(oldp+3427,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3428,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 0xaU))));
    bufp->fullBit(oldp+3429,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 9U))));
    bufp->fullBit(oldp+3430,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 8U))));
    bufp->fullCData(oldp+3431,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x27U] >> 5U))),3);
    bufp->fullBit(oldp+3432,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x27U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x27U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x27U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x27U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x27U] >> 5U))))));
    bufp->fullBit(oldp+3433,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3434,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 7U))));
    bufp->fullBit(oldp+3435,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 6U))));
    bufp->fullBit(oldp+3436,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 5U))));
    bufp->fullCData(oldp+3437,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x27U] >> 2U))),3);
    bufp->fullBit(oldp+3438,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x27U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x27U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x27U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x27U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x27U] >> 2U))))));
    bufp->fullBit(oldp+3439,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3440,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 4U))));
    bufp->fullBit(oldp+3441,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 3U))));
    bufp->fullBit(oldp+3442,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 2U))));
    bufp->fullCData(oldp+3443,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3444,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3445,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3446,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x27U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3447,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 1U)))));
    bufp->fullBit(oldp+3448,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3449,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x27U] >> 1U))));
    bufp->fullCData(oldp+3450,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x27U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3451,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x27U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x27U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3452,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3453,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x27U])));
    bufp->fullBit(oldp+3454,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3455,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3456,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3457,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3458,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3459,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3460,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3461,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3462,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3463,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3464,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3465,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3466,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3467,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3468,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3469,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3470,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3471,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3472,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3473,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3474,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3475,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3476,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3477,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3478,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3479,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3480,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3481,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3482,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3483,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3484,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3485,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3486,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x28U]),17);
    bufp->fullSData(oldp+3487,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3488,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3489,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3490,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3491,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3492,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3493,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3494,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3495,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x28U] >> 0xeU))),3);
    bufp->fullBit(oldp+3496,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x28U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x28U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x28U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x28U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x28U] >> 0xeU))))));
    bufp->fullBit(oldp+3497,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3498,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 0x10U))));
    bufp->fullBit(oldp+3499,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 0xfU))));
    bufp->fullBit(oldp+3500,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 0xeU))));
    bufp->fullCData(oldp+3501,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x28U] >> 0xbU))),3);
    bufp->fullBit(oldp+3502,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x28U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x28U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x28U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x28U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x28U] >> 0xbU))))));
    bufp->fullBit(oldp+3503,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3504,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 0xdU))));
    bufp->fullBit(oldp+3505,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 0xcU))));
    bufp->fullBit(oldp+3506,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 0xbU))));
    bufp->fullCData(oldp+3507,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x28U] >> 8U))),3);
    bufp->fullBit(oldp+3508,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x28U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x28U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x28U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x28U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x28U] >> 8U))))));
    bufp->fullBit(oldp+3509,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3510,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 0xaU))));
    bufp->fullBit(oldp+3511,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 9U))));
    bufp->fullBit(oldp+3512,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 8U))));
    bufp->fullCData(oldp+3513,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x28U] >> 5U))),3);
    bufp->fullBit(oldp+3514,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x28U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x28U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x28U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x28U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x28U] >> 5U))))));
    bufp->fullBit(oldp+3515,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3516,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 7U))));
    bufp->fullBit(oldp+3517,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 6U))));
    bufp->fullBit(oldp+3518,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 5U))));
    bufp->fullCData(oldp+3519,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x28U] >> 2U))),3);
    bufp->fullBit(oldp+3520,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x28U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x28U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x28U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x28U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x28U] >> 2U))))));
    bufp->fullBit(oldp+3521,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3522,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 4U))));
    bufp->fullBit(oldp+3523,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 3U))));
    bufp->fullBit(oldp+3524,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 2U))));
    bufp->fullCData(oldp+3525,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3526,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3527,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3528,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x28U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3529,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 1U)))));
    bufp->fullBit(oldp+3530,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3531,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x28U] >> 1U))));
    bufp->fullCData(oldp+3532,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x28U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3533,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x28U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x28U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3534,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3535,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x28U])));
    bufp->fullBit(oldp+3536,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3537,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3538,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3539,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3540,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3541,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3542,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3543,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3544,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3545,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3546,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3547,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3548,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3549,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3550,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3551,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3552,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3553,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3554,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3555,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3556,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3557,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3558,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3559,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3560,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3561,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3562,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3563,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3564,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3565,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3566,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3567,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3568,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x29U]),17);
    bufp->fullSData(oldp+3569,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3570,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3571,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3572,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3573,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3574,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3575,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3576,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3577,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x29U] >> 0xeU))),3);
    bufp->fullBit(oldp+3578,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x29U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x29U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x29U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x29U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x29U] >> 0xeU))))));
    bufp->fullBit(oldp+3579,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3580,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 0x10U))));
    bufp->fullBit(oldp+3581,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 0xfU))));
    bufp->fullBit(oldp+3582,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 0xeU))));
    bufp->fullCData(oldp+3583,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x29U] >> 0xbU))),3);
    bufp->fullBit(oldp+3584,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x29U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x29U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x29U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x29U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x29U] >> 0xbU))))));
    bufp->fullBit(oldp+3585,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3586,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 0xdU))));
    bufp->fullBit(oldp+3587,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 0xcU))));
    bufp->fullBit(oldp+3588,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 0xbU))));
    bufp->fullCData(oldp+3589,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x29U] >> 8U))),3);
    bufp->fullBit(oldp+3590,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x29U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x29U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x29U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x29U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x29U] >> 8U))))));
    bufp->fullBit(oldp+3591,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3592,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 0xaU))));
    bufp->fullBit(oldp+3593,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 9U))));
    bufp->fullBit(oldp+3594,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 8U))));
    bufp->fullCData(oldp+3595,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x29U] >> 5U))),3);
    bufp->fullBit(oldp+3596,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x29U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x29U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x29U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x29U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x29U] >> 5U))))));
    bufp->fullBit(oldp+3597,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3598,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 7U))));
    bufp->fullBit(oldp+3599,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 6U))));
    bufp->fullBit(oldp+3600,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 5U))));
    bufp->fullCData(oldp+3601,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x29U] >> 2U))),3);
    bufp->fullBit(oldp+3602,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x29U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x29U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x29U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x29U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x29U] >> 2U))))));
    bufp->fullBit(oldp+3603,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3604,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 4U))));
    bufp->fullBit(oldp+3605,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 3U))));
    bufp->fullBit(oldp+3606,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 2U))));
    bufp->fullCData(oldp+3607,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3608,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3609,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3610,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x29U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3611,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 1U)))));
    bufp->fullBit(oldp+3612,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3613,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x29U] >> 1U))));
    bufp->fullCData(oldp+3614,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x29U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3615,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x29U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x29U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3616,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3617,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x29U])));
    bufp->fullBit(oldp+3618,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3619,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3620,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3621,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3622,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3623,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3624,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3625,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3626,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3627,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3628,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3629,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3630,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3631,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3632,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3633,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3634,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3635,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3636,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3637,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3638,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3639,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3640,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3641,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3642,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3643,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3644,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3645,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3646,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3647,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3648,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3649,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3650,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x2aU]),17);
    bufp->fullSData(oldp+3651,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3652,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3653,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3654,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3655,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3656,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3657,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3658,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3659,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2aU] >> 0xeU))),3);
    bufp->fullBit(oldp+3660,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2aU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2aU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2aU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2aU] >> 0xeU))))));
    bufp->fullBit(oldp+3661,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3662,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 0x10U))));
    bufp->fullBit(oldp+3663,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 0xfU))));
    bufp->fullBit(oldp+3664,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 0xeU))));
    bufp->fullCData(oldp+3665,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2aU] >> 0xbU))),3);
    bufp->fullBit(oldp+3666,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2aU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2aU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2aU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2aU] >> 0xbU))))));
    bufp->fullBit(oldp+3667,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3668,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 0xdU))));
    bufp->fullBit(oldp+3669,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 0xcU))));
    bufp->fullBit(oldp+3670,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 0xbU))));
    bufp->fullCData(oldp+3671,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2aU] >> 8U))),3);
    bufp->fullBit(oldp+3672,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2aU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2aU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2aU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2aU] >> 8U))))));
    bufp->fullBit(oldp+3673,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3674,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 0xaU))));
    bufp->fullBit(oldp+3675,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 9U))));
    bufp->fullBit(oldp+3676,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 8U))));
    bufp->fullCData(oldp+3677,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2aU] >> 5U))),3);
    bufp->fullBit(oldp+3678,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2aU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2aU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2aU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2aU] >> 5U))))));
    bufp->fullBit(oldp+3679,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3680,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 7U))));
    bufp->fullBit(oldp+3681,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 6U))));
    bufp->fullBit(oldp+3682,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 5U))));
    bufp->fullCData(oldp+3683,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2aU] >> 2U))),3);
    bufp->fullBit(oldp+3684,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2aU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2aU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2aU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2aU] >> 2U))))));
    bufp->fullBit(oldp+3685,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3686,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 4U))));
    bufp->fullBit(oldp+3687,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 3U))));
    bufp->fullBit(oldp+3688,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 2U))));
    bufp->fullCData(oldp+3689,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3690,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3691,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3692,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x2aU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3693,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 1U)))));
    bufp->fullBit(oldp+3694,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3695,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2aU] >> 1U))));
    bufp->fullCData(oldp+3696,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x2aU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3697,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x2aU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2aU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3698,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3699,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x2aU])));
    bufp->fullBit(oldp+3700,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3701,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3702,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3703,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3704,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3705,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3706,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3707,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3708,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3709,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3710,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3711,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3712,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3713,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3714,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3715,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3716,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3717,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3718,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3719,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3720,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3721,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3722,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3723,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3724,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3725,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3726,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3727,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3728,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3729,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3730,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3731,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3732,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x2bU]),17);
    bufp->fullSData(oldp+3733,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3734,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3735,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3736,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3737,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3738,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3739,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3740,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3741,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2bU] >> 0xeU))),3);
    bufp->fullBit(oldp+3742,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2bU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2bU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2bU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2bU] >> 0xeU))))));
    bufp->fullBit(oldp+3743,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3744,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 0x10U))));
    bufp->fullBit(oldp+3745,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 0xfU))));
    bufp->fullBit(oldp+3746,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 0xeU))));
    bufp->fullCData(oldp+3747,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2bU] >> 0xbU))),3);
    bufp->fullBit(oldp+3748,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2bU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2bU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2bU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2bU] >> 0xbU))))));
    bufp->fullBit(oldp+3749,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3750,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 0xdU))));
    bufp->fullBit(oldp+3751,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 0xcU))));
    bufp->fullBit(oldp+3752,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 0xbU))));
    bufp->fullCData(oldp+3753,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2bU] >> 8U))),3);
    bufp->fullBit(oldp+3754,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2bU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2bU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2bU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2bU] >> 8U))))));
    bufp->fullBit(oldp+3755,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3756,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 0xaU))));
    bufp->fullBit(oldp+3757,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 9U))));
    bufp->fullBit(oldp+3758,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 8U))));
    bufp->fullCData(oldp+3759,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2bU] >> 5U))),3);
    bufp->fullBit(oldp+3760,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2bU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2bU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2bU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2bU] >> 5U))))));
    bufp->fullBit(oldp+3761,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3762,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 7U))));
    bufp->fullBit(oldp+3763,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 6U))));
    bufp->fullBit(oldp+3764,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 5U))));
    bufp->fullCData(oldp+3765,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2bU] >> 2U))),3);
    bufp->fullBit(oldp+3766,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2bU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2bU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2bU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2bU] >> 2U))))));
    bufp->fullBit(oldp+3767,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3768,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 4U))));
    bufp->fullBit(oldp+3769,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 3U))));
    bufp->fullBit(oldp+3770,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 2U))));
    bufp->fullCData(oldp+3771,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3772,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3773,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3774,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x2bU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3775,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 1U)))));
    bufp->fullBit(oldp+3776,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3777,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2bU] >> 1U))));
    bufp->fullCData(oldp+3778,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x2bU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3779,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x2bU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2bU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3780,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3781,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x2bU])));
    bufp->fullBit(oldp+3782,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3783,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3784,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3785,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3786,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3787,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3788,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3789,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3790,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3791,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3792,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3793,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3794,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3795,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3796,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3797,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3798,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3799,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3800,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3801,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3802,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3803,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3804,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3805,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3806,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3807,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3808,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3809,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3810,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3811,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3812,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3813,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3814,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x2cU]),17);
    bufp->fullSData(oldp+3815,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3816,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3817,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3818,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3819,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3820,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3821,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3822,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3823,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2cU] >> 0xeU))),3);
    bufp->fullBit(oldp+3824,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2cU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2cU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2cU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2cU] >> 0xeU))))));
    bufp->fullBit(oldp+3825,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3826,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 0x10U))));
    bufp->fullBit(oldp+3827,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 0xfU))));
    bufp->fullBit(oldp+3828,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 0xeU))));
    bufp->fullCData(oldp+3829,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2cU] >> 0xbU))),3);
    bufp->fullBit(oldp+3830,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2cU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2cU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2cU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2cU] >> 0xbU))))));
    bufp->fullBit(oldp+3831,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3832,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 0xdU))));
    bufp->fullBit(oldp+3833,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 0xcU))));
    bufp->fullBit(oldp+3834,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 0xbU))));
    bufp->fullCData(oldp+3835,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2cU] >> 8U))),3);
    bufp->fullBit(oldp+3836,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2cU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2cU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2cU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2cU] >> 8U))))));
    bufp->fullBit(oldp+3837,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3838,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 0xaU))));
    bufp->fullBit(oldp+3839,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 9U))));
    bufp->fullBit(oldp+3840,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 8U))));
    bufp->fullCData(oldp+3841,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2cU] >> 5U))),3);
    bufp->fullBit(oldp+3842,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2cU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2cU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2cU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2cU] >> 5U))))));
    bufp->fullBit(oldp+3843,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3844,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 7U))));
    bufp->fullBit(oldp+3845,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 6U))));
    bufp->fullBit(oldp+3846,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 5U))));
    bufp->fullCData(oldp+3847,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2cU] >> 2U))),3);
    bufp->fullBit(oldp+3848,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2cU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2cU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2cU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2cU] >> 2U))))));
    bufp->fullBit(oldp+3849,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3850,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 4U))));
    bufp->fullBit(oldp+3851,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 3U))));
    bufp->fullBit(oldp+3852,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 2U))));
    bufp->fullCData(oldp+3853,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3854,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3855,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3856,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x2cU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3857,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 1U)))));
    bufp->fullBit(oldp+3858,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3859,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2cU] >> 1U))));
    bufp->fullCData(oldp+3860,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x2cU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3861,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x2cU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2cU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3862,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3863,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x2cU])));
    bufp->fullBit(oldp+3864,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3865,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3866,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3867,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3868,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3869,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3870,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3871,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3872,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3873,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3874,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3875,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3876,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3877,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3878,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3879,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3880,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3881,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3882,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3883,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3884,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3885,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3886,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3887,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3888,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3889,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3890,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3891,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3892,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3893,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3894,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3895,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3896,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x2dU]),17);
    bufp->fullSData(oldp+3897,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3898,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3899,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3900,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3901,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3902,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3903,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3904,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3905,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2dU] >> 0xeU))),3);
    bufp->fullBit(oldp+3906,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2dU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2dU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2dU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2dU] >> 0xeU))))));
    bufp->fullBit(oldp+3907,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3908,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 0x10U))));
    bufp->fullBit(oldp+3909,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 0xfU))));
    bufp->fullBit(oldp+3910,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 0xeU))));
    bufp->fullCData(oldp+3911,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2dU] >> 0xbU))),3);
    bufp->fullBit(oldp+3912,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2dU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2dU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2dU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2dU] >> 0xbU))))));
    bufp->fullBit(oldp+3913,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3914,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 0xdU))));
    bufp->fullBit(oldp+3915,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 0xcU))));
    bufp->fullBit(oldp+3916,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 0xbU))));
    bufp->fullCData(oldp+3917,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2dU] >> 8U))),3);
    bufp->fullBit(oldp+3918,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2dU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2dU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2dU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2dU] >> 8U))))));
    bufp->fullBit(oldp+3919,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3920,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 0xaU))));
    bufp->fullBit(oldp+3921,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 9U))));
    bufp->fullBit(oldp+3922,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 8U))));
    bufp->fullCData(oldp+3923,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2dU] >> 5U))),3);
    bufp->fullBit(oldp+3924,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2dU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2dU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2dU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2dU] >> 5U))))));
    bufp->fullBit(oldp+3925,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3926,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 7U))));
    bufp->fullBit(oldp+3927,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 6U))));
    bufp->fullBit(oldp+3928,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 5U))));
    bufp->fullCData(oldp+3929,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2dU] >> 2U))),3);
    bufp->fullBit(oldp+3930,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2dU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2dU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2dU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2dU] >> 2U))))));
    bufp->fullBit(oldp+3931,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3932,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 4U))));
    bufp->fullBit(oldp+3933,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 3U))));
    bufp->fullBit(oldp+3934,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 2U))));
    bufp->fullCData(oldp+3935,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3936,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3937,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3938,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x2dU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3939,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 1U)))));
    bufp->fullBit(oldp+3940,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3941,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2dU] >> 1U))));
    bufp->fullCData(oldp+3942,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x2dU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3943,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x2dU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2dU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3944,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3945,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x2dU])));
    bufp->fullBit(oldp+3946,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3947,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3948,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3949,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3950,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3951,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3952,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3953,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3954,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3955,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3956,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3957,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3958,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3959,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3960,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3961,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3962,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3963,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3964,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3965,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3966,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3967,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3968,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3969,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3970,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3971,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3972,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3973,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3974,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3975,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3976,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3977,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3978,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x2eU]),17);
    bufp->fullSData(oldp+3979,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3980,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3981,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3982,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3983,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3984,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3985,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3986,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3987,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2eU] >> 0xeU))),3);
    bufp->fullBit(oldp+3988,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2eU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2eU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2eU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2eU] >> 0xeU))))));
    bufp->fullBit(oldp+3989,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3990,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 0x10U))));
    bufp->fullBit(oldp+3991,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 0xfU))));
    bufp->fullBit(oldp+3992,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 0xeU))));
    bufp->fullCData(oldp+3993,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2eU] >> 0xbU))),3);
    bufp->fullBit(oldp+3994,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2eU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2eU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2eU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2eU] >> 0xbU))))));
    bufp->fullBit(oldp+3995,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3996,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 0xdU))));
    bufp->fullBit(oldp+3997,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 0xcU))));
    bufp->fullBit(oldp+3998,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 0xbU))));
    bufp->fullCData(oldp+3999,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2eU] >> 8U))),3);
    bufp->fullBit(oldp+4000,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2eU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2eU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2eU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2eU] >> 8U))))));
    bufp->fullBit(oldp+4001,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4002,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 0xaU))));
    bufp->fullBit(oldp+4003,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 9U))));
    bufp->fullBit(oldp+4004,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 8U))));
    bufp->fullCData(oldp+4005,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2eU] >> 5U))),3);
    bufp->fullBit(oldp+4006,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2eU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2eU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2eU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2eU] >> 5U))))));
    bufp->fullBit(oldp+4007,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4008,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 7U))));
    bufp->fullBit(oldp+4009,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 6U))));
    bufp->fullBit(oldp+4010,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 5U))));
    bufp->fullCData(oldp+4011,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2eU] >> 2U))),3);
    bufp->fullBit(oldp+4012,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2eU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2eU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2eU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2eU] >> 2U))))));
    bufp->fullBit(oldp+4013,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4014,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 4U))));
    bufp->fullBit(oldp+4015,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 3U))));
    bufp->fullBit(oldp+4016,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 2U))));
    bufp->fullCData(oldp+4017,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4018,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4019,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4020,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x2eU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4021,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 1U)))));
    bufp->fullBit(oldp+4022,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4023,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2eU] >> 1U))));
    bufp->fullCData(oldp+4024,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x2eU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4025,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x2eU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2eU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4026,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4027,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x2eU])));
    bufp->fullBit(oldp+4028,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4029,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4030,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4031,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4032,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4033,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4034,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4035,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4036,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4037,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4038,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4039,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4040,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4041,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4042,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4043,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4044,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4045,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4046,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4047,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4048,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4049,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4050,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4051,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4052,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4053,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4054,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4055,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4056,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4057,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4058,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4059,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4060,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x2fU]),17);
    bufp->fullSData(oldp+4061,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4062,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4063,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4064,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4065,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4066,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4067,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4068,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4069,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2fU] >> 0xeU))),3);
    bufp->fullBit(oldp+4070,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2fU] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2fU] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2fU] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2fU] >> 0xeU))))));
    bufp->fullBit(oldp+4071,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4072,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 0x10U))));
    bufp->fullBit(oldp+4073,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 0xfU))));
    bufp->fullBit(oldp+4074,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 0xeU))));
    bufp->fullCData(oldp+4075,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2fU] >> 0xbU))),3);
    bufp->fullBit(oldp+4076,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2fU] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2fU] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2fU] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2fU] >> 0xbU))))));
    bufp->fullBit(oldp+4077,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4078,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 0xdU))));
    bufp->fullBit(oldp+4079,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 0xcU))));
    bufp->fullBit(oldp+4080,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 0xbU))));
    bufp->fullCData(oldp+4081,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2fU] >> 8U))),3);
    bufp->fullBit(oldp+4082,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2fU] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2fU] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2fU] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2fU] >> 8U))))));
    bufp->fullBit(oldp+4083,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4084,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 0xaU))));
    bufp->fullBit(oldp+4085,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 9U))));
    bufp->fullBit(oldp+4086,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 8U))));
    bufp->fullCData(oldp+4087,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2fU] >> 5U))),3);
    bufp->fullBit(oldp+4088,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2fU] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2fU] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2fU] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2fU] >> 5U))))));
    bufp->fullBit(oldp+4089,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4090,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 7U))));
    bufp->fullBit(oldp+4091,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 6U))));
    bufp->fullBit(oldp+4092,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 5U))));
    bufp->fullCData(oldp+4093,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2fU] >> 2U))),3);
    bufp->fullBit(oldp+4094,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x2fU] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2fU] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x2fU] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x2fU] >> 2U))))));
    bufp->fullBit(oldp+4095,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4096,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 4U))));
    bufp->fullBit(oldp+4097,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 3U))));
    bufp->fullBit(oldp+4098,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 2U))));
    bufp->fullCData(oldp+4099,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4100,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4101,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4102,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x2fU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4103,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 1U)))));
    bufp->fullBit(oldp+4104,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4105,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x2fU] >> 1U))));
    bufp->fullCData(oldp+4106,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x2fU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4107,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x2fU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x2fU]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4108,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4109,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x2fU])));
    bufp->fullBit(oldp+4110,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4111,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4112,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4113,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4114,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4115,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4116,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4117,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4118,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4119,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4120,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4121,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4122,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4123,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4124,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4125,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4126,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4127,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4128,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4129,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4130,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4131,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4132,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4133,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4134,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4135,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4136,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4137,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4138,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4139,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4140,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4141,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4142,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x30U]),17);
    bufp->fullSData(oldp+4143,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4144,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4145,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4146,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4147,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4148,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4149,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4150,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4151,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x30U] >> 0xeU))),3);
    bufp->fullBit(oldp+4152,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x30U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x30U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x30U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x30U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x30U] >> 0xeU))))));
    bufp->fullBit(oldp+4153,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4154,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 0x10U))));
    bufp->fullBit(oldp+4155,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 0xfU))));
    bufp->fullBit(oldp+4156,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 0xeU))));
    bufp->fullCData(oldp+4157,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x30U] >> 0xbU))),3);
    bufp->fullBit(oldp+4158,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x30U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x30U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x30U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x30U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x30U] >> 0xbU))))));
    bufp->fullBit(oldp+4159,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4160,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 0xdU))));
    bufp->fullBit(oldp+4161,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 0xcU))));
    bufp->fullBit(oldp+4162,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 0xbU))));
    bufp->fullCData(oldp+4163,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x30U] >> 8U))),3);
    bufp->fullBit(oldp+4164,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x30U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x30U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x30U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x30U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x30U] >> 8U))))));
    bufp->fullBit(oldp+4165,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4166,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 0xaU))));
    bufp->fullBit(oldp+4167,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 9U))));
    bufp->fullBit(oldp+4168,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 8U))));
    bufp->fullCData(oldp+4169,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x30U] >> 5U))),3);
    bufp->fullBit(oldp+4170,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x30U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x30U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x30U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x30U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x30U] >> 5U))))));
    bufp->fullBit(oldp+4171,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4172,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 7U))));
    bufp->fullBit(oldp+4173,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 6U))));
    bufp->fullBit(oldp+4174,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 5U))));
    bufp->fullCData(oldp+4175,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x30U] >> 2U))),3);
    bufp->fullBit(oldp+4176,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x30U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x30U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x30U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x30U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x30U] >> 2U))))));
    bufp->fullBit(oldp+4177,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4178,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 4U))));
    bufp->fullBit(oldp+4179,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 3U))));
    bufp->fullBit(oldp+4180,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 2U))));
    bufp->fullCData(oldp+4181,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4182,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4183,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4184,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x30U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4185,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 1U)))));
    bufp->fullBit(oldp+4186,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4187,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x30U] >> 1U))));
    bufp->fullCData(oldp+4188,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x30U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4189,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x30U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x30U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4190,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4191,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x30U])));
    bufp->fullBit(oldp+4192,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4193,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4194,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4195,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4196,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4197,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4198,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4199,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4200,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4201,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4202,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4203,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4204,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4205,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4206,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4207,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4208,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4209,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4210,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4211,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4212,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4213,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4214,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4215,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4216,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4217,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4218,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4219,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4220,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4221,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4222,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4223,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4224,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x31U]),17);
    bufp->fullSData(oldp+4225,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4226,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4227,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4228,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4229,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4230,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4231,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4232,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4233,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x31U] >> 0xeU))),3);
    bufp->fullBit(oldp+4234,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x31U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x31U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x31U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x31U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x31U] >> 0xeU))))));
    bufp->fullBit(oldp+4235,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4236,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 0x10U))));
    bufp->fullBit(oldp+4237,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 0xfU))));
    bufp->fullBit(oldp+4238,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 0xeU))));
    bufp->fullCData(oldp+4239,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x31U] >> 0xbU))),3);
    bufp->fullBit(oldp+4240,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x31U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x31U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x31U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x31U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x31U] >> 0xbU))))));
    bufp->fullBit(oldp+4241,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4242,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 0xdU))));
    bufp->fullBit(oldp+4243,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 0xcU))));
    bufp->fullBit(oldp+4244,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 0xbU))));
    bufp->fullCData(oldp+4245,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x31U] >> 8U))),3);
    bufp->fullBit(oldp+4246,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x31U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x31U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x31U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x31U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x31U] >> 8U))))));
    bufp->fullBit(oldp+4247,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4248,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 0xaU))));
    bufp->fullBit(oldp+4249,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 9U))));
    bufp->fullBit(oldp+4250,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 8U))));
    bufp->fullCData(oldp+4251,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x31U] >> 5U))),3);
    bufp->fullBit(oldp+4252,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x31U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x31U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x31U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x31U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x31U] >> 5U))))));
    bufp->fullBit(oldp+4253,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4254,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 7U))));
    bufp->fullBit(oldp+4255,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 6U))));
    bufp->fullBit(oldp+4256,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 5U))));
    bufp->fullCData(oldp+4257,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x31U] >> 2U))),3);
    bufp->fullBit(oldp+4258,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x31U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x31U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x31U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x31U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x31U] >> 2U))))));
    bufp->fullBit(oldp+4259,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4260,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 4U))));
    bufp->fullBit(oldp+4261,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 3U))));
    bufp->fullBit(oldp+4262,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 2U))));
    bufp->fullCData(oldp+4263,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4264,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4265,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4266,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x31U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4267,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 1U)))));
    bufp->fullBit(oldp+4268,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4269,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x31U] >> 1U))));
    bufp->fullCData(oldp+4270,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x31U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4271,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x31U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x31U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4272,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4273,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x31U])));
    bufp->fullBit(oldp+4274,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4275,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4276,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4277,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4278,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4279,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4280,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4281,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4282,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4283,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4284,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4285,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4286,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4287,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4288,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4289,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4290,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4291,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4292,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4293,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4294,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4295,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4296,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4297,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4298,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4299,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4300,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4301,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4302,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4303,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4304,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4305,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4306,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x32U]),17);
    bufp->fullSData(oldp+4307,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4308,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4309,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4310,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4311,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4312,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4313,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4314,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4315,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x32U] >> 0xeU))),3);
    bufp->fullBit(oldp+4316,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x32U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x32U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x32U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x32U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x32U] >> 0xeU))))));
    bufp->fullBit(oldp+4317,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4318,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 0x10U))));
    bufp->fullBit(oldp+4319,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 0xfU))));
    bufp->fullBit(oldp+4320,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 0xeU))));
    bufp->fullCData(oldp+4321,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x32U] >> 0xbU))),3);
    bufp->fullBit(oldp+4322,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x32U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x32U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x32U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x32U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x32U] >> 0xbU))))));
    bufp->fullBit(oldp+4323,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4324,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 0xdU))));
    bufp->fullBit(oldp+4325,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 0xcU))));
    bufp->fullBit(oldp+4326,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 0xbU))));
    bufp->fullCData(oldp+4327,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x32U] >> 8U))),3);
    bufp->fullBit(oldp+4328,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x32U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x32U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x32U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x32U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x32U] >> 8U))))));
    bufp->fullBit(oldp+4329,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4330,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 0xaU))));
    bufp->fullBit(oldp+4331,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 9U))));
    bufp->fullBit(oldp+4332,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 8U))));
    bufp->fullCData(oldp+4333,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x32U] >> 5U))),3);
    bufp->fullBit(oldp+4334,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x32U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x32U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x32U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x32U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x32U] >> 5U))))));
    bufp->fullBit(oldp+4335,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4336,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 7U))));
    bufp->fullBit(oldp+4337,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 6U))));
    bufp->fullBit(oldp+4338,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 5U))));
    bufp->fullCData(oldp+4339,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x32U] >> 2U))),3);
    bufp->fullBit(oldp+4340,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x32U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x32U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x32U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x32U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x32U] >> 2U))))));
    bufp->fullBit(oldp+4341,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4342,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 4U))));
    bufp->fullBit(oldp+4343,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 3U))));
    bufp->fullBit(oldp+4344,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 2U))));
    bufp->fullCData(oldp+4345,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4346,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4347,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4348,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x32U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4349,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 1U)))));
    bufp->fullBit(oldp+4350,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4351,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x32U] >> 1U))));
    bufp->fullCData(oldp+4352,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x32U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4353,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x32U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x32U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4354,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4355,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x32U])));
    bufp->fullBit(oldp+4356,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4357,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4358,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4359,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4360,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4361,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4362,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4363,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4364,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4365,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4366,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4367,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4368,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4369,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4370,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4371,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4372,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4373,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4374,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4375,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4376,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4377,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4378,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4379,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4380,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4381,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4382,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4383,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4384,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4385,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4386,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4387,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4388,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x33U]),17);
    bufp->fullSData(oldp+4389,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4390,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4391,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4392,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4393,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4394,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4395,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4396,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4397,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x33U] >> 0xeU))),3);
    bufp->fullBit(oldp+4398,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x33U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x33U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x33U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x33U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x33U] >> 0xeU))))));
    bufp->fullBit(oldp+4399,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4400,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 0x10U))));
    bufp->fullBit(oldp+4401,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 0xfU))));
    bufp->fullBit(oldp+4402,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 0xeU))));
    bufp->fullCData(oldp+4403,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x33U] >> 0xbU))),3);
    bufp->fullBit(oldp+4404,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x33U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x33U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x33U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x33U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x33U] >> 0xbU))))));
    bufp->fullBit(oldp+4405,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4406,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 0xdU))));
    bufp->fullBit(oldp+4407,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 0xcU))));
    bufp->fullBit(oldp+4408,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 0xbU))));
    bufp->fullCData(oldp+4409,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x33U] >> 8U))),3);
    bufp->fullBit(oldp+4410,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x33U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x33U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x33U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x33U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x33U] >> 8U))))));
    bufp->fullBit(oldp+4411,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4412,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 0xaU))));
    bufp->fullBit(oldp+4413,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 9U))));
    bufp->fullBit(oldp+4414,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 8U))));
    bufp->fullCData(oldp+4415,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x33U] >> 5U))),3);
    bufp->fullBit(oldp+4416,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x33U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x33U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x33U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x33U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x33U] >> 5U))))));
    bufp->fullBit(oldp+4417,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4418,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 7U))));
    bufp->fullBit(oldp+4419,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 6U))));
    bufp->fullBit(oldp+4420,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 5U))));
    bufp->fullCData(oldp+4421,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x33U] >> 2U))),3);
    bufp->fullBit(oldp+4422,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x33U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x33U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x33U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x33U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x33U] >> 2U))))));
    bufp->fullBit(oldp+4423,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4424,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 4U))));
    bufp->fullBit(oldp+4425,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 3U))));
    bufp->fullBit(oldp+4426,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 2U))));
    bufp->fullCData(oldp+4427,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4428,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4429,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4430,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x33U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4431,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 1U)))));
    bufp->fullBit(oldp+4432,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4433,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x33U] >> 1U))));
    bufp->fullCData(oldp+4434,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x33U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4435,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x33U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x33U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4436,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4437,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x33U])));
    bufp->fullBit(oldp+4438,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4439,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4440,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4441,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4442,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4443,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4444,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4445,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4446,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4447,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4448,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4449,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4450,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4451,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4452,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4453,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4454,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4455,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4456,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4457,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4458,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4459,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4460,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4461,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4462,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4463,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4464,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4465,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4466,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4467,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4468,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4469,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4470,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x34U]),17);
    bufp->fullSData(oldp+4471,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4472,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4473,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4474,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4475,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4476,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4477,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4478,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4479,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x34U] >> 0xeU))),3);
    bufp->fullBit(oldp+4480,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x34U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x34U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x34U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x34U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x34U] >> 0xeU))))));
    bufp->fullBit(oldp+4481,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4482,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 0x10U))));
    bufp->fullBit(oldp+4483,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 0xfU))));
    bufp->fullBit(oldp+4484,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 0xeU))));
    bufp->fullCData(oldp+4485,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x34U] >> 0xbU))),3);
    bufp->fullBit(oldp+4486,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x34U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x34U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x34U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x34U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x34U] >> 0xbU))))));
    bufp->fullBit(oldp+4487,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4488,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 0xdU))));
    bufp->fullBit(oldp+4489,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 0xcU))));
    bufp->fullBit(oldp+4490,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 0xbU))));
    bufp->fullCData(oldp+4491,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x34U] >> 8U))),3);
    bufp->fullBit(oldp+4492,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x34U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x34U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x34U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x34U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x34U] >> 8U))))));
    bufp->fullBit(oldp+4493,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4494,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 0xaU))));
    bufp->fullBit(oldp+4495,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 9U))));
    bufp->fullBit(oldp+4496,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 8U))));
    bufp->fullCData(oldp+4497,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x34U] >> 5U))),3);
    bufp->fullBit(oldp+4498,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x34U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x34U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x34U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x34U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x34U] >> 5U))))));
    bufp->fullBit(oldp+4499,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4500,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 7U))));
    bufp->fullBit(oldp+4501,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 6U))));
    bufp->fullBit(oldp+4502,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 5U))));
    bufp->fullCData(oldp+4503,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x34U] >> 2U))),3);
    bufp->fullBit(oldp+4504,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x34U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x34U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x34U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x34U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x34U] >> 2U))))));
    bufp->fullBit(oldp+4505,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4506,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 4U))));
    bufp->fullBit(oldp+4507,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 3U))));
    bufp->fullBit(oldp+4508,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 2U))));
    bufp->fullCData(oldp+4509,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4510,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4511,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4512,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x34U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4513,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 1U)))));
    bufp->fullBit(oldp+4514,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4515,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x34U] >> 1U))));
    bufp->fullCData(oldp+4516,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x34U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4517,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x34U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x34U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4518,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4519,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x34U])));
    bufp->fullBit(oldp+4520,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4521,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4522,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4523,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4524,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4525,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4526,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4527,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4528,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4529,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4530,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4531,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4532,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4533,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4534,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4535,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4536,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4537,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4538,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4539,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4540,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4541,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4542,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4543,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4544,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4545,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4546,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4547,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4548,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4549,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4550,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4551,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4552,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x35U]),17);
    bufp->fullSData(oldp+4553,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4554,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4555,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4556,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4557,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4558,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4559,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4560,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4561,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x35U] >> 0xeU))),3);
    bufp->fullBit(oldp+4562,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x35U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x35U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x35U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x35U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x35U] >> 0xeU))))));
    bufp->fullBit(oldp+4563,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4564,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 0x10U))));
    bufp->fullBit(oldp+4565,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 0xfU))));
    bufp->fullBit(oldp+4566,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 0xeU))));
    bufp->fullCData(oldp+4567,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x35U] >> 0xbU))),3);
    bufp->fullBit(oldp+4568,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x35U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x35U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x35U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x35U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x35U] >> 0xbU))))));
    bufp->fullBit(oldp+4569,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4570,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 0xdU))));
    bufp->fullBit(oldp+4571,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 0xcU))));
    bufp->fullBit(oldp+4572,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 0xbU))));
    bufp->fullCData(oldp+4573,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x35U] >> 8U))),3);
    bufp->fullBit(oldp+4574,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x35U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x35U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x35U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x35U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x35U] >> 8U))))));
    bufp->fullBit(oldp+4575,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4576,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 0xaU))));
    bufp->fullBit(oldp+4577,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 9U))));
    bufp->fullBit(oldp+4578,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 8U))));
    bufp->fullCData(oldp+4579,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x35U] >> 5U))),3);
    bufp->fullBit(oldp+4580,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x35U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x35U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x35U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x35U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x35U] >> 5U))))));
    bufp->fullBit(oldp+4581,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4582,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 7U))));
    bufp->fullBit(oldp+4583,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 6U))));
    bufp->fullBit(oldp+4584,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 5U))));
    bufp->fullCData(oldp+4585,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x35U] >> 2U))),3);
    bufp->fullBit(oldp+4586,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x35U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x35U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x35U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x35U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x35U] >> 2U))))));
    bufp->fullBit(oldp+4587,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4588,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 4U))));
    bufp->fullBit(oldp+4589,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 3U))));
    bufp->fullBit(oldp+4590,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 2U))));
    bufp->fullCData(oldp+4591,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4592,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4593,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4594,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x35U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4595,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 1U)))));
    bufp->fullBit(oldp+4596,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4597,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x35U] >> 1U))));
    bufp->fullCData(oldp+4598,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x35U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4599,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x35U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x35U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4600,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4601,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x35U])));
    bufp->fullBit(oldp+4602,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4603,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4604,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4605,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4606,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4607,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4608,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4609,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4610,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4611,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4612,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4613,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4614,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4615,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4616,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4617,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4618,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4619,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4620,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4621,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4622,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4623,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4624,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4625,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4626,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4627,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4628,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4629,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4630,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4631,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4632,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4633,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4634,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x36U]),17);
    bufp->fullSData(oldp+4635,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4636,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4637,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4638,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4639,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4640,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4641,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4642,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4643,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x36U] >> 0xeU))),3);
    bufp->fullBit(oldp+4644,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x36U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x36U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x36U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x36U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x36U] >> 0xeU))))));
    bufp->fullBit(oldp+4645,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4646,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 0x10U))));
    bufp->fullBit(oldp+4647,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 0xfU))));
    bufp->fullBit(oldp+4648,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 0xeU))));
    bufp->fullCData(oldp+4649,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x36U] >> 0xbU))),3);
    bufp->fullBit(oldp+4650,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x36U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x36U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x36U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x36U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x36U] >> 0xbU))))));
    bufp->fullBit(oldp+4651,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4652,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 0xdU))));
    bufp->fullBit(oldp+4653,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 0xcU))));
    bufp->fullBit(oldp+4654,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 0xbU))));
    bufp->fullCData(oldp+4655,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x36U] >> 8U))),3);
    bufp->fullBit(oldp+4656,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x36U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x36U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x36U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x36U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x36U] >> 8U))))));
    bufp->fullBit(oldp+4657,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4658,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 0xaU))));
    bufp->fullBit(oldp+4659,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 9U))));
    bufp->fullBit(oldp+4660,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 8U))));
    bufp->fullCData(oldp+4661,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x36U] >> 5U))),3);
    bufp->fullBit(oldp+4662,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x36U] >> 7U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x36U] >> 6U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x36U] >> 6U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x36U] 
                                           >> 7U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x36U] >> 5U))))));
    bufp->fullBit(oldp+4663,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4664,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 7U))));
    bufp->fullBit(oldp+4665,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 6U))));
    bufp->fullBit(oldp+4666,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 5U))));
    bufp->fullCData(oldp+4667,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x36U] >> 2U))),3);
    bufp->fullBit(oldp+4668,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x36U] >> 4U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x36U] >> 3U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x36U] >> 3U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x36U] 
                                           >> 4U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x36U] >> 2U))))));
    bufp->fullBit(oldp+4669,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4670,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 4U))));
    bufp->fullBit(oldp+4671,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 3U))));
    bufp->fullBit(oldp+4672,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 2U))));
    bufp->fullCData(oldp+4673,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4674,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4675,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4676,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                               [0x36U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4677,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 1U)))));
    bufp->fullBit(oldp+4678,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4679,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x36U] >> 1U))));
    bufp->fullCData(oldp+4680,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x36U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4681,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x36U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x36U]) & 
                                       ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4682,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4683,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                              [0x36U])));
    bufp->fullBit(oldp+4684,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4685,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4686,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4687,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4688,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4689,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4690,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4691,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4692,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4693,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4694,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4695,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4696,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4697,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4698,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4699,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4700,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4701,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4702,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4703,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4704,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4705,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4706,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4707,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4708,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4709,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4710,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4711,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4712,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4713,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4714,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4715,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4716,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x37U]),17);
    bufp->fullSData(oldp+4717,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4718,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4719,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4720,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4721,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4722,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4723,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4724,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4725,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x37U] >> 0xeU))),3);
    bufp->fullBit(oldp+4726,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x37U] >> 0x10U) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x37U] >> 0xfU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x37U] >> 0xfU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x37U] 
                                           >> 0x10U)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x37U] >> 0xeU))))));
    bufp->fullBit(oldp+4727,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4728,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 0x10U))));
    bufp->fullBit(oldp+4729,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 0xfU))));
    bufp->fullBit(oldp+4730,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 0xeU))));
    bufp->fullCData(oldp+4731,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x37U] >> 0xbU))),3);
    bufp->fullBit(oldp+4732,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x37U] >> 0xdU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x37U] >> 0xcU)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x37U] >> 0xcU) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x37U] 
                                           >> 0xdU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x37U] >> 0xbU))))));
    bufp->fullBit(oldp+4733,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4734,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 0xdU))));
    bufp->fullBit(oldp+4735,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 0xcU))));
    bufp->fullBit(oldp+4736,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 0xbU))));
    bufp->fullCData(oldp+4737,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x37U] >> 8U))),3);
    bufp->fullBit(oldp+4738,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x37U] >> 0xaU) 
                                     & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x37U] >> 9U)) 
                                    | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x37U] >> 9U) 
                                        | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x37U] 
                                           >> 0xaU)) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x37U] >> 8U))))));
    bufp->fullBit(oldp+4739,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4740,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 0xaU))));
    bufp->fullBit(oldp+4741,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 9U))));
    bufp->fullBit(oldp+4742,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 8U))));
}
