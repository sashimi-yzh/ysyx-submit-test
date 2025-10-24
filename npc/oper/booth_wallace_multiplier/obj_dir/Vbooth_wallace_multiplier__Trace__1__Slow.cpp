// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbooth_wallace_multiplier__Syms.h"


VL_ATTR_COLD void Vbooth_wallace_multiplier___024root__trace_full_sub_1(Vbooth_wallace_multiplier___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root__trace_full_sub_1\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+2393,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2394,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 0xdU))));
    bufp->fullBit(oldp+2395,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 0xcU))));
    bufp->fullBit(oldp+2396,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 0xbU))));
    bufp->fullCData(oldp+2397,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1bU] >> 8U))),3);
    bufp->fullBit(oldp+2398,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1bU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1bU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1bU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1bU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1bU] >> 8U))))));
    bufp->fullBit(oldp+2399,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2400,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 0xaU))));
    bufp->fullBit(oldp+2401,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 9U))));
    bufp->fullBit(oldp+2402,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 8U))));
    bufp->fullCData(oldp+2403,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1bU] >> 5U))),3);
    bufp->fullBit(oldp+2404,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1bU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1bU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1bU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1bU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1bU] >> 5U))))));
    bufp->fullBit(oldp+2405,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2406,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 7U))));
    bufp->fullBit(oldp+2407,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 6U))));
    bufp->fullBit(oldp+2408,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 5U))));
    bufp->fullCData(oldp+2409,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1bU] >> 2U))),3);
    bufp->fullBit(oldp+2410,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1bU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1bU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1bU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1bU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1bU] >> 2U))))));
    bufp->fullBit(oldp+2411,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2412,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 4U))));
    bufp->fullBit(oldp+2413,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 3U))));
    bufp->fullBit(oldp+2414,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 2U))));
    bufp->fullCData(oldp+2415,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2416,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2417,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2418,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1bU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2419,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 1U)))));
    bufp->fullBit(oldp+2420,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2421,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 1U))));
    bufp->fullCData(oldp+2422,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1bU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2423,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1bU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1bU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2424,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2425,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x1bU])));
    bufp->fullBit(oldp+2426,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2427,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2428,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2429,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2430,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2431,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2432,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2433,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2434,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2435,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2436,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2437,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2438,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2439,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2440,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2441,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2442,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2443,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2444,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2445,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2446,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2447,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2448,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2449,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2450,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2451,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2452,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2453,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2454,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2455,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2456,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2457,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2458,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x1cU]),17);
    bufp->fullSData(oldp+2459,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2460,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2461,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2462,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2463,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+2464,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+2465,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+2466,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+2467,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 0xeU))),3);
    bufp->fullBit(oldp+2468,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1cU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1cU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 0xeU))))));
    bufp->fullBit(oldp+2469,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2470,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 0x10U))));
    bufp->fullBit(oldp+2471,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 0xfU))));
    bufp->fullBit(oldp+2472,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 0xeU))));
    bufp->fullCData(oldp+2473,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 0xbU))),3);
    bufp->fullBit(oldp+2474,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1cU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1cU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 0xbU))))));
    bufp->fullBit(oldp+2475,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2476,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 0xdU))));
    bufp->fullBit(oldp+2477,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 0xcU))));
    bufp->fullBit(oldp+2478,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 0xbU))));
    bufp->fullCData(oldp+2479,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 8U))),3);
    bufp->fullBit(oldp+2480,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1cU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1cU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 8U))))));
    bufp->fullBit(oldp+2481,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2482,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 0xaU))));
    bufp->fullBit(oldp+2483,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 9U))));
    bufp->fullBit(oldp+2484,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 8U))));
    bufp->fullCData(oldp+2485,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 5U))),3);
    bufp->fullBit(oldp+2486,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1cU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1cU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 5U))))));
    bufp->fullBit(oldp+2487,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2488,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 7U))));
    bufp->fullBit(oldp+2489,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 6U))));
    bufp->fullBit(oldp+2490,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 5U))));
    bufp->fullCData(oldp+2491,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 2U))),3);
    bufp->fullBit(oldp+2492,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1cU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1cU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 2U))))));
    bufp->fullBit(oldp+2493,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2494,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 4U))));
    bufp->fullBit(oldp+2495,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 3U))));
    bufp->fullBit(oldp+2496,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 2U))));
    bufp->fullCData(oldp+2497,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2498,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2499,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2500,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1cU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2501,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 1U)))));
    bufp->fullBit(oldp+2502,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2503,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1cU] >> 1U))));
    bufp->fullCData(oldp+2504,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1cU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2505,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1cU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1cU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2506,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2507,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x1cU])));
    bufp->fullBit(oldp+2508,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2509,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2510,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2511,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2512,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2513,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2514,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2515,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2516,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2517,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2518,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2519,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2520,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2521,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2522,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2523,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2524,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2525,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2526,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2527,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2528,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2529,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2530,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2531,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2532,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2533,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2534,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2535,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2536,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2537,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2538,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2539,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2540,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x1dU]),17);
    bufp->fullSData(oldp+2541,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2542,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2543,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2544,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2545,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+2546,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+2547,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+2548,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+2549,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 0xeU))),3);
    bufp->fullBit(oldp+2550,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1dU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 0xeU))))));
    bufp->fullBit(oldp+2551,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2552,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 0x10U))));
    bufp->fullBit(oldp+2553,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 0xfU))));
    bufp->fullBit(oldp+2554,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 0xeU))));
    bufp->fullCData(oldp+2555,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 0xbU))),3);
    bufp->fullBit(oldp+2556,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1dU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 0xbU))))));
    bufp->fullBit(oldp+2557,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2558,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 0xdU))));
    bufp->fullBit(oldp+2559,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 0xcU))));
    bufp->fullBit(oldp+2560,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 0xbU))));
    bufp->fullCData(oldp+2561,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 8U))),3);
    bufp->fullBit(oldp+2562,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1dU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 8U))))));
    bufp->fullBit(oldp+2563,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2564,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 0xaU))));
    bufp->fullBit(oldp+2565,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 9U))));
    bufp->fullBit(oldp+2566,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 8U))));
    bufp->fullCData(oldp+2567,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 5U))),3);
    bufp->fullBit(oldp+2568,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1dU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 5U))))));
    bufp->fullBit(oldp+2569,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2570,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 7U))));
    bufp->fullBit(oldp+2571,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 6U))));
    bufp->fullBit(oldp+2572,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 5U))));
    bufp->fullCData(oldp+2573,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 2U))),3);
    bufp->fullBit(oldp+2574,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1dU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 2U))))));
    bufp->fullBit(oldp+2575,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2576,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 4U))));
    bufp->fullBit(oldp+2577,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 3U))));
    bufp->fullBit(oldp+2578,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 2U))));
    bufp->fullCData(oldp+2579,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2580,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2581,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2582,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1dU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2583,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 1U)))));
    bufp->fullBit(oldp+2584,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2585,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1dU] >> 1U))));
    bufp->fullCData(oldp+2586,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1dU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2587,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1dU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2588,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2589,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x1dU])));
    bufp->fullBit(oldp+2590,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2591,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2592,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2593,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2594,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2595,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2596,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2597,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2598,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2599,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2600,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2601,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2602,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2603,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2604,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2605,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2606,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2607,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2608,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2609,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2610,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2611,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2612,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2613,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2614,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2615,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2616,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2617,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2618,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2619,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2620,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2621,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2622,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x1eU]),17);
    bufp->fullSData(oldp+2623,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2624,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2625,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2626,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2627,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+2628,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+2629,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+2630,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+2631,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 0xeU))),3);
    bufp->fullBit(oldp+2632,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1eU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 0xeU))))));
    bufp->fullBit(oldp+2633,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2634,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 0x10U))));
    bufp->fullBit(oldp+2635,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 0xfU))));
    bufp->fullBit(oldp+2636,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 0xeU))));
    bufp->fullCData(oldp+2637,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 0xbU))),3);
    bufp->fullBit(oldp+2638,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1eU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 0xbU))))));
    bufp->fullBit(oldp+2639,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2640,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 0xdU))));
    bufp->fullBit(oldp+2641,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 0xcU))));
    bufp->fullBit(oldp+2642,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 0xbU))));
    bufp->fullCData(oldp+2643,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 8U))),3);
    bufp->fullBit(oldp+2644,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1eU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 8U))))));
    bufp->fullBit(oldp+2645,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2646,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 0xaU))));
    bufp->fullBit(oldp+2647,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 9U))));
    bufp->fullBit(oldp+2648,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 8U))));
    bufp->fullCData(oldp+2649,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 5U))),3);
    bufp->fullBit(oldp+2650,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1eU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 5U))))));
    bufp->fullBit(oldp+2651,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2652,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 7U))));
    bufp->fullBit(oldp+2653,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 6U))));
    bufp->fullBit(oldp+2654,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 5U))));
    bufp->fullCData(oldp+2655,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 2U))),3);
    bufp->fullBit(oldp+2656,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1eU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 2U))))));
    bufp->fullBit(oldp+2657,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2658,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 4U))));
    bufp->fullBit(oldp+2659,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 3U))));
    bufp->fullBit(oldp+2660,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 2U))));
    bufp->fullCData(oldp+2661,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2662,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2663,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2664,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1eU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2665,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 1U)))));
    bufp->fullBit(oldp+2666,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2667,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1eU] >> 1U))));
    bufp->fullCData(oldp+2668,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1eU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2669,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1eU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2670,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2671,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x1eU])));
    bufp->fullBit(oldp+2672,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2673,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2674,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2675,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2676,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2677,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2678,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2679,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2680,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2681,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2682,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2683,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2684,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2685,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2686,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2687,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2688,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2689,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2690,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2691,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2692,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2693,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2694,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2695,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2696,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2697,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2698,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2699,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2700,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2701,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2702,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2703,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2704,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x1fU]),17);
    bufp->fullSData(oldp+2705,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2706,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2707,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2708,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2709,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+2710,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+2711,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+2712,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+2713,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 0xeU))),3);
    bufp->fullBit(oldp+2714,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1fU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 0xeU))))));
    bufp->fullBit(oldp+2715,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2716,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 0x10U))));
    bufp->fullBit(oldp+2717,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 0xfU))));
    bufp->fullBit(oldp+2718,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 0xeU))));
    bufp->fullCData(oldp+2719,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 0xbU))),3);
    bufp->fullBit(oldp+2720,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1fU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 0xbU))))));
    bufp->fullBit(oldp+2721,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2722,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 0xdU))));
    bufp->fullBit(oldp+2723,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 0xcU))));
    bufp->fullBit(oldp+2724,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 0xbU))));
    bufp->fullCData(oldp+2725,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 8U))),3);
    bufp->fullBit(oldp+2726,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1fU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 8U))))));
    bufp->fullBit(oldp+2727,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2728,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 0xaU))));
    bufp->fullBit(oldp+2729,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 9U))));
    bufp->fullBit(oldp+2730,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 8U))));
    bufp->fullCData(oldp+2731,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 5U))),3);
    bufp->fullBit(oldp+2732,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1fU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 5U))))));
    bufp->fullBit(oldp+2733,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2734,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 7U))));
    bufp->fullBit(oldp+2735,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 6U))));
    bufp->fullBit(oldp+2736,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 5U))));
    bufp->fullCData(oldp+2737,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 2U))),3);
    bufp->fullBit(oldp+2738,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1fU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 2U))))));
    bufp->fullBit(oldp+2739,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2740,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 4U))));
    bufp->fullBit(oldp+2741,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 3U))));
    bufp->fullBit(oldp+2742,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 2U))));
    bufp->fullCData(oldp+2743,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2744,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2745,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2746,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1fU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2747,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 1U)))));
    bufp->fullBit(oldp+2748,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2749,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1fU] >> 1U))));
    bufp->fullCData(oldp+2750,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1fU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2751,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1fU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2752,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2753,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x1fU])));
    bufp->fullBit(oldp+2754,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2755,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2756,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2757,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2758,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2759,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2760,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2761,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2762,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2763,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2764,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2765,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2766,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2767,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2768,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2769,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2770,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2771,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2772,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2773,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2774,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2775,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2776,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2777,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2778,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2779,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2780,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2781,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2782,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2783,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2784,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2785,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2786,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x20U]),17);
    bufp->fullSData(oldp+2787,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2788,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2789,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2790,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2791,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+2792,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+2793,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+2794,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+2795,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 0xeU))),3);
    bufp->fullBit(oldp+2796,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x20U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x20U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 0xeU))))));
    bufp->fullBit(oldp+2797,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2798,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 0x10U))));
    bufp->fullBit(oldp+2799,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 0xfU))));
    bufp->fullBit(oldp+2800,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 0xeU))));
    bufp->fullCData(oldp+2801,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 0xbU))),3);
    bufp->fullBit(oldp+2802,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x20U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x20U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 0xbU))))));
    bufp->fullBit(oldp+2803,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2804,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 0xdU))));
    bufp->fullBit(oldp+2805,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 0xcU))));
    bufp->fullBit(oldp+2806,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 0xbU))));
    bufp->fullCData(oldp+2807,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 8U))),3);
    bufp->fullBit(oldp+2808,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x20U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x20U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 8U))))));
    bufp->fullBit(oldp+2809,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2810,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 0xaU))));
    bufp->fullBit(oldp+2811,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 9U))));
    bufp->fullBit(oldp+2812,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 8U))));
    bufp->fullCData(oldp+2813,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 5U))),3);
    bufp->fullBit(oldp+2814,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x20U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x20U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 5U))))));
    bufp->fullBit(oldp+2815,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2816,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 7U))));
    bufp->fullBit(oldp+2817,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 6U))));
    bufp->fullBit(oldp+2818,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 5U))));
    bufp->fullCData(oldp+2819,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 2U))),3);
    bufp->fullBit(oldp+2820,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x20U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x20U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 2U))))));
    bufp->fullBit(oldp+2821,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2822,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 4U))));
    bufp->fullBit(oldp+2823,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 3U))));
    bufp->fullBit(oldp+2824,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 2U))));
    bufp->fullCData(oldp+2825,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2826,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2827,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2828,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x20U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2829,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 1U)))));
    bufp->fullBit(oldp+2830,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2831,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x20U] >> 1U))));
    bufp->fullCData(oldp+2832,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x20U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2833,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x20U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2834,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2835,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x20U])));
    bufp->fullBit(oldp+2836,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2837,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2838,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2839,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2840,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2841,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2842,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2843,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2844,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2845,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2846,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2847,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2848,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2849,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2850,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2851,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2852,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2853,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2854,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2855,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2856,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2857,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2858,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2859,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2860,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2861,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2862,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2863,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2864,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2865,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2866,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2867,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2868,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x21U]),17);
    bufp->fullSData(oldp+2869,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2870,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2871,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2872,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2873,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+2874,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+2875,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+2876,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+2877,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 0xeU))),3);
    bufp->fullBit(oldp+2878,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x21U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x21U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 0xeU))))));
    bufp->fullBit(oldp+2879,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2880,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 0x10U))));
    bufp->fullBit(oldp+2881,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 0xfU))));
    bufp->fullBit(oldp+2882,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 0xeU))));
    bufp->fullCData(oldp+2883,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 0xbU))),3);
    bufp->fullBit(oldp+2884,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x21U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x21U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 0xbU))))));
    bufp->fullBit(oldp+2885,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2886,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 0xdU))));
    bufp->fullBit(oldp+2887,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 0xcU))));
    bufp->fullBit(oldp+2888,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 0xbU))));
    bufp->fullCData(oldp+2889,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 8U))),3);
    bufp->fullBit(oldp+2890,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x21U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x21U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 8U))))));
    bufp->fullBit(oldp+2891,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2892,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 0xaU))));
    bufp->fullBit(oldp+2893,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 9U))));
    bufp->fullBit(oldp+2894,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 8U))));
    bufp->fullCData(oldp+2895,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 5U))),3);
    bufp->fullBit(oldp+2896,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x21U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x21U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 5U))))));
    bufp->fullBit(oldp+2897,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2898,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 7U))));
    bufp->fullBit(oldp+2899,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 6U))));
    bufp->fullBit(oldp+2900,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 5U))));
    bufp->fullCData(oldp+2901,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 2U))),3);
    bufp->fullBit(oldp+2902,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x21U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x21U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 2U))))));
    bufp->fullBit(oldp+2903,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2904,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 4U))));
    bufp->fullBit(oldp+2905,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 3U))));
    bufp->fullBit(oldp+2906,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 2U))));
    bufp->fullCData(oldp+2907,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2908,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2909,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2910,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x21U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2911,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 1U)))));
    bufp->fullBit(oldp+2912,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2913,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x21U] >> 1U))));
    bufp->fullCData(oldp+2914,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x21U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2915,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x21U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2916,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2917,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x21U])));
    bufp->fullBit(oldp+2918,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+2919,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+2920,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+2921,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+2922,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+2923,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+2924,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+2925,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+2926,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+2927,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+2928,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+2929,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+2930,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+2931,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+2932,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+2933,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+2934,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+2935,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+2936,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+2937,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+2938,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+2939,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+2940,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+2941,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+2942,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+2943,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+2944,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+2945,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+2946,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+2947,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+2948,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+2949,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+2950,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x22U]),17);
    bufp->fullSData(oldp+2951,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+2952,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout));
    bufp->fullBit(oldp+2953,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+2954,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+2955,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+2956,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+2957,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+2958,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+2959,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 0xeU))),3);
    bufp->fullBit(oldp+2960,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x22U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x22U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 0xeU))))));
    bufp->fullBit(oldp+2961,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+2962,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 0x10U))));
    bufp->fullBit(oldp+2963,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 0xfU))));
    bufp->fullBit(oldp+2964,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 0xeU))));
    bufp->fullCData(oldp+2965,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 0xbU))),3);
    bufp->fullBit(oldp+2966,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x22U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x22U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 0xbU))))));
    bufp->fullBit(oldp+2967,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+2968,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 0xdU))));
    bufp->fullBit(oldp+2969,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 0xcU))));
    bufp->fullBit(oldp+2970,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 0xbU))));
    bufp->fullCData(oldp+2971,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 8U))),3);
    bufp->fullBit(oldp+2972,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x22U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x22U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 8U))))));
    bufp->fullBit(oldp+2973,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+2974,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 0xaU))));
    bufp->fullBit(oldp+2975,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 9U))));
    bufp->fullBit(oldp+2976,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 8U))));
    bufp->fullCData(oldp+2977,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 5U))),3);
    bufp->fullBit(oldp+2978,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x22U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x22U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 5U))))));
    bufp->fullBit(oldp+2979,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+2980,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 7U))));
    bufp->fullBit(oldp+2981,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 6U))));
    bufp->fullBit(oldp+2982,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 5U))));
    bufp->fullCData(oldp+2983,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 2U))),3);
    bufp->fullBit(oldp+2984,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x22U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x22U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 2U))))));
    bufp->fullBit(oldp+2985,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+2986,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 4U))));
    bufp->fullBit(oldp+2987,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 3U))));
    bufp->fullBit(oldp+2988,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 2U))));
    bufp->fullCData(oldp+2989,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+2990,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+2991,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+2992,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x22U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+2993,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 1U)))));
    bufp->fullBit(oldp+2994,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+2995,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x22U] >> 1U))));
    bufp->fullCData(oldp+2996,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x22U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+2997,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x22U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+2998,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+2999,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x22U])));
    bufp->fullBit(oldp+3000,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3001,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3002,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3003,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3004,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3005,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3006,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3007,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3008,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3009,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3010,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3011,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3012,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3013,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3014,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3015,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3016,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3017,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3018,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3019,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3020,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3021,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3022,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3023,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3024,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3025,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3026,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3027,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3028,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3029,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3030,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3031,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3032,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x23U]),17);
    bufp->fullSData(oldp+3033,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3034,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3035,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3036,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3037,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3038,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3039,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3040,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3041,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 0xeU))),3);
    bufp->fullBit(oldp+3042,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x23U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x23U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 0xeU))))));
    bufp->fullBit(oldp+3043,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3044,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 0x10U))));
    bufp->fullBit(oldp+3045,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 0xfU))));
    bufp->fullBit(oldp+3046,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 0xeU))));
    bufp->fullCData(oldp+3047,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 0xbU))),3);
    bufp->fullBit(oldp+3048,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x23U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x23U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 0xbU))))));
    bufp->fullBit(oldp+3049,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3050,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 0xdU))));
    bufp->fullBit(oldp+3051,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 0xcU))));
    bufp->fullBit(oldp+3052,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 0xbU))));
    bufp->fullCData(oldp+3053,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 8U))),3);
    bufp->fullBit(oldp+3054,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x23U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x23U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 8U))))));
    bufp->fullBit(oldp+3055,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3056,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 0xaU))));
    bufp->fullBit(oldp+3057,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 9U))));
    bufp->fullBit(oldp+3058,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 8U))));
    bufp->fullCData(oldp+3059,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 5U))),3);
    bufp->fullBit(oldp+3060,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x23U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x23U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 5U))))));
    bufp->fullBit(oldp+3061,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3062,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 7U))));
    bufp->fullBit(oldp+3063,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 6U))));
    bufp->fullBit(oldp+3064,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 5U))));
    bufp->fullCData(oldp+3065,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 2U))),3);
    bufp->fullBit(oldp+3066,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x23U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x23U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 2U))))));
    bufp->fullBit(oldp+3067,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3068,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 4U))));
    bufp->fullBit(oldp+3069,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 3U))));
    bufp->fullBit(oldp+3070,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 2U))));
    bufp->fullCData(oldp+3071,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3072,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3073,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3074,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x23U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3075,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 1U)))));
    bufp->fullBit(oldp+3076,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3077,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x23U] >> 1U))));
    bufp->fullCData(oldp+3078,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x23U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3079,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x23U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3080,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3081,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x23U])));
    bufp->fullBit(oldp+3082,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3083,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3084,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3085,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3086,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3087,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3088,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3089,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3090,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3091,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3092,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3093,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3094,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3095,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3096,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3097,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3098,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3099,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3100,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3101,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3102,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3103,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3104,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3105,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3106,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3107,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3108,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3109,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3110,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3111,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3112,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3113,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3114,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x24U]),17);
    bufp->fullSData(oldp+3115,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3116,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3117,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3118,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3119,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3120,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3121,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3122,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3123,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 0xeU))),3);
    bufp->fullBit(oldp+3124,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x24U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x24U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 0xeU))))));
    bufp->fullBit(oldp+3125,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3126,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 0x10U))));
    bufp->fullBit(oldp+3127,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 0xfU))));
    bufp->fullBit(oldp+3128,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 0xeU))));
    bufp->fullCData(oldp+3129,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 0xbU))),3);
    bufp->fullBit(oldp+3130,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x24U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x24U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 0xbU))))));
    bufp->fullBit(oldp+3131,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3132,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 0xdU))));
    bufp->fullBit(oldp+3133,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 0xcU))));
    bufp->fullBit(oldp+3134,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 0xbU))));
    bufp->fullCData(oldp+3135,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 8U))),3);
    bufp->fullBit(oldp+3136,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x24U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x24U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 8U))))));
    bufp->fullBit(oldp+3137,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3138,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 0xaU))));
    bufp->fullBit(oldp+3139,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 9U))));
    bufp->fullBit(oldp+3140,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 8U))));
    bufp->fullCData(oldp+3141,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 5U))),3);
    bufp->fullBit(oldp+3142,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x24U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x24U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 5U))))));
    bufp->fullBit(oldp+3143,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3144,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 7U))));
    bufp->fullBit(oldp+3145,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 6U))));
    bufp->fullBit(oldp+3146,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 5U))));
    bufp->fullCData(oldp+3147,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 2U))),3);
    bufp->fullBit(oldp+3148,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x24U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x24U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 2U))))));
    bufp->fullBit(oldp+3149,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3150,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 4U))));
    bufp->fullBit(oldp+3151,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 3U))));
    bufp->fullBit(oldp+3152,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 2U))));
    bufp->fullCData(oldp+3153,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3154,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3155,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3156,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x24U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3157,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 1U)))));
    bufp->fullBit(oldp+3158,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3159,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x24U] >> 1U))));
    bufp->fullCData(oldp+3160,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x24U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3161,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x24U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3162,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3163,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x24U])));
    bufp->fullBit(oldp+3164,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3165,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3166,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3167,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3168,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3169,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3170,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3171,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3172,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3173,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3174,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3175,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3176,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3177,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3178,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3179,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3180,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3181,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3182,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3183,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3184,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3185,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3186,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3187,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3188,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3189,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3190,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3191,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3192,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3193,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3194,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3195,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3196,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x25U]),17);
    bufp->fullSData(oldp+3197,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3198,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3199,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3200,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3201,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3202,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3203,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3204,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3205,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 0xeU))),3);
    bufp->fullBit(oldp+3206,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x25U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x25U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 0xeU))))));
    bufp->fullBit(oldp+3207,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3208,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 0x10U))));
    bufp->fullBit(oldp+3209,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 0xfU))));
    bufp->fullBit(oldp+3210,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 0xeU))));
    bufp->fullCData(oldp+3211,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 0xbU))),3);
    bufp->fullBit(oldp+3212,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x25U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x25U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 0xbU))))));
    bufp->fullBit(oldp+3213,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3214,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 0xdU))));
    bufp->fullBit(oldp+3215,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 0xcU))));
    bufp->fullBit(oldp+3216,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 0xbU))));
    bufp->fullCData(oldp+3217,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 8U))),3);
    bufp->fullBit(oldp+3218,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x25U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x25U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 8U))))));
    bufp->fullBit(oldp+3219,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3220,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 0xaU))));
    bufp->fullBit(oldp+3221,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 9U))));
    bufp->fullBit(oldp+3222,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 8U))));
    bufp->fullCData(oldp+3223,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 5U))),3);
    bufp->fullBit(oldp+3224,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x25U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x25U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 5U))))));
    bufp->fullBit(oldp+3225,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3226,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 7U))));
    bufp->fullBit(oldp+3227,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 6U))));
    bufp->fullBit(oldp+3228,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 5U))));
    bufp->fullCData(oldp+3229,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 2U))),3);
    bufp->fullBit(oldp+3230,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x25U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x25U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 2U))))));
    bufp->fullBit(oldp+3231,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3232,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 4U))));
    bufp->fullBit(oldp+3233,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 3U))));
    bufp->fullBit(oldp+3234,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 2U))));
    bufp->fullCData(oldp+3235,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3236,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3237,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3238,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x25U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3239,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 1U)))));
    bufp->fullBit(oldp+3240,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3241,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x25U] >> 1U))));
    bufp->fullCData(oldp+3242,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x25U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3243,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x25U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3244,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3245,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x25U])));
    bufp->fullBit(oldp+3246,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3247,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3248,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3249,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3250,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3251,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3252,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3253,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3254,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3255,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3256,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3257,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3258,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3259,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3260,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3261,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3262,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3263,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3264,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3265,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3266,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3267,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3268,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3269,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3270,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3271,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3272,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3273,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3274,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3275,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3276,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3277,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3278,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x26U]),17);
    bufp->fullSData(oldp+3279,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3280,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3281,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3282,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3283,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3284,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3285,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3286,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3287,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 0xeU))),3);
    bufp->fullBit(oldp+3288,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x26U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x26U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 0xeU))))));
    bufp->fullBit(oldp+3289,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3290,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 0x10U))));
    bufp->fullBit(oldp+3291,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 0xfU))));
    bufp->fullBit(oldp+3292,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 0xeU))));
    bufp->fullCData(oldp+3293,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 0xbU))),3);
    bufp->fullBit(oldp+3294,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x26U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x26U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 0xbU))))));
    bufp->fullBit(oldp+3295,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3296,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 0xdU))));
    bufp->fullBit(oldp+3297,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 0xcU))));
    bufp->fullBit(oldp+3298,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 0xbU))));
    bufp->fullCData(oldp+3299,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 8U))),3);
    bufp->fullBit(oldp+3300,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x26U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x26U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 8U))))));
    bufp->fullBit(oldp+3301,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3302,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 0xaU))));
    bufp->fullBit(oldp+3303,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 9U))));
    bufp->fullBit(oldp+3304,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 8U))));
    bufp->fullCData(oldp+3305,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 5U))),3);
    bufp->fullBit(oldp+3306,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x26U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x26U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 5U))))));
    bufp->fullBit(oldp+3307,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3308,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 7U))));
    bufp->fullBit(oldp+3309,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 6U))));
    bufp->fullBit(oldp+3310,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 5U))));
    bufp->fullCData(oldp+3311,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 2U))),3);
    bufp->fullBit(oldp+3312,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x26U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x26U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 2U))))));
    bufp->fullBit(oldp+3313,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3314,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 4U))));
    bufp->fullBit(oldp+3315,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 3U))));
    bufp->fullBit(oldp+3316,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 2U))));
    bufp->fullCData(oldp+3317,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3318,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3319,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3320,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x26U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3321,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 1U)))));
    bufp->fullBit(oldp+3322,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3323,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x26U] >> 1U))));
    bufp->fullCData(oldp+3324,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x26U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3325,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x26U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3326,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3327,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x26U])));
    bufp->fullBit(oldp+3328,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3329,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3330,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3331,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3332,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3333,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3334,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3335,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3336,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3337,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3338,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3339,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3340,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3341,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3342,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3343,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3344,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3345,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3346,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3347,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3348,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3349,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3350,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3351,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3352,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3353,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3354,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3355,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3356,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3357,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3358,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3359,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3360,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x27U]),17);
    bufp->fullSData(oldp+3361,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3362,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3363,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3364,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3365,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3366,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3367,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3368,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3369,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 0xeU))),3);
    bufp->fullBit(oldp+3370,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x27U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x27U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 0xeU))))));
    bufp->fullBit(oldp+3371,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3372,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 0x10U))));
    bufp->fullBit(oldp+3373,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 0xfU))));
    bufp->fullBit(oldp+3374,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 0xeU))));
    bufp->fullCData(oldp+3375,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 0xbU))),3);
    bufp->fullBit(oldp+3376,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x27U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x27U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 0xbU))))));
    bufp->fullBit(oldp+3377,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3378,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 0xdU))));
    bufp->fullBit(oldp+3379,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 0xcU))));
    bufp->fullBit(oldp+3380,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 0xbU))));
    bufp->fullCData(oldp+3381,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 8U))),3);
    bufp->fullBit(oldp+3382,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x27U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x27U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 8U))))));
    bufp->fullBit(oldp+3383,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3384,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 0xaU))));
    bufp->fullBit(oldp+3385,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 9U))));
    bufp->fullBit(oldp+3386,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 8U))));
    bufp->fullCData(oldp+3387,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 5U))),3);
    bufp->fullBit(oldp+3388,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x27U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x27U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 5U))))));
    bufp->fullBit(oldp+3389,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3390,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 7U))));
    bufp->fullBit(oldp+3391,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 6U))));
    bufp->fullBit(oldp+3392,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 5U))));
    bufp->fullCData(oldp+3393,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 2U))),3);
    bufp->fullBit(oldp+3394,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x27U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x27U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 2U))))));
    bufp->fullBit(oldp+3395,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3396,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 4U))));
    bufp->fullBit(oldp+3397,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 3U))));
    bufp->fullBit(oldp+3398,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 2U))));
    bufp->fullCData(oldp+3399,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3400,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3401,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3402,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x27U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3403,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 1U)))));
    bufp->fullBit(oldp+3404,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3405,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x27U] >> 1U))));
    bufp->fullCData(oldp+3406,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x27U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3407,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x27U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3408,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3409,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x27U])));
    bufp->fullBit(oldp+3410,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3411,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3412,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3413,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3414,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3415,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3416,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3417,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3418,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3419,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3420,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3421,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3422,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3423,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3424,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3425,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3426,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3427,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3428,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3429,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3430,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3431,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3432,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3433,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3434,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3435,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3436,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3437,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3438,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3439,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3440,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3441,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3442,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x28U]),17);
    bufp->fullSData(oldp+3443,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3444,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3445,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3446,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3447,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3448,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3449,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3450,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3451,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x28U] >> 0xeU))),3);
    bufp->fullBit(oldp+3452,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x28U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x28U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x28U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x28U] >> 0xeU))))));
    bufp->fullBit(oldp+3453,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3454,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 0x10U))));
    bufp->fullBit(oldp+3455,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 0xfU))));
    bufp->fullBit(oldp+3456,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 0xeU))));
    bufp->fullCData(oldp+3457,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x28U] >> 0xbU))),3);
    bufp->fullBit(oldp+3458,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x28U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x28U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x28U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x28U] >> 0xbU))))));
    bufp->fullBit(oldp+3459,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3460,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 0xdU))));
    bufp->fullBit(oldp+3461,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 0xcU))));
    bufp->fullBit(oldp+3462,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 0xbU))));
    bufp->fullCData(oldp+3463,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x28U] >> 8U))),3);
    bufp->fullBit(oldp+3464,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x28U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x28U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x28U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x28U] >> 8U))))));
    bufp->fullBit(oldp+3465,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3466,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 0xaU))));
    bufp->fullBit(oldp+3467,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 9U))));
    bufp->fullBit(oldp+3468,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 8U))));
    bufp->fullCData(oldp+3469,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x28U] >> 5U))),3);
    bufp->fullBit(oldp+3470,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x28U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x28U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x28U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x28U] >> 5U))))));
    bufp->fullBit(oldp+3471,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3472,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 7U))));
    bufp->fullBit(oldp+3473,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 6U))));
    bufp->fullBit(oldp+3474,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 5U))));
    bufp->fullCData(oldp+3475,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x28U] >> 2U))),3);
    bufp->fullBit(oldp+3476,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x28U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x28U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x28U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x28U] >> 2U))))));
    bufp->fullBit(oldp+3477,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3478,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 4U))));
    bufp->fullBit(oldp+3479,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 3U))));
    bufp->fullBit(oldp+3480,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 2U))));
    bufp->fullCData(oldp+3481,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3482,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3483,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3484,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x28U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3485,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 1U)))));
    bufp->fullBit(oldp+3486,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3487,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x28U] >> 1U))));
    bufp->fullCData(oldp+3488,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3489,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x28U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x28U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3490,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3491,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x28U])));
    bufp->fullBit(oldp+3492,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3493,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3494,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3495,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3496,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3497,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3498,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3499,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3500,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3501,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3502,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3503,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3504,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3505,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3506,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3507,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3508,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3509,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3510,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3511,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3512,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3513,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3514,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3515,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3516,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3517,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3518,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3519,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3520,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3521,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3522,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3523,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3524,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x29U]),17);
    bufp->fullSData(oldp+3525,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3526,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3527,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3528,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3529,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3530,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3531,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3532,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3533,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x29U] >> 0xeU))),3);
    bufp->fullBit(oldp+3534,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x29U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x29U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x29U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x29U] >> 0xeU))))));
    bufp->fullBit(oldp+3535,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3536,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 0x10U))));
    bufp->fullBit(oldp+3537,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 0xfU))));
    bufp->fullBit(oldp+3538,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 0xeU))));
    bufp->fullCData(oldp+3539,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x29U] >> 0xbU))),3);
    bufp->fullBit(oldp+3540,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x29U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x29U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x29U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x29U] >> 0xbU))))));
    bufp->fullBit(oldp+3541,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3542,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 0xdU))));
    bufp->fullBit(oldp+3543,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 0xcU))));
    bufp->fullBit(oldp+3544,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 0xbU))));
    bufp->fullCData(oldp+3545,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x29U] >> 8U))),3);
    bufp->fullBit(oldp+3546,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x29U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x29U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x29U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x29U] >> 8U))))));
    bufp->fullBit(oldp+3547,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3548,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 0xaU))));
    bufp->fullBit(oldp+3549,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 9U))));
    bufp->fullBit(oldp+3550,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 8U))));
    bufp->fullCData(oldp+3551,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x29U] >> 5U))),3);
    bufp->fullBit(oldp+3552,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x29U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x29U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x29U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x29U] >> 5U))))));
    bufp->fullBit(oldp+3553,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3554,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 7U))));
    bufp->fullBit(oldp+3555,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 6U))));
    bufp->fullBit(oldp+3556,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 5U))));
    bufp->fullCData(oldp+3557,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x29U] >> 2U))),3);
    bufp->fullBit(oldp+3558,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x29U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x29U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x29U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x29U] >> 2U))))));
    bufp->fullBit(oldp+3559,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3560,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 4U))));
    bufp->fullBit(oldp+3561,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 3U))));
    bufp->fullBit(oldp+3562,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 2U))));
    bufp->fullCData(oldp+3563,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3564,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3565,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3566,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x29U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3567,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 1U)))));
    bufp->fullBit(oldp+3568,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3569,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x29U] >> 1U))));
    bufp->fullCData(oldp+3570,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3571,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x29U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x29U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3572,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3573,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x29U])));
    bufp->fullBit(oldp+3574,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3575,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3576,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3577,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3578,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3579,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3580,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3581,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3582,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3583,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3584,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3585,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3586,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3587,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3588,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3589,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3590,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3591,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3592,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3593,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3594,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3595,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3596,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3597,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3598,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3599,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3600,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3601,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3602,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3603,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3604,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3605,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3606,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x2aU]),17);
    bufp->fullSData(oldp+3607,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3608,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3609,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3610,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3611,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3612,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3613,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3614,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3615,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2aU] >> 0xeU))),3);
    bufp->fullBit(oldp+3616,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2aU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2aU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2aU] >> 0xeU))))));
    bufp->fullBit(oldp+3617,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3618,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 0x10U))));
    bufp->fullBit(oldp+3619,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 0xfU))));
    bufp->fullBit(oldp+3620,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 0xeU))));
    bufp->fullCData(oldp+3621,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2aU] >> 0xbU))),3);
    bufp->fullBit(oldp+3622,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2aU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2aU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2aU] >> 0xbU))))));
    bufp->fullBit(oldp+3623,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3624,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 0xdU))));
    bufp->fullBit(oldp+3625,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 0xcU))));
    bufp->fullBit(oldp+3626,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 0xbU))));
    bufp->fullCData(oldp+3627,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2aU] >> 8U))),3);
    bufp->fullBit(oldp+3628,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2aU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2aU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2aU] >> 8U))))));
    bufp->fullBit(oldp+3629,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3630,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 0xaU))));
    bufp->fullBit(oldp+3631,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 9U))));
    bufp->fullBit(oldp+3632,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 8U))));
    bufp->fullCData(oldp+3633,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2aU] >> 5U))),3);
    bufp->fullBit(oldp+3634,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2aU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2aU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2aU] >> 5U))))));
    bufp->fullBit(oldp+3635,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3636,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 7U))));
    bufp->fullBit(oldp+3637,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 6U))));
    bufp->fullBit(oldp+3638,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 5U))));
    bufp->fullCData(oldp+3639,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2aU] >> 2U))),3);
    bufp->fullBit(oldp+3640,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2aU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2aU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2aU] >> 2U))))));
    bufp->fullBit(oldp+3641,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3642,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 4U))));
    bufp->fullBit(oldp+3643,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 3U))));
    bufp->fullBit(oldp+3644,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 2U))));
    bufp->fullCData(oldp+3645,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3646,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3647,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3648,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2aU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3649,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 1U)))));
    bufp->fullBit(oldp+3650,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3651,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2aU] >> 1U))));
    bufp->fullCData(oldp+3652,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3653,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x2aU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2aU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3654,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3655,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x2aU])));
    bufp->fullBit(oldp+3656,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3657,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3658,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3659,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3660,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3661,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3662,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3663,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3664,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3665,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3666,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3667,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3668,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3669,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3670,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3671,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3672,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3673,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3674,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3675,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3676,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3677,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3678,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3679,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3680,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3681,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3682,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3683,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3684,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3685,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3686,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3687,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3688,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x2bU]),17);
    bufp->fullSData(oldp+3689,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3690,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3691,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3692,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3693,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3694,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3695,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3696,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3697,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2bU] >> 0xeU))),3);
    bufp->fullBit(oldp+3698,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2bU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2bU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2bU] >> 0xeU))))));
    bufp->fullBit(oldp+3699,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3700,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 0x10U))));
    bufp->fullBit(oldp+3701,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 0xfU))));
    bufp->fullBit(oldp+3702,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 0xeU))));
    bufp->fullCData(oldp+3703,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2bU] >> 0xbU))),3);
    bufp->fullBit(oldp+3704,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2bU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2bU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2bU] >> 0xbU))))));
    bufp->fullBit(oldp+3705,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3706,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 0xdU))));
    bufp->fullBit(oldp+3707,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 0xcU))));
    bufp->fullBit(oldp+3708,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 0xbU))));
    bufp->fullCData(oldp+3709,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2bU] >> 8U))),3);
    bufp->fullBit(oldp+3710,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2bU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2bU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2bU] >> 8U))))));
    bufp->fullBit(oldp+3711,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3712,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 0xaU))));
    bufp->fullBit(oldp+3713,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 9U))));
    bufp->fullBit(oldp+3714,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 8U))));
    bufp->fullCData(oldp+3715,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2bU] >> 5U))),3);
    bufp->fullBit(oldp+3716,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2bU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2bU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2bU] >> 5U))))));
    bufp->fullBit(oldp+3717,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3718,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 7U))));
    bufp->fullBit(oldp+3719,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 6U))));
    bufp->fullBit(oldp+3720,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 5U))));
    bufp->fullCData(oldp+3721,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2bU] >> 2U))),3);
    bufp->fullBit(oldp+3722,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2bU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2bU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2bU] >> 2U))))));
    bufp->fullBit(oldp+3723,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3724,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 4U))));
    bufp->fullBit(oldp+3725,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 3U))));
    bufp->fullBit(oldp+3726,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 2U))));
    bufp->fullCData(oldp+3727,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3728,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3729,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3730,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2bU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3731,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 1U)))));
    bufp->fullBit(oldp+3732,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3733,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2bU] >> 1U))));
    bufp->fullCData(oldp+3734,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3735,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x2bU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2bU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3736,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3737,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x2bU])));
    bufp->fullBit(oldp+3738,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3739,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3740,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3741,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3742,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3743,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3744,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3745,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3746,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3747,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3748,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3749,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3750,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3751,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3752,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3753,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3754,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3755,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3756,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3757,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3758,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3759,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3760,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3761,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3762,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3763,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3764,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3765,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3766,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3767,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3768,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3769,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3770,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x2cU]),17);
    bufp->fullSData(oldp+3771,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3772,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3773,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3774,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3775,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3776,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3777,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3778,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3779,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2cU] >> 0xeU))),3);
    bufp->fullBit(oldp+3780,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2cU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2cU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2cU] >> 0xeU))))));
    bufp->fullBit(oldp+3781,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3782,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 0x10U))));
    bufp->fullBit(oldp+3783,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 0xfU))));
    bufp->fullBit(oldp+3784,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 0xeU))));
    bufp->fullCData(oldp+3785,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2cU] >> 0xbU))),3);
    bufp->fullBit(oldp+3786,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2cU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2cU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2cU] >> 0xbU))))));
    bufp->fullBit(oldp+3787,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3788,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 0xdU))));
    bufp->fullBit(oldp+3789,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 0xcU))));
    bufp->fullBit(oldp+3790,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 0xbU))));
    bufp->fullCData(oldp+3791,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2cU] >> 8U))),3);
    bufp->fullBit(oldp+3792,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2cU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2cU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2cU] >> 8U))))));
    bufp->fullBit(oldp+3793,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3794,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 0xaU))));
    bufp->fullBit(oldp+3795,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 9U))));
    bufp->fullBit(oldp+3796,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 8U))));
    bufp->fullCData(oldp+3797,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2cU] >> 5U))),3);
    bufp->fullBit(oldp+3798,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2cU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2cU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2cU] >> 5U))))));
    bufp->fullBit(oldp+3799,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3800,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 7U))));
    bufp->fullBit(oldp+3801,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 6U))));
    bufp->fullBit(oldp+3802,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 5U))));
    bufp->fullCData(oldp+3803,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2cU] >> 2U))),3);
    bufp->fullBit(oldp+3804,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2cU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2cU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2cU] >> 2U))))));
    bufp->fullBit(oldp+3805,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3806,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 4U))));
    bufp->fullBit(oldp+3807,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 3U))));
    bufp->fullBit(oldp+3808,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 2U))));
    bufp->fullCData(oldp+3809,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3810,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3811,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3812,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2cU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3813,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 1U)))));
    bufp->fullBit(oldp+3814,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3815,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2cU] >> 1U))));
    bufp->fullCData(oldp+3816,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3817,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x2cU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2cU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3818,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3819,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x2cU])));
    bufp->fullBit(oldp+3820,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3821,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3822,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3823,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3824,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3825,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3826,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3827,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3828,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3829,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3830,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3831,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3832,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3833,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3834,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3835,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3836,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3837,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3838,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3839,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3840,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3841,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3842,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3843,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3844,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3845,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3846,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3847,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3848,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3849,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3850,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3851,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3852,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x2dU]),17);
    bufp->fullSData(oldp+3853,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3854,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3855,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3856,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3857,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3858,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3859,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3860,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3861,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2dU] >> 0xeU))),3);
    bufp->fullBit(oldp+3862,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2dU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2dU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2dU] >> 0xeU))))));
    bufp->fullBit(oldp+3863,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3864,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 0x10U))));
    bufp->fullBit(oldp+3865,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 0xfU))));
    bufp->fullBit(oldp+3866,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 0xeU))));
    bufp->fullCData(oldp+3867,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2dU] >> 0xbU))),3);
    bufp->fullBit(oldp+3868,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2dU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2dU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2dU] >> 0xbU))))));
    bufp->fullBit(oldp+3869,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3870,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 0xdU))));
    bufp->fullBit(oldp+3871,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 0xcU))));
    bufp->fullBit(oldp+3872,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 0xbU))));
    bufp->fullCData(oldp+3873,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2dU] >> 8U))),3);
    bufp->fullBit(oldp+3874,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2dU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2dU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2dU] >> 8U))))));
    bufp->fullBit(oldp+3875,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3876,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 0xaU))));
    bufp->fullBit(oldp+3877,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 9U))));
    bufp->fullBit(oldp+3878,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 8U))));
    bufp->fullCData(oldp+3879,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2dU] >> 5U))),3);
    bufp->fullBit(oldp+3880,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2dU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2dU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2dU] >> 5U))))));
    bufp->fullBit(oldp+3881,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3882,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 7U))));
    bufp->fullBit(oldp+3883,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 6U))));
    bufp->fullBit(oldp+3884,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 5U))));
    bufp->fullCData(oldp+3885,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2dU] >> 2U))),3);
    bufp->fullBit(oldp+3886,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2dU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2dU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2dU] >> 2U))))));
    bufp->fullBit(oldp+3887,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3888,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 4U))));
    bufp->fullBit(oldp+3889,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 3U))));
    bufp->fullBit(oldp+3890,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 2U))));
    bufp->fullCData(oldp+3891,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3892,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3893,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3894,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2dU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3895,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 1U)))));
    bufp->fullBit(oldp+3896,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3897,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2dU] >> 1U))));
    bufp->fullCData(oldp+3898,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3899,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x2dU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2dU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3900,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3901,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x2dU])));
    bufp->fullBit(oldp+3902,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3903,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3904,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3905,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3906,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3907,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3908,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3909,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3910,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3911,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3912,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3913,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3914,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3915,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3916,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3917,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+3918,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+3919,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+3920,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+3921,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+3922,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+3923,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+3924,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+3925,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+3926,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+3927,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+3928,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+3929,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+3930,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+3931,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+3932,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+3933,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+3934,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x2eU]),17);
    bufp->fullSData(oldp+3935,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+3936,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout));
    bufp->fullBit(oldp+3937,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+3938,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+3939,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+3940,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+3941,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+3942,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+3943,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2eU] >> 0xeU))),3);
    bufp->fullBit(oldp+3944,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2eU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2eU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2eU] >> 0xeU))))));
    bufp->fullBit(oldp+3945,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+3946,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 0x10U))));
    bufp->fullBit(oldp+3947,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 0xfU))));
    bufp->fullBit(oldp+3948,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 0xeU))));
    bufp->fullCData(oldp+3949,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2eU] >> 0xbU))),3);
    bufp->fullBit(oldp+3950,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2eU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2eU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2eU] >> 0xbU))))));
    bufp->fullBit(oldp+3951,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+3952,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 0xdU))));
    bufp->fullBit(oldp+3953,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 0xcU))));
    bufp->fullBit(oldp+3954,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 0xbU))));
    bufp->fullCData(oldp+3955,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2eU] >> 8U))),3);
    bufp->fullBit(oldp+3956,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2eU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2eU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2eU] >> 8U))))));
    bufp->fullBit(oldp+3957,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+3958,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 0xaU))));
    bufp->fullBit(oldp+3959,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 9U))));
    bufp->fullBit(oldp+3960,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 8U))));
    bufp->fullCData(oldp+3961,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2eU] >> 5U))),3);
    bufp->fullBit(oldp+3962,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2eU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2eU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2eU] >> 5U))))));
    bufp->fullBit(oldp+3963,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+3964,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 7U))));
    bufp->fullBit(oldp+3965,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 6U))));
    bufp->fullBit(oldp+3966,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 5U))));
    bufp->fullCData(oldp+3967,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2eU] >> 2U))),3);
    bufp->fullBit(oldp+3968,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2eU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2eU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2eU] >> 2U))))));
    bufp->fullBit(oldp+3969,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+3970,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 4U))));
    bufp->fullBit(oldp+3971,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 3U))));
    bufp->fullBit(oldp+3972,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 2U))));
    bufp->fullCData(oldp+3973,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+3974,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+3975,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+3976,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2eU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+3977,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 1U)))));
    bufp->fullBit(oldp+3978,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+3979,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2eU] >> 1U))));
    bufp->fullCData(oldp+3980,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+3981,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x2eU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2eU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+3982,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+3983,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x2eU])));
    bufp->fullBit(oldp+3984,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+3985,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+3986,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+3987,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+3988,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+3989,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+3990,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+3991,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+3992,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+3993,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+3994,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+3995,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+3996,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+3997,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+3998,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+3999,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4000,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4001,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4002,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4003,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4004,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4005,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4006,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4007,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4008,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4009,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4010,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4011,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4012,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4013,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4014,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4015,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4016,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x2fU]),17);
    bufp->fullSData(oldp+4017,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4018,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4019,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4020,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4021,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4022,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4023,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4024,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4025,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2fU] >> 0xeU))),3);
    bufp->fullBit(oldp+4026,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2fU] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2fU] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2fU] >> 0xeU))))));
    bufp->fullBit(oldp+4027,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4028,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 0x10U))));
    bufp->fullBit(oldp+4029,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 0xfU))));
    bufp->fullBit(oldp+4030,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 0xeU))));
    bufp->fullCData(oldp+4031,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2fU] >> 0xbU))),3);
    bufp->fullBit(oldp+4032,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2fU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2fU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2fU] >> 0xbU))))));
    bufp->fullBit(oldp+4033,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4034,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 0xdU))));
    bufp->fullBit(oldp+4035,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 0xcU))));
    bufp->fullBit(oldp+4036,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 0xbU))));
    bufp->fullCData(oldp+4037,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2fU] >> 8U))),3);
    bufp->fullBit(oldp+4038,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2fU] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2fU] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2fU] >> 8U))))));
    bufp->fullBit(oldp+4039,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4040,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 0xaU))));
    bufp->fullBit(oldp+4041,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 9U))));
    bufp->fullBit(oldp+4042,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 8U))));
    bufp->fullCData(oldp+4043,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2fU] >> 5U))),3);
    bufp->fullBit(oldp+4044,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2fU] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2fU] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2fU] >> 5U))))));
    bufp->fullBit(oldp+4045,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4046,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 7U))));
    bufp->fullBit(oldp+4047,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 6U))));
    bufp->fullBit(oldp+4048,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 5U))));
    bufp->fullCData(oldp+4049,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2fU] >> 2U))),3);
    bufp->fullBit(oldp+4050,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x2fU] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2fU] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2fU] >> 2U))))));
    bufp->fullBit(oldp+4051,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4052,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 4U))));
    bufp->fullBit(oldp+4053,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 3U))));
    bufp->fullBit(oldp+4054,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 2U))));
    bufp->fullCData(oldp+4055,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4056,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4057,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4058,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2fU] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4059,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 1U)))));
    bufp->fullBit(oldp+4060,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4061,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x2fU] >> 1U))));
    bufp->fullCData(oldp+4062,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4063,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x2fU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2fU]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4064,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4065,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x2fU])));
    bufp->fullBit(oldp+4066,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4067,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4068,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4069,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4070,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4071,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4072,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4073,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4074,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4075,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4076,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4077,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4078,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4079,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4080,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4081,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4082,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4083,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4084,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4085,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4086,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4087,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4088,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4089,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4090,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4091,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4092,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4093,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4094,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4095,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4096,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4097,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4098,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x30U]),17);
    bufp->fullSData(oldp+4099,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4100,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4101,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4102,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4103,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4104,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4105,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4106,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4107,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x30U] >> 0xeU))),3);
    bufp->fullBit(oldp+4108,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x30U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x30U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x30U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x30U] >> 0xeU))))));
    bufp->fullBit(oldp+4109,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4110,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 0x10U))));
    bufp->fullBit(oldp+4111,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 0xfU))));
    bufp->fullBit(oldp+4112,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 0xeU))));
    bufp->fullCData(oldp+4113,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x30U] >> 0xbU))),3);
    bufp->fullBit(oldp+4114,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x30U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x30U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x30U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x30U] >> 0xbU))))));
    bufp->fullBit(oldp+4115,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4116,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 0xdU))));
    bufp->fullBit(oldp+4117,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 0xcU))));
    bufp->fullBit(oldp+4118,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 0xbU))));
    bufp->fullCData(oldp+4119,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x30U] >> 8U))),3);
    bufp->fullBit(oldp+4120,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x30U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x30U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x30U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x30U] >> 8U))))));
    bufp->fullBit(oldp+4121,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4122,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 0xaU))));
    bufp->fullBit(oldp+4123,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 9U))));
    bufp->fullBit(oldp+4124,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 8U))));
    bufp->fullCData(oldp+4125,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x30U] >> 5U))),3);
    bufp->fullBit(oldp+4126,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x30U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x30U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x30U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x30U] >> 5U))))));
    bufp->fullBit(oldp+4127,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4128,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 7U))));
    bufp->fullBit(oldp+4129,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 6U))));
    bufp->fullBit(oldp+4130,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 5U))));
    bufp->fullCData(oldp+4131,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x30U] >> 2U))),3);
    bufp->fullBit(oldp+4132,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x30U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x30U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x30U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x30U] >> 2U))))));
    bufp->fullBit(oldp+4133,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4134,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 4U))));
    bufp->fullBit(oldp+4135,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 3U))));
    bufp->fullBit(oldp+4136,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 2U))));
    bufp->fullCData(oldp+4137,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4138,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4139,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4140,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x30U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4141,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 1U)))));
    bufp->fullBit(oldp+4142,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4143,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x30U] >> 1U))));
    bufp->fullCData(oldp+4144,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4145,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x30U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x30U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4146,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4147,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x30U])));
    bufp->fullBit(oldp+4148,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4149,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4150,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4151,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4152,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4153,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4154,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4155,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4156,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4157,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4158,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4159,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4160,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4161,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4162,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4163,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4164,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4165,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4166,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4167,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4168,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4169,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4170,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4171,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4172,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4173,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4174,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4175,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4176,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4177,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4178,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4179,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4180,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x31U]),17);
    bufp->fullSData(oldp+4181,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4182,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4183,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4184,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4185,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4186,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4187,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4188,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4189,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x31U] >> 0xeU))),3);
    bufp->fullBit(oldp+4190,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x31U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x31U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x31U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x31U] >> 0xeU))))));
    bufp->fullBit(oldp+4191,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4192,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 0x10U))));
    bufp->fullBit(oldp+4193,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 0xfU))));
    bufp->fullBit(oldp+4194,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 0xeU))));
    bufp->fullCData(oldp+4195,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x31U] >> 0xbU))),3);
    bufp->fullBit(oldp+4196,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x31U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x31U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x31U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x31U] >> 0xbU))))));
    bufp->fullBit(oldp+4197,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4198,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 0xdU))));
    bufp->fullBit(oldp+4199,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 0xcU))));
    bufp->fullBit(oldp+4200,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 0xbU))));
    bufp->fullCData(oldp+4201,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x31U] >> 8U))),3);
    bufp->fullBit(oldp+4202,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x31U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x31U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x31U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x31U] >> 8U))))));
    bufp->fullBit(oldp+4203,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4204,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 0xaU))));
    bufp->fullBit(oldp+4205,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 9U))));
    bufp->fullBit(oldp+4206,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 8U))));
    bufp->fullCData(oldp+4207,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x31U] >> 5U))),3);
    bufp->fullBit(oldp+4208,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x31U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x31U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x31U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x31U] >> 5U))))));
    bufp->fullBit(oldp+4209,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4210,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 7U))));
    bufp->fullBit(oldp+4211,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 6U))));
    bufp->fullBit(oldp+4212,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 5U))));
    bufp->fullCData(oldp+4213,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x31U] >> 2U))),3);
    bufp->fullBit(oldp+4214,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x31U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x31U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x31U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x31U] >> 2U))))));
    bufp->fullBit(oldp+4215,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4216,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 4U))));
    bufp->fullBit(oldp+4217,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 3U))));
    bufp->fullBit(oldp+4218,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 2U))));
    bufp->fullCData(oldp+4219,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4220,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4221,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4222,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x31U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4223,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 1U)))));
    bufp->fullBit(oldp+4224,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4225,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x31U] >> 1U))));
    bufp->fullCData(oldp+4226,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4227,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x31U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x31U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4228,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4229,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x31U])));
    bufp->fullBit(oldp+4230,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4231,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4232,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4233,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4234,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4235,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4236,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4237,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4238,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4239,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4240,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4241,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4242,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4243,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4244,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4245,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4246,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4247,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4248,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4249,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4250,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4251,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4252,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4253,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4254,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4255,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4256,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4257,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4258,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4259,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4260,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4261,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4262,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x32U]),17);
    bufp->fullSData(oldp+4263,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4264,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4265,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4266,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4267,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4268,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4269,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4270,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4271,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x32U] >> 0xeU))),3);
    bufp->fullBit(oldp+4272,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x32U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x32U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x32U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x32U] >> 0xeU))))));
    bufp->fullBit(oldp+4273,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4274,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 0x10U))));
    bufp->fullBit(oldp+4275,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 0xfU))));
    bufp->fullBit(oldp+4276,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 0xeU))));
    bufp->fullCData(oldp+4277,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x32U] >> 0xbU))),3);
    bufp->fullBit(oldp+4278,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x32U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x32U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x32U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x32U] >> 0xbU))))));
    bufp->fullBit(oldp+4279,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4280,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 0xdU))));
    bufp->fullBit(oldp+4281,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 0xcU))));
    bufp->fullBit(oldp+4282,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 0xbU))));
    bufp->fullCData(oldp+4283,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x32U] >> 8U))),3);
    bufp->fullBit(oldp+4284,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x32U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x32U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x32U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x32U] >> 8U))))));
    bufp->fullBit(oldp+4285,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4286,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 0xaU))));
    bufp->fullBit(oldp+4287,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 9U))));
    bufp->fullBit(oldp+4288,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 8U))));
    bufp->fullCData(oldp+4289,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x32U] >> 5U))),3);
    bufp->fullBit(oldp+4290,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x32U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x32U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x32U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x32U] >> 5U))))));
    bufp->fullBit(oldp+4291,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4292,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 7U))));
    bufp->fullBit(oldp+4293,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 6U))));
    bufp->fullBit(oldp+4294,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 5U))));
    bufp->fullCData(oldp+4295,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x32U] >> 2U))),3);
    bufp->fullBit(oldp+4296,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x32U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x32U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x32U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x32U] >> 2U))))));
    bufp->fullBit(oldp+4297,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4298,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 4U))));
    bufp->fullBit(oldp+4299,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 3U))));
    bufp->fullBit(oldp+4300,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 2U))));
    bufp->fullCData(oldp+4301,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4302,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4303,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4304,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x32U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4305,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 1U)))));
    bufp->fullBit(oldp+4306,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4307,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x32U] >> 1U))));
    bufp->fullCData(oldp+4308,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4309,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x32U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x32U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4310,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4311,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x32U])));
    bufp->fullBit(oldp+4312,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4313,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4314,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4315,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4316,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4317,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4318,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4319,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4320,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4321,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4322,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4323,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4324,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4325,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4326,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4327,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4328,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4329,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4330,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4331,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4332,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4333,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4334,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4335,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4336,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4337,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4338,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4339,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4340,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4341,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4342,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4343,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4344,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x33U]),17);
    bufp->fullSData(oldp+4345,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4346,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4347,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4348,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4349,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4350,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4351,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4352,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4353,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x33U] >> 0xeU))),3);
    bufp->fullBit(oldp+4354,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x33U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x33U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x33U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x33U] >> 0xeU))))));
    bufp->fullBit(oldp+4355,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4356,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 0x10U))));
    bufp->fullBit(oldp+4357,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 0xfU))));
    bufp->fullBit(oldp+4358,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 0xeU))));
    bufp->fullCData(oldp+4359,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x33U] >> 0xbU))),3);
    bufp->fullBit(oldp+4360,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x33U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x33U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x33U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x33U] >> 0xbU))))));
    bufp->fullBit(oldp+4361,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4362,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 0xdU))));
    bufp->fullBit(oldp+4363,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 0xcU))));
    bufp->fullBit(oldp+4364,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 0xbU))));
    bufp->fullCData(oldp+4365,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x33U] >> 8U))),3);
    bufp->fullBit(oldp+4366,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x33U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x33U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x33U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x33U] >> 8U))))));
    bufp->fullBit(oldp+4367,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4368,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 0xaU))));
    bufp->fullBit(oldp+4369,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 9U))));
    bufp->fullBit(oldp+4370,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 8U))));
    bufp->fullCData(oldp+4371,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x33U] >> 5U))),3);
    bufp->fullBit(oldp+4372,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x33U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x33U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x33U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x33U] >> 5U))))));
    bufp->fullBit(oldp+4373,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4374,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 7U))));
    bufp->fullBit(oldp+4375,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 6U))));
    bufp->fullBit(oldp+4376,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 5U))));
    bufp->fullCData(oldp+4377,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x33U] >> 2U))),3);
    bufp->fullBit(oldp+4378,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x33U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x33U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x33U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x33U] >> 2U))))));
    bufp->fullBit(oldp+4379,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4380,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 4U))));
    bufp->fullBit(oldp+4381,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 3U))));
    bufp->fullBit(oldp+4382,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 2U))));
    bufp->fullCData(oldp+4383,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4384,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4385,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4386,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x33U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4387,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 1U)))));
    bufp->fullBit(oldp+4388,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4389,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x33U] >> 1U))));
    bufp->fullCData(oldp+4390,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4391,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x33U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x33U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4392,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4393,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x33U])));
    bufp->fullBit(oldp+4394,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4395,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4396,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4397,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4398,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4399,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4400,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4401,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4402,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4403,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4404,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4405,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4406,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4407,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4408,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4409,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4410,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4411,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4412,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4413,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4414,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4415,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4416,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4417,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4418,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4419,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4420,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4421,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4422,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4423,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4424,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4425,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4426,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x34U]),17);
    bufp->fullSData(oldp+4427,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4428,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4429,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4430,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4431,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4432,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4433,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4434,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4435,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x34U] >> 0xeU))),3);
    bufp->fullBit(oldp+4436,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x34U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x34U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x34U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x34U] >> 0xeU))))));
    bufp->fullBit(oldp+4437,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4438,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 0x10U))));
    bufp->fullBit(oldp+4439,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 0xfU))));
    bufp->fullBit(oldp+4440,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 0xeU))));
    bufp->fullCData(oldp+4441,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x34U] >> 0xbU))),3);
    bufp->fullBit(oldp+4442,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x34U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x34U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x34U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x34U] >> 0xbU))))));
    bufp->fullBit(oldp+4443,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4444,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 0xdU))));
    bufp->fullBit(oldp+4445,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 0xcU))));
    bufp->fullBit(oldp+4446,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 0xbU))));
    bufp->fullCData(oldp+4447,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x34U] >> 8U))),3);
    bufp->fullBit(oldp+4448,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x34U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x34U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x34U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x34U] >> 8U))))));
    bufp->fullBit(oldp+4449,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4450,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 0xaU))));
    bufp->fullBit(oldp+4451,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 9U))));
    bufp->fullBit(oldp+4452,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 8U))));
    bufp->fullCData(oldp+4453,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x34U] >> 5U))),3);
    bufp->fullBit(oldp+4454,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x34U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x34U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x34U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x34U] >> 5U))))));
    bufp->fullBit(oldp+4455,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4456,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 7U))));
    bufp->fullBit(oldp+4457,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 6U))));
    bufp->fullBit(oldp+4458,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 5U))));
    bufp->fullCData(oldp+4459,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x34U] >> 2U))),3);
    bufp->fullBit(oldp+4460,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x34U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x34U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x34U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x34U] >> 2U))))));
    bufp->fullBit(oldp+4461,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4462,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 4U))));
    bufp->fullBit(oldp+4463,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 3U))));
    bufp->fullBit(oldp+4464,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 2U))));
    bufp->fullCData(oldp+4465,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4466,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4467,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4468,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x34U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4469,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 1U)))));
    bufp->fullBit(oldp+4470,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4471,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x34U] >> 1U))));
    bufp->fullCData(oldp+4472,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4473,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x34U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x34U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4474,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4475,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x34U])));
    bufp->fullBit(oldp+4476,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4477,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4478,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4479,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4480,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4481,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4482,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4483,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4484,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4485,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4486,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4487,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4488,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4489,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4490,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4491,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4492,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4493,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4494,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4495,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4496,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4497,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4498,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4499,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4500,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4501,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4502,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4503,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4504,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4505,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4506,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4507,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4508,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x35U]),17);
    bufp->fullSData(oldp+4509,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4510,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4511,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4512,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4513,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4514,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4515,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4516,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4517,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x35U] >> 0xeU))),3);
    bufp->fullBit(oldp+4518,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x35U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x35U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x35U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x35U] >> 0xeU))))));
    bufp->fullBit(oldp+4519,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4520,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 0x10U))));
    bufp->fullBit(oldp+4521,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 0xfU))));
    bufp->fullBit(oldp+4522,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 0xeU))));
    bufp->fullCData(oldp+4523,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x35U] >> 0xbU))),3);
    bufp->fullBit(oldp+4524,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x35U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x35U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x35U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x35U] >> 0xbU))))));
    bufp->fullBit(oldp+4525,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4526,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 0xdU))));
    bufp->fullBit(oldp+4527,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 0xcU))));
    bufp->fullBit(oldp+4528,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 0xbU))));
    bufp->fullCData(oldp+4529,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x35U] >> 8U))),3);
    bufp->fullBit(oldp+4530,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x35U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x35U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x35U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x35U] >> 8U))))));
    bufp->fullBit(oldp+4531,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4532,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 0xaU))));
    bufp->fullBit(oldp+4533,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 9U))));
    bufp->fullBit(oldp+4534,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 8U))));
    bufp->fullCData(oldp+4535,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x35U] >> 5U))),3);
    bufp->fullBit(oldp+4536,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x35U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x35U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x35U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x35U] >> 5U))))));
    bufp->fullBit(oldp+4537,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4538,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 7U))));
    bufp->fullBit(oldp+4539,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 6U))));
    bufp->fullBit(oldp+4540,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 5U))));
    bufp->fullCData(oldp+4541,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x35U] >> 2U))),3);
    bufp->fullBit(oldp+4542,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x35U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x35U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x35U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x35U] >> 2U))))));
    bufp->fullBit(oldp+4543,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4544,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 4U))));
    bufp->fullBit(oldp+4545,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 3U))));
    bufp->fullBit(oldp+4546,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 2U))));
    bufp->fullCData(oldp+4547,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4548,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4549,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4550,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x35U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4551,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 1U)))));
    bufp->fullBit(oldp+4552,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4553,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x35U] >> 1U))));
    bufp->fullCData(oldp+4554,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4555,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x35U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x35U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4556,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4557,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x35U])));
    bufp->fullBit(oldp+4558,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4559,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4560,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4561,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4562,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4563,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4564,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4565,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4566,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4567,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4568,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4569,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4570,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4571,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4572,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4573,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4574,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4575,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4576,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4577,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4578,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4579,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4580,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4581,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4582,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4583,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4584,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4585,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4586,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4587,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4588,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4589,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4590,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x36U]),17);
    bufp->fullSData(oldp+4591,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4592,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4593,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4594,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4595,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4596,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4597,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4598,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4599,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x36U] >> 0xeU))),3);
    bufp->fullBit(oldp+4600,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x36U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x36U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x36U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x36U] >> 0xeU))))));
    bufp->fullBit(oldp+4601,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4602,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 0x10U))));
    bufp->fullBit(oldp+4603,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 0xfU))));
    bufp->fullBit(oldp+4604,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 0xeU))));
    bufp->fullCData(oldp+4605,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x36U] >> 0xbU))),3);
    bufp->fullBit(oldp+4606,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x36U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x36U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x36U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x36U] >> 0xbU))))));
    bufp->fullBit(oldp+4607,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4608,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 0xdU))));
    bufp->fullBit(oldp+4609,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 0xcU))));
    bufp->fullBit(oldp+4610,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 0xbU))));
    bufp->fullCData(oldp+4611,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x36U] >> 8U))),3);
    bufp->fullBit(oldp+4612,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x36U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x36U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x36U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x36U] >> 8U))))));
    bufp->fullBit(oldp+4613,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4614,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 0xaU))));
    bufp->fullBit(oldp+4615,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 9U))));
    bufp->fullBit(oldp+4616,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 8U))));
    bufp->fullCData(oldp+4617,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x36U] >> 5U))),3);
    bufp->fullBit(oldp+4618,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x36U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x36U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x36U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x36U] >> 5U))))));
    bufp->fullBit(oldp+4619,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4620,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 7U))));
    bufp->fullBit(oldp+4621,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 6U))));
    bufp->fullBit(oldp+4622,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 5U))));
    bufp->fullCData(oldp+4623,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x36U] >> 2U))),3);
    bufp->fullBit(oldp+4624,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x36U] >> 4U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x36U] >> 3U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 3U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x36U] 
                                           >> 4U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x36U] >> 2U))))));
    bufp->fullBit(oldp+4625,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s));
    bufp->fullBit(oldp+4626,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 4U))));
    bufp->fullBit(oldp+4627,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 3U))));
    bufp->fullBit(oldp+4628,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 2U))));
    bufp->fullCData(oldp+4629,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa2__s)))),3);
    bufp->fullBit(oldp+4630,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa2__s)))));
    bufp->fullBit(oldp+4631,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s));
    bufp->fullCData(oldp+4632,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s) 
                                            << 1U) 
                                           | (1U & 
                                              (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                               [0x36U] 
                                               >> 1U))))),3);
    bufp->fullBit(oldp+4633,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s)) 
                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 1U)))));
    bufp->fullBit(oldp+4634,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s));
    bufp->fullBit(oldp+4635,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x36U] >> 1U))));
    bufp->fullCData(oldp+4636,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] << 2U)) 
                                | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                         >> 3U)))),3);
    bufp->fullBit(oldp+4637,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x36U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                >> 4U)) 
                                    | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                         >> 4U) | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x36U]) & 
                                       ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                        >> 3U))))));
    bufp->fullBit(oldp+4638,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa7__s));
    bufp->fullBit(oldp+4639,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                              [0x36U])));
    bufp->fullBit(oldp+4640,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 4U))));
    bufp->fullBit(oldp+4641,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 3U))));
    bufp->fullCData(oldp+4642,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))),3);
    bufp->fullBit(oldp+4643,((1U & ((IData)((6U == 
                                             (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))))));
    bufp->fullBit(oldp+4644,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s));
    bufp->fullBit(oldp+4645,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 2U))));
    bufp->fullBit(oldp+4646,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 1U))));
    bufp->fullBit(oldp+4647,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))));
    bufp->fullCData(oldp+4648,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa7__s)))),3);
    bufp->fullBit(oldp+4649,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s)) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa7__s)))));
    bufp->fullBit(oldp+4650,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s));
    bufp->fullCData(oldp+4651,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                 >> 5U)))),3);
    bufp->fullBit(oldp+4652,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s) 
                                     & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                        >> 6U)) | (
                                                   (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                     >> 6U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s)) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                      >> 5U))))));
    bufp->fullBit(oldp+4653,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s));
    bufp->fullBit(oldp+4654,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 6U))));
    bufp->fullBit(oldp+4655,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 5U))));
    bufp->fullCData(oldp+4656,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                               >> 0xaU))))),3);
    bufp->fullBit(oldp+4657,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+4658,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s));
    bufp->fullBit(oldp+4659,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 0xaU))));
    bufp->fullCData(oldp+4660,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+4661,((1U & ((IData)((0x300U 
                                             == (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                    | ((IData)((0U 
                                                != 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                          >> 7U))))));
    bufp->fullBit(oldp+4662,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s));
    bufp->fullBit(oldp+4663,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 9U))));
    bufp->fullBit(oldp+4664,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 8U))));
    bufp->fullBit(oldp+4665,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 7U))));
    bufp->fullCData(oldp+4666,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                               >> 0xbU))))),3);
    bufp->fullBit(oldp+4667,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s) 
                               & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s)) 
                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s) 
                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s)) 
                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+4668,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 0xbU))));
    bufp->fullCData(oldp+4669,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__PVT__fifth_s) 
                                 << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                 >> 0xcU)))),3);
    bufp->fullBit(oldp+4670,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 0xdU))));
    bufp->fullBit(oldp+4671,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                    >> 0xcU))));
    bufp->fullIData(oldp+4672,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x37U]),17);
    bufp->fullSData(oldp+4673,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group),14);
    bufp->fullBit(oldp+4674,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout));
    bufp->fullBit(oldp+4675,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__PVT__fifth_s) 
                                    ^ VL_REDXOR_16(
                                                   (0x3000U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))))));
    bufp->fullCData(oldp+4676,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s) 
                                 << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
    bufp->fullCData(oldp+4677,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s) 
                                 << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s) 
                                            << 2U) 
                                           | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s))))),4);
    bufp->fullCData(oldp+4678,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s))),2);
    bufp->fullCData(oldp+4679,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s) 
                                 << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s))),2);
    bufp->fullBit(oldp+4680,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__PVT__fifth_s));
    bufp->fullCData(oldp+4681,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x37U] >> 0xeU))),3);
    bufp->fullBit(oldp+4682,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x37U] >> 0x10U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x37U] >> 0xfU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U] >> 0xfU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x37U] 
                                           >> 0x10U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x37U] >> 0xeU))))));
    bufp->fullBit(oldp+4683,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s));
    bufp->fullBit(oldp+4684,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 0x10U))));
    bufp->fullBit(oldp+4685,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 0xfU))));
    bufp->fullBit(oldp+4686,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 0xeU))));
    bufp->fullCData(oldp+4687,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x37U] >> 0xbU))),3);
    bufp->fullBit(oldp+4688,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x37U] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x37U] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x37U] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x37U] >> 0xbU))))));
    bufp->fullBit(oldp+4689,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s));
    bufp->fullBit(oldp+4690,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 0xdU))));
    bufp->fullBit(oldp+4691,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 0xcU))));
    bufp->fullBit(oldp+4692,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 0xbU))));
    bufp->fullCData(oldp+4693,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x37U] >> 8U))),3);
    bufp->fullBit(oldp+4694,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x37U] >> 0xaU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x37U] >> 9U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U] >> 9U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x37U] 
                                           >> 0xaU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x37U] >> 8U))))));
    bufp->fullBit(oldp+4695,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s));
    bufp->fullBit(oldp+4696,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 0xaU))));
    bufp->fullBit(oldp+4697,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 9U))));
    bufp->fullBit(oldp+4698,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 8U))));
    bufp->fullCData(oldp+4699,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x37U] >> 5U))),3);
    bufp->fullBit(oldp+4700,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x37U] >> 7U) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x37U] >> 6U)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U] >> 6U) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x37U] 
                                           >> 7U)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x37U] >> 5U))))));
    bufp->fullBit(oldp+4701,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s));
    bufp->fullBit(oldp+4702,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 7U))));
    bufp->fullBit(oldp+4703,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 6U))));
    bufp->fullBit(oldp+4704,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 5U))));
}
